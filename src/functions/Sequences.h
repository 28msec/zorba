/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef ZORBA_SEQUENCES_H
#define ZORBA_SEQUENCES_H

#include <vector>

#include "common/shared_types.h"

#include "functions/function_impl.h"
#include "functions/nodeid_internal.h"

#include "runtime/sequences/SequencesImpl.h"

namespace zorba {

  class zorba;

  /*______________________________________________________________________
    |  
    | 15.1 General Functions and Operators on Sequences
    |_______________________________________________________________________*/


  //15.1.1 fn:boolean (effective boolean value)
  //-----------------


  //15.1.2 op:concatenate
  //---------------------
  class op_concatenate : public function
  {
  public:
    op_concatenate(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
    xqtref_t return_type (const std::vector<xqtref_t> &arg_types) const;
    void compute_annotation (AnnotationHolder *parent, std::vector<AnnotationHolder *> &kids, Annotation::key_t k) const;
  };


  //15.1.3 fn:index-of
  //------------------

  typedef function_impl<FnIndexOfIterator> fn_index_of;


  //15.1.4 fn:empty
  //---------------

  typedef function_impl<FnEmptyIterator> fn_empty;


  //15.1.5 fn:exists
  //----------------

  typedef function_impl<FnExistsIterator> fn_exists;


  //15.1.6 fn:distinct-values
  //-------------------------
  class fn_distinct_values : public single_seq_function
  {
  public:
    fn_distinct_values(const signature& sig) : single_seq_function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };


  //15.1.7 fn:insert-before
  //-----------------------
  class fn_insert_before : public function
  {
  public:
    fn_insert_before(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };


  //15.1.8 fn:remove
  //----------------
  class fn_remove : public single_seq_function
  {
  public:
    fn_remove(const signature& sig) : single_seq_function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };


  //15.1.9 fn:reverse
  //-----------------
  class fn_reverse : public single_seq_function
  {
  public:
    fn_reverse(const signature& sig) : single_seq_function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };


  //15.1.10 fn:subsequence
  //----------------------
  class fn_subsequence : public single_seq_function
  {
  public:
    fn_subsequence(const signature&sig) : single_seq_function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
    void compute_annotation (AnnotationHolder *parent, std::vector<AnnotationHolder *> &kids, Annotation::key_t k) const;
  };


  /*______________________________________________________________________
    |  
    | 15.2 Functions That Test the Cardinality of Sequences
    |_______________________________________________________________________*/

  //15.2.1 fn:zero-or-one
  typedef function_impl<FnZeroOrOneIterator> fn_zero_or_one;

  //15.2.2 fn:one-or-more
  typedef function_impl<FnOneOrMoreIterator> fn_one_or_more;

  //15.2.3 fn:exactly-one
  class fn_exactly_one_noraise : public function
  {
  public:
    fn_exactly_one_noraise(const signature& sig) : function (sig), raise_err (false) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;

  protected:
    bool raise_err;
  };

  class fn_exactly_one : public fn_exactly_one_noraise {
  public:
    fn_exactly_one (const signature& sig) : fn_exactly_one_noraise (sig)
    { raise_err = true; }
  };

  /*______________________________________________________________________
    |
    | 15.3 Equals, Union, Intersection and Except
    |_______________________________________________________________________*/

  //15.3.1 fn:deep-equal
  class fn_deep_equal : public function
  {
  public:
    fn_deep_equal(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };


  //15.3.2 op:union
  class fn_union : public function
  {
  public:
    fn_union(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  //15.3.3 op:intersect
  class fn_intersect : public function
  {
  public:
    fn_intersect(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  //15.3.4 op:except
  class fn_except: public function
  {
  public:
    fn_except(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  /*______________________________________________________________________
    |
    | 15.4 Aggregate Functions
    |_______________________________________________________________________*/

  //15.4.1 fn:count
  typedef function_impl<FnCountIterator> fn_count;

  //15.4.2 fn:avg
  typedef function_impl<FnAvgIterator> fn_avg;

  //15.4.3 fn:max
  class fn_max_1 : public function
  {
  public:
    fn_max_1(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  class fn_max_2 : public fn_max_1
  {
  public:
    fn_max_2(const signature& sig)
      : fn_max_1(sig) { }
  };


  //15.4.4 fn:min
  //-------------
  class fn_min_1 : public function
  {
  public:
    fn_min_1(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  class fn_min_2 : public fn_min_1
  {
  public:
    fn_min_2(const signature& sig)
      : fn_min_1(sig) { }
  };

  //15.4.5 fn:sum
  typedef function_impl<FnSumIterator> fn_sum;


  /*______________________________________________________________________
    |
    | 15.5 Functions and Operators that Generate Sequences
    |_______________________________________________________________________*/

  //15.5.1 op:to
  typedef function_impl<OpToIterator> op_to;

  //15.5.2 fn:id
  typedef function_impl<FnIdIterator> fn_id;

  //15.5.3 fn:idref
  typedef function_impl<FnIdRefIterator> fn_id_ref;

  //15.5.4 fn:doc
  class fn_doc_func : public function
  {
  public:
    fn_doc_func(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
    virtual bool isSource() const { return true; }
    bool requires_dyn_ctx () const { return true; }  // TODO: rename to unfoldable()
  };

  class fn_parse_func : public function
  {
  public:
    fn_parse_func(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
    virtual bool isSource() const { return true; }
    bool requires_dyn_ctx () const { return true; }  // TODO: rename to unfoldable()
  };


  //15.5.5 fn:doc-available
  class fn_doc_available_func : public function
  {
  public:
    fn_doc_available_func(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };


  //15.5.6 fn:collection


} /* namespace zorba */
#endif /* ZORBA_SEQUENCES_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
