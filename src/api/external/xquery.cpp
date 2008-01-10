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
   const char* query_text)
  :
  m_xquery_source_uri(xquery_source_uri),
  m_query_text (query_text)
{
  is_compiled = false;
  top_iterator = NULL;
  lStateSize = 0;
  internal_sctx = NULL;

  default_collator = NULL;
}


Zorba_XQueryBinary::~Zorba_XQueryBinary()
{
  delete internal_sctx;
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
      ZORBA_ERROR_ALERT(AlertCodes::API0004_XQUERY_ALREADY_COMPILED,
                        NULL,
                        true///continue execution
                        );
      zorba->current_xquery = NULL;
      return false;
    }

    if(!m_query_text[0])
	  {
      ZORBA_ERROR_ALERT(AlertCodes::API0001_XQUERY_STRING_IS_EMPTY,
                        NULL,
                        true///continue execution
                        );
      zorba->current_xquery = NULL;
      return false;
    }

    if (sctx) {
      internal_static_context = sctx;
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
    driver.parse_string(m_query_text);

    parsenode* n_p = driver.get_expr();

    if (Properties::instance()->printAST())
	  {
      cout << "Parse tree:\n";
      ParseNodePrintXMLVisitor lPrintXMLVisitor(std::cout);
      lPrintXMLVisitor.print(n_p);
    }    
	
    MainModule* mm_p;
    QueryBody* qb_p;
    Expr* ex_p;

    if ((mm_p = dynamic_cast<MainModule*>(n_p))==NULL) 
	  {
      ZORBA_ERROR_ALERT(AlertCodes::XPST0003,
                        NULL, true,
                        "Parse error: expecting MainModule");
      zorba->current_xquery = NULL;
      return false;
    }

    if ((qb_p = dynamic_cast<QueryBody*>(&*mm_p->get_query_body()))==NULL) 
	  {
      ZORBA_ERROR_ALERT(AlertCodes::XPST0003,
                        NULL, true,
                        "Parse error: expecting MainModule->QueryBody");
      //UnregisterCurrentXQueryForCurrentThread( this );
      zorba->current_xquery = NULL;
      return false;
    }

    if ((ex_p = dynamic_cast<Expr*>(&*qb_p->get_expr()))==NULL) 
	  {
      ZORBA_ERROR_ALERT(AlertCodes::XPST0003,
                        NULL, true, 
                        "Parse error: expecting MainModule->QueryBody->Expr");
      zorba->current_xquery = NULL;
      return false;
    }

    if (Properties::instance ()->printNormalizedExpressions ())
      cout << "Expression tree:\n";

    rchandle<expr> e_h = translate (zorba->get_static_context(), *mm_p);
    if (e_h == NULL)
    {
      ZORBA_ERROR_ALERT(AlertCodes::API0002_COMPILE_FAILED, NULL, true);
      zorba->current_xquery = NULL;
      return false;
    }
  
    normalizer n(zorba->get_static_context());
    e_h->accept(n);

    if (Properties::instance()->printNormalizedExpressions())
      e_h->put(cout) << endl;

    ///now do code generation (generate iterator tree)

    top_iterator = codegen (e_h);

    if (Properties::instance()->printIteratorTree()) {
      cout << "Iterator tree:\n";
      XMLIterPrinter vp(std::cout);
      PrinterVisitor pv(vp);
      top_iterator->accept(pv);
    }
	
    if (top_iterator == NULL) {
      cout << "Codegen returned null";
      ZORBA_ERROR_ALERT(AlertCodes::API0002_COMPILE_FAILED, NULL, true);
      zorba->current_xquery = NULL;
      return false;
    }

    is_compiled = true;

  }
  catch(xqp_exception &)
  {
    zorba->current_xquery = NULL;
    return false;
  }
  catch(...)
  {
    zorba->current_xquery = NULL;
    throw;
  }

  zorba->current_xquery = NULL;

  return true;
}


