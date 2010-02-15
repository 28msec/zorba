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
#include <fstream>

#include "zorbaerrors/Assert.h"
#include "zorbaerrors/error_messages.h"

#include "system/globalenv.h"

#include "context/static_context.h"
#include "context/statically_known_collection.h"
#include "context/static_context_consts.h"
#include "context/dynamic_context.h"
#include "context/static_context_consts.h"

#include "compiler/indexing/value_ic.h"
#include "runtime/introspection/sctx.h"
#include "functions/function.h"

#include "store/api/item_factory.h"
#include "store/api/iterator.h"
#include "store/api/collection.h"
#include "store/api/store.h"


namespace zorba {

/*******************************************************************************

********************************************************************************/
bool IsDeclaredCollectionIterator::nextImpl(
    store::Item_t& aResult,
    PlanState& aPlanState) const
{
  store::Item_t      lName;

  PlanIteratorState* lState;
  DEFAULT_STACK_INIT(PlanIteratorState, lState, aPlanState);

  consumeNext(lName, theChildren[0].getp(), aPlanState);

  if (theSctx->lookup_collection(lName.getp()) == 0) 
  {
    STACK_PUSH(GENV_ITEMFACTORY->createBoolean(aResult, false), lState);
  }
  else 
  {
    STACK_PUSH(GENV_ITEMFACTORY->createBoolean(aResult, true), lState);
  }
  STACK_END (lState);
}


/*******************************************************************************

********************************************************************************/
DeclaredCollectionsIteratorState::~DeclaredCollectionsIteratorState()
{
  if ( nameItState != NULL ) 
  {
    nameItState->close();
    nameItState = NULL;
  }
}


void DeclaredCollectionsIteratorState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  nameItState = NULL;
}


void DeclaredCollectionsIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  if ( nameItState != NULL ) 
  {
    nameItState->close();
    nameItState = NULL;
  }
}


bool DeclaredCollectionsIterator::nextImpl(
    store::Item_t& aResult,
    PlanState& aPlanState) const
{
  store::Item_t lName;

  DeclaredCollectionsIteratorState* lState;
  DEFAULT_STACK_INIT(DeclaredCollectionsIteratorState, lState, aPlanState);

  for ((lState->nameItState = theSctx->collection_names())->open();
       lState->nameItState->next(lName); )
  {
    aResult = lName;
    STACK_PUSH(true, lState);
  }

  lState->nameItState->close();

  STACK_END(lState);
}


/*******************************************************************************

********************************************************************************/
bool IsDeclaredIndexIterator::nextImpl(
    store::Item_t& aResult,
    PlanState& aPlanState) const
{
  store::Item_t      lName;

  PlanIteratorState* lState;
  DEFAULT_STACK_INIT(PlanIteratorState, lState, aPlanState);

  consumeNext(lName, theChildren[0].getp(), aPlanState);

  if (theSctx->lookup_index(lName.getp()) == 0) 
  {
    STACK_PUSH(GENV_ITEMFACTORY->createBoolean(aResult, false), lState);
  }
  else 
  {
    STACK_PUSH(GENV_ITEMFACTORY->createBoolean(aResult, true), lState);
  }

  STACK_END(lState);
}


/*******************************************************************************

********************************************************************************/
DeclaredIndexesIteratorState::~DeclaredIndexesIteratorState()
{
  if (nameItState != NULL) 
  {
    nameItState->close();
    nameItState = NULL;
  }
}


void DeclaredIndexesIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  if (nameItState != NULL) 
  {
    nameItState->close();
    nameItState = NULL;
  }
}


bool DeclaredIndexesIterator::nextImpl(
    store::Item_t& aResult,
    PlanState& aPlanState) const
{
  store::Item_t lName;

  DeclaredIndexesIteratorState* lState;
  DEFAULT_STACK_INIT(DeclaredIndexesIteratorState, lState, aPlanState);

  for ((lState->nameItState = theSctx->index_names())->open();
       lState->nameItState->next(lName); )
  {
    aResult = lName;
    STACK_PUSH(true, lState);
  }

  lState->nameItState->close();

  STACK_END(lState);
}


/*******************************************************************************

********************************************************************************/
StaticNamespacesIteratorState::~StaticNamespacesIteratorState()
{
}


void StaticNamespacesIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  position = 0;
}


