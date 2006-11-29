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

#include "symbol_table.h"
#include "xquery_parser.tab.h"

/*
	Flex expects the signature of yylex to be defined in the macro
	YY_DECL, and the C++ parser expects it to be declared. We can
	do both as follows. 
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

public:	
  xquery_driver(uint32_t initial_heapsize = 1024);
  virtual ~xquery_driver();

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

};

#endif /* XQP_XQUERY_DRIVER_H */

