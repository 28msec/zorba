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

#include <boost/spirit.hpp>
#include <boost/bind.hpp>

class Specification
{
  typedef char char_t;
  typedef boost::spirit::file_iterator <char_t> iterator_t;
  typedef boost::spirit::scanner<iterator_t> scanner_t;
  typedef boost::spirit::rule<scanner_t> rule_t;

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

  void setInline(iterator_t, iterator_t) {
    theInline = true;
  }

  void setVarName(iterator_t str, iterator_t end) {
    theVarName = std::string(str, end);
  }

  void setVarValue(iterator_t str, iterator_t end) {
    theVarValue = std::string(str, end);
  }

  void addVariable(iterator_t str, iterator_t end) {
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
  variablesBegin() { return theVariables.begin(); }
  std::vector<Variable>::const_iterator
  variablesEnd()   { return theVariables.end(); }

  std::vector<std::string>::const_iterator
  errorsBegin() { return theErrors.begin(); }
  std::vector<std::string>::const_iterator
  errorsEnd()    { return theErrors.end(); }

  size_t
  variablesSize() { return theVariables.size(); }

  size_t
  errorsSize() { return theErrors.size(); }

  bool hasDateSet() {
    return theDate.size() != 0;
  }

  bool hasTimezoneSet() {
    return theTimezone.size() != 0;
  }

  std::string getDate() {
    return theDate;
  }

  std::string getTimezone() {
    return theTimezone;
  }


  bool
  parseFile(std::string str)
  {
    rule_t props
      = (+(boost::spirit::graph_p & ~boost::spirit::ch_p(':') & ~boost::spirit::ch_p('=')))[bind(&Specification::setVarName, this, _1, _2)]
      >> boost::spirit::str_p("=")[bind(&Specification::setInline, this, _1, _2)]
      >> (+boost::spirit::graph_p)[bind(&Specification::setVarValue, this, _1, _2)];

    rule_t propsInline
      = (+(boost::spirit::graph_p & ~boost::spirit::ch_p(':') & ~boost::spirit::ch_p('=')))[bind(&Specification::setVarName, this, _1, _2)]
      >> boost::spirit::str_p(":=") 
      >> (+boost::spirit::graph_p)[bind(&Specification::setVarValue, this, _1, _2)];
    
    rule_t argument 
      =  boost::spirit::str_p("Args:") 
      >> +(
            boost::spirit::blank_p
         && boost::spirit::str_p("-x")
         && boost::spirit::blank_p
         && (props | propsInline)[bind(&Specification::addVariable, this, _1, _2)]
         )
      >> !boost::spirit::eol_p;

    rule_t error  
      =  boost::spirit::str_p("Error:") 
      >> !boost::spirit::blank_p
      >> (*boost::spirit::print_p)[bind(&Specification::addError, this, _1, _2)] 
      >> !boost::spirit::eol_p;

    rule_t date
      =  boost::spirit::str_p("Date:") 
      >> !boost::spirit::blank_p
      >> (*boost::spirit::print_p)[bind(&Specification::setDate, this, _1, _2)] 
      >> !boost::spirit::eol_p;
    rule_t timezone
      =  boost::spirit::str_p("Timezone:") 
      >> !boost::spirit::blank_p
      >> (*boost::spirit::print_p)[bind(&Specification::setTimezone, this, _1, _2)] 
      >> !boost::spirit::eol_p;

    rule_t defs = *( argument | error | date | timezone );

    iterator_t first(str.c_str());
    if (!first)
      return false;

    iterator_t last = first.make_end();

    return boost::spirit::parse(first, last, defs).full; 
  }
};
#endif