bool StaticNamespacesIterator::nextImpl(
    store::Item_t& aResult,
    PlanState& aPlanState) const
{
  StaticNamespacesIteratorState* lState;
  xqpString temp;

  DEFAULT_STACK_INIT(StaticNamespacesIteratorState, lState, aPlanState);

  lState->string_keys.reset(theSctx->get_all_str_keys());
  lState->position = 0;

  while (lState->position < lState->string_keys->size())
  {
    if (lState->string_keys->at(lState->position).indexOf("ns:") == 0)
    {
      temp = lState->string_keys->at(lState->position).substr(3);

      STACK_PUSH(GENV_ITEMFACTORY->createString(aResult, temp.theStrStore), lState);
    }
    lState->position++;
  }

  STACK_END (lState);
}


/*******************************************************************************

********************************************************************************/
bool StaticNamespaceBindingIterator::nextImpl(
    store::Item_t& aResult,
    PlanState& aPlanState) const
{
  store::Item_t lName;
  xqpStringStore_t ns;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);

  consumeNext(lName, theChildren[0].getp(), aPlanState);

  if (theSctx->lookup_ns(ns, lName->getStringValue(), loc))
    STACK_PUSH(GENV_ITEMFACTORY->createString(aResult, ns), state);

  STACK_END(state);
}


/*******************************************************************************

********************************************************************************/
InscopeVariablesIteratorState::~InscopeVariablesIteratorState()
{
}


void InscopeVariablesIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  position = 0;
}


bool InscopeVariablesIterator::nextImpl(
    store::Item_t& aResult,
    PlanState& aPlanState) const
{
  xqpString name, ns;

  InscopeVariablesIteratorState* lState;
  DEFAULT_STACK_INIT(InscopeVariablesIteratorState, lState, aPlanState);

  lState->keymap.reset(theSctx->get_all_keymap_keys());
  lState->position = 0;

  while (lState->position < lState->keymap->size())
  {
    name = lState->keymap->at(lState->position);
    if (name.indexOf("var:") == 0 && name.indexOf("var:$$") == -1)
    {
      name = name.substr(4);
      if (name.indexOf(":") != -1)
      {
        ns = name.substr(name.indexOf(":") + 1);
        name = name.substr(0, name.indexOf(":"));
      }
      STACK_PUSH(GENV_ITEMFACTORY->createQName(aResult,
                                               ns.theStrStore,
                                               xqpString().theStrStore,
                                               name.theStrStore),
                 lState);
    }

    lState->position++;
  }

  STACK_END(lState);
}


/*******************************************************************************

********************************************************************************/
bool DefaultCollectionTypeIterator::nextImpl(
    store::Item_t& aResult,
    PlanState& aPlanState) const
{
  store::Item_t lName;
  xqpString type_string;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);

  type_string = theSctx->lookup_type("type:defcollection:")->toStdString();

  STACK_PUSH(GENV_ITEMFACTORY->createString(aResult, type_string.theStrStore), state);
  STACK_END(state);
}


/*******************************************************************************

********************************************************************************/
bool XPath10CompatModeIterator::nextImpl(
    store::Item_t& aResult,
    PlanState& aPlanState) const
{
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);

  STACK_PUSH(GENV_ITEMFACTORY->createBoolean(aResult,
                                             theSctx->xpath_compatibility() == StaticContextConsts::xpath1_0_only), state);

  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
bool StaticallyKnownDocumentsIterator::nextImpl(
    store::Item_t& aResult,
    PlanState& aPlanState) const
{
  PlanIteratorState* state;
  store::Item_t lName;
  xqpString temp_str;
  xqtref_t type;

  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);

  consumeNext(lName, theChildren[0].getp(), aPlanState);
  type = theSctx->get_document_type(xqpString(lName->getStringValue()));
  if (type.getp() == NULL)
  {
    temp_str = "document-node()?"; // as per http://www.w3.org/TR/xquery/#dt-known-docs
    STACK_PUSH(GENV_ITEMFACTORY->createString(aResult, temp_str.theStrStore), state);
  }
  else
  {
    STACK_PUSH(type->get_qname(), state);

    /*
    ns = qname->getNamespace();
    prefix = qname->getPrefix();

    // find the prefix of the given namespace
    if (prefix.length() == 0)
    {
      string_keys.reset(theSctx->get_all_str_keys());
      for (unsigned int i=0; i<string_keys->size(); i++)
      {
        theSctx->lookup_ns(string_keys->at(i).substr(3), temp_ns);
        if (temp_ns == ns)
        {
          prefix = string_keys->at(i).substr(3);
          break;
        }
      }
    }
    */

    // STACK_PUSH( GENV_ITEMFACTORY->createQName(aResult, ns.theStrStore, prefix.theStrStore, qname->getLocalName()), state);
  }

  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
