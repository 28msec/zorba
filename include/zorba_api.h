///Created: Daniel Turcanu @ IPDevel 



#ifndef ZORBA_XQUERY_CPP_API_HEADER
#define ZORBA_XQUERY_CPP_API_HEADER


#include "store/api/item.h"
#include "store/api/collection.h"
#include "util/rchandle.h"
#include "error_api.h"

///from ICU
#include <unicode/coll.h>

#include "types/typeident.h"

#include <time.h>

namespace xqp {


typedef rchandle<Item> Item_t;


class XQueryExecution : public Iterator
{
public:
	virtual ~XQueryExecution() {};
//	virtual Item_t		next() = 0;
  virtual Item_t next() = 0;
  virtual void reset() = 0;
  virtual void close() = 0;
	virtual void setAlertsParam(void *alert_callback_param) = 0;
  virtual std::ostream& serialize( std::ostream& os ) = 0;
  virtual std::ostream& serializeXML( std::ostream& os ) = 0;
  virtual std::ostream& serializeHTML( std::ostream& os ) = 0;
  virtual std::ostream& serializeTEXT( std::ostream& os ) = 0;
	virtual bool isError() = 0;

	virtual void	AbortQueryExecution() = 0;

	///extension from dynamic context (specific only for this execution)
	virtual bool AddVariable( xqp_string varname, XQueryExecution_t item_iter ) = 0;

	///register documents available through fn:doc() in xquery
	virtual bool AddAvailableDocument(xqp_string docURI,
																		Item_t docitem) = 0;
	///register collections available through fn:collection() in xquery
	///default collection has empty URI ""
	virtual bool AddAvailableCollection(xqp_string collectionURI,
																			Collection_t) = 0;

};

typedef rchandle<XQueryExecution>		XQueryExecution_t;
/*
class CollationInfo : public rcobject
{
	std::string  coll_string;
	::Collator::ECollationStrength coll_strength;

	::Collator *coll;
public:
	CollationInfo();
	CollationInfo( ::Collator *coll );
	CollationInfo( std::string  coll_string, ::Collator::ECollationStrength coll_strength);
	~CollationInfo();

	::Collator	*getCollator();
	std::string	getLocaleString();
	::Collator::ECollationStrength getCollatorStrength();
};

typedef rchandle<CollationInfo>		CollationInfo_t;
*/
typedef struct 
{
	xqp_string		URI;
	std::string		coll_string;
	::Collator::ECollationStrength	coll_strength;
	::Collator		*coll;

}CollationInfo;
/// the Static Context
/// this class represents only the part that is the interface to the user
class StaticQueryContext : public rcobject
{
public:
	typedef enum { xpath2_0, xpath1_0_only }		xpath1_0compatib_mode_t;
	typedef enum { cons_preserve, cons_strip }	construction_mode_t;
	typedef enum { ordered, unordered }					ordering_mode_t;
	typedef enum { empty_greatest, empty_least } order_empty_mode_t;
	typedef enum { preserve_space, strip_space } boundary_space_mode_t;
	typedef enum { inherit_ns, no_inherit_ns }	inherit_mode_t;
	typedef enum { preserve_ns, no_preserve_ns } preserve_mode_t;


public:
  virtual ~StaticQueryContext() { }

	virtual void		SetXPath1_0CompatibMode( xpath1_0compatib_mode_t mode ) = 0;///true for XPath1.0 only, false for XPath2.0 (default false)
	virtual xpath1_0compatib_mode_t		GetXPath1_0CompatibMode( ) = 0;///true for XPath1.0 only, false for XPath2.0

	virtual void		AddNamespace( xqp_string prefix, xqp_string URI ) = 0;//override the previous set prefix
	virtual xqp_string		GetNamespaceURIByPrefix( xqp_string prefix ) = 0;
//	virtual xqp_string		GetNamespacePrefixByURI( xqp_string URI ) = 0;
	virtual void		DeleteNamespace( xqp_string prefix ) = 0;
	virtual unsigned int	GetNamespaceCount() = 0;
	virtual bool		GetNamespaceByIndex( unsigned int i, xqp_string *prefix, xqp_string *URI ) = 0;
	virtual void		DeleteAllNamespaces() = 0;

	virtual void		SetDefaultElementAndTypeNamespace( xqp_string URI ) = 0;///default is none
	virtual xqp_string		GetDefaultElementAndTypeNamespace( ) = 0;

	virtual void		SetDefaultFunctionNamespace( xqp_string URI ) = 0;///default is none
	virtual xqp_string		GetDefaultFunctionNamespace( ) = 0;

	//here some functions for schema ... not impl yet

