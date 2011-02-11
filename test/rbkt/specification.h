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
#include <sstream>
#include "util/ascii_util.h"
#include <testuriresolver.h>

#undef WIN32_LEAN_AND_MEAN

/**
 * Represents the contents of a testdriver-style .spec file.
 */
class Specification
{
  typedef char char_t;
  typedef std::string::iterator iterator_t;

public:
  struct Variable 
  {
    bool        theInline;
    std::string theVarName;
    std::string theVarValue;
  };

  struct Option
  {
    std::string theOptName;
    std::string theOptValue;
  };

  Specification()
    : theInline(false),
      theComparisonMethod("Fragment"),
      theSerializationMethod("XML"),
      theUseIndent(false),
      theEnableDtd(false),
      theEnableUriTestResolver(false)
  {}

private:
  bool                     theInline;
  std::string              theVarName;
  std::string              theVarValue;
  std::vector<Variable>    theVariables;
  std::vector<Option>      theOptions;
  std::vector<std::string> theResultFiles;
  std::vector<std::string> theErrors;
  std::string              theDate;
  std::string              theTimezone;
  std::string              theInputQueryFile;
  std::string              theComparisonMethod; // default is Fragment such that the user doesn't need to care about root tags for sequences etc
  std::string              theDefaultCollection;
  std::string              theSerializationMethod;//"XML" (default), "TXT"(for CSV testing)
  bool                     theUseIndent;
  bool                     theEnableDtd;
  bool                     theEnableUriTestResolver;
#ifndef ZORBA_NO_FULL_TEXT
  zorba::TestFullTextURIResolver  theStopWordsResolver;
  zorba::TestFullTextURIResolver  theThesaurusResolver;
#endif

  void setInline(bool inl) {
    theInline = inl;
  }

  void setVarName(iterator_t str, iterator_t end) {
    theVarName = std::string(str, end);
  }

  void setVarValue(iterator_t str, iterator_t end) {
    theVarValue = std::string(str, end);
  }

  void addVariable() {
    Variable var = { theInline, theVarName, theVarValue };
    theVariables.push_back(var);
  }

#ifndef ZORBA_NO_FULL_TEXT
  void addStopWords() {
    theStopWordsResolver.add_mapping(theVarName, theVarValue);
  }

  void addThesaurus() {
    theThesaurusResolver.add_mapping(theVarName, theVarValue);
  }
#endif

