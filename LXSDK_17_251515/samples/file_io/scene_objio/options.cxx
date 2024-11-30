/*
 * Command: loaderOptions.wf_OBJ
 *
 *  Copyright 0000
 */

#include "objParser.hxx"
#include "objio.hxx"

#include <algorithm>
#include <cctype>
#include <cstdio>
#include <string>

#include <lxu_command.hpp>

static LXtTextValueHint unitsType_hints[] = { { 0, "meters" }, { 1, "centimeters" }, { 2, "millimeters" }, { 3, "inches" }, { 0, nullptr } };

namespace OBJ_Options
{

    class CCommand : public CLxBasicCommand
    {
    public:
        CCommand();

        int      basic_CmdFlags() override;
        void     cmd_Execute(unsigned int flags) override;
        LxResult cmd_ArgEnable(unsigned int arg) override;

    private:
        unsigned int m_argIgnoreKa;
        unsigned int m_argAsStatic;
        unsigned int m_argGroupsAsSeparateMeshes;
        unsigned int m_argUnits;
    };

    /*
     * We need factories for all the exported objects that are not servers.
     * Since the polymorph object has to exist for the lifetime of any instance,
     * they are explicitly allocated as part of the module global data and freed
     * at shutdown.
     */
    static class CFactories
    {
    public:
        CLxPolymorph<CLoadOptions> opt;

        CFactories()
        {
            opt.AddInterface(new CLxIfc_StreamIO<CLoadOptions>);
        }
    }* pF;

    CCommand::CCommand()
    {
        unsigned int index = 0;
        m_argIgnoreKa      = index++;
        dyna_Add("sceneio.obj.import.ignoreKa", LXsTYPE_BOOLEAN);
        m_argAsStatic = index++;
        dyna_Add("sceneio.obj.import.asStatic", LXsTYPE_BOOLEAN);
        m_argGroupsAsSeparateMeshes = index++;
        dyna_Add("sceneio.obj.import.groupsAsSeparateMeshes", LXsTYPE_BOOLEAN);
        m_argUnits = index++;
        dyna_Add("sceneio.obj.import.importunits", LXsTYPE_INTEGER);
        dyna_SetHint(m_argUnits, unitsType_hints);
    }

    int CCommand::basic_CmdFlags()
    {
        return LXfCMD_UI;
    }

    void CCommand::cmd_Execute(unsigned int /*flags*/)
    {
        CLxUser_IOService ios;
        CLoadOptions*     opt;
        ILxUnknownID      obj;

        obj = pF->opt.Spawn();
        opt = pF->opt.Cast(obj);

        attr_GetBool(0, &opt->ignore_ka);
        attr_GetBool(1, &opt->as_static);
        attr_GetBool(2, &opt->groups_as_separate_meshes);
        attr_GetInt(3, &opt->unitsType);

        ios.SetOptions(obj);
        lx::ObjRelease(obj);
    }

    LxResult CCommand::cmd_ArgEnable(unsigned int arg)
    {
        /*
          In the current implementation, if 'Import as a Static Mesh' is selected, only one mesh will
          be created, meaning 'Import groups as separate meshes' has no effect.  So if one option is
          selected, disable the other.
         */
        bool enabled;
        if (m_argAsStatic == arg)
        {
            attr_GetBool(m_argGroupsAsSeparateMeshes, &enabled);
            return enabled ? LXe_CMD_DISABLED : LXe_OK;
        }
        else if (m_argGroupsAsSeparateMeshes == arg)
        {
            attr_GetBool(m_argAsStatic, &enabled);
            return enabled ? LXe_CMD_DISABLED : LXe_OK;
        }
        else
        {
            return LXe_OK;
        }
    }

    char toLower(char c)
    {
        return static_cast<char>(std::tolower(c));
    }

