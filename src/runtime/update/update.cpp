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
#include "stdafx.h"

#include "common/shared_types.h"

#include "store/api/pul.h"
#include "store/api/update_consts.h"
#include "store/api/item.h"
#include "store/api/iterator.h"
#include "store/api/collection.h"
#include "store/api/item_factory.h"
#include "store/api/store.h"
#include "store/api/copymode.h"

#include "runtime/update/update.h"
#include "runtime/core/var_iterators.h"
#include "runtime/visitors/planiter_visitor.h"

#include "types/root_typemanager.h"
#include "types/casting.h"

#include "compiler/xqddf/collection_decl.h"

#include "context/static_context.h"
#include "context/dynamic_context.h"
#include "context/static_context_consts.h"
#include "context/namespace_context.h"

#include "system/globalenv.h"

#include "zorbautils/fatal.h"


namespace zorba 
{

SERIALIZABLE_CLASS_VERSIONS(InsertIterator)
END_SERIALIZABLE_CLASS_VERSIONS(InsertIterator)

SERIALIZABLE_CLASS_VERSIONS(DeleteIterator)
END_SERIALIZABLE_CLASS_VERSIONS(DeleteIterator)

SERIALIZABLE_CLASS_VERSIONS(ReplaceIterator)
END_SERIALIZABLE_CLASS_VERSIONS(ReplaceIterator)

SERIALIZABLE_CLASS_VERSIONS(RenameIterator)
END_SERIALIZABLE_CLASS_VERSIONS(RenameIterator)

SERIALIZABLE_CLASS_VERSIONS(CopyClause)
END_SERIALIZABLE_CLASS_VERSIONS(CopyClause)

SERIALIZABLE_CLASS_VERSIONS(TransformIterator)
END_SERIALIZABLE_CLASS_VERSIONS(TransformIterator)


void areNodeModifiersViolated(
    const static_context* aSctx,
    const store::Item* aTarget,
    const QueryLoc& aLoc)
{
  const store::Collection* lColl = aTarget->getCollection();
  if (lColl != 0 && !lColl->isDynamic()) 
  {
    const StaticallyKnownCollection* lDeclColl = 
    aSctx->lookup_collection(lColl->getName());

    if (lDeclColl == NULL)
    {
      throw XQUERY_EXCEPTION(zerr::ZDDY0001_COLLECTION_NOT_DECLARED,
                             ERROR_PARAMS(lColl->getName()->getStringValue()),
                             ERROR_LOC(aLoc));
    }

    switch(lDeclColl->getNodeModifier()) 
    {
    case StaticContextConsts::read_only:
      throw XQUERY_EXCEPTION(zerr::ZDDY0010_COLLECTION_CONST_NODE_UPDATE,
                             ERROR_PARAMS( lColl->getName()->getStringValue() ),
                             ERROR_LOC(aLoc));

    case StaticContextConsts::mutable_node:
      // good to go
      break;
    }
  }
}


/*******************************************************************************

********************************************************************************/
InsertIterator::InsertIterator(
    static_context*                 sctx,
    const QueryLoc&                 aLoc,
    store::UpdateConsts::InsertType aType,
    PlanIter_t                      source,
    PlanIter_t                      target)
  :
  BinaryBaseIterator<InsertIterator, PlanIteratorState>(sctx, aLoc, source, target),
  theType(aType),
  theDoCopy(true)
{ 
}


bool InsertIterator::nextImpl(store::Item_t& result, PlanState& aPlanState) const
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

