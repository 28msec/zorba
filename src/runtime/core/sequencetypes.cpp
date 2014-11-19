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

#include "diagnostics/xquery_diagnostics.h"
#include "diagnostics/util_macros.h"

#include "system/globalenv.h"

#include "types/casting.h"
#include "types/typeops.h"

#include "context/static_context.h"
#include "context/namespace_context.h"

#include "runtime/core/sequencetypes.h"
#include "runtime/util/iterator_impl.h"
#include "runtime/visitors/planiter_visitor.h"

#include "store/api/item_factory.h"

#include "zorbatypes/integer.h"
#include "zorbatypes/numeric_types.h"

namespace zorba
{

SERIALIZABLE_CLASS_VERSIONS(InstanceOfIterator)
DEF_GET_NAME_AS_STRING(InstanceOfIterator)

SERIALIZABLE_CLASS_VERSIONS(CastIterator)
DEF_GET_NAME_AS_STRING(CastIterator)

SERIALIZABLE_CLASS_VERSIONS(CastableIterator)
DEF_GET_NAME_AS_STRING(CastableIterator)

SERIALIZABLE_CLASS_VERSIONS(PromoteIterator)
DEF_GET_NAME_AS_STRING(PromoteIterator)

SERIALIZABLE_CLASS_VERSIONS(TreatIterator)
DEF_GET_NAME_AS_STRING(TreatIterator)

SERIALIZABLE_CLASS_VERSIONS(EitherNodesOrAtomicsIterator)
DEF_GET_NAME_AS_STRING(EitherNodesOrAtomicsIterator)


/*******************************************************************************

********************************************************************************/

InstanceOfIterator::InstanceOfIterator(
   static_context* sctx,
   const QueryLoc& loc,
   PlanIter_t& aTreatExpr,
   xqtref_t aSequenceType)
  :
  UnaryBaseIterator<InstanceOfIterator, PlanIteratorState>(sctx, loc, aTreatExpr),
  theSequenceType (aSequenceType)
{
}


InstanceOfIterator::~InstanceOfIterator()
{
}


void InstanceOfIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (UnaryBaseIterator<InstanceOfIterator, PlanIteratorState>*)this);

  ar & theSequenceType;
}


bool InstanceOfIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t item;
  SequenceType::Quantifier quant;
  bool res = false;
  store::Item_t temp;
  const TypeManager* tm = theSctx->get_typemanager();

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  quant = theSequenceType->get_quantifier();

  if (consumeNext(item, theChild.getp(), planState))
  {
    if (theSequenceType->type_kind() == XQType::ATOMIC_TYPE_KIND &&
        item->isAtomic())
    {
      store::SchemaTypeCode targetType = 
      static_cast<const AtomicXQType*>(theSequenceType.getp())->get_type_code();

      store::SchemaTypeCode itemType = item->getTypeCode();

      if (TypeOps::is_subtype(itemType, targetType))
      {
        if (consumeNext(item, theChild.getp(), planState))
        {
          if (quant == SequenceType::QUANT_PLUS || quant == SequenceType::QUANT_STAR)
          {
            res = true;
            do
            {
              if (item->isAtomic())
              {
                itemType = item->getTypeCode();
                res = TypeOps::is_subtype(itemType, targetType);
              }
              else 
              {
                res = false;
              }

              if (res == false)
              {
                theChild->reset(planState);
                break;
              }
            }
            while (consumeNext(item, theChild.getp(), planState));
          }
        }
        else
        {
          res = true;
        }
      }
    }
    else if (TypeOps::is_subtype(tm, item, *theSequenceType, loc))
    {
      if (consumeNext(item, theChild.getp(), planState))
      {
        if (quant == SequenceType::QUANT_PLUS || quant == SequenceType::QUANT_STAR)
        {
          res = true;
          do
          {
            if (!TypeOps::is_subtype(tm, item, *theSequenceType, loc))
            {
              res = false;
              theChild->reset(planState);
              break;
            }
          }
          while (consumeNext(item, theChild.getp(), planState));
        }
      }
      else
      {
        res = true;
      }
    }
  }
  else
  {
    res = !(quant == SequenceType::QUANT_ONE || quant == SequenceType::QUANT_PLUS);
  }

  STACK_PUSH(GENV_ITEMFACTORY->createBoolean(result, res), state);
  STACK_END(state);
}


