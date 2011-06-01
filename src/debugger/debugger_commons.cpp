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
  int c;
  if ((c = a.getFilename().compare(b.getFilename())) != 0) {
    return c < 0;
  }

  if (a.getLineBegin() == 0 || b.getLineBegin() == 0) {
    return false;
  }

  return a.getLineBegin() < b.getLineBegin();
}

// ****************************************************************************

SERIALIZABLE_CLASS_VERSIONS(DebuggerSingletonIterator)
END_SERIALIZABLE_CLASS_VERSIONS(DebuggerSingletonIterator)

DebuggerSingletonIterator::DebuggerSingletonIterator(
  static_context* sctx, QueryLoc loc, DebuggerCommons* lCommons) :
NoaryBaseIterator<DebuggerSingletonIterator, PlanIteratorState>(sctx, loc),
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
    theExecEval(false)
{
  theRuntime = NULL;
  theCurrentStaticContext = NULL;
  theCurrentDynamicContext = NULL;
  theCurrentIterator = NULL;
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
  ar & theUriFileMappingMap;
  if(ar.is_serializing_out())
    theRuntime = NULL;
  ar & theCurrentStaticContext;
  if(ar.is_serializing_out())
    theCurrentDynamicContext = NULL;
  ar & theBreak;
  ar & theCause;
  ar & theCurrentIterator;
  ar & theBreakIterators;
  if(ar.is_serializing_out())
    thePlanState = NULL;
  if(ar.is_serializing_out())
    theDebugIteratorState = NULL;
  ar & theEvalItem;
  ar & theExecEval;
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

//bool
//DebuggerCommons::addBreakpoint(DebugLocation_t& aLocation, unsigned int aId)
//{
//  bool lResult = false;
//
//  // First we check, if the filename is a module namespace
//  std::map<std::string, std::string>::iterator lMapIter;
//  lMapIter = theUriFileMappingMap.find(aLocation.theFileName);
//  if (lMapIter != theUriFileMappingMap.end()) {
//    aLocation.theFileName = lMapIter->second;
//  }
//
//  std::map<DebugLocation_t, bool, DebugLocation>::iterator lIter;
//  lIter = theLocationMap.find(aLocation);
//  // if the location could not be found, try it again with the encoded file uri.
//  if (lIter == theLocationMap.end()) {
//    zstring filename = aLocation.theFileName;
//    zstring url;
//    URI::encode_file_URI(filename, url);
//    aLocation.theFileName = url.str();
//    lIter = theLocationMap.find(aLocation);
//    aLocation.theFileName = filename.str();
//  }
//  if (lIter != theLocationMap.end()) {
//    aLocation.theQueryLocation = lIter->first.theQueryLocation;
//    lIter->second = true;
//    lResult = true;
//  }
//  // If the location could not be found, we iterate over all locations and try
//  // to find a location with a filename with a matching substring
//  for (lIter = theLocationMap.begin(); !lResult && lIter != theLocationMap.end();
//    lIter++) {
//    if (lIter->first.theFileName.find(aLocation.theFileName) !=
//      std::string::npos && aLocation.theLineNumber ==
//      lIter->first.theLineNumber) {
//        lIter->second = true;
//        aLocation.theQueryLocation = lIter->first.theQueryLocation;
//        lResult = true;
//    }
//  }
//  //otherwise, there could not be found a breakable expression
//  if (lResult) {
//    theBreakpoints.insert(
//      std::pair<unsigned int, DebugLocation_t>(aId, aLocation));
//  }
//  return lResult;
//}

bool
DebuggerCommons::hasToBreakAt(const QueryLoc& aLocation) const
{
  if (theExecEval) {
    return false;
  }

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
  //Preconditions
  ZORBA_ASSERT(aIter != NULL);

  if (theExecEval) {
    return false;
  }

  std::list</*const */DebugIterator*>::iterator lIter;
  for (lIter = theBreakIterators.begin();
    lIter != theBreakIterators.end();
    lIter++) {
      if (*lIter == aIter) {
        theBreakIterators.erase(lIter);
        return true;
      }
  }
  return false;
}

bool
DebuggerCommons::hasToBreak(SuspensionCause* aCause) const
{
  //This is not a precondition, because the client does not hava another
  //way to check it, then calling this function. But if theCause is 0, this
  // is clearly a bug.
  ZORBA_ASSERT(theBreak ? theCause != 0 : true);

  // Check preconditions
  ZORBA_ASSERT(*aCause == 0);

  if (theExecEval) {
    return false;
  }

  *aCause = theCause;

  // Check postconditions
  ZORBA_ASSERT(theCause == *aCause);

  return theBreak;
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
  theCurrentIterator = (DebugIterator*)aIterator;
  //Test postconditions
  ZORBA_ASSERT(aIterator == theCurrentIterator);
}

const DebugIterator*
DebuggerCommons::getCurrentIterator() const
{
  return theCurrentIterator;
}

void DebuggerCommons::makeStepOut()
{
  /*const */DebugIterator* lIter = (DebugIterator*)theCurrentIterator->getParent();
  if (lIter != NULL) {
    theBreakIterators.push_back(lIter);
  }
}

void
DebuggerCommons::makeStepOver()
{
  //Preconditions
  ZORBA_ASSERT(theCurrentIterator != NULL);

  /*const*/ DebugIterator* lIter = (DebugIterator*)theCurrentIterator->getOverIterator();
  if (lIter != NULL) {
    theBreakIterators.push_back(lIter);
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
  std::list<std::pair<zstring, zstring> > lRes =
    theCurrentIterator->eval(thePlanState, &aSerOpts);

  theExecEval = false;
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
DebuggerCommons::addBreakable(Breakable aBreakable)
{
  unsigned int lId = theBreakables.size();
  theBreakables.push_back(aBreakable);
  theBreakableIDs[aBreakable.getLocation()] = lId;
}

} // namespace zorba