  void addOption() {
    Option opt = { theVarName, theVarValue };
    theOptions.push_back(opt);
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

  void setSerializationMethod(std::string ser_method)
  {
    theSerializationMethod = ser_method;
  }
  void setUseIndent() {
    theUseIndent = true;
  }

public:
  std::vector<Variable>::const_iterator
  variablesBegin() const { return theVariables.begin(); }

  std::vector<Variable>::const_iterator
  variablesEnd() const { return theVariables.end(); }

  std::vector<Option>::const_iterator
  optionsBegin() const { return theOptions.begin(); }

  std::vector<Option>::const_iterator
  optionsEnd() const { return theOptions.end(); }

  std::vector<std::string>::const_iterator
  errorsBegin() const { return theErrors.begin(); }

  std::vector<std::string>::const_iterator
  errorsEnd() const { return theErrors.end(); }

  std::vector<std::string>::const_iterator
  resultsBegin() const { return theResultFiles.begin(); }

  std::vector<std::string>::const_iterator
  resultsEnd() const { return theResultFiles.end(); }

  size_t
  variablesSize() const { return theVariables.size(); }

  size_t
  optionsSize() const { return theOptions.size(); }

  size_t
  errorsSize() const { return theErrors.size(); }

#ifndef ZORBA_NO_FULL_TEXT
  zorba::TestFullTextURIResolver*
  getThesaurusResolver() { return &theThesaurusResolver; }

  zorba::TestFullTextURIResolver*
  getStopWordsResolver() { return &theStopWordsResolver; }
#endif

  bool hasDateSet() const {
    return theDate.size() != 0;
  }

  bool hasTimezoneSet() const {
    return theTimezone.size() != 0;
  }

  bool hasInputQuery () const {
    return theInputQueryFile.size() != 0;
  }

  const std::string & getInputQueryFile () const {
    return theInputQueryFile;
  }

  std::string getDate() const {
    return theDate;
  }

  std::string getTimezone() const {
    return theTimezone;
  }

  std::string getComparisonMethod() const {
    return theComparisonMethod;
  }

  std::string getDefaultCollection() const {
    return theDefaultCollection;
  }

  std::string getSerializationMethod()
  {
    return theSerializationMethod;
  }
  bool getUseIndent() const {
    return theUseIndent;
  }

  bool getEnableDtd() const {
    return theEnableDtd;
  }

  bool getEnableUriTestResolver() const {
    return theEnableUriTestResolver;
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

  void trim(std::string& str) {
    std::string::size_type  notwhite = str.find_first_not_of(" \t\n\r");
    str.erase(0,notwhite);

    notwhite = str.find_last_not_of(" \t\n\r"); 
    str.erase(notwhite+1); 
  }

  bool parseFile(std::string str, std::string rbkt_src_dir,
    std::string rbkt_binary_dir)
  {
    std::ifstream lFile(str.c_str(), std::ifstream::in);
    std::stringstream lContent;
    char c = (char)lFile.get();
    while(lFile.good()) {
      lContent << c;
      c = (char)lFile.get();
    }
    lFile.close();

    std::vector<std::string> lines;
    std::vector<std::string>::iterator it;

    tokenize(lContent.str(), lines, "\n");
    theEnableDtd = false;

    for(it = lines.begin(); it != lines.end(); ++it)
    {
      // Replace $RBKT_SRC_DIR and $RBKT_BINARY_DIR
      zorba::ascii::replace_all(*it, "$RBKT_SRC_DIR", rbkt_src_dir);
      zorba::ascii::replace_all(*it, "$RBKT_BINARY_DIR", rbkt_binary_dir);

      std::vector<std::string> tokens;
      std::vector<std::string>::iterator lIter;
      trim(*it);

      tokenize(*it, tokens, " ");

      for(lIter = tokens.begin(); lIter != tokens.end(); ++lIter)
      {
        if( *lIter == "Args:" )
        {
          for(++lIter; lIter!=tokens.end(); ++lIter)
          {
            std::string lArg = *lIter;
            if ( (lArg == "-x") ||
              (lArg == "--stop-words") || (lArg == "--thesaurus") )
            {
              // Argument binding and stop-words/thesaurus URI binding are
              // very similar, so use the same code path for most of it.
              ++lIter;
              if(lIter->find(":=") == std::string::npos) {
                setInline(true);
              }
              else if(lIter->find('=') == std::string::npos) {
                return false;
              }
              else {
                setInline(false);
              }
              if( theInline ) {
                setVarName(lIter->begin(), lIter->begin()+lIter->find('='));
              } else {
                setVarName(lIter->begin(), lIter->begin()+lIter->find(":="));
              }
              setVarValue(lIter->begin()+lIter->find("=")+1, lIter->end());
              if (lArg == "-x") {
                addVariable();
              }
#ifndef ZORBA_NO_FULL_TEXT
              else if (lArg == "--stop-words") {
                addStopWords();
              }
              else if (lArg == "--thesaurus") {
                addThesaurus();
              }
#endif
            }
            else if (lArg == "--enable-dtd")
            {
              theEnableDtd = true;
            }
            else if (lArg == "--enable-uritestresolver")
            {
              theEnableUriTestResolver = true;
            }
            else
            {
              return false;
            }
          }
          break;
        }
        else if ( *lIter == "Options:" )
        {
          for (++lIter; lIter != tokens.end(); ++lIter)
          {
            if (lIter->find('=') == std::string::npos) { return false; }
            // Re-use existing setVarName/Value stuff
            setVarName(lIter->begin(), lIter->begin() + lIter->find('='));
            setVarValue(lIter->begin() + lIter->find('=') + 1, lIter->end());
            addOption();
          }
          break;
        }
        else if ( *lIter == "Serialization:" )
        {
          for(++lIter; lIter!=tokens.end(); ++lIter)
          {
            trim(*lIter);
            // Just --indent for now
            if (*lIter == "--indent") {
              setUseIndent();
            } else if(*lIter == "--method") {
              ++lIter;
              theSerializationMethod = *lIter;
              if(theSerializationMethod == "TXT")
                theComparisonMethod = "Text";
            } else {
              return false;
            }
          }
          break;
        }
        else if ( *lIter == "Result:" ) 
        {
          for (++lIter; lIter != tokens.end(); ++lIter)
          {
            trim(*lIter);
            theResultFiles.push_back(*lIter);
          }
          break;
        }
        else if ( *lIter == "InputQuery:" ) 
        {
          ++lIter;
          theInputQueryFile = *lIter;
        }
        else if ( *lIter == "Comparison:" ) 
        {
          ++lIter;
          theComparisonMethod = *lIter;
        }
        else if ( *lIter == "DefaultCollection:" ) 
        {
          ++lIter;
          theDefaultCollection = *lIter;
        }
        else if ( *lIter == "Error:" ) 
        { 
          ++lIter;
          if(lIter == tokens.end() ) { return false; }
          addError(lIter->begin(), lIter->end());
        }
        else if( *lIter == "Date:" ) 
        {
          ++lIter;
          if(lIter == tokens.end() ) { return false; }
          setDate( lIter->begin(), lIter->end() );
        }
        else if ( *lIter == "Timezone:" ) 
        {
          ++lIter;
          if(lIter == tokens.end() ) { return false; }
          setTimezone(lIter->begin(), lIter->end());
        }
        else if ( lIter->find("Error:") != std::string::npos ) 
        {
          addError(lIter->begin()+lIter->find(":")+1, lIter->end());
        }
        else if ( lIter->find("Date:") != std::string::npos  ) 
        {
          setDate(lIter->begin()+lIter->find(":")+1, lIter->end());
        }
        else if ( lIter->find("Timezone:") != std::string::npos ) 
        {
          setTimezone(lIter->begin()+lIter->find(":")+1, lIter->end());
        }
        else
        {
          break;
        }
      }
    }
    return true;
  }
};
#endif
