/*
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Authors: Tim Kraska, David Graf
 */

#ifndef XQP_BOOLEAN_IMPL_H
#define XQP_BOOLEAN_IMPL_H

#include "context/common.h"
#include "functions/function.h"
#include "runtime/item_iterator.h"
#include "types/sequence_type.h"
#include "util/rchandle.h"

namespace xqp{

class zorba;

/*______________________________________________________________________
|  
|	15.1.1 fn:boolean
|	fn:boolean($arg as item()*) as xs:boolean
|	
|	Computes the effective boolean value of the sequence $arg.
|_______________________________________________________________________*/
class FnBooleanIterator : public Batcher<FnBooleanIterator>
{
private:
	Iterator_t arg0_;
// 	bool donef;
	
public:
	FnBooleanIterator(yy::location loc, Iterator_t arg0)
	 :
	Batcher<FnBooleanIterator>(loc), arg0_(arg0) {}
	~FnBooleanIterator() {}
	
	Item_t nextImpl();
	void resetImpl();
	void releaseResourcesImpl();

	std::ostream&  _show(std::ostream&) const;
};

}

#endif
