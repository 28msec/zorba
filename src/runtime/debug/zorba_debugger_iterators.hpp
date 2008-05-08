#ifndef XQP_ZORBA_DEBUGGER_ITERATORS_H
#define XQP_ZORBA_DEBUGGER_ITERATORS_H

#include <vector>

#include <boost/thread/mutex.hpp>

#include "runtime/base/narybase.h"

#include "compiler/parser/location.hh"

namespace zorba {

class ZorbaDebuggerImpl;

class FnDebugIterator : public NaryBaseIterator<FnDebugIterator, PlanIteratorState>
{
protected:
  ZorbaDebuggerImpl *  theDebugger;

public:
  FnDebugIterator( const QueryLoc& loc, std::vector<PlanIter_t>& args );

  virtual ~FnDebugIterator();

  store::Item_t nextImpl(PlanState& planState) const;

  void accept(PlanIterVisitor& v) const;

  void openImpl(PlanState& planState, uint32_t& offset );

};
} /* namespace zorba */

#endif /* XQP_DEBUG_ITERATORS_H */
/* vim:set ts=2 sw=2: */
