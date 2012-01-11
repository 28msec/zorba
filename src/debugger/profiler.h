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

#ifndef ZORBA_DEBUGGER_PROFILER_H
#define ZORBA_DEBUGGER_PROFILER_H

#include <fstream>
#include <string>
#include <stack>

namespace zorba {

class String;
class FnCallEntry;
class QueryLoc;

class Profiler
{
  private:
    std::string theFileName;
    double theTimeTaken;
    std::ofstream theProfile;
    std::stack<FnCallEntry *> theStack;
    FnCallEntry* theRoot;
    FnCallEntry* theCurrent;

    void print(FnCallEntry* aCall);

  public:
    Profiler(const String& aFileName, const std::string& aProfileName);
    ~Profiler();
  
    void beginFn(const std::string& aFnName, const QueryLoc& aQueryLoc);
    void endFn();
};
}//end of namespace
#endif
