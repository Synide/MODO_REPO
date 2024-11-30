/*
 * Plug-in SDK Header: C++ Services
 *
 * Copyright 0000
 *
 * Helper classes for listening for tableau events and scheduling the tableau updates.
 */
#ifndef LX_TABLEAU_HPP
#define LX_TABLEAU_HPP

#include <lx_tableau.hpp>
#include <lx_item.hpp>

#include <map>
#include <vector>

//-----------------------------------------------------------------------------
// CLxTableauListener
//
// This is a generic class for adding tableau listeners.
//-----------------------------------------------------------------------------


class CLxTableauListener
{
public:

	// Call this from plugin init()
	static void Init();

	// Call this from plugin cleanup()
	static void Cleanup();

	// Add tableau listener (listens to all channels changes on given item)
	// If chanIndex is -1 then all changes are propagated, otherwise only channel
	// with given index will propagate the change back to source.
	// SourceT class needs to have method:
	//     LxResult TableauUpdate (ILxUnknownID tbxObj, ILxUnknownID itemObj, int chan)
	template< typename SourceT >
	static bool Add (
					SourceT*		source,
					ILxUnknownID	tableauObj,
					ILxUnknownID	item,
					int				chanIndex = -1);
private:

	//---------------------------------------------------------------------
	// Tableau update callback (helper class)
	//---------------------------------------------------------------------
	struct TbxUpdateCallback
	{
		typedef LxResult (*TableauUpdateFunc) (void*, ILxUnknownID, ILxUnknownID, int);

		//---------------------------------------------------------------------
		// Helper class to invoke TableauUpdate (specialized for type passed in the TbxUpdate constructor)
		//---------------------------------------------------------------------
		template< typename T >
		struct TableauUpdateStub
		{
			// Stub function
			static LxResult TableauUpdate (void* inst, ILxUnknownID tbx, ILxUnknownID item, int chan)
			{
				T* ptr = reinterpret_cast < T* > (inst);

				return ptr->TableauUpdate (tbx, item, chan);
			}
		};

		//---------------------------------------------------------------------
		// Default constructor
		//---------------------------------------------------------------------
		TbxUpdateCallback ()
			: source (nullptr)
			, func (nullptr)
		{
		}

		//---------------------------------------------------------------------
		// Constructor
		//---------------------------------------------------------------------
		template< typename SourceT >
		TbxUpdateCallback (SourceT*	src)
			: source (src)
			, func (TableauUpdateStub< SourceT >::TableauUpdate)
		{
		}

		//---------------------------------------------------------------------
		// Invoke TableauUpdate
		//---------------------------------------------------------------------
		LxResult TableauUpdate (ILxUnknownID tbx, ILxUnknownID item, int chan)
		{
			if (source && func)
				return func (source, tbx, item, chan);

			return LXe_NOTFOUND;
		}

		// Members
		void*				source;			// Source instance
		TableauUpdateFunc	func;			// Pointer to function
	};

	// Forward declaration
	class UpdateVisitor;

	//-----------------------------------------------------------------------------
	// Tableau listener implementation
	//-----------------------------------------------------------------------------
	class Listener : public CLxImpl_TableauListener
	{
	public:

		Listener ();
		~Listener ();

		void Add (ILxUnknownID tableauCtx, const TbxUpdateCallback& callback, ILxUnknownID item, int chan);

		// Called when item channel is changed
			void
		tli_ChannelChange (
			ILxUnknownID	tableauObj,
			ILxUnknownID	itemObj,
			int				chan) override;

		// Called when tableau is destroyed
			void
		tli_TableauDestroy (
			ILxUnknownID tableau) override;


	private:

		// Members
		struct Entry
		{
			TbxUpdateCallback	callback;
			ILxUnknownID		item;
			int					chanIndex;
		};

		typedef std::vector< Entry >	EntryArray;

		EntryArray		m_entries;
		UpdateVisitor*	m_visitor;
		ILxUnknownID	m_tableauCtx;			// We need to store tableau context used to initialize listener
												// NOTE: We need this, since tableau object that we get in the listener
												//       is different than the tableau context object.
												//       Also, we need tableau context to read channels values via GetChannels().
	};



	// Return instance
	static CLxTableauListener* GetInstance();

	// Constructor
	CLxTableauListener ();

	// Add item listener
	bool AddListener (
					ILxUnknownID				tableau,
					const TbxUpdateCallback&	callback,
					ILxUnknownID				item,
					int							chan);

	// Remove all listeners for given tableau
	void RemoveTableauListeners (
					ILxUnknownID	tableau);

	// Members
	typedef std::map < ILxUnknownID, ILxUnknownID >		TbxListenerMap;

	CLxPolymorph< Listener >	tli;
	TbxListenerMap				m_tbxListeners;
};


//-----------------------------------------------------------------------------
// Add tableau listener
//-----------------------------------------------------------------------------
	template< typename SourceT >
	inline bool
CLxTableauListener::Add (
	SourceT*		source,
	ILxUnknownID	tableau,
	ILxUnknownID	item,
	int				chanIndex)
{
	TbxUpdateCallback callback(source);

	return GetInstance ()->AddListener (tableau, callback, item, chanIndex);
}



#endif // LX_TABLEAU_HPP
