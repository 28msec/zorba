
#include "static_context_wrapper.h"
#include "system/globalenv.h"
#include "errors/error_manager.h"
#include "system/zorba_engine.h"

namespace xqp{

/*
CollationInfo::CollationInfo()
{
	coll = NULL;
}

CollationInfo::CollationInfo( ::Collator *coll )
{
	this->coll = coll;//take control of the collator pointer
}

CollationInfo::CollationInfo( std::string  coll_string, ::Collator::ECollationStrength coll_strength)
{
	this->coll_string = coll_string;
	this->coll_strength = coll_strength;
	this->coll = NULL;
}

CollationInfo::~CollationInfo()
{
	if(coll)
		delete coll;//we take control of the collator pointer
}

::Collator* CollationInfo::getCollator()
{
	return this->coll;
}

std::string	CollationInfo::getLocaleString()
{
	return this->coll_string;
}

::Collator::ECollationStrength CollationInfo::getCollatorStrength()
{
	return this->coll_strength;
}
*/

StaticContextWrapper::StaticContextWrapper()
{
	try{

	xpath1_0compatib_mode = (xpath1_0compatib_mode_t)-1;//not initialized
	
//	std::vector<scw_namespace_t>				ext_ns_list;
	default_elem_ns_was_set = false;
//	namespace_t										default_elem_ns;
	default_fun_ns_was_set = false;
//	namespace_t										default_fun_ns;
//	std::vector<scw_QName_plus_type>		ext_var_list;
//	type_ident_ref_t							context_item_type;
//	std::vector<scw_collation_t>		collation_list;
	default_collation_URI_was_set = false;
//	xqp_string										default_collation_URI;
	construction_mode = (construction_mode_t)-1;//not initialized
	ordering_mode = (ordering_mode_t)-1;//not initialized
	order_empty_mode = (order_empty_mode_t)-1;//not initialized
	boundary_space_mode = (boundary_space_mode_t)-1;//not initialized
	preserve_mode = (preserve_mode_t)-1;//not initialized
	inherit_mode = (inherit_mode_t)-1;//not initialized
	baseURI_was_set = false;
//	xqp_string										baseURI;
//	std::vector<scw_URI_plus_type>		doc_type_list;
//	std::vector<scw_URI_plus_type>		collection_type_list;
//	type_ident_ref_t							default_collection_type;
	}CATCH_ALL_NO_RETURN(;);
}

StaticContextWrapper::~StaticContextWrapper()
{
}

void		StaticContextWrapper::SetXPath1_0CompatibMode( xpath1_0compatib_mode_t mode )///true for XPath1.0 only, false for XPath2.0 (default false)
{
	xpath1_0compatib_mode = mode ;
}

StaticQueryContext::xpath1_0compatib_mode_t		StaticContextWrapper::GetXPath1_0CompatibMode( )///true for XPath1.0 only, false for XPath2.0
{
	if(xpath1_0compatib_mode >= 0)
		return xpath1_0compatib_mode;//previously set by user
	//else take the default value from root_static_context

	return static_context::root_static_context()->xpath1_0compatib_mode();
}

bool		StaticContextWrapper::AddNamespace( xqp_string prefix, xqp_string URI )//override the previous set prefix
{
	try{
//	internal_stcx.bind_ns( prefix, URI );
	scw_namespace_t		ns;

	if((prefix == "xml") || (prefix == "xmlns"))
		return false;//ignore that

	ns.prefix = prefix;
	ns.URI = URI;

	ext_ns_list.push_back(ns);
	return true;
	}CATCH_ALL_RETURN_false;
}

xqp_string		StaticContextWrapper::GetNamespaceURIByPrefix( xqp_string prefix )
{
//	return internal_stcx.lookup_ns( prefix );

	//blind search
	std::vector<scw_namespace_t>::iterator		it;
	for(it = ext_ns_list.begin(); it != ext_ns_list.end(); it++)
	{
		if((*it).prefix == prefix)
		{
			return (*it).URI;
		}
	}

	return "";
}

void		StaticContextWrapper::DeleteNamespace( xqp_string prefix )
{
	try{
	//blind search
	std::vector<scw_namespace_t>::iterator		it;
	for(it = ext_ns_list.begin(); it != ext_ns_list.end(); it++)
	{
		if((*it).prefix == prefix)
		{
			ext_ns_list.erase(it);
			return;
		}
	}
	}CATCH_ALL_NO_RETURN(;);
}

unsigned int	StaticContextWrapper::GetNamespaceCount()
{
	return ext_ns_list.size();
}

bool		StaticContextWrapper::GetNamespaceByIndex( unsigned int i, xqp_string *prefix, xqp_string *URI )
{
	try{

	if(i >= ext_ns_list.size())
		return false;

	scw_namespace_t		&ns = ext_ns_list[i];
	if(prefix)
		*prefix = ns.prefix;
	if(URI)
		*URI = ns.URI;
	return true;
	}CATCH_ALL_RETURN_false;

}

void		StaticContextWrapper::DeleteAllNamespaces()
{
	ext_ns_list.clear();
}


void		StaticContextWrapper::SetDefaultElementAndTypeNamespace( xqp_string URI )///default is none
{
//	internal_stcx.set_default_elem_type_ns( URI );
	default_elem_ns = URI;
	default_elem_ns_was_set = true;
}

xqp_string		StaticContextWrapper::GetDefaultElementAndTypeNamespace( )
{
//	return internal_stcx.default_elem_type_ns();
	if(default_elem_ns_was_set)
		return default_elem_ns;

	//else return the default
	return static_context::root_static_context()->default_elem_type_ns();
}


void		StaticContextWrapper::SetDefaultFunctionNamespace( xqp_string URI )///default is none
{
//	internal_stcx.set_default_function_namespace( URI );
	default_fun_ns = URI;
	default_fun_ns_was_set = true;
}

xqp_string		StaticContextWrapper::GetDefaultFunctionNamespace( )
{
//	return internal_stcx.default_function_namespace();
	if(default_fun_ns_was_set)
		return default_fun_ns;

	//else return the default
	return static_context::root_static_context()->default_function_namespace();
}


