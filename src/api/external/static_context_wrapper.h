#ifndef ZORBA_XQUERY_STATIC_CONTEXT_WRAPPER_20_NOV_2007
#define ZORBA_XQUERY_STATIC_CONTEXT_WRAPPER_20_NOV_2007

#include "context/static_context_api.h"
#include "context/static_context.h"

namespace xqp{

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

public:

	StaticContextWrapper();
	virtual ~StaticContextWrapper();

	virtual void		SetXPath1_0CompatibMode( xpath1_0compatib_mode_t mode );///true for XPath1.0 only, false for XPath2.0 (default false)
	virtual xpath1_0compatib_mode_t		GetXPath1_0CompatibMode( );///true for XPath1.0 only, false for XPath2.0

	virtual bool		AddNamespace( xqp_string prefix, xqp_string URI );//override the previous set prefix
	virtual xqp_string		GetNamespaceURIByPrefix( xqp_string prefix );
//	virtual xqp_string		GetNamespacePrefixByURI( xqp_string URI );
	virtual void		DeleteNamespace( xqp_string prefix );
	virtual unsigned int	GetNamespaceCount();
	virtual bool		GetNamespaceByIndex( unsigned int i, xqp_string *prefix, xqp_string *URI );
	virtual void		DeleteAllNamespaces();

	virtual void		SetDefaultElementAndTypeNamespace( xqp_string URI );///default is none
	virtual xqp_string		GetDefaultElementAndTypeNamespace( );

	virtual void		SetDefaultFunctionNamespace( xqp_string URI );///default is none
	virtual xqp_string		GetDefaultFunctionNamespace( );

	//here some functions for schema ... not impl yet

	virtual void		AddExternalVariableType( xqp_string	var_name, type_ident_ref_t var_type);
	virtual type_ident_ref_t	GetExternalVariableType( xqp_string	var_name );
	virtual void		DeleteExternalVariableType( xqp_string var_name );
	virtual	unsigned int			GetExternalVariableCount();
	virtual	bool		GetExternalVariableByIndex( unsigned int i, xqp_string *var_name, type_ident_ref_t *var_type );
	virtual void		DeleteAllVariables();

	virtual void		SetContextItemStaticType( type_ident_ref_t		type );
	virtual type_ident_ref_t		GetContextItemStaticType( );

	///here some api for external functions
	// virtual void AddExternalFunction( xqp_string func_name, extern_func *cpp_func, TypeIdentifier *type_of_result, ...);//and the types of parameters
	// virtual void	DeleteAllExternalFunctions();

	virtual void		AddCollation( xqp_string URI, std::string  coll_string, ::Collator::ECollationStrength coll_strength = ::Collator::PRIMARY);//if URI is empty then it sets the default collation
	virtual void		AddCollation( xqp_string URI, ::Collator *user_coll );
	virtual CollationInfo*		GetCollation( xqp_string URI);//if URI is empty then it sets the default collation
	virtual void		DeleteCollation( xqp_string URI);//if URI is empty then it sets the default collation
	virtual unsigned int			GetCollationCount();
	virtual CollationInfo*		GetCollationInfoByIndex( unsigned int i );//std::string *coll_string, ::Collator::ECollationStrength *coll_strength );
	virtual void		DeleteAllCollations();

	virtual void		SetDefaultCollation( xqp_string URI );//std::string  coll_string, ::Collator::ECollationStrength coll_strength );
	virtual xqp_string	GetDefaultCollation();

	virtual void		SetConstructionMode( construction_mode_t );
	virtual construction_mode_t		GetConstructionMode( );

	virtual void		SetOrderingMode( ordering_mode_t );
	virtual ordering_mode_t		GetOrderingMode( );

	virtual void		SetDefaultOrderForEmptySequences( order_empty_mode_t );
	virtual order_empty_mode_t		GetDefaultOrderForEmptySequences( );

	virtual void		SetBoundarySpacePolicy( boundary_space_mode_t );
	virtual boundary_space_mode_t		GetBoundarySpacePolicy( );

	virtual void		SetCopyNamespacesMode( preserve_mode_t preserve, inherit_mode_t inherit );
	virtual void		GetCopyNamespacesMode( preserve_mode_t *preserve, inherit_mode_t *inherit );

	virtual void		SetBaseURI( xqp_string baseURI );
	virtual xqp_string		GetBaseURI( );

	//statically known documents (types)
	virtual void		AddDocumentType( xqp_string URI, type_ident_ref_t doc_type );
	virtual type_ident_ref_t		GetDocumentType( xqp_string URI);
	virtual void		DeleteDocumentType( xqp_string URI);
	virtual unsigned int			GetDocumentTypeCount();
	virtual bool		GetDocumentByIndex( unsigned int i, xqp_string *URI, type_ident_ref_t *doc_type );
	virtual void		DeleteAllDocumentTypes();

	virtual void		AddCollectionType( xqp_string URI, type_ident_ref_t		collection_type );///if URI is empty then it refers to default collection type
	virtual type_ident_ref_t		GetCollectionType( xqp_string URI );///if URI is empty then it refers to default collection type
	virtual void		DeleteCollectionType( xqp_string URI );///if URI is empty then it refers to default collection type
	virtual unsigned int			GetCollectionTypeCount();
	virtual bool		GetCollectionTypeByIndex( unsigned int i, xqp_string *URI, type_ident_ref_t *collection_type );
	virtual void		DeleteAllCollectionTypes();

	virtual void		SetDefaultCollectionType( type_ident_ref_t default_collection_type );///default node()*
	virtual type_ident_ref_t	GetDefaultCollectionType( );


	static_context*		FillInStaticContext();

};

//typedef rchandle<StaticContextWrapper>		StaticContextWrapper_t;

}///end namespace xqp

#endif
