#include "zorba_debugger_commons.h"

#include "zorbaerrors/Assert.h"
#include "runtime/debug/zorba_debug_iterator.h"

zorba::ZorbaDebuggerCommons::ZorbaDebuggerCommons()
:
theBreak(false), theCause(0)
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
  if (lIter != theLocationMap.end()) {
    aLocation.theQueryLocation = lIter->first.theQueryLocation;
    lIter->second = true;
    return true;
  }
  return false;
}

bool zorba::ZorbaDebuggerCommons::hasToBreakAt( const QueryLoc& aLocation ) const
{
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

bool zorba::ZorbaDebuggerCommons::hasToBrak(SuspensionCause* aCause) const
{
  //This is not a precondition, because the client does not hava another
  //way to check it, then calling this function. But if theCause is 0, this
  // is clearly a bug.
  ZORBA_ASSERT(theBreak ? theCause != NULL : true);

  // Check preconditions
  ZORBA_ASSERT(*aCause == 0);

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
