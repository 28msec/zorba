
#include <zorba/stateless_function.h>
#include <zorba/static_context_consts.h>

#include "system/zorba.h"
#include "system/zorba_engine.h"
#include "static_context_wrapper.h"
#include "types/root_typemanager.h"
#include "system/globalenv.h"
#include "errors/error_manager.h"
#include "system/globalenv.h"
#include "types/casting.h"
#include "context/static_context.h"


namespace zorba{


StaticContextWrapper::StaticContextWrapper()
{
	try{

	xpath1_0compatib_mode = (StaticContextConsts::xpath1_0compatib_mode_t)-1;//not initialized
	
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
	construction_mode = (StaticContextConsts::construction_mode_t)-1;//not initialized
	ordering_mode = (StaticContextConsts::ordering_mode_t)-1;//not initialized
	order_empty_mode = (StaticContextConsts::order_empty_mode_t)-1;//not initialized
	boundary_space_mode = (StaticContextConsts::boundary_space_mode_t)-1;//not initialized
	preserve_mode = (StaticContextConsts::preserve_mode_t)-1;//not initialized
	inherit_mode = (StaticContextConsts::inherit_mode_t)-1;//not initialized
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

void		StaticContextWrapper::setXPath1_0CompatibMode( StaticContextConsts::xpath1_0compatib_mode_t mode )///true for XPath1.0 only, false for XPath2.0 (default false)
{
	xpath1_0compatib_mode = mode ;
}

StaticContextConsts::xpath1_0compatib_mode_t		StaticContextWrapper::getXPath1_0CompatibMode( )///true for XPath1.0 only, false for XPath2.0
{
	if(xpath1_0compatib_mode >= 0)
		return xpath1_0compatib_mode;//previously set by user
	//else take the default value from root_static_context

	return GENV.getRootStaticContext().xpath1_0compatib_mode();
}

bool		StaticContextWrapper::addNamespace( xqp_string prefix, xqp_string URI )//override the previous set prefix
{
	try{
//	internal_stcx.bind_ns( prefix, URI );
	scw_namespace_t		ns;

	if((prefix == "xmlns") ||
		(prefix == "xml") && (URI != "http://www.w3.org/XML/1998/namespace" ))
	{
		ZORBA_ERROR_ALERT(ZorbaError::XQST0070, NULL, DONT_CONTINUE_EXECUTION, prefix, URI);
		return false;//ignore that
	}

	deleteNamespace(prefix);
	ns.prefix = prefix;
	ns.URI = URI;

	ext_ns_list.push_back(ns);
	return true;
	}CATCH_ALL_RETURN_false;
}

xqp_string		StaticContextWrapper::getNamespaceURIByPrefix( xqp_string prefix )
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

void		StaticContextWrapper::deleteNamespace( xqp_string prefix )
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

unsigned int	StaticContextWrapper::getNamespaceCount()
{
	return ext_ns_list.size();
}

bool		StaticContextWrapper::getNamespaceByIndex( unsigned int i, xqp_string *prefix, xqp_string *URI )
{
	try{

	if(i >= ext_ns_list.size())
	{
//		ZORBA_ERROR_ALERT(ZorbaError::API0012_INVALID_INDEX);
		return false;
	}

	scw_namespace_t		&ns = ext_ns_list[i];
	if(prefix)
		*prefix = ns.prefix;
	if(URI)
		*URI = ns.URI;
	return true;
	}CATCH_ALL_RETURN_false;

}

void		StaticContextWrapper::deleteAllNamespaces()
{
	ext_ns_list.clear();
}


void		StaticContextWrapper::setDefaultElementAndTypeNamespace( xqp_string URI )///default is none
{
//	internal_stcx.set_default_elem_type_ns( URI );
	default_elem_ns = URI;
	default_elem_ns_was_set = true;
}

xqp_string		StaticContextWrapper::getDefaultElementAndTypeNamespace( )
{
//	return internal_stcx.default_elem_type_ns();
	if(default_elem_ns_was_set)
		return default_elem_ns;

	//else return the default
	return GENV.getRootStaticContext().default_elem_type_ns();
}


void		StaticContextWrapper::setDefaultFunctionNamespace( xqp_string URI )///default is none
{
//	internal_stcx.set_default_function_namespace( URI );
	default_fun_ns = URI;
	default_fun_ns_was_set = true;
}

xqp_string		StaticContextWrapper::getDefaultFunctionNamespace( )
{
//	return internal_stcx.default_function_namespace();
	if(default_fun_ns_was_set)
		return default_fun_ns;

	//else return the default
	return GENV.getRootStaticContext().default_function_namespace();
}


	//here some functions for schema ... not impl yet...

void		StaticContextWrapper::addExternalVariableType( xqp_string	var_name, type_ident_ref_t var_type)
{
	try{

	scw_QName_plus_type		var;

	deleteExternalVariableType(var_name);

	var.qname = var_name;
	var.type = var_type;

	ext_var_list.push_back(var);

	}CATCH_ALL_NO_RETURN(;);
}

type_ident_ref_t	StaticContextWrapper::getExternalVariableType( xqp_string	var_name )
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

void		StaticContextWrapper::deleteExternalVariableType( xqp_string var_name )
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

unsigned int			StaticContextWrapper::getExternalVariableCount()
{
	return ext_var_list.size();
}

bool		StaticContextWrapper::getExternalVariableByIndex( unsigned int i, xqp_string *var_name, type_ident_ref_t *var_type )
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

void		StaticContextWrapper::deleteAllVariables()
{
	ext_var_list.clear();
}

void		StaticContextWrapper::setContextItemStaticType( type_ident_ref_t		type )
{
//	xqtref_t		internal_type;
//	internal_type = GENV_TYPESYSTEM.create_type( *type );
//	//now what
//	internal_sctx.set_context_item_static_type( internal_type );

	context_item_type = type;
}

type_ident_ref_t		StaticContextWrapper::getContextItemStaticType( )
{
	if(context_item_type.getp())
		return context_item_type;

	///else get the default value from root_static_context
	xqtref_t t =  GENV.getRootStaticContext().context_item_static_type();

	return GENV_TYPESYSTEM.get_type_identifier(*t);
}

	///here some api for external functions
	// virtual void AddExternalFunction( QNameItem_t func_name, extern_func *cpp_func, TypeIdentifier *type_of_result, ...);//and the types of parameters
	// virtual void	DeleteAllExternalFunctions();

void		StaticContextWrapper::addCollation( xqp_string URI, std::string  coll_string, ::Collator::ECollationStrength coll_strength )
{
	try{

	deleteCollation(URI);
	CollationInfo		cinfo;

	cinfo.URI = URI;
	cinfo.coll_string = coll_string;
	cinfo.coll_strength = coll_strength;
	cinfo.coll = NULL;
	collation_list.push_back(cinfo);

	}CATCH_ALL_NO_RETURN(;);
}

void		StaticContextWrapper::addCollation( xqp_string URI, ::Collator	*coll)
{
	try{

	deleteCollation(URI);
	CollationInfo		cinfo;

	if(!coll)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0014_INVALID_ARGUMENT);
		return;
	}
	cinfo.URI = URI;
	cinfo.coll = coll;
	collation_list.push_back(cinfo);

	}CATCH_ALL_NO_RETURN(;);
}

CollationInfo*		StaticContextWrapper::getCollation( xqp_string URI)
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

void		StaticContextWrapper::deleteCollation( xqp_string URI)
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

unsigned int			StaticContextWrapper::getCollationCount()
{
	return collation_list.size();
}

CollationInfo*		StaticContextWrapper::getCollationInfoByIndex( unsigned int i )
{
	try{

	if(i >= collation_list.size())
		return NULL;

	return &collation_list[i];

	}CATCH_ALL_RETURN_NULL;
}

void		StaticContextWrapper::deleteAllCollations()
{
	collation_list.clear();
}


void		StaticContextWrapper::setDefaultCollation( xqp_string URI )//std::string  coll_string, ::Collator::ECollationStrength coll_strength )
{
	default_collation_URI = URI;
	default_collation_URI_was_set = true;
}

xqp_string	StaticContextWrapper::getDefaultCollation()
{
	if(default_collation_URI_was_set)
		return default_collation_URI;

	//else return the default collation from root_static_context
	return GENV.getRootStaticContext().default_collation_uri();
}



void		StaticContextWrapper::setConstructionMode( StaticContextConsts::construction_mode_t c)
{
	//internal_sctx.set_construction_mode( c );
	construction_mode = c;
}

StaticContextConsts::construction_mode_t		StaticContextWrapper::getConstructionMode( )
{
//	return internal_sctx.construction_mode();
	if(construction_mode >= 0)
		return construction_mode;

	return GENV.getRootStaticContext().construction_mode();
}

void		StaticContextWrapper::setOrderingMode( StaticContextConsts::ordering_mode_t o)
{
	//internal_sctx.set_ordering_mode(o);
	ordering_mode = o;
}

StaticContextConsts::ordering_mode_t		StaticContextWrapper::getOrderingMode( )
{
	//return internal_sctx.ordering_mode();
	if(ordering_mode >= 0)
		return ordering_mode;

	return GENV.getRootStaticContext().ordering_mode();
}


void		StaticContextWrapper::setDefaultOrderForEmptySequences( StaticContextConsts::order_empty_mode_t o)
{
	//internal_sctx.set_order_empty_mode( o );
	order_empty_mode = o;
}

StaticContextConsts::order_empty_mode_t		StaticContextWrapper::getDefaultOrderForEmptySequences( )
{
	//return internal_sctx.order_empty_mode();
	if(order_empty_mode >= 0)
		return order_empty_mode;
	return GENV.getRootStaticContext().order_empty_mode();
}


void		StaticContextWrapper::setBoundarySpacePolicy( StaticContextConsts::boundary_space_mode_t b)
{
	//internal_sctx.set_boundary_space_mode( b );
	boundary_space_mode = b;
}

StaticContextConsts::boundary_space_mode_t		StaticContextWrapper::getBoundarySpacePolicy( )
{
	//return internal_sctx.boundary_space_mode();
	if(boundary_space_mode >= 0)
		return boundary_space_mode;
	return GENV.getRootStaticContext().boundary_space_mode();

}

void		StaticContextWrapper::setCopyNamespacesMode( StaticContextConsts::preserve_mode_t preserve, StaticContextConsts::inherit_mode_t inherit )
{
	//internal_sctx.set_preserve_mode( preserve );
	//internal_sctx.set_inherit_mode( inherit );
	preserve_mode = preserve;
	inherit_mode = inherit;
}

void		StaticContextWrapper::getCopyNamespacesMode( StaticContextConsts::preserve_mode_t *preserve, StaticContextConsts::inherit_mode_t *inherit )
{
	if(preserve_mode >= 0)
	{
		*preserve = preserve_mode;
		*inherit = inherit_mode;
		return;
	}
	*preserve = GENV.getRootStaticContext().preserve_mode( );
	*inherit = GENV.getRootStaticContext().inherit_mode( );
}

bool		StaticContextWrapper::setBaseURI( xqp_string baseURI )
{
  try{
	//internal_sctx.set_baseuri( baseURI );
  if(((std::string)baseURI).find("://") == std::string::npos)
  {
    xqp_string    newbase;
    newbase = "file://";
    newbase += baseURI;
    baseURI = newbase;
  }

  if(!GenericCast::instance()->isCastable(baseURI, GENV_TYPESYSTEM.ANY_URI_TYPE_ONE))
  {
    ZORBA_ERROR_ALERT(ZorbaError::XQP0020_INVALID_URI, NULL, DONT_CONTINUE_EXECUTION,
                baseURI);
    return false;
  }

	this->baseURI = baseURI;
	baseURI_was_set = true;
  return true;

  }CATCH_ALL_RETURN_false;
}

xqp_string		StaticContextWrapper::getBaseURI( )
{
	//return internal_sctx.baseuri();
	if(baseURI_was_set)
		return this->baseURI;

	///else return the value set in root_static_context
	return GENV.getRootStaticContext().baseuri();
}

