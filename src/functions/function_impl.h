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
#ifndef ZORBA_FUNCTION_IMPL_H
#define ZORBA_FUNCTION_IMPL_H

#include "system/globalenv.h"

#include "functions/function.h"

#include "store/api/store.h"
#include "store/api/item_factory.h"

#include "context/static_context.h"

#define ITEM_FACTORY (*(GENV.getStore().getItemFactory()))

#define DECL(sctx, type, sig)                                  \
do                                                             \
{                                                              \
  std::auto_ptr<function> type##_ptr(new type(signature sig)); \
                                                               \
  sctx->bind_fn(type##_ptr->get_fname (),                      \
                type##_ptr.get(),                              \
                type##_ptr->get_signature().arg_count());      \
  type##_ptr.release();                                        \
} while(0)


namespace zorba {

  static inline store::Item_t createQName(const char *ns, const char *pre, const char *local)
  {
    store::Item_t res;
    ITEM_FACTORY.createQName(res, ns, pre, local);
    return res;
  }


  template <class Iter> class function_impl : public function {
  public:
    function_impl ( const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const {
      return new Iter (loc, argv);
    }
  };

}	/* namespace zorba */

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
