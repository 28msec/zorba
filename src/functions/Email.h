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
#ifndef ZORBA_FUNCTIONS_EMAIL_H
#define ZORBA_FUNCTIONS_EMAIL_H

#include <vector>
#include "common/shared_types.h"
#include "functions/function.h"

namespace zorba {

  class zorba_mail : public function
  {
    public:
      zorba_mail(const signature& sig): function(sig){}

      PlanIter_t codegen (CompilerCB* cb,
                          short sctx,
                          const QueryLoc& loc,
                          std::vector<PlanIter_t>& argv,
                          AnnotationHolder &ann) const;
  };
}

#endif /* ZORBA_FUNCTIONS_EMAIL_H */

/* vim:set ts=2 sw=2: */
/*
 * Local variables:
 * mode: c++
 * End:
 */
