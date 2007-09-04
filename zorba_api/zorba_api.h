


#ifndef ZORBA_XQUERY_CPP_API_HEADER
#define ZORBA_XQUERY_CPP_API_HEADER


#include "errors/errors.h"

using namespace std;

//?namespace xqp	///xqp is too general name for a namespace
//?{
///////////////////////////////Engine initialization ////////////////

/*	from zorba.h

class zorba
{
public:
	// to initialize the application
	static void		initializeZorbaEngine();
	static void		uninitializeZorbaEngine();


	// to initialize the engine for each thread
	static zorba* getZorbaForCurrentThread();
	
	static zorba*	allocateZorbaForNewThread();
	static void		destroyZorbaForCurrentThread();//when ending the thread
};
*/

///Init the engine once per application
void		Zorba_InitializeZorbaEngine();
void		Zorba_UninitializeZorbaEngine();


// to initialize the engine for each thread
bool		Zorba_InitThread();
void		Zorba_CloseThread();//when ending the thread

////////////////////////////////Error handling interface //////////////////
class Zorba_ErrorLocation;

class Zorba_AlertMessage
{
	typedef enum Zorba_AlertType
	{
		ERROR_ALERT,
		WARNING_ALERT,
		NOTIFICATION_ALERT,
		FEEDBACK_REQUEST_ALERT,

		USER_ERROR_ALERT,//fn:error
		USER_TRACE_ALERT//fn:trace
	};
	
	Zorba_AlertType		alert_type;

	union
	{
		///for errors
		struct
		{	
			error_messages::errcode			error_code;
			error_messages::error_type	error_type;
			Zorba_ErrorLocation err_loc;///may contain no location (zero values)
			bool is_fatal;
		};
		///for warnings
		struct
		{
			error_messages::warning_code			warning_code;
			Zorba_ErrorLocation warn_loc;///may contain no location (zero values)
		};
		///for notifications
		struct
		{
			error_messages::NotifyEvent_code	notif_code;
		};
		///for user interaction
		struct
		{
			error_messages::AskUserString_code ask_string;
			error_messages::AskUserStringOptions_code ask_string_options;
		};
		///for user fn:error()
		struct
		{
			Zorba_QName		err_name;
			const Zorba_Items items_error;
		};
		///for user fn:trace()
		struct
		{
			const Zorba_Items items_trace;
		};
	};

	///the user readable description; can be in other languages than english
	std::string		alert_description;

	time_t			time_of_alert;
};

class Zorba_ErrorLocation
{
public:
	std::string		module_name;///empty if is main module
	int						line;
}

//typedef	std::list<Zorba_AlertMessage>	Zorba_AlertList;

///user might choose to receive the alerts through callback functions
typedef (int)(alert_callback)(Zorba_AlertMessage *alert_mess);

class Zorba_AlertsManager : public std::list<Zorba_AlertMessage>
{
	alert_callback	*registered_callback;
public:
	///register function to be called when error/warning/alert happens
	///if callback function is NULL, then alerts are put in list
	RegisterAlertCallback(alert_callback	*user_alert_callback);
};

///alerts manager is a thread-specific global object
///each thread has its own error manager
Zorba_AlertsManager		*Zorba_getAlertsManagerForCurrentThread();



//////////////////Data objects - results of xquery//////////////////

///The Item - the data unit; is defined in item.h
//This is just a smart pointer to item
class Zorba_ItemPtr
{
	Item	*the_item;
public:
	Zorba_ItemPtr();
	Zorba_ItemPtr( Zorba_ItemPtr& );
	Zorba_ItemPtr( Item* );
	~Zorba_ItemPtr();

	Item* operator->();
	Item& operator*();

	///for node items
	void		SerializeAsXML( ostream &os, bool binary_form );
	void		ConstructFromXML( istream &is, bool is_binary_form);///or binary form is detected automatically
};

///the sequence/array of items
/*
///maybe we should derive this class from vector<Zorba_ItemPtr>
class Zorba_Items
{
	std::vector<Zorba_ItemPtr>		items;
public:
	int		GetItemCount();
	Zorba_ItemPtr	operator[](int index);


	///the user can construct its own sequence
	///if position is -1 item is inserted at the end
	void	InsertItem( Zorba_ItemPtr item, int position = -1);
	bool	DeleteItem( int position );

	///sort items by their id
	void	SortItems();
};
*/

