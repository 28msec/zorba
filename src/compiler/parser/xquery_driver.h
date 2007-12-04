/**
 * @file xquery_driver.h
 * @author: Paul Pedersen
 * @copyright 2006-2007 FLWOR Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *	
 *    http://www.apache.org/licenses/LICENSE-2.0
 *	
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef XQP_XQUERY_DRIVER_H
#define XQP_XQUERY_DRIVER_H

#include <string>
#include <ostream>

#include "compiler/parser/symbol_table.h"
#include "compiler/parser/xquery_parser.hpp"
#include "types/representations.h"

using namespace yy;

/*
**	Flex expects the signature of yylex to be defined in the macro
**	YY_DECL, and the C++ parser expects it to be declared. We can
**	do both as follows. 
*/

// Announce to Flex the prototype we want for lexing function, ...
# define YY_DECL																				\
		yy::xquery_parser::token_type                      \
		yylex (	yy::xquery_parser::semantic_type* yylval,  \
						yy::xquery_parser::location_type* yylloc,  \
						xquery_driver& driver,                     \
            void* yyscanner)
            
// ... and declare it for the parser's sake.
YY_DECL;

namespace xqp {

extern  bool g_trace_scanning;
extern  bool g_trace_parsing;

/**
** Conducting the whole scanning and parsing of xquery.
*/
class xquery_driver
{
public:	// state
//  bool trace_scanning;
//  bool trace_parsing;
  xqp_string filename;
	xqp::symbol_table symtab;
	std::ostream& os;
	parsenode* expr_p;
	bool rename_bit;
	bool ftcontains_bit;

public:	
  xquery_driver(std::ostream&, uint32_t initial_heapsize = 1024);
  virtual ~xquery_driver();
  
public: // manipulators
//  void set_trace_scanning() { trace_scanning = true; }
//  void set_trace_parsing() { trace_parsing = true; }
//  bool get_trace_scanning() const { return trace_scanning; }
//  bool get_trace_parsing() const { return trace_parsing; }
	int get_debug() const { return debug; }
	void set_debug(int d) { debug = d; }
  xqp_string get_file() const { return filename; }
  std::ostream& get_os() { return os; }
	void set_expr(parsenode* e_p) { expr_p = e_p; }
	parsenode* get_expr() const { return expr_p; }

public:
	/**
	**	To encapsulate the coordination with the Flex scanner, it is useful to 
	**	have two members function to open and close the scanning phase. 
	**	members. 
	*/
  /*
  void scan_begin();
  void scan_end();
  */
  
	/**
	**	Parse the contents of a file
	*/
  void parse(const xqp_string fname);

	/**
	**	Parse directly the content of a string
	*/
	void parse_string( const char *query_string);

	/**
	**	For pure handling of parse errors, instead of simply dumping them on
	**	the standard error output, we will pass them to the compiler driver
	**	using the following two member functions.
	*/
	void error(yy::location const& l, std::string const& m);
	void error(std::string const& m);

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

};

}	/* namespace xqp */
#endif /* XQP_XQUERY_DRIVER_H */

