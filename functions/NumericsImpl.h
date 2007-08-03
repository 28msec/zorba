/**
 * @file NumericsImpl.h
 * @authors Paul Pedersen (pcp071098@yahoo.com)
 * @copyright 2006-2007 FLWOR Foundation (flworfound.org)
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

#ifndef XQP_NUMERICS_IMPL_H
#define XQP_NUMERICS_IMPL_H

#include "context/common.h"
#include "functions/function.h"
#include "runtime/item_iterator.h"
#include "types/sequence_type.h"
#include "util/rchandle.h"


namespace xqp {

class zorba;


// binary iterator base class

class op_numeric_binary_iterator : public basic_iterator
{
public:
	op_numeric_binary_iterator(yy::location loc, iterator_t, iterator_t);
	virtual ~op_numeric_binary_iterator() {}

public:	// iterator interface
	virtual void _open();
	virtual void _close();
	virtual std::ostream&  _show(std::ostream&) const = 0;
	virtual item_t _next() = 0;
	virtual bool done() const;

protected:
	iterator_t arg0;
	iterator_t arg1;

};


/*______________________________________________________________________
|  
| 6.2 Operators on Numeric Values
|_______________________________________________________________________*/

// 6.2.1 op:numeric-add
// --------------------
class op_numeric_add_iterator : public op_numeric_binary_iterator
{
public:
	op_numeric_add_iterator(yy::location loc, iterator_t, iterator_t);
	~op_numeric_add_iterator() {}

public:	// iterator interface
	item_t _next();
	std::ostream&  _show(std::ostream&) const;
};



// 6.2.2 op:numeric-subtract
// -------------------------
class op_numeric_subtract_iterator : public op_numeric_binary_iterator
{
public:
	op_numeric_subtract_iterator(yy::location loc, iterator_t, iterator_t);
	~op_numeric_subtract_iterator() {}

public:	// iterator interface
	item_t _next();
	std::ostream&  _show(std::ostream&) const;
};



// 6.2.3 op:numeric-multiply
// -------------------------
class op_numeric_multiply_iterator : public op_numeric_binary_iterator
{
public:
	op_numeric_multiply_iterator(yy::location loc, iterator_t, iterator_t);
	~op_numeric_multiply_iterator() { }

public:	// iterator interface
	item_t _next();
	std::ostream&  _show(std::ostream&) const;
};


// 6.2.4 op:numeric-divide
// -----------------------
class op_numeric_divide_iterator : public op_numeric_binary_iterator
{
public:
	op_numeric_divide_iterator(yy::location loc, iterator_t, iterator_t);
	~op_numeric_divide_iterator() {}

public:	// iterator interface
	item_t _next();
	std::ostream&  _show(std::ostream&) const;
};


// 6.2.5 op:numeric-integer-divide
// -------------------------------
class op_numeric_integer_divide_iterator : public op_numeric_binary_iterator
{
public:
	op_numeric_integer_divide_iterator(yy::location loc, iterator_t, iterator_t);
	~op_numeric_integer_divide_iterator() {}

public:	// iterator interface
	item_t _next();
	std::ostream&  _show(std::ostream&) const;
};


// 6.2.6 op:numeric-mod
// --------------------
class op_numeric_mod_iterator : public op_numeric_binary_iterator
{
public:
	op_numeric_mod_iterator(yy::location loc, iterator_t, iterator_t);
	~op_numeric_mod_iterator() {}


public:	// iterator interface
	item_t _next();
	std::ostream&  _show(std::ostream&) const;
};


// 6.2.7 op:numeric-unary-plus
// ---------------------------


// 6.2.8 op:numeric-unary-minus
// ----------------------------
class op_numeric_unary_minus_iterator : public basic_iterator
{
public:
	op_numeric_unary_minus_iterator(yy::location loc, iterator_t);
	~op_numeric_unary_minus_iterator() {}

public:	// iterator interface
	void _open();
	void _close();
	item_t _next();
	std::ostream&  _show(std::ostream&) const;
	bool done() const;

private:
	iterator_t arg0;

};



/*______________________________________________________________________
|  
| 6.3 Comparison Operators on Numeric Values
|_______________________________________________________________________*/

// 6.3.1 op:numeric-equal
// -------------------------
class op_numeric_equal_iterator : public op_numeric_binary_iterator {
public:
	op_numeric_equal_iterator(yy::location loc, iterator_t, iterator_t);
	~op_numeric_equal_iterator() {}
	
public:
	item_t _next();
	std::ostream&  _show(std::ostream&) const;
};

// 6.3.2 op:numeric-less-than
// 6.3.3 op:numeric-greater-than


/*______________________________________________________________________
|  
| 6.4 Functions on Numeric Values
|_______________________________________________________________________*/

// 6.4.1 fn:abs
class fn_abs_iterator : public basic_iterator 
{
public:
	fn_abs_iterator(yy::location loc, iterator_t);
	~fn_abs_iterator() {}

public:
	void _open();
	void _close();
	item_t _next();
	std::ostream&  _show(std::ostream&) const;
	bool done() const;

private:
	iterator_t arg0;
};

// 6.4.2 fn:ceiling
// 6.4.3 fn:floor
// 6.4.4 fn:round
// 6.4.5 fn:round-half-to-even


}	/* namespace xqp */
#endif	/* XQP_NUMERICS_H */
