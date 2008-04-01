
#include "common/shared_types.h"
#include "errors/fatal.h"
#include "system/globalenv.h"
#include "context/static_context.h"
#include "runtime/api/runtimecb.h"
#include "runtime/update/update.h"
#include "store/api/pul.h"
#include "store/api/update_consts.h"
#include "store/api/item.h"
#include "store/api/item_factory.h"

namespace zorba {


/*******************************************************************************

********************************************************************************/
void
InsertIteratorState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  static_context* sctx = planState.theRuntimeCB->theStaticContext;

  theCopyMode.theTypePreserve =
    (sctx->construction_mode() == StaticContextConsts::cons_preserve ? true : false);

  theCopyMode.theNsPreserve =
    (sctx->preserve_mode() == StaticContextConsts::preserve_ns ? true : false);

  theCopyMode.theNsInherit = 
    (sctx->inherit_mode() == StaticContextConsts::inherit_ns ? true : false);
}


void
InsertIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
}


InsertIterator::InsertIterator (
  const QueryLoc&                 aLoc,
  store::UpdateConsts::InsertType aType,
  PlanIter_t                      source,
  PlanIter_t                      target)
:
  BinaryBaseIterator<InsertIterator, InsertIteratorState>(aLoc, source, target),
  theType(aType),
  theDoCopy(true)
{
}