UNARY_ACCEPT(InstanceOfIterator);


/*******************************************************************************

********************************************************************************/
void CastIteratorState::init(PlanState& planState) 
{
  PlanIteratorState::init(planState);
  theResultPos = 0;
  theResultItems.clear();
}


void CastIteratorState::reset(PlanState& planState) 
{
  PlanIteratorState::reset(planState);
  theResultPos = 0;
  theResultItems.clear();
}


CastIterator::CastIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& child,
    const xqtref_t& castType,
    bool allowEmpty)
  : 
  UnaryBaseIterator<CastIterator, CastIteratorState>(sctx, loc, child),
  theAllowEmpty(allowEmpty),
  theNsCtx(theSctx)
{
  theCastType = TypeOps::prime_type(sctx->get_typemanager(), *castType);
}


CastIterator::~CastIterator()
{
}


void CastIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (UnaryBaseIterator<CastIterator, CastIteratorState>*)this);
  ar & theCastType;
  ar & theAllowEmpty;

  theNsCtx.setStaticContext(theSctx);
}


bool CastIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t item;
  bool valid = false;
  const UserDefinedXQType* udt;
  store::SchemaTypeCode targetType;

  TypeManager* tm = theSctx->get_typemanager();

  CastIteratorState* state;
  DEFAULT_STACK_INIT(CastIteratorState, state, planState);

  if (!consumeNext(item, theChild.getp(), planState))
  {
    if (!theAllowEmpty)
    {
      RAISE_ERROR(err::XPTY0004, loc,
      ERROR_PARAMS(ZED(EmptySeqNoCastToTypeWithQuantOne)));
    }
  }
  else
  {
    if (theCastType->type_kind() == XQType::ATOMIC_TYPE_KIND)
    {
      targetType = static_cast<const AtomicXQType*>(theCastType.getp())->get_type_code();

      GenericCast::castToBuiltinAtomic(result, item, targetType, &theNsCtx, loc);

      STACK_PUSH(true, state);
    }
    else
    {
      ZORBA_ASSERT(theCastType->type_kind() == XQType::USER_DEFINED_KIND);

      udt = static_cast<const UserDefinedXQType*>(theCastType.getp());

      if (udt->isAtomicAny())
      {
        valid = GenericCast::
        castToAtomic(result, item, theCastType, tm, &theNsCtx, loc);

        STACK_PUSH(valid, state);
      }
      else
      {
        assert(udt->isList() || udt->isUnion());

        valid = GenericCast::
        castToSimple(item, theCastType, &theNsCtx, state->theResultItems, tm, loc);

        state->theResultPos = 0;

        while (state->theResultPos < state->theResultItems.size())
        {
          result = state->theResultItems[state->theResultPos];
          STACK_PUSH(true, state);

          ++state->theResultPos;
        }
      }
    }

    if (consumeNext(item, theChild.getp(), planState))
    {
      RAISE_ERROR(err::XPTY0004, loc,
      ERROR_PARAMS(ZED(NoSeqCastToTypeWithQuantOneOrQuestion)));
    }
  }

  STACK_END(state);
}


UNARY_ACCEPT(CastIterator);


/*******************************************************************************

********************************************************************************/
CastableIterator::CastableIterator(
  static_context* sctx,
  const QueryLoc& loc,
  PlanIter_t& child,
  const xqtref_t& castType,
  bool allowEmpty)
  :
  UnaryBaseIterator<CastableIterator, PlanIteratorState>(sctx, loc, child),
  theAllowEmpty(allowEmpty),
  theNsCtx(theSctx)
{
  theCastType = TypeOps::prime_type(sctx->get_typemanager(), *castType);
}


