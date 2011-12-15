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

#include "store/api/item_factory.h"
#include "store/api/copymode.h"

#include "runtime/json/json_constructors.h"
#include "runtime/visitors/planiter_visitor.h"

#include "system/globalenv.h"

#include "diagnostics/util_macros.h"

#ifdef ZORBA_WITH_JSON

namespace zorba
{

SERIALIZABLE_CLASS_VERSIONS(JSONObjectIterator)
END_SERIALIZABLE_CLASS_VERSIONS(JSONObjectIterator)

SERIALIZABLE_CLASS_VERSIONS(JSONArrayIterator)
END_SERIALIZABLE_CLASS_VERSIONS(JSONArrayIterator)

SERIALIZABLE_CLASS_VERSIONS(JSONPairIterator)
END_SERIALIZABLE_CLASS_VERSIONS(JSONPairIterator)


/*********************************************************************************

*********************************************************************************/
JSONPairIterator::JSONPairIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& name,
    PlanIter_t& value,
    bool copyInput)
  :
  BinaryBaseIterator<JSONPairIterator,
                     PlanIteratorState>(sctx, loc, name, value),
  theCopyInput(copyInput)
{
}


void JSONPairIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, 
  (BinaryBaseIterator<JSONPairIterator, PlanIteratorState>*)this);

  ar & theCopyInput;
}


bool JSONPairIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::CopyMode copymode;
  store::Item_t name;
  store::Item_t value;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(name, theChild0, planState);
  consumeNext(value, theChild1, planState);

  while (value->isJSONPair())
  {
    value = value->getValue();
  }

  if (theCopyInput && (value->isNode() || value->isJSONItem()))
  {
    copymode.set(true, true, true, true);

    value = value->copy(NULL, copymode);
  }

  GENV_ITEMFACTORY->createJSONObjectPair(result, name, value);

  STACK_END(state);
}


BINARY_ACCEPT(JSONPairIterator);



/*********************************************************************************

*********************************************************************************/
JSONObjectIterator::JSONObjectIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& content,
    bool copyInput)
  :
  NaryBaseIterator<JSONObjectIterator,
                   PlanIteratorState>(sctx, loc, content)
{
  csize numChildren = theChildren.size();

  theCopyInputs.resize(numChildren);

  for (csize i = 0; i < numChildren; ++i)
  {
    if (dynamic_cast<JSONPairIterator*>(theChildren[i].getp()) != NULL)
    {
      theCopyInputs[i] = false;
    }
    else
    {
      theCopyInputs[i] = copyInput;
    }
  }
}


void JSONObjectIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, 
  (NaryBaseIterator<JSONObjectIterator, PlanIteratorState>*)this);

  //ar & theCopyInputs; // TODO
}


bool JSONObjectIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::ItemFactory* factory = GENV_ITEMFACTORY;
  store::CopyMode copymode;
  store::Item_t child;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  try
  {
    factory->createJSONObject(result);

    for (csize i = 0; i < theChildren.size(); ++i)
    {
      copymode.set(theCopyInputs[i], true, true, true);

      while (consumeNext(child, theChildren[i], planState))
      {
        if (!child->isJSONItem() || 
            child->getJSONItemKind() != store::StoreConsts::jsonObjectPair)
        {
          RAISE_ERROR(zerr::JSDY0001, loc, ERROR_PARAMS(child->printKind()));
          
          child->copy(result, copymode);
        }
      }
    }
  }
  catch (XQueryException& e)
  {
    result = NULL;
    set_source(e, loc, false);
    throw;
  }

  STACK_PUSH(true, state);
  STACK_END(state);
}


NARY_ACCEPT(JSONObjectIterator);


/*********************************************************************************

*********************************************************************************/
JSONArrayIterator::JSONArrayIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& content)
  :
  UnaryBaseIterator<JSONArrayIterator,
                    PlanIteratorState>(sctx, loc, content)
{
}


void JSONArrayIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, 
  (UnaryBaseIterator<JSONArrayIterator, PlanIteratorState>*)this);
}


bool JSONArrayIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  STACK_END(state);
}


UNARY_ACCEPT(JSONArrayIterator);


}

#endif // ZORBA_WITH_JSON
