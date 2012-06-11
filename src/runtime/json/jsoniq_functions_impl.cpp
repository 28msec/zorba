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
#include <zorba/config.h>

#ifdef ZORBA_WITH_JSON

#include "stdafx.h"

#include <sstream>

#include "system/globalenv.h"

#include "runtime/json/jsoniq_functions.h"
#include "runtime/json/jsoniq_functions_impl.h"
#include "runtime/visitors/planiter_visitor.h"

#include "diagnostics/diagnostic.h"
#include "diagnostics/xquery_diagnostics.h"
#include "diagnostics/util_macros.h"

#include "zorba/internal/diagnostic.h"

#include "context/static_context.h"

#include "types/typeimpl.h"
#include "types/typeops.h"
#include "types/root_typemanager.h"

#include "store/api/pul.h"
#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "store/api/store.h"
#include "store/api/copymode.h"

#include <zorba/store_consts.h>

namespace zorba {


/*******************************************************************************

********************************************************************************/
bool
JSONParseIterator::nextImpl(
  store::Item_t& result,
  PlanState& planState) const
{
  store::Item_t lInput;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lInput, theChildren[0].getp(), planState);

  if (lInput->isStreamable())
  {
    result = GENV_STORE.parseJSON(lInput->getStream(), 0);
  }
  else
  {
    std::stringstream lStr;
    lStr << lInput->getStringValue();

    if (theRelativeLocation == QueryLoc::null)
    {
      try
      {
        result = GENV_STORE.parseJSON(lStr, 0);
      }
      catch (zorba::ZorbaException& e)
      {
        set_source(e, theChildren[0]->getLocation());
        throw;
      }
    }
    else
    {
      // pass the query location of the StringLiteral to the JSON
      // parser such that it can give better error locations.
      // Also, parseJSON already raises an XQueryException with the
      // location. Hence, no need to catch and rethrow the exception here
      zorba::internal::diagnostic::location lLoc;
      lLoc = ERROR_LOC(theRelativeLocation);
      result = GENV_STORE.parseJSON(lStr, &lLoc);
    }
  }

  STACK_PUSH(true, state);

  STACK_END(state);
}


/*******************************************************************************
  json:names($o as object()) as xs:string*
********************************************************************************/
bool
JSONObjectNamesIterator::nextImpl(
  store::Item_t& result,
  PlanState& planState) const
{
  store::Item_t input;
  store::Item_t key;

  JSONObjectNamesIteratorState* state;
  DEFAULT_STACK_INIT(JSONObjectNamesIteratorState, state, planState);

  consumeNext(input, theChild.getp(), planState);

  state->thePairs = input->getObjectKeys();
  state->thePairs->open();

  while (state->thePairs->next(key))
  {
    result = key;
    STACK_PUSH (true, state);
  }
  state->thePairs = NULL;

  STACK_END (state);
}


/*******************************************************************************
  json:value($o as object(), $name as xs:string) as item()?
********************************************************************************/
bool
JSONObjectValueIterator::nextImpl(
  store::Item_t& result,
  PlanState& planState) const
{
  store::Item_t lInput;
  store::Item_t lName;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lInput, theChild0.getp(), planState);
  consumeNext(lName, theChild1.getp(), planState);

  result = lInput->getObjectValue(lName);
  
  STACK_PUSH(result != 0, state);

  STACK_END (state);
}


/*******************************************************************************
  json:project($o as object(), $names as xs:string*) as object()
********************************************************************************/
bool
JSONObjectProjectIterator::nextImpl(
  store::Item_t& result,
  PlanState& planState) const
{
  store::Item_t obj;
  store::Item_t key;
  store::Iterator_t keysIte;
  store::Item_t value;
  store::Item_t name;
  std::vector<store::Item_t> names;
  csize numNames = 0;
  store::CopyMode copymode;
  std::vector<store::Item_t> newNames;
  std::vector<store::Item_t> newValues;
  csize i;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(obj, theChild0.getp(), planState);

  while (consumeNext(name, theChild1.getp(), planState))
  {
    ++numNames;
    names.resize(numNames);
    names[numNames - 1].transfer(name);
  }

  keysIte = obj->getObjectKeys();
  keysIte->open();

  while (keysIte->next(key))
  {
    for (i = 0; i < numNames; ++i)
    {
      if (names[i]->getStringValue() == key->getStringValue())
        break;
    }

    if (i < numNames)
    {
      value = obj->getObjectValue(key);

      if (value->isNode() || value->isJSONItem())
        value = value->copy(NULL, copymode);

      newValues.push_back(value);
      newNames.push_back(key);
    }
  }

  keysIte->close();

  GENV_ITEMFACTORY->createJSONObject(result, newNames, newValues);

  STACK_PUSH(true, state);
  STACK_END(state);
}