CastableIterator::~CastableIterator()
{
}


void CastableIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (UnaryBaseIterator<CastableIterator, PlanIteratorState>*)this);

  ar & theCastType;
  ar & theAllowEmpty;
}


bool CastableIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  bool res;
  store::Item_t item;

  TypeManager* tm = theSctx->get_typemanager();

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (!consumeNext(item, theChild.getp(), planState))
  {
    res = theAllowEmpty;
  }
  else
  {
    res = GenericCast::isCastable(item, theCastType, tm, &theNsCtx);

    if (consumeNext(item, theChild.getp(), planState))
    {
      res = false;
    }
  }

  STACK_PUSH(GENV_ITEMFACTORY->createBoolean(result, res), state);
  STACK_END(state);
}


UNARY_ACCEPT(CastableIterator);


/*******************************************************************************

********************************************************************************/

PromoteIterator::PromoteIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& child,
    const xqtref_t& promoteType,
    PromoteErrorKind err,
    store::Item_t qname)
  :
  UnaryBaseIterator<PromoteIterator, PlanIteratorState>(sctx, loc, child),
  theErrorKind(err),
  theQName(qname),
  theNsCtx(theSctx)
{
  thePromoteType = TypeOps::prime_type(sctx->get_typemanager(), *promoteType);
  theQuantifier = promoteType->get_quantifier(); 
}


PromoteIterator::~PromoteIterator()
{
}


void PromoteIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (UnaryBaseIterator<PromoteIterator, PlanIteratorState>*)this);

  ar & thePromoteType;
  SERIALIZE_ENUM(SequenceType::Quantifier, theQuantifier);
  SERIALIZE_ENUM(PromoteErrorKind, theErrorKind);
  ar & theQName;

  theNsCtx.setStaticContext(theSctx);
}


bool PromoteIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t item;
  store::Item_t temp;

  const TypeManager* tm = theSctx->get_typemanager();

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (!consumeNext(item, theChild.getp(), planState))
  {
    if (theQuantifier == SequenceType::QUANT_PLUS ||
        theQuantifier == SequenceType::QUANT_ONE)
    {
      raiseError("empty-sequence()");
    }
  }
  else if (theQuantifier == SequenceType::QUANT_QUESTION ||
           theQuantifier == SequenceType::QUANT_ONE)
  {
    if (consumeNext(temp, theChild.getp(), planState))
    {
      raiseError("sequence of more than one item");
    }

    // catch exceptions to add/change the error location
    if (! GenericCast::promote(result, item, thePromoteType, &theNsCtx, tm, loc))
    {
      zstring valueType = tm->create_value_type(item)->toSchemaString();
      raiseError(valueType);
    }

    STACK_PUSH(true, state);
  }
  else
  {
    do
    {
      if (! GenericCast::promote(result, item, thePromoteType, &theNsCtx, tm, loc))
      {
        zstring valueType = tm->create_value_type(item)->toSchemaString();
        raiseError(valueType);
      }
      else
      {
        STACK_PUSH(true, state);
      }
    }
    while (consumeNext(item, theChild.getp(), planState));
  }

  STACK_END(state);
}


