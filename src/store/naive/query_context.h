#ifndef ZORBA_STORE_QUERY_CONTEXT_H
#define ZORBA_STORE_QUERY_CONTEXT_H

#include <stack>
#include <map>

#include <zorba/common/api_shared_types.h>

#include "store/util/mutex.h"

namespace zorba { namespace store {

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
  SYNC_CODE(Mutex                         theMutex;)

public:
  QueryContext& getContext(ulong queryId)
  {
    SYNC_CODE(AutoMutex lock(theMutex);)

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
    SYNC_CODE(AutoMutex lock(theMutex);)

    std::map<ulong, QueryContext>::iterator ctxi;

    ctxi = theContainer.find(queryId);

    if (ctxi == theContainer.end() || (soft && !ctxi->second.empty()))
      return;

    theContainer.erase(queryId);
  }
};


} // namespace store
} // namespace zorba

#endif