  store::CopyMode lCopyMode;
  bool typePreserve;
  bool nsPreserve;
  bool nsInherit;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);

  typePreserve = (theSctx->construction_mode() == StaticContextConsts::cons_preserve ?
                  true : false);
  nsPreserve = (theSctx->preserve_mode() == StaticContextConsts::preserve_ns ?
                true : false);
  nsInherit = (theSctx->inherit_mode() == StaticContextConsts::inherit_ns ?
               true : false);

  lCopyMode.set(theDoCopy, typePreserve, nsPreserve, nsInherit);
  
  if (!consumeNext(target, theChild1, aPlanState))
    throw XQUERY_EXCEPTION( err::XUDY0027, ERROR_LOC( loc ) );

  if (theType == store::UpdateConsts::BEFORE ||
      theType == store::UpdateConsts::AFTER)
  {
    if (!target->isNode() ||
        target->getNodeKind() == store::StoreConsts::attributeNode ||
        target->getNodeKind() == store::StoreConsts::documentNode)
      throw XQUERY_EXCEPTION( err::XUTY0006, ERROR_LOC( loc ) );

    if (consumeNext(temp, theChild1, aPlanState))
      throw XQUERY_EXCEPTION( err::XUTY0006, ERROR_LOC( loc ) );

    if (target->getParent() == NULL)
      throw XQUERY_EXCEPTION( err::XUDY0029, ERROR_LOC( loc ) );

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
          throw XQUERY_EXCEPTION( err::XUTY0004, ERROR_LOC( loc ) );

        if (!elemParent)
          throw XQUERY_EXCEPTION( err::XUDY0030, ERROR_LOC( loc ) );

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

    areNodeModifiersViolated(theSctx, target, loc);

    pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

    if (numAttrs > 0)
    {
      attrs.resize(numAttrs);

      for (ulong i = 0; i < numAttrs; ++i)
        attrs[i] = attrs[i]->copy(NULL, lCopyMode);

      pul->addInsertAttributes(&loc, parent, attrs);
    }

    if (numNodes > 0)
    {
      nodes.resize(numNodes);

      for (ulong i = 0; i < numNodes; ++i)
        nodes[i] = nodes[i]->copy(NULL, lCopyMode);

      if (theType == store::UpdateConsts::BEFORE)
        pul->addInsertBefore(&loc, target, nodes);
      else
        pul->addInsertAfter(&loc, target, nodes);
    }

    result = pul.release();
    STACK_PUSH(result != NULL, state);
  }
  else
  {
    if (!target->isNode())
      throw XQUERY_EXCEPTION( err::XUTY0005, ERROR_LOC( loc ) );

    targetKind = target->getNodeKind();

    if (targetKind != store::StoreConsts::documentNode &&
        targetKind != store::StoreConsts::elementNode)
      throw XQUERY_EXCEPTION( err::XUTY0005, ERROR_LOC( loc ) );

    if (consumeNext(temp, theChild1, aPlanState))
      throw XQUERY_EXCEPTION( err::XUTY0005, ERROR_LOC( loc ) );

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
          throw XQUERY_EXCEPTION( err::XUTY0004, ERROR_LOC( loc ) );

        if (!elemTarget)
          throw XQUERY_EXCEPTION( err::XUTY0022, ERROR_LOC( loc ) );

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

    areNodeModifiersViolated(theSctx, target, loc);

    pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

    if (numAttrs > 0)
    {
      attrs.resize(numAttrs);

      for (ulong i = 0; i < numAttrs; ++i)
        attrs[i] = attrs[i]->copy(NULL, lCopyMode);

      pul->addInsertAttributes(&loc, target, attrs);
    }

    if (numNodes > 0)
    {
      nodes.resize(numNodes);

      for (ulong i = 0; i < numNodes; ++i)
        nodes[i] = nodes[i]->copy(NULL, lCopyMode);

      if (theType == store::UpdateConsts::INTO)
        pul->addInsertInto(&loc, target, nodes);
      else if (theType == store::UpdateConsts::AS_FIRST_INTO)
        pul->addInsertFirst(&loc, target, nodes);
      else
        pul->addInsertLast(&loc, target, nodes);
    }

    result = pul.release();
    STACK_PUSH(result != NULL, state);
  }

  STACK_END (state);
}


BINARY_ACCEPT(InsertIterator);


/*******************************************************************************

********************************************************************************/
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
      throw XQUERY_EXCEPTION( err::XUTY0007, ERROR_LOC( loc ) );

    areNodeModifiersViolated(theSctx, target, loc);

    pul->addDelete(&loc, target);

  }
  result = pul.release();
  STACK_PUSH(true, state);
  STACK_END(state);
}


UNARY_ACCEPT(DeleteIterator);


