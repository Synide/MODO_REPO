/*
 *  Plug-in SDK Header: Tableau update
 *
 * Copyright 0000
 *
 * Tableau update listener
 */

#include <lxu_tableau.hpp>

#include <lx_listener.hpp>
#include <lx_visitor.hpp>
#include <lxidef.h>

#include <algorithm>
#include <vector>

//-----------------------------------------------------------------------------
// Tableau update visitor implementation
//-----------------------------------------------------------------------------
class CLxTableauListener::UpdateVisitor : public CLxGenericPolymorph, public CLxImpl_Visitor
{
public:
    // Constructor
    UpdateVisitor();

    // Destructor
    ~UpdateVisitor();

    // Add tableau update
    void AddTableauUpdate(TbxUpdateCallback& callback, ILxUnknownID tableau, ILxUnknownID item, int chan);

    // CLxImpl_Visitor methods
    // Process all update requests
    // This method will be called by Tableau when it needs to update.
    LxResult vis_Evaluate() override;

    // CLxGenericPolymorph methods
    void* NewObj() override;
    void  FreeObj(void*) override;

    operator ILxUnknownID();

private:
    struct TbxUpdateEntry
    {
        TbxUpdateCallback callback;
        ILxUnknownID      tableau;
        ILxUnknownID      item;
        int               chanIndex;

        // Compare
        bool operator==(const TbxUpdateEntry& e) const
        {
            return callback.source == e.callback.source && item == e.item;
        }
    };

    std::vector<TbxUpdateEntry> m_updates;
    LXtObjectID                 m_ifc;
};

//-----------------------------------------------------------------------------
// Tableau update visitor constructor
//-----------------------------------------------------------------------------
inline CLxTableauListener::UpdateVisitor::UpdateVisitor() : m_ifc(nullptr)
{
    AddInterface(new CLxIfc_Visitor<UpdateVisitor>());

    m_ifc = Spawn();
}

//-----------------------------------------------------------------------------
// Tableau update visitor destructor
//-----------------------------------------------------------------------------
inline CLxTableauListener::UpdateVisitor::~UpdateVisitor()
{
    if (m_ifc)
    {
        lx::ObjRelease(m_ifc);
        m_ifc = nullptr;
    }

    m_updates.clear();
}

//-----------------------------------------------------------------------------
// Add tableau update
//-----------------------------------------------------------------------------
inline void
CLxTableauListener::UpdateVisitor::AddTableauUpdate(CLxTableauListener::TbxUpdateCallback& callback, ILxUnknownID tableau, ILxUnknownID item, int chan)
{
    // Notify tableau that we want to update it
    // Check if tableau is already in the update requests.
    // Since we have one listener/update per tableau, we just need to
    // check if we have any updates scheduled.
    if (m_updates.empty())
    {
        CLxUser_Tableau tbx(tableau);

        tbx.Update(*this, 1);
    }

    TbxUpdateEntry e;

    e.callback  = callback;
    e.tableau   = tableau;
    e.item      = item;
    e.chanIndex = chan;

    // Add update request (which is going to be processed when tableau is
    // ready in the vis_Evaluate()).
    // Check if update is already added for this item/channel
    if (std::find(m_updates.begin(), m_updates.end(), e) == m_updates.end())
        m_updates.push_back(e);
}