	//here some functions for schema ... not impl yet...

void		StaticContextWrapper::AddExternalVariableType( xqp_string	var_name, type_ident_ref_t var_type)
{
	try{

	scw_QName_plus_type		var;

	DeleteExternalVariableType(var_name);

	var.qname = var_name;
	var.type = var_type;

	ext_var_list.push_back(var);

	}CATCH_ALL_NO_RETURN(;);
}

type_ident_ref_t	StaticContextWrapper::GetExternalVariableType( xqp_string	var_name )
{
	try{

	//blind search
	std::vector<scw_QName_plus_type>::iterator		it;
	for(it = ext_var_list.begin(); it != ext_var_list.end(); it++)
	{
		if((*it).qname == var_name)
		{
			return (*it).type;
		}
	}

	return NULL;

	}CATCH_ALL_RETURN_NULL;
}

void		StaticContextWrapper::DeleteExternalVariableType( xqp_string var_name )
{
	try{

	//blind search
	std::vector<scw_QName_plus_type>::iterator		it;
	for(it = ext_var_list.begin(); it != ext_var_list.end(); it++)
	{
		if((*it).qname == var_name)
		{
			ext_var_list.erase(it);
			return;
		}
	}

	}CATCH_ALL_NO_RETURN(;);
}

unsigned int			StaticContextWrapper::GetExternalVariableCount()
{
	return ext_var_list.size();
}

bool		StaticContextWrapper::GetExternalVariableByIndex( unsigned int i, xqp_string *var_name, type_ident_ref_t *var_type )
{
	try{

	if(i >= ext_var_list.size())
		return false;

	scw_QName_plus_type		&var = ext_var_list[i];
	if(var_name)
		*var_name = var.qname;
	if(var_type)
		*var_type = var.type;
	return true;

	}CATCH_ALL_RETURN_false;
}

void		StaticContextWrapper::DeleteAllVariables()
{
	ext_var_list.clear();
}

void		StaticContextWrapper::SetContextItemStaticType( type_ident_ref_t		type )
{
//	TypeSystem::xqtref_t		internal_type;
//	internal_type = GENV_TYPESYSTEM.create_type( *type );
//	//now what
//	internal_sctx.set_context_item_static_type( internal_type );

	context_item_type = type;
}

type_ident_ref_t		StaticContextWrapper::GetContextItemStaticType( )
{
	if(context_item_type.getp())
		return context_item_type;

	///else get the default value from root_static_context
	TypeSystem::xqtref_t t =  static_context::root_static_context()->context_item_static_type();

	return GENV_TYPESYSTEM.get_type_identifier(*t);
}

