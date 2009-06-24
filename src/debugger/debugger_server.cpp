/*
* Copyright 2006-2008 The FLWOR Foundation.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
* 
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#include "debugger/debugger_server.h"

#include <zorba/debugger_default_event_handler.h>

#include <memory>
#include <fstream>

#include <zorba/zorba.h>
#include <zorba/uri_resolvers.h>
#include <zorba/util/path.h>

#include "debugger/utils.h"
#include "debugger/socket.h"
#include "debugger/message_factory.h"

#include "compiler/parser/xquery_driver.h"
#include "compiler/dewey/dewey.h"

#include "context/static_context.h"

#include "runtime/fncontext/FnContextImpl.h"
#include "runtime/core/item_iterator.h"
#include "runtime/api/runtimecb.h"
#include "runtime/api/plan_iterator_wrapper.h"
#include "runtime/util/iterator_impl.h"

#include "api/serialization/serializer.h"
#include "api/unmarshaller.h"
#include "api/itemfactoryimpl.h"

#include "system/globalenv.h"
#include "store/api/pul.h"
#include "store/api/item_factory.h"
#include "store/api/store.h"

#include "zorbatypes/numconversions.h"

#include "common/shared_types.h"

#include "debugger/synchronous_logger.h"
#include "debugger/debugger_helper_functions.h"

#ifdef WIN32
#include <windows.h>
#define sleep(s) Sleep(s*1000)
#endif

using namespace std;

namespace zorba{

	ZORBA_THREAD_RETURN runtimeThread( void *aDebugger )
	{
		ZorbaDebugger * lDebugger = (ZorbaDebugger *)aDebugger;
		//We wait for theRuntimeThread to be allocated
		while( lDebugger->theRuntimeThread == 0 ){ sleep(1); }
		lDebugger->runQuery();
#ifndef NDEBUG
		synchronous_logger::clog << "Quit runtimeThread\n";
#endif
		return 0;
	}

	ZorbaDebugger::ZorbaDebugger():
	theQuery(0),
		theOutputStream(0),
		theSerOptions(0),
		theRequestServerSocket(0), 
		theEventSocket(0), 
		theStatus( QUERY_IDLE  ),
		thePlanState(0),
		theRuntimeThread(0),
    m_debuggerCommunicator(0),
		isSteppingOver(false),
		isSteppingInto(false),
		isSteppingOut(false),
		theProfiler(0),
		isFunctionExecution(false),
		catchFunctionExecution(false)
	{
	}


	ZorbaDebugger::~ZorbaDebugger()
	{
		delete theProfiler;
		delete theRequestServerSocket;
		delete theEventSocket;
		delete m_debuggerCommunicator;
	}

	void ZorbaDebugger::start( XQueryImpl *aQuery,
		ostream& aOutStream,
		const Zorba_SerializerOptions_t* aSerOptions,
		unsigned short aRequestPortno,
		unsigned short aEventPortno)
	{
		theProfiler = new Profiler(aQuery->getFileName(), aQuery->getProfileName());
		theQuery = aQuery;
		theOutputStream = &aOutStream;
		theSerOptions = aSerOptions;
		m_debuggerCommunicator = new DebuggerCommunicator(aRequestPortno, aEventPortno);
		m_debuggerCommunicator->handshake();

    theWrapper = theQuery->generateWrapper();

    SYNC_CODE(AutoLock lock(GENV_STORE.getGlobalLock(), theQuery->isUpdateQuery()?Lock::WRITE:Lock::READ);)

    theWrapper->open();

		//Until the query execution has ended
		while ( theStatus != QUERY_TERMINATED )
		{
			auto_ptr<AbstractCommandMessage> message(m_debuggerCommunicator->handleTCPClient());
			if (message.get() != NULL) {
				processMessage(message.get());
				m_debuggerCommunicator->sendReplyMessage(message.get());
			}
		}
#ifndef NDEBUG
		synchronous_logger::clog << "[Server Thread] server quited\n";
#endif
		delete theRuntimeThread;
    theWrapper->close();
#ifndef NDEBUG
		synchronous_logger::clog << "[Server Thread] runtime thread quited\n";
#endif 
	}

	void ZorbaDebugger::setStatus( ExecutionStatus Status,
		SuspensionCause aCause ){

			if ( theStatus == QUERY_SUSPENDED && Status == QUERY_RUNNING )
			{
				theStatus = QUERY_RESUMED;
			} else {
				theStatus = Status;
			}

			switch ( theStatus )
			{
			case QUERY_RUNNING:
				startedEvent();
				break;
			case QUERY_SUSPENDED:
				suspendedEvent( theLocation, aCause );
				break;
			case QUERY_TERMINATED:
				terminatedEvent();
				break;
			case QUERY_RESUMED:
				theStatus = QUERY_RUNNING;
				resumedEvent();
				break;
			}
	}

	void ZorbaDebugger::startedEvent()
	{
		StartedEvent lMessage;
		m_debuggerCommunicator->sendEvent( &lMessage );
	}

	void ZorbaDebugger::suspendedEvent( QueryLoc &aLocation, SuspensionCause aCause )
	{
		SuspendedEvent lMessage( aLocation, aCause );
		m_debuggerCommunicator->sendEvent( &lMessage );
	}

	void ZorbaDebugger::resumedEvent()
	{
		ResumedEvent lMessage;
		m_debuggerCommunicator->sendEvent( &lMessage );
	}

	void ZorbaDebugger::terminatedEvent()
	{
		TerminatedEvent lMessage;
		m_debuggerCommunicator->sendEvent( &lMessage );
	}

	void ZorbaDebugger::runQuery()
	{
		setStatus( QUERY_RUNNING );
		try
		{
			if (theQuery->isUpdateQuery()) {
				theQuery->applyUpdates(theWrapper);
				*theOutputStream << "Query doesn't have a result because it is an updating query.";
			} else {
				theQuery->serialize( *theOutputStream, theWrapper, theSerOptions );
				theOutputStream->flush();
			}
		}catch(zorba::StaticException& se){
			synchronous_logger::cerr << se.getDescription().c_str() << "\n";
		}catch(zorba::DynamicException& e){
			synchronous_logger::cerr << e.getDescription().c_str() << "\n";  
		}catch(zorba::SystemException& e){
			synchronous_logger::cerr << e.getDescription().c_str() << "\n";
		} catch(zorba::TypeException& e) {
			synchronous_logger::cerr << e.getDescription().c_str() << "\n";
		} catch(...) {
			synchronous_logger::cerr << "Unknown exception" << "\n";
		}
		setStatus( QUERY_TERMINATED );
	}

	bool ZorbaDebugger::hasToSuspend()
	{
		//If the query has been suspend by the user
		if( theStatus == QUERY_SUSPENDED ){ return true; }
		map<unsigned int, QueryLoc>::iterator it;
		//TODO: can be faster
		for ( it = theBreakpoints.begin(); it != theBreakpoints.end(); it++ )
		{
			if (it->second == theLocation)
			{
				setStatus( QUERY_SUSPENDED, CAUSE_BREAKPOINT );
				return true;
			}
		}

		map<unsigned int, xqpString>::iterator lIter;
		for ( lIter = theWatchpoints.begin(); lIter != theWatchpoints.end(); lIter++ )
		{
			auto_ptr< CompilerCB > ccb(new CompilerCB(*thePlanState->theCompilerCB));
			auto_ptr< dynamic_context > dctx(new dynamic_context(thePlanState->dctx()));

			//TODO: catch exceptions
			auto_ptr<PlanWrapperHolder> eval_plan = compileEvalPlan(theLocation, ccb.get(), dctx.get(), lIter->second, *thePlanState);
			PlanWrapper* lIterator = eval_plan->get();
			try
			{
				store::Item_t lItem;
				map<xqpString, xqpString> lValuesAndTypes;

				error::ErrorManager lErrorManger;

				lIterator->next(lItem);

				if(lItem->getEBV()->getBooleanValue())
				{
					setStatus(QUERY_SUSPENDED, CAUSE_BREAKPOINT);
					return true;
				}
			} catch ( error::ZorbaError&) {
				//do nothing... 
			}
		}
		return false;
	}

	void ZorbaDebugger::run()
	{
		theRuntimeThread = new Thread( runtimeThread, this );
	}

	void ZorbaDebugger::suspend()
	{
		setStatus( QUERY_SUSPENDED );
	}

	void ZorbaDebugger::resume()
	{
		if ( theStatus == QUERY_SUSPENDED )
		{
			setStatus( QUERY_RUNNING );
			theRuntimeThread->resume();
		}
	}

	void ZorbaDebugger::terminate()
	{
		setStatus( QUERY_TERMINATED );
	}

	stack<unsigned int> ZorbaDebugger::getCurrentDecimal() const
	{
		stack<unsigned int> lCurrentDecimal;
		Classification_t::const_iterator it;
		for(it=theClassification.begin(); it!=theClassification.end(); ++it)
		{
			if(it->first == theLocation)
			{
				lCurrentDecimal = it->second;
				break;
			}
		}
		return lCurrentDecimal;
	}

	std::string ZorbaDebugger::getCurrentFunctionName() const
	{
		QueryLoc loc;
		Classification_t::const_iterator it;
		for(it=theClassification.begin(); it!=theClassification.end(); ++it)
		{
			if(it->first == theLocation)
			{
				loc = it->first;
				break;
			}
		}
		return loc.getFunctionName();
	}

	void ZorbaDebugger::step( const StepCommand aKind )
	{
		if (aKind == STEP_INTO) {
			isSteppingInto = true;
			resume();
			return;
		}
		//find the current decimal.
		stack<unsigned int> lCurrentDecimal = getCurrentDecimal();
		//if the current decimal is not found something really wrong happened
		if(lCurrentDecimal.empty())
		{
			//TODO: proper error handling
			cerr << "Internal error occured for step." << std::endl;
			return;
		}
		theFunctionName = getCurrentFunctionName();
		if( aKind == STEP_OVER )
		{
			cerr << "Step Over." << std::endl;
			isSteppingOver = true;
			theDecimalSize = lCurrentDecimal.size();
			resume();
		} else if ( aKind == STEP_INTO ) {
			cerr << "Step Into." << std::endl;
			isSteppingInto = true;
			theDecimalSize = lCurrentDecimal.size()+1;
			resume();
		} else if ( aKind == STEP_OUT ) {
			cerr << "Step Out." << std::endl;
			isSteppingOut = true;
			lCurrentDecimal.pop();
			theDecimalSize = lCurrentDecimal.size()-1;
			theLastKnownStack = theStack;
			if(theLastKnownStack.size() > 0) theLastKnownStack.pop();
			resume();
		}
	}

	bool ZorbaDebugger::hasToStepOver() const
	{
		stack<unsigned int> lDecimal(getCurrentDecimal());
		string lFunctionName(getCurrentFunctionName());
		if(lDecimal.empty())
		{
			return false;
		}
		if(isSteppingOver && lDecimal.size() <= theDecimalSize &&
			theFunctionName == lFunctionName)
		{
			cerr << "theFunctionName: " << theFunctionName << endl;
			cerr << "lFunctionName: " << lFunctionName << endl;
			return true;
		}
		return false;
	}

	bool ZorbaDebugger::hasToStepInto() const
	{
		if(isSteppingInto) //&& lDecimal.size() == theDecimalSize)
		{
			return true;
		}
		return false;
	}

	bool ZorbaDebugger::hasToStepOut() const
	{
		stack<unsigned int> lDecimal(getCurrentDecimal());
		string lFunctionName(getCurrentFunctionName());
		if(lDecimal.empty())
		{
			return false;
		}

		if(isSteppingOut && (
			(lDecimal.size() <= theDecimalSize && theFunctionName == lFunctionName) ||
			(theLastKnownStack == theStack)
			)
			)
		{
			return true;
		}
		return false;
	}

	void ZorbaDebugger::stepOver()
	{
		isSteppingOver = false;
	}

	void ZorbaDebugger::stepInto()
	{
		isSteppingInto = false;
	}

	void ZorbaDebugger::stepOut()
	{
		isSteppingOut = false;
	}

	void ZorbaDebugger::eval( xqpString anExpr )
	{
		if ( theStatus != QUERY_IDLE && theStatus != QUERY_TERMINATED )
		{
			auto_ptr<EvaluatedEvent> lMsg;
			try {
				auto_ptr< CompilerCB > ccb(new CompilerCB(*thePlanState->theCompilerCB));
				auto_ptr< dynamic_context > dctx(new dynamic_context(thePlanState->dctx()));
				xqpString lExpr = anExpr.replace("&quot;", "\"", "");
				auto_ptr<PlanWrapperHolder> eval_plan = compileEvalPlan(theLocation, ccb.get(), dctx.get(), lExpr, *thePlanState);
				PlanWrapper* lIterator = eval_plan->get();
				assert(lIterator != 0);

				store::Item_t lItem;
				list< pair<xqpString, xqpString> > lValuesAndTypes;

				if (lIterator->isUpdating()) {
					if (lIterator->next(lItem))
					{
						if (!lItem->isPul())
							ZORBA_ERROR_DESC(XQP0019_INTERNAL_ERROR,
							"Query does not return a pending update list");

						std::set<zorba::store::Item*> validationNodes;
						QueryLoc loc;

						store::Item_t validationPul = GENV_ITEMFACTORY->createPendingUpdateList();
#ifndef ZORBA_NO_XMLSCHEMA
						//          validateAfterUpdate(validationNodes, validationPul, theStaticContext, loc);
#endif  
						validationPul->applyUpdates(validationNodes);
					}
				} else {
					error::ErrorManager lErrorManger;
					serializer lSerializer(&lErrorManger);
					lSerializer.set_parameter("omit-xml-declaration", "yes");

					while (lIterator->next(lItem)) {
						ostringstream os;
						lSerializer.serialize(lItem, os);
						xqpString lValue = os.str();
						xqpString lType( lItem->getType()->getStringValue() );
						lValuesAndTypes.push_back(pair<xqpString, xqpString>(lValue, lType));
					}
				}
				lMsg.reset(new EvaluatedEvent(anExpr, lValuesAndTypes));
			} catch ( error::ZorbaError& e) {
				stringstream lOutputStream;
				xqpString lDescription = e.theDescription.replace("\\\"", "", "");
				lOutputStream << "Error: " << error::ZorbaError::toString(e.theErrorCode) << " " << lDescription;
				lMsg.reset(new EvaluatedEvent( anExpr, lOutputStream.str() ));
			}
			assert(lMsg.get() != 0);
			m_debuggerCommunicator->sendEvent(lMsg.get());
		}
	}

	const QueryLoc ZorbaDebugger::addBreakpoint(const QueryLoc& aLocation)
	{
		xqpString fileName = aLocation.getFilename();
		fileName = debugger_helper_functions::deascapeString(fileName);
		unsigned long line = aLocation.getLineBegin();
		std::map<xqpString, std::vector<std::vector<std::pair<QueryLoc, FnDebugIterator*> > > >::iterator iter;
		iter = theBreaks.find(fileName);
		if (iter == theBreaks.end()) {
			return QueryLoc();
		} else if (iter->second.size() < line) {
			return QueryLoc();
		}
		while (iter->second[line].empty()) {
			if (++iter == theBreaks.end()) {
				return QueryLoc();
			}
		}
		std::vector<std::pair<QueryLoc, FnDebugIterator*> > vec = iter->second[line];
		vec[0].second->setBreakpoint();
		return vec[0].first;
	}

	auto_ptr<PlanWrapperHolder>
		ZorbaDebugger::compileEvalPlan(const QueryLoc& loc, CompilerCB* ccb, dynamic_context* dctx, const xqpString& anExpr, PlanState& planState)
	{
		auto_ptr<PlanWrapperHolder> eval_plan(new PlanWrapperHolder());

		checked_vector< string > var_keys;

		//set up eval state's ccb
		ccb->m_sctx_list.push_back( ccb->m_sctx = ccb->m_sctx->create_child_context() );
		ccb->m_debugger = 0;

		//set up import list
		xqpString lExpr;
		map<string, string>::iterator it;
		stringstream lImport;
		for(it=theImports.begin(); it!=theImports.end(); ++it)
		{
			if(it->first!="ns")
			{
				lImport << "import module namespace " << it->second << "=\"" << it->first << "\";" << endl;
			}
		}
		lExpr += lImport.str();
		lExpr += anExpr;
		eval_plan->reset(
			new PlanWrapper (
			EvalIterator::compile ( ccb, lExpr, theVarnames, theVartypes ),
			ccb,
			dctx,
			planState.theStackDepth + 1 )
			);
		eval_plan->get()->checkDepth( loc );

		for (unsigned i = 0; i < theChildren.size () - 1; i++)
		{
			//reset the plan iterator for multiple execution
			theChildren[i+1]->reset(*thePlanState);
			store::Iterator_t lIter = new PlanIteratorWrapper(theChildren[i+1], *thePlanState);
			// TODO: is saving an open iterator efficient?
			// Then again if we close theChildren [1] here,
			// we won't be able to re-open it later via the PlanIteratorWrapper
			dctx->add_variable(dynamic_context::var_key(ccb->m_sctx->lookup_var(theVarnames[i])), lIter);
		}
		return auto_ptr<PlanWrapperHolder>(eval_plan.release());
	}

	void ZorbaDebugger::processMessage(AbstractCommandMessage * aMessage)
	{
		switch( aMessage->getCommandSet() )
		{
		case EXECUTION:
			{
				switch( aMessage->getCommand() )
				{
				case RUN:
					{
#ifndef NDEBUG
						RunMessage * lMessage = dynamic_cast<RunMessage *> ( aMessage );
						assert( lMessage );
#endif
						run();
						break;
					}
				case SUSPEND:
					{
#ifndef NDEBUG
						SuspendMessage * lMessage = dynamic_cast<SuspendMessage *> ( aMessage );
						assert( lMessage );
#endif
						suspend();
						break;
					}
				case RESUME:
					{
#ifndef NDEBUG
						ResumeMessage * lMessage = dynamic_cast<ResumeMessage*> ( aMessage );
						assert( lMessage );
#endif
						resume();
						break;
					}
				case TERMINATE:
					{
#ifndef NDEBUG
						TerminateMessage * lMessage = dynamic_cast<TerminateMessage *> ( aMessage );
						assert( lMessage );
#endif
						terminate();
						break;
					}
				case STEP:
					{
#ifndef NDEBUG
						StepMessage* lMessage = dynamic_cast<StepMessage *> ( aMessage );
						assert( lMessage );
#else
						StepMessage* lMessage =  static_cast<StepMessage *> ( aMessage );
#endif
						step(lMessage->getStepKind());
						break;
					}
				default: throw InvalidCommandException("Internal Error. Command not implemented for execution command set .");
				}
				break;
		case BREAKPOINTS:
			{
				switch( aMessage->getCommand() )
				{
				case SET:
					{
						SetMessage * lMessage;
#ifndef NDEBUG
						lMessage = dynamic_cast< SetMessage * > ( aMessage );
						assert( lMessage );
#else
						lMessage =  static_cast< SetMessage * > ( aMessage );
#endif
						SetReply* lReply = new SetReply(lMessage->getId(), DEBUGGER_NO_ERROR);

						map<unsigned int, QueryLoc> locations = lMessage->getLocations();
						map<unsigned int, QueryLoc>::iterator it;
						for ( it = locations.begin(); it != locations.end(); it++ )
						{
							QueryLoc loc = addBreakpoint(it->second);
							theBreakpoints.insert( make_pair( it->first, loc ) ); 
							lReply->addBreakpoint(it->first, loc);
						}

						map<unsigned int, xqpString> exprs = lMessage->getExprs();
						map<unsigned int, xqpString>::iterator lIt;
						for ( lIt = exprs.begin(); lIt != exprs.end(); lIt++ )
						{
							theWatchpoints.insert( make_pair( lIt->first, lIt->second ) ); 
						}

						lMessage->setReplyMessage(lReply);
						break;
					}
				case CLEAR:
					{
						ClearMessage * lMessage;
#ifndef NDEBUG
						lMessage = dynamic_cast< ClearMessage * > ( aMessage );
						assert( lMessage );
#else
						lMessage =  static_cast< ClearMessage * > ( aMessage );
#endif
						vector<unsigned int>::iterator it;
						vector<unsigned int> ids = lMessage->getIds();
						for ( it = ids.begin(); it != ids.end(); it++ )
						{
							map<unsigned int, QueryLoc>::iterator
								lIter = theBreakpoints.find( *it );
							if ( lIter !=  theBreakpoints.end() )
							{
								theBreakpoints.erase( lIter );
							} else {
								map<unsigned int, xqpString>::iterator lIter2 =
									theWatchpoints.find( *it );
								if ( lIter2 != theWatchpoints.end() ) {
									theWatchpoints.erase( lIter2 );
								}
							}
						}
						break;
					}
				default: throw InvalidCommandException("Internal Error. Command not implemented for breakpoints command set.");
				}
			}
			break;
		case ENGINE_EVENT:
		case STATIC:
		case DYNAMIC:
			{
				switch ( aMessage->getCommand() )
				{
				case EVAL:
					{
						EvalMessage * lMessage;
#ifndef NDEBUG
						lMessage = dynamic_cast< EvalMessage * > ( aMessage );
						assert( lMessage );
#else
						lMessage = static_cast< EvalMessage * > ( aMessage );
#endif
						eval( lMessage->getExpr() );
						break;
					}
				case VARIABLES:
					{
						VariableMessage * lMessage;
#ifndef NDEBUG
						lMessage = dynamic_cast< VariableMessage * > ( aMessage );
#else
						lMessage = static_cast< VariableMessage * > ( aMessage );
#endif
						VariableReply * lReply = new VariableReply( lMessage->getId(), DEBUGGER_NO_ERROR );
						for( unsigned i = 0; i<theVarnames.size(); i++ )
						{
							xqpString lName(theVarnames.at(i)->getStringValue());
							xqpString lType;
							if( theVartypes.at(i) != 0 )
							{
								lType = theVartypes.at(i)->toString();
							} else {
								lType = "[XS_UNTYPED]";
							}
							checked_vector<global_binding>::iterator it;
							bool is_global = false;
							for ( it = theGlobals.begin(); it != theGlobals.end(); ++it )
							{
								if ( it->first->get_varname() == theVarnames.at(i) )
								{
									lReply->addGlobal( lName, lType );
									is_global = true;
									break;
								}
							}
							if ( ! is_global )
							{
								lReply->addLocal( lName, lType );
							}
						}
						lMessage->setReplyMessage( lReply );
						break;
					}
				case FRAME:
					{
						FrameMessage* lMessage;
#ifndef NDEBUG
						lMessage = dynamic_cast<FrameMessage*>(aMessage);
#else
						lMessage = static_cast<FrameMessage*>(aMessage);
#endif
						FrameReply* lReply = new FrameReply(lMessage->getId(), DEBUGGER_NO_ERROR, theStack);
						lMessage->setReplyMessage(lReply);
						break;
					}
				default: throw InvalidCommandException("Internal Error. Command not implemented for dynamic command set.");
				}
			}
			break;
		default:
			throw InvalidCommandException("Internal Error. CommandSet not implemented.");
			}
		}
	};

	void ZorbaDebugger::registerIterator( const QueryLoc& loc, FnDebugIterator* iter )
	{
		unsigned int lineNumber = loc.getLineBegin();
		xqpString uri = loc.getFilename();
		std::vector<std::vector<std::pair<QueryLoc,FnDebugIterator*> > >& vec = theBreaks[uri];
		if (vec.size() <= lineNumber) {
			vec.resize(lineNumber * 2);
		}
		vec[lineNumber].push_back(std::pair<QueryLoc, FnDebugIterator*>(loc, iter));
	}
}//end of namespace

