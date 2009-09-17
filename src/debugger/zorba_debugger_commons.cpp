
#include "system/globalenv.h"

#include "zorba_debugger_commons.h"

#include "compiler/api/compilercb.h"
#include "context/dynamic_context.h"
#include "zorbaerrors/Assert.h"

#include "runtime/debug/zorba_debug_iterator.h"
#include "runtime/visitors/planitervisitor.h"

#include "store/api/item_factory.h"

#include "zorbatypes/URI.h"

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

bool ZorbaDebuggerCommons::addBreakpoint( DebugLocation_t& aLocation )
{
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
ZorbaDebuggerCommons::eval(const xqpString& aExpr)
{
  theExecEval = true;
  xqpStringStore_t lStore = aExpr.getStore();
  GlobalEnvironment::getInstance().getItemFactory()->createString(theEvalItem,
    lStore);
  std::list<std::pair<xqpString, xqpString> > lRes =
    theCurrentIterator->eval(*thePlanState);
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
  std::string lRes = URI::decode_file_URI(lString)->c_str();
  return lRes;
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