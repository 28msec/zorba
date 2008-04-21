#include <memory>

#include "runtime/api/plan_wrapper.h"

namespace zorba {

// RAII-style class
class PlanWrapperHolder {
  std::auto_ptr<PlanWrapper> pw;
  
 public:
  PlanWrapperHolder (PlanIter_t plan, CompilerCB* compilercb) : pw (new PlanWrapper (plan, compilercb, 0))
  { pw->open (); }
  ~PlanWrapperHolder() { pw->close (); }
  PlanWrapper *operator-> () { return pw.get(); }
};

}