void PromoteIterator::raiseError(const zstring& valueType) const
{
  zstring targetType;

  if (thePromoteType->type_kind() == XQType::NONE_KIND && 
      theQuantifier == SequenceType::QUANT_QUESTION)
  {
    targetType = "empty-sequence()";
  }
  else
  {
    targetType = thePromoteType->toSchemaString();

    if (theQuantifier == SequenceType::QUANT_PLUS)
      targetType += "+";
    else if (theQuantifier == SequenceType::QUANT_STAR)
      targetType += "*";
    else if (theQuantifier == SequenceType::QUANT_QUESTION)
      targetType += "?";
  }

  switch (theErrorKind)
  {
  case PROMOTE_FUNC_RETURN:
  {
    assert(theQName != NULL);

    RAISE_ERROR(err::XPTY0004, loc, 
    ERROR_PARAMS(ZED(XPTY0004_NoReturnTypePromote_234),
                 valueType, targetType, theQName->getStringValue()));
    break;
  }
  case PROMOTE_FUNC_PARAM:
  {
    assert(theQName != NULL);

    if (TypeOps::is_equal(theSctx->get_typemanager(),
                          *thePromoteType,
                          *GENV_TYPESYSTEM.NOTATION_TYPE_ONE,
                          loc))
    {
      RAISE_ERROR(err::XPTY0117, loc,
      ERROR_PARAMS(ZED(XPTY0117_NotationParam_23),
                   valueType, theQName->getStringValue()));
    }

    RAISE_ERROR(err::XPTY0004, loc, 
    ERROR_PARAMS(ZED(XPTY0004_NoParamTypePromote_234),
                 valueType, targetType, theQName->getStringValue()));
    break;
  }
  case PROMOTE_TYPE_PROMOTION:
  {
    RAISE_ERROR(err::XPTY0004, loc, 
    ERROR_PARAMS(ZED(XPTY0004_NoTypePromote_23), valueType, targetType));
    break;
  }
  case PROMOTE_JSONIQ_ARRAY_SELECTOR:
  {
    RAISE_ERROR(jerr::JNUP0007, loc,
    ERROR_PARAMS(ZED(JNUP0007_Array), valueType));
    break;
  }
  case PROMOTE_JSONIQ_OBJECT_SELECTOR:
  {
    RAISE_ERROR(jerr::JNUP0007, loc,
    ERROR_PARAMS(ZED(JNUP0007_Object), valueType));
    break;
  }
  case PROMOTE_JSONIQ_SELECTOR:
  {
    RAISE_ERROR(jerr::JNUP0007, loc,
    ERROR_PARAMS(ZED(JNUP0007_ObjectArray), valueType));
    break;
  }
  case PROMOTE_INDEX_KEY:
  {
    RAISE_ERROR(zerr::ZDTY0011_INDEX_KEY_TYPE_ERROR, loc,
    ERROR_PARAMS(valueType, targetType, theQName->getStringValue()));
    break;
  }
  default:
  {
    ZORBA_ASSERT(false);
  }
  }
}


UNARY_ACCEPT(PromoteIterator);


/*******************************************************************************

********************************************************************************/

TreatIterator::TreatIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& child,
    const xqtref_t& treatType,
    bool checkPrime,
    TreatErrorKind errorKind,
    store::Item_t qname)
  :
  UnaryBaseIterator<TreatIterator, PlanIteratorState>(sctx, loc, child),
  theCheckPrime(checkPrime),
  theErrorKind(errorKind),
  theQName(qname)
{
  theTreatType = TypeOps::prime_type(sctx->get_typemanager(), *treatType);
  theQuantifier = treatType->get_quantifier();
}


void TreatIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (UnaryBaseIterator<TreatIterator, PlanIteratorState>*)this);

  ar & theTreatType;
  SERIALIZE_ENUM(SequenceType::Quantifier, theQuantifier);
  ar & theCheckPrime;
  SERIALIZE_ENUM(TreatErrorKind, theErrorKind);
  ar & theQName;
}

bool TreatIterator::countImpl( store::Item_t &result, PlanState &planState) const {
  bool const ret_val = theChild->count( result, planState );
  xs_integer const count( result->getIntegerValue() );

  switch ( theQuantifier ) {
    case SequenceType::QUANT_QUESTION:
      if ( count <= numeric_consts<xs_integer>::one() )
        break;
      // no break;
    case SequenceType::QUANT_ONE:
      if ( count > numeric_consts<xs_integer>::one() )
        raiseError("sequence of more than one item");
      // no break;
    case SequenceType::QUANT_PLUS:
      if ( count == numeric_consts<xs_integer>::zero() )
        raiseError("empty-sequence()");
      break;
    default:
      // do nothing
      break;
  }
  return ret_val;
}

