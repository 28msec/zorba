/**
 * @file SequencesImpl.h
 * @authors Paul Pedersen (pcp071098@yahoo.com)
 * @copyright 2006-2007 FLWOR Foundation (flworfound.org).
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

#ifndef XQP_SEQUENCES_IMPL_H
#define XQP_SEQUENCES_IMPL_H

#include <string>
#include <vector>

#include "context/common.h"
#include "runtime/base/iterator.h"
#include "store/naive/simple_store.h"
#include "runtime/base/unarybase.h"
#include "util/logging/logging.hh"

namespace xqp
{

  class zorba;

  /*______________________________________________________________________
  |
  | 15.1 General Functions and Operators on Sequences
  |_______________________________________________________________________*/


//15.1.1 fn:boolean


//15.1.2 op:concatenate
class ConcatIterator : public Batcher<ConcatIterator>
{
//  DECLARE_LOGGER;
protected:
  std::vector<PlanIter_t> theChildren;

public:
  ConcatIterator(
  yy::location loc,
  const vector<PlanIter_t>& aChildren);
  
  ~ConcatIterator();

  Item_t nextImpl(PlanState& planState);
  void resetImpl(PlanState& planState);
  void releaseResourcesImpl(PlanState& planState);
  
  virtual int32_t getStateSize();
  virtual int32_t getStateSizeOfSubtree();
  virtual void setOffset(PlanState& planState, int32_t& offset);
  
  virtual void accept(PlanIterVisitor&) const;
  
protected:
  class ConcatIteratorState : public PlanIteratorState {
  private:  
    int32_t curIter;
  
  public:
    void init();
    void reset();
    
    void incCurIter();
    int32_t getCurIter();
  };
};


//15.1.3 fn:index-of

//15.1.4 fn:empty

//15.1.5 fn:exists

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
  virtual int32_t getStateSize();
  
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
