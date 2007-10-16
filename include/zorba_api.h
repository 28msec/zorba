///Created: Daniel Turcanu @ IPDevel 



#ifndef ZORBA_XQUERY_CPP_API_HEADER
#define ZORBA_XQUERY_CPP_API_HEADER


//#include "errors/errors.h"
#include "store/api/item.h"
#include "errors/errors.h"
#include "types/typecodes.h"
#include "util/rchandle.h"
#include "store/api/item.h"
#include <list>

//using namespace std;

//?namespace xqp	///xqp is too general name for a namespace
//?{

namespace xqp {

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
/*
///Init the engine once per application
void		Zorba_InitializeZorbaEngine();
void		Zorba_UninitializeZorbaEngine();


// to initialize the engine for each thread
bool		Zorba_InitThread();
void		Zorba_CloseThread();//when ending the thread
*/

////////////////////////////////Error handling interface //////////////////
typedef rchandle<Item> Item_t;
class ItemFactory;


class Zorba_QName
{
};

class Zorba_Items
{
};

struct Zorba_ErrorLocation
{
	std::string		module_name;///empty if is main module

	const char *filename;
	const unsigned int line;
	const unsigned int column;
};

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


//typedef	std::list<Zorba_AlertMessage>	Zorba_AlertList;

///user might choose to receive the alerts through callback functions
typedef int alert_callback(Zorba_AlertMessage *alert_mess);

class Zorba_AlertsManager : public std::list<Zorba_AlertMessage>, public rcobject
{
	alert_callback	*registered_callback;
public:
	///register function to be called when error/warning/alert happens
	///if callback function is NULL, then alerts are put in list
	int RegisterAlertCallback(alert_callback	*user_alert_callback);
};

///alerts manager is a thread-specific global object
///each thread has its own error manager
/*
Zorba_AlertsManager		*Zorba_getAlertsManagerForCurrentThread();
*/

/*

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

///QName is an item
class Zorba_QName : public Zorba_ItemPtr
{
};

///Xml Doc is an item
class Zorba_XmlDocument : public Zorba_ItemPtr
{
};


///the sequence/array of items



class Zorba_Items : public std::vector<Zorba_ItemPtr>
										//public BasicIterator///is also an iterator to serve as a var value
{
public:
	///sort items by their id
	void	SortItems();
};





/////////////////////Item stream generator/////////////////////////

class Zorba_ItemStream : public BasicIterator
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

///DOM access will be provided

///SAX access
class Zorba_XmlSaxReader
{
public:
	typedef enum SaxEvents
	{
		SAX_NULL = 0,///returned after the last element


		SAX_ELEMENT_START,
		SAX_ELEMENT_END,
		SAX_TEXT,
		SAX_COMMENT
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

///the user can define its function for comparing strings 
///return -1, 0, 1 for less, equal, bigger
typedef (int)(user_collation)(uint32_t codepoint1, uint32_t codepoint2);

/// the Static Context
/// this class represents only the part that is the interface to the user
class Zorba_StaticContext
{
public:

	void		SetXPath1_0CompatibMode( bool mode );///true for XPath1.0 only, false for XPath2.0
	void		AddNamespace( std::string prefix, std::string URI );
	void		SetDefaultElementAndTypeNamespace( std::string URI );
	void		SetDefaultFunctionNamespace( std::string URI );
	void		SetContextItemStaticType( TypeCode		type );
	void		AddCollation( std::string URI, std::string available_collation );//if URI is empty then it sets the default collation
	void		SetCustomCollation( user_collation *fn_collation);
	void		SetConstructionMode( enum construction_mode );
	void		SetOrderingMode( enum ordering_mode );
	void		SetDefaultOrderForEmptySequences( enum ordering_mode );
	void		SetBoundarySpacePolicy( enum boundary_space_policy );
	void		SetCopyNamespacesMode( bool preserve, bool inherit );
	void		SetBaseURI( std::string baseURI );
	//statically known documents (types)
	void		AddDocumentType( std::string URI, TypeCode doc_type );
	void		AddCollectionType( std::string URI, TypeCode		collection_type );///if URI is empty then it refers to default collection type
};

///dynamic context used for executing xqueries
///Attention is needed here: this object can be used for executing multiple xqueries
///but some parts cannot be shared between xqueries (between threads)
///so they are defined actually in Zorba_XQueryBinary
class Zorba_DynamicContext
{
public:
		
	///set custom date time
	bool			SetCustomDateTime( Zorba_ItemPtr datetime_item);
	bool			SetImplicitTimezone( int tz );

	///register documents available through fn:doc() in xquery
	bool			RegisterAvailableDocument(std::string docURI,
																			Zorba_XmlDocument doc);
	///register collections available through fn:collection() in xquery
	///default collection has empty URI ""
	bool			RegisterAvailableCollection(std::string collectionURI,
																			Zorba_Items *collection);
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


class Zorba_XQueryBinary : 
{
public:
	///the contexts are copied into internal contexts
	//Zorba_StaticContext		*internal_static_context;///the binary maintains its own static context
	Zorba_DynamicContext	*internal_dynamic_context;///user can change dyn context directly here

public:
	//more functions for dynamic context set up (specific only to this binary object)
	///set a var with an iterator (singleton iterator for single item)
	///context item has a predefined name, empty name "" (applies only for setting with item)
	///return true for success
	bool		SetVariable( Zorba_QName varname, Zorba_ItemPtr &item );
	bool		SetVariable( Zorba_QName varname, Zorba_Items	&item_seq);
	//setup the var with an infinite stream of items that implements the iterator contract
	bool		SetVariable( Zorba_QName varname, Zorba_ItemStream	&item_generator);
	//when executing, the XQueryBinary generator cannot be used by other threads
	bool		SetVariable( Zorba_QName varname, Zorba_XQueryBinary	&item_generator);
	bool		DeleteVariable( Zorba_QName varname );



	///duplicate other object, without the dynamic context (or maybe with it?)
	///this is usefull for multithreading
	///carefull that the other binary might be in execution state: do not clone its internal state
	bool		Clone( Zorba_XQueryBinary &source_binary);



	///retrieve all the items at once
	//return true for success; see the error list if insuccess
	bool		Execute(  Zorba_DynamicContext *pdynamic_context,///can be NULL
										Zorba_Items &result_items,///the result
										int		max_items = -1 ///default -1, get all items; x, return only x items
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
*/
///the user can define its function for comparing strings 
///return -1, 0, 1 for less, equal, bigger
typedef int user_collation(uint32_t codepoint1, uint32_t codepoint2);

class XQueryResult : public rcobject
{
public:
	Item_t		next();
};

/// the Static Context
/// this class represents only the part that is the interface to the user
class StaticQueryContext
{
public:

