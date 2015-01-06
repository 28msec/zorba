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
#include <util/ascii_util.h>
#include <zorba/util/uri.h>
#include "testuriresolver.h"
#include <zorba/uri_resolvers.h>

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

public:
  Specification()
    :
    theInline(false),
    theComparisonMethod("Fragment"),
    theEnableDtd(false),
    theEnableUriTestResolver(false)
#ifndef ZORBA_NO_FULL_TEXT
    ,
    theStopWordsMapper(zorba::EntityData::STOP_WORDS),
    theThesaurusMapper(zorba::EntityData::THESAURUS)
#endif /* ZORBA_NO_FULL_TEXT */
  {
  }

private:
  bool                     theInline;
  std::string              theVarName;
  std::string              theVarValue;
  std::vector<Variable>    theVariables;
  std::vector<Option>      theOptions;
  std::vector<Option>      theSerializerOptions;
  std::vector<std::string> theResultFiles;
  std::vector<std::string> theErrors;
  std::string              theDate;
  std::string              theTimezone;
  std::string              theInputQueryFile;
  std::string              theComparisonMethod; // default is Fragment such that the user doesn't need to care about root tags for sequences etc
  std::string              theDefaultCollection;
  bool                     theUseIndent;
  bool                     theEnableDtd;
  bool                     theEnableUriTestResolver;
#ifndef ZORBA_NO_FULL_TEXT
  zorba::OneToOneURIMapper theStopWordsMapper;
  zorba::OneToOneURIMapper theThesaurusMapper;
#endif /* ZORBA_NO_FULL_TEXT */

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
  void addStopWordMapping() {
    zorba::String lUri = zorba::URIHelper::encodeFileURI(theVarValue);
    theStopWordsMapper.addMapping(theVarName, lUri);
  }

  void addThesaurusMapping() {
    theThesaurusMapper.addMapping(theVarName, theVarValue);
  }
