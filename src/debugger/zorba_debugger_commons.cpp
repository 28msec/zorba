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

#include "system/globalenv.h"

#include "zorba_debugger_commons.h"

#include "compiler/api/compilercb.h"
#include "context/dynamic_context.h"
#include "zorbaerrors/Assert.h"

#include "runtime/debug/zorba_debug_iterator.h"
#include "runtime/visitors/planiter_visitor.h"

#include "store/api/item_factory.h"

#include "zorbatypes/URI.h"

#include "types/typeimpl.h"

namespace zorba {

ZorbaDebuggerCommons::ZorbaDebuggerCommons(static_context* sctx)
:
theBreak(false),
theCause(0),
theExecEval(false)
{
}

ZorbaDebuggerCommons::~ZorbaDebuggerCommons()
{
}

void ZorbaDebuggerCommons::setRuntime( ZorbaDebuggerRuntime* aRuntime )
{
  theRuntime = aRuntime;
}

ZorbaDebuggerRuntime* ZorbaDebuggerCommons::getRuntime()
{
  return theRuntime;
}

void ZorbaDebuggerCommons::setCurrentStaticContext( static_context* aStaticContext )
{
  theCurrentStaticContext = aStaticContext;
}

void ZorbaDebuggerCommons::setCurrentDynamicContext( dynamic_context* aDynamicContext )
{
 theCurrentDynamicContext = aDynamicContext;
}

dynamic_context* ZorbaDebuggerCommons::getCurrentDynamicContext() const
{
  return theCurrentDynamicContext;
}

static_context* ZorbaDebuggerCommons::getCurrentStaticContext() const
{
  return theCurrentStaticContext;
}

bool ZorbaDebuggerCommons::addBreakpoint(DebugLocation_t& aLocation,
                                         unsigned int aId)
{
  bool lResult = false;
  // First we check, if the filename is a module namespace
  std::map<std::string, std::string>::iterator lMapIter;
  lMapIter = theUriFileMappingMap.find(aLocation.theFileName);
  if (lMapIter != theUriFileMappingMap.end()) {
    aLocation.theFileName = lMapIter->second;
  }

  std::map<DebugLocation_t, bool, DebugLocation>::iterator lIter;
  lIter = theLocationMap.find(aLocation);
  // if the location could not be found, try it again with the encoded file uri.
  if (lIter == theLocationMap.end()) {
    xqpStringStore_t filename = new xqpStringStore(aLocation.theFileName);
    xqpStringStore_t url;
    URI::encode_file_URI(filename, url);
    aLocation.theFileName = url->str();
    lIter = theLocationMap.find(aLocation);
    aLocation.theFileName = filename->str();
  }
  if (lIter != theLocationMap.end()) {
    aLocation.theQueryLocation = lIter->first.theQueryLocation;
    lIter->second = true;
    lResult = true;
  }
  // If the location could not be found, we iterate over all locations and try
  // to find a location with a filename with a matching substring
  for (lIter = theLocationMap.begin(); !lResult && lIter != theLocationMap.end();
    lIter++) {
    if (lIter->first.theFileName.find(aLocation.theFileName) !=
      std::string::npos && aLocation.theLineNumber ==
      lIter->first.theLineNumber) {
        lIter->second = true;
        aLocation.theQueryLocation = lIter->first.theQueryLocation;
        lResult = true;
    }
  }
  //otherwise, there could not be found a breakable expression
  if (lResult) {
    theBreakpoints.insert(
      std::pair<unsigned int, DebugLocation_t>(aId, aLocation));
  }
  return lResult;
}

bool ZorbaDebuggerCommons::hasToBreakAt( const QueryLoc& aLocation ) const
{
  if (theExecEval) {
    return false;
  }
  DebugLocation_t lLocation;
  lLocation.theFileName = aLocation.getFilename();
  lLocation.theLineNumber = aLocation.getLineno();
  lLocation.theQueryLocation = aLocation;
  std::map<DebugLocation_t, bool, DebugLocation>::const_iterator lIter;
  lIter = theLocationMap.find(lLocation);
  if (lIter->second) {
    return true;
  }
  return false;
}

bool ZorbaDebuggerCommons::hasToBreakAt(const ZorbaDebugIterator* aIter)
{
  //Preconditions
  ZORBA_ASSERT(aIter != NULL);

  if (theExecEval) {
    return false;
  }

  std::list<const ZorbaDebugIterator*>::iterator lIter;
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

bool ZorbaDebuggerCommons::hasToBreak(SuspensionCause* aCause) const
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

void ZorbaDebuggerCommons::setBreak( bool lBreak, SuspensionCause aCause )
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

void ZorbaDebuggerCommons::setCurrentIterator( const ZorbaDebugIterator* aIterator )
{
  theCurrentIterator = aIterator;
  //Test postconditions
  ZORBA_ASSERT(aIterator == theCurrentIterator);
}

const ZorbaDebugIterator* ZorbaDebuggerCommons::getCurrentIterator() const
{
  return theCurrentIterator;
}

void ZorbaDebuggerCommons::makeStepOut()
{
  const ZorbaDebugIterator* lIter = theCurrentIterator->getParent();
  if (lIter != NULL) {
    theBreakIterators.push_back(lIter);
  }
}

void ZorbaDebuggerCommons::makeStepOver()
{
  //Preconditions
  ZORBA_ASSERT(theCurrentIterator != NULL);

  const ZorbaDebugIterator* lIter = theCurrentIterator->getOverIterator();
  if (lIter != NULL) {
    theBreakIterators.push_back(lIter);
  }
}

void ZorbaDebuggerCommons::setPlanState( PlanState* aPlanState )
{
  thePlanState = aPlanState;
  //Check postconditions
  ZORBA_ASSERT(thePlanState == aPlanState);
}

void ZorbaDebuggerCommons::setDebugIteratorState( ZorbaDebugIteratorState* aState )
{
  theDebugIteratorState = aState;
  //Check postconditions
  ZORBA_ASSERT(theDebugIteratorState == aState);
}

std::list<std::pair<xqpString, xqpString> > 
ZorbaDebuggerCommons::eval(const xqpString& aExpr,
                           Zorba_SerializerOptions& aSerOpts)
{
  theExecEval = true;
  xqpStringStore_t lStore = aExpr.getStore();
  GlobalEnvironment::getInstance().getItemFactory()->createString(theEvalItem,
    lStore);
  std::list<std::pair<xqpString, xqpString> > lRes =
    theCurrentIterator->eval(thePlanState, &aSerOpts);
  theExecEval = false;
  return lRes;
}

store::Item_t* ZorbaDebuggerCommons::getEvalItem()
{
  return &theEvalItem;
}

void ZorbaDebuggerCommons::addModuleUriMapping( std::string aUri, 
                                                      std::string aFileUri )
{
  ZORBA_ASSERT(theUriFileMappingMap.find(aUri) == theUriFileMappingMap.end());
  theUriFileMappingMap.insert(
    std::pair<std::string, std::string>(aUri, aFileUri));
  ZORBA_ASSERT(theUriFileMappingMap.find(aUri) != theUriFileMappingMap.end());
}

std::string ZorbaDebuggerCommons::getFilepathOfURI(const std::string& aUri) const
{
  std::map<std::string, std::string>::const_iterator lIter;
  lIter = theUriFileMappingMap.find(aUri);
  xqpStringStore_t lString;
  if (lIter == theUriFileMappingMap.end()) {
    lString = new xqpStringStore(aUri);
  } else {
    lString = new xqpStringStore(lIter->second);
  }
  xqpStringStore_t lRes;
  URI::decode_file_URI(lString, lRes);
  return lRes->str();
}

void ZorbaDebuggerCommons::clearBreakpoint( unsigned int aId )
{
  std::map<DebugLocation_t, bool, DebugLocation>::iterator lLocation;
  std::map<unsigned int, DebugLocation_t>::iterator lBreakpoint;

  lBreakpoint = theBreakpoints.find(aId);
  if (lBreakpoint == theBreakpoints.end()) {
    return;
  }
 
  lLocation = theLocationMap.find(lBreakpoint->second);
  if (lLocation != theLocationMap.end()) {
    lLocation->second = false;
  }
}

bool DebugLocation::operator()( const DebugLocation_t& aLocation1, const DebugLocation_t& aLocation2 ) const
{
  int c;
  if ((c = aLocation1.theFileName.compare(aLocation2.theFileName)) != 0) {
    return c < 0;
  }
  if (aLocation1.theLineNumber == aLocation2.theLineNumber) {
    if (aLocation1.theQueryLocation.getLineBegin() == 0 ||
      aLocation2.theQueryLocation.getLineBegin() == 0) {
        return false;
    }
    if (aLocation1.theQueryLocation.getLineBegin() == 
      aLocation2.theQueryLocation.getLineBegin()) {
        return aLocation1.theQueryLocation.getLineEnd() <
          aLocation2.theQueryLocation.getLineEnd();
    }
    return aLocation1.theQueryLocation.getLineBegin() <
      aLocation2.theQueryLocation.getLineBegin();
  }
  return aLocation1.theLineNumber < aLocation2.theLineNumber;
}

store::Item* DebuggerSingletonIterator::getValue() const
{
  return theValue->getp();
}

void DebuggerSingletonIterator::setValue(store::Item_t* aValue)
{
  theValue = aValue;
}

DebuggerSingletonIterator::DebuggerSingletonIterator(
  static_context* sctx, QueryLoc loc, store::Item_t* aValue ) :
NoaryBaseIterator<DebuggerSingletonIterator, PlanIteratorState>(sctx, loc),
theValue(aValue)
{
}

NOARY_ACCEPT(DebuggerSingletonIterator);

bool DebuggerSingletonIterator::nextImpl( store::Item_t& result,
                                                PlanState& planState ) const
{
  PlanIteratorState* state;
  DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );
  result = theValue->getp();
  STACK_PUSH ( result != NULL, state );
  STACK_END (state);
}

} //namespace zorba
