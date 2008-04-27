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
#ifndef ZORBA_ACCESSORS_H
#define ZORBA_ACCESSORS_H

#include <vector>
#include "common/shared_types.h"
#include "functions/single_seq_func.h"

namespace zorba {

  class fn_data_func : public single_seq_function
  {
  public:
    fn_data_func ( const signature& sig) : single_seq_function (sig) {}    
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
    xqtref_t return_type (const std::vector<xqtref_t> &arg_types) const;
  };


  class fn_root_func : public function
  {
  public:
    fn_root_func(const signature& s);
    
  public:
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  class fn_nodename_func : public function
  {
  public:
    fn_nodename_func(const signature& s);
    
  public:
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  class fn_nilled_func : public function
  {
  public:
    fn_nilled_func(const signature& s);
    
  public:
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  class fn_base_uri_func : public function
  {
  public:
    fn_base_uri_func(const signature& s);
    
  public:
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  class fn_document_uri_func : public function
  {
  public:
    fn_document_uri_func(const signature& s);
    
  public:
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };
  
  class fn_name_func : public function
  {
  public:
    fn_name_func(const signature& s);
    
  public:
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };
} /* namespace zorba */

#endif /* ZORBA_ACCESSORS_H */