/*******************************************************************************
  j:size($i as array()) as xs:integer*
********************************************************************************/
bool
JSONArraySizeIterator::nextImpl(
  store::Item_t& result,
  PlanState& planState) const
{
  store::Item_t lJSONItem;
  xs_integer lSize;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lJSONItem, theChild.getp(), planState);

  lSize = lJSONItem->getArraySize()->getIntegerValue();

  STACK_PUSH(GENV_ITEMFACTORY->createInteger(result, lSize), state);

  STACK_END(state);
}


/*******************************************************************************
  json:member($a as array(), $pos as xs:integer) as item()?
********************************************************************************/
bool
JSONArrayMemberIterator::nextImpl(
  store::Item_t& result,
  PlanState& planState) const
{
  store::Item_t lInput;
  store::Item_t lPosition;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lInput, theChild0.getp(), planState);
  consumeNext(lPosition, theChild1.getp(), planState);

  result = lInput->getArrayValue(lPosition);

  STACK_PUSH(result != 0, state);

  STACK_END(state);
}


/*******************************************************************************
  json:members($a as array()) as item()*
********************************************************************************/
bool
JSONArrayMembersIterator::nextImpl(
  store::Item_t& result,
  PlanState& planState) const
{
  store::Item_t array;

  JSONArrayMembersIteratorState* state;
  DEFAULT_STACK_INIT(JSONArrayMembersIteratorState, state, planState);

  consumeNext(array, theChild.getp(), planState);

  state->theMembers = array->getArrayValues();
  state->theMembers->open();
  while (state->theMembers->next(result))
  {
    STACK_PUSH(true, state);
  }
  state->theMembers->close();

  STACK_END(state);
}


/*******************************************************************************
  json:flatten($a as array()) as item()*

  op-zorba:flatten-internal($a as item()*) as item()*
********************************************************************************/
void JSONArrayFlattenIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  while (!theStack.empty())
  {
    theStack.pop();
  }
}


bool
JSONArrayFlattenIterator::nextImpl(
  store::Item_t& result,
  PlanState& planState) const
{
  store::Item_t item;
  bool lFoundArray = false;

  JSONArrayFlattenIteratorState* state;
  DEFAULT_STACK_INIT(JSONArrayFlattenIteratorState, state, planState);

  consumeNext(item, theChild.getp(), planState);

  assert(item->isJSONArray());

  state->theStack.push(item->getArrayValues());
  state->theStack.top()->open();

  while (!state->theStack.empty())
  {
    while (state->theStack.top()->next(result))
    {
      if (result->isJSONArray())
      {
        state->theStack.push(result->getArrayValues());
        state->theStack.top()->open();
        lFoundArray = true;
        break;
      }
      
      STACK_PUSH(true, state);
    }
    
    if (lFoundArray)
    {
      lFoundArray = false;
      continue;
    }
    
    state->theStack.top()->close();
    state->theStack.pop();
  }

  STACK_END(state);
}


/*******************************************************************************
  op_zorba:json-item-accessor($i as json-item(), $s as xs:anyAtomic) as item()?
********************************************************************************/
bool
JSONItemAccessorIterator::nextImpl(
  store::Item_t& result,
  PlanState& planState) const
{
  store::Item_t input;
  store::Item_t selector;

  const TypeManager* tm = theSctx->get_typemanager();

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(input, theChild0.getp(), planState);
  consumeNext(selector, theChild1.getp(), planState);

  if (input->isJSONArray())
  {
    store::SchemaTypeCode type = selector->getTypeCode();

    if (!TypeOps::is_subtype(type, store::XS_INTEGER))
    {
      xqtref_t type = tm->create_value_type(selector, loc);

      RAISE_ERROR(err::XPTY0004, loc, 
      ERROR_PARAMS(ZED(XPTY0004_NoTypePromotion_23),
                   type->toSchemaString(),
                   GENV_TYPESYSTEM.INTEGER_TYPE_ONE->toSchemaString()));
    }

    result = input->getArrayValue(selector);
  }
  else if (input->isJSONObject())
  {
    store::SchemaTypeCode type = selector->getTypeCode();

    if (!TypeOps::is_subtype(type, store::XS_STRING) &&
        !TypeOps::is_subtype(type, store::XS_UNTYPED_ATOMIC) &&
        !TypeOps::is_subtype(type, store::XS_ANY_URI))
    {
      xqtref_t type = tm->create_value_type(selector, loc);

      RAISE_ERROR(err::XPTY0004, loc, 
      ERROR_PARAMS(ZED(XPTY0004_NoTypePromotion_23),
                   type->toSchemaString(),
                   GENV_TYPESYSTEM.STRING_TYPE_ONE->toSchemaString()));
    }

    result = input->getObjectValue(selector);
  }
  else
  {
    ZORBA_ASSERT(false);
  }

  STACK_PUSH(result != 0, state);

  STACK_END(state);
}


