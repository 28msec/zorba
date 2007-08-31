/**
 * @file NumericsImpl.cpp
 * @author Paul Pedersen (pcp071098@yahoo.com)
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

#include "NumericsImpl.h"
#include "util/tracer.h"
#include <iostream>

using namespace std;
namespace xqp {

	/* begin class BinaryBaseIterator */
	
	namespace num_operations {
		static Item_t makeOperation(ItemFactory* itemFactory, Operation operation, Item_t item0, Item_t item1) {
			Item_t resultItem;
			
			switch (item0->getType()) {
			case xs_integer:
				switch (item1->getType()) {
				case xs_integer:
					switch (operation) {
					case num_operations::add:
						resultItem = itemFactory->createInteger(item0->getIntegerValue() + item1->getIntegerValue());
						break;
					case num_operations::subtract:
						resultItem = itemFactory->createInteger(item0->getIntegerValue() - item1->getIntegerValue());
						break;
					default:
						break;
					}
					break;
				case xs_float:
					resultItem = itemFactory->createFloat(item0->getIntegerValue() + item1->getFloatValue());
					break;
				case xs_double:
					resultItem = itemFactory->createDouble(item0->getIntegerValue() + item1->getDoubleValue());
					break;
				case xs_decimal:
					resultItem = itemFactory->createDecimal(item0->getIntegerValue() + item1->getDecimalValue());
					break;
				default:
					break;
			}
			break;
			case xs_float:
				switch (item1->getType()) {
					case xs_integer:
						resultItem = itemFactory->createFloat(item0->getFloatValue() + item1->getIntegerValue());
						break;
					case xs_float:
						resultItem = itemFactory->createFloat(item0->getFloatValue() + item1->getFloatValue());
						break;
					case xs_double:
						resultItem = itemFactory->createDouble(item0->getFloatValue() + item1->getDoubleValue());
						break;
					case xs_decimal:
						resultItem = itemFactory->createDecimal(item0->getFloatValue() + item1->getDecimalValue());
						break;
					default:
						break;
				}
				break;
			case xs_double:
				switch (item1->getType()) {
					case xs_integer:
						resultItem = itemFactory->createDouble(item0->getDoubleValue() + item1->getIntegerValue());
						break;
					case xs_float:
						resultItem = itemFactory->createDouble(item0->getDoubleValue() + item1->getFloatValue());
						break;
					case xs_double:
						resultItem = itemFactory->createDouble(item0->getDoubleValue() + item1->getDoubleValue());
						break;
					case xs_decimal:
						resultItem = itemFactory->createDecimal(item0->getDoubleValue() + item1->getDecimalValue());
						break;
					default:
						break;
				}
				break;
			case xs_decimal:
				switch (item1->getType()) {
					case xs_integer:
						resultItem = itemFactory->createDecimal(item0->getDecimalValue() + item1->getIntegerValue());
						break;
					case xs_float:
						resultItem = itemFactory->createDecimal(item0->getDecimalValue() + item1->getFloatValue());
						break;
					case xs_double:
						resultItem = itemFactory->createDecimal(item0->getDecimalValue() + item1->getDoubleValue());
						break;
					case xs_decimal:
						resultItem = itemFactory->createDecimal(item0->getDecimalValue() + item1->getDecimalValue());
						break;
					default:
						break;
				}
			default:
				break;
			}
			
			return resultItem;
		}
	}
	
	/* end class BinaryBaseIterator */

// 	/* begin class ArithmeticIterator */
// 	Item_t ArithmeticIterator::nextImpl()
// 	{
// 		Item_t n0;
// 		Item_t n1;
// 		sequence_type_t type0;
// 		sequence_type_t type1;
// 		sequence_type_t resultType;
// 		
// 		STACK_INIT();
// 		n0 = this->consumeNext(this->arg0);
// 		if(n0 == NULL) {
// 			STACK_PUSH(NULL);
// 		} else {
// 			n1 = this->consumeNext(this->arg1);
// 			if (n1 == NULL) {
// 				STACK_PUSH(NULL);
// 			} else {
// 				n0 = n0->getAtomizationValue();
// 				n1 = n1->getAtomizationValue();
// 				type0 = n0->getType();
// 				type1 = n1->getType();
// 				resultType = sequence_type::getNumericalOpResultType(type0, type1);
// 				
// 			}
// 		}
// 		STACK_END();
// 	}
// 	
// 	Item_t ArithmeticIterator::upCast(sequence_type_t type, Item_t item)
// 	{
// 		if (value->getType() == type) {
// 			return item;
// 		} else {
// 			switch(type) {
// 			case 
// 			}
// 		}
// 	}
// 	/* end class ArithmeticIterator */

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

// OpNumericAddIterator::OpNumericAddIterator(
// 	yy::location loc, 
// 	Iterator_t arg0,
// 	Iterator_t arg1)
// :
// 	op_numeric_binary_iterator(loc,arg0,arg1)
// {
// }