XQueryExecution_t Zorba_XQueryBinary::createExecution( DynamicQueryContext_t dctx)
{
  // init thread
  // check if thread is inited, if not do automatic init
  // and register this xquery as the current xquery executed/compiling in this current thread
  Zorba* zorba = ZORBA_FOR_CURRENT_THREAD();
  zorba->current_xquery = this;
  // RegisterCurrentXQueryForCurrentThread( this );

  try{
  
  if(!is_compiled)
  {
    cout << "not compiled" << endl;
    ZORBA_ERROR_ALERT(AlertCodes::API0003_XQUERY_NOT_COMPILED,
                                  NULL,
                                  true///continue execution
                                  );
    zorba->current_xquery = NULL;
    return NULL;
  }

  ///compute the offsets for each iterator into the state block
  lStateSize = top_iterator->getStateSizeOfSubtree();//daniel: is this needed at every execution?
  PlanState* stateBlock = new PlanState(lStateSize);
  uint32_t lOffset = 0;
  top_iterator->setOffset(*stateBlock, lOffset);

  ///and construct the state block of state objects...
  Zorba_XQueryExecution* zorba_result = new Zorba_XQueryExecution();
  zorba_result->it_result = top_iterator;
  zorba_result->state_block = stateBlock;
  zorba_result->state_block->zorp = zorba;
  zorba_result->state_block->xqbinary = this;
	this->addReference();
//  zorba_result->state_block->xqexecution = zorba_result;
  if(dctx.get_ptr())
  {
    DynamicContextWrapper *dctx_wrapper = static_cast<DynamicContextWrapper*>(dctx.get_ptr());
    zorba_result->internal_dyn_context = dctx_wrapper->create_dynamic_context(internal_sctx);
  }
	else
	{
    zorba_result->internal_dyn_context = new dynamic_context;
	}

  zorba->current_xquery = NULL;
//  RegisterCurrentXQueryForCurrentThread( NULL );

  return zorba_result;
  }
  catch(xqp_exception &)
  {
    zorba->current_xquery = NULL;
    return NULL;
  }
  catch(...)
  {
    zorba->current_xquery = NULL;
    throw;
  }
  
  return NULL;

}

//bool Zorba_XQueryBinary::isCompiled()
//{
//  return is_compiled;
//}

//QueryPtr Zorba_XQueryBinary::clone()
//{
//}

StaticQueryContext_t Zorba_XQueryBinary::getInternalStaticContext()
{
	if(internal_static_context.get_ptr() == NULL)
		internal_static_context = new StaticContextWrapper();
  return internal_static_context;
}


bool   Zorba_XQueryBinary::serializeQuery(ostream &os)
{
  ZORBA_ERROR_ALERT(AlertCodes::XQP0015_SYSTEM_NOT_YET_IMPLEMENTED,
                    NULL,
                    true,///continue execution
                    "Zorba_XQueryBinary::serializeQuery"
                    );
  return false;
}

/*
  Register the callback for the thread specific error manager
*/
/*
void Zorba_XQueryBinary::RegisterAlertCallback(alert_callback *user_alert_callback,
                                                void *param)
{
  xquery_registered_callback = user_alert_callback;
  xquery_registered_param = param;
}
*/

Zorba_XQueryExecution::Zorba_XQueryExecution()
{
  theClosed = false;
  is_error = false;
  internal_dyn_context = NULL;
}

Zorba_XQueryExecution::~Zorba_XQueryExecution()
{
	state_block->xqbinary->removeReference();

  delete state_block;
  delete internal_dyn_context;

}

void Zorba_XQueryExecution::setAlertsParam(void *alert_callback_param)
{
  this->alert_callback_param = alert_callback_param;
}

/*
  next() should be called in the same thread where the xquery was called execute()
*/
Item_t Zorba_XQueryExecution::next()
{
  if (theClosed)
  {
    return NULL;
  }

	Zorba_XQueryBinary        *prev_current_xquery = state_block->zorp->current_xquery;
	Zorba_XQueryExecution     *prev_current_xqueryresult = state_block->zorp->current_xqueryresult;
  state_block->zorp->current_xquery = state_block->xqbinary;
  state_block->zorp->current_xqueryresult = this;
  try
  {

    Item_t it = it_result->produceNext( *state_block );

    state_block->zorp->current_xquery = prev_current_xquery;
    state_block->zorp->current_xqueryresult = prev_current_xqueryresult;

    return it;
  }
  catch(xqp_exception &)
  {
    is_error = true;
    state_block->zorp->current_xquery = prev_current_xquery;
    state_block->zorp->current_xqueryresult = prev_current_xqueryresult;
    return NULL;
  }
  catch(...)
  {
    is_error = true;
    state_block->zorp->current_xquery = prev_current_xquery;
    state_block->zorp->current_xqueryresult = prev_current_xqueryresult;
    throw;
  }

  return NULL;
}