#endif

  void addOption() {
    Option opt = { theVarName, theVarValue };
    theOptions.push_back(opt);
  }

  void addSerializerOption() {
    Option opt = { theVarName, theVarValue };
    theSerializerOptions.push_back(opt);
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

  std::vector<Option>::const_iterator
  optionsBegin() const { return theOptions.begin(); }

  std::vector<Option>::const_iterator
  optionsEnd() const { return theOptions.end(); }

  std::vector<Option>::const_iterator
  serializerOptionsBegin() const { return theSerializerOptions.begin(); }

  std::vector<Option>::const_iterator
  serializerOptionsEnd() const { return theSerializerOptions.end(); }

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
  serializerOptionsSize() const { return theSerializerOptions.size(); }

  size_t
  errorsSize() const { return theErrors.size(); }

#ifndef ZORBA_NO_FULL_TEXT
  zorba::OneToOneURIMapper*
  getThesaurusMapper() { return &theThesaurusMapper; }

  zorba::OneToOneURIMapper*
  getStopWordsMapper() { return &theStopWordsMapper; }
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

    // Discriminate when items are between () and "", precedence for (
    std::string::size_type posBracket = str.find_first_of("(", lastPos);
    if (posBracket<pos)
    {
      posBracket = str.find_first_of(")", lastPos);
      pos = str.find_first_of(delimiters, posBracket);  //New position after )
    }
    std::string::size_type posQuotes = str.find_first_of("\"", lastPos);
    if (posQuotes<pos)
    {
      posQuotes = str.find_first_of("\"", posQuotes+1);
      pos = str.find_first_of(delimiters, posQuotes);  //New position after second "
    }

    while (std::string::npos != pos || std::string::npos != lastPos)
    {
      // Found a token, add it to the vector.
      tokens.push_back(str.substr(lastPos, pos - lastPos));
      // Skip delimiters.  Note the "not_of"
      lastPos = str.find_first_not_of(delimiters, pos);
      // Find next "non-delimiter"
      pos = str.find_first_of(delimiters, lastPos);

    // Discriminate when items are between () and "", precedence for (
      if (posBracket<pos) {
        posBracket = str.find_first_of(")", lastPos);
        pos = str.find_first_of(delimiters, posBracket);  //New position after ")"
        posBracket = str.find_first_of("(", posBracket);
      }
      if (posQuotes<pos)
      {
        posQuotes = str.find_first_of("\"", posQuotes+1);
        pos = str.find_first_of(delimiters, posQuotes);  //New position after second "
        posQuotes = str.find_first_of("\"", posQuotes+1);
      }

    }
  }

  void trim(std::string& str) {
    std::string::size_type  notwhite = str.find_first_not_of(" \t\n\r");
    str.erase(0,notwhite);

    notwhite = str.find_last_not_of(" \t\n\r"); 
    str.erase(notwhite+1); 
  }

  void trim(std::string& str, const std::string& toTrim) {
    std::string::size_type  notwhite = str.find_first_not_of(toTrim);
    str.erase(0,notwhite);

    notwhite = str.find_last_not_of(toTrim); 
    str.erase(notwhite+1); 
  }

  bool isKeyword(std::string& str) 
  {
    bool c = ((str.find("Args:")!=std::string::npos) ||
              (str.find("Options:")!=std::string::npos) || 
              (str.find("Serialization:")!=std::string::npos) || 
              (str.find("Result:")!=std::string::npos) || 
              (str.find("InputQuery:")!=std::string::npos) || 
              (str.find("Comparison:")!=std::string::npos) || 
              (str.find("DefaultCollection:")!=std::string::npos) ||
              (str.find("Error:")!=std::string::npos) || 
              (str.find("Date:")!=std::string::npos) || 
              (str.find("Timezone:")!=std::string::npos));
    return c;
  }

  bool parseFile(std::string str, std::string rbkt_src_dir, 
    std::string rbkt_src_dir_uri, std::string rbkt_bin_dir,
	std::string rbkt_bin_dir_uri)
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

    std::string one_space(" ");
    for(it = lines.begin(); it != lines.end(); ++it)
    {
      zorba::ascii::replace_all(*it, "$RBKT_SRC_DIR_URI", one_space + rbkt_src_dir_uri);
      zorba::ascii::replace_all(*it, "$RBKT_SRC_DIR", one_space + rbkt_src_dir);
	  zorba::ascii::replace_all(*it, "$RBKT_BIN_DIR_URI", rbkt_bin_dir_uri);
	  zorba::ascii::replace_all(*it, "$RBKT_BIN_DIR", rbkt_bin_dir);

      std::vector<std::string> tokens;
      std::vector<std::string>::iterator lIter;
      trim(*it);

      tokenize(*it, tokens, " ");

      for(lIter = tokens.begin(); lIter != tokens.end(); ++lIter)
      {
        if( *lIter == "Args:" )
        {
          for(++it; (it!=lines.end()) &&  !isKeyword(*it); ++it)
          {
            zorba::ascii::replace_all(*it, "$RBKT_SRC_DIR_URI", rbkt_src_dir_uri);
            zorba::ascii::replace_all(*it, "$RBKT_SRC_DIR", rbkt_src_dir);            
			zorba::ascii::replace_all(*it, "$RBKT_BIN_DIR_URI", rbkt_bin_dir_uri);
			zorba::ascii::replace_all(*it, "$RBKT_BIN_DIR", rbkt_bin_dir);
            trim(*it);
            std::string lArg = *it;
            if ( (lArg == "-x") ||
              (lArg == "--stop-words") || (lArg == "--thesaurus") )
            {
              // Argument binding and stop-words/thesaurus URI binding are
              // very similar, so use the same code path for most of it.
              it++;
              zorba::ascii::replace_all(*it, "$RBKT_SRC_DIR_URI", rbkt_src_dir_uri);
              zorba::ascii::replace_all(*it, "$RBKT_SRC_DIR", rbkt_src_dir);
			  zorba::ascii::replace_all(*it, "$RBKT_BIN_DIR_URI", rbkt_bin_dir_uri);
			  zorba::ascii::replace_all(*it, "$RBKT_BIN_DIR", rbkt_bin_dir);
              trim(*it);
              if(it->find(":=") == std::string::npos) {
                setInline(true);
              }
              else if(it->find('=') == std::string::npos) {
                return false;
              }
              else {
                setInline(false);
              }
              if( theInline ) {
                setVarName(it->begin(), it->begin()+it->find('='));
              } else {
                setVarName(it->begin(), it->begin()+it->find(":="));
              }
              setVarValue(it->begin()+it->find("=")+1, it->end());
              if (lArg == "-x") {
                addVariable();
              }
#ifndef ZORBA_NO_FULL_TEXT
              else if (lArg == "--stop-words") {
                addStopWordMapping();
              }
              else if (lArg == "--thesaurus") {
                addThesaurusMapping();
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
          it--;
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
          for(++lIter; lIter != tokens.end(); ++lIter)
          {
            trim(*lIter);
            std::string opt(*lIter);
            // Have to translate "old-style" --indent and --method options, because
            // some non-core module tests use them. Deprecated.
            if (opt == "--indent") {
              opt = "indent=yes";
              // Fall through to new-style code below
            } else if(*lIter == "--method") {
              opt = "method=";
              std::string lMethod = *(++lIter);

              if (lMethod == "TXT") {
                // --method TXT implies "Text" comparison and "text" serialization
                theComparisonMethod = "Text";
                opt.append("text");
              }
              else {
                opt.append(lMethod);
              }
              // Fall through to new-style code below
            } else if (lIter->find('=') == std::string::npos) {
              return false;
            }
            // Now, handle the "new-style" opt=value options. Re-use existing
            // setVarName/Value stuff.
            setVarName(opt.begin(), opt.begin() + opt.find('='));
            setVarValue(opt.begin() + opt.find('=') + 1, opt.end());
            addSerializerOption();
          }
          break;
        }
        else if ( *lIter == "Result:" ) 
        {
          for (++lIter; lIter != tokens.end(); ++lIter)
          {
            trim(*lIter," \t\n\r\"");
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
        else if ( lIter->length() && (*lIter)[0] == '#')
        {
          break;
        }
        else
        {
          return false;
        }
      }
    }
    return true;
  }
};
#endif
