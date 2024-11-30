/*
 * Plug-in SDK Header: Common Utility
 *
 * Copyright 0000
 *
 * Command Query Wrapper
 */

#include <lx_command.hpp>
#include <lx_scripts.hpp>
#include <lxu_getstring.hpp>
#include <lxu_queries.hpp>

/*
 * ----------------------------------------------------------------
 * CLxCommandQuery : Implementation
 *
 * We'll create a command with the desired name and hold onto the array results
 * so the user can see them.
 */
class pv_CommandQuery
{
public:
    CLxUser_CommandService svc;
    CLxUser_Command        cmd;
    CLxUser_Attributes     arg;
    CLxUser_ValueArray     va;
    unsigned int           argIndex, valIndex;

    LxResult sgs_GetString(char* buf, unsigned len);
};

/*
 * Create the command on construction, setting the args as well if possible.
 */
CLxCommandQuery::CLxCommandQuery(const char* name)
{
    pv = new pv_CommandQuery;

    if (pv->svc.NewCommand(pv->cmd, name))
        pv->arg.set(pv->cmd);
}

/*
 * Destructor just deletes the private object.
 */
CLxCommandQuery::~CLxCommandQuery()
{
    delete pv;
}

/*
 * The client may need to set arguments, which can be done this way.
 */
CLxUser_Attributes& CLxCommandQuery::Arguments()
{
    return pv->arg;
}

/*
 * Perform the actual query. On success this object will contain a value array
 * positioned at index 0.
 */
bool CLxCommandQuery::Query(unsigned int argIndex)
{
    if (!pv->cmd.test())
        return false;

    pv->valIndex = 0;
    pv->argIndex = argIndex;
    pv->va.clear();

    if (!pv->svc.QueryIndex(pv->cmd, argIndex, pv->va))
        return false;

    return pv->va.test();
}

/*
 * Get the value's type name.
 */
const char* CLxCommandQuery::ValueType()
{
    const char* tname;

    if (!pv->arg.test())
        return nullptr;

    if (LXx_FAIL(pv->arg.TypeName(pv->argIndex, &tname)))
        return nullptr;

    return tname;
}

/*
 * Iteration is done by getting the count and then setting the index
 * the desired element.
 */
unsigned int CLxCommandQuery::Count()
{
    if (!pv->va.test())
        return 0;

    return pv->va.Count();
}

void CLxCommandQuery::SetIndex(unsigned int valIndex)
{
    pv->valIndex = valIndex;
}

/*
 * Get...() methods return the value at the current index.
 */
int CLxCommandQuery::GetInt()
{
    int val = 0;

    if (pv->va.test())
        pv->va.GetInt(pv->valIndex, &val);

    return val;
}

double CLxCommandQuery::GetFloat()
{
    double val = 0.0;

    if (pv->va.test())
        pv->va.GetFloat(pv->valIndex, &val);

    return val;
}

const char* CLxCommandQuery::GetString(char* buf, unsigned len)
{
    if (pv->va.test())
        pv->va.GetString(pv->valIndex, buf, len);

    return buf;
}

/*
 * Nice version of GetString() that never truncates.
 */
LxResult pv_CommandQuery::sgs_GetString(char* buf, unsigned len)
{
    return va.GetString(valIndex, buf, len);
}

void CLxCommandQuery::GetString(std::string& string)
{
    if (!pv->va.test())
        return;

    CLxSafeGetString<pv_CommandQuery> sgs;

    sgs.GetStringEx(*pv, string);
}

bool CLxCommandQuery::GetValue(CLxLocalizedObject& o_dest)
{
    if (!pv->va.test())
        return false;

    CLxResult res = pv->va.GetValue(pv->valIndex, o_dest);
    return res.ok();
}

void CLxCommandQuery::ResetArgs()
{
    pv->cmd.ArgResetAll();
}

LxResult CLxCommandQuery::IntHint(const LXtTextValueHint** hints)
{
    if (pv->arg.test())
    {
        *hints = pv->arg.Hints(1);
        return LXe_OK;
    }

    return LXe_FAILED;
}

/*
 * ----------------------------------------------------------------
 * CLxReadUserValue : Implementation
 *
 * This is very similar to using query commands for reading user values, but
 * we use the script service to read user values directly. This is much faster
 * and safer.
 */
class pv_ReadUserValue
{
public:
    CLxUser_ScriptSysService svc;
    CLxUser_UserValue        val;

    LxResult sgs_GetString(char* buf, unsigned len);
};

CLxReadUserValue::CLxReadUserValue()
{
    pv = new pv_ReadUserValue;
}

CLxReadUserValue::~CLxReadUserValue()
{
    delete pv;
}

bool CLxReadUserValue::Query(const char* name)
{
    return pv->svc.UserValueLookup(name, pv->val);
}

const char* CLxReadUserValue::ValueType()
{
    const char* tname;
    LxResult    rc;

    if (!pv->val.test())
        return nullptr;

    rc = pv->val.CLxLoc_UserValue::TypeName(&tname);
    if (LXx_FAIL(rc))
        return nullptr;

    return tname;
}

int CLxReadUserValue::GetInt()
{
    int value;

    if (!pv->val.test() || LXx_FAIL(pv->val.GetInt(&value)))
        return -1;

    return value;
}

double CLxReadUserValue::GetFloat()
{
    double value;

    if (!pv->val.test() || LXx_FAIL(pv->val.GetFlt(&value)))
        return -1.0;

    return value;
}

LxResult pv_ReadUserValue::sgs_GetString(char* buf, unsigned len)
{
    return val.GetString(buf, len);
}

void CLxReadUserValue::GetString(std::string& string)
{
    if (!pv->val.test())
        return;

    CLxSafeGetString<pv_ReadUserValue> sgs;

    sgs.GetStringEx(*pv, string);
}
