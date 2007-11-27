///Created: Daniel Turcanu @ IPDevel 



#ifndef ZORBA_XQUERY_CPP_API_HEADER
#define ZORBA_XQUERY_CPP_API_HEADER


//#include "errors/errors.h"
#include "store/api/item.h"
//#include "store/api/store.h"
#include "util/rchandle.h"
#include "error_api.h"

///from ICU
//#include <unicode/utypes.h>
#include <unicode/coll.h>
//#include <unicode/ustring.h>

#include "types/typeident.h"

//using namespace std;

//?namespace xqp	///xqp is too general name for a namespace
//?{

namespace xqp {

///////////////////////////////Engine initialization ////////////////


////////////////////////////////Error handling interface //////////////////
typedef rchandle<Item> Item_t;

class Store;





///the user can define its function for comparing strings 
///return -1, 0, 1 for less, equal, bigger
typedef int user_collation(uint32_t codepoint1, uint32_t codepoint2);

class XQueryResult : public rcobject
{
public:
	virtual ~XQueryResult() {};
	virtual Item_t		next() = 0;
	virtual void setAlertsParam(void *alert_callback_param) = 0;
  virtual std::ostream& serializeXML( std::ostream& os ) = 0;
	virtual bool isError() = 0;

	virtual void	AbortQueryExecution() = 0;
};

typedef rchandle<XQueryResult>		XQueryResult_t;

/// the Static Context
/// this class represents only the part that is the interface to the user
class StaticQueryContext
{
public:
	typedef enum { cons_preserve, cons_strip } construction_mode_t;
	typedef enum { empty_greatest, empty_least } order_empty_mode_t;
	typedef enum { preserve_space, strip_space } boundary_space_mode_t;
	typedef enum { inherit_ns, no_inherit_ns } inherit_mode_t;
	typedef enum { preserve_ns, no_preserve_ns } preserve_mode_t;

	typedef enum { ordered, unordered } ordering_mode_t;

public:
  virtual ~StaticQueryContext() { }

	virtual void		SetXPath1_0CompatibMode( bool mode ) = 0;///true for XPath1.0 only, false for XPath2.0 (default false)
	virtual bool		GetXPath1_0CompatibMode( ) = 0;///true for XPath1.0 only, false for XPath2.0

	virtual void		AddNamespace( xqpString prefix, xqpString URI ) = 0;//override the previous set prefix
	virtual xqpString		GetNamespaceURIByPrefix( xqpString prefix ) = 0;
//	virtual xqpString		GetNamespacePrefixByURI( xqpString URI ) = 0;
	virtual xqpString		DeleteNamespace( xqpString prefix ) = 0;
	virtual unsigned int	GetNamespaceCount() = 0;
	virtual bool		GetNamespaceByIndex( int i, xqpString *prefix, xqpString *URI ) = 0;
	virtual void		DeleteAllNamespaces() = 0;

	virtual void		SetDefaultElementAndTypeNamespace( xqpString URI ) = 0;///default is none
	virtual xqpString		GetDefaultElementAndTypeNamespace( ) = 0;

	virtual void		SetDefaultFunctionNamespace( xqpString URI ) = 0;///default is none
	virtual xqpString		GetDefaultFunctionNamespace( ) = 0;

	//here some functions for schema ... not impl yet

	virtual void		AddExternalVariableType( QNameItem_t	var_name, TypeIdentifier* var_type) = 0;
	virtual TypeIdentifier*	GetExternalVariableType( QNameItem_t	var_name ) = 0;
	virtual void		DeleteExternalVariableType( QNameItem_t var_name ) = 0;
	virtual	unsigned int			GetExternalVariableCount() = 0;
	virtual	bool		GetExternalVariableByIndex( unsigned int i, QNameItem_t *var_name, TypeIdentifier* *var_type ) = 0;
	virtual void		DeleteAllVariables() = 0;

	virtual void		SetContextItemStaticType( TypeIdentifier*		type ) = 0;
	virtual TypeIdentifier*		GetContextItemStaticType( ) = 0;

	///here some api for external functions
	// virtual void AddExternalFunction( QNameItem_t func_name, extern_func *cpp_func, TypeIdentifier *type_of_result, ...);//and the types of parameters
	// virtual void	DeleteAllExternalFunctions();

	virtual void		AddCollation( xqpString URI, std::string  coll_string, ::Collator::ECollationStrength coll_strength ) = 0;//if URI is empty then it sets the default collation
	virtual bool		IsCollationPresent( xqpString URI) = 0;//if URI is empty then it sets the default collation
	virtual void		DeleteCollation( xqpString URI) = 0;//if URI is empty then it sets the default collation
	virtual int			GetCollationCount() = 0;
	virtual bool		GetCollationInfoByIndex( int i, xqpString *URI, std::string *coll_string, ::Collator::ECollationStrength *coll_strength ) = 0;
	virtual void		DeleteAllCustomCollations() = 0;

	virtual void		SetDefaultCollation( std::string  coll_string, ::Collator::ECollationStrength coll_strength ) = 0;

	virtual void		SetConstructionMode( construction_mode_t ) = 0;
	virtual construction_mode_t		GetConstructionMode( ) = 0;