void
Zorba_XQueryExecution::reset()
{
	Zorba_XQueryBinary        *prev_current_xquery = state_block->zorp->current_xquery;
	Zorba_XQueryExecution     *prev_current_xqueryresult = state_block->zorp->current_xqueryresult;
  state_block->zorp->current_xquery = state_block->xqbinary;
  state_block->zorp->current_xqueryresult = this;
	try
  {
    if (!theClosed)
    {

      it_result->reset(*state_block);

      state_block->zorp->current_xquery = prev_current_xquery;
      state_block->zorp->current_xqueryresult = prev_current_xqueryresult;
    }
	}
  catch(xqp_exception &)
	{
    is_error = true;
    state_block->zorp->current_xquery = prev_current_xquery;
    state_block->zorp->current_xqueryresult = prev_current_xqueryresult;
	}
  catch(...)
  {
    is_error = true;
    state_block->zorp->current_xquery = prev_current_xquery;
    state_block->zorp->current_xqueryresult = prev_current_xqueryresult;
    throw;
  }

  is_error = false;
}


void
Zorba_XQueryExecution::close()
{
	Zorba_XQueryBinary        *prev_current_xquery = state_block->zorp->current_xquery;
	Zorba_XQueryExecution     *prev_current_xqueryresult = state_block->zorp->current_xqueryresult;
  state_block->zorp->current_xquery = state_block->xqbinary;
  state_block->zorp->current_xqueryresult = this;
	try
  {
    if (!theClosed)
    {

      it_result->releaseResources(*state_block); 

      state_block->zorp->current_xquery = prev_current_xquery;
      state_block->zorp->current_xqueryresult = prev_current_xqueryresult;

      theClosed = true;
    }
	}
  catch(xqp_exception &)
	{
    is_error = true;
    state_block->zorp->current_xquery = prev_current_xquery;
    state_block->zorp->current_xqueryresult = prev_current_xqueryresult;
	}
  catch(...)
  {
    is_error = true;
    state_block->zorp->current_xquery = prev_current_xquery;
    state_block->zorp->current_xqueryresult = prev_current_xqueryresult;
    throw;
  }

  is_error = false;
}


bool Zorba_XQueryExecution::serialize( ostream& os )
{
  state_block->zorp->current_xquery = state_block->xqbinary;
  state_block->zorp->current_xqueryresult = this;

  serializer *ser;
	try
  {
		ser = ZORBA_FOR_CURRENT_THREAD()->getDocSerializer();

    ser->serialize(this, os);
	}
  catch(xqp_exception &)
  {
	}
  state_block->zorp->current_xquery = NULL;
  state_block->zorp->current_xqueryresult = NULL;
  return !isError();
}

bool Zorba_XQueryExecution::serializeXML( std::ostream& os )
{
  state_block->zorp->current_xquery = state_block->xqbinary;
  state_block->zorp->current_xqueryresult = this;

  serializer *ser = new serializer;

	try
  {
    ser->serialize(this, os);
    delete ser;
	}
  catch(xqp_exception &)
  {
		delete ser;
	}
  state_block->zorp->current_xquery = NULL;
  state_block->zorp->current_xqueryresult = NULL;
  return !isError();
}

bool Zorba_XQueryExecution::serializeHTML( std::ostream& os )
{
  state_block->zorp->current_xquery = state_block->xqbinary;
  state_block->zorp->current_xqueryresult = this;

  serializer *ser = new serializer;
	try{
  ser->set_parameter("method", "html");
  ser->serialize(this, os);
  delete ser;
	}
  catch(xqp_exception &)
  {
		delete ser;
	}
  state_block->zorp->current_xquery = NULL;
  state_block->zorp->current_xqueryresult = NULL;
  return !isError();
}

bool Zorba_XQueryExecution::serializeTEXT( std::ostream& os )
{
  state_block->zorp->current_xquery = state_block->xqbinary;
  state_block->zorp->current_xqueryresult = this;

	try{
  Item_t    it;

  while(1)
  {
    it = next();
    if(!it.get_ptr())
      break;
    os << it->show() << endl;
  }
	}
  catch(xqp_exception &)
  {
	}
  state_block->zorp->current_xquery = NULL;
  state_block->zorp->current_xqueryresult = NULL;
  return !isError();
}


bool Zorba_XQueryExecution::isError()
{
  return is_error;
}

void  Zorba_XQueryExecution::AbortQueryExecution()
{
  ZORBA_ERROR_ALERT(AlertCodes::XQP0015_SYSTEM_NOT_YET_IMPLEMENTED,
                    NULL,
                    true,///continue execution
                    "AbortQueryExecution"
                    );
}

