/**
 * Copyright FLWOR Foundation
 *
 * Author: David Graf (david.graf@28msec.com)
 */

#ifndef XQP_SEQUENCES_IMPL_H
#define XQP_SEQUENCES_IMPL_H

#include <string>
#include <vector>

#include "context/common.h"
#include "runtime/base/iterator.h"
#include "store/naive/simple_store.h"
#include "runtime/base/unarybase.h"
#include "runtime/base/binarybase.h"
#include "runtime/base/narybase.h"

namespace xqp
{

  /*______________________________________________________________________
  |
  | 15.1 General Functions and Operators on Sequences
  |_______________________________________________________________________*/


//15.1.1 fn:boolean


//15.1.2 op:concatenate
class FnConcatIterator : public NaryBaseIterator<FnConcatIterator>
{
public:
  FnConcatIterator(
  yy::location loc, vector<PlanIter_t>& aChildren);
  
  virtual ~FnConcatIterator();

  Item_t nextImpl(PlanState& planState);
  void resetImpl(PlanState& planState);
  
  virtual uint32_t getStateSize() const { return sizeof(FnConcatIteratorState); }
  
  virtual void accept(PlanIterVisitor&) const;
  
protected:
  class FnConcatIteratorState : public PlanIteratorState {
  private:  
    uint32_t theCurIter;
  
  public:
    void init();
    void reset();
    
    void incCurIter();
    uint32_t getCurIter() { return theCurIter; }
  };
};


//15.1.3 fn:index-of
/*
 * If the value of $arg is the empty sequence, the function returns true; 
 * otherwise, the function returns false.
 */
class FnIndexOfIterator : public BinaryBaseIterator<FnIndexOfIterator>
{

public:
 FnIndexOfIterator(yy::location loc,
                    PlanIter_t& arg1, PlanIter_t& arg2);
 
 ~FnIndexOfIterator();

 Item_t 
 nextImpl(PlanState& planState);
 
 virtual void 
 accept(PlanIterVisitor&) const;

  virtual uint32_t 
  getStateSize() const { return sizeof ( FnIndexOfIteratorState ); }

  virtual uint32_t
  getStateSizeOfSubtree() const;

protected:
  class FnIndexOfIteratorState : public PlanIteratorState {
  private:  
    uint32_t theCurPos;
  
  public:
    void init();
    void reset();
    
    void incCurPos();
    uint32_t getCurPos() { return theCurPos; }
  };
  
};

//15.1.4 fn:empty
/*
 * If the value of $arg is the empty sequence, the function returns true; 
 * otherwise, the function returns false.
 */
class FnEmptyIterator : public UnaryBaseIterator<FnEmptyIterator>
{

public:
	FnEmptyIterator(yy::location loc,
	               PlanIter_t& arg);
	
	~FnEmptyIterator();

	Item_t 
	nextImpl(PlanState& planState);
	
	virtual void 
	accept(PlanIterVisitor&) const;
};


//15.1.5 fn:exists
/*
 * If the value of $arg is not the empty sequence, the function returns true; 
 * otherwise, the function returns false.
 */
class FnExistsIterator : public UnaryBaseIterator<FnExistsIterator>
{

public:
	FnExistsIterator(yy::location loc,
	               PlanIter_t& arg);
	
	~FnExistsIterator();

	Item_t 
	nextImpl(PlanState& planState);
	
	virtual void 
	accept(PlanIterVisitor&) const;
};

//15.1.6 fn:distinct-values

//15.1.7 fn:insert-before

//15.1.8 fn:remove

//15.1.9 fn:reverse

//15.1.10 fn:subsequence

//15.1.11 fn:unordered


  /*______________________________________________________________________
  |
  | 15.2 Functions That Test the Cardinality of Sequences
  |_______________________________________________________________________*/

//15.2.1 fn:zero-or-one

//15.2.2 fn:one-or-more

//15.2.3 fn:exactly-one


  /*______________________________________________________________________
  |
  | 15.3 Equals, Union, Intersection and Except
  |_______________________________________________________________________*/

//15.3.1 fn:deep-equal

//15.3.2 op:union

//15.3.3 op:intersect

//15.3.4 op:except


  /*______________________________________________________________________
  |
  | 15.4 Aggregate Functions
  |_______________________________________________________________________*/

//15.4.1 fn:count

//15.4.2 fn:avg

//15.4.3 fn:max

//15.4.4 fn:min

//15.4.5 fn:sum


  /*______________________________________________________________________
  |
  | 15.5 Functions and Operators that Generate Sequences
  |_______________________________________________________________________*/

//15.5.1 op:to

//15.5.2 fn:id

//15.5.3 fn:idref


//15.5.4 fn:doc

class DocIterator : public UnaryBaseIterator<DocIterator>
{
//  DECLARE_LOGGER;
protected:
  
public:
  DocIterator(yy::location loc, PlanIter_t& arg);
  virtual ~DocIterator();

  Item_t nextImpl(PlanState& planState);
  virtual uint32_t getStateSize() const;
  
  virtual void accept(PlanIterVisitor&) const;

protected:
  class DocIteratorState : public PlanIteratorState {
  public:
    DocIteratorState();
    
    int got_doc;              // if got_doc == 0 - no document,
                              //            == 1 - Item_t doc is used
                              //            == 2 - Collection_t collection is used
    Iterator_t childrenIter;
    Item_t doc;
    Collection_t collection;
    xqp_string uri;
    
  public:
    void init();
    void reset();
  };
};


//15.5.5 fn:doc-available

//15.5.6 fn:collection


  /*______________________________________________________________________
  |
  | Extensions
  |_______________________________________________________________________*/


} /* namespace xqp */
#endif /* XQP_SEQUENCES_H */
