#ifndef XQP_XQUERY_DRIVER_H
#define XQP_XQUERY_DRIVER_H

#include <ostream>
#include <zorbatypes/xqpstring.h>
#include "compiler/parser/symbol_table.h"

namespace xqp {

class location;
class parsenode;

class xquery_driver
{
public:
  xqpString theFilename;
  xqp::symbol_table symtab;
  parsenode* expr_p;
  bool rename_bit;
  bool ftcontains_bit;

  xquery_driver(uint32_t initial_heapsize = 1024);
  virtual ~xquery_driver() {}

  bool 
  parse_stream(std::istream& in, const xqpString& aFilename = "");

  bool 
  parse_string(const xqpString& input);

  bool 
  parse_file(const xqpString& aFilename);

  void 
  error(const xqp::location& l, const std::string& m);

  void 
  error(const std::string& m);

	void set_expr(parsenode* e_p) { expr_p = e_p; }
	parsenode* get_expr() const { return expr_p; }

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

  QueryLoc createQueryLoc(const xqp::location& aLoc);

  class xquery_scanner* lexer;
};

}	/* namespace xqp */
#endif /* XQP_XQUERY_DRIVER_H */

