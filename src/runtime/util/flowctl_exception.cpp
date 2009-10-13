#include "runtime/util/flowctl_exception.h"
#include "store/api/iterator.h"

namespace zorba {


  ExitException::ExitException( store::Iterator_t val_ )
    : FlowCtlException (EXIT),
    val (val_)
  {}

  ExitException::~ExitException()
  {
  }
}