/*******************************************************************************

********************************************************************************/
ReplaceIterator::ReplaceIterator (
    static_context* sctx,
    const QueryLoc& aLoc,
    store::UpdateConsts::ReplaceType aType,
    PlanIter_t target,
    PlanIter_t source)
  :
  BinaryBaseIterator<ReplaceIterator, PlanIteratorState>(sctx, aLoc, target, source),
  theType(aType),
  theDoCopy(true)
{ 
}


void ReplaceIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (BinaryBaseIterator<ReplaceIterator, PlanIteratorState>*)this);

  SERIALIZE_ENUM(store::UpdateConsts::ReplaceType, theType);
  ar & theDoCopy;
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

  store::CopyMode lCopyMode;
  bool typePreserve;
  bool nsPreserve;
  bool nsInherit;

  PlanIteratorState* lState;
  DEFAULT_STACK_INIT(PlanIteratorState, lState, aPlanState);
  
  typePreserve = (theSctx->construction_mode() == StaticContextConsts::cons_preserve ?
                  true : false);
  nsPreserve = (theSctx->preserve_mode() == StaticContextConsts::preserve_ns ?
                true : false);
  nsInherit = (theSctx->inherit_mode() == StaticContextConsts::inherit_ns ?
               true : false);

  lCopyMode.set(theDoCopy, typePreserve, nsPreserve, nsInherit);

  if (!consumeNext(lTarget, theChild0, aPlanState))
    throw XQUERY_EXCEPTION(err::XUDY0027, ERROR_LOC(loc));

  if (consumeNext(temp, theChild0, aPlanState))
    throw XQUERY_EXCEPTION(err::XUTY0008, ERROR_LOC(loc));

  if (!lTarget->isNode())
     throw XQUERY_EXCEPTION(err::XUTY0008, ERROR_LOC(loc));

  lTargetKind = lTarget->getNodeKind();

  if (!( lTargetKind == store::StoreConsts::elementNode ||
         lTargetKind == store::StoreConsts::attributeNode ||
         lTargetKind == store::StoreConsts::textNode ||
         lTargetKind == store::StoreConsts::commentNode ||
         lTargetKind == store::StoreConsts::piNode))
  {
    throw XQUERY_EXCEPTION(err::XUTY0008, ERROR_LOC(loc));
  }

  if (theType == store::UpdateConsts::NODE) // replace node ...
  {
    if (lTarget->getParent() == 0)
    {
      throw XQUERY_EXCEPTION(err::XUDY0009, ERROR_LOC(loc));
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
    
    if (lTargetKind == store::StoreConsts::attributeNode)
    {
      while (consumeNext(lWith, theChild1, aPlanState)) 
      {
        if (!lWith->isNode() ||
            lWith->getNodeKind() != store::StoreConsts::attributeNode)
        {
          throw XQUERY_EXCEPTION(err::XUTY0011, ERROR_LOC(loc));
        }

        lWith = lWith->copy(NULL, lCopyMode);

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
          throw XQUERY_EXCEPTION(err::XUTY0010, ERROR_LOC(loc));

        lWithKind = lWith->getNodeKind();

        if (!(lWithKind == store::StoreConsts::elementNode
              || lWithKind == store::StoreConsts::textNode
              || lWithKind == store::StoreConsts::commentNode
              || lWithKind == store::StoreConsts::piNode))
        {
          throw XQUERY_EXCEPTION(err::XUTY0010, ERROR_LOC(loc));
        }

        lWith = lWith->copy(NULL, lCopyMode);

        lNodes[lNumNodes++].transfer(lWith);

        if (lNumNodes == lNodes.size())
          lNodes.resize(2 * lNumNodes);
      }
    }

    areNodeModifiersViolated(theSctx, lTarget, loc);

    lPul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

    lNodes.resize(lNumNodes);
    lPul->addReplaceNode(&loc, lTarget, lNodes);
  }
  else // replace value of node ...
  {
    lPul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

    zstring content;
    store::Item_t typedVal;
    store::Iterator_t typedIter;
    bool haveContent = false;

    if (consumeNext(lWith, theChild1, aPlanState))
    {
      haveContent = true;

      if (lWith->isAtomic())
      {
        lWith->getStringValue2(content);
      }
      else
      {
        lWith->getTypedValue(typedVal, typedIter);

        if (typedIter == NULL)
        {
          typedVal->getStringValue2(content);
        }
        else
        {
          typedIter->open();

          if (typedIter->next(typedVal))
          {
            typedVal->getStringValue2(content);

            while (typedIter->next(typedVal))
            {
              content += " ";
              typedVal->appendStringValue(content);
            }
          }

          typedIter->close();
        }
      }
      
      while (consumeNext(lWith, theChild1, aPlanState))
      {
        content += " ";

        if (lWith->isAtomic())
        {
          lWith->appendStringValue(content);
        }
        else
        {
          lWith->getTypedValue(typedVal, typedIter);

          if (typedIter == NULL)
          {
            typedVal->appendStringValue(content);
          }
          else
          {
            typedIter->open();

            if (typedIter->next(typedVal))
            {
              typedVal->appendStringValue(content);

              while (typedIter->next(typedVal))
              {
                content += " ";
                typedVal->appendStringValue(content);
              }
            }

            typedIter->close();
          }
        }
      }
    }

    if (lTargetKind == store::StoreConsts::elementNode)
    {
      if (haveContent)
        GENV_ITEMFACTORY->createTextNode(lWith, NULL, content);
      else
        lWith = NULL;

      areNodeModifiersViolated(theSctx, lTarget, loc);

      lPul->addReplaceContent(&loc, lTarget, lWith);
    }
    else
    {
      if (lTargetKind == store::StoreConsts::commentNode &&
          (content.find("--") != zstring::npos || ascii::ends_with(content, "-", 1)))
      {
        throw XQUERY_EXCEPTION(err::XQDY0072, ERROR_LOC(loc));
      }
      else if (lTargetKind == store::StoreConsts::piNode &&
               content.find("?>") != zstring::npos)
      {
        throw XQUERY_EXCEPTION(err::XQDY0026, ERROR_LOC(loc));
      }

      areNodeModifiersViolated(theSctx, lTarget, loc);

      if (content.empty() && lTargetKind == store::StoreConsts::textNode)
      {
        store::Item_t temp = lTarget;
        lPul->addReplaceValue(&loc, temp, content);
        lPul->addDelete(&loc, lTarget);
      }
      else
      {
        lPul->addReplaceValue(&loc, lTarget, content);
      }
    }
  }

  result = lPul.release();
  STACK_PUSH(true, lState);

  STACK_END (lState);
}


