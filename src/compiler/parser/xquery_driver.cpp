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

#include <fstream>
#include "system/properties.h"
#include "compiler/parser/xquery_driver.h"

#ifdef __GNUC__
  // disable a warning in location.hh which comes with bison
  // position.hh:141: warning: suggest parentheses around && within ||
#  pragma GCC diagnostic ignored "-Wparentheses"
#endif

#include "compiler/parser/xquery_scanner.h"
#include "compiler/parser/xquery_parser.hpp"

#ifdef __GNUC__
#  pragma GCC diagnostic warning "-Wparentheses"
#endif

#include "compiler/api/compilercb.h"
#include "context/static_context.h"
#include "diagnostics/xquery_diagnostics.h"
#include "util/xml_util.h"

namespace zorba
{

ZorbaParserError::ZorbaParserError(std::string _msg, Error const &code)
  :
  msg(_msg), err_code(code)
{
}

ZorbaParserError::ZorbaParserError(std::string _msg, const location& aLoc, Error const &code)
  :
  msg(_msg), loc(xquery_driver::createQueryLocStatic(aLoc)), err_code(code)
{
}

ZorbaParserError::ZorbaParserError(std::string _msg, const QueryLoc& aLoc, Error const &code)
  :
  msg(_msg), loc(aLoc), err_code(code)
{
}

xquery_driver::xquery_driver(CompilerCB* aCompilerCB, uint32_t initial_heapsize)
  :
  symtab(initial_heapsize),
  expr_p (NULL),
  theCompilerCB(aCompilerCB),
  parserError(NULL)
{
}

xquery_driver::~xquery_driver()
{
  if (parserError)
    delete parserError;
}

// Error generators
ZorbaParserError* xquery_driver::unrecognizedCharErr(const char* _error_token, const location& loc)
{
  std::string token;
    // translate some common non-printable characters for better readability.
  if (*_error_token == '\t')
    token = "\\t";
  else if (*_error_token == '\n')
    token = "\\n";
  else if (*_error_token == '\r')
    token = "\\r";
  else if (*_error_token == ' ')
    token = "<blank>";
  else
    token = _error_token;

  parserError = new ZorbaParserError("syntax error, unexpected character \"" + token + "\"", loc);
  return parserError;
};

ZorbaParserError* xquery_driver::unterminatedCommentErr(const location& loc)
{
  parserError = new ZorbaParserError("syntax error, unexpected end of file, unterminated comment", loc);
  return parserError;
}

ZorbaParserError* xquery_driver::unterminatedElementConstructor(const location& loc)
{
  parserError = new ZorbaParserError("syntax error, unexpected end of file, unterminated direct element constructor", loc);
  return parserError;
}

ZorbaParserError* xquery_driver::noClosingTagForElementConstructor(const location& loc)
{
  parserError = new ZorbaParserError("syntax error, unexpected end of file, no closing tag for direct element constructor", loc);
  return parserError;
}

ZorbaParserError* xquery_driver::unrecognizedToken(const char* _error_token, const location& loc)
{
  parserError = new ZorbaParserError(std::string("syntax error, unexpected \"") + _error_token + "\"", loc);
  return parserError;
}

ZorbaParserError* xquery_driver::invalidCharRef(const char* _message, const location& loc)
{
  std::string ref = "";
  std::string temp = _message;
  std::string out;
  temp = temp.substr(temp.find("&"));

  while (temp.size()>0 && xml::parse_entity(temp, &out) != -1)
  {
    temp = temp.substr(temp.find(";") + 1);
    if (temp.find("&") != std::string::npos)
      temp = temp.substr(temp.find("&"));
  }

  if (temp.find("&") != std::string::npos)
  {
    ref = "\"" + temp.substr(temp.find("&"), 6);
    if (temp.size() == 7)
      ref += "\"";
    else if (temp.size() > 7)
      ref += "...\"";
    ref += " ";
  }

  parserError = new ZorbaParserError(std::string("syntax error, invalid character or entity reference "
      + ref + "in the string literal ") + _message + ".", loc);
  return parserError;
}


ZorbaParserError* xquery_driver::parserErr(const std::string& _message, const location& loc, Error const &code)
{
  parserError = new ZorbaParserError(_message, loc, code);
  return parserError;
}

ZorbaParserError* xquery_driver::parserErr(const std::string& _message, const QueryLoc& loc, Error const &code)
{
  parserError = new ZorbaParserError(_message, loc, code);
  return parserError;
}


bool xquery_driver::parse_stream(std::istream& in, const zstring& aFilename)
{
  int ch[3];

  theFilename = aFilename;
  theFilename2 = theFilename.str();

  // process the UTF16 Byte Order Mark = \xEF\xBB\xBF
  if (in.peek() == 0xEF)
  {
    int i;
    for (i=0; i<3; i++)
      if (in.good())
        ch[i] = in.get();
      else
        break;

    if (i<3 || ch[0] != 0xEF || ch[1] != 0xBB || ch[2] != 0xBF)
    {
      if (i==3) i--;
      for ( ; i>=0; i--)
        in.putback(ch[i]);
    }
  }

  // process the UTF16 (LE) Byte Order Mark = \xFF\xFE, not supported yet
  //else if (in.peek() == 0xFF)
  //{
    // transcode the input to UTF8
  //}

  xquery_scanner scanner(this, &in);
  scanner.set_yy_flex_debug(Properties::instance()->traceScanning());
  this->lexer = &scanner;
  // scanner.set_yy_flex_debug(true); // debugging purposes

  xquery_parser parser(*this);
  parser.set_debug_level(Properties::instance()->traceParsing());
  // parser.set_debug_level(true); // debugging purposes

  return (parser.parse() == 0);
}

bool xquery_driver::parse_file(const zstring& aFilename)
{
  std::ifstream in(aFilename.c_str());
  return parse_stream(in, aFilename);
}

bool xquery_driver::parse_string(const zstring& input)
{
  std::istringstream iss(input.str());
  return parse_stream(iss);
}

void xquery_driver::set_expr(parsenode* e_p)
{
  if (theCompilerCB->theConfig.parse_cb != NULL)
  {
    zstring uri;
    theCompilerCB->theRootSctx->get_entity_retrieval_uri(uri);
    theCompilerCB->theConfig.parse_cb(e_p, uri.str());
  }
  expr_p = e_p;
}

QueryLoc xquery_driver::createQueryLoc(const location& aLoc) const
{
  QueryLoc lLoc;
  lLoc.setFilename(theFilename);
  lLoc.setLineBegin(aLoc.begin.line);
  lLoc.setColumnBegin(aLoc.begin.column);
  lLoc.setLineEnd(aLoc.end.line);
  lLoc.setColumnEnd(aLoc.end.column);
  return lLoc;
}

QueryLoc xquery_driver::createQueryLocStatic(const location& aLoc)
{
  QueryLoc lLoc;
  lLoc.setFilename(aLoc.begin.filename->c_str());
  lLoc.setLineBegin(aLoc.begin.line);
  lLoc.setColumnBegin(aLoc.begin.column);
  lLoc.setLineEnd(aLoc.end.line);
  lLoc.setColumnEnd(aLoc.end.column);
  return lLoc;
}

}	/* namespace zorba */
/* vim:set et sw=2 ts=2: */