	virtual void		AddExternalVariableType( QNameItem_t	var_name, type_ident_ref_t var_type) = 0;
	virtual type_ident_ref_t	GetExternalVariableType( QNameItem_t	var_name ) = 0;
	virtual void		DeleteExternalVariableType( QNameItem_t var_name ) = 0;
	virtual	unsigned int			GetExternalVariableCount() = 0;
	virtual	bool		GetExternalVariableByIndex( unsigned int i, QNameItem_t *var_name, type_ident_ref_t *var_type ) = 0;
	virtual void		DeleteAllVariables() = 0;

	virtual void		SetContextItemStaticType( type_ident_ref_t		type ) = 0;
	virtual type_ident_ref_t		GetContextItemStaticType( ) = 0;

	///here some api for external functions
	// virtual void AddExternalFunction( QNameItem_t func_name, extern_func *cpp_func, TypeIdentifier *type_of_result, ...);//and the types of parameters
	// virtual void	DeleteAllExternalFunctions();

	virtual void		AddCollation( xqp_string URI, std::string  coll_string, ::Collator::ECollationStrength coll_strength = ::Collator::PRIMARY) = 0;
	virtual void		AddCollation( xqp_string URI, ::Collator *user_coll ) = 0;
	virtual CollationInfo*		GetCollation( xqp_string URI ) = 0;
	virtual void		DeleteCollation( xqp_string URI) = 0;
	virtual unsigned int			GetCollationCount() = 0;
	virtual CollationInfo*		GetCollationInfoByIndex( unsigned int i ) = 0;//std::string *coll_string, ::Collator::ECollationStrength *coll_strength ) = 0;
	virtual void		DeleteAllCollations() = 0;

	virtual void		SetDefaultCollation( xqp_string URI ) = 0;//std::string  coll_string, ::Collator::ECollationStrength coll_strength ) = 0;
	virtual xqp_string	GetDefaultCollation() = 0;

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

	virtual void		SetBaseURI( xqp_string baseURI ) = 0;
	virtual xqp_string		GetBaseURI( ) = 0;

	//statically known documents (types)
	virtual void		AddDocumentType( xqp_string URI, type_ident_ref_t doc_type ) = 0;
	virtual type_ident_ref_t		GetDocumentType( xqp_string URI) = 0;
	virtual void		DeleteDocumentType( xqp_string URI) = 0;
	virtual unsigned int			GetDocumentTypeCount() = 0;
	virtual bool		GetDocumentByIndex( unsigned int i, xqp_string *URI, type_ident_ref_t *doc_type ) = 0;
	virtual void		DeleteAllDocumentTypes() = 0;

	virtual void		AddCollectionType( xqp_string URI, type_ident_ref_t		collection_type ) = 0;///if URI is empty then it refers to default collection type
	virtual type_ident_ref_t		GetCollectionType( xqp_string URI ) = 0;///if URI is empty then it refers to default collection type
	virtual void		DeleteCollectionType( xqp_string URI ) = 0;///if URI is empty then it refers to default collection type
	virtual unsigned int			GetCollectionTypeCount() = 0;
	virtual bool		GetCollectionTypeByIndex( unsigned int i, xqp_string *URI, type_ident_ref_t *collection_type ) = 0;
	virtual void		DeleteAllCollectionTypes() = 0;

	virtual void		SetDefaultCollectionType( type_ident_ref_t default_collection_type ) = 0;///default node()*
	virtual type_ident_ref_t	GetDefaultCollectionType( ) = 0;

};

typedef rchandle<StaticQueryContext>	StaticQueryContext_t;


class DynamicQueryContext : public rcobject
{
public:
	typedef enum
	{
		//XS_DECIMAL,//derived from XS_ANY_ATOMIC_TYPE
		XS_INTEGER,//derived from XS_DECIMAL
		XS_NON_POSITIVE_INTEGER,//derived from XS_INTEGER
		XS_NEGATIVE_INTEGER,//derived from XS_NON_POSITIVE_INTEGER
		XS_LONG,//derived from XS_INTEGER
		XS_INT,//derived from XS_LONG
		XS_SHORT,//derived from XS_INT
		XS_BYTE,//derived from XS_SHORT
		XS_NON_NEGATIVE_INTEGER,//derived from XS_INTEGER
		XS_UNSIGNED_LONG,//derived from XS_NON_NEGATIVE_INTEGER
		XS_UNSIGNED_INT,//derived from XS_UNSIGNED_LONG
		XS_UNSIGNED_SHORT,//derived from XS_UNSIGNED_INT
		XS_UNSIGNED_BYTE,//derived from XS_UNSIGNED_SHORT
		XS_POSITIVE_INTEGER//derived from XS_NON_NEGATIVE_INTEGER
	}VAR_INT_TYPE;
	typedef enum
	{
		XS_STRING,//derived from XS_ANY_ATOMIC_TYPE
		XS_NORMALIZED_STRING,//derived from XS_STRING
		XS_TOKEN,//derived from XS_NORMALIZED_STRING
		XS_LANGUAGE,//derived from XS_TOKEN
		XS_NMTOKEN,//derived from XS_TOKEN
		XS_NAME,//derived from XS_TOKEN
		XS_NCNAME,//derived from XS_NAME
		XS_ID,//derived from XS_NCNAME
		XS_IDREF,//derived from XS_NCNAME
		XS_ENTITY,//derived from XS_NCNAME
		XS_NOTATION,
		XS_ANYURI,
		XS_UNTYPED_ATOMIC
	}VAR_STR_TYPE;
	typedef enum
	{
		XS_DECIMAL,
		XS_FLOAT,
		XS_DOUBLE
	}VAR_DOUBLE_TYPE;
	typedef enum
	{
		XS_DATETIME,
		XS_DATE,
		XS_TIME,
		XS_GYEAR_MONTH,
		XS_GYEAR,
		XS_GMONTH_DAY,
		XS_GDAY,
		XS_GMONTH,
	}VAR_DATETIME_TYPE;
public:
	time_t	current_date_time;
	int			implicit_timezone;