	///here some api for external functions
	// virtual void AddExternalFunction( QNameItem_t func_name, extern_func *cpp_func, TypeIdentifier *type_of_result, ...);//and the types of parameters
	// virtual void	DeleteAllExternalFunctions();

void		StaticContextWrapper::AddCollation( xqp_string URI, std::string  coll_string, ::Collator::ECollationStrength coll_strength )
{
	try{

	CollationInfo		cinfo;

	cinfo.URI = URI;
	cinfo.coll_string = coll_string;
	cinfo.coll_strength = coll_strength;
	cinfo.coll = NULL;
	collation_list.push_back(cinfo);

	}CATCH_ALL_NO_RETURN(;);
}

void		StaticContextWrapper::AddCollation( xqp_string URI, ::Collator	*coll)
{
	try{

	CollationInfo		cinfo;

	if(!coll)
		return;
	cinfo.URI = URI;
	cinfo.coll = coll;
	collation_list.push_back(cinfo);

	}CATCH_ALL_NO_RETURN(;);
}

CollationInfo*		StaticContextWrapper::GetCollation( xqp_string URI)
{
	try{

	//blind search
	std::vector<CollationInfo>::iterator		it;
	for(it = collation_list.begin(); it != collation_list.end(); it++)
	{
		if((*it).URI == URI)
		{
			return &*it;
		}
	}

	return NULL;

	}CATCH_ALL_RETURN_NULL;
}

void		StaticContextWrapper::DeleteCollation( xqp_string URI)
{
	try{

	//blind search
	std::vector<CollationInfo>::iterator		it;
	for(it = collation_list.begin(); it != collation_list.end(); it++)
	{
		if((*it).URI == URI)
		{
			collation_list.erase(it);
			return;
		}
	}
	}CATCH_ALL_NO_RETURN(;);
}

unsigned int			StaticContextWrapper::GetCollationCount()
{
	return collation_list.size();
}

CollationInfo*		StaticContextWrapper::GetCollationInfoByIndex( unsigned int i )
{
	try{

	if(i >= collation_list.size())
		return NULL;

	return &collation_list[i];

	}CATCH_ALL_RETURN_NULL;
}

void		StaticContextWrapper::DeleteAllCollations()
{
	collation_list.clear();
}


void		StaticContextWrapper::SetDefaultCollation( xqp_string URI )//std::string  coll_string, ::Collator::ECollationStrength coll_strength )
{
	default_collation_URI = URI;
	default_collation_URI_was_set = true;
}

xqp_string	StaticContextWrapper::GetDefaultCollation()
{
	if(default_collation_URI_was_set)
		return default_collation_URI;

	//else return the default collation from root_static_context
	return static_context::root_static_context()->default_collation_uri();
}



void		StaticContextWrapper::SetConstructionMode( construction_mode_t c)
{
	//internal_sctx.set_construction_mode( c );
	construction_mode = c;
}

StaticQueryContext::construction_mode_t		StaticContextWrapper::GetConstructionMode( )
{
//	return internal_sctx.construction_mode();
	if(construction_mode >= 0)
		return construction_mode;

	return static_context::root_static_context()->construction_mode();
}

void		StaticContextWrapper::SetOrderingMode( ordering_mode_t o)
{
	//internal_sctx.set_ordering_mode(o);
	ordering_mode = o;
}

StaticQueryContext::ordering_mode_t		StaticContextWrapper::GetOrderingMode( )
{
	//return internal_sctx.ordering_mode();
	if(ordering_mode >= 0)
		return ordering_mode;

	return static_context::root_static_context()->ordering_mode();
}


void		StaticContextWrapper::SetDefaultOrderForEmptySequences( order_empty_mode_t o)
{
	//internal_sctx.set_order_empty_mode( o );
	order_empty_mode = o;
}

StaticQueryContext::order_empty_mode_t		StaticContextWrapper::GetDefaultOrderForEmptySequences( )
{
	//return internal_sctx.order_empty_mode();
	if(order_empty_mode >= 0)
		return order_empty_mode;
	return static_context::root_static_context()->order_empty_mode();
}


void		StaticContextWrapper::SetBoundarySpacePolicy( boundary_space_mode_t b)
{
	//internal_sctx.set_boundary_space_mode( b );
	boundary_space_mode = b;
}

StaticQueryContext::boundary_space_mode_t		StaticContextWrapper::GetBoundarySpacePolicy( )
{
	//return internal_sctx.boundary_space_mode();
	if(boundary_space_mode >= 0)
		return boundary_space_mode;
	return static_context::root_static_context()->boundary_space_mode();

}

void		StaticContextWrapper::SetCopyNamespacesMode( preserve_mode_t preserve, inherit_mode_t inherit )
{
	//internal_sctx.set_preserve_mode( preserve );
	//internal_sctx.set_inherit_mode( inherit );
	preserve_mode = preserve;
	inherit_mode = inherit;
}

void		StaticContextWrapper::GetCopyNamespacesMode( preserve_mode_t *preserve, inherit_mode_t *inherit )
{
	if(preserve_mode >= 0)
	{
		*preserve = preserve_mode;
		*inherit = inherit_mode;
		return;
	}
	*preserve = static_context::root_static_context()->preserve_mode( );
	*inherit = static_context::root_static_context()->inherit_mode( );
}

void		StaticContextWrapper::SetBaseURI( xqp_string baseURI )
{
	//internal_sctx.set_baseuri( baseURI );
	this->baseURI = baseURI;
	baseURI_was_set = true;
}

xqp_string		StaticContextWrapper::GetBaseURI( )
{
	//return internal_sctx.baseuri();
	if(baseURI_was_set)
		return this->baseURI;

	///else return the value set in root_static_context
	return static_context::root_static_context()->baseuri();
}

