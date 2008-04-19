#ifndef ZORBA_PLAN_VISITOR_H
#define ZORBA_PLAN_VISITOR_H

#include <vector>
#include "compiler/expression/expr.h"
#include "runtime/core/item_iterator.h"
#include "common/shared_types.h"


/*______________________________________________________________________
|  
|	 Design note: Visitor pattern.  See, for example:
|	 "Modern C++ Design" by Andrei Alexandrescu,
|  Addison Wesley (2001), Chapter 10.
|_______________________________________________________________________*/

namespace zorba {
  template <class T> class hash64map;

  PlanIter_t codegen (
        const char *descr,
        expr *root,
        hash64map<std::vector<LetVarIter_t> *> *param_var_map = NULL);

} /* namespace zorba */
#endif /* ZORBA_PLAN_VISITOR_H */