StaticallyKnownCollationsIteratorState::~StaticallyKnownCollationsIteratorState()
{
}

void StaticallyKnownCollationsIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  position = 0;
}


bool StaticallyKnownCollationsIterator::nextImpl(
    store::Item_t& aResult,
    PlanState& aPlanState) const
{
  xqpString temp;

  StaticallyKnownCollationsIteratorState* lState;
  DEFAULT_STACK_INIT(StaticallyKnownCollationsIteratorState, lState, aPlanState);

  lState->keymap.reset(theSctx->get_all_str_keys());
  lState->position = 0;

  while (lState->position < lState->keymap->size())
  {
    temp = lState->keymap->at(lState->position);
    if (temp.indexOf("coll:") == 0 && temp.indexOf("coll:default") == -1)
    {
      temp = temp.substr(5, temp.size());
      STACK_PUSH(GENV_ITEMFACTORY->createString(aResult, temp.theStrStore), lState);
    }

    lState->position++;
  }

  STACK_END(lState);
}


/*******************************************************************************

********************************************************************************/
bool ConstructionModeIterator::nextImpl(
    store::Item_t& aResult,
    PlanState& aPlanState) const
{
  xqpString temp;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);

  if (theSctx->construction_mode() == StaticContextConsts::cons_preserve)
    temp = "preserve";
  else
    temp = "strip";

  STACK_PUSH(GENV_ITEMFACTORY->createString(aResult, temp.theStrStore), state);
  STACK_END(state);
}


/*******************************************************************************

********************************************************************************/
bool OrderingModeIterator::nextImpl(
    store::Item_t& aResult,
    PlanState& aPlanState) const
{
  PlanIteratorState* state;
  xqpString temp;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);

  if (theSctx->ordering_mode() == StaticContextConsts::ordered)
    temp = "ordered";
  else
    temp = "unordered";

  STACK_PUSH(GENV_ITEMFACTORY->createString(aResult, temp.theStrStore), state);
  STACK_END(state);
}


/*******************************************************************************

********************************************************************************/
bool DefaultOrderIterator::nextImpl(
    store::Item_t& aResult,
    PlanState& aPlanState) const
{
  PlanIteratorState* state;
  xqpString temp;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);

  if (theSctx->empty_order_mode() == StaticContextConsts::empty_greatest)
    temp = "greatest";
  else
    temp = "least";

  STACK_PUSH(GENV_ITEMFACTORY->createString(aResult, temp.theStrStore), state);
  STACK_END(state);
}


/*******************************************************************************

********************************************************************************/
bool BoundarySpacePolicyIterator::nextImpl(
    store::Item_t& aResult,
    PlanState& aPlanState) const
{
  xqpString temp;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);

  if (theSctx->boundary_space_mode() == StaticContextConsts::preserve_space)
    temp = "preserve";
  else
    temp = "strip";

  STACK_PUSH( GENV_ITEMFACTORY->createString(aResult, temp.theStrStore), state);
  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
bool CopyNamespacesModeIterator::nextImpl(
    store::Item_t& aResult, 
    PlanState& aPlanState) const
{
  PlanIteratorState* state;
  xqpString inherit, preserve;

  if (theSctx->inherit_mode() == StaticContextConsts::inherit_ns)
    inherit = "inherit";
  else
    inherit = "no-inherit";

  if (theSctx->preserve_mode() == StaticContextConsts::preserve_ns)
    preserve = "preserve";
  else
    preserve = "no-preserve";

  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);
  STACK_PUSH(GENV_ITEMFACTORY->createString(aResult, inherit.theStrStore), state);
  STACK_PUSH(GENV_ITEMFACTORY->createString(aResult, preserve.theStrStore), state);
  STACK_END(state);
}


/*******************************************************************************

********************************************************************************/
FunctionNamesIteratorState::~FunctionNamesIteratorState()
{
}

void FunctionNamesIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  position = 0;
}


