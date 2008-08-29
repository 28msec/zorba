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
#ifndef ZORBA_SPECIFICATON
#define ZORBA_SPECIFICATON

#include <vector>
#include <string>
#include <cassert>
#include <iostream>
#include "common/common.h"

class Variable 
{
public:
  bool        theInline;
  std::string theName;
  std::string theValue;

  Variable() : theInline(false) {}
};


/*******************************************************************************
  A State object stores the result of parsing a "State" declaration in a .spec
  file. A State declaration corresponds to one query and specifies the query
  name, its external variables, and its possible expected results. 

  For example, the /UseCases/PartsUpdates/parts-q1.spec file looks like this:

  State: parts-q1
  Args: -x part-tree=$UPDATE_SRC_DIR/Queries/w3c_update_testsuite/TestSources/part-tree.xml -d 2006-08-05
  State: parts-q1-test
  Args: -x part-tree=$UPDATE_SRC_DIR/Queries/w3c_update_testsuite/TestSources/part-tree.xml -d 2007-02-01
  Compare: parts-q1-results.xml Fragment

  Parsing this file will produce 2 State objects.
********************************************************************************/
class State 
{
public:
  enum CompareType {
    TEXT,
    FRAGMENT
  };

  static std::string compareTypeStr(CompareType aType) {
    switch(aType) {
    case TEXT:
      return "TEXT";
    case FRAGMENT:
      return "FRAGMENT";
    }
    assert(false);
  }

  std::string              theName;
  std::vector<Variable*>   theVars;
  bool                     hasDate;
  std::string              theDate;
  bool                     hasCompare;
  std::vector<std::string> theCompares;
  std::vector<CompareType> theCompareTypes;
  bool                     hasErrors;
  std::vector<std::string> theErrors;

  State() : hasDate(false), hasCompare(false), hasErrors(false)
  {}

  ~State() 
  {
    std::vector<Variable*>::iterator lIter = theVars.begin();
    std::vector<Variable*>::iterator lEnd =  theVars.end();
    for (;lIter != lEnd; ++lIter)
    {
      delete *lIter;
    }
    theVars.clear();
  }

  size_t varsSize() const
  {
    return theVars.size();
  }

  std::vector<Variable*>::const_iterator
  varsBegin() const
  {
    return theVars.begin();
  }


  std::vector<Variable*>::const_iterator
  varsEnd() const
  {
    return theVars.end();
  }
};


/*******************************************************************************
  A Specification object stores the result of parsing a .spec file. It consists
  of a vector of State objs.
********************************************************************************/
class Specification
{
  typedef char char_t;
  typedef std::string::iterator iterator_t;

public:
  std::vector<State*> theStates;

private:
  // Transient data members used during the parsing of the associated .spec file
  State     * theCurState;
  Variable  * theCurVar;

public:
  Specification() {}

  ~Specification() 
  {
    std::vector<State*>::iterator lIter = theStates.begin();
    std::vector<State*>::iterator lEnd =  theStates.end();
    for (;lIter != lEnd; ++lIter)
    {
      delete *lIter;
    }
    theStates.clear();
  }

  size_t statesSize() const
  {
    return theStates.size();
  }

  std::vector<State*>::const_iterator
  statesBegin() const
  {
    return theStates.begin();
  }

  std::vector<State*>::const_iterator
  statesEnd() const
  {
    return theStates.end();
  }

private:
  void addState(iterator_t str, iterator_t end) 
  {
    theCurState = new State();
    theCurState->theName = std::string(str, end);
  }

  void setDate(iterator_t str, iterator_t end) 
  {
    theCurState->hasDate = true;
    theCurState->theDate = std::string(str, end);
  }

  void addCompare(iterator_t str, iterator_t end) 
  {
    theCurState->hasCompare = true;
    theCurState->theCompares.push_back(std::string(str, end));
  }

  void addCompareType(iterator_t str, iterator_t end) 
  {
    std::string lCompareType = std::string(str, end);
    if (lCompareType.compare("Text") == 0) 
    {
      theCurState->theCompareTypes.push_back(State::TEXT);
    }
    else if (lCompareType.compare("Fragment") == 0) 
    {
      theCurState->theCompareTypes.push_back(State::FRAGMENT);
    }
    else 
    {
      assert(false);
    }
  }

  void addError(iterator_t str, iterator_t end) 
  {
    theCurState->hasErrors = true;
    std::string lError = std::string(str, end);
    theCurState->theErrors.push_back(lError);
  }

  void addQuery() 
  {
    theStates.push_back(theCurState);
    theCurState = 0;
  }

  void setVarName(iterator_t str, iterator_t end) 
  {
    theCurVar = new Variable();
    theCurVar->theName = std::string(str, end);
  }

  void setVarValue(iterator_t str, iterator_t end) 
  {
    theCurVar->theValue = std::string(str,end);
  }

  void addVariable(bool aInline) 
  {
    theCurVar->theInline = aInline;
    theCurState->theVars.push_back(theCurVar);
    theCurVar = 0;
  }

  void tokenize(const std::string& str,
                std::vector<std::string>& tokens,
                const std::string& delimiters)
  {
    // Skip delimiters at beginning.
    std::string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    // Find first "non-delimiter".
    std::string::size_type pos     = str.find_first_of(delimiters, lastPos);

    while (std::string::npos != pos || std::string::npos != lastPos)
    {
      // Found a token, add it to the vector.
      tokens.push_back(str.substr(lastPos, pos - lastPos));
      // Skip delimiters.  Note the "not_of"
      lastPos = str.find_first_not_of(delimiters, pos);
      // Find next "non-delimiter"
      pos = str.find_first_of(delimiters, lastPos);
    }
  }

public:
  