class Zorba_Items : public std::vector<Zorba_ItemPtr>,
										public basic_iterator///is also an iterator to serve as a var value
{
public:
	///sort items by their id
	void	SortItems();
};





/////////////////////Item stream generator/////////////////////////

class Zorba_ItemStream : public basic_iterator
{
public:
	///URI points to a file or internet resource
	bool		OpenUriAsStream ( std::string absoluteURI );

	//or get stream from a input stream
	bool		ListenFromIStream( istream &is );

	//or get stream by listening on TCP
	bool		ListenStreamOnSocket( int socket );
};

///other item stream generator is the xquery binary itself, if executed in iterator mode


////////////////////Item construction/////////////////////////////
//item construction is provided by ItemFactory.h
//the ItemFactory is a global object
//using this the user can construct a whole XML doc in DOM mode

//Either Item or ItemFactory should be able to parse an existing XML and construct an item

///returns a smart pointer
ItemFactoryPtr		Zorba_getGlobalItemFactory();









///////////////////XML View ////////////////////////////////////////

///Dom and Stax
///Item is already Dom


class Zorba_XmlSaxReader
{
public:
	typedef enum SaxEvents
	{
		SAX_NULL = 0,///returned after the last element


		SAX_ELEMENT_START,
		SAX_ELEMENT_END,
		SAX_TEXT
	};
	///item must be a node item
	bool		InitReader( Item *item );
	bool		InitReader( istream &is );///read XML from a file or buffer

	bool		IsInited();
	void		Reinit();

	SaxEvents		GetNextEvent();
};






////////////////////////////Context (static for compile, dynamic for execution) /////////
class Zorba_XQueryBinary;

/// the Static Context
/// this class represents only the part that is the interface to the user
class Zorba_StaticContext
{
public:

	///nothing here yet
};

///dynamic context used for executing xqueries
///Attention is needed here: this object can be used for executing multiple xqueries
///but some parts cannot be shared between xqueries
///so they are defined actually in Zorba_XQueryBinary
class Zorba_DynamicContext
{
public:
	///set a var with an iterator (singleton iterator for single item)
	///context item has a predefined name, empty name ""
	///return true for success
	bool		SetVariable( Zorba_QName varname, Zorba_ItemPtr &item );
	bool		SetVariable( Zorba_QName varname, Zorba_Items	&item_seq);


	///and other dynamic context setup
};






/////////////////////////////////XQuery Compiler & Binary ///////////////////

class Zorba_XQueryCompiler
{
public:
	//return true for success; see the error list if insuccess
	//the static context gets copied into binary
	bool		Compile ( std::string xquery_text,
										Zorba_StaticContext *pstatic_context,///can be NULL
										Zorba_XQueryBinary &result_binary);///the result
};

///this class provides also interface to its dynamic context
//One Zorba_XQueryBinary can be used only in one thread 
//(and probably only in the thread that created it)
class Zorba_XQueryBinary : public Zorba_DynamicContext
{
public:
	//more functions for dynamic context set up (specific only to this binary object)
	//setup the var with an infinite stream of items that implements the iterator contract
	bool		SetVariable( Zorba_QName varname, Zorba_ItemStream	&item_generator);
	//when executing, the XQueryBinary generator cannot be used by other threads
	bool		SetVariable( Zorba_QName varname, Zorba_XQueryBinary	&item_generator);



	///duplicate other object, without the dynamic context
	///this is usefull for multithreading
	///carefull that the other binary might be in execution state: do not clone its internal state
	bool		Clone( Zorba_XQueryBinary &source_binary);



	///retrieve all the items at once
	//return true for success; see the error list if insuccess
	bool		Execute(  Zorba_DynamicContext *pdynamic_context,///can be NULL
										Zorba_Items &result_items///the result
										);
	///to be called from another thread while executing
	void		CancelExecution();



	//to retrieve items one by one
	//initialize its internal states
	bool		StartExecution( Zorba_DynamicContext *pdynamic_context );///can be NULL
	//ItemPtr is smart pointer to actual Item
	Zorba_ItemPtr		GetNextItem();
	void		CloseExecution();

	bool		IsExecutionStarted();


	///to save and load the binary xquery
	bool		SerializeXQueryBinary( ostream &os );
	bool		LoadXQueryBinary( istream &is );
};


//?}//end namespace xqp

#endif