BINARY_ACCEPT(ReplaceIterator);


/*******************************************************************************

********************************************************************************/
RenameIterator::RenameIterator (
    static_context* sctx,
    const QueryLoc& aLoc,
    PlanIter_t target,
    PlanIter_t source,
    const NamespaceContext_t& nsctx)
  :
  BinaryBaseIterator<RenameIterator, PlanIteratorState>(sctx, aLoc, target, source),
  theNsCtx(nsctx)
{ 
}


void RenameIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (BinaryBaseIterator<RenameIterator, PlanIteratorState>*)this);

  ar & theNsCtx;
}


bool
RenameIterator::nextImpl(store::Item_t& result, PlanState& aPlanState) const
{
  store::StoreConsts::NodeKind lTargetKind;
  store::Item_t lTarget;
  store::Item_t lNewname;
  store::Item_t qnameItem;
  store::Item_t temp;
  std::auto_ptr<store::PUL> lPul;

  PlanIteratorState* lState;
  DEFAULT_STACK_INIT(PlanIteratorState, lState, aPlanState);

  if (!consumeNext(lTarget, theChild0, aPlanState))
  {
    throw XQUERY_EXCEPTION( err::XUDY0027, ERROR_LOC( loc ) );
  }
  
  if (!lTarget->isNode())
    throw XQUERY_EXCEPTION(err::XUTY0012, ERROR_LOC(loc));

  lTargetKind = lTarget->getNodeKind();

  if (!(lTargetKind == store::StoreConsts::elementNode ||
        lTargetKind == store::StoreConsts::attributeNode ||
        lTargetKind == store::StoreConsts::piNode))
  {
    throw XQUERY_EXCEPTION(err::XUTY0012, ERROR_LOC(loc));
  }

  if (consumeNext(temp, theChild0, aPlanState))
  {
    throw XQUERY_EXCEPTION(err::XUTY0012, ERROR_LOC(loc));
  }

  areNodeModifiersViolated(theSctx, lTarget, loc);

  if (!consumeNext(lNewname, theChild1, aPlanState))
  {
    throw XQUERY_EXCEPTION(
      err::XPTY0004,
      ERROR_PARAMS( ZED( EmptySeqNoCastToQName ) ),
      ERROR_LOC( loc )
    );
  }

  if (consumeNext(temp, theChild1, aPlanState))
  {
    throw XQUERY_EXCEPTION(
      err::XPTY0004,
      ERROR_PARAMS( ZED( SeqNoCastToQName ) ),
      ERROR_LOC( loc )
    );
  }

  try
  {
    GenericCast::instance()->
    castToQName(qnameItem,
                lNewname,
                theNsCtx.getp(),
                (lTargetKind == store::StoreConsts::attributeNode),
                theSctx->get_typemanager(),
                loc);
  }
  catch (ZorbaException const& e)
  {
    if (e.diagnostic() != err::XPTY0004)
    {
      // the returned error codes are wrong for name casting => they must be changed
      throw XQUERY_EXCEPTION(
        err::XQDY0074, ERROR_PARAMS( "item" ), ERROR_LOC( loc )
      );
    }
    else
    {
      throw;
    }
  }

  lPul.reset(GENV_ITEMFACTORY->createPendingUpdateList());
  lPul->addRename(&loc, lTarget, qnameItem);

  result = lPul.release();
  STACK_PUSH(true, lState);

  STACK_END (lState);
}


