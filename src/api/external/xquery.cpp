#include <iostream>
#include <fstream>
#include "zorba/common/common.h"

#include <zorba/properties.h>

#include "system/zorba_engine.h"
#include "system/zorba.h"
#include "common/shared_types.h"
#include "context/static_context.h"
#include "context/dynamic_context.h"
#include "compiler/api/compiler_api.h"
#include "errors/error_factory.h"
#include "xquery.h"


#include "runtime/sequences/SequencesImpl.h"
#include "runtime/base/plan_wrapper.h"
#include "runtime/core/item_iterator.h"

#include "api/serialization/serializer.h"
#include "api/external/dynamic_context_wrapper.h"
#include "api/external/static_context_wrapper.h"
#include "api/external/result_iterator_wrapper.h"

#include "system/globalenv.h"

#include "store/api/store.h"
#include "store/api/item_factory.h"

#include "sax2/using_libxml2/xmlreader_libxml2.h"

using namespace std;

//XERCES_CPP_NAMESPACE_USE

namespace zorba
{

Zorba_XQueryInfo::Zorba_XQueryInfo(
   Zorba_XQueryBinary *xquery,
   xqp_string  xquery_source_uri,
   xqp_string  query_text)
{
  this->xquery = xquery;
  m_xquery_source_uri = xquery_source_uri;
  m_query_text = query_text;

  is_compiled = false;
  top_iterator = NULL;
//  lStateSize = 0;
  internal_sctx = NULL;

  default_collator = NULL;

	alert_callback_param = NULL;

}

Zorba_XQueryInfo::Zorba_XQueryInfo(Zorba_XQueryBinary *xquery, 
                                   Zorba_XQueryInfo* original_info)
:
  m_xquery_source_uri(original_info->m_xquery_source_uri),
  m_query_text (original_info->m_query_text),
	is_compiled(original_info->is_compiled),
	top_iterator(original_info->top_iterator),
	default_collator(original_info->default_collator),
	internal_sctx(original_info->internal_sctx),
	alert_callback_param(original_info->alert_callback_param)
{
  this->xquery = xquery;
}

Zorba_XQueryBinary::Zorba_XQueryBinary(
   xqp_string  xquery_source_uri,
   xqp_string  query_text)
{
  info = new Zorba_XQueryInfo(this, xquery_source_uri, query_text);

}

Zorba_XQueryBinary::Zorba_XQueryBinary(
   Zorba_XQueryBinary *original_xquery)
{
  info = new Zorba_XQueryInfo(this, original_xquery->info);
}


Zorba_XQueryBinary::~Zorba_XQueryBinary()
{
}


bool Zorba_XQueryBinary::compile(StaticQueryContext* sctx, 
                                 bool routing_mode,
                                 XQueryTreePlans_t planprint)
{
  Zorba* zorba = ZORBA_FOR_CURRENT_THREAD();
  zorba->current_xquery = info;
  
  try
  {
    if(info->is_compiled)
    {
      ZORBA_ERROR_ALERT(ZorbaError::API0004_XQUERY_ALREADY_COMPILED);
      zorba->current_xquery = NULL;
      return false;
    }

    if(info->m_query_text.empty() && info->m_xquery_source_uri.empty())
	  {
      ZORBA_ERROR_ALERT(ZorbaError::API0001_XQUERY_STRING_IS_EMPTY);
      zorba->current_xquery = NULL;
      return false;
    }

    if (sctx) {
      //internal_static_context = sctx;
      //now build the static context
      StaticContextWrapper* context_wrapper = static_cast<StaticContextWrapper*>(sctx);
      info->internal_sctx = context_wrapper->fillInStaticContext();//return a static_context*
    }
    else
    {
      info->internal_sctx = GENV.getRootStaticContext().create_child_context();
    }
    info->internal_sctx->set_entity_file_uri(info->m_xquery_source_uri);

    // reset the error list from error manager
    // m_error_manager.clear();///delete all alerts from list

    XQueryPlanPrinterConfig   *pp = NULL;
    if(planprint != NULL)
        pp = static_cast<XQueryPlanPrinterConfig*>(&*planprint);

    XQueryCompiler compiler(info->sctx_list, info->internal_sctx);
    info->top_iterator = compiler.compile(info->m_xquery_source_uri, info->m_query_text, pp);
    if (info->top_iterator == NULL) {
        zorba->current_xquery = NULL;
        return false;
    }

    info->is_compiled = true;

		zorba->current_xquery = NULL;

		return true;
  }
	CATCH_ALL_NO_RETURN(zorba->current_xquery = NULL;);

//  zorba->current_xquery = NULL;
  return false;
}


bool Zorba_XQueryBinary::initExecution( DynamicQueryContext_t dctx)
{
	Zorba_XQueryInfo	*prev_xquery = NULL;
  // register this xquery as the current xquery executed/compiling in this current thread
  Zorba* zorba = ZORBA_FOR_CURRENT_THREAD();
  try{

	if(!zorba)
	{
    ZORBA_ERROR_ALERT(ZorbaError::API0009_THREAD_NOT_INITIALIZED);
		return false;//
	}
	prev_xquery = zorba->current_xquery;
  zorba->current_xquery = info;

  
  if(!info->is_compiled)
  {
    cout << "not compiled" << endl;
    ZORBA_ERROR_ALERT(ZorbaError::API0003_XQUERY_NOT_COMPILED);
    zorba->current_xquery = prev_xquery;
    return false;
  }

	result = new ResultIteratorWrapper(info, static_cast<DynamicContextWrapper*>(&*dctx));
	if(result == NULL)
	{
    ZORBA_ERROR_ALERT(ZorbaError::API0010_XQUERY_EXECUTION_NOT_STARTED);
	}

  zorba->current_xquery = prev_xquery;

  return true;//execution started
  }
	CATCH_ALL_NO_RETURN(if(zorba) zorba->current_xquery = prev_xquery;);

//  zorba->current_xquery = NULL;
  return false;
}

/*
StaticQueryContext_t Zorba_XQueryBinary::getInternalStaticContext()
{
	try{
	
	if(internal_static_context.getp() == NULL)
		internal_static_context = new StaticContextWrapper();
  return internal_static_context;
	
	}CATCH_ALL_RETURN_NULL;
}
*/

bool   Zorba_XQueryBinary::serializeQuery(ostream &os)
{
	try{

  ZORBA_ERROR_ALERT(ZorbaError::XQP0015_SYSTEM_NOT_YET_IMPLEMENTED,
                    NULL,
                    DONT_CONTINUE_EXECUTION,
                    "Zorba_XQueryBinary::serializeQuery"
                    );
	}
	CATCH_ALL_RETURN_false;
  return true;
}

void Zorba_XQueryBinary::setAlertsParam(void *alert_callback_param)
{
	try{

  info->alert_callback_param = alert_callback_param;

	}CATCH_ALL_NO_RETURN(;);
}

/*
  next() should be called in the same thread where the xquery was called execute()
*/
/*
Item_t Zorba_XQueryBinary::next()
{
	try{
		if(!theStateBlock)
		{
			ZORBA_ERROR_ALERT(ZorbaError::API0010_XQUERY_EXECUTION_NOT_STARTED);
			return NULL;
		}
		if (theClosed)
		{
			ZORBA_ERROR_ALERT(ZorbaError::API0010_XQUERY_EXECUTION_NOT_STARTED);
			return NULL;
		}
	}
	CATCH_ALL_RETURN_NULL;

	Zorba_XQueryBinary        *prev_current_xquery = theStateBlock->theZorba->current_xquery;
  theStateBlock->theZorba->current_xquery = info;;
  try
  {
    Item_t it = top_iterator->produceNext( *theStateBlock );

    theStateBlock->theZorba->current_xquery = prev_current_xquery;

    return it;
  }
	CATCH_ALL_NO_RETURN(  \
  theStateBlock->theZorba->current_xquery = prev_current_xquery;)

  return NULL;
}

void
Zorba_XQueryBinary::reset()
{
	try{
		if(!theStateBlock)
		{
			ZORBA_ERROR_ALERT(ZorbaError::API0010_XQUERY_EXECUTION_NOT_STARTED);
			return;
		}
	}CATCH_ALL_NO_RETURN(;);

	Zorba_XQueryBinary        *prev_current_xquery = theStateBlock->theZorba->current_xquery;
  theStateBlock->theZorba->current_xquery = info;;
	try
  {
    if (!theClosed)
    {
      top_iterator->reset(*theStateBlock);
    }

    theStateBlock->theZorba->current_xquery = prev_current_xquery;
		return;
	}
	CATCH_ALL_NO_RETURN(\
  theStateBlock->theZorba->current_xquery = prev_current_xquery;);
}


void
Zorba_XQueryBinary::close()
{
	try{
		if(!theStateBlock)
		{
			ZORBA_ERROR_ALERT(ZorbaError::API0010_XQUERY_EXECUTION_NOT_STARTED);
			return;
		}
	}CATCH_ALL_NO_RETURN(;);

	Zorba			*zorba = ZORBA_FOR_CURRENT_THREAD();
	Zorba_XQueryBinary        *prev_current_xquery = NULL;
	if(zorba)
	{
		prev_current_xquery = zorba->current_xquery;
		zorba->current_xquery = info;
	}

	try
  {
    if (!theClosed)
    {
      top_iterator->close(*theStateBlock); 
	    delete theStateBlock;
			theStateBlock = NULL;
      theClosed = true;
    }
		if(zorba)
			zorba->current_xquery = prev_current_xquery;
		return;
	}
	CATCH_ALL_NO_RETURN(if(zorba) zorba->current_xquery = prev_current_xquery;);

}
*/

ResultIterator_t	Zorba_XQueryBinary::getIterator()
{
	try{
		if(result == NULL)
		{
			ZORBA_ERROR_ALERT(ZorbaError::API0010_XQUERY_EXECUTION_NOT_STARTED);
		}
		ResultIterator_t	temp_result = result;
		result = NULL;
		return temp_result;
	}
	CATCH_ALL_RETURN_NULL;
}

bool Zorba_XQueryBinary::serialize( ostream& os )
{
	try{
		if(result == NULL)
		{
			ZORBA_ERROR_ALERT(ZorbaError::API0010_XQUERY_EXECUTION_NOT_STARTED);
			return false;
		}
	}CATCH_ALL_RETURN_false;

  result->theStateBlock->theZorba->current_xquery = info;;

  serializer *ser;
	try
  {
		ser = ZORBA_FOR_CURRENT_THREAD()->getDocSerializer();

    ser->serialize(result, os);
		result->theStateBlock->theZorba->current_xquery = NULL;
	}
	CATCH_ALL_NO_RETURN(result->theStateBlock->theZorba->current_xquery = NULL;);

  return !isError();
}

bool Zorba_XQueryBinary::serializeXML( std::ostream& os )
{
	try{
		if(result == NULL)
		{
			ZORBA_ERROR_ALERT(ZorbaError::API0010_XQUERY_EXECUTION_NOT_STARTED);
			return false;
		}
	}CATCH_ALL_RETURN_false;

	result->theStateBlock->theZorba->current_xquery = info;;

  auto_ptr<serializer> ser(new serializer);

	try
  {
    ser->serialize(result, os);
	}
	CATCH_ALL_NO_RETURN(result->theStateBlock->theZorba->current_xquery = NULL;);
	result->theStateBlock->theZorba->current_xquery = NULL;
  return !isError();
}

bool Zorba_XQueryBinary::serializeHTML( std::ostream& os )
{
	try{
		if(result == NULL)
		{
			ZORBA_ERROR_ALERT(ZorbaError::API0010_XQUERY_EXECUTION_NOT_STARTED);
			return false;
		}
	}CATCH_ALL_RETURN_false;
  result->theStateBlock->theZorba->current_xquery = info;;

  auto_ptr<serializer> ser(new serializer);
	
	try{
		ser->set_parameter("method", "html");
		ser->serialize(result, os);
	}
	CATCH_ALL_NO_RETURN(result->theStateBlock->theZorba->current_xquery = NULL;);
  result->theStateBlock->theZorba->current_xquery = NULL;
  return !isError();
}

bool Zorba_XQueryBinary::serializeTEXT( std::ostream& os )
{
	try{
		if(result == NULL)
		{
			ZORBA_ERROR_ALERT(ZorbaError::API0010_XQUERY_EXECUTION_NOT_STARTED);
			return false;
		}
	}CATCH_ALL_RETURN_false;
  result->theStateBlock->theZorba->current_xquery = info;;

	try{
  Item_t    it;

  while(1)
  {
    it = result->next();
    if(!it.getp())
      break;
    os << it->show() << endl;
  }
	}
	CATCH_ALL_NO_RETURN(result->theStateBlock->theZorba->current_xquery = NULL;);
  result->theStateBlock->theZorba->current_xquery = NULL;
  return !isError();
}
/*
XERCES_CPP_NAMESPACE_QUALIFIER DOMDocument*  Zorba_XQueryBinary::getResultAsDOM()
{

  std::ostringstream    oss;
  if(!serializeXML(oss))
    return NULL;

	result->theStateBlock->theZorba->current_xquery = info;
  XMLCh       *xml_utf16 = NULL;
  MemBufInputSource*   mem_xml = NULL;
  XercesDOMParser* parser = NULL;
  ErrorHandler *errReporter = NULL;
  try{

    XERCES_CPP_NAMESPACE_QUALIFIER DOMDocument*   myDocument;
    std::string   oss_str = oss.str();
   // xml_utf16 = new XMLCh[oss_str.length()+1];
   // memset(xml_utf16, 0, (oss_str.length()+1)*sizeof(XMLCh));
    xml_utf16 = XMLString::transcode(oss_str.c_str());
   // mem_xml = new MemBufInputSource((XMLByte*)xml_utf16, (oss_str.length()+1)*sizeof(XMLCh), "getResultAsDOM");
    mem_xml = new MemBufInputSource((XMLByte*)oss_str.c_str(), oss_str.length(), "getResultAsDOM");
    parser = new XercesDOMParser();
  
    errReporter = new HandlerBase();
    parser->setErrorHandler(errReporter);
  //  parser->setValidationScheme(XercesDOMParser::Val_Always);    
  //  parser->setDoNamespaces(true);    // optional
    parser->parse(*mem_xml);
    if(parser->getErrorCount())
    {
      delete parser;
      delete errReporter;
      delete mem_xml;
      if(xml_utf16) XMLString::release (&xml_utf16);
      result->theStateBlock->theZorba->current_xquery = NULL;
      ZORBA_ERROR_ALERT(ZorbaError::XQP0022_GET_RESULTS_AS_DOM_FAILED);
      return NULL;
    }
    myDocument = parser->adoptDocument();

    delete parser;
    delete errReporter;
    delete mem_xml;
    if(xml_utf16) XMLString::release (&xml_utf16);
    result->theStateBlock->theZorba->current_xquery = NULL;
    return myDocument;
	}
	CATCH_ALL_NO_RETURN(delete parser;\
    delete errReporter;\
    delete mem_xml;\
    if(xml_utf16) XMLString::release (&xml_utf16);\
    result->theStateBlock->theZorba->current_xquery = NULL;);
	
  result->theStateBlock->theZorba->current_xquery = NULL;
  return NULL;


}
*/

/*
bool  Zorba_XQueryBinary::getResultAsSAX(XERCES_CPP_NAMESPACE_QUALIFIER DocumentHandler *user_sax_dochandler,
                                         XERCES_CPP_NAMESPACE_QUALIFIER ErrorHandler *user_sax_errhandler)
{

  std::ostringstream    oss;
  if(!serializeXML(oss))
    return false;

	result->theStateBlock->theZorba->current_xquery = info;
  XMLCh       *xml_utf16 = NULL;
  MemBufInputSource*   mem_xml = NULL;
  SAXParser* parser = NULL;
  ErrorHandler *errReporter = NULL;
  try{

    std::string   oss_str = oss.str();
   // xml_utf16 = new XMLCh[oss_str.length()+1];
   // memset(xml_utf16, 0, (oss_str.length()+1)*sizeof(XMLCh));
    xml_utf16 = XMLString::transcode(oss_str.c_str());
   // mem_xml = new MemBufInputSource((XMLByte*)xml_utf16, (oss_str.length()+1)*sizeof(XMLCh), "getResultAsDOM");
    mem_xml = new MemBufInputSource((XMLByte*)oss_str.c_str(), oss_str.length(), "getResultAsDOM");
    parser = new SAXParser();

    parser->setDocumentHandler(user_sax_dochandler);
    parser->setErrorHandler(user_sax_errhandler);

  //  parser->setValidationScheme(XercesDOMParser::Val_Always);    
  //  parser->setDoNamespaces(true);    // optional
    parser->parse(*mem_xml);

    if(parser->getErrorCount())
    {
      delete parser;
      delete errReporter;
      delete mem_xml;
      if(xml_utf16) XMLString::release (&xml_utf16);
      result->theStateBlock->theZorba->current_xquery = NULL;
      ZORBA_ERROR_ALERT(ZorbaError::XQP0023_GET_RESULTS_AS_SAX_FAILED);
      return false;
    }
    delete parser;
    delete errReporter;
    delete mem_xml;
    if(xml_utf16) XMLString::release (&xml_utf16);
    result->theStateBlock->theZorba->current_xquery = NULL;
    return true;
	}
	CATCH_ALL_NO_RETURN(delete parser;\
    delete errReporter;\
    delete mem_xml;\
    if(xml_utf16) XMLString::release (&xml_utf16);\
    result->theStateBlock->theZorba->current_xquery = NULL;);
	
  result->theStateBlock->theZorba->current_xquery = NULL;
  return false;


}
*/

void   Zorba_XQueryBinary::getResultAsSAX2( 
                                SAX2_ContentHandler *content_handler,
                                SAX2_ErrorHandler* error_handler,
                                SAX2_DTDHandler*  dtd_handler,
                                SAX2_DeclHandler* decl_handler,
                                SAX2_LexicalHandler* lexical_handler)
{
  SAX2_XMLReaderLibXML2   xmlreader(content_handler,
                                    error_handler,
                                    dtd_handler,
                                    decl_handler,
                                    lexical_handler);

  xmlreader.parse(this);
}

bool Zorba_XQueryBinary::isError()
{
  //return is_error;
	return ZorbaEngine::getInstance()->getAlertsManagerForCurrentThread()->isError();
}

void  Zorba_XQueryBinary::abortQueryExecution()
{
	try{
  ZORBA_ERROR_ALERT(ZorbaError::XQP0015_SYSTEM_NOT_YET_IMPLEMENTED,
                    NULL,
                    DONT_CONTINUE_EXECUTION,
                    "AbortQueryExecution"
                    );
	}CATCH_ALL_NO_RETURN(;);
}

/*extension from dynamic context (specific only for this execution)
bind external variable with the result from another xquery
*/
bool Zorba_XQueryBinary::setVariableAsXQueryResult( xqp_string varname, 
                                        ResultIterator_t item_iter )
{
	try{
		if(result == NULL)
		{
			ZORBA_ERROR_ALERT(ZorbaError::API0010_XQUERY_EXECUTION_NOT_STARTED);
			return false;
		}
	}CATCH_ALL_RETURN_false;

  result->theStateBlock->theZorba->current_xquery = info;;

	try{
		DynamicContextWrapper::checkVarName(varname);

		///add to dynamic context
		xqp_string    expanded_name;
    ResultIteratorWrapper   *iter_wrapper = static_cast<ResultIteratorWrapper*>(&*item_iter);
		expanded_name = result->internal_dyn_context->expand_varname(info->internal_sctx, varname);
		//result->internal_dyn_context->add_variable(expanded_name, new ResultIteratorInternalWrapper(item_iter));
    result->internal_dyn_context->add_variable(expanded_name, iter_wrapper);

		result->theStateBlock->theZorba->current_xquery = NULL;
		return true;
	}
	CATCH_ALL_NO_RETURN(result->theStateBlock->theZorba->current_xquery = NULL;);
  return false;
}


bool Zorba_XQueryBinary::setVariableAsDocumentFromStream(
    xqp_string    varname,
    xqp_string    docUri,
    std::istream& is)
{
	try{
		if(result == NULL)
		{
			ZORBA_ERROR_ALERT(ZorbaError::API0010_XQUERY_EXECUTION_NOT_STARTED);
			return false;
		}
	}CATCH_ALL_RETURN_false;

  result->theStateBlock->theZorba->current_xquery = info;;

  PlanIter_t iter;
  PlanWrapper* planWrapper = NULL;

	try
  {
		DynamicContextWrapper::checkVarName(varname);

   // if(!internal_dyn_context)
   //   internal_dyn_context = new dynamic_context;

    xqp_string expanded_name = result->internal_dyn_context->expand_varname(info->internal_sctx, varname);

		Store		&store = GENV.getStore();
		ItemFactory* factory = Zorba::getItemFactory();

    Item_t uriItem = factory->createAnyURI(docUri.getStore());
		if(uriItem == NULL)
		{//not a valid uri
			result->theStateBlock->theZorba->current_xquery = NULL;
			ZORBA_ERROR_ALERT(ZorbaError::API0014_INVALID_ARGUMENT, NULL, DONT_CONTINUE_EXECUTION, docUri);
			return false;
		}
		//?store.deleteDocument(docUri);
		Item_t	docItem = store.loadDocument(docUri.getStore(), is);
		if(docItem == NULL)
		{//cannot upload document into store
			//or maybe is not valid xml
			result->theStateBlock->theZorba->current_xquery = NULL;
			ZORBA_ERROR_ALERT(ZorbaError::API0017_CANNOT_LOAD_DOCUMENT, NULL, DONT_CONTINUE_EXECUTION, docUri);
			return false;
		}

    iter = new SingletonIterator(Zorba::null_loc, uriItem);
    iter = new FnDocIterator(Zorba::null_loc, iter);

    planWrapper = new PlanWrapper(iter);
    planWrapper->open();

    result->internal_dyn_context->add_variable(expanded_name, planWrapper);

		result->theStateBlock->theZorba->current_xquery = NULL;
    return true;
	}
	CATCH_ALL_NO_RETURN(\
  if (planWrapper != NULL)\
    delete planWrapper;\
  result->theStateBlock->theZorba->current_xquery = NULL;);
  return false;
}

bool Zorba_XQueryBinary::setContextItemAsDocumentFromStream(
    xqp_string    docUri,
    std::istream& is)
{
	try{
		if(result == NULL)
		{
			ZORBA_ERROR_ALERT(ZorbaError::API0010_XQUERY_EXECUTION_NOT_STARTED);
			return false;
		}
	}CATCH_ALL_RETURN_false;

  result->theStateBlock->theZorba->current_xquery = info;;

	try
  {
		Store		&store = GENV.getStore();

		//?store.deleteDocument(docUri);
		Item_t	docItem = store.loadDocument(docUri.getStore(), is);
		if(docItem == NULL)
		{//cannot upload document into store
			//or maybe is not valid xml
			result->theStateBlock->theZorba->current_xquery = NULL;
			ZORBA_ERROR_ALERT(ZorbaError::API0017_CANNOT_LOAD_DOCUMENT, NULL, DONT_CONTINUE_EXECUTION, docUri);
			return false;
		}

		result->internal_dyn_context->set_context_item(docItem, 1);

		result->theStateBlock->theZorba->current_xquery = NULL;
    return true;
	}
	CATCH_ALL_NO_RETURN(result->theStateBlock->theZorba->current_xquery = NULL;);
  return false;
}


///register documents available through fn:doc() in xquery
/*
bool Zorba_XQueryBinary::AddAvailableDocument(xqp_string docURI,
                                                Item_t docitem)
{
  theStateBlock->theZorba->current_xquery = info;;

  ///add to dynamic context
	try{
  theStateBlock->theZorba->current_xquery = NULL;
  return false;
	}
//  catch(xqp_exception &)
//  {
//	}
	CATCH_ALL_NO_RETURN(\
	theStateBlock->theZorba->current_xquery = NULL;);
	return false;
}
*/

///register collections available through fn:collection() in xquery
///default collection has empty URI ""
/*
bool Zorba_XQueryBinary::AddAvailableCollection(xqp_string collectionURI,
                                                  Collection_t collection)
{
  theStateBlock->theZorba->current_xquery = info;;

  ///add to dynamic context
	try{
  theStateBlock->theZorba->current_xquery = NULL;
  return false;
	}
//  catch(xqp_exception &)
//  {
//	}
	CATCH_ALL_NO_RETURN(\
	theStateBlock->theZorba->current_xquery = NULL;);
	return false;
}
*/

XQuery_t Zorba_XQueryBinary::clone()
{
	try{
	return new Zorba_XQueryBinary(this);
	}
	CATCH_ALL_RETURN_NULL;
	
}

}///end namespace zorba
