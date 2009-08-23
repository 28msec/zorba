#include "zorba_debugger_commons.h"


void zorba::ZorbaDebuggerCommons::addDebugLocation( const DebugLocation_t& aLocation, ZorbaDebugIterator* anIterator )
{
  theLocationMap.insert(std::pair<DebugLocation_t, ZorbaDebugIterator*>(aLocation, anIterator));
}

zorba::ZorbaDebugIterator* zorba::ZorbaDebuggerCommons::findDebugIterator( const DebugLocation_t& aLocation ) const
{
  std::map<DebugLocation_t, ZorbaDebugIterator*, DebugLocation>::const_iterator iter = theLocationMap.find(aLocation);
  if (iter == theLocationMap.end()) {
    return NULL;
  }
  return iter->second;
}

void zorba::ZorbaDebuggerCommons::setRuntime( ZorbaDebuggerRuntime* aRuntime )
{
  theRuntime = aRuntime;
}

zorba::ZorbaDebuggerRuntime* zorba::ZorbaDebuggerCommons::getRuntime()
{
  return theRuntime;
}

bool zorba::DebugLocation::operator()( const DebugLocation_t& aLocation1, const DebugLocation_t& aLocation2 ) const
{
  int c;
  if ((c = aLocation1.theFileName.compare(aLocation2.theFileName)) != 0) {
    return c < 0;
  }
  return aLocation1.theLineNumber < aLocation2.theLineNumber;
}