bool TreatIterator::skipImpl( int64_t count, PlanState &planState ) const {
  switch ( theQuantifier ) {
    //
    // Given that the skip() signature is not as good as it could be (it should
    // return a pair<int64_t,bool> indicating how many were skipped and whether
    // there are more), it's not possible to optimize this for any quantifier
    // other than '*' (since any number of elements is valid for '*').
    //
    case SequenceType::QUANT_STAR:
      return theChild->skip( count, planState );
    default:
      return base_type::skipImpl( count, planState );
  }
}


bool TreatIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t temp;
  bool res;
  const TypeManager* tm = theSctx->get_typemanager();

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (!consumeNext(result, theChild.getp(), planState))
  {
    if (theQuantifier == SequenceType::QUANT_PLUS ||
        theQuantifier == SequenceType::QUANT_ONE)
    {
      raiseError("empty-sequence()");
    }
  }
  else if (theQuantifier == SequenceType::QUANT_QUESTION ||
           theQuantifier == SequenceType::QUANT_ONE)
  {
    if (consumeNext(temp, theChild.getp(), planState))
    {
      raiseError("sequence of more than one item");
    }

    if (theCheckPrime)
    {
      if (theTreatType->type_kind() == XQType::ATOMIC_TYPE_KIND &&
          result->isAtomic())
      {
        store::SchemaTypeCode targetType = 
        static_cast<const AtomicXQType*>(theTreatType.getp())->get_type_code();

        store::SchemaTypeCode itemType = result->getTypeCode();

        res = TypeOps::is_subtype(itemType, targetType);
      }
      else
      {
        res = TypeOps::is_subtype(tm, result, *theTreatType, loc);
      }
      
      if (!res)
      {
        zstring valueType = tm->create_value_type(result)->toSchemaString();
        raiseError(valueType);
      }
    }

    STACK_PUSH(true, state);
  }
  else
  {
    do
    {
      if (theCheckPrime) 
      {
        if (theTreatType->type_kind() == XQType::ATOMIC_TYPE_KIND &&
            result->isAtomic())
        {
          store::SchemaTypeCode targetType = 
          static_cast<const AtomicXQType*>(theTreatType.getp())->get_type_code();

          store::SchemaTypeCode itemType = result->getTypeCode();

          res = TypeOps::is_subtype(itemType, targetType);
        }
        else
        {
          res = TypeOps::is_subtype(tm, result, *theTreatType, loc);
        } 
        
        if (!res)
        {
          zstring valueType = tm->create_value_type(result)->toSchemaString();
          raiseError(valueType);
        }
      }

      STACK_PUSH(true, state);
    } 
    while (consumeNext(result, theChild.getp(), planState));
  }

  STACK_END(state);
}


