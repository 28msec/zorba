#ifndef FLOWCTL_EXCEPTION
#include "common/common.h"
#include "zorbaerrors/errors.h"

namespace zorba {

  class FlowCtlException : public error::ZorbaInternalException {
  public:
    enum action {
      BREAK, CONTINUE, EXIT, INTERRUPT
    };
  public:
    enum action act;

    FlowCtlException (enum action act_)
      : act (act_) 
    {}
  };

  class ExitException : public FlowCtlException {
  public:
    virtual ~ExitException();
    store::Iterator_t val;
    ExitException (store::Iterator_t val_);
  };
}

#define FLOWCTL_EXCEPTION 
#endif // FLOWCTL_EXCEPTION