    bool Recognize(const char* file)
    {
        COBJParser objParser;
        objParser.fp_Open(file);

        // First verify that the file extension is "obj".
        std::string::size_type pos;
        std::string            filename(file), ext;

        pos = filename.find_last_of(".");
        if (pos == std::string::npos)
            return false;

        // Strip off file extension, and convert to lowercase
        ext = filename.substr(pos + 1, filename.length() - pos - 1);
        std::transform(ext.begin(), ext.end(), ext.begin(), toLower);

        if (ext != std::string("obj"))
            return false;

        // Test for unknown commands:
        int i, unk = 0;

        for (i = 0; i < 50; i++)
        {
            if (!objParser.lp_ReadLine())
                break;
            if (objParser.Command() == CMD_UNKNOWN)
                unk++;
        }

        objParser.fp_Cleanup();
        return unk < 4 && (i - unk) >= 4;
    }

    CLoadOptions* GetOptions()
    {
        CLxUser_IOService ios;
        ILxUnknownID      obj;

        obj = ios.PeekOptions();
        if (!obj)
            return nullptr;

        return pF->opt.Cast(obj);
    }

    void SpawnOptions(void** ppvObj)
    {
        if (!pF->opt.Alloc(ppvObj))
            throw(LXe_FAILED);
    }

#define OPTf_AS_STATIC                 0x01
#define OPTf_GROUPS_AS_SEPARATE_MESHES 0x02
#define OPTf_UNITS_TYPE                0x04
#define OPTf_IGNORE_KA                 0x08

#define OPT_VER_0_0 0  // old version (no units type)
#define OPT_VER_1_0 1  // version with added units type

#define FAIL_EX(f)    \
    rc = f;           \
    if (LXx_FAIL(rc)) \
    throw(rc)

    LxResult CLoadOptions::io_Write(ILxUnknownID stream)
    {
        CLxUser_BlockWrite blk(stream);
        unsigned           u4;
        LxResult           rc;

        u4 = OPT_VER_1_0;
        FAIL_EX(blk.WriteU4(&u4, 1));

        u4 = 0;
        if (as_static)
            u4 |= OPTf_AS_STATIC;

        if (groups_as_separate_meshes)
            u4 |= OPTf_GROUPS_AS_SEPARATE_MESHES;

        if (unitsType)
            u4 |= OPTf_UNITS_TYPE;

        if (ignore_ka)
            u4 |= OPTf_IGNORE_KA;

        FAIL_EX(blk.WriteU4(&u4, 1));  // flags

        return LXe_OK;
    }

    LxResult CLoadOptions::io_Read(ILxUnknownID stream)
    {
        CLxUser_BlockRead blk(stream);
        unsigned          u4[2];
        int               count;
        LxResult          rc;

        FAIL_EX(blk.ReadU4(u4, 2, &count));

        // Check version
        if (u4[0] > OPT_VER_1_0)
            return LXe_NOTFOUND;

        as_static = (u4[1] & OPTf_AS_STATIC) ? true : false;

        groups_as_separate_meshes = (u4[1] & OPTf_GROUPS_AS_SEPARATE_MESHES) ? true : false;

        ignore_ka = (u4[1] & OPTf_IGNORE_KA) ? true : false;

        if (u4[0] == 1)
            unitsType = (u4[1] & OPTf_UNITS_TYPE);
        else
            unitsType = UNITS_M;

        return LXe_OK;
    }

    /*
     * Setup our command as a server. It has a command interface, an attributes
     * interface for arguments, and an attributesUI interface.
     */
    void initialize()
    {
        CLxGenericPolymorph* srv;

        srv = new CLxPolymorph<CCommand>;
        srv->AddInterface(new CLxIfc_Command<CCommand>);
        srv->AddInterface(new CLxIfc_Attributes<CCommand>);
        srv->AddInterface(new CLxIfc_AttributesUI<CCommand>);
        lx::AddServer("loaderOptions.wf_OBJ", srv);

        pF = new CFactories;
    }

    void cleanup()
    {
        delete pF;
    }

};  // namespace OBJ_Options
