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
#pragma once
#ifndef ZORBA_XQUERY_DRIVER_H
#define ZORBA_XQUERY_DRIVER_H

#include <ostream>
#include <string>
#include <zorba/config.h>
#include "compiler/parser/symbol_table.h"

// needed because we have to delete the main module node
#include "compiler/parsetree/parsenode_base.h"

namespace zorba {

class location;
class parsenode;
class CompilerCB;


class ZorbaParserError
{
public:
  std::string msg;
  QueryLoc loc;
  Error const &err_code;

public:
  ZorbaParserError(std::string _msg, Error const &code = err::XPST0003);
  ZorbaParserError(std::string _msg, const location& aLoc, Error const &code = err::XPST0003);
  ZorbaParserError(std::string _msg, const QueryLoc& aLoc, Error const &code = err::XPST0003);
};


// exported for unit testing only
class ZORBA_DLL_PUBLIC xquery_driver
{
public:
  std::stringstream theDocComment;
  std::string theMainModuleDocComment;
  zstring theFilename;
  std::string theFilename2;
  symbol_table symtab;
  rchandle<parsenode> expr_p;
  CompilerCB* theCompilerCB;
  ZorbaParserError* parserError;
  class xquery_scanner* lexer;

  xquery_driver(CompilerCB* aCompilerCB, uint32_t initial_heapsize = 1024);

  virtual ~xquery_driver();

  bool parse_stream(std::istream& in, const zstring& aFilename = "");

  bool parse_string(const zstring& input);

  bool parse_file(const zstring& aFilename);

	void set_expr(parsenode* e_p);

	parsenode* get_expr() { return expr_p; }

  QueryLoc createQueryLoc(const location& aLoc) const;

  // Error generators
  ZorbaParserError* unrecognizedCharErr(const char* _error_token, const location& loc);
  ZorbaParserError* unterminatedCommentErr(const location& loc);
  ZorbaParserError* unterminatedElementConstructor(const location& loc);
  ZorbaParserError* noClosingTagForElementConstructor(const location& loc);
  ZorbaParserError* unrecognizedToken(const char* _error_token, const location& loc);
  ZorbaParserError* invalidCharRef(const char* _error_token, const location& loc);
  ZorbaParserError* parserErr(const std::string& _message, const location& loc, Error const &code = err::XPST0003);
  ZorbaParserError* parserErr(const std::string& _message, const QueryLoc& loc, Error const &code = err::XPST0003);

public:
  // transform a parser location into a QueryLoc
  static QueryLoc createQueryLocStatic(const location& aLoc);
};

}	/* namespace zorba */
#endif /* ZORBA_XQUERY_DRIVER_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
