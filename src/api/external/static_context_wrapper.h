#ifndef ZORBA_XQUERY_STATIC_CONTEXT_WRAPPER_20_NOV_2007
#define ZORBA_XQUERY_STATIC_CONTEXT_WRAPPER_20_NOV_2007

#include "context/static_context_api.h"
//#include "context/static_context.h"

#include <vector>
#include "util/hashmap.h"

namespace xqp{

class static_context;

class StaticContextWrapper : public StaticQueryContext //defined in zorba_api
{
public:

	typedef struct
	{
		xqp_string		qname;
		type_ident_ref_t		type;
	}scw_QName_plus_type;

	typedef struct
	{
		xqp_string		prefix, URI;
	}scw_namespace_t;


	typedef struct
	{
		xqp_string					URI;
		type_ident_ref_t		type;
	}scw_URI_plus_type;

	xpath1_0compatib_mode_t		xpath1_0compatib_mode;
	
	std::vector<scw_namespace_t>				ext_ns_list;
	bool													default_elem_ns_was_set;
	xqp_string										default_elem_ns;
	bool													default_fun_ns_was_set;
	xqp_string										default_fun_ns;
	std::vector<scw_QName_plus_type>		ext_var_list;
	type_ident_ref_t							context_item_type;
	std::vector<CollationInfo>		collation_list;
	bool													default_collation_URI_was_set;
	xqp_string										default_collation_URI;
	construction_mode_t						construction_mode;
	ordering_mode_t								ordering_mode;
	order_empty_mode_t						order_empty_mode;
	boundary_space_mode_t					boundary_space_mode;
	preserve_mode_t								preserve_mode;
	inherit_mode_t								inherit_mode;
	bool													baseURI_was_set;
	xqp_string										baseURI;
	std::vector<scw_URI_plus_type>		doc_type_list;
	std::vector<scw_URI_plus_type>		collection_type_list;
	type_ident_ref_t							default_collection_type;

  // contains all the stateless external functions
  hashmap<StatelessExternalFunction_t>  stateless_ext_functions;

public:

	StaticContextWrapper();
	virtual ~StaticContextWrapper();

	virtual void		setXPath1_0CompatibMode( xpath1_0compatib_mode_t mode );///true for XPath1.0 only, false for XPath2.0 (default false)
	virtual xpath1_0compatib_mode_t		getXPath1_0CompatibMode( );///true for XPath1.0 only, false for XPath2.0

	virtual bool		addNamespace( xqp_string prefix, xqp_string URI );//override the previous set prefix
	virtual xqp_string		getNamespaceURIByPrefix( xqp_string prefix );
//	virtual xqp_string		getNamespacePrefixByURI( xqp_string URI );
	virtual void		deleteNamespace( xqp_string prefix );
	virtual unsigned int	getNamespaceCount();
	virtual bool		getNamespaceByIndex( unsigned int i, xqp_string *prefix, xqp_string *URI );
	virtual void		deleteAllNamespaces();

	virtual void		setDefaultElementAndTypeNamespace( xqp_string URI );///default is none
	virtual xqp_string		getDefaultElementAndTypeNamespace( );

	virtual void		setDefaultFunctionNamespace( xqp_string URI );///default is none
	virtual xqp_string		getDefaultFunctionNamespace( );

	//here some functions for schema ... not impl yet

	virtual void		addExternalVariableType( xqp_string	var_name, type_ident_ref_t var_type);
	virtual type_ident_ref_t	getExternalVariableType( xqp_string	var_name );
	virtual void		deleteExternalVariableType( xqp_string var_name );
	virtual	unsigned int			getExternalVariableCount();
	virtual	bool		getExternalVariableByIndex( unsigned int i, xqp_string *var_name, type_ident_ref_t *var_type );
	virtual void		deleteAllVariables();

	virtual void		setContextItemStaticType( type_ident_ref_t		type );
	virtual type_ident_ref_t		getContextItemStaticType( );

	///here some api for external functions
	// virtual void AddExternalFunction( xqp_string func_name, extern_func *cpp_func, TypeIdentifier *type_of_result, ...);//and the types of parameters
	// virtual void	DeleteAllExternalFunctions();

	virtual void		addCollation( xqp_string URI, std::string  coll_string, ::Collator::ECollationStrength coll_strength = ::Collator::PRIMARY);//if URI is empty then it sets the default collation
	virtual void		addCollation( xqp_string URI, ::Collator *user_coll );
	virtual CollationInfo*		getCollation( xqp_string URI);//if URI is empty then it sets the default collation
	virtual void		deleteCollation( xqp_string URI);//if URI is empty then it sets the default collation
	virtual unsigned int			getCollationCount();
	virtual CollationInfo*		getCollationInfoByIndex( unsigned int i );//std::string *coll_string, ::Collator::ECollationStrength *coll_strength );
	virtual void		deleteAllCollations();

	virtual void		setDefaultCollation( xqp_string URI );//std::string  coll_string, ::Collator::ECollationStrength coll_strength );
	virtual xqp_string	getDefaultCollation();

	virtual void		setConstructionMode( construction_mode_t );
	virtual construction_mode_t		getConstructionMode( );

	virtual void		setOrderingMode( ordering_mode_t );
	virtual ordering_mode_t		getOrderingMode( );

	virtual void		setDefaultOrderForEmptySequences( order_empty_mode_t );
	virtual order_empty_mode_t		getDefaultOrderForEmptySequences( );

	virtual void		setBoundarySpacePolicy( boundary_space_mode_t );
	virtual boundary_space_mode_t		getBoundarySpacePolicy( );

	virtual void		setCopyNamespacesMode( preserve_mode_t preserve, inherit_mode_t inherit );
	virtual void		getCopyNamespacesMode( preserve_mode_t *preserve, inherit_mode_t *inherit );

	virtual bool		setBaseURI( xqp_string baseURI );
	virtual xqp_string		getBaseURI( );

	//statically known documents (types)
	virtual void		addDocumentType( xqp_string URI, type_ident_ref_t doc_type );
	virtual type_ident_ref_t		getDocumentType( xqp_string URI);
	virtual void		deleteDocumentType( xqp_string URI);
	virtual unsigned int			getDocumentTypeCount();
	virtual bool		getDocumentByIndex( unsigned int i, xqp_string *URI, type_ident_ref_t *doc_type );
	virtual void		deleteAllDocumentTypes();

	virtual void		addCollectionType( xqp_string URI, type_ident_ref_t		collection_type );///if URI is empty then it refers to default collection type
	virtual type_ident_ref_t		getCollectionType( xqp_string URI );///if URI is empty then it refers to default collection type
	virtual void		deleteCollectionType( xqp_string URI );///if URI is empty then it refers to default collection type
	virtual unsigned int			getCollectionTypeCount();
	virtual bool		getCollectionTypeByIndex( unsigned int i, xqp_string *URI, type_ident_ref_t *collection_type );
	virtual void		deleteAllCollectionTypes();

	virtual void		setDefaultCollectionType( type_ident_ref_t default_collection_type );///default node()*
	virtual type_ident_ref_t	getDefaultCollectionType( );


	static_context*		fillInStaticContext();

  /**
   * functions that are used for registering external functions
   */
  virtual void registerStatelessExternalFunction(StatelessExternalFunction_t aExternalFunction);

};

//typedef rchandle<StaticContextWrapper>		StaticContextWrapper_t;

}///end namespace xqp

#endif
