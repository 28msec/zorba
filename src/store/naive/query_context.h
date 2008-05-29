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
#ifndef ZORBA_SIMPLE_STORE_QUERY_CONTEXT
#define ZORBA_SIMPLE_STORE_QUERY_CONTEXT

#include <stack>
#include <map>
#include <vector>

#include "zorbautils/mutex.h"
#include "zorbaerrors/fatal.h"

#include "common/shared_types.h"


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