BINARY_ACCEPT(RenameIterator);


/*******************************************************************************

********************************************************************************/
TransformIterator::TransformIterator(
    static_context* sctx,
    const QueryLoc& aLoc,
    std::vector<CopyClause>& aCopyClauses,
    PlanIter_t aModifyIter,
    PlanIter_t aPulHolderIter,
    PlanIter_t aApplyIter,
    PlanIter_t aReturnIter)
  :
  Batcher<TransformIterator>(sctx, aLoc),
  theCopyClauses(aCopyClauses),
  theModifyIter(aModifyIter),
  thePulHolderIter(aPulHolderIter),
  theApplyIter(aApplyIter),
  theReturnIter(aReturnIter)
{
}


TransformIterator::~TransformIterator()
{
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
  lSize += thePulHolderIter->getStateSizeOfSubtree();
  lSize += theApplyIter->getStateSizeOfSubtree();
  lSize += theReturnIter->getStateSizeOfSubtree();
  return lSize;
}


void TransformIterator::accept(PlanIterVisitor &v) const 
{
  v.beginVisit(*this);
  CopyClause::const_iter_t lIter = theCopyClauses.begin();
  CopyClause::const_iter_t lEnd = theCopyClauses.end();
  for ( ; lIter != lEnd; ++lIter ) {
    lIter->theInput->accept ( v );
  } 
  theModifyIter->accept(v);
  theReturnIter->accept(v);
  v.endVisit(*this);
}


