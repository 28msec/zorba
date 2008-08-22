/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "zorbautils/fatal.h"
#include "common/shared_types.h"
#include "system/globalenv.h"
#include "types/root_typemanager.h"
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
}


bool
InsertIterator::nextImpl(store::Item_t& result, PlanState& aPlanState) const
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
  store::Item_t temp;

  static_context* sctx;
  store::CopyMode lCopyMode;
  bool typePreserve;
  bool nsPreserve;
  bool nsInherit;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);

  sctx = aPlanState.theRuntimeCB->theStaticContext;

  typePreserve = (sctx->construction_mode() == StaticContextConsts::cons_preserve ?
                  true : false);
  nsPreserve = (sctx->preserve_mode() == StaticContextConsts::preserve_ns ?
                true : false);
  nsInherit = (sctx->inherit_mode() == StaticContextConsts::inherit_ns ?
               true : false);

  lCopyMode.set(theDoCopy, typePreserve, nsPreserve, nsInherit);
  
  if (!consumeNext(target, theChild1, aPlanState))
  {
    ZORBA_ERROR_LOC(XUDY0027, loc);
  }

  if (theType == store::UpdateConsts::BEFORE ||
      theType == store::UpdateConsts::AFTER)
  {
    if (!target->isNode() ||
        target->getNodeKind() == store::StoreConsts::attributeNode ||
        target->getNodeKind() == store::StoreConsts::documentNode)
      ZORBA_ERROR_LOC(XUTY0006, loc);

    if (consumeNext(temp, theChild1, aPlanState))
      ZORBA_ERROR_LOC(XUTY0006, loc);

    if (target->getParent() == NULL)
      ZORBA_ERROR_LOC(XUDY0029, loc);

    parent = target->getParent();

    elemParent = (parent->getNodeKind() == store::StoreConsts::elementNode);

    // Do not preserve the type of the source nodes (we do this here so that
    // we don't have to use the upd::setToUntyped() primitive later, during
    // the application of the PUL).
    if (lCopyMode.theTypePreserve &&
        (!elemParent ||
         parent->getType()->equals(GENV_TYPESYSTEM.XS_UNTYPED_QNAME)))
      lCopyMode.theTypePreserve = false;

    while (consumeNext(source, theChild0, aPlanState))
    {
      ZORBA_FATAL(source->isNode(), "");

      if (source->getNodeKind() == store::StoreConsts::attributeNode)
      {
        if (numNodes > 0)
          ZORBA_ERROR_LOC(XUTY0004, loc);

        if (!elemParent)
          ZORBA_ERROR_LOC(XUDY0030, loc);

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
    }

    pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

    if (numAttrs > 0)
    {
      attrs.resize(numAttrs);

      pul->addInsertAttributes(parent, attrs, lCopyMode);
    }

    if (numNodes > 0)
    {
      nodes.resize(numNodes);
      if (theType == store::UpdateConsts::BEFORE)
        pul->addInsertBefore(target, nodes, lCopyMode);
      else
        pul->addInsertAfter(target, nodes, lCopyMode);
    }

    result = pul.release();
    STACK_PUSH(result != NULL, state);
  }
  else
  {
    if (!target->isNode())
      ZORBA_ERROR_LOC(XUTY0005, loc);

    targetKind = target->getNodeKind();

    if (targetKind != store::StoreConsts::documentNode &&
        targetKind != store::StoreConsts::elementNode)
      ZORBA_ERROR_LOC(XUTY0005, loc);

    if (consumeNext(temp, theChild1, aPlanState))
      ZORBA_ERROR_LOC(XUTY0005, loc);

    elemTarget = (targetKind == store::StoreConsts::elementNode);

    if (lCopyMode.theTypePreserve &&
        (!elemTarget ||
         target->getType()->equals(GENV_TYPESYSTEM.XS_UNTYPED_QNAME)))
      lCopyMode.theTypePreserve = false;

    while (consumeNext(source, theChild0, aPlanState))
    {
      ZORBA_FATAL(source->isNode(), "");

      if (source->getNodeKind() == store::StoreConsts::attributeNode)
      {
        if (numNodes > 0)
          ZORBA_ERROR_LOC(XUTY0004, loc);

        if (!elemTarget)
          ZORBA_ERROR_LOC(XUTY0022, loc);

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
    }

    pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

    if (numAttrs > 0)
    {
      attrs.resize(numAttrs);
      pul->addInsertAttributes(target, attrs, lCopyMode);
    }

    if (numNodes > 0)
    {
      nodes.resize(numNodes);
      if (theType == store::UpdateConsts::INTO)
        pul->addInsertInto(target, nodes, lCopyMode);
      else if (theType == store::UpdateConsts::AS_FIRST_INTO)
        pul->addInsertFirst(target, nodes, lCopyMode);
      else
        pul->addInsertLast(target, nodes, lCopyMode);
    }

    result = pul.release();
    STACK_PUSH(result != NULL, state);
  }

  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
DeleteIterator::DeleteIterator(const QueryLoc& aLoc, PlanIter_t target)
  :
  UnaryBaseIterator<DeleteIterator, PlanIteratorState>(aLoc, target)
{ 
}


bool
DeleteIterator::nextImpl(store::Item_t& result, PlanState& aPlanState) const
{ 
  store::Item_t target;
  std::auto_ptr<store::PUL> pul;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);

  pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

  while (consumeNext(target, theChild, aPlanState))
  {
    if (!target->isNode())
      ZORBA_ERROR_LOC(XUTY0007, loc);

    pul->addDelete(target);

  }
  result = pul.release();
  STACK_PUSH(true, state);
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


bool
ReplaceIterator::nextImpl(store::Item_t& result, PlanState& aPlanState) const
{
  bool elemParent;
  store::StoreConsts::NodeKind lTargetKind;
  store::StoreConsts::NodeKind lWithKind;
  store::Item_t lWith;
  store::Item_t lTarget;
  store::Item_t lParent;
  store::Item_t temp;
  std::vector<store::Item_t> lNodes(16);
  ulong lNumNodes = 0;
  std::auto_ptr<store::PUL> lPul;

  static_context* sctx;
  store::CopyMode lCopyMode;
  bool typePreserve;
  bool nsPreserve;
  bool nsInherit;

  PlanIteratorState* lState;
  DEFAULT_STACK_INIT(PlanIteratorState, lState, aPlanState);
  
  sctx = aPlanState.theRuntimeCB->theStaticContext;

  typePreserve = (sctx->construction_mode() == StaticContextConsts::cons_preserve ?
                  true : false);
  nsPreserve = (sctx->preserve_mode() == StaticContextConsts::preserve_ns ?
                true : false);
  nsInherit = (sctx->inherit_mode() == StaticContextConsts::inherit_ns ?
               true : false);

  lCopyMode.set(theDoCopy, typePreserve, nsPreserve, nsInherit);

  if (!consumeNext(lTarget, theChild0, aPlanState))
    ZORBA_ERROR_LOC(XUDY0027, loc);

  if (consumeNext(temp, theChild0, aPlanState))
    ZORBA_ERROR_LOC(XUTY0008, loc);

  if (!lTarget->isNode())
     ZORBA_ERROR_LOC(XUTY0008, loc);

  lTargetKind = lTarget->getNodeKind();

  if (!( lTargetKind == store::StoreConsts::elementNode ||
         lTargetKind == store::StoreConsts::attributeNode ||
         lTargetKind == store::StoreConsts::textNode ||
         lTargetKind == store::StoreConsts::commentNode ||
         lTargetKind == store::StoreConsts::piNode))
  {
    ZORBA_ERROR_LOC(XUTY0008, loc);
  }

  if (theType == store::UpdateConsts::NODE) // replace node ...
  {
    if (lTarget->getParent() == 0)
    {
      ZORBA_ERROR_LOC(XUDY0009, loc);
    }

    lParent = lTarget->getParent();

    elemParent = (lParent->getNodeKind() == store::StoreConsts::elementNode);

    // Do not preserve the type of the source nodes (we do this here so that
    // we don't have to use the upd::setToUntyped() primitive later, during
    // the application of the PUL).
    if (lCopyMode.theTypePreserve &&
        (!elemParent ||
         lParent->getType()->equals(GENV_TYPESYSTEM.XS_UNTYPED_QNAME)))
      lCopyMode.theTypePreserve = false;
    
    if ( lTargetKind == store::StoreConsts::attributeNode)
    {
      while (consumeNext(lWith, theChild1, aPlanState)) 
      {
        if (!lWith->isNode() ||
            lWith->getNodeKind() != store::StoreConsts::attributeNode)
        {
          ZORBA_ERROR_LOC(XUTY0011, loc);
        }

        lNodes[lNumNodes++].transfer(lWith);
        if (lNumNodes == lNodes.size())
          lNodes.resize(2 * lNumNodes);
      }
    }
    else
    {
      while (consumeNext(lWith, theChild1, aPlanState))
      {
        if (!lWith->isNode())
          ZORBA_ERROR_LOC(XUTY0010, loc);

        lWithKind = lWith->getNodeKind();

        if (!(lWithKind == store::StoreConsts::elementNode
              || lWithKind == store::StoreConsts::textNode
              || lWithKind == store::StoreConsts::commentNode
              || lWithKind == store::StoreConsts::piNode))
        {
          ZORBA_ERROR_LOC(XUTY0010, loc);
        }

        lNodes[lNumNodes++].transfer(lWith);
        if (lNumNodes == lNodes.size())
          lNodes.resize(2 * lNumNodes);
      }
    }

    lPul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

    lNodes.resize(lNumNodes);
    lPul->addReplaceNode(lTarget, lNodes, lCopyMode);
  }
  else // replace value of node ...
  {
    lPul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

    xqpStringStore_t content;

    if (consumeNext(lWith, theChild1, aPlanState))
    {
      content = (lWith->isAtomic() ?
                 lWith->getStringValue() : 
                 lWith->getAtomizationValue()->getStringValue());
                   
      std::string buf;
      while (consumeNext(lWith, theChild1, aPlanState))
      {
        buf += " ";
        buf += (lWith->isAtomic() ?
                lWith->getStringValue()->c_str() :
                lWith->getAtomizationValue()->getStringValue()->str());
      }
      if (!buf.empty())
        content = content->append(buf);
    }

    if (lTargetKind == store::StoreConsts::elementNode)
    {
      if (content != NULL)
        GENV_ITEMFACTORY->createTextNode(lWith, NULL, 0, content);
      else
        lWith = NULL;

      lCopyMode.theDoCopy = false;
      lPul->addReplaceContent(lTarget, lWith, lCopyMode);
    }
    else
    {
      if (content == NULL)
        content = new xqpStringStore("");

      if (lTargetKind == store::StoreConsts::commentNode &&
          (content->indexOf("--") >= 0 || content->endsWith("-")))
      {
        ZORBA_ERROR_LOC(XQDY0072, loc);
      }
      else if (lTargetKind == store::StoreConsts::piNode &&
               content->indexOf("?>") >= 0)
      {
        ZORBA_ERROR_LOC(XQDY0026, loc);
      }

      lPul->addReplaceValue(lTarget, content);
    }
  }

  result = lPul.release();
  STACK_PUSH(true, lState);

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


bool
RenameIterator::nextImpl(store::Item_t& result, PlanState& aPlanState) const
{
  store::StoreConsts::NodeKind lTargetKind;
  store::Item_t lTarget;
  store::Item_t lNewname;
  store::Item_t temp;
  std::auto_ptr<store::PUL> lPul;

  PlanIteratorState* lState;
  DEFAULT_STACK_INIT(PlanIteratorState, lState, aPlanState);

  if (!consumeNext(lTarget, theChild0, aPlanState))
  {
    ZORBA_ERROR_LOC(XUDY0027, loc);
  }
  
  if (!lTarget->isNode())
    ZORBA_ERROR_LOC(XUTY0012, loc);

  lTargetKind = lTarget->getNodeKind();

  if (!(lTargetKind == store::StoreConsts::elementNode ||
        lTargetKind == store::StoreConsts::attributeNode ||
        lTargetKind == store::StoreConsts::piNode))
  {
    ZORBA_ERROR_LOC(XUTY0012, loc);
  }

  if (consumeNext(temp, theChild0, aPlanState))
  {
    ZORBA_ERROR_LOC(XUTY0012, loc);
  }

  // because of codegen, it can be assumed that newname is already a qname 
  consumeNext(lNewname, theChild1, aPlanState);

  lPul.reset(GENV_ITEMFACTORY->createPendingUpdateList());
  lPul->addRename(lTarget, lNewname);

  result = lPul.release();
  STACK_PUSH(true, lState);

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


TransformIterator::~TransformIterator()
{
}


bool
TransformIterator::nextImpl(store::Item_t& result, PlanState& aPlanState) const
{
  std::vector<ForVarIter_t>::const_iterator lVarRefIter; 
  std::vector<ForVarIter_t>::const_iterator lVarRefEnd;
  rchandle<store::PUL> lPul;
  store::CopyMode lCopyMode;
  store::Item_t temp;
  store::Item_t lItem;
  store::Item_t lCopyNode;

  PlanIteratorState* aState;
  DEFAULT_STACK_INIT(PlanIteratorState, aState, aPlanState);

  {
    ulong numCopyClauses = theCopyClauses.size(); 
    std::vector<store::Item*> copyNodes(numCopyClauses);

    // For each copy var compute the target node and bind that node to all
    // reference of the copy var.
    for(ulong i = 0; i < numCopyClauses; i++)
    {
      const CopyClause& copyClause = theCopyClauses[i];

      if (!consumeNext(lCopyNode, copyClause.theInput, aPlanState) ||
          !lCopyNode->isNode())
      {
        ZORBA_ERROR_LOC(XUTY0013, loc);
      }

      copyNodes[i] = lCopyNode->copy(NULL, 0, lCopyMode);

      if (consumeNext(temp, copyClause.theInput, aPlanState))
      {
        ZORBA_ERROR_LOC(XUTY0013, loc);
      }

      lVarRefIter = copyClause.theCopyVars.begin();
      lVarRefEnd = copyClause.theCopyVars.end();
      for(; lVarRefIter != lVarRefEnd; ++lVarRefIter)
      {
        (*lVarRefIter)->bind(copyNodes[i], aPlanState);
      }
    }

    // generate the PUL for the modify clause. Assumption: Codegen did the
    // check if theModifyIter is an updating expr, empty seq producion expr
    // or an error expr
    if (consumeNext(lItem, theModifyIter, aPlanState))
    {
      ZORBA_FATAL(lItem->isPul(), "");

      lPul = static_cast<store::PUL *>(lItem.getp());

      // check that every target node in the lPul is inside the tree rooted
      // at some of the copied nodes.
      lPul->checkTransformUpdates(copyNodes);

      std::set<zorba::store::Item*> validationNodes;

      lPul->applyUpdates(validationNodes);  
    }
  }

  // Compute and return the results
  while (consumeNext(result, theReturnIter, aPlanState))
  {
    STACK_PUSH(true, aState); 
  }

  STACK_END (aState);
}


void 
TransformIterator::openImpl ( PlanState& planState, uint32_t& offset ) 
{
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
TransformIterator::getStateSizeOfSubtree() const 
{
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
