#ifndef ZORBA_DEBUG_ITERATOR
#define ZORBA_DEBUG_ITERATOR

#include "common/shared_types.h"
#include "runtime/base/narybase.h"

#include <vector>

namespace zorba {
  class ZorbaDebugIterator : public NaryBaseIterator<ZorbaDebugIterator, PlanIteratorState>
  {
  public: // Constructor
    ZorbaDebugIterator ( short sctx, const QueryLoc& loc, std::vector<PlanIter_t>& aChildVector );
  public:
    void accept(PlanIterVisitor& v) const;
    bool nextImpl( store::Item_t& result, PlanState& planState ) const;
    void openImpl(PlanState& planState, uint32_t& offset );
    bool isUpdating() const;
    void setChildren(std::vector<PlanIter_t>& args);
    void addChild(ZorbaDebugIterator* child);
    void setParent(ZorbaDebugIterator* parent);
    QueryLoc getQueryLocation() const;
  public: // Debugger commands
    void setBreakpoint();
    void deleteBreakpoint();
  private:
    std::vector<ZorbaDebugIterator*>  theDebuggerChildren;
    ZorbaDebugIterator*               theDebuggerParent;
    bool                              theHasToBreak;
  };
}

#endif // ZORBA_DEBUG_ITERATOR
