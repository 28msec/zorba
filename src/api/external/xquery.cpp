///Created: Daniel Turcanu @ IPDevel 

#include "errors/Error.h"
#include "xquerybinary.h"

#include "compiler/codegen/plan_visitor.h"
#include "compiler/translator/normalize_visitor.h"
#include "compiler/parsetree/parsenode_print_xml_visitor.h"
#include "compiler/parsetree/parsenode_print_dot_visitor.h"
#include "compiler/parser/xquery_driver.h"
#include "util/zorba.h"
//#include "store/naive/basic_item_factory.h"
//#include "store/naive/simple_store.h"

#include "api/serialization/serializer.h"

//#include "../../test/timer.h"

#include <iostream>
#include <fstream>

using namespace std;
namespace xqp {


Zorba_XQueryBinary::Zorba_XQueryBinary( const char* query_text ) :
	m_query_text (query_text)
{
	is_compiled = false;
	top_iterator = NULL;
	lStateSize = 0;

	//addReference();
//	xquery_registered_callback = NULL;
//	xquery_registered_param = NULL;
}

//Zorba_XQueryBinary::Zorba_XQueryBinary()
//{
//}

Zorba_XQueryBinary::~Zorba_XQueryBinary()
{
}

bool Zorba_XQueryBinary::compile(StaticQueryContext* sctx, bool routing_mode)
{
	zorba	*thread_specific_zorba;

	thread_specific_zorba = zorba::getZorbaForCurrentThread();
	thread_specific_zorba->current_xquery = this;
	
	try{

	if(is_compiled)
	{
		ZORBA_ERROR_ALERT(error_messages::API0004_XQUERY_ALREADY_COMPILED,
																	error_messages::STATIC_ERROR,
																	NULL,
																	true///continue execution
																	);
		thread_specific_zorba->current_xquery = NULL;
		return false;
	}


	///reset the error list from error manager
//	m_error_manager.clear();///delete all alerts from list

	//if(m_query_text.empty())
	if(!m_query_text[0])
	{
		ZORBA_ERROR_ALERT(error_messages::API0001_XQUERY_STRING_IS_EMPTY,
																	error_messages::STATIC_ERROR,
																	NULL,
																	true///continue execution
																	);
		//UnregisterCurrentXQueryForCurrentThread( this );
		thread_specific_zorba->current_xquery = NULL;
		return false;
	}
	
	///NOW COMPILE
	xquery_driver driver(cout);///for debug, send log text on cout

	///build up the expression tree
	driver.parse_string(m_query_text);

	parsenode* n_p = driver.get_expr();
	cout << endl;
	
	{
              std::ofstream lXMLOutFile("query.xml");
              ParseNodePrintXMLVisitor lPrintXMLVisitor(lXMLOutFile);
              lPrintXMLVisitor.print(n_p);
          }    

          {
              std::ofstream lDOTOutFile("query.dot");				
              ParseNodePrintDOTVisitor lPrintDOTVisitor(lDOTOutFile);
              lPrintDOTVisitor.print(n_p);
	}
	
	cout << "Syntax tree:\n";
	n_p->put(cout) << endl;

	///normalize the expression tree
	normalize_visitor nvs;
	MainModule* mm_p;
	QueryBody* qb_p;
	Expr* ex_p;

	if ((mm_p = dynamic_cast<MainModule*>(n_p))==NULL) 
	{
		cout << "Parse error: expecting MainModule\n";
		ZORBA_ERROR_ALERT(error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
																	error_messages::SYSTEM_ERROR,
																	NULL,
																	true///continue execution
																	);
		//UnregisterCurrentXQueryForCurrentThread( this );
		thread_specific_zorba->current_xquery = NULL;
		return false;
	}
	if ((qb_p = dynamic_cast<QueryBody*>(&*mm_p->get_query_body()))==NULL) 
	{
		cout << "Parse error: expecting MainModule->QueryBody\n";
		ZORBA_ERROR_ALERT(error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
																	error_messages::SYSTEM_ERROR,
																	NULL,
																	true///continue execution
																	);
		//UnregisterCurrentXQueryForCurrentThread( this );
		thread_specific_zorba->current_xquery = NULL;
		return false;
	}
	if ((ex_p = dynamic_cast<Expr*>(&*qb_p->get_expr()))==NULL) 
	{
		cout << "Parse error: expecting MainModule->QueryBody->Expr\n";
		ZORBA_ERROR_ALERT(error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
																	error_messages::SYSTEM_ERROR,
																	NULL,
																	true///continue execution
																	);
		//UnregisterCurrentXQueryForCurrentThread( this );
		thread_specific_zorba->current_xquery = NULL;
		return false;
	}

	cout << "Expression tree:\n";
	mm_p->accept(nvs);
	rchandle<expr> e_h = nvs.pop_nodestack();

	cout << endl;

	if (e_h==NULL) {
		cout << "e_h==NULL\n";
		ZORBA_ERROR_ALERT(error_messages::API0002_COMPILE_FAILED,
																	error_messages::STATIC_ERROR,
																	NULL,
																	true///continue execution
																	);
		thread_specific_zorba->current_xquery = NULL;
		return false;
	}
	e_h->put(cout) << endl;

	///now do code generation (generate iterator tree)

	cout << "Codegen:\n";
	plan_visitor pvs;
	e_h->accept(pvs);
	top_iterator = pvs.pop_itstack();
	cout << endl;

	cout << "Iterator tree:" << std::endl;
	top_iterator->show(cout);
	
	//cout << "iterator type = " << typeid(*it_h).name() << endl;
	cout << "\nIterator run:\n";
	if (top_iterator==NULL) {
		cout << "it_h==NULL\n";
		ZORBA_ERROR_ALERT(error_messages::API0002_COMPILE_FAILED,
																	error_messages::STATIC_ERROR,
																	NULL,
																	true///continue execution
																	);
		//UnregisterCurrentXQueryForCurrentThread( this );
		thread_specific_zorba->current_xquery = NULL;
		return false;
	}

	is_compiled = true;

	}
	catch(xqp_exception &)
	{
		thread_specific_zorba->current_xquery = NULL;
		return false;
	}
	catch(...)
	{
		thread_specific_zorba->current_xquery = NULL;
		throw;
	}

	//UnregisterCurrentXQueryForCurrentThread( this );
	thread_specific_zorba->current_xquery = NULL;

	return true;
}

XQueryResult_t Zorba_XQueryBinary::execute( DynamicQueryContext* dctx)
{
	///init thread
	//check if thread is inited, if not do automatic init
	///and register this xquery as the current xquery executed/compiling in this current thread
	zorba	*thread_specific_zorba;

	thread_specific_zorba = zorba::getZorbaForCurrentThread();
	thread_specific_zorba->current_xquery = this;
//	RegisterCurrentXQueryForCurrentThread( this );

	try{
	
	if(!is_compiled)
	{
		cout << "not compiled" << endl;
		ZORBA_ERROR_ALERT(error_messages::API0003_XQUERY_NOT_COMPILED,
																	error_messages::RUNTIME_ERROR,
																	NULL,
																	true///continue execution
																	);
		thread_specific_zorba->current_xquery = NULL;
		return NULL;
	}

	///compute the offsets for each iterator into the state block
	lStateSize = top_iterator->getStateSizeOfSubtree();//daniel: is this needed at every execution?
	PlanState* stateBlock = new PlanState(lStateSize);
	int32_t lOffset = 0;
	top_iterator->setOffset(*stateBlock, lOffset);

	Zorba_XQueryResult* zorba_result = new Zorba_XQueryResult();
	zorba_result->it_result = top_iterator;
	zorba_result->state_block = stateBlock;
	zorba_result->state_block->zorp = thread_specific_zorba;
	zorba_result->state_block->xqbinary = this;
	///and construct the state block of state objects...

	thread_specific_zorba->current_xquery = NULL;
//	RegisterCurrentXQueryForCurrentThread( NULL );

	return zorba_result;
	}
	catch(xqp_exception &)
	{
		thread_specific_zorba->current_xquery = NULL;
		return NULL;
	}
	catch(...)
	{
		thread_specific_zorba->current_xquery = NULL;
		throw;
	}
	
	return NULL;

}

//bool Zorba_XQueryBinary::isCompiled()
//{
//	return is_compiled;
//}

//QueryPtr Zorba_XQueryBinary::clone()
//{
//}

StaticQueryContext* Zorba_XQueryBinary::getInternalStaticContext()
{
	return NULL;//&internal_static_context;
}


bool   Zorba_XQueryBinary::serializeQuery(ostream &os)
{
	return false;
}

/*
	Register the callback for the thread specific error manager
*/
/*
void Zorba_XQueryBinary::RegisterAlertCallback(alert_callback	*user_alert_callback,
																								void *param)
{
	xquery_registered_callback = user_alert_callback;
	xquery_registered_param = param;
}
*/

Zorba_XQueryResult::Zorba_XQueryResult()
{
	is_error = false;
}

Zorba_XQueryResult::~Zorba_XQueryResult()
{
  delete state_block;
}

void Zorba_XQueryResult::setAlertsParam(void *alert_callback_param)
{
	this->alert_callback_param = alert_callback_param;
}

/*
	next() should be called in the same thread where the xquery was called execute()
*/
Item_t Zorba_XQueryResult::next()
{
	state_block->zorp->current_xquery = state_block->xqbinary;
	state_block->zorp->current_xqueryresult = this;

	try{

	Item_t it = it_result->produceNext( *state_block );

	state_block->zorp->current_xquery = NULL;
	state_block->zorp->current_xqueryresult = NULL;

	return it;
	}
	catch(xqp_exception &)
	{
		is_error = true;
		state_block->zorp->current_xquery = NULL;
		state_block->zorp->current_xqueryresult = NULL;
		return NULL;
	}
	catch(...)
	{
		state_block->zorp->current_xquery = NULL;
		state_block->zorp->current_xqueryresult = NULL;
		throw;
	}

	return NULL;
}

ostream& Zorba_XQueryResult::serializeXML( ostream& os )
{
	serializer ser;
	ser.serialize(this, os);
	return os;
}

bool Zorba_XQueryResult::isError()
{
	return is_error;
}

}///end namespace xqp