Item_t OpNumericAddIterator::nextImpl(){
	Item_t n0;
	Item_t n1;
	sequence_type_t type0;
	sequence_type_t type1;
	Item_t resultItem;
	ItemFactory* itemFactory;
	
	STACK_INIT();
	n0 = this->consumeNext(arg0);
	if(n0 == NULL) {
		STACK_PUSH(NULL);
	} else {
		n1 = this->consumeNext(arg1);
		if(n1 == NULL) {
			STACK_PUSH(NULL);
		} else {
			type0 = n0->getType();
			type1 = n1->getType();
			itemFactory = zorba::getZorbaForCurrentThread()->getItemFactory();
			resultItem = num_operations::makeOperation(itemFactory, num_operations::add, n0, n1);
			STACK_PUSH(resultItem);
			STACK_PUSH(NULL);
		}
	}
	STACK_END();
}

std::ostream& OpNumericAddIterator::_show(std::ostream& os)
const
{
	os << IT_DEPTH << "<info>" << "additional information" << "</info>" << std::endl;
	arg1->show(os);
	arg0->show(os);
	return os;
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

Item_t OpNumericSubtractIterator::nextImpl()
{
	Item_t n0;
	Item_t n1;
	sequence_type_t type0;
	sequence_type_t type1;
	Item_t resultItem;
	ItemFactory* itemFactory;
	
	STACK_INIT();
	n0 = this->consumeNext(arg0);
	if(n0 == NULL) {
		STACK_PUSH(NULL);
	} else {
		n1 = this->consumeNext(arg1);
		if(n1 == NULL) {
			STACK_PUSH(NULL);
		} else {
			type0 = n0->getType();
			type1 = n1->getType();
			itemFactory = zorba::getZorbaForCurrentThread()->getItemFactory();
			resultItem = num_operations::makeOperation(itemFactory, num_operations::subtract, n0, n1);
			STACK_PUSH(resultItem);
			STACK_PUSH(NULL);
		}
	}
	STACK_END();
}

std::ostream& OpNumericSubtractIterator::_show(std::ostream& os)
const
{
	arg1->show(os);
	arg0->show(os);
	return os;
}

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


Item_t OpNumericMultiplyIterator::nextImpl()
{
	Item_t n0;
	Item_t n1;
	sequence_type_t type0;
	sequence_type_t type1;
	sequence_type_t resultType;
	
	STACK_INIT();
// 	n0_h = this->consumeNext(this->arg0);
// 	if(&*n0_h == NULL) {
// 		STACK_PUSH(NULL);
// 	} else {
// 		n1_h = this->consumeNext(this->arg1);
// 		if(&*n1_h == NULL) {
// 			STACK_PUSH(NULL);
// 		} else {
// 			n0 = dynamic_cast<const numericValue*>(&*n0_h);
// 			n1 = dynamic_cast<const numericValue*>(&*n1_h);
// 			type0 = n0->type();
// 			type1 = n1->type();
// 			resultType = sequence_type::getNumericalOpResultType(type0, type1);
// 			STACK_PUSH(new numericValue(resultType, n0->val() * n1->val()));
// 			STACK_PUSH(NULL);
// 		}
// 	}
	STACK_END();
}

std::ostream& OpNumericMultiplyIterator::_show(std::ostream& os)
const
{
	arg1->show(os);
	arg0->show(os);
	return os;
}

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

Item_t OpNumericDivideIterator::nextImpl()
{
	Item_t n0;
	Item_t n1;
	sequence_type_t type0;
	sequence_type_t type1;
	sequence_type_t resultType;
	
	STACK_INIT();
// 	n0_h = this->consumeNext(this->arg0);
// 	if(&*n0_h == NULL) {
// 		STACK_PUSH(NULL);
// 	} else {
// 		n1_h = this->consumeNext(this->arg1);
// 		if(&*n1_h == NULL) {
// 			STACK_PUSH(NULL);
// 		} else {
// 			n0 = dynamic_cast<const numericValue*>(&*n0_h);
// 			n1 = dynamic_cast<const numericValue*>(&*n1_h);
// 			type0 = n0->type();
// 			type1 = n1->type();
// 			resultType = sequence_type::getNumericalOpResultType(type0, type1);
// 			STACK_PUSH(new numericValue(resultType, n0->val() / n1->val()));
// 			STACK_PUSH(NULL);
// 		}
// 	}
	STACK_END();
}

std::ostream& OpNumericDivideIterator::_show(std::ostream& os)
const
{
	arg1->show(os);
	arg0->show(os);
	return os;
}

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

Item_t OpNumericModIterator::nextImpl()
{
	Item_t n0;
	Item_t n1;
	sequence_type_t type0;
	sequence_type_t type1;
	sequence_type_t resultType;
	
	STACK_INIT();
// 	n0_h = this->consumeNext(this->arg0);
// 	if(&*n0_h == NULL) {
// 		STACK_PUSH(NULL);
// 	} else {
// 		n1_h = this->consumeNext(this->arg1);
// 		if(&*n1_h == NULL) {
// 			STACK_PUSH(NULL);
// 		} else {
// 			n0 = dynamic_cast<const numericValue*>(&*n0_h);
// 			n1 = dynamic_cast<const numericValue*>(&*n1_h);
// 			type0 = n0->type();
// 			type1 = n1->type();
// 			resultType = sequence_type::getNumericalOpResultType(type0, type1);
// 			STACK_PUSH(new numericValue(resultType, (long)n0->val() % (long)n1->val()));
// 			STACK_PUSH(NULL);
// 		}
// 	}
	STACK_END();
}

std::ostream& OpNumericModIterator::_show(std::ostream& os)
const
{
	os  << IT_INDENT << "<OpNumericModIterator>\n";
	arg1->show(os);
	arg0->show(os);
	os << IT_OUTDENT << "</OpNumericModIterator>\n";
	return os;
}

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

Item_t OpNumericUnaryMinusIterator::nextImpl()
{
	Item_t n;
// 	const numericValue* n;
	
	STACK_INIT();
// 	n_h = this->consumeNext(this->arg0_);
// 	if(&*n_h == NULL) {
// 		STACK_PUSH(n_h);
// 	} else {
// 		n = dynamic_cast<const numericValue*>(&*n_h);
// 		STACK_PUSH(new numericValue(n->type(), -n->val()));
// 	}
// 	STACK_PUSH(NULL);
	STACK_END();
}

void OpNumericUnaryMinusIterator::resetImpl()
{
	this->resetChild(this->arg0_);
}

void OpNumericUnaryMinusIterator::releaseResourcesImpl()
{
	this->releaseChildResources(this->arg0_);
}

std::ostream& OpNumericUnaryMinusIterator::_show(std::ostream& os)
const
{
	this->arg0_->show(os);
	return os;
}


  
/*______________________________________________________________________
|  
| 6.3 Comparison Operators on Numeric Values
|_______________________________________________________________________*/

// 6.3.1 op:numeric-equal
Item_t OpNumericEqualIterator::nextImpl()
{
// 	const numericValue *n0;
// 	const numericValue *n1;
	
	STACK_INIT();
// 		n0 = dynamic_cast<const numericValue*>(&*arg0->next());
// 	if(n0 == NULL) {
// 		STACK_PUSH(NULL);
// 	} else {
// 		n1 = dynamic_cast<const numericValue*>(&*arg1->next());
// 		if(n1 == NULL) {
// 			STACK_PUSH(NULL);
// 		} else {
// 			STACK_PUSH(new booleanValue(n1->val() == n0->val()));
// 			STACK_PUSH(NULL);
// 		}
// 	}
	STACK_END();
}

std::ostream& OpNumericEqualIterator::_show(std::ostream& os)
const
{
	arg1->show(os);
	arg0->show(os);
	return os;
}
		
// Item_t OpNumericEqualIterator::_next()
// {
// 	const numericValue& n0 = dynamic_cast<const numericValue&>(*arg0->next());
// 	const numericValue& n1 = dynamic_cast<const numericValue&>(*arg1->next());
// 	return new booleanValue(n1.val() == n0.val());
// }
// 6.3.2 op:numeric-less-than
// 6.3.3 op:numeric-greater-than


/*______________________________________________________________________
|  
| 6.4 Functions on Numeric Values
|_______________________________________________________________________*/

// 6.4.1 fn:abs
Item_t FnAbsIterator::nextImpl() {
// 	const numericValue* n0;
	
	STACK_INIT();
// // // // 	n0 = dynamic_cast<const numericValue*>(&*this->arg0_->next());
// // // // 	if(n0 == NULL) {
// // // // 		STACK_PUSH(NULL);
// // // // 	} else {
// // // // 		if (n0->val() >= 0) {
// // // // 			STACK_PUSH(new numericValue(xs_decimal, n0->val()));
// // // // 		} else {
// // // // 			STACK_PUSH(new numericValue(xs_decimal, -n0->val()));
// // // // 		}
// // // // 		STACK_PUSH(NULL);	
// // // // 	}
	STACK_END();
}

void FnAbsIterator::resetImpl() {
	this->resetChild(this->arg0_);
}

void FnAbsIterator::releaseResourcesImpl() {
	this->releaseChildResources(this->arg0_);
}

std::ostream& FnAbsIterator::_show(std::ostream& os) const {
	this->arg0_->show(os);
	return os;
}


// 6.4.2 fn:ceiling
// 6.4.3 fn:floor
// 6.4.4 fn:round
// 6.4.5 fn:round-half-to-even


  
} /* namespace xqp */

