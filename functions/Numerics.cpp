
/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: Numerics.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#include "Numerics.h"

using namespace std;
namespace xqp {
 

/*______________________________________________________________________
|  
|	6.2.1 op:numeric-add
|	op:numeric-add($arg1 as numeric, $arg2 as numeric) as numeric
|	
|	Summary: Backs up the "+" operator and returns the arithmetic sum of 
|	its operands: ($arg1 + $arg2).
|	
|	Note:
|	For xs:float or xs:double values, if one of the operands is a zero or 
|	a finite number and the other is INF or -INF, INF or -INF is returned. 
|	If both operands are INF, INF is returned. If both operands are -INF, 
|	-INF is returned. If one of the operands is INF and the other is -INF, 
|	NaN is returned.
|_______________________________________________________________________*/

rchandle<item> op_numeric_add(context const* context_p)
{
	handle<item> arg1_h = content_p->argv[1];
	handle<item> arg2_h = content_p->argv[2];
}



/*______________________________________________________________________
|  
|	6.2.2 op:numeric-subtract
|	op:numeric-subtract($arg1 as numeric, $arg2 as numeric) as numeric
|	
|	Summary: Backs up the "-" operator and returns the arithmetic 
|	difference of its operands: ($arg1 - $arg2).
|	
|	Note:
|	For xs:float or xs:double values, if one of the operands is a zero or 
|	a finite number and the other is INF or -INF, an infinity of the 
|	appropriate sign is returned. If both operands are INF or -INF, NaN is 
|	returned. If one of the operands is INF and the other is -INF, an 
|	infinity of the appropriate sign is returned.
|_______________________________________________________________________*/




/*______________________________________________________________________
|  
|	6.2.3 op:numeric-multiply
|	op:numeric-multiply($arg1 as numeric, $arg2 as numeric) as numeric
|	
|	Summary: Backs up the "*" operator and returns the arithmetic product 
|	of its operands: ($arg1 * $arg2).
|	
|	Note:
|	For xs:float or xs:double values, if one of the operands is a zero and 
|	the other is an infinity, NaN is returned. If one of the operands is a 
|	non-zero number and the other is an infinity, an infinity with the 
|	appropriate sign is returned.
|_______________________________________________________________________*/




/*______________________________________________________________________
|  
|	6.2.4 op:numeric-divide
|	op:numeric-divide($arg1 as numeric, $arg2 as numeric) as numeric
|	
|	Summary: Backs up the "div" operator and returns the arithmetic 
|	quotient of its operands: ($arg1 div $arg2).
|	
|	As a special case, if the types of both $arg1 and $arg2 are 
|	xs:integer, then the return type is xs:decimal.
|	
|	Notes:
|	For xs:decimal and xs:integer operands, if the divisor is (positive or 
|	negative) zero, an error is raised [err:FOAR0001]. For xs:float and 
|	xs:double operands, floating point division is performed as specified 
|	in [IEEE 754-1985].
|	
|	For xs:float or xs:double values, a positive number divided by 
|	positive zero returns INF. A negative number divided by positive zero 
|	returns -INF. Division by negative zero returns -INF and INF, 
|	respectively. Positive or negative zero divided by positive or 
|	negative zero returns NaN. Also, INF or -INF divided by INF or -INF 
|	returns NaN.
|_______________________________________________________________________*/




/*______________________________________________________________________
|  
|	6.2.5 op:numeric-integer-divide
|	op:numeric-integer-divide($arg1 as numeric, $arg2 as numeric) as xs:integer
|	
|	Summary: This function backs up the "idiv" operator and performs an 
|	integer division: that is, it divides the first argument by the 
|	second, and returns the integer obtained by truncating the fractional 
|	part of the result. The division is performed so that the sign of the 
|	fractional part is the same as the sign of the dividend.
|	
|	If the dividend, $arg1, is not evenly divided by the divisor, $arg2, 
|	then the quotient is the xs:integer value obtained, ignoring 
|	(truncating) any remainder that results from the division (that is, no 
|	rounding is performed). Thus, the semantics " $a idiv $b " are 
|	equivalent to " ($a div $b) cast as xs:integer " except for error 
|	situations.
|	
|	If the divisor is (positive or negative) zero, then an error is raised 
|	[err:FOAR0001]. If either operand is NaN or if $arg1 is INF or -INF 
|	then an error is raised [err:FOAR0002].
|	
|	Note:
|	The semantics of this function are different from integer division as 
|	defined in programming languages such as Java and C++.
|_______________________________________________________________________*/




/*______________________________________________________________________
|  
|	6.2.6 op:numeric-mod
|	op:numeric-mod($arg1 as numeric, $arg2 as numeric) as numeric
|	
|	Summary: Backs up the "mod" operator. Informally, this function 
|	returns the remainder resulting from dividing $arg1, the dividend, by 
|	$arg2, the divisor. The operation a mod b for operands that are 
|	xs:integer or xs:decimal, or types derived from them, produces a 
|	result such that (a idiv b)*b+(a mod b) is equal to a and the 
|	magnitude of the result is always less than the magnitude of b. This 
|	identity holds even in the special case that the dividend is the 
|	negative integer of largest possible magnitude for its type and the 
|	divisor is -1 (the remainder is 0). It follows from this rule that the 
|	sign of the result is the sign of the dividend.
|	
|	For xs:integer and xs:decimal operands, if $arg2 is zero, then an 
|	error is raised [err:FOAR0001].
|	
|	For xs:float and xs:double operands the following rules apply:
|	  * If either operand is NaN, the result is NaN.
|	  * If the dividend is positive or negative infinity, or the divisor 
|			is positive or negative zero (0), or both, the result is NaN.
|	  * If the dividend is finite and the divisor is an infinity, the 
|			result equals the dividend.
|	  * If the dividend is positive or negative zero and the divisor is 
|			finite, the result is the same as the dividend.
|	  * In the remaining cases, where neither positive or negative 
|			infinity, nor positive or negative zero, nor NaN is involved, the 
|			result obeys (a idiv b)*b+(a mod b) = a. Division is truncating 
|			division, analogous to integer division, not [IEEE 754-1985] rounding 
|			division i.e. additional digits are truncated, not rounded to the 
|			required precision.
|_______________________________________________________________________*/




/*______________________________________________________________________
|  
|	6.2.7 op:numeric-unary-plus
|	op:numeric-unary-plus($arg as numeric) as numeric
|	
|	Summary: Backs up the unary "+" operator and returns its operand with 
|	the sign unchanged: (+ $arg). Semantically, this operation performs no 
|	operation.
|_______________________________________________________________________*/




/*______________________________________________________________________
|  
|	6.2.8 op:numeric-unary-minus
|	op:numeric-unary-minus($arg as numeric) as numeric
|	
|	Summary: Backs up the unary "-" operator and returns its operand with 
|	the sign reversed: (- $arg). If $arg is positive, its negative is 
|	returned; if it is negative, its positive is returned.
|	
|	For xs:integer and xs:decimal arguments, 0 and 0.0 return 0 and 0.0, 
|	respectively. For xs:float and xs:double arguments, NaN returns NaN, 
|	0.0E0 returns -0.0E0 and vice versa. INF returns -INF. -INF returns 
|	INF.
|_______________________________________________________________________*/



  
  
} /* namespace xqp */

