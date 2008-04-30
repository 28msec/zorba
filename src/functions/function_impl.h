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

/*
 * Local variables:
 * mode: c++
 * End:
 */
