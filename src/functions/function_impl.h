#ifndef ZORBA_FUNCTION_IMPL_H
#define ZORBA_FUNCTION_IMPL_H

#include "functions/function.h"

namespace zorba {

  template <class Iter> class function_impl : public function {
  public:
    function_impl ( const signature& sig) : function (sig) {}
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const {
      return new Iter (loc, argv);
    }
  };

}

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
