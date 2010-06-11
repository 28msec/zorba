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


#ifdef _WIN32
  // Include the NOMINMAX definition before windwows.h is included,
  // so that min and max macros are not defined, and std::max and std::min
  // uses do not generate errors on Windows.
#define NOMINMAX
#endif


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
#include "zorbaerrors/error_manager.h"

namespace zorba
{

ZorbaParserError::ZorbaParserError(std::string _msg, const location& aLoc)
  :
  msg(_msg), loc(xquery_driver::createQueryLoc(aLoc))
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

  parserError = new ZorbaParserError("syntax error, unexpected character '" + token + "'", loc);
  return parserError;
};

ZorbaParserError* xquery_driver::unterminatedCommentErr(const location& loc)
{
  parserError = new ZorbaParserError("syntax error, unexpected end of file, unterminated comment", loc);
  return parserError;
}

ZorbaParserError* xquery_driver::unrecognizedToken(const char* _error_token, const location& loc)
{
  parserError = new ZorbaParserError(std::string("syntax error, unexpected '") + _error_token + "'", loc);
  return parserError;
}

ZorbaParserError* xquery_driver::unrecognizedIntegerErr(const char* _error_token, const location& loc)
{
  parserError = new ZorbaParserError(std::string("syntax error, unexpected '") + _error_token + "', separator needed after numeric literal", loc);
  return parserError;
}

bool xquery_driver::parse_stream(std::istream& in, const xqpString& aFilename)
{
  int ch[3];

  theFilename = aFilename;

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

bool xquery_driver::parse_file(const xqpString& aFilename)
{
  std::ifstream in(aFilename.c_str());
  return parse_stream(in, aFilename);
}

bool xquery_driver::parse_string(const xqpString& input)
{
  std::istringstream iss(input);
  return parse_stream(iss);
}

void xquery_driver::set_expr(parsenode* e_p)
{
  if (theCompilerCB->theConfig.parse_cb != NULL)
    theCompilerCB->theConfig.parse_cb(e_p, theCompilerCB->theRootSctx->get_entity_retrieval_uri()->str());
  expr_p = e_p;
}

QueryLoc xquery_driver::createQueryLoc(const zorba::location& aLoc)
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
