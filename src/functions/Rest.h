#ifndef ZORBA_REST_H
#define ZORBA_REST_H

#include <vector>
#include "common/shared_types.h"
#include "functions/function.h"

namespace zorba {

class rest_get_1 : public function
{
public:
  rest_get_1(const signature&);

  PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  xqtref_t return_type (const std::vector<xqtref_t> &arg_types) const;
};

} /* namespace zorba */

#endif
