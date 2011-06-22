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

#include "stdafx.h"

#include "debugger/profiler.h"

#include <string>
#include <ctime>
#include <cassert>
#include <sstream>
#include <list>

#include <zorba/zorba_string.h>

#include "compiler/parser/query_loc.h"

using namespace std;

namespace zorba {

  class FnCallEntry
  {
    private:
      FnCallEntry* theParent;
      list<FnCallEntry*> theChildren;
      bool isUserDefined;
      string theFnName;
      string theFileName;
      unsigned int theLineNo;
      double theTimeTaken;
      double theMark;
    
    public:
      
      FnCallEntry(string aFnName, string aFileName, unsigned int aLineNo)
        : theParent(0),
          theChildren(0),
          isUserDefined(false),
          theFnName(aFnName),
          theFileName(aFileName),
          theLineNo(aLineNo),
          theTimeTaken(0),
          theMark(0)
      {
      }
      
      ~FnCallEntry()
      {
        list<FnCallEntry*>::iterator it;
        for(it=theChildren.begin(); it!=theChildren.end(); ++it)
        {
          delete *it;
        }
      }

      FnCallEntry* addChild(FnCallEntry* aChild)
      {
        aChild->theParent = this;
        theChildren.push_back(aChild);
        return this;
      }

      FnCallEntry* setUserDefined(bool userDefined)
      {
        isUserDefined = userDefined;
        return this;  
      }

      FnCallEntry* setFnName(string aFnName)
      {
        //size_t found = aFnName.find("(");
        //if(found != string::npos)
        //{
        //  theFnName = string(aFnName.begin(), aFnName.begin()+found);
        //} else {
        //  theFnName = aFnName;
        //}
        theFnName = aFnName;
        return this;
      }

      FnCallEntry* setFileName(string aFileName)
      {
        theFileName = aFileName;
        return this;
      }

      FnCallEntry* setTimeTaken(double aTimeTaken)
      {
        theTimeTaken = aTimeTaken;
        return this;
      }

      FnCallEntry* setMark(double aMark)
      {
        theMark = aMark;
        return this;
      }
     
      list<FnCallEntry*> getChildren(){ return theChildren; }
      
      FnCallEntry* getParent(){ return theParent; }

      string getFnName(){ return theFnName; }

      string getFileName(){ return theFileName; }

      unsigned int getLineNo(){ return theLineNo; }

      double getTimeTaken(){ return theTimeTaken; }
 
      double getMark(){ return theMark; }
 };
  
  double getTime()
  {
    return  (double)clock()/CLOCKS_PER_SEC*1000;
  }

  Profiler::Profiler(const String& aFileName,
                     const string& aProfileName): theRoot(0), theCurrent(0)
  {
    stringstream lStream;
    lStream << aFileName;
    theFileName = lStream.str();
    theProfile.open(aProfileName.c_str());
    theProfile << "version: 0.9.6\ncmd: " << theFileName << "\npart: 1\n\nevents: Time" << endl << endl;     
  }

  Profiler::~Profiler()
  {
    print(theRoot);
    assert(theProfile.is_open());
    theProfile.close();
    delete theRoot;
  }

  void Profiler::print(FnCallEntry* aCall)
  {
    if(aCall == 0) return;
    list<FnCallEntry*> children = aCall->getChildren();
    list<FnCallEntry*>::iterator it;
    for(it=children.begin(); it!=children.end(); ++it)
    {
      FnCallEntry* lCall = *it;
      assert(lCall != 0);
      print(lCall);
    }
    theProfile << endl;
    theProfile << "fl=" << aCall->getFileName() << endl;
    theProfile << "fn=" << aCall->getFnName() << endl;
    if(aCall->getFnName() == "{main}")
    {
      theProfile << endl << "summary: " << theTimeTaken << endl << endl;
    }
    theProfile << aCall->getLineNo() << ' ' << (unsigned int)aCall->getTimeTaken() << endl;
    
    for(it=children.begin(); it!=children.end(); ++it)
    {
      FnCallEntry* lCall = *it;
      assert(lCall != 0);
      theProfile << "cfl=" << lCall->getFileName() << endl;
      theProfile << "cfn=" << lCall->getFnName() << endl;
      theProfile << "calls=1 " << lCall->getLineNo() << " 0" << endl;
      theProfile << lCall->getLineNo() << ' ' << lCall->getTimeTaken() << endl;
    }
  }

  void Profiler::beginFn(const string& aFnName, const QueryLoc& aQueryLoc)
  {
    if(theRoot == 0)
    {
      theRoot = new FnCallEntry("{main}", theFileName, 1);
      theCurrent = theRoot;
    }
    stringstream lFile;
    lFile << aQueryLoc.getFilename();
    FnCallEntry* lCall = new FnCallEntry( aFnName,
                                          lFile.str(),
                                          aQueryLoc.getLineBegin()
                                        );
    lCall->setTimeTaken(0);
    lCall->setMark(getTime());
    theStack.push(lCall);
    theCurrent->addChild(lCall);
    theCurrent = lCall;
  }

  void Profiler::endFn()
  {
    assert(theCurrent != 0);
    assert(theStack.size() > 0);
    FnCallEntry* lCall = theStack.top();
    theStack.pop();
    lCall->setTimeTaken(getTime() - lCall->getMark());
    theTimeTaken += lCall->getTimeTaken();
    theCurrent = theCurrent->getParent();
  }
}//end of namespace