	//statically known documents (types)
void		StaticContextWrapper::AddDocumentType( xqp_string URI, type_ident_ref_t doc_type )
{
	try{

	scw_URI_plus_type		doc;

	doc.URI = URI;
	doc.type = doc_type;

	doc_type_list.push_back(doc);

	}CATCH_ALL_NO_RETURN(;);
}

type_ident_ref_t		StaticContextWrapper::GetDocumentType( xqp_string URI)
{
	try{

	//blind search
	std::vector<scw_URI_plus_type>::iterator		it;
	for(it = doc_type_list.begin(); it != doc_type_list.end(); it++)
	{
		if((*it).URI == URI)
		{
			return (*it).type;
		}
	}

	return NULL;

	}CATCH_ALL_RETURN_NULL;
}

void		StaticContextWrapper::DeleteDocumentType( xqp_string URI)
{
	try{

	//blind search
	std::vector<scw_URI_plus_type>::iterator		it;
	for(it = doc_type_list.begin(); it != doc_type_list.end(); it++)
	{
		if((*it).URI == URI)
		{
			doc_type_list.erase(it);
			return;
		}
	}

	}CATCH_ALL_NO_RETURN(;);
}

unsigned int			StaticContextWrapper::GetDocumentTypeCount()
{
	return doc_type_list.size();
}

bool		StaticContextWrapper::GetDocumentByIndex( unsigned int i, xqp_string *URI, type_ident_ref_t *doc_type )
{
	try{

	if(i >= doc_type_list.size())
		return false;

	scw_URI_plus_type	&doc = doc_type_list[i];
	if(URI)
		*URI = doc.URI;
	if(doc_type)
		*doc_type = doc.type;
	return true;

	}CATCH_ALL_RETURN_false;
}

void		StaticContextWrapper::DeleteAllDocumentTypes()
{
	doc_type_list.clear();
}


void		StaticContextWrapper::AddCollectionType( xqp_string URI, type_ident_ref_t		collection_type )///if URI is empty then it refers to default collection type
{
	try{

	scw_URI_plus_type		collection;

	collection.URI = URI;
	collection.type = collection_type;

	collection_type_list.push_back(collection);

	}CATCH_ALL_NO_RETURN(;);

}

type_ident_ref_t		StaticContextWrapper::GetCollectionType( xqp_string URI )///if URI is empty then it refers to default collection type
{
	try{

	//blind search
	std::vector<scw_URI_plus_type>::iterator		it;
	for(it = collection_type_list.begin(); it != collection_type_list.end(); it++)
	{
		if((*it).URI == URI)
		{
			return (*it).type;
		}
	}

	return NULL;

	}CATCH_ALL_RETURN_NULL;
}

void		StaticContextWrapper::DeleteCollectionType( xqp_string URI )///if URI is empty then it refers to default collection type
{
	try{

	//blind search
	std::vector<scw_URI_plus_type>::iterator		it;
	for(it = collection_type_list.begin(); it != collection_type_list.end(); it++)
	{
		if((*it).URI == URI)
		{
			collection_type_list.erase(it);
			return;
		}
	}
	}CATCH_ALL_NO_RETURN(;);
}

unsigned int			StaticContextWrapper::GetCollectionTypeCount()
{
	return collection_type_list.size();
}

bool		StaticContextWrapper::GetCollectionTypeByIndex( unsigned int i, xqp_string *URI, type_ident_ref_t *collection_type )
{
	try{

	if(i >= collection_type_list.size())
		return false;

	scw_URI_plus_type	&collection = collection_type_list[i];
	if(URI)
		*URI = collection.URI;
	if(collection_type)
		*collection_type = collection.type;
	return true;

	}CATCH_ALL_RETURN_false;
}

void		StaticContextWrapper::DeleteAllCollectionTypes()
{
	collection_type_list.clear();
}


void		StaticContextWrapper::SetDefaultCollectionType( type_ident_ref_t def_collection_type )///default node()*
{
	this->default_collection_type = def_collection_type;
}

type_ident_ref_t	StaticContextWrapper::GetDefaultCollectionType( )
{
	try{

	if(default_collection_type.getp())
		return default_collection_type;

	//else return the default value set in root_static_context
	TypeSystem::xqtref_t t = static_context::root_static_context()->default_collection_type();

	return GENV_TYPESYSTEM.get_type_identifier(*t);
	}CATCH_ALL_RETURN_NULL;
}


static_context*		StaticContextWrapper::FillInStaticContext()
{
	try{

	static_context		*sctx = NULL;
	unsigned int			i, max;
	xqp_string				prefix, uri;
	xqp_string				var_name;
	type_ident_ref_t	type;
	TypeSystem::xqtref_t		internal_type;

	sctx = new static_context;

	if(xpath1_0compatib_mode >= 0)
		sctx->set_xpath1_0compatib_mode(xpath1_0compatib_mode);


	max = GetNamespaceCount();
	for(i=0;i<max;i++)
	{
		if(GetNamespaceByIndex(i, &prefix, &uri))
		{
			sctx->bind_ns(prefix, uri);
		}
		else
			break;
	}


	if(default_elem_ns_was_set)
		sctx->set_default_elem_type_ns(default_elem_ns);


	if(default_fun_ns_was_set)
		sctx->set_default_function_namespace(default_fun_ns);


	max = GetExternalVariableCount();
	for(i=0;i<max;i++)
	{
		if(GetExternalVariableByIndex(i, &var_name, &type))
		{
			internal_type = GENV_TYPESYSTEM.create_type( *type );
			sctx->add_variable_type(var_name, internal_type);
		}
		else
			break;
	}

	
	if(context_item_type.getp())
	{
		internal_type = GENV_TYPESYSTEM.create_type( *context_item_type );
		sctx->set_context_item_static_type(internal_type);
	}


	max = GetCollationCount();
	for(i=0;i<max;i++)
	{
		CollationInfo*		cinfo;
		cinfo = GetCollationInfoByIndex(i);
		if(cinfo)
		{
			sctx->add_collation(cinfo->URI, 
													cinfo->coll_string, 
													cinfo->coll_strength, 
													cinfo->coll,
													false);///is user created
		}
		else
			break;
	}


	if(default_collation_URI_was_set)
		sctx->set_default_collation_uri(default_collation_URI);


	if(construction_mode >= 0)
		sctx->set_construction_mode(construction_mode);


	if(ordering_mode >= 0)
		sctx->set_ordering_mode(ordering_mode);

	if(order_empty_mode >= 0)
		sctx->set_order_empty_mode(order_empty_mode);

	if(boundary_space_mode >= 0)
		sctx->set_boundary_space_mode(boundary_space_mode);

	if(preserve_mode >= 0)
		sctx->set_preserve_mode(preserve_mode);

	if(inherit_mode >= 0)
		sctx->set_inherit_mode(inherit_mode);


	if(baseURI_was_set)
		sctx->set_baseuri(baseURI, false);///not from prolog


	max = GetDocumentTypeCount();
	for(i=0;i<max;i++)
	{
		if(GetDocumentByIndex(i, &uri, &type))
		{
			internal_type = GENV_TYPESYSTEM.create_type( *type );
			sctx->set_document_type(uri, internal_type);
		}
		else
			break;
	}

	max = GetCollectionTypeCount();
	for(i=0;i<max;i++)
	{
		if(GetCollectionTypeByIndex(i, &uri, &type))
		{
			internal_type = GENV_TYPESYSTEM.create_type( *type );
			sctx->set_collection_type(uri, internal_type);
		}
		else
			break;
	}

	if(default_collection_type.getp())
	{
		internal_type = GENV_TYPESYSTEM.create_type( *default_collection_type );
		sctx->set_default_collection_type(internal_type);
	}

	return sctx;
	}CATCH_ALL_RETURN_NULL;
}


}//end namespace xqp

