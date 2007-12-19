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
#include "runtime/booleans/BooleanImpl.h"

namespace xqp
{

  /*______________________________________________________________________
  |
  | 15.1 General Functions and Operators on Sequences
  |_______________________________________________________________________*/

//15.1.1 fn:boolean
// see BooleanImpl.h

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
  public:
    uint32_t theCurIter;
  
    void init();
    void reset();
    
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
                    PlanIter_t& arg1, PlanIter_t& arg2, 
                    std::string collation);
 
  ~FnIndexOfIterator();

  Item_t 
  nextImpl(PlanState& planState);
 
  void 
  resetImpl(PlanState& planState);
  
  void 
  releaseResourcesImpl(PlanState& planState);
 
 
  virtual void 
  accept(PlanIterVisitor&) const;

  virtual uint32_t 
  getStateSize() const { return sizeof ( FnIndexOfIteratorState ); }

  virtual uint32_t
  getStateSizeOfSubtree() const;
  
  void 
  setOffset(PlanState& planState, uint32_t& offset);  

protected:
  class FnIndexOfIteratorState : public PlanIteratorState {
  public:  
    uint32_t theCurrentPos; // the current position in the sequence
    Item_t   theSearchItem; // the item to search for
  
    void init();
    void reset();
    
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
class FnDistinctValuesIterator : public NaryBaseIterator<FnDistinctValuesIterator>
{

public:
  FnDistinctValuesIterator(yy::location loc,
                           vector<PlanIter_t>& args);
 
  ~FnDistinctValuesIterator();

  Item_t 
  nextImpl(PlanState& planState);
 
  void 
  resetImpl(PlanState& planState);
  
  void 
  releaseResourcesImpl(PlanState& planState);
 
  virtual void 
  accept(PlanIterVisitor&) const;

  virtual uint32_t 
  getStateSize() const { return sizeof ( FnDistinctValuesIteratorState ); }

  void 
  setOffset(PlanState& planState, uint32_t& offset);

protected:
  struct ItemCmp 
  {
      bool operator() ( const Item_t& i1, const Item_t& i2) const
      {
        return CompareIterator::compare(i1, i2)<0?true:false;
      }

  };
  
  class FnDistinctValuesIteratorState : public PlanIteratorState {
  public:  
    typedef std::map<Item_t, uint8_t, ItemCmp> AlreadySeenMap_t;
    typedef AlreadySeenMap_t::const_iterator   AlreadySeenConstIter_t;

    AlreadySeenMap_t theAlreadySeenMap;  
  
    void init();
    void reset();
  };
  
};



//15.1.7 fn:insert-before
// Returns a new sequence constructed from the value of the first parameter with the value of third parameter inserted 
// at the position specified by the value of the second parameter. 
class FnInsertBeforeIterator : public NaryBaseIterator<FnInsertBeforeIterator>
{

public:
  FnInsertBeforeIterator(yy::location loc, vector<PlanIter_t>& aChildren);
 
  ~FnInsertBeforeIterator();

  Item_t 
  nextImpl(PlanState& planState);
 
  void 
  resetImpl(PlanState& planState);
  
  void 
  releaseResourcesImpl(PlanState& planState);
 
  virtual void 
  accept(PlanIterVisitor&) const;

  virtual uint32_t 
  getStateSize() const { return sizeof ( FnInsertBeforeIteratorState ); }
 
protected:
  class FnInsertBeforeIteratorState : public PlanIteratorState {
  public:  
    xqp_integer theCurrentPos; // the current position in the sequence
    xqp_integer thePosition;
    Item_t      theTargetItem;
  
    void init();
    void reset();
    
  };
  
};
// 

//15.1.8 fn:remove
// Returns a new sequence constructed from the value of aTarget with the item at the position specified by the 
// value of aPosition removed.
class FnRemoveIterator : public BinaryBaseIterator<FnRemoveIterator>
{

public:
  FnRemoveIterator(yy::location loc, PlanIter_t& aTarget, PlanIter_t& aPosition);
 
  ~FnRemoveIterator();

  Item_t 
  nextImpl(PlanState& planState);
 
  void 
  resetImpl(PlanState& planState);
  
  void 
  releaseResourcesImpl(PlanState& planState);
 
  virtual void 
  accept(PlanIterVisitor&) const;

  virtual uint32_t 
  getStateSize() const { return sizeof ( FnRemoveIteratorState ); }
 
protected:
  class FnRemoveIteratorState : public PlanIteratorState {
  public:  
    xqp_integer theCurrentPos; // the current position in the sequence
    xqp_integer thePosition; // the position to delete
  
    void init();
    void reset();
  };
  
};


//15.1.9 fn:reverse
// TODO implement

//15.1.10 fn:subsequence
// Returns the contiguous sequence of items in the value of $sourceSeq beginning at the position indicated by the value 
// of $startingLoc and continuing for the number of items indicated by the value of $length.
class FnSubsequenceIterator : public NaryBaseIterator<FnSubsequenceIterator>
{
public:
  FnSubsequenceIterator(yy::location loc, vector<PlanIter_t>& aChildren);
 
  ~FnSubsequenceIterator();

  Item_t 
  nextImpl(PlanState& planState);
 
  void 
  resetImpl(PlanState& planState);
  
  void 
  releaseResourcesImpl(PlanState& planState);
 
  virtual void 
  accept(PlanIterVisitor&) const;

  virtual uint32_t 
  getStateSize() const { return sizeof ( FnSubsequenceIteratorState ); }
 
  void 
  setOffset(PlanState& planState, uint32_t& offset);  
 
 
protected:
  class FnSubsequenceIteratorState : public PlanIteratorState {
  public:
    xqp_double  theStartingLoc; // second argument (startingLoc)
    xqp_double  theLength; // third optional argument (length)

    xqp_integer theCurrentPos; // the current position in the sequence
    xqp_integer theCurrentLength; // used for returning a specific number of items
  
    void init();
    void reset();  
  };
  
};

//15.1.11 fn:unordered
// no need to implement an operator for his


  /*______________________________________________________________________
  |
  | 15.2 Functions That Test the Cardinality of Sequences
  |_______________________________________________________________________*/

//15.2.1 fn:zero-or-one
class FnZeroOrOneIterator : public UnaryBaseIterator<FnZeroOrOneIterator>
{
public:
  FnZeroOrOneIterator(yy::location loc, PlanIter_t& aChild);
 
  ~FnZeroOrOneIterator();

  Item_t 
  nextImpl(PlanState& planState);
  
  virtual void 
  accept(PlanIterVisitor&) const;
};

//15.2.2 fn:one-or-more
class FnOneOrMoreIterator : public UnaryBaseIterator<FnOneOrMoreIterator>
{
public:
  FnOneOrMoreIterator(yy::location loc, PlanIter_t& aChild);
 
  ~FnOneOrMoreIterator();

  Item_t 
  nextImpl(PlanState& planState);
  
  virtual void 
  accept(PlanIterVisitor&) const;
};

//15.2.3 fn:exactly-one
class FnExactlyOneIterator : public UnaryBaseIterator<FnExactlyOneIterator>
{
public:
  FnExactlyOneIterator(yy::location loc, PlanIter_t& aChild);
 
  ~FnExactlyOneIterator();

  Item_t 
  nextImpl(PlanState& planState);
  
  virtual void 
  accept(PlanIterVisitor&) const;
};


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
class FnCountIterator : public UnaryBaseIterator<FnCountIterator>
{
public:
  FnCountIterator(yy::location loc, PlanIter_t& aChild);
 
  ~FnCountIterator();

  Item_t 
  nextImpl(PlanState& planState);
  
  virtual void 
  accept(PlanIterVisitor&) const;
};

//15.4.2 fn:avg
class FnAvgIterator : public UnaryBaseIterator<FnAvgIterator>
{
public:
  FnAvgIterator(yy::location loc, PlanIter_t& aChild);
 
  ~FnAvgIterator();

  Item_t 
  nextImpl(PlanState& planState);
  
  virtual void 
  accept(PlanIterVisitor&) const;
};

//15.4.3 fn:max
class FnMaxIterator : public NaryBaseIterator<FnMaxIterator>
{
public:
  FnMaxIterator(yy::location loc, vector<PlanIter_t>& aChildren);
 
  ~FnMaxIterator();

  Item_t 
  nextImpl(PlanState& planState);
  
  virtual void 
  accept(PlanIterVisitor&) const;
};


//15.4.4 fn:min
class FnMinIterator : public NaryBaseIterator<FnMinIterator>
{
public:
  FnMinIterator(yy::location loc, vector<PlanIter_t>& aChildren);
 
  ~FnMinIterator();

  Item_t 
  nextImpl(PlanState& planState);
  
  virtual void 
  accept(PlanIterVisitor&) const;
};

//15.4.5 fn:sum
class FnSumIterator : public NaryBaseIterator<FnSumIterator>
{
public:
  FnSumIterator(yy::location loc, vector<PlanIter_t>& aChildren);
 
  ~FnSumIterator();

  Item_t 
  nextImpl(PlanState& planState);
  
  virtual void 
  accept(PlanIterVisitor&) const;
};


  /*______________________________________________________________________
  |
  | 15.5 Functions and Operators that Generate Sequences
  |_______________________________________________________________________*/

//15.5.1 op:to
class OpToIterator : public BinaryBaseIterator<OpToIterator> {
public:
  OpToIterator(
  yy::location loc,
  PlanIter_t& arg1, PlanIter_t& arg2);
  
  virtual ~OpToIterator();

  Item_t nextImpl(PlanState& planState);
  void resetImpl(PlanState& planState);
  
  virtual uint32_t getStateSize() const { return sizeof(OpToIteratorState); }
  
  virtual void accept(PlanIterVisitor&) const;
  
protected:
  class OpToIteratorState : public PlanIteratorState {
  public:
    xqp_integer theCurInt;
    xqp_integer theFirstVal;
    xqp_integer theLastVal;
  
    void init();
    void reset();
    
  };
};

//15.5.2 fn:id

//15.5.3 fn:idref


//15.5.4 fn:doc

class FnDocIterator : public UnaryBaseIterator<FnDocIterator>
{
//  DECLARE_LOGGER;
protected:
  
public:
  FnDocIterator(yy::location loc, PlanIter_t& arg);
  virtual ~FnDocIterator();

  Item_t nextImpl(PlanState& planState);
  virtual uint32_t getStateSize() const;
  
  virtual void accept(PlanIterVisitor&) const;

protected:
  class FnDocIteratorState : public PlanIteratorState {
  public:
    FnDocIteratorState();
    
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
