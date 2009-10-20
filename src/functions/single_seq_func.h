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
#ifndef ZORBA_SINGLE_SEQ_FUNC_H
#define ZORBA_SINGLE_SEQ_FUNC_H

#include "functions/function.h"

namespace zorba {

/*******************************************************************************
  A function that processes a single sequence. Assumptions:
  - Return type is the same as type of the sequence argument.
  - Preserves sorted/disctinct node annotations from children.
  - Propagates IGNORES_* properties downward.
  - Only propagates sequence arg to output.
*******************************************************************************/
class single_seq_function : public function 
{
protected:
  unsigned src;
  
public:
  single_seq_function(const signature& sig, FunctionConsts::FunctionKind kind, unsigned src_ = 0)
    :
    function (sig, kind),
    src (src_)
  {}

  xqtref_t return_type (const std::vector<xqtref_t> &arg_types) const;

  void compute_annotation(
        AnnotationHolder* parent,
        std::vector<AnnotationHolder *>& kids,
        Annotations::Key k) const;

  ZORBA_PROPAGATES_ONE_I2O (src);
  ZORBA_PRESERVES_SORTED
  ZORBA_PRESERVES_DISTINCT
};


/*******************************************************************************
  Like single_seq_function, but may not return all items in the sequence arg.
*******************************************************************************/
class single_seq_opt_function : public function 
{
protected:
  unsigned src;
  
public:
  single_seq_opt_function(const signature& sig, FunctionConsts::FunctionKind kind, unsigned src_ = 0) 
    :
    function (sig, kind),
    src (src_)
  {}

  xqtref_t return_type (const std::vector<xqtref_t> &arg_types) const;
};

}

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