	void		SetXPath1_0CompatibMode( bool mode );///true for XPath1.0 only, false for XPath2.0
	void		AddNamespace( std::string prefix, std::string URI );
	void		SetDefaultElementAndTypeNamespace( std::string URI );
	void		SetDefaultFunctionNamespace( std::string URI );
	void		SetContextItemStaticType( enum TypeCode		type );
	void		AddCollation( std::string URI, std::string available_collation );//if URI is empty then it sets the default collation
	void		SetCustomCollation( user_collation *fn_collation);
	void		SetConstructionMode( enum construction_mode );
	void		SetOrderingMode( enum ordering_mode );
	void		SetDefaultOrderForEmptySequences( enum ordering_mode );
	void		SetBoundarySpacePolicy( enum boundary_space_policy );
	void		SetCopyNamespacesMode( bool preserve, bool inherit );
	void		SetBaseURI( std::string baseURI );
	//statically known documents (types)
	void		AddDocumentType( std::string URI, TypeCode doc_type );
	void		AddCollectionType( std::string URI, TypeCode		collection_type );///if URI is empty then it refers to default collection type
};

class DynamicQueryContext : public rcobject
{
	int			current_date_time;
	int			implicit_timezone;


	///following is the input data; this is not duplicable between executions
	bool		SetVariable( Zorba_QName varname, XQueryResult *item_iter );
	bool		SetVariable( Zorba_QName varname, Item_t &item );
	bool		DeleteVariable( Zorba_QName varname );


	///register documents available through fn:doc() in xquery
	bool			RegisterAvailableDocument(xqp_string docURI,
																			xqp_string store_docURI);
	///register collections available through fn:collection() in xquery
	///default collection has empty URI ""
	bool			RegisterAvailableCollection(xqp_string collectionURI,
																			xqp_string store_collectionURI);
};




class XQuery : public rcobject
{
		friend class XQueryPtr;
protected:
    XQuery( );
    ~XQuery();

public:


    // StaticQueryContext is optional
		//daniel: return true for success
		// Matthias: how to return errors? daniel: using the error manager
    // routing_mode: should documents in a collection be filtered or queried completely
    //         if filtered, the result will be a sequences of URI, one for each qualifying documents
    bool compile(StaticQueryContext* = 0, bool routing_mode = false);