/*******************************************************************************
  j:null()) as jdm:null
********************************************************************************/
bool
JSONNullIterator::nextImpl(
  store::Item_t& result,
  PlanState& planState) const
{
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  STACK_PUSH(GENV_ITEMFACTORY->createJSONNull(result), state);

  STACK_END(state);
}


/*******************************************************************************
  updating function op-zorba:object-insert(
      $o as object(),
      $name1 as xs:string, $value1 as item(), 
      ..., 
      $nameN as xs:string, $valueN as item())
********************************************************************************/
JSONObjectInsertIterator::JSONObjectInsertIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& args,
    bool copyInput)
  :
  NaryBaseIterator<JSONObjectInsertIterator, PlanIteratorState>(sctx, loc, args)
{
  csize numPairs = (args.size() - 1) / 2;

  theCopyInputs.resize(numPairs);

  for (csize i = 0; i < numPairs; ++i)
  {
    if (theChildren[2 + 2*i]->isConstructor())
    {
      theCopyInputs[i] = false;
    }
    else
    {
      theCopyInputs[i] = copyInput;
    }
  }
}


void JSONObjectInsertIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, 
  (NaryBaseIterator<JSONObjectInsertIterator, PlanIteratorState>*)this);

  SERIALIZE_BOOL_VEC(theCopyInputs);
}


bool JSONObjectInsertIterator::nextImpl(
  store::Item_t& result,
  PlanState& planState) const
{
  store::Item_t object;
  store::Item_t name;
  store::Item_t value;
  std::vector<store::Item_t> names;
  std::vector<store::Item_t> values;
  store::PUL_t pul;
  store::CopyMode copymode;
  csize numPairs;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(object, theChildren[0].getp(), planState);

  copymode.set(true, 
               theSctx->construction_mode() == StaticContextConsts::cons_preserve,
               theSctx->preserve_mode() == StaticContextConsts::preserve_ns,
               theSctx->inherit_mode() == StaticContextConsts::inherit_ns);

  numPairs = (theChildren.size() - 1) / 2;

  names.resize(numPairs);
  values.resize(numPairs);

  for (csize i = 0; i < numPairs; ++i)
  {
    consumeNext(name, theChildren[i + 1].getp(), planState);
    consumeNext(value, theChildren[i + 2].getp(), planState);

    names[i].transfer(name);

    if (theCopyInputs[i] && (value->isNode() || value->isJSONItem()))
      value = value->copy(NULL, copymode);

    values[i].transfer(value);
  }

  pul = GENV_ITEMFACTORY->createPendingUpdateList();

  pul->addJSONObjectInsert(&loc, object, names, values);

  result.transfer(pul);

  STACK_PUSH(true, state);

  STACK_END(state);
}


NARY_ACCEPT(JSONObjectInsertIterator);

SERIALIZABLE_CLASS_VERSIONS(JSONObjectInsertIterator)


/*******************************************************************************
  updating function op-zorba:array-insert(
      $o as array(),
      $pos as xs:integer, 
      $values as item()*, 
********************************************************************************/
bool JSONArrayInsertIterator::nextImpl(
  store::Item_t& result,
  PlanState& planState) const
{
  store::Item_t array;
  store::Item_t member;
  store::Item_t pos;
  std::vector<store::Item_t> members;
  store::PUL_t pul;
  store::CopyMode copymode;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(array, theChildren[0].getp(), planState);
  consumeNext(pos, theChildren[1].getp(), planState);

  copymode.set(true, 
               theSctx->construction_mode() == StaticContextConsts::cons_preserve,
               theSctx->preserve_mode() == StaticContextConsts::preserve_ns,
               theSctx->inherit_mode() == StaticContextConsts::inherit_ns);

  while (consumeNext(member, theChildren[2].getp(), planState))
  {
    if (member->isNode() || member->isJSONItem())
    {
      member = member->copy(NULL, copymode);
    }

    members.resize(members.size() + 1);
    members.back().transfer(member);
  }

  pul = GENV_ITEMFACTORY->createPendingUpdateList();

  pul->addJSONArrayInsert(&loc, array, pos, members);

  result.transfer(pul);

  STACK_PUSH(true, state);

  STACK_END (state);
}