void TreatIterator::raiseError(const zstring& valueType) const
{
  zstring targetType;

  if (theTreatType->type_kind() == XQType::NONE_KIND && 
      theQuantifier == SequenceType::QUANT_QUESTION)
  {
    targetType = "empty-sequence()";
  }
  else
  {
    targetType = theTreatType->toSchemaString();

    if (theQuantifier == SequenceType::QUANT_PLUS)
      targetType += "+";
    else if (theQuantifier == SequenceType::QUANT_STAR)
      targetType += "*";
    else if (theQuantifier == SequenceType::QUANT_QUESTION)
      targetType += "?";
  }

  switch (theErrorKind)
  {
  case TREAT_FUNC_RETURN:
  {
    assert(theQName != NULL);

    RAISE_ERROR(err::XPTY0004, loc, 
    ERROR_PARAMS(ZED(XPTY0004_NoReturnTypePromote_234),
                 valueType, targetType, theQName->getStringValue()));
    break;
  }
  case TREAT_FUNC_PARAM:
  {
    assert(theQName != NULL);

    RAISE_ERROR(err::XPTY0004, loc, 
    ERROR_PARAMS(ZED(XPTY0004_NoParamTypePromote_234),
                 valueType, targetType, theQName->getStringValue()));
    break;
  }
  case TREAT_TYPE_MATCH:
  {
    RAISE_ERROR(err::XPTY0004, loc, 
    ERROR_PARAMS(ZED(XPTY0004_NoTreatAs_23), valueType, targetType));
    break;
  }
  case TREAT_EXPR:
  {
    RAISE_ERROR(err::XPDY0050, loc, ERROR_PARAMS(valueType, targetType));
    break;
  }
  case TREAT_INDEX_DOMAIN:
  {
    RAISE_ERROR(zerr::ZDTY0010_INDEX_DOMAIN_TYPE_ERROR, loc,
    ERROR_PARAMS(theQName->getStringValue()));
    break;
  }
  case TREAT_INDEX_KEY:
  {
    RAISE_ERROR(zerr::ZDTY0011_INDEX_KEY_TYPE_ERROR, loc,
    ERROR_PARAMS(valueType, targetType, theQName->getStringValue()));
    break;
  }
  case TREAT_PATH_STEP:
  {
    RAISE_ERROR_NO_PARAMS(err::XPTY0019, loc);
    break;
  }
  case TREAT_PATH_DOT:
  {
    RAISE_ERROR_NO_PARAMS(err::XPTY0020, loc);
    break;
  }
  case TREAT_MULTI_VALUED_GROUPING_KEY:
  {
    RAISE_ERROR(err::XPTY0004, loc,
    ERROR_PARAMS(ZED(XPTY0004_MultiValuedGroupingKey)));
    break;
  }
  case TREAT_JSONIQ_VALUE:
  {
    RAISE_ERROR_NO_PARAMS(jerr::JNTY0002, loc);
    break;
  }
  case TREAT_JSONIQ_UPDATE_TARGET:
  {
    RAISE_ERROR(jerr::JNUP0008, loc,
    ERROR_PARAMS(ZED(JNUP0008_ObjectArray), valueType));
    break;
  }
  case TREAT_JSONIQ_OBJECT_UPDATE_TARGET:
  {
    RAISE_ERROR(jerr::JNUP0008, loc,
    ERROR_PARAMS(ZED(JNUP0008_Object), valueType));
    break;
  }
  case TREAT_JSONIQ_OBJECT_UPDATE_CONTENT:
  {
    RAISE_ERROR(jerr::JNUP0019, loc, ERROR_PARAMS(valueType));
    break;
  }
  case TREAT_JSONIQ_ARRAY_UPDATE_TARGET:
  {
    RAISE_ERROR(jerr::JNUP0008, loc,
    ERROR_PARAMS(ZED(JNUP0008_Array), valueType));
    break;
  }
  case TREAT_JSONIQ_OBJECT_UPDATE_VALUE:
  {
    RAISE_ERROR_NO_PARAMS(jerr::JNUP0017, loc);
    break;
  }
  default:
  {
    ZORBA_ASSERT(false);
  }
  }
}


UNARY_ACCEPT(TreatIterator);


/*******************************************************************************

********************************************************************************/
bool EitherNodesOrAtomicsIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  EitherNodesOrAtomicsIteratorState* state;
  DEFAULT_STACK_INIT(EitherNodesOrAtomicsIteratorState, state, planState);

  if (CONSUME(result, 0))
  {
    state->atomics = !result->isNode();

    STACK_PUSH(true, state);

    while (CONSUME(result, 0))
    {
      if (state->atomics == result->isNode())
        throw XQUERY_EXCEPTION(err::XPTY0018, ERROR_LOC(loc));

      STACK_PUSH(true, state);
    }
  }

  STACK_END(state);
}


NARY_ACCEPT(EitherNodesOrAtomicsIterator);


} // namespace zorba
/* vim:set et sw=2 ts=2: */
