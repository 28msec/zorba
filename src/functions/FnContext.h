/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Authors: Tim Kraska
 */

#ifndef ZORBA_FN_CONTEXT_H
#define ZORBA_FN_CONTEXT_H

#include <vector>
#include "common/shared_types.h"
#include "functions/function.h"

/**
16.1 fn:position
16.2 fn:last
16.3 fn:current-dateTime
16.3.1 Examples
16.4 fn:current-date
16.4.1 Examples
16.5 fn:current-time
16.5.1 Examples
16.6 fn:implicit-timezone
16.7 fn:default-collation
16.8 fn:static-base-uri
*/


namespace zorba {

  
  
class ctx_variable : public function
{
public:
  ctx_variable(const signature&);
  ~ctx_variable() {}

public:
  PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;

  xqtref_t type_check(signature&) const;
  bool validate_args(std::vector<PlanIter_t>&) const;

  bool requires_dyn_ctx () const { return true; }
};
  
}


#endif  /* ZORBA_FN_CONTEXT_H */
