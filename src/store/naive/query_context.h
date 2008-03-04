#ifndef ZORBA_DEFAULT_STORE_QUERY_CONTEXT
#define ZORBA_DEFAULT_STORE_QUERY_CONTEXT

#include <stack>
#include <map>

#include <zorba/common/api_shared_types.h>

#include "store/util/mutex.h"

namespace zorba
{

class XmlNode;

/*******************************************************************************

********************************************************************************/
class QueryContext
{
protected:
  std::stack<XmlNode*> theNodePath;

public:
  ~QueryContext() { clear(); }

  bool empty() const { return theNodePath.empty(); }

  void push(XmlNode* n)
  {
    theNodePath.push(n);
  }

  XmlNode* pop()
  {
    XmlNode* n = theNodePath.top();
    theNodePath.pop();
    return n;
  }
  
  XmlNode* top()
  {
    return theNodePath.top();
  }

  void clear()
  {
    while (!theNodePath.empty())
      theNodePath.pop();
  }
};


/*******************************************************************************

********************************************************************************/
class QueryContextContainer
{
protected:
  std::map<ulong, QueryContext> theContainer;
  Mutex                         theMutex;

public:
  QueryContext& getContext(ulong queryId)
  {
    AutoMutex lock(theMutex);

    std::map<ulong, QueryContext>::iterator ctxi;

    ctxi = theContainer.find(queryId);

    if (ctxi != theContainer.end())
      return ctxi->second;

    std::pair<std::map<ulong, QueryContext>::iterator, bool> res =
      theContainer.insert(std::pair<ulong, QueryContext>(queryId, QueryContext()));

    ctxi = res.first;
    return ctxi->second;
  }

  void removeContext(ulong queryId, bool soft)
  {
    AutoMutex lock(theMutex);

    std::map<ulong, QueryContext>::iterator ctxi;

    ctxi = theContainer.find(queryId);

    if (ctxi == theContainer.end() || (soft && !ctxi->second.empty()))
      return;

    theContainer.erase(queryId);
  }
};


}

#endif
