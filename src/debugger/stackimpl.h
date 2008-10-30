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

class FrameImpl: public Frame
{
  private:
    const std::string theSignature;
    const QueryLocation* theLocation;

  public:
    FrameImpl(const std::string& aSignature, const QueryLocation* aLocation):
      theSignature(aSignature), theLocation(aLocation){}

    ~FrameImpl(){ delete theLocation; }

    const std::string& getSignature() const { return theSignature; }
    const QueryLocation* getLocation() const { return theLocation; }
};

class StackFrameImpl: public StackFrame{
  
  private:
    std::stack<Frame*> theStack;
  
  public:
    StackFrameImpl(){}

    ~StackFrameImpl()
    {
      while(!theStack.empty())
      {
        delete theStack.top();
        theStack.pop();
      }
    }

    const Frame* top() const
    {
      if(!theStack.empty())
      {
        return theStack.top();
      }
      return 0;
    }

    StackFrame* push(const std::string aSignature, QueryLocation* aLocation)
    {
      theStack.push(new FrameImpl(aSignature, aLocation));
      return this;
    }

    StackFrame* push(Frame* aFrame)
    {
      theStack.push(aFrame);
      return this;
    }

    StackFrame* pop()
    {
      if(!theStack.empty())
      {
        delete theStack.top();
        theStack.pop();
      }
      return this;
    }

    unsigned int size() const
    {
      return theStack.size(); 
    }

    bool empty() const
    {
      return theStack.empty();
    }
};
}//end of namespace
#endif