    // execute the query and compile it if necessary
		//daniel: return true for success
		// Matthias: again, how tu return errors? daniel: using the error manager
    // the DynamicQueryContext does not need to be passed, a default one can always be used
    XQueryResult* execute( DynamicQueryContext* = 0);

    bool isCompiled();

    // clone the query (can be compiled or not compiled)
   // QueryPtr clone();

		//daniel: isn't the Query more suitable to serialize itself?
		bool   serializeQuery(ostream &os);

public:
    // getters/setters for Static- and DynamicQueryContext
    // a default static and dynamiccontext is always available

    // Matthias: don't call it internal
    // there is no need to distinguish interal and external
		StaticQueryContext* getInternalStaticContext();
 //   DynamicQueryContextPtr getInternalDynamicContext();

		//daniel: get the variables out of the dynamic context class
		// Matthias: get the dynamiccontext from the query and set the variables there
		//           adhere to the XQuery processing model and don't deviate from it
		//daniel: one dynamic context object can be used in many Queries; a variable is specific to only one Query
		//				that is because an ItemIterator keeps an internal state and can be used in a single thread
//		bool		SetVariable( Zorba_QName varname, ItemIterator &item_iter );
//		bool		SetVariable( Zorba_QName varname, Item_t &item );
//		bool		DeleteVariable( Zorba_QName varname );

public:
	///error manager holds the list of errors for this Query
	///you can set a callback function into the error manager
	///when executing the Query returns false, you can get the list of errors from the error manager
//	Zorba_AlertsManager*		getAlertsManager();
};    



class ZorbaFactory
{
public:
	ZorbaFactory(ItemFactory*);
	~ZorbaFactory();

	void InitThread();
	void UninitThread();

  XQuery* createQuery(xqp_string aQueryString);

};

}//end namespace xqp







#endif


/*
		Use cases:

		Query a XML and iterate through results. The XML is a file on disk.
		One thread executing.

		
		std::string		query = "/book[@nr_pages > 100]";

		///load the xml file
		Zorba_XmlDocument		source_xml;///actually an item in disguise
		ifstream						xml_file;
		xml_file.open("books.xml");
		///construct completely into memory
		source_xml.ConstructFromXML( xml_file, !IN_BINARY_FORM);
		xml_file.close();///no more need for the file

		//compile the xquery
		Zorba_XQueryCompiler		xq_compiler;
		Zorba_XQueryBinary			xqbin;

		if(!xq_compiler(query, NULL, //no static context defined
										&xqbin))
		{
			///....error
			goto DisplayErrorsAndExit;
		}
		
		///set the context item into dynamic context of the binary
		if(!xqbin.SetVariable( Zorba_QName("", "") ///var prefix and name empty
												&source_xml))
		{
			///....error
			goto DisplayErrorsAndExit;
		}

		////execute step by step
		if(!xqbin.StartExecution( NULL ))///no external dynamic context provided
		{
			///....error
			goto DisplayErrorsAndExit;
		}
		
		///iterate through the results
		Zorba_ItemPtr		it;
		while(it=xqbin.GetNextItem() && (*it))
		{
			///do something with the book item
			///....
		}

		xqbin.CloseExecution();

		///thats all
		return 0;

DisplayErrorsAndExit:
		///process the errors
		Zorba_AlertsManager		err_manag = Zorba_getAlertsManagerForCurrentThread();

		std::list<Zorba_AlertMessage>::iterator		it;

		for(it = err_manag.begin; it<err_manag.end(); it++)
		{
			//"it" is of type Zorba_AlertMessage
			switch((*it).alert_type)
			{
			case	ERROR_ALERT:
					cout << "Err" << (*it).err_code << ":" << (*it).err_loc.module_name << ":" << (*it).err_loc.line << " : ";
					break;
			case	WARNING_ALERT:
					cout << "Warning" << (*it).warn_code << ":" << (*it).warn_loc.module_name << ":" << (*it).warn_loc.line << " : ";
					break;
			case	NOTIFICATION_ALERT:
					//no special info here
					break;
			case	FEEDBACK_REQUEST_ALERT:
					///not implemented
					break;

			case	USER_ERROR_ALERT://fn:error
					cout << "User Err " << (*it).err_name.prefix << ":"<<(*it).err_name.name << " : ";
					break;
			case	USER_TRACE_ALERT://fn:trace
					break;
			};

			///display the message
			cout << (*it).alert_description;

			//display the item list if exists
			Zorba_Items		*after_items = NULL;
			switch((*it).alert_type)
			{
			case	USER_ERROR_ALERT://fn:error
					after_items = &(*it).items_error;
					break;
			case	USER_TRACE_ALERT://fn:trace
					after_items = &(*it).items_trace;
					break;
			};
			if(after_items)
			{
				ostringstream		oss;
				for(int i=0;i<after_items->size();i++)
				{
					after_items[i].SerializeAsXml( oss, !IN_BINARY_FORM );
					cout << endl << endl;
					cout << oss.c_str();
					oss.clear();
				}
			}

			cout << endl;
		}

		return -1;

*/


