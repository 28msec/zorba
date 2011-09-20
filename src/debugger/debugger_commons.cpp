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

#include "debugger_commons.h"

#include "system/globalenv.h"

#include "compiler/api/compilercb.h"
#include "context/static_context.h"
#include "context/dynamic_context.h"
#include "diagnostics/assert.h"

#include "runtime/debug/debug_iterator.h"
#include "runtime/visitors/planiter_visitor.h"

#include "store/api/item_factory.h"

#include "zorbatypes/URI.h"

#include "types/typeimpl.h"

#include "zorba/util/uri.h"

namespace zorba {

// ****************************************************************************

SERIALIZABLE_CLASS_VERSIONS(Breakable)
END_SERIALIZABLE_CLASS_VERSIONS(Breakable)

void
Breakable::serialize(serialization::Archiver& ar)
{
  ar & theLocation;
  ar & theEnabled;
}

// ****************************************************************************

SERIALIZABLE_CLASS_VERSIONS(QueryLocComparator)
END_SERIALIZABLE_CLASS_VERSIONS(QueryLocComparator)

void
QueryLocComparator::serialize(serialization::Archiver& ar) {
}

bool
QueryLocComparator::operator()(const QueryLoc& a, const QueryLoc& b) const
{
  // check the file names
  // smaller has priority
  int c;
  if ((c = a.getFilename().compare(b.getFilename())) != 0) {
    return c < 0;
  }

  int ai, bi;

  // check line numbers
  // smaller has priority
  ai = a.getLineBegin();
  bi = b.getLineBegin();
  if (ai != bi) {
    return ai < bi;
  }

  // check column begin numbers
  // smaller has priority
  ai = a.getColumnBegin();
  bi = b.getColumnBegin();
  if (ai == 0 || bi == 0) {
    return false;
  }
  if (ai != bi) {
    return ai < bi;
  }

  // check line end numbers
  // larger has priority
  ai = a.getLineEnd();
  bi = b.getLineEnd();
  if (ai != bi) {
    return ai > bi;
  }

  // check column end numbers
  // larger has priority
  ai = a.getColumnEnd();
  bi = b.getColumnEnd();
  if (ai == 0 || bi == 0) {
    return false;
  }

  return a.getColumnEnd() > b.getColumnEnd();
}

// ****************************************************************************

SERIALIZABLE_CLASS_VERSIONS(DebuggerSingletonIterator)
END_SERIALIZABLE_CLASS_VERSIONS(DebuggerSingletonIterator)

DebuggerSingletonIterator::DebuggerSingletonIterator(
  static_context* sctx, QueryLoc loc, DebuggerCommons* lCommons)
  : NoaryBaseIterator<DebuggerSingletonIterator, PlanIteratorState>(sctx, loc),
    theCommons(lCommons)
{
}

void
DebuggerSingletonIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (NoaryBaseIterator<DebuggerSingletonIterator,PlanIteratorState>*)this);
  ar & theCommons;
}

NOARY_ACCEPT(DebuggerSingletonIterator);

bool
DebuggerSingletonIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState* state;
  DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );
  result = theCommons->getEvalItem();
  STACK_PUSH ( result != NULL, state );
  STACK_END (state);
}


// ****************************************************************************

SERIALIZABLE_CLASS_VERSIONS(DebuggerCommons)
END_SERIALIZABLE_CLASS_VERSIONS(DebuggerCommons)

DebuggerCommons::DebuggerCommons(static_context* sctx)
  : theBreak(false),
    theCause(0),
    theBreakCondition(0),
    theExecEval(false),
    theStepping(false)
    
{
  theRuntime = NULL;
  theCurrentStaticContext = NULL;
  theCurrentDynamicContext = NULL;
  thePlanState = NULL;
  theDebugIteratorState = NULL;
}

DebuggerCommons::~DebuggerCommons()
{
}

void
DebuggerCommons::serialize(::zorba::serialization::Archiver& ar)
{
  ar & theBreakables;
  ar & theBreakableIDs;
  ar & theStackTrace;
  ar & theUriFileMappingMap;

  if(ar.is_serializing_out())
    theRuntime = NULL;
  ar & theCurrentStaticContext;
  if(ar.is_serializing_out())
    theCurrentDynamicContext = NULL;

  ar & theBreak;
  ar & theCause;
  ar & theIteratorStack;
  ar & theBreakCondition;

  if(ar.is_serializing_out())
    thePlanState = NULL;
  if(ar.is_serializing_out())
    theDebugIteratorState = NULL;
  ar & theEvalItem;
  ar & theExecEval;
  ar & theStepping;
}


void
DebuggerCommons::setRuntime(DebuggerRuntime* aRuntime)
{
  theRuntime = aRuntime;
}

DebuggerRuntime*
DebuggerCommons::getRuntime()
{
  return theRuntime;
}

