#ifndef XQP_DEFAULT_STORE_QUERY_CONTEXT
#define XQP_DEFAULT_STORE_QUERY_CONTEXT

#include <stack>
#include <map>


namespace xqp
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
class QueryContextContainer : public std::map<ulong, QueryContext>
{
public:
  QueryContext& getContext(ulong queryId)
  {
    std::map<ulong, QueryContext>::iterator ctxi;

    ctxi = find(queryId);

    if (ctxi != end())
      return ctxi->second;

    std::pair<std::map<ulong, QueryContext>::iterator, bool> res =
      insert(std::pair<ulong, QueryContext>(queryId, QueryContext()));

    ctxi = res.first;
    return ctxi->second;
  }

  void removeContext(ulong queryId)
  {
    std::map<ulong, QueryContext>::iterator ctxi;

    ctxi = find(queryId);

    if (ctxi == end())
      return;

    erase(queryId);
  }
};


}

#endif