/*extension from dynamic context (specific only for this execution)
bind external variable with the result from another xquery
*/
bool Zorba_XQueryExecution::SetVariable( xqp_string varname, 
                                        XQueryExecution_t item_iter )
{
  state_block->zorp->current_xquery = state_block->xqbinary;
  state_block->zorp->current_xqueryresult = this;

	try{

  ///add to dynamic context
  if(!internal_dyn_context)
    internal_dyn_context = new dynamic_context;
  xqp_string    expanded_name;
  expanded_name = internal_dyn_context->expand_varname(state_block->xqbinary->internal_sctx, varname);
  internal_dyn_context->add_variable(expanded_name, item_iter.get_ptr());

  state_block->zorp->current_xquery = NULL;
  state_block->zorp->current_xqueryresult = NULL;
  return true;
	}
  catch(xqp_exception &)
  {
		state_block->zorp->current_xquery = NULL;
		state_block->zorp->current_xqueryresult = NULL;
		return false;
  }
  state_block->zorp->current_xquery = NULL;
  state_block->zorp->current_xqueryresult = NULL;
  return false;
}


bool Zorba_XQueryExecution::SetVariable(
    xqp_string    varname,
    xqp_string    docUri,
    std::istream& is)
{
  state_block->zorp->current_xquery = state_block->xqbinary;
  state_block->zorp->current_xqueryresult = this;

  PlanIter_t iter;
  PlanWrapper* planWrapper = NULL;

	try
  {
    if(!internal_dyn_context)
      internal_dyn_context = new dynamic_context;

    xqp_string expanded_name = internal_dyn_context->
                               expand_varname(state_block->xqbinary->internal_sctx, varname);

		Store		&store = Store::getInstance();
		ItemFactory* factory = Zorba::getItemFactory();

    Item_t uriItem = factory->createAnyURI(docUri);
		if(uriItem.isNull())
		{//not a valid uri
			state_block->zorp->current_xquery = NULL;
			state_block->zorp->current_xqueryresult = NULL;
			return false;
		}
		//?store.deleteDocument(docUri);
		Item_t	docItem = store.loadDocument(docUri, is);
		if(docItem.isNull())
		{//cannot upload document into store
			//or maybe is not valid xml
			state_block->zorp->current_xquery = NULL;
			state_block->zorp->current_xqueryresult = NULL;
			return false;
		}

    iter = new SingletonIterator(Zorba::null_loc, uriItem);
    iter = new FnDocIterator(Zorba::null_loc, iter);

    planWrapper = new PlanWrapper(iter);

    internal_dyn_context->add_variable(expanded_name, planWrapper);

		state_block->zorp->current_xquery = NULL;
		state_block->zorp->current_xqueryresult = NULL;
    return true;
	}
  catch(xqp_exception &)
  {
    if (planWrapper != NULL)
      delete planWrapper;

		state_block->zorp->current_xquery = NULL;
		state_block->zorp->current_xqueryresult = NULL;
		return false;
  }
  state_block->zorp->current_xquery = NULL;
  state_block->zorp->current_xqueryresult = NULL;
  return false;
}


///register documents available through fn:doc() in xquery
bool Zorba_XQueryExecution::AddAvailableDocument(xqp_string docURI,
                                                Item_t docitem)
{
  state_block->zorp->current_xquery = state_block->xqbinary;
  state_block->zorp->current_xqueryresult = this;

  ///add to dynamic context
	try{
  state_block->zorp->current_xquery = NULL;
  state_block->zorp->current_xqueryresult = NULL;
  return false;
	}
  catch(xqp_exception &)
  {
		state_block->zorp->current_xquery = NULL;
		state_block->zorp->current_xqueryresult = NULL;
		return false;
	}
  state_block->zorp->current_xquery = NULL;
  state_block->zorp->current_xqueryresult = NULL;
	return false;
}

///register collections available through fn:collection() in xquery
///default collection has empty URI ""
bool Zorba_XQueryExecution::AddAvailableCollection(xqp_string collectionURI,
                                                  Collection_t collection)
{
  state_block->zorp->current_xquery = state_block->xqbinary;
  state_block->zorp->current_xqueryresult = this;

  ///add to dynamic context
	try{
  state_block->zorp->current_xquery = NULL;
  state_block->zorp->current_xqueryresult = NULL;
  return false;
	}
  catch(xqp_exception &)
  {
		state_block->zorp->current_xquery = NULL;
		state_block->zorp->current_xqueryresult = NULL;
		return false;
	}
  state_block->zorp->current_xquery = NULL;
  state_block->zorp->current_xqueryresult = NULL;
	return false;
}


}///end namespace xqp
