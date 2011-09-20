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

#include "stdafx.h"

#include "debugger_runtime.h"

#include <memory>
#include <vector>
#include <sstream>
#include <fstream>

#include <zorba/util/uri.h>

#include "store/api/store.h"

#include "api/zorbaimpl.h"
#include "api/xqueryimpl.h"
#include "api/serializerimpl.h"

#include "context/static_context.h"
#include "compiler/expression/var_expr.h"

#include "runtime/api/plan_wrapper.h"
#include "runtime/debug/debug_iterator.h"
#include "runtime/util/flowctl_exception.h"

#include "zorba/diagnostic_handler.h"
#include "diagnostics/xquery_diagnostics.h"
#include "zorbautils/synchronous_logger.h"

#include "debugger/debugger_protocol.h"
#include "debugger/debugger_communicator.h"
#include "debugger/debugger_commons.h"

#ifdef WIN32
#include <windows.h>
#define sleep(s) Sleep(s*1000)
#endif

namespace zorba {

DebuggerRuntime::DebuggerRuntime(
  XQueryImpl* xqueryImpl,
  std::ostream& oStream,
  Zorba_SerializerOptions& serializerOptions,
  DebuggerCommunicator* communicator,
  itemHandler aHandler,
  void* aCallBackData)
  : theQuery(xqueryImpl),
    theOStream(oStream),
    theSerializerOptions(serializerOptions),
    theCommunicator(communicator),
    theWrapper(theQuery->generateWrapper()),
    theExecStatus(QUERY_IDLE),
    theNotSendTerminateEvent(false),
    thePlanIsOpen(false),
    theSerializer(0),
    theItemHandler(aHandler),
    theCallbackData(aCallBackData)
{
}

DebuggerRuntime::~DebuggerRuntime()
{
  delete theSerializer;
}

// this is the main loop of the thread
// the runtime thread terminates if this method finishes
void
DebuggerRuntime::run()
{
  theWrapper->open();
  thePlanIsOpen = true;
  runQuery();
}

void
DebuggerRuntime::finish()
{
  if (thePlanIsOpen) {
    theWrapper->close();
  }
  terminateRuntime();
}


void
DebuggerRuntime::resetRuntime()
{
  theWrapper = theQuery->generateWrapper();
  thePlanIsOpen = false;
  theExecStatus = QUERY_IDLE;
  theNotSendTerminateEvent = false;
  reset();
}


ExecutionStatus
DebuggerRuntime::getExecutionStatus() const
{
  AutoLock lLock(theLock, Lock::READ);
  return theExecStatus;
}


void
DebuggerRuntime::runQuery()
{
  theLock.wlock();
  theExecStatus = theExecStatus == QUERY_SUSPENDED ? QUERY_RESUMED : QUERY_RUNNING;

  try {
    DebuggerCommons* lCommons = getDebbugerCommons();
    lCommons->setRuntime(this);

    theLock.unlock();

    delete theSerializer;
    theSerializer = new serializer(theQuery->theXQueryDiagnostics);
    SerializerImpl::setSerializationParameters(
      *theSerializer, theSerializerOptions);
    if (theItemHandler) {
      theSerializer->serialize(theWrapper.getp(), theOStream,
        theItemHandler, theCallbackData);
    } else {
      theSerializer->serialize(theWrapper.getp(), theOStream);
    }
    
    theOStream.flush();
  } catch (FlowCtlException&) {
    // Runtime correctly terminated by user interrupt
  } catch (ZorbaException const& e){
    // this does not rethrow but only print the error message
    ZorbaImpl::notifyError(theQuery->theDiagnosticHandler, e);
  }
  theLock.wlock();
  theExecStatus = QUERY_TERMINATED;
  theLock.unlock();
}


void
DebuggerRuntime::setQueryRunning()
{
  AutoLock lLock(theLock, Lock::WRITE);
  assert(theExecStatus == QUERY_RESUMED);
  theExecStatus = QUERY_RUNNING;
}

// ****************************************************************************
// Breakpoints

unsigned int
DebuggerRuntime::addBreakpoint(const QueryLoc& aLocation, bool aEnabled)
{
  AutoLock lLock(theLock, Lock::WRITE);
  DebuggerCommons* lCommons = getDebbugerCommons();
  return lCommons->addBreakpoint(aLocation, aEnabled);
}

Breakable
DebuggerRuntime::getBreakpoint(unsigned int aId)
{
  AutoLock lLock(theLock, Lock::WRITE);
  DebuggerCommons* lCommons = getDebbugerCommons();
  return lCommons->getBreakpoint(aId);
}

void
DebuggerRuntime::updateBreakpoint(
  unsigned int aId,
  bool aEnabled,
  std::string aCondition,
  unsigned int aHitValue)
{
  AutoLock lLock(theLock, Lock::WRITE);

  DebuggerCommons* lCommons = getDebbugerCommons();

  if (aCondition == "") {
    lCommons->updateBreakpoint(aId, aEnabled);
  } else {
    lCommons->updateBreakpoint(aId, aEnabled, aCondition, aHitValue);
  }
}

void
DebuggerRuntime::removeBreakpoint(unsigned int aId)
{
  AutoLock lLock(theLock, Lock::WRITE);
  DebuggerCommons* lCommons = getDebbugerCommons();
  lCommons->removeBreakpoint(aId);
}

// ****************************************************************************
// Stack frames

unsigned int
DebuggerRuntime::getStackDepth()
{
  return theWrapper->thePlanState->theStackDepth;
}

std::vector<StackFrameImpl>
DebuggerRuntime::getStackFrames()
{
  std::vector<StackFrameImpl> lFrames;

  DebuggerCommons* lCommons = getDebbugerCommons();
  std::vector<std::pair<QueryLoc, std::string> > lRawFrames = lCommons->getStackFrames();

  QueryLoc lLocation;
  std::string lSignature("query body");

  // add the frames for each function call
  for (std::size_t i = 0 ; i < lRawFrames.size(); i++) {
    lLocation = lRawFrames.at(i).first;

    StackFrameImpl lFrame(lSignature, lLocation);
    lFrames.push_back(lFrame);

    lSignature = lRawFrames.at(i).second;
  }

  // add the top most frame from the current iterator
  const DebugIterator* lIterator = lCommons->getCurrentIterator();
  lLocation = lIterator->loc;
  StackFrameImpl lFrame(lSignature, lLocation);
  lFrames.push_back(lFrame);

  return lFrames;
}

// ****************************************************************************
// Other

void
DebuggerRuntime::suspendRuntime(QueryLoc aLocation, SuspensionCause aCause)
{
  theLock.wlock();
  theExecStatus = QUERY_SUSPENDED;

  std::stringstream lResponse;
  lResponse << "<response command=\"" << "" << "\" transaction_id=\"" << theLastContinuationTransactionID << "\" ";
  lResponse << "reason=\"ok\" status=\"break\" ";
  lResponse << "/>";
  theCommunicator->send(lResponse.str());

  theLock.unlock();
  suspend();
}


void
DebuggerRuntime::resumeRuntime()
{
  AutoLock lLock(theLock, Lock::WRITE);
  theExecStatus = QUERY_RUNNING;
  resume();
}


void
DebuggerRuntime::terminateRuntime()
{
  AutoLock lLock(theLock, Lock::WRITE);
  theExecStatus = QUERY_TERMINATED;

  std::stringstream lResult;
  lResult << "<response command=\"stop\" "
    << "status=\"stopping\" "
    << "reason=\"ok\" "
    << "transaction_id=\"" << theLastContinuationTransactionID << "\">"
    << "</response>";
  theCommunicator->send(lResult.str());
  // TODO: something more here?
}


void
DebuggerRuntime::detachRuntime()
{
  AutoLock lLock(theLock, Lock::WRITE);
  theExecStatus = QUERY_DETACHED; 
  // TODO: something more here?
}


std::vector<std::pair<std::string, std::string> >
DebuggerRuntime::getVariables(bool aLocals)
{
  DebuggerCommons* lCommons = getDebbugerCommons();
  static_context* lContext = lCommons->getCurrentStaticContext();

  // get all visible variables and filter below
  std::vector<var_expr_t> lVars;
  lContext->getVariables(lVars, false);

  std::vector<std::pair<std::string, std::string> > lVarList;
  std::vector<var_expr_t>::iterator lIte = lVars.begin();
  std::vector<var_expr_t>::iterator lEnd = lVars.end();

  for (; lIte != lEnd; ++lIte) {
    // non-global to locals and globals to globals
    if ((aLocals && (*lIte)->get_kind() == var_expr::prolog_var) ||
        (!aLocals && (*lIte)->get_kind() != var_expr::prolog_var)) {
      continue;
    }

    std::stringstream lTypeSs;
    std::stringstream lNameSs;


    // read the name ****************************
    store::Item* lNameItem = (*lIte)->get_name();
    zstring lLocalName = lNameItem->getLocalName();

    // correct the name of the context item
    if (!aLocals && lLocalName == "$$dot") {
      lVarList.push_back(std::pair<std::string, std::string>(".", "item()*"));
      continue;
    }

    bool lHasNS = ! lNameItem->getNamespace().empty();

    // if there is a namespace, append the local name as well
    if (lHasNS) {
      lNameSs << lNameItem->getPrefix().str() << ":";
    }
    lNameSs << lNameItem->getLocalName().str();

    // if there is a namespace, append the namespace URI
    if (lHasNS) {
      lNameSs << "\\" << lNameItem->getNamespace().str();
    }


    // read the type ****************************
    xqtref_t lType = (*lIte)->get_type();

    if (lType == NULL || lType->get_qname() == NULL) {
      lTypeSs << "item()*";
    } else {
      TypeConstants::quantifier_t lQuantifier = lType->get_quantifier();
      store::Item_t lQname = (*lIte)->get_type()->get_qname();
      lTypeSs << lQname->getPrefix().str()
            << ":"
            << lQname->getLocalName().str();
      switch (lQuantifier) {
      case TypeConstants::QUANT_QUESTION:
        lTypeSs << "?";
        break;
      case TypeConstants::QUANT_STAR:
        lTypeSs << "*";
        break;
      case TypeConstants::QUANT_PLUS:
        lTypeSs << "+";
        break;
      case TypeConstants::QUANT_ONE:
      case TypeConstants::QUANTIFIER_LIST_SIZE:
        break;
      }

      // TODO: support namespaces
      //lTypeSs << " " << lQname->getNamespace().str();
    }


    // add a new result
    lVarList.push_back(
      std::pair<std::string, std::string>(lNameSs.str(), lTypeSs.str())
    );
  }

  return lVarList;
}


void
DebuggerRuntime::step(StepCommand aStepType)
{
  DebuggerCommons* lCommons = theWrapper->thePlanState->theDebuggerCommons;

  switch (aStepType)
  {
  case STEP_INTO:
    // Resume and then suspend as soon as the next iterator is reached.
    lCommons->setBreak(true, CAUSE_STEP);
    resumeRuntime();
    break;
  case STEP_OUT:
    lCommons->makeStepOut();
    resumeRuntime();
    break;
  case STEP_OVER:
    lCommons->makeStepOver();
    resumeRuntime();
    break;
  }
}


void
DebuggerRuntime::setNotSendTerminateEvent()
{
  theNotSendTerminateEvent = true;
}


std::list<std::pair<zstring, zstring> >
DebuggerRuntime::eval(zstring& aExpr)
{
  // disable the xml declaration for evals/variables
  Zorba_omit_xml_declaration_t lOldOpt = theSerializerOptions.omit_xml_declaration;
  theSerializerOptions.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;
  DebuggerCommons* lCommons = getDebbugerCommons();
  std::list<std::pair<zstring, zstring> > lResults;

  try {
    lResults = lCommons->eval(aExpr, theSerializerOptions);
  } catch (...) {
    // restore the initial omit xml declaration option
    theSerializerOptions.omit_xml_declaration = lOldOpt;
    throw;
  }

  // restore the initial omit xml declaration option
  theSerializerOptions.omit_xml_declaration = lOldOpt;
  return lResults;
}


std::string
DebuggerRuntime::listSource()
{
  //ZORBA_ASSERT(dynamic_cast<ListCommand*>(theCurrentMessage));
  //ListCommand* lCommand = dynamic_cast<ListCommand*>(theCurrentMessage);
  //std::string lFile;
  //lFile = theWrapper->thePlanState->theDebuggerCommons->getFilepathOfURI(
  //  lCommand->getFilename());

  //std::string lCurrLine;
  ////std::string::iterator lSIter;
  ////for (lSIter = lFile.begin(); lSIter != lFile.end(); ++lSIter) {
  ////  if (*lSIter == '\\' && *(lSIter+1) == '\\') {
  ////    lFile.erase(lSIter);
  ////    ++lSIter;
  ////  }
  ////}
  //std::ifstream lStream(lFile.c_str());
  //for (unsigned long i = 1; i < lCommand->getFirstline() && lStream.good(); ++i)
  //{
  //  std::getline(lStream, lCurrLine);
  //}
  //std::stringstream lOut;
  //for (unsigned long i = lCommand->getFirstline();
  //  i <= lCommand->getLastline() && lStream.good(); ++i) {
  //  std::getline(lStream, lCurrLine);
  //  lOut << lCurrLine;
  //  if (lStream.good()) {
  //    lOut << std::endl;
  //  }
  //}
  //return new ListReply(
  //  theCurrentMessage->getId(), DEBUGGER_NO_ERROR, lOut.str());

  return "";
}


void
DebuggerRuntime::setTheLastContinuationTransactionID(int aTID)
{
  theLastContinuationTransactionID = aTID;
}


int
DebuggerRuntime::getTheLastContinuationTransactionID()
{
  return theLastContinuationTransactionID;
}

// ****************************************************************************
// Private functions

DebuggerCommons* 
DebuggerRuntime::getDebbugerCommons()
{
  return theWrapper->thePlanState->theDebuggerCommons;
}

} // namespace zorba