	//statically known documents (types)
void		StaticContextWrapper::addDocumentType( xqp_string URI, type_ident_ref_t doc_type )
{
	try{

	deleteDocumentType(URI);

	scw_URI_plus_type		doc;

	doc.URI = URI;
	doc.type = doc_type;

	doc_type_list.push_back(doc);

	}CATCH_ALL_NO_RETURN(;);
}

type_ident_ref_t		StaticContextWrapper::getDocumentType( xqp_string URI)
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

void		StaticContextWrapper::deleteDocumentType( xqp_string URI)
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

unsigned int			StaticContextWrapper::getDocumentTypeCount()
{
	return doc_type_list.size();
}

bool		StaticContextWrapper::getDocumentByIndex( unsigned int i, xqp_string *URI, type_ident_ref_t *doc_type )
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

void		StaticContextWrapper::deleteAllDocumentTypes()
{
	doc_type_list.clear();
}


void		StaticContextWrapper::addCollectionType( xqp_string URI, type_ident_ref_t		collection_type )///if URI is empty then it refers to default collection type
{
	try{

	deleteCollectionType( URI );
	scw_URI_plus_type		collection;

	collection.URI = URI;
	collection.type = collection_type;

	collection_type_list.push_back(collection);

	}CATCH_ALL_NO_RETURN(;);

}

type_ident_ref_t		StaticContextWrapper::getCollectionType( xqp_string URI )///if URI is empty then it refers to default collection type
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

void		StaticContextWrapper::deleteCollectionType( xqp_string URI )///if URI is empty then it refers to default collection type
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

unsigned int			StaticContextWrapper::getCollectionTypeCount()
{
	return collection_type_list.size();
}

bool		StaticContextWrapper::getCollectionTypeByIndex( unsigned int i, xqp_string *URI, type_ident_ref_t *collection_type )
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

void		StaticContextWrapper::deleteAllCollectionTypes()
{
	collection_type_list.clear();
}


void		StaticContextWrapper::setDefaultCollectionType( type_ident_ref_t def_collection_type )///default node()*
{
	this->default_collection_type = def_collection_type;
}

type_ident_ref_t	StaticContextWrapper::getDefaultCollectionType( )
{
	try{

	if(default_collection_type.getp())
		return default_collection_type;

	//else return the default value set in root_static_context
	xqtref_t t = GENV.getRootStaticContext().default_collection_type();

	return GENV_TYPESYSTEM.get_type_identifier(*t);
	}CATCH_ALL_RETURN_NULL;
}


static_context*		StaticContextWrapper::fillInStaticContext()
{
	try{

	static_context		*sctx = NULL;
	unsigned int			i, max;
	xqp_string				prefix, uri;
	xqp_string				var_name;
	type_ident_ref_t	type;
	xqtref_t		internal_type;

	sctx = GENV.getRootStaticContext().create_child_context();

	if(xpath1_0compatib_mode >= 0)
		sctx->set_xpath1_0compatib_mode(xpath1_0compatib_mode);


	max = getNamespaceCount();
	for(i=0;i<max;i++)
	{
		if(getNamespaceByIndex(i, &prefix, &uri))
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


	max = getExternalVariableCount();
	for(i=0;i<max;i++)
	{
		if(getExternalVariableByIndex(i, &var_name, &type))
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


	max = getCollationCount();
	for(i=0;i<max;i++)
	{
		CollationInfo*		cinfo;
		cinfo = getCollationInfoByIndex(i);
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

	max = getDocumentTypeCount();
	for(i=0;i<max;i++)
	{
		if(getDocumentByIndex(i, &uri, &type))
		{
			internal_type = GENV_TYPESYSTEM.create_type( *type );
			sctx->set_document_type(uri, internal_type);
		}
		else
			break;
	}

	max = getCollectionTypeCount();
	for(i=0;i<max;i++)
	{
		if(getCollectionTypeByIndex(i, &uri, &type))
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

  for (uint32_t i = 0; i < stateless_ext_functions.size(); ++i)
  {
    StatelessExternalFunction_t lFun = stateless_ext_functions.getentryVal(i);
    sctx->bind_stateless_external_function(lFun);
  }

	return sctx;
	}CATCH_ALL_RETURN_NULL;
}

  /**
   * functions that are used for registering external functions
   */
  void 
  StaticContextWrapper::registerStatelessExternalFunction(StatelessExternalFunction_t aExtFunction)
  {
    if ( stateless_ext_functions.put( aExtFunction->getURI() + aExtFunction->getLocalName(), 
                                      aExtFunction ) )
		  ZORBA_ERROR_ALERT(ZorbaError::API0019_FUNCTION_ALREADY_REGISTERED, 
                        NULL, DONT_CONTINUE_EXECUTION, aExtFunction->getURI(), 
                        aExtFunction->getLocalName());
  }

}//end namespace zorba