/*
			Other use case.
			Use xml input data from database. Database is viewed as a collection of xmls.
			Retrieve all data at once.

		std::string		query = "<results> 
													{fn:collection("file://books.local.xmldb")/book[@nr_pages > 100]} 
													</results>";

		///init the xml db (the details should be in store.h api)
		Zorba_XmlDatabase		source_xmldb;///offers also Zorba_Items interface
		source_xmldb.opendb("c:\xmldb\books.zdb");///the physical location

		///set up a generic dynamic context
		Zorba_DynamicContext		dyn_ctx;
		if(!dyn_ctx.RegisterAvailableCollection("file://books.local.xmldb",///some URI
																			&Zorba_XmlDatabase))
		{
			///....error
			goto DisplayErrorsAndExit;
		}

		//compile the xquery
		Zorba_XQueryCompiler		xq_compiler;
		Zorba_XQueryBinary			xqbin;

		if(!xq_compiler(query, NULL, //no static context defined
										&xqbin))
		{
			///....error
			goto DisplayErrorsAndExit;
		}
		
		////execute step by step
		Zorba_Items		result;
		if(!xqbin.Execute( &dyn_ctx, &result ))
		{
			///....error
			goto DisplayErrorsAndExit;
		}
		
		///result should contain only one item
		if(result.size() < 1)
		{
			///....error
			goto DisplayErrorsAndExit;
		}

		///save the result into a xml file
		ofstream		result_xml_file("selected_books.xml");
		result[0]->SerializeAsXml( result_xml_file, !IN_BINARY_FORM);
		result_xml_file.close();

		///thats all

DisplayErrorsAndExit:
//   .....

*/

/*

		Using multiple threads. Cloning the xquery binary.
		Reading results in pages of 20 results (this is a common case for accessing a database through web).

	
		Thread 1																									Thread2

	Zorba_InitializeZorbaEngine();


	///compile a query
	Zorba_XQueryCompiler		xq_compiler;
	Zorba_XQueryBinary			xqbin;
	std::string		query = "/book[@nr_pages > 100]";

	///set up the store
	Zorba_XmlDatabase		source_xmldb;
	source_xmldb.opendb("c:\xmldb\books.zdb");

	///set up a generic dynamic context
	Zorba_DynamicContext		dyn_ctx;
	if(!dyn_ctx.RegisterAvailableCollection
									("file://books.local.xmldb",
									&Zorba_XmlDatabase))
	{
		///....error
		goto DisplayErrorsAndExit;
	}

	///compile the xquery
	if(!xq_compiler(query, NULL, 
									&xqbin))
	{
		///....error
		goto DisplayErrorsAndExit;
	}	

	

																												Thread2

																							////these are worker threads
																							// to initialize the engine for each thread
																							Zorba_InitThread();
																							Zorba_XQueryBinary		xqbin2;

																							///clone the previously compiled xquery
																							///to be used in this thread
																							if(!xqbin2.Clone(xqbin))
																							{
																								///....error
																								goto DisplayErrorsAndExit2;
																							}

																							Zorba_Items		result;
																							if(!xqbin2.Execute( &dyn_ctx, &result,
																																	100))///retrieve only 100 results
																							{
																								///....error
																								goto DisplayErrorsAndExit2;
																							}
																							
																							if(result.size() < 1)
																							{
																								///....error
																								goto DisplayErrorsAndExit2;
																							}

																							///now Zorba_Items are independent of xqbin2

																							///a user defined function to format HTML output
																							display20Items( &result, 0, 20);
																							Zorba_CloseThread();//when ending the thread




					Thread 3

		///user called for another 20 items

		Zorba_InitThread();
		display20Items( &result, x, 20);
		Zorba_CloseThread();//when ending the thread

*/