/*******************************************************************************
  updating function op-zorba:json-delete(
      $target as json-item(),
      $selector as xs:anyAtomicType) 
********************************************************************************/
bool JSONDeleteIterator::nextImpl(
    store::Item_t& result, 
    PlanState& planState) const
{
  store::Item_t target;
  store::Item_t selector;
  store::PUL_t pul;

  const TypeManager* tm = theSctx->get_typemanager();

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(target, theChildren[0].getp(), planState);
  consumeNext(selector, theChildren[1].getp(), planState);

  pul = GENV_ITEMFACTORY->createPendingUpdateList();

  if (target->isJSONObject())
  {
    store::SchemaTypeCode type = selector->getTypeCode();

    if (type != store::XS_STRING && type != store::XS_ANY_URI)
    {
      xqtref_t type = tm->create_value_type(selector, loc);

      RAISE_ERROR(jerr::JNTY0007, loc, 
      ERROR_PARAMS(ZED(JNTY0007_Object), type->toSchemaString()));
    }

    pul->addJSONObjectDelete(&loc, target, selector);
  }
  else if (target->isJSONArray())
  {
    store::SchemaTypeCode type = selector->getTypeCode();

    if (type != store::XS_INTEGER)
    {
      xqtref_t type = tm->create_value_type(selector, loc);

      RAISE_ERROR(jerr::JNTY0007, loc, 
      ERROR_PARAMS(ZED(JNTY0007_Array), type->toSchemaString()));
    }

    pul->addJSONArrayDelete(&loc, target, selector);
  }

  result.transfer(pul);

  STACK_PUSH(true, state);

  STACK_END (state);
}


/*******************************************************************************
  updating function op-zorba:replace-value(
      $target as json-item(),
      $selector as xs:anyAtomicType, 
      $newValue as item()) 
********************************************************************************/
JSONReplaceValueIterator::JSONReplaceValueIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& args,
    bool copyInput)
  :
  NaryBaseIterator<JSONReplaceValueIterator, PlanIteratorState>(sctx, loc, args)
{
  if (theChildren[2]->isConstructor())
  {
    theCopyInput = false;
  }
  else
  {
    theCopyInput = copyInput;
  }
}


bool JSONReplaceValueIterator::nextImpl(
  store::Item_t& result,
  PlanState& planState) const
{
  store::Item_t target;
  store::Item_t selector;
  store::Item_t newValue;
  store::PUL_t pul;
  store::CopyMode copymode;

  const TypeManager* tm = theSctx->get_typemanager();

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(target, theChildren[0].getp(), planState);
  consumeNext(selector, theChildren[1].getp(), planState);
  consumeNext(newValue, theChildren[2].getp(), planState);

  if (theCopyInput && (newValue->isNode() || newValue->isJSONItem()))
  {
    copymode.set(true, 
      theSctx->construction_mode() == StaticContextConsts::cons_preserve,
      theSctx->preserve_mode() == StaticContextConsts::preserve_ns,
      theSctx->inherit_mode() == StaticContextConsts::inherit_ns);

    newValue = newValue->copy(NULL, copymode);
  }

  pul = GENV_ITEMFACTORY->createPendingUpdateList();

  if (target->isJSONObject())
  {
    store::SchemaTypeCode type = selector->getTypeCode();

    if (type != store::XS_STRING && type != store::XS_ANY_URI)
    {
      xqtref_t type = tm->create_value_type(selector, loc);

      RAISE_ERROR(jerr::JNTY0007, loc, 
      ERROR_PARAMS(ZED(JNTY0007_Object), type->toSchemaString()));
    }

    pul->addJSONObjectReplaceValue(&loc, target, selector, newValue);
  }
  else if (target->isJSONArray())
  {
    store::SchemaTypeCode type = selector->getTypeCode();

    if (type != store::XS_INTEGER)
    {
      xqtref_t type = tm->create_value_type(selector, loc);

      RAISE_ERROR(jerr::JNTY0007, loc, 
      ERROR_PARAMS(ZED(JNTY0007_Array), type->toSchemaString()));
    }

    pul->addJSONArrayReplaceValue(&loc, target, selector, newValue);
  }

  result.transfer(pul);

  STACK_PUSH(true, state);

  STACK_END(state);
}


/*******************************************************************************
  updating function op-zorba:object-rename(
      $o as object(),
      $name as xs:string, 
      $newName as xs:string) 
********************************************************************************/
bool JSONRenameIterator::nextImpl(
  store::Item_t& result,
  PlanState& planState) const
{
  store::Item_t target;
  store::Item_t name;
  store::Item_t newName;
  store::PUL_t pul;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(target, theChildren[0].getp(), planState);
  consumeNext(name, theChildren[1].getp(), planState);
  consumeNext(newName, theChildren[2].getp(), planState);

  pul = GENV_ITEMFACTORY->createPendingUpdateList();

  pul->addJSONObjectRename(&loc, target, name, newName);

  result.transfer(pul);

  STACK_PUSH(true, state);

  STACK_END(state);
}


} /* namespace zorba */
/* vim:set et sw=2 ts=2: */
#endif /* ZORBA_WITH_JSON */