store::Item_t
InsertIterator::nextImpl (PlanState& aPlanState) const
{
  store::StoreConsts::NodeKind targetKind;
  bool elemParent;
  bool elemTarget;
  store::Item_t parent;
  store::Item_t target;
  store::Item_t source;
  std::vector<store::Item_t> attrs(16);
  std::vector<store::Item_t> nodes(16);
  ulong numAttrs = 0;
  ulong numNodes = 0;
  std::auto_ptr<store::PUL> pul;

  InsertIteratorState* state;
  DEFAULT_STACK_INIT(InsertIteratorState, state, aPlanState);

  target = consumeNext(theChild1, aPlanState);

  if (target == NULL)
  {
    ZORBA_ERROR_LOC(ZorbaError::XUDY0027, loc);
  }

  targetKind = target->getNodeKind();

  if (theType == store::UpdateConsts::BEFORE || theType == store::UpdateConsts::AFTER)
  {
    if (!target->isNode() || targetKind == store::StoreConsts::attributeNode)
      ZORBA_ERROR_LOC(ZorbaError::XUTY0006, loc);

    if (consumeNext(theChild1, aPlanState) != NULL)
      ZORBA_ERROR_LOC(ZorbaError::XUTY0006, loc);

    if (target->getParent() == NULL)
      ZORBA_ERROR_LOC(ZorbaError::XUDY0029, loc);

    parent = target->getParent();

    elemParent = (parent->getNodeKind() == store::StoreConsts::elementNode);

    source = consumeNext(theChild0, aPlanState);

    while (source != NULL)
    {
      ZORBA_FATAL(source->isNode(), "");

      if (source->getNodeKind() == store::StoreConsts::attributeNode)
      {
        if (!elemParent)
          ZORBA_ERROR_LOC(ZorbaError::XUDY0030, loc);

        attrs[numAttrs++].transfer(source);
        if (numAttrs == attrs.size())
          attrs.resize(2 * numAttrs);
      }
      else
      {
        nodes[numNodes++].transfer(source);
        if (numNodes == nodes.size())
          nodes.resize(2 * numNodes);
      }

      source = consumeNext(theChild0, aPlanState);
    }

    pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

    if (numAttrs > 0)
    {
      attrs.resize(numAttrs);
      pul->addInsertAttributes(parent, attrs, theDoCopy, state->theCopyMode);
    }

    if (numNodes > 0)
    {
      nodes.resize(numNodes);
      if (theType == store::UpdateConsts::BEFORE)
        pul->addInsertBefore(target, nodes, theDoCopy, state->theCopyMode);
      else
        pul->addInsertAfter(target, nodes, theDoCopy, state->theCopyMode);
    }

    STACK_PUSH(pul.release(), state);
  }
  else
  {
    if (!target->isNode() ||
        (targetKind != store::StoreConsts::documentNode &&
         targetKind != store::StoreConsts::elementNode))
      ZORBA_ERROR_LOC(ZorbaError::XUTY0005, loc);

    if (consumeNext(theChild1, aPlanState) != NULL)
      ZORBA_ERROR_LOC(ZorbaError::XUTY0005, loc);

    elemTarget = (targetKind == store::StoreConsts::elementNode);

    source = consumeNext(theChild0, aPlanState);

    while (source != NULL)
    {
      ZORBA_FATAL(source->isNode(), "");

      if (source->getNodeKind() == store::StoreConsts::attributeNode)
      {
        if (!elemParent)
          ZORBA_ERROR_LOC(ZorbaError::XUTY0022, loc);

        attrs[numAttrs++].transfer(source);
        if (numAttrs == attrs.size())
          attrs.resize(2 * numAttrs);
      }
      else
      {
        nodes[numNodes++].transfer(source);
        if (numNodes == nodes.size())
          nodes.resize(2 * numNodes);
      }

      source = consumeNext(theChild0, aPlanState);
    }

    pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

    if (numAttrs > 0)
    {
      attrs.resize(numAttrs);
      pul->addInsertAttributes(target, attrs, theDoCopy, state->theCopyMode);
    }

    if (numNodes > 0)
    {
      nodes.resize(numNodes);
      if (theType == store::UpdateConsts::INTO)
        pul->addInsertInto(target, nodes, theDoCopy, state->theCopyMode);
      else if (theType == store::UpdateConsts::AS_FIRST_INTO)
        pul->addInsertFirst(target, nodes, theDoCopy, state->theCopyMode);
      else
        pul->addInsertLast(target, nodes, theDoCopy, state->theCopyMode);
    }

    STACK_PUSH(pul.release(), state);
  }

  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
store::Item_t
DeleteIterator::nextImpl(PlanState& aPlanState) const
{ 
  PlanIteratorState* aState;
  DEFAULT_STACK_INIT(PlanIteratorState, aState, aPlanState);
  STACK_END (aState);
}


/*******************************************************************************

********************************************************************************/
ReplaceIterator::ReplaceIterator (
  const QueryLoc& aLoc,
  store::UpdateConsts::ReplaceType aType,
  PlanIter_t aChild0,
  PlanIter_t aChild1)
:
  BinaryBaseIterator<ReplaceIterator, PlanIteratorState>(aLoc, aChild0, aChild1),
  theType(aType)
{}

store::Item_t
ReplaceIterator::nextImpl (PlanState& aPlanState) const
{
  PlanIteratorState* aState;
  DEFAULT_STACK_INIT(PlanIteratorState, aState, aPlanState);
  STACK_END (aState);
}


/*******************************************************************************

********************************************************************************/
store::Item_t
RenameIterator::nextImpl(PlanState& aPlanState) const
{
  PlanIteratorState* aState;
  DEFAULT_STACK_INIT(PlanIteratorState, aState, aPlanState);
  STACK_END (aState);
}


/*******************************************************************************

********************************************************************************/
TransformIterator::TransformIterator(
  const QueryLoc& aLoc,
  PlanIter_t aModifyIter,
  PlanIter_t aReturnIter)
:
  Batcher<TransformIterator>(aLoc),
  theModifyIter(aModifyIter),
  theReturnIter(aReturnIter)
{}

void
TransformIterator::addAssign(PlanIter_t anIter)
{
  theAssignIters.push_back(anIter); 
}

store::Item_t
TransformIterator::nextImpl(PlanState& aPlanState) const
{
  PlanIteratorState* aState;
  DEFAULT_STACK_INIT(PlanIteratorState, aState, aPlanState);
  STACK_END (aState);
}

void 
TransformIterator::openImpl ( PlanState& planState, uint32_t& offset ) {
  StateTraitsImpl<PlanIteratorState>::createState(planState, this->stateOffset, offset);

  std::vector<PlanIter_t>::iterator lIter = theAssignIters.begin();
  std::vector<PlanIter_t>::iterator lEnd = theAssignIters.end();
  for ( ; lIter != lEnd ; ++lIter )
  {
    (*lIter)->open(planState, offset );
  }
  theModifyIter->open( planState, offset );
  theReturnIter->open( planState , offset);
}

void 
TransformIterator::resetImpl ( PlanState& planState ) const
{
  StateTraitsImpl<PlanIteratorState>::reset(planState, this->stateOffset);
  
  std::vector<PlanIter_t>::const_iterator lIter = theAssignIters.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theAssignIters.end();
  for ( ; lIter != lEnd ; ++lIter )
  {
    (*lIter)->reset(planState);
  }
  theModifyIter->reset( planState );
  theReturnIter->reset( planState );
}

void 
TransformIterator::closeImpl ( PlanState& planState ) const
{
  std::vector<PlanIter_t>::const_iterator lIter = theAssignIters.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theAssignIters.end();
  for ( ; lIter != lEnd ; ++lIter )
  {
    (*lIter)->close(planState);
  }
  theModifyIter->close( planState );
  theReturnIter->close( planState );

  StateTraitsImpl<PlanIteratorState>::destroyState(planState, this->stateOffset);
}

uint32_t 
TransformIterator::getStateSizeOfSubtree() const {
  uint32_t lSize = getStateSize();
  std::vector<PlanIter_t>::const_iterator lIter = theAssignIters.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theAssignIters.end();
  for ( ; lIter != lEnd ; ++lIter )
  {
    lSize += (*lIter)->getStateSizeOfSubtree();
  }
  lSize += theModifyIter->getStateSizeOfSubtree();
  lSize += theReturnIter->getStateSizeOfSubtree();
  return lSize;
}
} // namespace zorba
