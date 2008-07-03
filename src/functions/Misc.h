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
#ifndef ZORBA_MISC_H
#define ZORBA_MISC_H

#include <vector>
#include "common/shared_types.h"
#include "functions/function.h"

namespace zorba {
  
  class fn_trace_func : public function {
  public:
    fn_trace_func(const signature& sig) : function (sig) {}    
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  class fn_error : public function {
  public:
    fn_error(const signature& sig) : function (sig) {}
    
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;

    virtual expr_update_t getUpdateType() const { return VACUOUS_EXPR; }
  };

  class fn_resolve_uri : public function {
  public:
    fn_resolve_uri(const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  class fn_read_string : public function {
  public:
    fn_read_string(const signature& sig) : function (sig) {}
    bool requires_dyn_ctx () const { return true; }
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  class fn_print : public function {
  public:
    fn_print(const signature& sig) : function (sig) {}
    bool requires_dyn_ctx () const { return true; }
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

}

#endif /* ZORBA_MISC_H */

/* vim:set ts=2 sw=2: */
/*
 * Local variables:
 * mode: c++
 * End:
 */
