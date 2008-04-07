
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

namespace zorba 
{

/*******************************************************************************

********************************************************************************/
InsertIterator::InsertIterator (
  const QueryLoc&                 aLoc,
  store::UpdateConsts::InsertType aType,
  PlanIter_t                      source,
  PlanIter_t                      target)
  :
  BinaryBaseIterator<InsertIterator, PlanIteratorState>(aLoc, source, target),
  theType(aType),
  theDoCopy(true)
{
  if (source->isUpdateIterator())
    ZORBA_ERROR_LOC(ZorbaError::XUST0001, aLoc);

  if (target->isUpdateIterator())
    ZORBA_ERROR_LOC(ZorbaError::XUST0001, aLoc);
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

  static_context* sctx;
  store::CopyMode lCopyMode;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);

  sctx = aPlanState.theRuntimeCB->theStaticContext;
  lCopyMode = store::CopyMode(
    sctx->construction_mode(),
    sctx->preserve_mode(),
    sctx->inherit_mode());

  target = consumeNext(theChild1, aPlanState);

  if (target == NULL)
  {
    ZORBA_ERROR_LOC(ZorbaError::XUDY0027, loc);
  }

  if (theType == store::UpdateConsts::BEFORE ||
      theType == store::UpdateConsts::AFTER)
  {
    if (!target->isNode() ||
        target->getNodeKind() == store::StoreConsts::attributeNode ||
        target->getNodeKind() == store::StoreConsts::documentNode)
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
        if (numNodes > 0)
          ZORBA_ERROR_LOC(ZorbaError::XUTY0004, loc);

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

      pul->addInsertAttributes(parent, attrs, theDoCopy, lCopyMode);
    }

    if (numNodes > 0)
    {
      nodes.resize(numNodes);
      if (theType == store::UpdateConsts::BEFORE)
        pul->addInsertBefore(target, nodes, theDoCopy, lCopyMode);
      else
        pul->addInsertAfter(target, nodes, theDoCopy, lCopyMode);
    }

    STACK_PUSH(pul.release(), state);
  }
  else
  {
    if (!target->isNode())
      ZORBA_ERROR_LOC(ZorbaError::XUTY0005, loc);

    targetKind = target->getNodeKind();

    if (targetKind != store::StoreConsts::documentNode &&
        targetKind != store::StoreConsts::elementNode)
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
        if (numNodes > 0)
          ZORBA_ERROR_LOC(ZorbaError::XUTY0004, loc);

        if (!elemTarget)
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
      pul->addInsertAttributes(target, attrs, theDoCopy, lCopyMode);
    }

    if (numNodes > 0)
    {
      nodes.resize(numNodes);
      if (theType == store::UpdateConsts::INTO)
        pul->addInsertInto(target, nodes, theDoCopy, lCopyMode);
      else if (theType == store::UpdateConsts::AS_FIRST_INTO)
        pul->addInsertFirst(target, nodes, theDoCopy, lCopyMode);
      else
        pul->addInsertLast(target, nodes, theDoCopy, lCopyMode);
    }

    STACK_PUSH(pul.release(), state);
  }

  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
DeleteIterator::DeleteIterator(const QueryLoc& aLoc, PlanIter_t target)
  :
  UnaryBaseIterator<DeleteIterator, PlanIteratorState>(aLoc, target)
{
  if (target->isUpdateIterator())
    ZORBA_ERROR_LOC(ZorbaError::XUST0001, aLoc);
}


store::Item_t
DeleteIterator::nextImpl(PlanState& aPlanState) const
{ 
  store::Item_t target;
  std::auto_ptr<store::PUL> pul;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);

  pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

  target = consumeNext(theChild, aPlanState);

  while (target != NULL)
  {
    if (!target->isNode())
      ZORBA_ERROR_LOC(ZorbaError::XUTY0007, loc);

    pul->addDelete(target);

    target = consumeNext(theChild, aPlanState);
  }

  STACK_PUSH(pul.release(), state);
  STACK_END(state);
}


/*******************************************************************************

********************************************************************************/
ReplaceIterator::ReplaceIterator (
  const QueryLoc& aLoc,
  store::UpdateConsts::ReplaceType aType,
  PlanIter_t target,
  PlanIter_t source)
  :
  BinaryBaseIterator<ReplaceIterator, PlanIteratorState>(aLoc, target, source),
  theType(aType),
  theDoCopy(true)
{
}


