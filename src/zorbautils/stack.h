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
#ifndef ZORBA_UTILS_STACK
#define ZORBA_UTILS_STACK

#include <vector>

#include "zorbamisc/config/platform.h"


namespace zorba { 

template <class T>
class Stack
{
protected:
  ulong          theTop;
  std::vector<T> theStack;

public:
  Stack(ulong initSize = 0) : theTop(0)
  {
    if (initSize > 0)
      theStack.resize(initSize);
  }

  ~Stack() { }

  bool empty() const
  {
    return theTop == 0;
  }

  ulong size() const
  {
    return theTop;
  }

  void clear()
  {
    theTop = 0;
    theStack.clear();
  }

  const T& top() const
  {
    assert(!empty());
    return theStack[theTop-1];
  }

  T& top()
  {
    assert(!empty());
    return theStack[theTop-1];
  }

  void pop()
  {
    assert(!empty());
    theTop--;
    theStack[theTop].~T();
  }

  void push(const T& val)
  {
    if (theTop < theStack.size())
      theStack[theTop] = val;
    else
      theStack.push_back(val);

    theTop++;
  }

  const T& operator[](ulong i) const
  {
    assert(i < theTop);
    return theStack[i];
  }
};


}
#endif
