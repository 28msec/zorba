#include "zorba_debugger_commons.h"

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
  std::map<DebugLocation_t, bool, DebugLocation>::const_iterator lIter;
  for (lIter = theLocationMap.find(lLocation); lIter != theLocationMap.end(); lIter++) {
    if (lIter->second)
      return true;
  }
  return false;
}

bool zorba::DebugLocation::operator()( const DebugLocation_t& aLocation1, const DebugLocation_t& aLocation2 ) const
{
  int c;
  if ((c = aLocation1.theFileName.compare(aLocation2.theFileName)) != 0) {
    return c < 0;
  }
  return aLocation1.theLineNumber < aLocation2.theLineNumber;
}
