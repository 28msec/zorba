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

#ifndef ZORBA_NODEID_INTERNAL_H
#define ZORBA_NODEID_INTERNAL_H

#include "functions/single_seq_func.h"

#include "zorbautils/checked_vector.h"

namespace zorba {


// internal distinct-nodes function

class op_node_sort_distinct : public single_seq_function 
{
public:
  typedef enum { NODES, ATOMICS, MIXED } nodes_or_atomics_t;

  op_node_sort_distinct(const signature& sig) : single_seq_function (sig) {}

  // (sort?, atomics?, distinct?, ascending?)
  virtual const bool *action () const = 0;

  static const function *op_for_action(
        const static_context *sctx,
        const bool *a,
        const AnnotationHolder *parent,
        const AnnotationHolder *child,
        nodes_or_atomics_t noa);

  virtual const function *min_action(
        const static_context *sctx,
        const AnnotationHolder *self,
        const AnnotationHolder *child,
        nodes_or_atomics_t noa) const;

  PlanIter_t codegen(
        CompilerCB* cb,
        short sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& argv,
        AnnotationHolder &ann) const;

  void compute_annotation(
        AnnotationHolder* parent,
        std::vector<AnnotationHolder *>& kids,
        Annotation::key_t k) const;
};


class op_either_nodes_or_atomics : public op_node_sort_distinct 
{
public:
  op_either_nodes_or_atomics (const signature& sig) : op_node_sort_distinct (sig) {}

  const bool *action () const 
  {
    //                         sort   atomics  distinct  ascendig
    static const bool a [] = { false, true,    false,    false };
    return a;
  }
};


class op_distinct_nodes : public op_node_sort_distinct
{
public:
  op_distinct_nodes(const signature& sig) : op_node_sort_distinct (sig) {}

  const bool *action () const 
  {
    //                         sort   atomics  distinct  ascendig
    static const bool a [] = { false, false,   true,     false };
    return a;
  }
};


/**
 * Similar to op-distinct, but it allows a sequences of atomic items as input 
 * (but no mixture of atomic and node items). In this case, the result is
 * equal to the input
 */
class op_distinct_nodes_or_atomics : public op_node_sort_distinct 
{
public:
  op_distinct_nodes_or_atomics(const signature& sig) : op_node_sort_distinct(sig) {}

  const bool *action () const {
    static const bool a [] = { false, true, true, false };
      return a;
  }
};
  

class op_sort_nodes_ascending : public op_node_sort_distinct
{
public:
  op_sort_nodes_ascending(const signature& sig) : op_node_sort_distinct (sig) {}
  
  const bool *action () const {
    static const bool a [] = { true, false, false, true };
    return a;
  }
};
  

/**
 * Similar to op-sort-ascending, but it allows a sequences of atomic items as input 
 * (but no mixture of atomic and node items). In this case, the result is
 * equal to the input
 */
class op_sort_nodes_asc_or_atomics : public op_node_sort_distinct {
public:
  op_sort_nodes_asc_or_atomics(const signature& sig) : op_node_sort_distinct (sig) {}

  const bool *action () const {
    static const bool a [] = { true, true, false, true };
    return a;
  }
};
  

class op_sort_nodes_descending : public op_node_sort_distinct
{
public:
  op_sort_nodes_descending(const signature& sig) : op_node_sort_distinct (sig) {}
  
  const bool *action () const {
    static const bool a [] = { true, false, false, false };
    return a;
  }
};


/**
 * Similar to op-sort-descending, but it allows a sequences of atomic items as input 
 * (but no mixture of atomic and node items). In this case, the result is
 * equal to the input
 */
class op_sort_nodes_desc_or_atomics : public op_node_sort_distinct
{
public:
  op_sort_nodes_desc_or_atomics(const signature& sig) : op_node_sort_distinct (sig) {}
  
  const bool *action () const {
    static const bool a [] = { true, true, false, false };
    return a;
  }
};
  

// sort nodes in document order and doing distinct-nodes in one run
class op_sort_distinct_nodes_ascending : public op_node_sort_distinct
{
public:
  op_sort_distinct_nodes_ascending(const signature& sig) : op_node_sort_distinct (sig) {}
  
  const bool *action () const {
    static const bool a [] = { true, false, true, true };
    return a;
  }
};


/**
 * Similar to sort-distinct-nodes-ascending, but it allows a sequences of atomic items as input 
 * (but no mixture of atomic and node items). In this case, the result is
 * equal to the input
 */
class op_sort_distinct_nodes_asc_or_atomics : public op_node_sort_distinct
{
public:
  op_sort_distinct_nodes_asc_or_atomics(const signature& sig) : op_node_sort_distinct (sig) {}

  const bool *action () const {
    static const bool a [] = { true, true, true, true };
    return a;
  }
};
  

// internal function for sort-nodes in reverse document order and doing distinct-nodes in one run
class op_sort_distinct_nodes_descending : public op_node_sort_distinct
{
public:
  op_sort_distinct_nodes_descending(const signature& sig) : op_node_sort_distinct (sig) {}

  const bool *action () const {
    static const bool a [] = { true, false, true, false };
    return a;
  }
};


class fn_unordered : public single_seq_function 
{
public:
  fn_unordered(const signature& sig) : single_seq_function (sig) {}

  PlanIter_t codegen(
        CompilerCB* cb,
        short sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& argv,
        AnnotationHolder &ann) const;

  void compute_annotation(
        AnnotationHolder *parent,
        std::vector<AnnotationHolder *> &kids,
        Annotation::key_t k) const;
};

}	/* namespace zorba */

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
