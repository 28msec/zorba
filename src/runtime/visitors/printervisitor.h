#ifndef ZORBA_PRINTERVISITOR_H
#define ZORBA_PRINTERVISITOR_H

#include "runtime/visitors/planitervisitor.h"

namespace zorba {

  class PlanIterator;
  class IterPrinter;
  
  void print_iter_plan (IterPrinter& aPrinter, PlanIterator* aIter);

} /* namespace zorba */

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */

