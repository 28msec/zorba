/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: xquery_driver.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 */

#ifndef XQP_XQUERY_DRIVER_H
#define XQP_XQUERY_DRIVER_H

#include <string>
#include <ostream>

#include "../context/context.h"
#include "symbol_table.h"
#include "xquery_parser.tab.h"

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
						xquery_driver& driver)

// ... and declare it for the parser's sake.
YY_DECL;


/**
** Conducting the whole scanning and parsing of xquery.
*/
class xquery_driver
{
public:	// state
  bool trace_scanning;
  bool trace_parsing;
  std::string file;
	xqp::symbol_table symtab;
	std::ostream& os;
	context ctx;

	bool rename_bit;
	bool ftcontains_bit;

public:	
  xquery_driver(std::ostream&, uint32_t initial_heapsize = 1024);
  virtual ~xquery_driver();
  
public: // manipulators
  void set_trace_scanning() { trace_scanning = true; }
  void set_trace_parsing() { trace_parsing = true; }
  bool get_trace_scanning() const { return trace_scanning; }
  bool get_trace_parsing() const { return trace_parsing; }
  
  std::string get_file() const { return file; }
  std::ostream& get_os() { return os; }
  context const* get_ctx() { return &ctx; }

public:
	/**
	**	To encapsulate the coordination with the Flex scanner, it is useful to 
	**	have two members function to open and close the scanning phase. 
	**	members. 
	*/
  void scan_begin();
  void scan_end();

	/**
	**	Similarly for the parser itself.
	*/
  void parse(const std::string& fname);

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

#endif /* XQP_XQUERY_DRIVER_H */

