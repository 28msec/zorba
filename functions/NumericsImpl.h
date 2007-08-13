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


/**
 * TODO CommonBase-Classes should be implemented in the Header file, as they make troutble
 * if you seperate them in .h and .cpp during linking. Any suggestions to fix that are 
 * welcome.
 * 
 */
template <class IterType>
class BinaryBaseIterator : public Batcher<IterType> {
	
public:
	BinaryBaseIterator
	(yy::location loc, iterator_t arg0_, iterator_t arg1_)
	:
	Batcher<IterType>(loc),arg0(arg0_),arg1(arg1_){}
	
	~BinaryBaseIterator() {}

	void resetImpl(){
		this->resetChild(arg0);
		this->resetChild(arg1);
	}
	
	void releaseResourcesImpl(){
		this->releaseChildResources(this->arg0);
		this->releaseChildResources(this->arg1);
	}

	
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

class OpNumericAddIterator : public BinaryBaseIterator<OpNumericAddIterator>
{
public:
	OpNumericAddIterator
	(yy::location loc, iterator_t iter0, iterator_t iter1)
	:
	BinaryBaseIterator<OpNumericAddIterator>(loc, iter0, iter1){}
	~OpNumericAddIterator() {}

public:	// iterator interface
	item_t nextImpl();

	std::ostream&  _show(std::ostream&) const;
};



// 6.2.2 op:numeric-subtract
// -------------------------
class OpNumericSubtractIterator : public BinaryBaseIterator<OpNumericSubtractIterator>
{
public:
	OpNumericSubtractIterator(yy::location loc, iterator_t iter0, iterator_t iter1)
		:
	BinaryBaseIterator<OpNumericSubtractIterator>(loc, iter0, iter1){}
	~OpNumericSubtractIterator() {}

public:	// iterator interface
	item_t nextImpl();
	std::ostream&  _show(std::ostream&) const;
};



// 6.2.3 op:numeric-multiply
// -------------------------
class OpNumericMultiplyIterator : public BinaryBaseIterator<OpNumericMultiplyIterator>
{
public:
	OpNumericMultiplyIterator(yy::location loc, iterator_t iter0, iterator_t iter1)
		:
	BinaryBaseIterator<OpNumericMultiplyIterator>(loc, iter0, iter1){}
	~OpNumericMultiplyIterator() { }

public:	// iterator interface
	item_t nextImpl();
	std::ostream&  _show(std::ostream&) const;
};


// 6.2.4 op:numeric-divide
// -----------------------
class OpNumericDivideIterator : public BinaryBaseIterator<OpNumericDivideIterator>
{
public:
	OpNumericDivideIterator(yy::location loc, iterator_t iter0, iterator_t iter1)
		:
	BinaryBaseIterator<OpNumericDivideIterator>(loc, iter0, iter1){}
	~OpNumericDivideIterator() {}

public:	// iterator interface
	item_t nextImpl();
	std::ostream&  _show(std::ostream&) const;
};


// 6.2.5 op:numeric-integer-divide
// -------------------------------
class OpNumericIntegerDivideIterator : public OpNumericDivideIterator
{
public:
	OpNumericIntegerDivideIterator(yy::location loc, iterator_t iter0, iterator_t iter1)
		:
	OpNumericDivideIterator(loc, iter0, iter1) {}
};


// 6.2.6 op:numeric-mod
// --------------------
class OpNumericModIterator : public BinaryBaseIterator<OpNumericModIterator>
{
public:
	OpNumericModIterator(yy::location loc, iterator_t iter0, iterator_t iter1)
		:
	BinaryBaseIterator<OpNumericModIterator>(loc, iter0, iter1) {}
	~OpNumericModIterator() {}


public:	// iterator interface
	item_t nextImpl();
	std::ostream&  _show(std::ostream&) const;
};


// 6.2.7 op:numeric-unary-plus
// ---------------------------


// 6.2.8 op:numeric-unary-minus
// ----------------------------
class OpNumericUnaryMinusIterator : public Batcher<OpNumericUnaryMinusIterator>
{
private:
	iterator_t arg0_;
	
public:
	OpNumericUnaryMinusIterator(yy::location loc, iterator_t iter)
		:
	Batcher<OpNumericUnaryMinusIterator>(loc), arg0_(iter) {}
	~OpNumericUnaryMinusIterator() {}

public:	// iterator interface
	item_t nextImpl();
	void resetImpl();
	void releaseResourcesImpl();
	std::ostream&  _show(std::ostream&) const;
};



/*______________________________________________________________________
|  
| 6.3 Comparison Operators on Numeric Values
|_______________________________________________________________________*/

// 6.3.1 op:numeric-equal
// -------------------------
class OpNumericEqualIterator : public BinaryBaseIterator<OpNumericModIterator> {
public:
	OpNumericEqualIterator(yy::location loc, iterator_t iter1, iterator_t iter2)
		:
	BinaryBaseIterator<OpNumericModIterator>(loc, iter1, iter2) {}
	~OpNumericEqualIterator() {}
	
public:
	item_t nextImpl();
	std::ostream&  _show(std::ostream&) const;
};

// 6.3.2 op:numeric-less-than
// 6.3.3 op:numeric-greater-than


/*______________________________________________________________________
|  
| 6.4 Functions on Numeric Values
|_______________________________________________________________________*/

// 6.4.1 fn:abs
class FnAbsIterator : public Batcher<FnAbsIterator>
{
private:
	iterator_t arg0_;
	
public:
	FnAbsIterator(yy::location loc, iterator_t iter)
		:
	Batcher<FnAbsIterator>(loc), arg0_(iter) {}
	~FnAbsIterator() {}

public:
	item_t nextImpl();
	void resetImpl();
	void releaseResourcesImpl();
	std::ostream&  _show(std::ostream&) const;
};

// 6.4.2 fn:ceiling
// 6.4.3 fn:floor
// 6.4.4 fn:round
// 6.4.5 fn:round-half-to-even


}	/* namespace xqp */
#endif	/* XQP_NUMERICS_H */