void
DebuggerCommons::setCurrentStaticContext(static_context* aStaticContext)
{
  theCurrentStaticContext = aStaticContext;
}

void
DebuggerCommons::setCurrentDynamicContext(dynamic_context* aDynamicContext)
{
 theCurrentDynamicContext = aDynamicContext;
}

dynamic_context*
DebuggerCommons::getCurrentDynamicContext() const
{
  return theCurrentDynamicContext;
}

static_context*
DebuggerCommons::getCurrentStaticContext() const
{
  return theCurrentStaticContext;
}

unsigned int
DebuggerCommons::addBreakpoint(const QueryLoc& aLocation, bool aEnabled)
{
  BreakableIdMap::iterator lIter = theBreakableIDs.find(aLocation);

  if (lIter == theBreakableIDs.end()) {
    std::stringstream lSs;
    lSs << "The breakpoint could not be set at line " << aLocation.getLineBegin()
      << " in file: " << aLocation.getFilename();
    throw lSs.str();
  }
  unsigned int lId = lIter->second;
  theBreakables[lId].setSet(true);
  theBreakables[lId].setEnabled(aEnabled);
  return lId;
}

Breakable
DebuggerCommons::getBreakpoint(unsigned int aId)
{
  checkBreakpoint(aId);
  return theBreakables[aId];
}

void
DebuggerCommons::checkBreakpoint(unsigned int aId)
{
  if (aId >= theBreakables.size() || !theBreakables[aId].isSet()) {
    std::stringstream lSs;
    lSs << "No such breakpoint: " << aId;
    throw lSs.str();
  }
}

void
DebuggerCommons::updateBreakpoint(
  unsigned int aId,
  bool aEnabled)
{
  checkBreakpoint(aId);
  theBreakables[aId].setEnabled(aEnabled);
}

void
DebuggerCommons::updateBreakpoint(
  unsigned int aId,
  bool aEnabled,
  std::string aCondition,
  unsigned int aHitValue)
{
  checkBreakpoint(aId);
  theBreakables[aId].setEnabled(aEnabled);
  // TODO: set condition
}

void
DebuggerCommons::removeBreakpoint(unsigned int aId)
{
  checkBreakpoint(aId);
  theBreakables[aId].setSet(false);
}

bool
DebuggerCommons::canBreak()
{
  return !theExecEval;
}

bool
DebuggerCommons::mustBreak(SuspensionCause& aCause)
{
  if (theBreak) {
    aCause = CAUSE_STEP;
    return true;
  } else if (theStepping) {
    std::size_t lSize = theIteratorStack.size();

    // either we meet the step condition
    if (lSize <= theBreakCondition) {
      // reset the break conditions
      theBreakCondition = 0;
      theStepping = false;
      return true;
    }
    // or we have stepped over from a function declaration breakpoint
    // we have for sure at least the following stack of debug iterators:
    // MainModule DI -> FunctionCall DI -> FunctionDecl DI -> current DI
    if (lSize > 3 && lSize == theBreakCondition + 1 && theIteratorStack.at(lSize - 2)->getDebuggerParent() == NULL) {
      // reset the break conditions
      theBreakCondition = 0;
      theStepping = false;
      return true;
    }
    // or we have stepped over and we reached another variable declaration
    // TODO: still to check and stop only at declarations on the same level
    if (lSize <= theBreakCondition && theIteratorStack.back()->isVarDeclaration()) {
      // reset the break conditions
      theBreakCondition = 0;
      theStepping = false;
      return true;
    }
  }

  return false;
}

bool
DebuggerCommons::hasToBreakAt(QueryLoc aLocation)
{
  adjustLocationFilePath(aLocation);

  BreakableIdMap::const_iterator lIter = theBreakableIDs.find(aLocation);
  if (lIter == theBreakableIDs.end()) {
    return false;
  }

  Breakable lBreakable = theBreakables[lIter->second];
  return lBreakable.isSet() && lBreakable.isEnabled();
}

bool
DebuggerCommons::hasToBreakAt(const DebugIterator* aIter)
{
  return false;
}

void
DebuggerCommons::setBreak(bool lBreak, SuspensionCause aCause)
{
#ifndef NDEBUG
  //Check preconditions
  ZORBA_ASSERT(lBreak ? aCause != 0 : true);
#endif // NDEBUG
  theBreak = lBreak;
  theCause = aCause;
#ifndef NDEBUG
  // Check post conditions
  ZORBA_ASSERT(theBreak == lBreak);
  ZORBA_ASSERT(theCause == aCause);
#endif //NDEBUG
}