	virtual ~DynamicQueryContext( ) {};

	///following is the input data; this is not duplicable between executions
//	virtual bool SetVariable( QNameItem_t varname, XQueryExecution_t item_iter ) = 0;
	virtual bool SetVariable( xqp_string varname, long long int_value, VAR_INT_TYPE type = XS_INTEGER) = 0;
	virtual bool SetVariable( xqp_string varname, xqp_string str_value, VAR_STR_TYPE type = XS_STRING) = 0;
	virtual bool SetVariable( xqp_string varname, long double double_value, VAR_DOUBLE_TYPE type = XS_DOUBLE) = 0;
	virtual bool SetVariable( xqp_string varname, bool bool_value) = 0;
	virtual bool SetVariable( xqp_string varname, struct tm datetime_value, VAR_DATETIME_TYPE type = XS_DATETIME) = 0;

	virtual bool DeleteVariable( xqp_string varname ) = 0;
	virtual void DeleteAllVariables( ) = 0;


	///register documents available through fn:doc() in xquery
//	virtual bool RegisterAvailableDocument(xqp_string docURI,
//																			xqp_string store_docURI) = 0;
	///register collections available through fn:collection() in xquery
	///default collection has empty URI ""
//	virtual bool RegisterAvailableCollection(xqp_string collectionURI,
//																			xqp_string store_collectionURI) = 0;

	virtual void SetDefaultCollection( xqp_string collectionURI ) = 0;
};

typedef rchandle<DynamicQueryContext>	DynamicQueryContext_t;



class XQuery : public rcobject
{
    //XQuery( );
public:
		virtual ~XQuery() {};

public:

    // execute the query 
		//daniel: return NULL for error
		// Matthias: again, how tu return errors? daniel: using the error manager
    // the DynamicQueryContext does not need to be passed, a default one can always be used
    virtual XQueryExecution_t createExecution( DynamicQueryContext_t = 0) = 0;

		//daniel: isn't the Query more suitable to serialize itself?
    virtual bool   serializeQuery(std::ostream &os) = 0;

public:
    // getters/setters for Static- and DynamicQueryContext
    // a default static and dynamiccontext is always available

    // Matthias: don't call it internal
    // there is no need to distinguish interal and external
		virtual StaticQueryContext_t getInternalStaticContext() = 0;
 //   DynamicQueryContextPtr getInternalDynamicContext();

public:

	//register a callback specific to this xquery object
	//	virtual void RegisterAlertCallback(alert_callback	*user_alert_callback,
	//																		void *param) = 0;
};    

typedef rchandle<XQuery>	XQuery_t;

class ZorbaFactory
{
private:
	ZorbaFactory();

public:
	static ZorbaFactory& getInstance();

	static void shutdownZorbaEngine();

	void InitThread(
        error_messages* em = NULL);

	void UninitThread();

  XQuery_t createQuery(
        const char* aQueryString,
        StaticQueryContext_t = 0, 
				xqp_string	xquery_source_uri = "",
        bool routing_mode = false);

	Zorba_AlertsManager& getAlertsManagerForCurrentThread();

	void		setDefaultCollation(std::string  coll_string, ::Collator::ECollationStrength coll_strength = ::Collator::PRIMARY);
	void		setDefaultCollation(::Collator *default_coll);
	void		getDefaultCollation(std::string  *coll_string, ::Collator::ECollationStrength *coll_strength, ::Collator **default_coll);

	void		setItemSerializerParameter(xqp_string parameter_name, xqp_string value);
	void		setDocSerializerParameter(xqp_string parameter_name, xqp_string value);


	StaticQueryContext_t createStaticContext();
	DynamicQueryContext_t createDynamicContext();

};



}//end namespace xqp

#endif
