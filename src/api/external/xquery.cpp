///Created: Daniel Turcanu @ IPDevel 

#include "errors/Error.h"
#include "xquerybinary.h"

#include "compiler/codegen/plan_visitor.h"
#include "compiler/translator/normalize_visitor.h"
#include "compiler/parsetree/parsenode_print_xml_visitor.h"
#include "compiler/parsetree/parsenode_print_dot_visitor.h"
#include "compiler/parser/xquery_driver.h"
#include "util/zorba.h"
#include "store/naive/basic_item_factory.h"
#include "store/naive/simple_store.h"

#include "../test/timer.h"

#include <iostream>
#include <fstream>

using namespace std;
namespace xqp {


Zorba_XQueryBinary::Zorba_XQueryBinary( xqp_string query_text ) :
	m_query_text (query_text)
{
	is_compiled = false;
	top_iterator = NULL;
	lStateSize = 0;
}

//Zorba_XQueryBinary::Zorba_XQueryBinary()
//{
//}

Zorba_XQueryBinary::~Zorba_XQueryBinary()
{
}

bool Zorba_XQueryBinary::compile(StaticQueryContext* sctx, bool routing_mode)
{
	
	if(is_compiled)
	{
		ZorbaErrorAlerts::error_alert(error_messages::API0004_XQUERY_ALREADY_COMPILED,
																	error_messages::STATIC_ERROR,
																	NULL,
																	true///continue execution
																	);
		return false;
	}

	///init thread
	//check if thread is inited, if not do automatic init
	///and register this xquery as the current xquery executed/compiling in this current thread
	zorba	*thread_specific_zorba;

	thread_specific_zorba = zorba::getZorbaForCurrentThread();
	thread_specific_zorba->current_xquery = this;
//	RegisterCurrentXQueryForCurrentThread( this );

	///reset the error list from error manager
//	m_error_manager.clear();///delete all alerts from list

	if(m_query_text.empty())
	{
		ZorbaErrorAlerts::error_alert(error_messages::API0001_XQUERY_STRING_IS_EMPTY,
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
	driver.parse(m_query_text);

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
		ZorbaErrorAlerts::error_alert(error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
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
		ZorbaErrorAlerts::error_alert(error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
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
		ZorbaErrorAlerts::error_alert(error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
																	error_messages::SYSTEM_ERROR,
																	NULL,
																	true///continue execution
																	);
		//UnregisterCurrentXQueryForCurrentThread( this );
		thread_specific_zorba->current_xquery = NULL;
		return false;
	}

	cout << "Expression tree:\n";
	ex_p->accept(nvs);
	rchandle<expr> e_h = nvs.pop_nodestack();

	cout << endl;

	if (e_h==NULL) {
		cout << "e_h==NULL\n";
		thread_specific_zorba->current_xquery = NULL;
		ZorbaErrorAlerts::error_alert(error_messages::API0002_COMPILE_FAILED,
																	error_messages::STATIC_ERROR,
																	NULL,
																	true///continue execution
																	);
		return false;
	}
	e_h->put(cout) << endl;

	///now do code generation (generate iterator tree)

	cout << "Codegen:\n";
	plan_visitor pvs;
	e_h->accept(pvs);
	top_iterator = pvs.pop_itstack();
	cout << endl;

	//cout << "iterator type = " << typeid(*it_h).name() << endl;
	cout << "\nIterator run:\n";
	if (top_iterator==NULL) {
		cout << "it_h==NULL\n";
		ZorbaErrorAlerts::error_alert(error_messages::API0002_COMPILE_FAILED,
																	error_messages::STATIC_ERROR,
																	NULL,
																	true///continue execution
																	);
		//UnregisterCurrentXQueryForCurrentThread( this );
		thread_specific_zorba->current_xquery = NULL;
		return false;
	}

	cout << "Iterator tree:" << std::endl;
	top_iterator->show(cout);


	///compute the offsets for each iterator into the state block
	lStateSize = top_iterator->getStateSizeOfSubtree();
	PlanState		*stateBlock = new PlanState(lStateSize);
	int32_t lOffset = 0;
	top_iterator->setOffset(*stateBlock, lOffset);
	delete stateBlock;

	is_compiled = true;

	//UnregisterCurrentXQueryForCurrentThread( this );
	thread_specific_zorba->current_xquery = NULL;

	return true;
}

XQueryResult* Zorba_XQueryBinary::execute( DynamicQueryContext* dctx)
{
	///init thread
	//check if thread is inited, if not do automatic init
	///and register this xquery as the current xquery executed/compiling in this current thread
	zorba	*thread_specific_zorba;

	thread_specific_zorba = zorba::getZorbaForCurrentThread();
	thread_specific_zorba->current_xquery = this;
//	RegisterCurrentXQueryForCurrentThread( this );
	
	if(!is_compiled)
	{
		cout << "not compiled" << endl;
		ZorbaErrorAlerts::error_alert(error_messages::API0003_XQUERY_NOT_COMPILED,
																	error_messages::RUNTIME_ERROR,
																	NULL,
																	true///continue execution
																	);
		thread_specific_zorba->current_xquery = NULL;
		return NULL;
	}


	Zorba_XQueryResult		*zorba_result = new Zorba_XQueryResult;
	zorba_result->it_result = top_iterator;
	zorba_result->state_block = new PlanState(lStateSize);
	zorba_result->state_block->zorp = thread_specific_zorba;
	zorba_result->state_block->xqbinary = this;
	///and construct the state block of state objects...




	thread_specific_zorba->current_xquery = NULL;
//	RegisterCurrentXQueryForCurrentThread( NULL );

	return zorba_result;
}

bool Zorba_XQueryBinary::isCompiled()
{
	return is_compiled;
}

//QueryPtr Zorba_XQueryBinary::clone()
//{
//}


bool   Zorba_XQueryBinary::serializeQuery(ostream &os)
{
	return false;
}


/*
	next() should be called in the same thread where the xquery was executed
*/
Item_t Zorba_XQueryResult::next()
{
	state_block->zorp->current_xquery = state_block->xqbinary;

	return it_result->produceNext( *state_block );
}

}///end namespace xqp
