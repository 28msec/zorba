
#include "system/globalenv.h"

#include "zorba_debugger_commons.h"

#include "compiler/api/compilercb.h"
#include "context/dynamic_context.h"
#include "zorbaerrors/Assert.h"

#include "runtime/debug/zorba_debug_iterator.h"
#include "runtime/visitors/planitervisitor.h"

#include "store/api/item_factory.h"

#include "zorbatypes/URI.h"

zorba::ZorbaDebuggerCommons::ZorbaDebuggerCommons(zorba::static_context* sctx)
:
theBreak(false),
theCause(0),
theExecEval(false)
{
}

zorba::ZorbaDebuggerCommons::~ZorbaDebuggerCommons()
{
}

void zorba::ZorbaDebuggerCommons::setRuntime( ZorbaDebuggerRuntime* aRuntime )
{
  theRuntime = aRuntime;
}

zorba::ZorbaDebuggerRuntime* zorba::ZorbaDebuggerCommons::getRuntime()
{
  return theRuntime;
}

void zorba::ZorbaDebuggerCommons::setCurrentStaticContext( static_context* aStaticContext )
{
  theCurrentStaticContext = aStaticContext;
}

void zorba::ZorbaDebuggerCommons::setCurrentDynamicContext( dynamic_context* aDynamicContext )
{
 theCurrentDynamicContext = aDynamicContext;
}

zorba::dynamic_context* zorba::ZorbaDebuggerCommons::getCurrentDynamicContext() const
{
  return theCurrentDynamicContext;
}

zorba::static_context* zorba::ZorbaDebuggerCommons::getCurrentStaticContext() const
{
  return theCurrentStaticContext;
}

bool zorba::ZorbaDebuggerCommons::addBreakpoint( DebugLocation_t& aLocation )
{
  std::map<DebugLocation_t, bool, DebugLocation>::iterator lIter;
  lIter = theLocationMap.find(aLocation);
  // if the location could not be found, try it again with the encoded file uri.
  if (lIter == theLocationMap.end()) {
    std::string lTmp = aLocation.theFileName;
    aLocation.theFileName = URI::encode_file_URI(aLocation.theFileName)->str();
    lIter = theLocationMap.find(aLocation);
    aLocation.theFileName = lTmp;
  }
  if (lIter != theLocationMap.end()) {
    aLocation.theQueryLocation = lIter->first.theQueryLocation;
    lIter->second = true;
    return true;
  }
  // If the location could not be found, we iterate over all locations and try
  // to find a location with a filename with a matching substring
  for (lIter = theLocationMap.begin(); lIter != theLocationMap.end(); lIter++) {
    if (lIter->first.theFileName.find(aLocation.theFileName) !=
      std::string::npos && aLocation.theLineNumber ==
      lIter->first.theLineNumber) {
        lIter->second = true;
        aLocation.theQueryLocation = lIter->first.theQueryLocation;
        return true;
    }
  }
  //otherwise, there could not be found a breakable expression
  return false;
}

bool zorba::ZorbaDebuggerCommons::hasToBreakAt( const QueryLoc& aLocation ) const
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

bool zorba::ZorbaDebuggerCommons::hasToBreakAt( const ZorbaDebugIterator* aIter )
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

bool zorba::ZorbaDebuggerCommons::hasToBreak(SuspensionCause* aCause) const
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

void zorba::ZorbaDebuggerCommons::setBreak( bool lBreak, SuspensionCause aCause )
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

void zorba::ZorbaDebuggerCommons::setCurrentIterator( const ZorbaDebugIterator* aIterator )
{
  theCurrentIterator = aIterator;
  //Test postconditions
  ZORBA_ASSERT(aIterator == theCurrentIterator);
}

const zorba::ZorbaDebugIterator* zorba::ZorbaDebuggerCommons::getCurrentIterator()
{
  return theCurrentIterator;
}

void zorba::ZorbaDebuggerCommons::makeStepOut()
{
  const ZorbaDebugIterator* lIter = theCurrentIterator->getParent();
  if (lIter != NULL) {
    theBreakIterators.push_back(lIter);
  }
}

void zorba::ZorbaDebuggerCommons::makeStepOver()
{
  //Preconditions
  ZORBA_ASSERT(theCurrentIterator != NULL);

  const ZorbaDebugIterator* lIter = theCurrentIterator->getOverIterator();
  if (lIter != NULL) {
    theBreakIterators.push_back(lIter);
  }
}

void zorba::ZorbaDebuggerCommons::setPlanState( PlanState* aPlanState )
{
  thePlanState = aPlanState;
  //Check postconditions
  ZORBA_ASSERT(thePlanState == aPlanState);
}

void zorba::ZorbaDebuggerCommons::setDebugIteratorState( ZorbaDebugIteratorState* aState )
{
  theDebugIteratorState = aState;
  //Check postconditions
  ZORBA_ASSERT(theDebugIteratorState == aState);
}

std::list<std::pair<zorba::xqpString, zorba::xqpString> > 
zorba::ZorbaDebuggerCommons::eval(const xqpString& aExpr)
{
  theExecEval = true;
  xqpStringStore_t lStore = aExpr.getStore();
  GlobalEnvironment::getInstance().getItemFactory()->createString(theEvalItem,
    lStore);
  std::list<std::pair<zorba::xqpString, zorba::xqpString> > lRes =
    theCurrentIterator->eval(*thePlanState);
  theExecEval = false;
  return lRes;
}

zorba::store::Item_t* zorba::ZorbaDebuggerCommons::getEvalItem()
{
  return &theEvalItem;
}

bool zorba::DebugLocation::operator()( const DebugLocation_t& aLocation1, const DebugLocation_t& aLocation2 ) const
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

zorba::store::Item* zorba::DebuggerSingletonIterator::getValue() const
{
  return theValue->getp();
}

void zorba::DebuggerSingletonIterator::setValue(zorba::store::Item_t* aValue)
{
  theValue = aValue;
}

zorba::DebuggerSingletonIterator::DebuggerSingletonIterator(
  static_context* sctx, QueryLoc loc, zorba::store::Item_t* aValue ) :
NoaryBaseIterator<DebuggerSingletonIterator, PlanIteratorState>(sctx, loc),
theValue(aValue)
{
}

NOARY_ACCEPT(zorba::DebuggerSingletonIterator);

bool zorba::DebuggerSingletonIterator::nextImpl( store::Item_t& result,
                                                PlanState& planState ) const
{
  PlanIteratorState* state;
  DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );
  result = theValue->getp();
  STACK_PUSH ( result != NULL, state );
  STACK_END (state);
}