	virtual void		SetOrderingMode( ordering_mode_t ) = 0;
	virtual ordering_mode_t		GetOrderingMode( ) = 0;

	virtual void		SetDefaultOrderForEmptySequences( order_empty_mode_t ) = 0;
	virtual order_empty_mode_t		GetDefaultOrderForEmptySequences( ) = 0;

	virtual void		SetBoundarySpacePolicy( boundary_space_mode_t ) = 0;
	virtual boundary_space_mode_t		GetBoundarySpacePolicy( ) = 0;

	virtual void		SetCopyNamespacesMode( preserve_mode_t preserve, inherit_mode_t inherit ) = 0;
	virtual void		GetCopyNamespacesMode( preserve_mode_t *preserve, inherit_mode_t *inherit ) = 0;

	virtual void		SetBaseURI( xqpString baseURI ) = 0;
	virtual xqpString		GetBaseURI( ) = 0;

	//statically known documents (types)
	virtual void		AddDocumentType( xqpString URI, TypeIdentifier* doc_type ) = 0;
	virtual TypeIdentifier*		GetDocumentType( xqpString URI) = 0;
	virtual void		DeleteDocumentType( xqpString URI) = 0;
	virtual int			GetDocumentTypeCount() = 0;
	virtual void		GetDocumentByIndex( int i, xqpString *URI, TypeIdentifier **doc_type ) = 0;
	virtual void		DeleteAllDocumentTypes() = 0;

	virtual void		AddCollectionType( xqpString URI, TypeIdentifier*		collection_type ) = 0;///if URI is empty then it refers to default collection type
	virtual TypeIdentifier*		GetCollectionType( xqpString URI ) = 0;///if URI is empty then it refers to default collection type
	virtual void		DeleteCollectionType( xqpString URI ) = 0;///if URI is empty then it refers to default collection type
	virtual int			GetCollectionTypeCount() = 0;
	virtual void		GetCollectionTypeByIndex( int i, xqpString *URI, TypeIdentifier **collection_type ) = 0;
	virtual void		DeleteAllCollectionTypes() = 0;

	virtual void		SetDefaultCollectionType( TypeIdentifier *default_collection_type ) = 0;///default node()*
	virtual TypeIdentifier*	GetDefaultCollectionType( ) = 0;

};


class DynamicQueryContext : public rcobject
{
	int			current_date_time;
	int			implicit_timezone;


	///following is the input data; this is not duplicable between executions
	virtual bool SetVariable( Zorba_QName *varname, XQueryResult *item_iter ) = 0;
	virtual bool SetVariable( Zorba_QName *varname, Item_t &item ) = 0;
	virtual bool DeleteVariable( Zorba_QName *varname ) = 0;


	///register documents available through fn:doc() in xquery
	virtual bool RegisterAvailableDocument(xqp_string docURI,
																			xqp_string store_docURI) = 0;
	///register collections available through fn:collection() in xquery
	///default collection has empty URI ""
	virtual bool RegisterAvailableCollection(xqp_string collectionURI,
																			xqp_string store_collectionURI) = 0;
};




class XQuery : public rcobject
{
    //XQuery( );
public:
		virtual ~XQuery() {};

public:


    // StaticQueryContext is optional
		//daniel: return true for success
		// Matthias: how to return errors? daniel: using the error manager
    // routing_mode: should documents in a collection be filtered or queried completely
    //         if filtered, the result will be a sequences of URI, one for each qualifying documents
    //virtual bool compile(StaticQueryContext* = 0, bool routing_mode = false) = 0;

    // execute the query 
		//daniel: return NULL for error
		// Matthias: again, how tu return errors? daniel: using the error manager
    // the DynamicQueryContext does not need to be passed, a default one can always be used
		//alert_callback_param is the param to be passed to the error callback function when executing next()
    virtual XQueryResult_t execute( DynamicQueryContext* = 0) = 0;

    //virtual bool isCompiled() = 0;

    // clone the query (can be compiled or not compiled)
   // QueryPtr clone();

		//daniel: isn't the Query more suitable to serialize itself?
    virtual bool   serializeQuery(std::ostream &os) = 0;

public:
    // getters/setters for Static- and DynamicQueryContext
    // a default static and dynamiccontext is always available

    // Matthias: don't call it internal
    // there is no need to distinguish interal and external
		virtual StaticQueryContext* getInternalStaticContext() = 0;
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

	//register a callback specific to this xquery object
	//	virtual void RegisterAlertCallback(alert_callback	*user_alert_callback,
	//																		void *param) = 0;
};    

typedef rchandle<XQuery>	XQuery_t;

//class ZorbaFactory;

class ZorbaFactory
{
private:
	ZorbaFactory();

public:
	static ZorbaFactory& getInstance();

	static void shutdownZorbaEngine();

	void InitThread(
        error_messages *em = NULL,
        const char *collator_name = "root",
        ::Collator::ECollationStrength collator_strength = ::Collator::PRIMARY);

	void UninitThread();

  XQuery_t createQuery(
        const char* aQueryString,
        StaticQueryContext* = 0, 
        bool routing_mode = false);

	Zorba_AlertsManager& getAlertsManagerForCurrentThread();
};



}//end namespace xqp

#endif
