#include <memory>

#include "runtime/api/plan_wrapper.h"

namespace zorba {

// RAII-style class
class PlanWrapperHolder {
  std::auto_ptr<PlanWrapper> pw;
  
public:
  PlanWrapperHolder (PlanWrapper *pw_)
    : pw (pw_)
  { pw->open (); }
  PlanWrapperHolder () {}
  ~PlanWrapperHolder() {
    if (pw.get () != NULL)
      pw->close ();
  }
  
  void reset (PlanWrapper *pw_) {
    pw.reset (pw_);
    pw->open ();
  }
  PlanWrapper *get () { return pw.get (); }
  PlanWrapper *operator-> () { return pw.get(); }
};

}

/*
 * Local variables:
 * mode: c++
 * End:
 */
