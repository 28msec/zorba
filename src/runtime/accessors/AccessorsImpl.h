/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: collection.h,v 1.1 2007/08/27 07:07:59 $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: David Graf
 *
 */

#ifndef XQP_ACCESSORS_IMPL_H
#define XQP_ACCESSORS_IMPL_H

#include "context/common.h"
#include "functions/function.h"
#include "runtime/core/batching.h"

namespace xqp {

class FnDataIterator : public Batcher<FnDataIterator>
{
private:
  Iterator_t argument;
		
  // used to save the current typed value in the nextImpl method
  Iterator_t curTypedValue;
	
public:
  FnDataIterator ( const yy::location& loc, Iterator_t& arg0 )
		:
		Batcher<FnDataIterator> ( loc ), argument(arg0) {}
    ~FnDataIterator() {}
		
  Item_t nextImpl(IteratorTreeStateBlock& stateBlock);
  void resetImpl(IteratorTreeStateBlock& stateBlock);
  void releaseResourcesImpl(IteratorTreeStateBlock& stateBlock);
}; /* class FnDateIterator */



class FnRootIterator : public Batcher<FnRootIterator>
{
private:
  Iterator_t theInput;
		
public:
  FnRootIterator(const yy::location& loc, Iterator_t& input)
		:
		Batcher<FnRootIterator>(loc), theInput(input) {}
    ~FnRootIterator() {}
		
  Item_t nextImpl(IteratorTreeStateBlock& stateBlock);
  void resetImpl(IteratorTreeStateBlock& stateBlock);
  void releaseResourcesImpl(IteratorTreeStateBlock& stateBlock);

  std::ostream& _show(std::ostream& os)	const;
};



} /* namespace xqp */
#endif /* XQP_ACCESSORS_IMPL_H */