//-----------------------------------------------------------------------------
// Process all update requests
// This method will be called by Tableau when it needs to update.
//-----------------------------------------------------------------------------
inline LxResult CLxTableauListener::UpdateVisitor::vis_Evaluate()
{
    for (size_t c = 0; c < m_updates.size(); ++c)
    {
        TbxUpdateEntry& update = m_updates[c];

        update.callback.TableauUpdate(update.tableau, update.item, update.chanIndex);
    }

    m_updates.clear();

    return LXe_OK;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
inline void* CLxTableauListener::UpdateVisitor::NewObj()
{
    return this;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
inline void CLxTableauListener::UpdateVisitor::FreeObj(void* /*obj*/)
{
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
inline CLxTableauListener::UpdateVisitor::operator ILxUnknownID()
{
    if (m_ifc == nullptr)
        m_ifc = Spawn();

    return reinterpret_cast<ILxUnknownID>(m_ifc);
}

//-----------------------------------------------------------------------------
// Tableau listener constructor
//-----------------------------------------------------------------------------
inline CLxTableauListener::Listener::Listener() : m_tableauCtx(nullptr)
{
    m_visitor = new UpdateVisitor();
}

//-----------------------------------------------------------------------------
// Tableau listener Destructor
//-----------------------------------------------------------------------------
inline CLxTableauListener::Listener::~Listener()
{
    delete m_visitor;
}

//-----------------------------------------------------------------------------
// Add tableau update callback
//-----------------------------------------------------------------------------
inline void
CLxTableauListener::Listener::Add(ILxUnknownID tableauCtx, const CLxTableauListener::TbxUpdateCallback& callback, ILxUnknownID item, int chan)
{
    if (m_tableauCtx == nullptr)
        m_tableauCtx = tableauCtx;

    Entry e;
    e.callback  = callback;
    e.item      = item;
    e.chanIndex = chan;

    m_entries.push_back(e);
}

//-----------------------------------------------------------------------------
// Called when tableau item/channel changes
//-----------------------------------------------------------------------------
inline void CLxTableauListener::Listener::tli_ChannelChange(ILxUnknownID /*tableauObj*/, ILxUnknownID itemObj, int chan)
{
    CLxUser_Item item(itemObj);
    ILxUnknownID itemID = item;

#ifndef NDEBUG
    const char* itemName;
    const char* chanName = "";

    item.UniqueName(&itemName);
    item.ChannelName(chan, &chanName);
#endif

    // Find the item
    for (size_t c = 0; c < m_entries.size(); ++c)
    {
        ILxUnknownID srcItemID = m_entries[c].item;

        if (itemID == srcItemID)
        {
            // Check if item has registered channel index
            if (m_entries[c].chanIndex == -1)
            {
                m_visitor->AddTableauUpdate(m_entries[c].callback, m_tableauCtx, itemID, chan);
            }
            else if (m_entries[c].chanIndex == chan)
            {
                m_visitor->AddTableauUpdate(m_entries[c].callback, m_tableauCtx, itemID, chan);
            }
        }
    }
}

//-----------------------------------------------------------------------------
// When tableau is destroyed we need to remove all listeners
//-----------------------------------------------------------------------------
inline void CLxTableauListener::Listener::tli_TableauDestroy(ILxUnknownID /*tableauObj*/)
{
    // NOTE: tableauObj is different than tableauCtxObj
    // We need to notify that tableauCtxObj is being removed, since source has been added to
    // tableauCtxObj
    CLxTableauListener::GetInstance()->RemoveTableauListeners(m_tableauCtx);
}

//-----------------------------------------------------------------------------
// Return tableau listener static instance
//-----------------------------------------------------------------------------
CLxTableauListener* CLxTableauListener::GetInstance()
{
    static CLxTableauListener inst;

    return &inst;
}

//-----------------------------------------------------------------------------
// Constructor
//-----------------------------------------------------------------------------
CLxTableauListener::CLxTableauListener()
{
    tli.AddInterface(new CLxIfc_TableauListener<Listener>());
}

//-----------------------------------------------------------------------------
// Add tableau listener
//-----------------------------------------------------------------------------
bool CLxTableauListener::AddListener(ILxUnknownID tableau, const CLxTableauListener::TbxUpdateCallback& callback, ILxUnknownID item, int chan)
{
    Listener* listener = nullptr;

    TbxListenerMap::const_iterator it = m_tbxListeners.find(tableau);

    // Check if we already have a listener for this tableau
    if (it != m_tbxListeners.end())
    {
        listener = LXCWxOBJ((*it).second, Listener);
    }
    else
    {
        CLxUser_ListenerPort port(tableau);
        ILxUnknownID         tbxListener;
        LxResult             result;

        tbxListener = tli.Spawn();
        result      = port.AddListener(tbxListener);

        if (LXx_OK(result))
            listener = LXCWxOBJ(tbxListener, Listener);

        if (listener)
            m_tbxListeners.insert(TbxListenerMap::value_type(tableau, tbxListener));
    }

    if (listener)
    {
        listener->Add(tableau, callback, item, chan);

        return true;
    }

    return false;
}

//-----------------------------------------------------------------------------
// Remove tableau listeners
//-----------------------------------------------------------------------------
void CLxTableauListener::RemoveTableauListeners(ILxUnknownID tableau)
{
    auto it = m_tbxListeners.find(tableau);

    if (it != m_tbxListeners.end())
    {
        lx::UnkRelease((*it).second);
        m_tbxListeners.erase(it);
    }
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void CLxTableauListener::Init()
{
    GetInstance();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void CLxTableauListener::Cleanup()
{
}
