///Created: Daniel Turcanu @ IPDevel 

#include "errors/error_factory.h"
#include "xquery.h"

#include "compiler/codegen/plan_visitor.h"
#include "compiler/translator/translator.h"
#include "compiler/normalizer/normalizer.h"
#include "compiler/parsetree/parsenode_print_xml_visitor.h"
#include "compiler/parsetree/parsenode_print_dot_visitor.h"
#include "compiler/parser/xquery_driver.h"
#include "system/zorba.h"
#include "runtime/visitors/printervisitor.h"
#include "runtime/visitors/iterprinter.h"
#include "runtime/sequences/SequencesImpl.h"

#include "api/serialization/serializer.h"
#include "api/external/dynamic_context_wrapper.h"

#include "zorba/util/properties.h"

#include <iostream>
#include <fstream>

using namespace std;

namespace xqp
{


Zorba_XQueryBinary::Zorba_XQueryBinary(
   xqp_string  xquery_source_uri,
   xqp_string  query_text)
  :
  m_xquery_source_uri(xquery_source_uri),
  m_query_text (query_text)
{
  is_compiled = false;
  top_iterator = NULL;
//  lStateSize = 0;
  internal_sctx = NULL;

  default_collator = NULL;

	state_block = NULL;

	alert_callback_param = NULL;
	internal_dyn_context = NULL;
  theClosed = false;
}

Zorba_XQueryBinary::Zorba_XQueryBinary(
   Zorba_XQueryBinary *original_xquery)
  :
  m_xquery_source_uri(original_xquery->m_xquery_source_uri),
  m_query_text (original_xquery->m_query_text),
	is_compiled(original_xquery->is_compiled),
	top_iterator(original_xquery->top_iterator),
	default_collator(original_xquery->default_collator),
	internal_sctx(original_xquery->internal_sctx),
	alert_callback_param(original_xquery->alert_callback_param)
{

	state_block = NULL;
	internal_dyn_context = NULL;
  theClosed = false;
}


Zorba_XQueryBinary::~Zorba_XQueryBinary()
{
	try{

  //delete internal_sctx;
  close();
  delete state_block;
	delete internal_dyn_context;
	}CATCH_ALL_NO_RETURN(;);

}


bool Zorba_XQueryBinary::compile(StaticQueryContext* sctx, 
                                 bool routing_mode)
{
  Zorba* zorba = ZORBA_FOR_CURRENT_THREAD();
  zorba->current_xquery = this;
  
  try
  {
    if(is_compiled)
    {
      ZORBA_ERROR_ALERT(ZorbaError::API0004_XQUERY_ALREADY_COMPILED,
                        NULL,
                        true///continue execution
                        );
      zorba->current_xquery = NULL;
      return false;
    }

    if(m_query_text.empty())
	  {
      ZORBA_ERROR_ALERT(ZorbaError::API0001_XQUERY_STRING_IS_EMPTY,
                        NULL,
                        true///continue execution
                        );
      zorba->current_xquery = NULL;
      return false;
    }

    if (sctx) {
      //internal_static_context = sctx;
      //now build the static context
      StaticContextWrapper* context_wrapper = static_cast<StaticContextWrapper*>(sctx);
      internal_sctx = context_wrapper->FillInStaticContext();//return a static_context*
    }
    else
    {
      internal_sctx = new static_context;
    }
    internal_sctx->set_entity_file_uri(m_xquery_source_uri);

    // reset the error list from error manager
    // m_error_manager.clear();///delete all alerts from list

    ///NOW COMPILE
    xquery_driver driver;
    driver.filename = m_xquery_source_uri;

    ///build up the expression tree
    driver.parse_string(m_query_text.c_str());

    rchandle<parsenode> n_p = driver.get_expr();

    if (Properties::instance()->printAST())
	  {
      cout << "Parse tree:\n";
      ParseNodePrintXMLVisitor lPrintXMLVisitor(std::cout);
      lPrintXMLVisitor.print(&*n_p);
    }    
	
    MainModule* mm_p;
    QueryBody* qb_p;
    Expr* ex_p;

    if ((mm_p = dynamic_cast<MainModule*>(&*n_p))==NULL) 
	  {
      ZORBA_ERROR_ALERT(ZorbaError::XPST0003,
                        NULL, true,
                        "Parse error: expecting MainModule");
      zorba->current_xquery = NULL;
      return false;
    }

    if ((qb_p = dynamic_cast<QueryBody*>(&*mm_p->get_query_body()))==NULL)
	  {
      ZORBA_ERROR_ALERT(ZorbaError::XPST0003,
                        NULL, true,
                        "Parse error: expecting MainModule->QueryBody");
      //UnregisterCurrentXQueryForCurrentThread( this );
      zorba->current_xquery = NULL;
      return false;
    }

    if ((ex_p = dynamic_cast<Expr*>(&*qb_p->get_expr()))==NULL) 
	  {
      ZORBA_ERROR_ALERT(ZorbaError::XPST0003,
                        NULL, true, 
                        "Parse error: expecting MainModule->QueryBody->Expr");
      zorba->current_xquery = NULL;
      return false;
    }

    rchandle<expr> e_h = translate (zorba->get_static_context(), *mm_p);
    if (e_h == NULL)
    {
      ZORBA_ERROR_ALERT(ZorbaError::API0002_COMPILE_FAILED, NULL, true);
      zorba->current_xquery = NULL;
      return false;
    }
  
    if (Properties::instance ()->printTranslatedExpressions ()) {
      cout << "Expression tree after translation:\n";
      e_h->put(cout) << endl;
    }

    normalizer n(zorba->get_static_context());
    e_h->accept(n);

    if (Properties::instance ()->printNormalizedExpressions ()) {
      cout << "Expression tree after normalization:\n";
      e_h->put(cout) << endl;
    }

    ///now do code generation (generate iterator tree)

    top_iterator = codegen (e_h);

    if (top_iterator == NULL) {
      cout << "Codegen returned null";
      ZORBA_ERROR_ALERT(ZorbaError::API0002_COMPILE_FAILED, NULL, true);
      zorba->current_xquery = NULL;
      return false;
    }

    if (Properties::instance()->printIteratorTree()) {
      cout << "Iterator tree:\n";
      XMLIterPrinter vp(std::cout);
      PrinterVisitor pv(vp);
      top_iterator->accept(pv);
    }
	
    is_compiled = true;

		zorba->current_xquery = NULL;

		return true;
  }
//  catch(xqp_exception &)
//  {
//  }
	CATCH_ALL_NO_RETURN(zorba->current_xquery = NULL;);

//  zorba->current_xquery = NULL;
  return false;
}


bool Zorba_XQueryBinary::initExecution( DynamicQueryContext_t dctx)
{
	Zorba_XQueryBinary	*prev_xquery = NULL;
  // register this xquery as the current xquery executed/compiling in this current thread
  Zorba* zorba = ZORBA_FOR_CURRENT_THREAD();
	if(!zorba)
	{
    ZORBA_ERROR_ALERT(ZorbaError::API0009_THREAD_NOT_INITIALIZED, NULL, true);
		return false;//
	}

  try{
	prev_xquery = zorba->current_xquery;
  zorba->current_xquery = this;

  
  if(!is_compiled)
  {
    cout << "not compiled" << endl;
    ZORBA_ERROR_ALERT(ZorbaError::API0003_XQUERY_NOT_COMPILED, NULL, true);
    zorba->current_xquery = prev_xquery;
    return false;
  }

  close();
  delete state_block;
	state_block = NULL;
	delete internal_dyn_context;
	internal_dyn_context = NULL;

	theClosed = false;
  ///compute the offsets for each iterator into the state block
	int32_t		lStateSize;
  lStateSize = top_iterator->getStateSizeOfSubtree();
  state_block = new PlanState(lStateSize);
  uint32_t lOffset = 0;
  top_iterator->open(*state_block, lOffset);

  ///and construct the state block of state objects...
  state_block->theZorba = zorba;

	if(dctx != NULL)
  {
    DynamicContextWrapper *dctx_wrapper = static_cast<DynamicContextWrapper*>(dctx.getp());
    dctx_wrapper->create_dynamic_context(internal_sctx, &internal_dyn_context);
  }
	else
	{
		if(!internal_dyn_context)
			internal_dyn_context = new dynamic_context;
	}

  zorba->current_xquery = prev_xquery;

  return true;//execution started
  }
//  catch(xqp_exception &)
//  {
//  }
	CATCH_ALL_NO_RETURN(zorba->current_xquery = prev_xquery;);

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
  ZORBA_ERROR_ALERT(ZorbaError::XQP0015_SYSTEM_NOT_YET_IMPLEMENTED,
                    NULL,
                    true,///continue execution
                    "Zorba_XQueryBinary::serializeQuery"
                    );
  return false;
}

void Zorba_XQueryBinary::setAlertsParam(void *alert_callback_param)
{
	try{

  this->alert_callback_param = alert_callback_param;

	}CATCH_ALL_NO_RETURN(;);
}

/*
  next() should be called in the same thread where the xquery was called execute()
*/
Item_t Zorba_XQueryBinary::next()
{
	if(!state_block)
	{
	  ZORBA_ERROR_ALERT(ZorbaError::API0010_XQUERY_EXECUTION_NOT_STARTED,
                    NULL,
                    true);///continue execution
		return NULL;
	}
  if (theClosed)
  {
	  ZORBA_ERROR_ALERT(ZorbaError::API0010_XQUERY_EXECUTION_NOT_STARTED,
                    NULL,
                    true);///continue execution
    return NULL;
  }

	Zorba_XQueryBinary        *prev_current_xquery = state_block->theZorba->current_xquery;
  state_block->theZorba->current_xquery = this;
  try
  {
    Item_t it = top_iterator->produceNext( *state_block );

    state_block->theZorba->current_xquery = prev_current_xquery;

    return it;
  }
//  catch(xqp_exception &)
//  {
//  }
	CATCH_ALL_NO_RETURN(  \
  state_block->theZorba->current_xquery = prev_current_xquery;)

  return NULL;
}

void
Zorba_XQueryBinary::reset()
{
	if(!state_block)
	{
	  ZORBA_ERROR_ALERT(ZorbaError::API0010_XQUERY_EXECUTION_NOT_STARTED,
                    NULL,
                    true);///continue execution
		return;
	}
	Zorba_XQueryBinary        *prev_current_xquery = state_block->theZorba->current_xquery;
  state_block->theZorba->current_xquery = this;
	try
  {
    if (!theClosed)
    {
      top_iterator->reset(*state_block);
    }

    state_block->theZorba->current_xquery = prev_current_xquery;
		return;
	}
//  catch(xqp_exception &)
//	{
//	}
	CATCH_ALL_NO_RETURN(\
  state_block->theZorba->current_xquery = prev_current_xquery;);
}


void
Zorba_XQueryBinary::close()
{
	if(!state_block)
		return;
	Zorba			*zorba = ZORBA_FOR_CURRENT_THREAD();
	Zorba_XQueryBinary        *prev_current_xquery = NULL;
	if(zorba)
	{
		prev_current_xquery = zorba->current_xquery;
		zorba->current_xquery = this;
	}
	try
  {
    if (!theClosed)
    {
      top_iterator->close(*state_block); 
	    delete state_block;
			state_block = NULL;
      theClosed = true;
    }
		if(zorba)
			zorba->current_xquery = prev_current_xquery;
		return;
	}
//  catch(xqp_exception &)
//	{
//	}
	CATCH_ALL_NO_RETURN(\
  if(zorba) zorba->current_xquery = prev_current_xquery;);

}


bool Zorba_XQueryBinary::serialize( ostream& os )
{
  state_block->theZorba->current_xquery = this;

  serializer *ser;
	try
  {
		ser = ZORBA_FOR_CURRENT_THREAD()->getDocSerializer();

    ser->serialize(this, os);
	}
//  catch(xqp_exception &)
//  {
//	}
	CATCH_ALL_NO_RETURN(;);
  state_block->theZorba->current_xquery = NULL;
  return !isError();
}

bool Zorba_XQueryBinary::serializeXML( std::ostream& os )
{
  state_block->theZorba->current_xquery = this;

  auto_ptr<serializer> ser(new serializer);

	try
  {
    ser->serialize(this, os);
	}
//  catch(xqp_exception &)
//  {
//	}
	CATCH_ALL_NO_RETURN(;);
	state_block->theZorba->current_xquery = NULL;
  return !isError();
}

bool Zorba_XQueryBinary::serializeHTML( std::ostream& os )
{
  state_block->theZorba->current_xquery = this;

  auto_ptr<serializer> ser(new serializer);
	
	try{
		ser->set_parameter("method", "html");
		ser->serialize(this, os);
	}
//  catch(xqp_exception &)
//  {
//	}
	CATCH_ALL_NO_RETURN(;);
  state_block->theZorba->current_xquery = NULL;
  return !isError();
}

bool Zorba_XQueryBinary::serializeTEXT( std::ostream& os )
{
  state_block->theZorba->current_xquery = this;

	try{
  Item_t    it;

  while(1)
  {
    it = next();
    if(!it.getp())
      break;
    os << it->show() << endl;
  }
	}
//  catch(xqp_exception &)
//  {
//	}
	CATCH_ALL_NO_RETURN(;);
  state_block->theZorba->current_xquery = NULL;
  return !isError();
}


bool Zorba_XQueryBinary::isError()
{
  //return is_error;
	return ZorbaEngine::getInstance().getAlertsManagerForCurrentThread().isError();
}

void  Zorba_XQueryBinary::AbortQueryExecution()
{
  ZORBA_ERROR_ALERT(ZorbaError::XQP0015_SYSTEM_NOT_YET_IMPLEMENTED,
                    NULL,
                    true,///continue execution
                    "AbortQueryExecution"
                    );
}

/*extension from dynamic context (specific only for this execution)
bind external variable with the result from another xquery
*/
bool Zorba_XQueryBinary::SetVariable( xqp_string varname, 
                                        XQuery_t item_iter )
{
	if(!state_block)
	{
	  ZORBA_ERROR_ALERT(ZorbaError::API0010_XQUERY_EXECUTION_NOT_STARTED,
                    NULL,
                    true);///continue execution
		return false;
	}
  state_block->theZorba->current_xquery = this;

	try{

  ///add to dynamic context
  if(!internal_dyn_context)
    internal_dyn_context = new dynamic_context;
  xqp_string    expanded_name;
  expanded_name = internal_dyn_context->expand_varname(internal_sctx, varname);
  internal_dyn_context->add_variable(expanded_name, item_iter.getp());

  state_block->theZorba->current_xquery = NULL;
  return true;
	}
//  catch(xqp_exception &)
//  {
//  }
	CATCH_ALL_NO_RETURN(\
  state_block->theZorba->current_xquery = NULL;);
  return false;
}


bool Zorba_XQueryBinary::SetVariable(
    xqp_string    varname,
    xqp_string    docUri,
    std::istream& is)
{
	if(!state_block)
	{
	  ZORBA_ERROR_ALERT(ZorbaError::API0010_XQUERY_EXECUTION_NOT_STARTED,
                    NULL,
                    true);///continue execution
		return false;
	}
  state_block->theZorba->current_xquery = this;

  PlanIter_t iter;
  PlanWrapper* planWrapper = NULL;

	try
  {
    if(!internal_dyn_context)
      internal_dyn_context = new dynamic_context;

    xqp_string expanded_name = internal_dyn_context->expand_varname(internal_sctx, varname);

		Store		&store = Store::getInstance();
		ItemFactory* factory = Zorba::getItemFactory();

    Item_t uriItem = factory->createAnyURI(docUri);
		if(uriItem == NULL)
		{//not a valid uri
			state_block->theZorba->current_xquery = NULL;
			return false;
		}
		//?store.deleteDocument(docUri);
		Item_t	docItem = store.loadDocument(docUri, is);
		if(docItem == NULL)
		{//cannot upload document into store
			//or maybe is not valid xml
			state_block->theZorba->current_xquery = NULL;
			return false;
		}

    iter = new SingletonIterator(Zorba::null_loc, uriItem);
    iter = new FnDocIterator(Zorba::null_loc, iter);

    planWrapper = new PlanWrapper(iter);

    internal_dyn_context->add_variable(expanded_name, planWrapper);

		state_block->theZorba->current_xquery = NULL;
    return true;
	}
//  catch(xqp_exception &)
//  {
//  }
	CATCH_ALL_NO_RETURN(\
  if (planWrapper != NULL)\
    delete planWrapper;\
  state_block->theZorba->current_xquery = NULL;);
  return false;
}


///register documents available through fn:doc() in xquery
/*
bool Zorba_XQueryBinary::AddAvailableDocument(xqp_string docURI,
                                                Item_t docitem)
{
  state_block->theZorba->current_xquery = this;

  ///add to dynamic context
	try{
  state_block->theZorba->current_xquery = NULL;
  return false;
	}
//  catch(xqp_exception &)
//  {
//	}
	CATCH_ALL_NO_RETURN(\
	state_block->theZorba->current_xquery = NULL;);
	return false;
}
*/

///register collections available through fn:collection() in xquery
///default collection has empty URI ""
/*
bool Zorba_XQueryBinary::AddAvailableCollection(xqp_string collectionURI,
                                                  Collection_t collection)
{
  state_block->theZorba->current_xquery = this;

  ///add to dynamic context
	try{
  state_block->theZorba->current_xquery = NULL;
  return false;
	}
//  catch(xqp_exception &)
//  {
//	}
	CATCH_ALL_NO_RETURN(\
	state_block->theZorba->current_xquery = NULL;);
	return false;
}
*/

XQuery_t Zorba_XQueryBinary::clone()
{
	return new Zorba_XQueryBinary(this);
}

}///end namespace xqp
