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
#ifndef ZORBA_NODES_H
#define ZORBA_NODES_H

#include <vector>
#include "common/shared_types.h"
#include "functions/function.h"

namespace zorba {

  class fn_local_name : public function {
  public:
    fn_local_name(const signature&);    
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  class fn_namespace_uri : public function {
  public:
    fn_namespace_uri(const signature&);
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  class fn_lang : public function {
  public:
    fn_lang(const signature&);
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  class fn_collection : public function {
  public:
    fn_collection(const signature&);
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
    bool requires_dyn_ctx () const { return true; }  // TODO: rename to unfoldable()
  };

}

#endif /* ZORBA_NODES_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