  void trim(std::string& str) {
    std::string::size_type  notwhite = str.find_first_not_of(" \t\n");
    str.erase(0,notwhite);

    notwhite = str.find_last_not_of(" \t\n"); 
    str.erase(notwhite+1); 
  }
  
  bool
  parseFile(std::string str)
  {
    bool first_query = true;
    std::ifstream lFile(str.c_str(), std::ifstream::in);
    std::stringstream lContent;
    while(lFile.good()){
      lContent << (char)lFile.get();
    }
    lFile.close();
    std::vector<std::string> lines;
    std::vector<std::string>::iterator it;
    tokenize(lContent.str(), lines, "\n");
    for(it=lines.begin(); it!=lines.end(); ++it)
    {
      std::vector<std::string> tokens;
      std::vector<std::string>::iterator lIter;
      trim(*it);
      tokenize(*it, tokens, " ");
      for(lIter=tokens.begin(); lIter!=tokens.end(); ++lIter)
      {      
        if( *lIter == "Args:" )
        {
          for(++lIter;lIter!=tokens.end(); ++lIter)
          {
            if(*lIter == "-d")
            {
              ++lIter;
              if(lIter == tokens.end() ) { return false; }
              setDate(lIter->begin(), lIter->end());
            } else if (*lIter == "-x" ) {
              bool lInline = false;
              ++lIter;
              if(lIter == tokens.end() ) { return false; }
              if(lIter->find(':') == std::string::npos){ lInline=true; }
              if(lIter->find('=') == std::string::npos){ return false; }
              if( lInline ){
                setVarName(lIter->begin(), lIter->begin()+lIter->find('='));
              } else {
                setVarName(lIter->begin(), lIter->begin()+lIter->find(':'));
              }
              setVarValue(lIter->begin()+lIter->find("=")+1, lIter->end());
              addVariable(lInline);
            } else {
              return false;
            }
          }
          break;
        } else if ( *lIter == "Compare:" ){
          ++lIter;
          if(lIter == tokens.end() ) { return false; }
          addCompare(lIter->begin(), lIter->end());
          ++lIter;
          if(lIter == tokens.end() ) { return false; }
          addCompareType(lIter->begin(), lIter->end());
        } else if ( *lIter == "State:" ) {
          if(first_query){
            first_query = false;
          } else {
            addQuery();
          }
          ++lIter;
          if(lIter == tokens.end() ) { return false; }
          addState(lIter->begin(), lIter->end());
        } else if ( *lIter == "Error:" ) { 
          ++lIter;
          if(lIter == tokens.end() ) { return false; }
          addError(lIter->begin(), lIter->end());
        } else if ( lIter->find("Compare:") != std::string::npos){
          addCompare( lIter->begin()+lIter->find(":")+1, lIter->end() );
          ++lIter;
          if(lIter == tokens.end() ) { return false; }
          addCompareType(lIter->begin(), lIter->end());
        } else if ( lIter->find("State:") != std::string::npos ) {
          if(first_query){
            first_query = false;
          } else {
            addQuery();
          }
          addState( lIter->begin()+lIter->find(":")+1, lIter->end());
        } else if ( lIter->find("Error:") != std::string::npos ) {
          addError(lIter->begin()+lIter->find(":")+1, lIter->end());
        } else {
          break;
        }
      }
    }
    addQuery();
    return true;
  }

  void printContent() 
  {
    std::cout << "STATES (Size: " << statesSize() << ")" << std::endl;
    std::vector<State*>::const_iterator lIter = statesBegin();
    std::vector<State*>::const_iterator lEnd = statesEnd();

    for(;lIter!=lEnd;++lIter)
    {
      std::cout << "STATE" << std::endl;
      std::cout << "  Name: " << (*lIter)->theName << std::endl; 
      std::cout << "  HasDate: " << (*lIter)->hasDate << std::endl; 
      if ((*lIter)->hasDate) {
        std::cout << "  Date: " << (*lIter)->theDate << std::endl; 
      }

      std::cout << "  VARS (Size: " << (*lIter)->varsSize() << ")" << std::endl;
      std::vector<Variable*>::const_iterator lIter2 = (*lIter)->varsBegin();
      std::vector<Variable*>::const_iterator lEnd2 = (*lIter)->varsEnd();
      
      for(;lIter2!=lEnd2;++lIter2)
      {
        std::cout << "  VAR" << std::endl;
        std::cout << "    Inline: " << (*lIter2)->theInline << std::endl;
        std::cout << "    Name: " << (*lIter2)->theName << std::endl;
        std::cout << "    Value: " << (*lIter2)->theValue << std::endl;
      }

      std::cout << "  HasCompare: " << (*lIter)->hasCompare << std::endl; 
      if ((*lIter)->hasCompare) 
      {
        ulong numCompares = (*lIter)->theCompares.size();
        for (ulong i = 0; i < numCompares; i++)
        {
          std::cout << "  Compare: " << (*lIter)->theCompares[i] << std::endl; 
          std::cout << "  CompareType: " << State::compareTypeStr((*lIter)->theCompareTypes[i]) << std::endl; 
        }
      }

      std::cout << "  HasErrors: " << (*lIter)->hasErrors << std::endl;
      if ((*lIter)->hasErrors) {
        std::vector<std::string>::const_iterator lIter3 = (*lIter)->theErrors.begin();
        std::vector<std::string>::const_iterator lEnd3  = (*lIter)->theErrors.end();
        for(;lIter3!=lEnd3;++lIter3)
        {
          std::cout << "    Error: " << *lIter3 << std::endl;
        }
      }

    }
  }

};

#endif
