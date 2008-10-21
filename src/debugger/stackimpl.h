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
#ifndef ZORBA_DEBUGGER_STACK_H
#define ZORBA_DEBUGGER_STACK_H

#include <stack>
#include <string>

#include <zorba/debugger_client.h>

namespace zorba{

class StackImpl: public RuntimeStack{
  
  private:
    std::stack< std::pair<std::string, QueryLocation*> > theStack;
  
  public:
    StackImpl(){}

    ~StackImpl()
    {
      while(!theStack.empty())
      {
        delete theStack.top().second;
        theStack.pop();
      }
    }

    void push(std::string aLabel, QueryLocation* aLocation)
    {
      theStack.push(std::make_pair<std::string, QueryLocation*>(aLabel, aLocation));
    }

    virtual std::stack< std::pair<std::string, QueryLocation*> > getFrames() const
    {
      return theStack;
    }
};
}//end of namespace
#endif
