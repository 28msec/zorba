
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
#include "runtime/core/var_iterators.h"
#include "store/api/store.h"
#include "runtime/api/plan_iterator_wrapper.h"
#include "store/api/temp_seq.h"
#include "store/api/copymode.h"
#include "store/api/item_iterator.h"

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
{ }


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
{ }


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
{ }


store::Item_t
ReplaceIterator::nextImpl (PlanState& aPlanState) const
{
  store::StoreConsts::NodeKind lTargetKind;
  store::StoreConsts::NodeKind lWithKind;
  store::Iterator_t withWrapper;
  store::Item_t lWith;
  store::Item_t lTarget;
  store::Item_t lParent;
  std::vector<store::Item_t> lNodes(16);
  ulong lNumNodes = 0;
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
    ZORBA_ERROR_LOC(ZorbaError::XUDY0027, loc);

  if (consumeNext(theChild0, aPlanState) != 0)
    ZORBA_ERROR_LOC(ZorbaError::XUTY0008, loc);

  if (!lTarget->isNode())
     ZORBA_ERROR_LOC(ZorbaError::XUTY0008, loc);

  lTargetKind = lTarget->getNodeKind();

  if (!( lTargetKind == store::StoreConsts::elementNode ||
         lTargetKind == store::StoreConsts::attributeNode ||
         lTargetKind == store::StoreConsts::textNode ||
         lTargetKind == store::StoreConsts::commentNode ||
         lTargetKind == store::StoreConsts::piNode))
  {
    ZORBA_ERROR_LOC(ZorbaError::XUTY0008, loc);
  }

  if (theType == store::UpdateConsts::NODE) 
  {
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
        if (!lWith->isNode() ||
            lWith->getNodeKind() != store::StoreConsts::attributeNode)
        {
          ZORBA_ERROR_LOC(ZorbaError::XUTY0011, loc);
        }

        lNodes[lNumNodes++].transfer(lWith);
        if (lNumNodes == lNodes.size())
          lNodes.resize(2 * lNumNodes);

        lWith = consumeNext(theChild1, aPlanState);
      }
    }
    else
    {
      lWith = consumeNext(theChild1, aPlanState);
      while (lWith != 0)
      {
        if (!lWith->isNode())
          ZORBA_ERROR_LOC(ZorbaError::XUTY0010, loc);

        lWithKind = lWith->getNodeKind();

        if (!(lWithKind == store::StoreConsts::elementNode
              || lWithKind == store::StoreConsts::textNode
              || lWithKind == store::StoreConsts::commentNode
              || lWithKind == store::StoreConsts::piNode))
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

    lNodes.resize(lNumNodes);
    lPul->addReplaceNode(lTarget, lNodes, theDoCopy, lCopyMode);
  }
  else
  {
    lPul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

    if (lTargetKind == store::StoreConsts::elementNode)
    {

      withWrapper = new PlanIteratorWrapper(theChild1, aPlanState);

      lWith = GENV_ITEMFACTORY->createTextNode((ulong)&aPlanState,
                                               withWrapper,
                                               false,
                                               true);

      lPul->addReplaceContent(lTarget, lWith, theDoCopy, lCopyMode);
    }
    else
    {
      std::auto_ptr<xqpStringStore> stringValue(new xqpStringStore(""));

      lWith = consumeNext(theChild1, aPlanState); 
      while (lWith != 0)
      {
        stringValue->str() += lWith->getStringValue()->c_str();

        lWith = consumeNext(theChild1, aPlanState);
      }

      if (lTargetKind == store::StoreConsts::commentNode &&
          (stringValue->indexOf("--") >= 0 || stringValue->endsWith("-")))
      {
        ZORBA_ERROR_LOC(ZorbaError::XQDY0072, loc);
      }
      else if (lTargetKind == store::StoreConsts::piNode &&
               stringValue->indexOf("?>") >= 0)
      {
        ZORBA_ERROR_LOC(ZorbaError::XQDY0026, loc);
      }

      lPul->addReplaceValue(lTarget, stringValue.release());
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
{ }


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
  
  if (!lTarget->isNode())
    ZORBA_ERROR_LOC(ZorbaError::XUTY0012, loc);

  lTargetKind = lTarget->getNodeKind();

  if (!(lTargetKind == store::StoreConsts::elementNode ||
        lTargetKind == store::StoreConsts::attributeNode ||
        lTargetKind == store::StoreConsts::piNode))
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
  std::vector<CopyClause>& aCopyClauses,
  PlanIter_t aModifyIter,
  PlanIter_t aReturnIter)
  :
  Batcher<TransformIterator>(aLoc),
  theCopyClauses(aCopyClauses),
  theModifyIter(aModifyIter),
  theReturnIter(aReturnIter)
{
}


TransformIterator::~TransformIterator(){}


store::Item_t
TransformIterator::nextImpl(PlanState& aPlanState) const
{
  CopyClause::const_iter_t lIter, lEnd;
  std::vector<ref_iter_t>::const_iterator lIter2, lEnd2;
  store::Item_t lItem;
  store::CopyMode lCopyMode;

  PlanIteratorState* aState;
  DEFAULT_STACK_INIT(PlanIteratorState, aState, aPlanState);

  {
    lIter = theCopyClauses.begin();
    lEnd = theCopyClauses.end();
    for(; lIter != lEnd; ++lIter)
    {
      store::Item_t lCopyItem = consumeNext(lIter->theInput, aPlanState);
      if (lCopyItem == 0 || !lCopyItem->isNode())
      {
        ZORBA_ERROR_LOC(ZorbaError::XUTY0013, loc);
      }
      lCopyItem = lCopyItem->copyXmlTree(lCopyMode);
      if (consumeNext(lIter->theInput, aPlanState))
      {
        ZORBA_ERROR_LOC(ZorbaError::XUTY0013, loc);
      }

      lIter2 = lIter->theCopyVars.begin();
      lEnd2 = lIter->theCopyVars.end();
      for(;lIter2!=lEnd2;++lIter2)
      {
        store::Iterator_t lSeqIter = new store::ItemIterator(lCopyItem);
        lSeqIter->open();
        (*lIter2)->bind(lSeqIter, aPlanState);
      }
    }

    // Assumption: Codegen did the check if theModifyIter is an updating expr,
    // empty seq producion expr or an error expr
    lItem = consumeNext(theModifyIter, aPlanState);

    if (lItem != 0 && lItem->isPul())
    {
      lItem->applyUpdates();  
    }

    lItem = consumeNext(theReturnIter, aPlanState);
    while (lItem != 0)
    {
      STACK_PUSH(lItem, aState); 
      lItem = consumeNext(theReturnIter, aPlanState);
    }
  }

  STACK_END (aState);
}

void 
TransformIterator::openImpl ( PlanState& planState, uint32_t& offset ) {
  StateTraitsImpl<PlanIteratorState>::createState(planState, this->stateOffset, offset);

  CopyClause::iter_t lIter = theCopyClauses.begin();
  CopyClause::iter_t lEnd = theCopyClauses.end();
  for ( ; lIter != lEnd ; ++lIter )
  {
    lIter->theInput->open(planState, offset );
  }
  theModifyIter->open( planState, offset );
  theReturnIter->open( planState , offset);
}

void 
TransformIterator::resetImpl ( PlanState& planState ) const
{
  StateTraitsImpl<PlanIteratorState>::reset(planState, this->stateOffset);
  
  CopyClause::const_iter_t lIter = theCopyClauses.begin();
  CopyClause::const_iter_t lEnd = theCopyClauses.end();
  for ( ; lIter != lEnd ; ++lIter )
  {
    lIter->theInput->reset(planState);
  }
  theModifyIter->reset( planState );
  theReturnIter->reset( planState );
}

void 
TransformIterator::closeImpl ( PlanState& planState ) const
{
  CopyClause::const_iter_t lIter = theCopyClauses.begin();
  CopyClause::const_iter_t lEnd = theCopyClauses.end();
  for ( ; lIter != lEnd ; ++lIter )
  {
    lIter->theInput->close(planState);
  }
  theModifyIter->close( planState );
  theReturnIter->close( planState );

  StateTraitsImpl<PlanIteratorState>::destroyState(planState, this->stateOffset);
}

uint32_t 
TransformIterator::getStateSizeOfSubtree() const {
  uint32_t lSize = getStateSize();
  CopyClause::const_iter_t lIter = theCopyClauses.begin();
  CopyClause::const_iter_t lEnd = theCopyClauses.end();
  for ( ; lIter != lEnd ; ++lIter )
  {
    lSize += lIter->theInput->getStateSizeOfSubtree();
  }
  lSize += theModifyIter->getStateSizeOfSubtree();
  lSize += theReturnIter->getStateSizeOfSubtree();
  return lSize;
}
} // namespace zorba
