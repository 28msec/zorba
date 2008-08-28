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
#include <fstream>

class Specification
{
  typedef char char_t;
  typedef std::string::iterator iterator_t;

public:
  struct Variable {
    bool theInline;
    std::string theVarName, theVarValue;
  };

  Specification() : theInline(false) {}

private:
  bool theInline;
  std::string theVarName, theVarValue;
  std::vector<Variable> theVariables;
  std::vector<std::string> theErrors;
  std::string theDate, theTimezone;

  void setInline() {
    theInline = true;
  }

  void setVarName(iterator_t str, iterator_t end) {
    theVarName = std::string(str, end);
  }

  void setVarValue(iterator_t str, iterator_t end) {
    theVarValue = std::string(str, end);
  }

  void addVariable() {
    Variable args = { theInline, theVarName, theVarValue};
    theVariables.push_back(args);
  }

  void addError(iterator_t str, iterator_t end) {
    std::string s(str, end);
    theErrors.push_back(s);
  }

  void setDate(iterator_t str, iterator_t end) {
    std::string s(str, end);
    theDate = s;
  }

  void setTimezone(iterator_t str, iterator_t end) {
    std::string s(str, end);
    theTimezone = s;
  }

public:
  std::vector<Variable>::const_iterator
  variablesBegin() const { return theVariables.begin(); }
  std::vector<Variable>::const_iterator
  variablesEnd() const { return theVariables.end(); }

  std::vector<std::string>::const_iterator
  errorsBegin() const { return theErrors.begin(); }
  std::vector<std::string>::const_iterator
  errorsEnd() const { return theErrors.end(); }

  size_t
  variablesSize() const { return theVariables.size(); }

  size_t
  errorsSize() const { return theErrors.size(); }

  bool hasDateSet() const {
    return theDate.size() != 0;
  }

  bool hasTimezoneSet() const {
    return theTimezone.size() != 0;
  }

  std::string getDate() const {
    return theDate;
  }

  std::string getTimezone() const {
    return theTimezone;
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

  bool parseFile(std::string str)
  {
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
      tokenize(*it, tokens, " ");
      for(lIter=tokens.begin(); lIter!=tokens.end(); ++lIter)
      {      
        if( *lIter == "Args:" )
        {
          for(++lIter;lIter!=tokens.end(); ++lIter)
          {
            if(*lIter != "-x"){ return false; }
            ++lIter;
            if(lIter->find(':') == std::string::npos){ setInline(); }
            if(lIter->find('=') == std::string::npos){ return false; }
            if( theInline ){
              setVarName(lIter->begin(), lIter->begin()+lIter->find('='));
            } else {
              setVarName(lIter->begin(), lIter->begin()+lIter->find(':'));
            }
            setVarValue(lIter->begin()+lIter->find("=")+1, lIter->end());
            addVariable();
          }
          break;
        } else if ( *lIter == "Error:" ) { 
          ++lIter;
          addError(lIter->begin(), lIter->end());
        } else if( *lIter == "Date:" ) {
          ++lIter;
          setDate( lIter->begin(), lIter->end() );
        } else if ( *lIter == "Timezone:" ) {
          ++lIter;
          setTimezone(lIter->begin(), lIter->end());
        } else if ( lIter->find("Error:") != std::string::npos ) {
          addError(lIter->begin()+lIter->find(":")+1, lIter->end());
        } else if ( lIter->find("Date:") != std::string::npos  ) {
          setDate(lIter->begin()+lIter->find(":")+1, lIter->end());
        } else if ( lIter->find("Timezone:") != std::string::npos ) {
          setTimezone(lIter->begin()+lIter->find(":")+1, lIter->end());
        } else {
          break;
        }
      }
    }
    return true;
  }
};
#endif
