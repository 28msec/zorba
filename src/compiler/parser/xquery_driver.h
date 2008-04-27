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
#ifndef ZORBA_XQUERY_DRIVER_H
#define ZORBA_XQUERY_DRIVER_H

#include <ostream>
#include "zorbatypes/xqpstring.h"

#include "compiler/parser/symbol_table.h"

// needed because we have to delete the main module node
#include "compiler/parsetree/parsenodes.h"

namespace zorba {

class location;
class parsenode;
class CompilerCB;

class xquery_driver
{
public:
  std::string theFilename;
  symbol_table symtab;
  rchandle<parsenode> expr_p;
  bool rename_bit;
  bool ftcontains_bit;
  CompilerCB* theCompilerCB;

  xquery_driver(CompilerCB* aCompilerCB, uint32_t initial_heapsize = 1024);
  virtual ~xquery_driver() {}

  bool parse_stream(std::istream& in, const xqpString& aFilename = "");

  bool parse_string(const xqpString& input);

  bool parse_file(const xqpString& aFilename);

  void error(const location& l, const std::string& m);

  void error(const std::string& m);

	void set_expr(parsenode* e_p) { expr_p = e_p; }
	parsenode* get_expr() { return expr_p; }

	/**
	**	Deal with "as" operator overloading for update
	*/
	void set_rename(bool b) { rename_bit = b; }
	bool rename() const { return rename_bit; }


	/**
	**	Deal with operator overloading for ft
	*/
	void set_ftcontains(bool b) { ftcontains_bit = b; }
	bool ftcontains() const { return ftcontains_bit; }

  QueryLoc createQueryLoc(const location& aLoc);

  class xquery_scanner* lexer;
};

}	/* namespace zorba */
#endif /* ZORBA_XQUERY_DRIVER_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
