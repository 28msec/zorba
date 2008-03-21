#ifndef ZORBA_SIMPLE_STORE_QUERY_CONTEXT
#define ZORBA_SIMPLE_STORE_QUERY_CONTEXT

#include <stack>
#include <map>
#include <vector>

#include "common/shared_types.h"
#include "errors/fatal.h"
#include "store/util/mutex.h"

namespace zorba { namespace store {

class XmlNode;

/*******************************************************************************

********************************************************************************/
class QueryContext
{
  friend class QueryContextContainer;

protected:
  std::stack<XmlNode*>   theNodePath;

public:
  ~QueryContext() { }

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
  SYNC_CODE(Mutex               theMutex;)

public:
  QueryContext& getContext(ulong queryId);

  void removeContext(ulong queryId);
};


} // namespace store
} // namespace zorba

#endif
