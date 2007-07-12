/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
*
 *  $Id: function_library.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Authors: John Cowan,Paul Pedersen
 *
 */

#ifndef XQP_LIBRARY_H
#define XQP_LIBRARY_H

#include "context/common.h"
#include "util/fxhashmap.h"
#include <string>

namespace xqp {

class function;
class value_factory;
class zorba;

class library : public rcobject
{
protected:
	zorba* zorp;
	fxhash64map<const function*> funtab;

public:
	// Numeric functions
	static qnamekey_t op_add_key;
	static qnamekey_t op_subtract_key;
  static qnamekey_t op_mul_key;
  static qnamekey_t op_div_key;
  static qnamekey_t op_idiv_key;
  static qnamekey_t op_mod_key;

	// comparison operators
	static qnamekey_t op_eq_key;
	static qnamekey_t op_ne_key;
	static qnamekey_t op_lt_key;
	static qnamekey_t op_le_key;
	static qnamekey_t op_gt_key;
	static qnamekey_t op_ge_key;
	static qnamekey_t op_val_eq_key;
	static qnamekey_t op_val_ne_key;
	static qnamekey_t op_val_lt_key;
	static qnamekey_t op_val_le_key;
	static qnamekey_t op_val_gt_key;
	static qnamekey_t op_val_ge_key;
	static qnamekey_t op_is_key;
	static qnamekey_t op_precedes_key;
	static qnamekey_t op_follows_key;

	// Sequence functions
	static qnamekey_t op_concatenate_key;
	static qnamekey_t op_union_key;
	static qnamekey_t op_intersect_key;
	static qnamekey_t op_except_key;
	static qnamekey_t fn_doc_key;

public:
	library(zorba* zorp);
	~library();
	static bool static_init;
	void init(value_factory*);

public:
	void put(const function*);
	const function* get(qnamekey_t);

};

} /* namespace xqp */
#endif /* XQP_LIBRARY_H */