store::Item_t
ReplaceIterator::nextImpl (PlanState& aPlanState) const
{
  store::StoreConsts::NodeKind lTargetKind;
  store::StoreConsts::NodeKind lWithKind;
  store::Item_t lWith;
  store::Item_t lTarget;
  store::Item_t lParent;
  std::vector<store::Item_t> lNodes(16);
  std::vector<store::Item_t> lAttrs(16);
  ulong lNumNodes = 0;
  ulong lNumAttrs = 0;
  std::auto_ptr<store::PUL> lPul;

  static_context* sctx;
  store::CopyMode lCopyMode;

  PlanIteratorState* lState;
  DEFAULT_STACK_INIT(PlanIteratorState, lState, aPlanState);
  
  sctx = aPlanState.theRuntimeCB->theStaticContext;
  lCopyMode = store::CopyMode(
    sctx->construction_mode(),
    sctx->preserve_mode(),
    sctx->inherit_mode());

  lTarget = consumeNext(theChild0, aPlanState);
  if (lTarget == 0)
  {
    ZORBA_ERROR_LOC(ZorbaError::XUDY0027, loc);
  }
  if (consumeNext(theChild0, aPlanState) != 0) {
    ZORBA_ERROR_LOC(ZorbaError::XUST0001, loc);
  }
  lTargetKind = lTarget->getNodeKind();

  if (!( lTarget->isNode() && (
     lTargetKind == store::StoreConsts::elementNode
  || lTargetKind == store::StoreConsts::attributeNode
  || lTargetKind == store::StoreConsts::textNode
  || lTargetKind == store::StoreConsts::commentNode
  || lTargetKind == store::StoreConsts::piNode
  )))
  {
    ZORBA_ERROR_LOC(ZorbaError::XUTY0008, loc);
  }

  if (theType == store::UpdateConsts::NODE) {
    if (lTarget->getParent() == 0)
    {
      ZORBA_ERROR_LOC(ZorbaError::XUDY0009, loc);
    }
    lParent = lTarget->getParent();
    
    if ( lTargetKind == store::StoreConsts::attributeNode)
    {
      lWith = consumeNext(theChild1, aPlanState);
      while (lWith != 0) 
      {
        lWithKind = lWith->getNodeKind();
        if (!(lWith->isNode() && lWithKind == store::StoreConsts::attributeNode))
        {
          ZORBA_ERROR_LOC(ZorbaError::XUTY0011, loc);
        }
        lAttrs[lNumAttrs++].transfer(lWith);
        if (lNumAttrs == lAttrs.size())
          lAttrs.resize(2 * lNumAttrs);

        lWith = consumeNext(theChild1, aPlanState);
      }
    } else {
      lWith = consumeNext(theChild1, aPlanState);
      while (lWith != 0)
      {
        lWithKind = lWith->getNodeKind();
        if (!(lWith->isNode() && (
           lWithKind == store::StoreConsts::elementNode
        || lWithKind == store::StoreConsts::textNode
        || lWithKind == store::StoreConsts::commentNode
        || lWithKind == store::StoreConsts::piNode
        )))
        {
          ZORBA_ERROR_LOC(ZorbaError::XUTY0010, loc);
        }
        lNodes[lNumNodes++].transfer(lWith);
        if (lNumNodes == lNodes.size())
          lNodes.resize(2 * lNumNodes);

        lWith = consumeNext(theChild1, aPlanState);
      }

    }
    lPul.reset(GENV_ITEMFACTORY->createPendingUpdateList());
    if (lNumNodes > 0)
    {
      lNodes.resize(lNumNodes);
      lPul->addReplaceNode(lTarget, lNodes, theDoCopy, lCopyMode);
    }
  } else {
    // the compiler added a test constructor around
    // the with expression => lWith is always a text node
    lWith = consumeNext(theChild1, aPlanState); 
    lPul.reset(GENV_ITEMFACTORY->createPendingUpdateList());
    if (lTargetKind == store::StoreConsts::elementNode)
    {
      lPul->addReplaceContent(lTarget, lWith, theDoCopy, lCopyMode);
    } else {
      xqp_string lText;
      if (lWith != 0)
        lText = lWith->getStringValueP();
      else
        lText = "";
      if (lTargetKind == store::StoreConsts::commentNode
      && (lText.indexOf("--") >= 0 || lText.endsWith("-")))
      {
          ZORBA_ERROR_LOC(ZorbaError::XQDY0072, loc);
      }
      if (lTargetKind == store::StoreConsts::piNode && lText.indexOf("?>") >= 0)
      {
          ZORBA_ERROR_LOC(ZorbaError::XQDY0026, loc);
      }
      lPul->addReplaceValue(lTarget, lText.theStrStore);
    }
  }

  STACK_PUSH(lPul.release(), lState);

  STACK_END (lState);
}


/*******************************************************************************

********************************************************************************/
RenameIterator::RenameIterator (
    const QueryLoc& aLoc,
    PlanIter_t target,
    PlanIter_t name)
  :
  BinaryBaseIterator<RenameIterator, PlanIteratorState>(aLoc, target, name)
{
}


store::Item_t
RenameIterator::nextImpl(PlanState& aPlanState) const
{
  store::StoreConsts::NodeKind lTargetKind;
  store::Item_t lTarget;
  store::Item_t lNewname;
  std::auto_ptr<store::PUL> lPul;

  PlanIteratorState* lState;
  DEFAULT_STACK_INIT(PlanIteratorState, lState, aPlanState);

  lTarget = consumeNext(theChild0, aPlanState);
  if (lTarget == NULL)
  {
    ZORBA_ERROR_LOC(ZorbaError::XUDY0027, loc);
  }
  
  lTargetKind = lTarget->getNodeKind();

  if (!(lTarget->isNode() && (
      lTargetKind == store::StoreConsts::elementNode
   || lTargetKind == store::StoreConsts::attributeNode
   || lTargetKind == store::StoreConsts::piNode
  )))
  {
    ZORBA_ERROR_LOC(ZorbaError::XUTY0012, loc);
  }

  if (consumeNext(theChild0, aPlanState) != 0)
  {
    ZORBA_ERROR_LOC(ZorbaError::XUTY0012, loc);
  }

  // because of codegen, it can be assumed that newname is already a qname 
  lNewname = consumeNext(theChild1, aPlanState);

  lPul.reset(GENV_ITEMFACTORY->createPendingUpdateList());
  lPul->addRename(lTarget, lNewname);

  STACK_PUSH(lPul.release(), lState);

  STACK_END (lState);
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