bool
TransformIterator::nextImpl(store::Item_t& result, PlanState& aPlanState) const
{
  std::vector<ForVarIter_t>::const_iterator lVarRefIter; 
  std::vector<ForVarIter_t>::const_iterator lVarRefEnd;
  store::Item_t pulItem;
  store::Item_t validationPul;
  store::PUL_t pul;
  store::Item_t temp;
  store::Item_t lItem;
  store::Item_t lCopyNode;
  store::CopyMode lCopyMode;
  bool typePreserve;
  bool nsPreserve;
  bool nsInherit;

  PlanIteratorState* aState;
  DEFAULT_STACK_INIT(PlanIteratorState, aState, aPlanState);

  pul = GENV_ITEMFACTORY->createPendingUpdateList();

  typePreserve = (theSctx->construction_mode() == StaticContextConsts::cons_preserve ?
                  true : false);
  nsPreserve = (theSctx->preserve_mode() == StaticContextConsts::preserve_ns ?
                true : false);
  nsInherit = (theSctx->inherit_mode() == StaticContextConsts::inherit_ns ?
               true : false);

  lCopyMode.set(true, typePreserve, nsPreserve, nsInherit);

  {
    ulong numCopyClauses = (ulong)theCopyClauses.size(); 
    std::vector<store::Item*> copyNodes(numCopyClauses);

    // For each copy var compute the target node and bind that node to all
    // references of the copy var.
    for (ulong i = 0; i < numCopyClauses; i++)
    {
      const CopyClause& copyClause = theCopyClauses[i];

      if (!consumeNext(lCopyNode, copyClause.theInput, aPlanState) ||
          !lCopyNode->isNode())
      {
        throw XQUERY_EXCEPTION(err::XUTY0013, ERROR_LOC(loc));
      }

      if (consumeNext(temp, copyClause.theInput, aPlanState))
      {
        throw XQUERY_EXCEPTION(err::XUTY0013, ERROR_LOC(loc));
      }

      copyNodes[i] = lCopyNode->copy(NULL, lCopyMode);

      lVarRefIter = copyClause.theCopyVars.begin();
      lVarRefEnd = copyClause.theCopyVars.end();
      for(; lVarRefIter != lVarRefEnd; ++lVarRefIter)
      {
        (*lVarRefIter)->bind(copyNodes[i], aPlanState);
      }
    }

    // Generate the PUL for the modify clause. Assumption: Codegen did the
    // check if theModifyIter is an updating expr, empty seq producing expr
    // or an error expr. If a PUL is generated, then apply its updates.
    while (consumeNext(pulItem, theModifyIter, aPlanState))
    {
      if (pulItem->isPul())
      {
        pul->mergeUpdates(pulItem);
      }
    }

    // check that every target node in the lPul is inside the tree rooted
    // at some of the copied nodes.
    pul->checkTransformUpdates(copyNodes);

    // apply the pul
    static_cast<ForVarIterator*>(thePulHolderIter.getp())->bind(pul.getp(), aPlanState);
    consumeNext(temp, theApplyIter, aPlanState);
  }

  // Compute and return the results
  while (consumeNext(result, theReturnIter, aPlanState))
  {
    STACK_PUSH(true, aState); 
  }

  STACK_END (aState);
}


void 
TransformIterator::openImpl(PlanState& planState, uint32_t& offset) 
{
  StateTraitsImpl<PlanIteratorState>::createState(planState, theStateOffset, offset);

  CopyClause::iter_t lIter = theCopyClauses.begin();
  CopyClause::iter_t lEnd = theCopyClauses.end();
  for ( ; lIter != lEnd ; ++lIter )
  {
    lIter->theInput->open(planState, offset );
  }

  theModifyIter->open(planState, offset);
  // Do not open thePulHolderIter; it is a descendant of theApplyIter as well,
  // so it will be opened during theApplyIter->open()
  theApplyIter->open(planState, offset);
  theReturnIter->open(planState , offset);
}


void 
TransformIterator::resetImpl(PlanState& planState) const
{
  StateTraitsImpl<PlanIteratorState>::reset(planState, theStateOffset);
  
  CopyClause::const_iter_t lIter = theCopyClauses.begin();
  CopyClause::const_iter_t lEnd = theCopyClauses.end();
  for ( ; lIter != lEnd ; ++lIter )
  {
    lIter->theInput->reset(planState);
  }

  theModifyIter->reset(planState);
  thePulHolderIter->reset(planState);
  theApplyIter->reset(planState);
  theReturnIter->reset(planState);
}


void 
TransformIterator::closeImpl(PlanState& planState) const
{
  CopyClause::const_iter_t lIter = theCopyClauses.begin();
  CopyClause::const_iter_t lEnd = theCopyClauses.end();
  for ( ; lIter != lEnd ; ++lIter )
  {
    lIter->theInput->close(planState);
  }
  theModifyIter->close(planState);
  thePulHolderIter->close(planState);
  theApplyIter->close(planState);
  theReturnIter->close(planState);

  StateTraitsImpl<PlanIteratorState>::destroyState(planState, theStateOffset);
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
