#ifndef ZORBA_DEBUG_ITERATOR
#define ZORBA_DEBUG_ITERATOR

#include "common/shared_types.h"
#include "runtime/base/narybase.h"

#include <vector>
#include <map>

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
  public: // Setters
    /**
    * @brief Sets the parent of the current debugger in the debugger tree.
    *
    * This object represents the parent in the current debugger tree. This
    * is used to search other breakable expressions if the user wants to
    * step and the runtime has to look for the appropriate debugger
    * iterator. If parent is NULL, this means, that we are at the root of
    * the tree.
    *
    * @param parent The parent of this debugger iterator.
    * @post getParent() == parent
    */
    void setParent(ZorbaDebugIterator* parent);
    /**
    * @brief Adds a child to this debugger iterator.
    *
    * This method is intended to be used by the planvisitor to create the
    * debugger tree. The element is added as the last child of this debugger
    * iterator.
    *
    * @pre child != 0
    * @post theDebuggerChildren.back() == child
    */
    void addChild(ZorbaDebugIterator* child);
    void setChildren(std::vector<PlanIter_t>& args);
  public: // Getters
    /**
    * @brief Returns the parent of the current debugger iterator.
    *
    * If the result is null, this node is the root node in the debugger
    * tree.
    */
    const ZorbaDebugIterator* getParent() const;
    /**
    * @brief Gets the debugger iterator according to the rules of a step
    *  over.
    *
    * @return NULL, if the iterator does not have a parent; the parent
    *  if the iterator does not have any right-handed silblings, the next
    *  right handed silbling otherwise.
    */
    const ZorbaDebugIterator* getOverIterator() const;
    QueryLoc getQueryLocation() const;
  private:
    std::vector<ZorbaDebugIterator*>  theDebuggerChildren;
    ZorbaDebugIterator*               theDebuggerParent;
  };
}

#endif // ZORBA_DEBUG_ITERATOR
