///Created: Daniel Turcanu @ IPDevel 



#ifndef ZORBA_XQUERY_CPP_API_HEADER
#define ZORBA_XQUERY_CPP_API_HEADER


//#include "errors/errors.h"
#include "store/api/item.h"
//#include "store/api/store.h"
#include "errors/errors.h"
#include "types/typecodes.h"
#include "util/rchandle.h"

///from ICU
//#include <unicode/utypes.h>
#include <unicode/coll.h>
//#include <unicode/ustring.h>

#include <list>

//using namespace std;

//?namespace xqp	///xqp is too general name for a namespace
//?{

namespace xqp {

///////////////////////////////Engine initialization ////////////////


////////////////////////////////Error handling interface //////////////////
typedef rchandle<Item> Item_t;
class ItemFactory;
class Store;


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
Zorba_AlertsManager		*Zorba_getAlertsManagerForCurrentThread();




///the user can define its function for comparing strings 
///return -1, 0, 1 for less, equal, bigger
typedef int user_collation(uint32_t codepoint1, uint32_t codepoint2);

class XQueryResult : public rcobject
{
public:
	virtual ~XQueryResult();
	virtual Item_t		next();
};

/// the Static Context
/// this class represents only the part that is the interface to the user
class StaticQueryContext
{
public:

	virtual void		SetXPath1_0CompatibMode( bool mode );///true for XPath1.0 only, false for XPath2.0
	virtual void		AddNamespace( std::string prefix, std::string URI );
	virtual void		SetDefaultElementAndTypeNamespace( std::string URI );
	virtual void		SetDefaultFunctionNamespace( std::string URI );
	virtual void		SetContextItemStaticType( enum TypeCode		type );
	virtual void		AddCollation( std::string URI, std::string available_collation );//if URI is empty then it sets the default collation
	virtual void		SetCustomCollation( user_collation *fn_collation);
	virtual void		SetConstructionMode( enum construction_mode );
	virtual void		SetOrderingMode( enum ordering_mode );
	virtual void		SetDefaultOrderForEmptySequences( enum ordering_mode );
	virtual void		SetBoundarySpacePolicy( enum boundary_space_policy );
	virtual void		SetCopyNamespacesMode( bool preserve, bool inherit );
	virtual void		SetBaseURI( std::string baseURI );
	//statically known documents (types)
	virtual void		AddDocumentType( std::string URI, TypeCode doc_type );
	virtual void		AddCollectionType( std::string URI, TypeCode		collection_type );///if URI is empty then it refers to default collection type
};

class DynamicQueryContext : public rcobject
{
	int			current_date_time;
	int			implicit_timezone;


	///following is the input data; this is not duplicable between executions
	virtual bool		SetVariable( Zorba_QName varname, XQueryResult *item_iter );
	virtual bool		SetVariable( Zorba_QName varname, Item_t &item );
	virtual bool		DeleteVariable( Zorba_QName varname );


	///register documents available through fn:doc() in xquery
	virtual bool			RegisterAvailableDocument(xqp_string docURI,
																			xqp_string store_docURI);
	///register collections available through fn:collection() in xquery
	///default collection has empty URI ""
	virtual bool			RegisterAvailableCollection(xqp_string collectionURI,
																			xqp_string store_collectionURI);
};




class XQuery : public rcobject
{
		friend class XQueryPtr;
protected:
    XQuery( );
    virtual ~XQuery();

public:


    // StaticQueryContext is optional
		//daniel: return true for success
		// Matthias: how to return errors? daniel: using the error manager
    // routing_mode: should documents in a collection be filtered or queried completely
    //         if filtered, the result will be a sequences of URI, one for each qualifying documents
    virtual bool compile(StaticQueryContext* = 0, bool routing_mode = false);

    // execute the query and compile it if necessary
		//daniel: return NULL for error
		// Matthias: again, how tu return errors? daniel: using the error manager
    // the DynamicQueryContext does not need to be passed, a default one can always be used
    virtual XQueryResult* execute( DynamicQueryContext* = 0);

    virtual bool isCompiled();

    // clone the query (can be compiled or not compiled)
   // QueryPtr clone();

		//daniel: isn't the Query more suitable to serialize itself?
		virtual bool   serializeQuery(ostream &os);

public:
    // getters/setters for Static- and DynamicQueryContext
    // a default static and dynamiccontext is always available

    // Matthias: don't call it internal
    // there is no need to distinguish interal and external
		virtual StaticQueryContext* getInternalStaticContext();
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
	ZorbaFactory(ItemFactory*, Store*);
	~ZorbaFactory();

	void InitThread(//ItemFactory *item_factory,
									error_messages *em = NULL,
									char *collator_name = "root",
									::Collator::ECollationStrength collator_strength = ::Collator::PRIMARY
									);
	void UninitThread();

  XQuery* createQuery(xqp_string aQueryString);

	void		destroyQuery( XQuery *query );

};

}//end namespace xqp







#endif