void
DebuggerCommons::setCurrentIterator(const DebugIterator* aIterator)
{
  // don't modify the iterator stack during expression evaluation
  if (theExecEval) {
    return;
  }

  const DebugIterator* lParent = aIterator->getDebuggerParent();

  // when the stack is empty (main module debug iterator) or
  // when the parent is NULL but not a variable declaration (function declaration iterator) or
  // when the parent is the last in the stack
  if (theIteratorStack.empty() ||
      (lParent == NULL && !aIterator->isVarDeclaration()) ||
      theIteratorStack.back() == lParent) {
    theIteratorStack.push_back((DebugIterator*)aIterator);
    return;
  }

  // avoid multiple calls to this function
  // recursive functions always insert at least 2 iterators
  if (theIteratorStack.back() == aIterator) {
    return;
  }

  // now we remove the iterators from the stack until we find the parent
  theIteratorStack.pop_back();
  while (!theIteratorStack.empty()) {
    if (theIteratorStack.back() == aIterator->getDebuggerParent()) {
      theIteratorStack.push_back((DebugIterator*)aIterator);
      return;
    }
    theIteratorStack.pop_back();
  }

  // noe the stack is empty, so push this iterator in the stack
  theIteratorStack.push_back((DebugIterator*)aIterator);
}

const DebugIterator*
DebuggerCommons::getCurrentIterator() const
{
  if (theIteratorStack.empty()) {
    return NULL;
  }
  return theIteratorStack.back();
}

void
DebuggerCommons::makeStepOver()
{
  theStepping = true;
  if (!theIteratorStack.empty()) {
    theBreakCondition = theIteratorStack.size();
  } else {
    theBreakCondition = 0;
  }
}

void DebuggerCommons::makeStepOut()
{
  theStepping = true;
  if (!theIteratorStack.empty()) {
    theBreakCondition = theIteratorStack.size() - 1;
  } else {
    theBreakCondition = 0;
  }
}

void
DebuggerCommons::setPlanState(PlanState* aPlanState)
{
  thePlanState = aPlanState;
  //Check postconditions
  ZORBA_ASSERT(thePlanState == aPlanState);
}

void
DebuggerCommons::setDebugIteratorState(DebugIteratorState* aState)
{
  theDebugIteratorState = aState;
  //Check postconditions
  ZORBA_ASSERT(theDebugIteratorState == aState);
}

std::list<std::pair<zstring, zstring> >
DebuggerCommons::eval(const zstring& aExpr, Zorba_SerializerOptions& aSerOpts)
{
  theExecEval = true;
  zstring lStore = aExpr;
  GlobalEnvironment::getInstance().getItemFactory()->createString(theEvalItem,
                                                                  lStore);
  std::list<std::pair<zstring, zstring> > lRes;
  try {
    lRes = theIteratorStack.back()->eval(thePlanState, &aSerOpts);
    theExecEval = false;
  } catch (...) {
    theExecEval = false;
    throw;
  }

  return lRes;
}

store::Item_t
DebuggerCommons::getEvalItem()
{
  return theEvalItem;
}

void
DebuggerCommons::addModuleUriMapping(std::string aUri, std::string aFileUri)
{
  ZORBA_ASSERT(theUriFileMappingMap.find(aUri) == theUriFileMappingMap.end());
  theUriFileMappingMap.insert(
    std::pair<std::string, std::string>(aUri, aFileUri));
  ZORBA_ASSERT(theUriFileMappingMap.find(aUri) != theUriFileMappingMap.end());
}

std::string
DebuggerCommons::getFilepathOfURI(const std::string& aUri) const
{
  std::map<std::string, std::string>::const_iterator lIter;
  lIter = theUriFileMappingMap.find(aUri);
  zstring lString;
  if (lIter == theUriFileMappingMap.end())
  {
    lString = aUri;
  }
  else
  {
    lString = lIter->second;
  }
  zstring lRes;
  URI::decode_file_URI(lString, lRes);
  return lRes.str();
}

void
DebuggerCommons::addBreakable(Breakable& aBreakable)
{
  adjustLocationFilePath(aBreakable.getLocation());

  unsigned int lId = theBreakables.size();
  theBreakables.push_back(aBreakable);
  theBreakableIDs[aBreakable.getLocation()] = lId;
}

void
DebuggerCommons::pushStackFrame(QueryLoc aLocation, std::string& aFunctionName)
{
  theStackTrace.push_back(std::pair<QueryLoc, std::string>(aLocation, aFunctionName));
}

void
DebuggerCommons::popStackFrame()
{
  theStackTrace.pop_back();
}

std::vector<std::pair<QueryLoc, std::string> >
DebuggerCommons::getStackFrames() const
{
  return theStackTrace;
}

void
DebuggerCommons::adjustLocationFilePath(QueryLoc& aLocation)
{
  if (aLocation.getFilename().substr(0, 7) == "file://") {
    // adjust the file paths by removing the schema and encoding
    zstring lOldFilename(aLocation.getFilename());
    const String lNewFilename = URIHelper::decodeFileURI(lOldFilename.str());
    aLocation.setFilename(lNewFilename.str());
  }
}

} // namespace zorba