bool FunctionNamesIterator::nextImpl(
    store::Item_t& aResult,
    PlanState& aPlanState) const
{
  FunctionNamesIteratorState* lState;
  xqpString temp, ns;

  DEFAULT_STACK_INIT(FunctionNamesIteratorState, lState, aPlanState);

  lState->keymap.reset(theSctx->get_all_keymap_keys());
  lState->position = 0;

  while (lState->position < lState->keymap->size())
  {
    temp = lState->keymap->at(lState->position);
    if (temp.indexOf("fmap:") == 0)
    {
      temp = temp.substr(5);
      if (temp.indexOf(":") >= 0)
      {
        ns = temp.substr(temp.indexOf(":")+1);
        temp = temp.substr(0, temp.indexOf(":"));
      }
      STACK_PUSH(GENV_ITEMFACTORY->createQName(aResult,
                                               ns.theStrStore,
                                               xqpString().theStrStore,
                                               temp.theStrStore),
                  lState);
    }

    lState->position++;
  }

  STACK_END(lState);
}


/*******************************************************************************

********************************************************************************/
bool FunctionArgumentsCountIterator::nextImpl(
    store::Item_t& aResult,
    PlanState& aPlanState) const
{
  FunctionArgumentsCountIteratorState* lState;
  store::Item_t lName;
  std::vector<function*> funcs;

  DEFAULT_STACK_INIT(FunctionArgumentsCountIteratorState, lState, aPlanState);

  consumeNext(lName, theChildren[0].getp(), aPlanState);
  theSctx->find_functions(lName, funcs);
  for (unsigned int i=0; i<funcs.size(); i++)
    lState->arities.push_back(funcs[i]->get_arity());

  lState->position = 0;
  while (lState->position < lState->arities.size())
  {
    STACK_PUSH( GENV_ITEMFACTORY->createInt(aResult, lState->arities[lState->position]), lState);
    lState->position++;
  }

  STACK_END (lState);
}

FunctionArgumentsCountIteratorState::~FunctionArgumentsCountIteratorState()
{
}

void FunctionArgumentsCountIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  position = 0;
}


/*******************************************************************************

********************************************************************************/
InScopeSchemaTypesIteratorState::~InScopeSchemaTypesIteratorState()
{
}

void InScopeSchemaTypesIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  position = 0;
}


bool InScopeSchemaTypesIterator::nextImpl(
    store::Item_t& aResult,
    PlanState& aPlanState) const
{
  InScopeSchemaTypesIteratorState* state;
  store::Item_t temp;
  // const simplestore::QNameItem* temp_qname;

  DEFAULT_STACK_INIT(InScopeSchemaTypesIteratorState, state, aPlanState);

  /*
  for (state->position = 0;
       state->position < ((simplestore::SimpleStore*)&GENV_STORE)->theSchemaTypeNames.size();
       state->position++)
  {
    temp = ((simplestore::SimpleStore*)&GENV_STORE)->theSchemaTypeNames[state->position];
    temp_qname = dynamic_cast<simplestore::QNameItem*>(temp.getp());
    if (temp_qname != NULL)
      STACK_PUSH( GENV_ITEMFACTORY->createQName(aResult, temp_qname->getNamespace(), temp_qname->getPrefix(), temp_qname->getLocalName()), state);
  }
  */

  STACK_END (state);
}



/*******************************************************************************
*******************************************************************************/
bool
IsDeclaredICIterator::nextImpl(store::Item_t& aResult, PlanState& aPlanState)
  const
{
  PlanIteratorState *lState;
  store::Item_t      lName;

  DEFAULT_STACK_INIT(PlanIteratorState, lState, aPlanState);
  consumeNext(lName, theChildren[0].getp(), aPlanState);
  if (theSctx->lookup_ic(lName.getp()) == 0) {
    STACK_PUSH (GENV_ITEMFACTORY->createBoolean ( aResult, false ), lState);
  }
  else {
    STACK_PUSH (GENV_ITEMFACTORY->createBoolean ( aResult, true ), lState);
  }
  STACK_END (lState);
}

/*******************************************************************************
********************************************************************************/
bool
DeclaredICsIterator::nextImpl(store::Item_t& aResult, PlanState& aPlanState)
  const
{
  DeclaredICsIteratorState * lState;
  store::Item_t              lName;

  DEFAULT_STACK_INIT(DeclaredICsIteratorState, lState, aPlanState);

  for ((lState->nameItState = theSctx->ic_names())->open ();
       lState->nameItState->next(lName); )
  {
    aResult = lName;
    STACK_PUSH( true, lState);
  }

  lState->nameItState->close();

  STACK_END (lState);
}

DeclaredICsIteratorState::~DeclaredICsIteratorState()
{
  if ( nameItState != NULL ) {
    nameItState->close();
    nameItState = NULL;
  }
}


void DeclaredICsIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  if ( nameItState != NULL ) {
    nameItState->close();
    nameItState = NULL;
  }
}

} /* namespace zorba */
