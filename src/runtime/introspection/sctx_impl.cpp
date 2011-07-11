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

#include <fstream>

#include "diagnostics/assert.h"
#include "diagnostics/xquery_diagnostics.h"
#include "zorbatypes/numconversions.h"

#include "system/globalenv.h"

#include "context/static_context.h"
#include "context/static_context_consts.h"
#include "context/dynamic_context.h"
#include "context/static_context_consts.h"

#include "compiler/expression/var_expr.h"

#include "runtime/introspection/sctx.h"

#include "functions/function.h"

#include "store/api/item_factory.h"
#include "store/api/iterator.h"
#include "store/api/collection.h"
#include "store/api/store.h"


#ifndef ZORBA_NO_XMLSCHEMA
#include "types/schema/xercesIncludes.h"
#include "types/schema/schema.h"
#include "types/schema/PrintSchema.h"
#include "types/schema/StrX.h"
#endif // #ifndef ZORBA_NO_XMLSCHEMA


namespace zorba {

/*******************************************************************************

********************************************************************************/
StaticNamespacesIteratorState::~StaticNamespacesIteratorState()
{
}


void StaticNamespacesIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  thePosition = 0;
  theBindings.clear();
}


bool StaticNamespacesIterator::nextImpl(
    store::Item_t& aResult,
    PlanState& aPlanState) const
{
  StaticNamespacesIteratorState* lState;
  zstring prefix;

  DEFAULT_STACK_INIT(StaticNamespacesIteratorState, lState, aPlanState);

  theSctx->get_namespace_bindings(lState->theBindings);
  lState->thePosition = 0;

  while (lState->thePosition < lState->theBindings.size())
  {
    prefix = lState->theBindings[lState->thePosition].first;
    STACK_PUSH(GENV_ITEMFACTORY->createString(aResult, prefix), lState);
    ++lState->thePosition;
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
  zstring ns;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);

  consumeNext(lName, theChildren[0].getp(), aPlanState);

  if (theSctx->lookup_ns(ns, lName->getStringValue(), loc, zerr::ZXQP0000_NO_ERROR))
  {
    STACK_PUSH(GENV_ITEMFACTORY->createString(aResult, ns), state);
  }

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
  thePosition = 0;
  theVariables.clear();
}


bool InscopeVariablesIterator::nextImpl(
    store::Item_t& aResult,
    PlanState& aPlanState) const
{
  InscopeVariablesIteratorState* state;
  DEFAULT_STACK_INIT(InscopeVariablesIteratorState, state, aPlanState);

  theSctx->getVariables(state->theVariables);
  state->thePosition = 0;

  while (state->thePosition < state->theVariables.size())
  {
    aResult = state->theVariables[state->thePosition]->get_name();
    STACK_PUSH(true, state);
    ++state->thePosition;
  }

  STACK_END(state);
}


/*******************************************************************************

********************************************************************************/
bool DefaultCollectionTypeIterator::nextImpl(
    store::Item_t& aResult,
    PlanState& aPlanState) const
{
  store::Item_t lName;
  zstring typeString;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);

  typeString = theSctx->get_default_w3c_collection_type()->toSchemaString();

  STACK_PUSH(GENV_ITEMFACTORY->createString(aResult, typeString), state);
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

  STACK_END(state);
}


/*******************************************************************************

********************************************************************************/
StaticallyKnownDocumentsIteratorState::~StaticallyKnownDocumentsIteratorState()
{
}


void StaticallyKnownDocumentsIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  thePosition = 0;
  theDocuments.clear();
}


bool StaticallyKnownDocumentsIterator::nextImpl(
    store::Item_t& aResult,
    PlanState& aPlanState) const
{
  StaticallyKnownDocumentsIteratorState* state;
  DEFAULT_STACK_INIT(StaticallyKnownDocumentsIteratorState, state, aPlanState);

  theSctx->get_all_documents(state->theDocuments);
  state->thePosition = 0;
  while (state->thePosition < state->theDocuments.size())
  {
    STACK_PUSH(GENV_ITEMFACTORY->createString(aResult, state->theDocuments[state->thePosition]), state);
    ++state->thePosition;
  }

  STACK_END(state);
}


/*******************************************************************************

********************************************************************************/
bool StaticallyKnownDocumentTypeIterator::nextImpl(
    store::Item_t& aResult,
    PlanState& aPlanState) const
{
  PlanIteratorState* state;
  store::Item_t lName;
  zstring temp_str;
  xqtref_t type;

  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);

  consumeNext(lName, theChildren[0].getp(), aPlanState);

  type = theSctx->lookup_document(lName->getStringValue());

  if (type.getp() == NULL)
  {
    temp_str = "document-node()?"; // as per http://www.w3.org/TR/xquery/#dt-known-docs
    STACK_PUSH(GENV_ITEMFACTORY->createString(aResult, temp_str), state);
  }
  else
  {
    aResult = type->get_qname();
    STACK_PUSH(true, state);
  }

  STACK_END(state);
}


/*******************************************************************************

********************************************************************************/
StaticallyKnownCollationsIteratorState::~StaticallyKnownCollationsIteratorState()
{
}

void StaticallyKnownCollationsIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  thePosition = 0;
  theCollations.clear();
}


bool StaticallyKnownCollationsIterator::nextImpl(
    store::Item_t& aResult,
    PlanState& aPlanState) const
{
  zstring temp;

  StaticallyKnownCollationsIteratorState* state;
  DEFAULT_STACK_INIT(StaticallyKnownCollationsIteratorState, state, aPlanState);

  theSctx->get_collations(state->theCollations);
  state->thePosition = 0;

  while (state->thePosition < state->theCollations.size())
  {
    temp = state->theCollations.at(state->thePosition);
    STACK_PUSH(GENV_ITEMFACTORY->createString(aResult, temp), state);
    ++state->thePosition;
  }

  STACK_END(state);
}


/*******************************************************************************

********************************************************************************/
bool DefaultFunctionNamespaceIterator::nextImpl(
    store::Item_t& aResult,
    PlanState& aPlanState) const
{
  zstring temp = static_context::W3C_FN_NS;
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);
  STACK_PUSH(GENV_ITEMFACTORY->createString(aResult, temp), state);
  STACK_END(state);
}


/*******************************************************************************

********************************************************************************/
bool SctxBaseUriIterator::nextImpl(
    store::Item_t& aResult,
    PlanState& aPlanState) const
{
  zstring temp = theSctx->get_base_uri();
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);

  if (!temp.empty())
    STACK_PUSH(GENV_ITEMFACTORY->createString(aResult, temp), state);

  STACK_END(state);
}


/*******************************************************************************

********************************************************************************/
bool SctxDefaultCollationIterator::nextImpl(
    store::Item_t& aResult,
    PlanState& aPlanState) const
{
  zstring temp = theSctx->get_default_collation(loc);
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);
  STACK_PUSH(GENV_ITEMFACTORY->createString(aResult, temp), state);
  STACK_END(state);
}


/*******************************************************************************

********************************************************************************/
bool ConstructionModeIterator::nextImpl(
    store::Item_t& aResult,
    PlanState& aPlanState) const
{
  zstring temp;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);

  if (theSctx->construction_mode() == StaticContextConsts::cons_preserve)
    temp = "preserve";
  else
    temp = "strip";

  STACK_PUSH(GENV_ITEMFACTORY->createString(aResult, temp), state);
  STACK_END(state);
}


/*******************************************************************************

********************************************************************************/
bool OrderingModeIterator::nextImpl(
    store::Item_t& aResult,
    PlanState& aPlanState) const
{
  PlanIteratorState* state;
  zstring temp;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);

  if (theSctx->ordering_mode() == StaticContextConsts::ordered)
    temp = "ordered";
  else
    temp = "unordered";

  STACK_PUSH(GENV_ITEMFACTORY->createString(aResult, temp), state);
  STACK_END(state);
}


/*******************************************************************************

********************************************************************************/
bool DefaultOrderIterator::nextImpl(
    store::Item_t& aResult,
    PlanState& aPlanState) const
{
  PlanIteratorState* state;
  zstring temp;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);

  if (theSctx->empty_order_mode() == StaticContextConsts::empty_greatest)
    temp = "greatest";
  else
    temp = "least";

  STACK_PUSH(GENV_ITEMFACTORY->createString(aResult, temp), state);
  STACK_END(state);
}


/*******************************************************************************

********************************************************************************/
bool BoundarySpacePolicyIterator::nextImpl(
    store::Item_t& aResult,
    PlanState& aPlanState) const
{
  zstring temp;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);

  if (theSctx->boundary_space_mode() == StaticContextConsts::preserve_space)
    temp = "preserve";
  else
    temp = "strip";

  STACK_PUSH(GENV_ITEMFACTORY->createString(aResult, temp), state);
  STACK_END(state);
}


/*******************************************************************************

********************************************************************************/
bool CopyNamespacesModeIterator::nextImpl(
    store::Item_t& aResult,
    PlanState& aPlanState) const
{
  PlanIteratorState* state;
  zstring inherit, preserve;

  if (theSctx->inherit_mode() == StaticContextConsts::inherit_ns)
    inherit = "inherit";
  else
    inherit = "no-inherit";

  if (theSctx->preserve_mode() == StaticContextConsts::preserve_ns)
    preserve = "preserve";
  else
    preserve = "no-preserve";

  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);
  STACK_PUSH(GENV_ITEMFACTORY->createString(aResult, inherit), state);
  STACK_PUSH(GENV_ITEMFACTORY->createString(aResult, preserve), state);
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
  thePosition = 0;
  theFunctions.clear();
}


bool FunctionNamesIterator::nextImpl(
    store::Item_t& aResult,
    PlanState& aPlanState) const
{
  FunctionNamesIteratorState* state;
  bool already_returned;

  DEFAULT_STACK_INIT(FunctionNamesIteratorState, state, aPlanState);

  theSctx->get_functions(state->theFunctions);
  state->thePosition = 0;
  while (state->thePosition < state->theFunctions.size())
  {
    aResult = state->theFunctions[state->thePosition]->getName();
    already_returned = false;

    for (unsigned int i = 0; i < state->thePosition; ++i)
    {
      if (state->theFunctions[i]->getName()->equals(state->theFunctions[state->thePosition]->getName())
          &&
          state->theFunctions[i]->getXQueryVersion() <= theSctx->xquery_version())
      {
        // skip functions with the same name but different arities, which were previously returned
        already_returned = true;
        break;
      }
    }

    if (!already_returned
         &&
         state->theFunctions[state->thePosition]->getXQueryVersion() <= theSctx->xquery_version())
    {
      STACK_PUSH(true, state);
    }

    ++state->thePosition;
  }

  STACK_END(state);
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
    if (funcs[i]->getXQueryVersion() <= theSctx->xquery_version())
      lState->arities.push_back(funcs[i]->getArity());

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
  arities.clear();
}


/*******************************************************************************

********************************************************************************/
InScopeSchemaTypesIteratorState::~InScopeSchemaTypesIteratorState()
{
}

void InScopeSchemaTypesIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  ns_pos = 0;
  elem_pos = 0;
}


bool InScopeSchemaTypesIterator::nextImpl(
    store::Item_t& aResult,
    PlanState& aPlanState) const
{
#ifndef ZORBA_NO_XMLSCHEMA
  XERCES_CPP_NAMESPACE_USE;
  zstring qname_ns;
  bool modelHasChanged;
  Schema* schema;
  XMLGrammarPool* grammarPool;
  XSModel* xsModel = NULL;
  StringList* namespaces = NULL;
  const XMLCh* nameSpace;
  XSNamedMap<XSObject>* xsElements;
  XSElementDeclaration* xsElement;
  const XMLCh* elemNameSpace;

  schema = theSctx->get_typemanager()->getSchema();
  if (schema != NULL)
  {
    grammarPool = schema->getGrammarPool();
    xsModel = grammarPool->getXSModel(modelHasChanged);
    namespaces = xsModel->getNamespaces();
  }

  InScopeSchemaTypesIteratorState* state;
  DEFAULT_STACK_INIT(InScopeSchemaTypesIteratorState, state, aPlanState);

  state->ns_pos = 0;
  state->elem_pos = 0;
  while (schema != NULL && state->ns_pos < namespaces->size())
  {
    nameSpace = namespaces->elementAt(state->ns_pos);
    if (nameSpace == NULL || XMLString::stringLen(nameSpace) <= 0)
    {
      state->ns_pos++;
      state->elem_pos = 0;
      continue;
    }

    xsElements = xsModel->getComponentsByNamespace(XSConstants::TYPE_DEFINITION,
                                                   nameSpace);

    if (xsElements == NULL ||
        xsElements->getLength() <= 0 ||
        state->elem_pos >= xsElements->getLength())
    {
      state->ns_pos++;
      state->elem_pos = 0;
      continue;
    }

    xsElement = (XSElementDeclaration*)xsElements->item(state->elem_pos);
    elemNameSpace = xsElement->getNamespace();
    if (elemNameSpace && (XMLString::stringLen(elemNameSpace ) > 0))
      qname_ns = StrX(elemNameSpace).localForm();

    state->elem_pos++;

    STACK_PUSH(GENV_ITEMFACTORY->createQName(aResult,
                                             qname_ns.c_str(),
                                             "",
                                             StrX(xsElement->getName()).localForm()),
                                             state);
  }

  STACK_END (state);

#else // #ifndef ZORBA_NO_XMLSCHEMA

  // In case Zorba is compiled without schema, the function will return an empty sequence
  // TODO: the function should return the predefined xs: types even without schema
  InScopeSchemaTypesIteratorState* state;
  DEFAULT_STACK_INIT(InScopeSchemaTypesIteratorState, state, aPlanState);
  STACK_END (state);

#endif // #ifndef ZORBA_NO_XMLSCHEMA
}


/*******************************************************************************

********************************************************************************/
InScopeElementDeclarationsIteratorState::~InScopeElementDeclarationsIteratorState()
{
}

void InScopeElementDeclarationsIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  ns_pos = 0;
  elem_pos = 0;
}


bool InScopeElementDeclarationsIterator::nextImpl(
    store::Item_t& aResult,
    PlanState& aPlanState) const
{
#ifndef ZORBA_NO_XMLSCHEMA
  XERCES_CPP_NAMESPACE_USE;
  zstring qname_ns;
  bool modelHasChanged;
  Schema* schema;
  XMLGrammarPool* grammarPool;
  XSModel* xsModel = NULL;
  StringList* namespaces = NULL;
  const XMLCh* nameSpace;
  XSNamedMap<XSObject>* xsElements;
  XSElementDeclaration* xsElement;
  const XMLCh* elemNameSpace;

  schema = theSctx->get_typemanager()->getSchema();
  if (schema != NULL)
  {
    grammarPool = schema->getGrammarPool();
    xsModel = grammarPool->getXSModel(modelHasChanged);
    namespaces = xsModel->getNamespaces();
  }

  InScopeElementDeclarationsIteratorState* state;
  DEFAULT_STACK_INIT(InScopeElementDeclarationsIteratorState, state, aPlanState);

  state->ns_pos = 0;
  state->elem_pos = 0;
  while (schema != NULL && state->ns_pos < namespaces->size())
  {
    nameSpace = namespaces->elementAt(state->ns_pos);
    if (nameSpace == NULL || XMLString::stringLen(nameSpace) <= 0)
    {
      state->ns_pos++;
      state->elem_pos = 0;
      continue;
    }

    xsElements = xsModel->getComponentsByNamespace(XSConstants::ELEMENT_DECLARATION, nameSpace);
    if (xsElements == NULL || xsElements->getLength() <= 0 || state->elem_pos >= xsElements->getLength())
    {
      state->ns_pos++;
      state->elem_pos = 0;
      continue;
    }

    xsElement = (XSElementDeclaration*)xsElements->item(state->elem_pos);
    elemNameSpace = xsElement->getNamespace();
    if (elemNameSpace && (XMLString::stringLen(elemNameSpace )>0))
      qname_ns = StrX(elemNameSpace).localForm();

    state->elem_pos++;
    STACK_PUSH(GENV_ITEMFACTORY->createQName(aResult,
                                             qname_ns.c_str(),
                                             "",
                                             StrX(xsElement->getName()).localForm()),
                                             state);
  }

  STACK_END (state);

#else // #ifndef ZORBA_NO_XMLSCHEMA

  // In case Zorba is compiled without schema, the function will return an empty sequence
  InScopeElementDeclarationsIteratorState* state;
  DEFAULT_STACK_INIT(InScopeElementDeclarationsIteratorState, state, aPlanState);
  STACK_END (state);

#endif // #ifndef ZORBA_NO_XMLSCHEMA
}


/*******************************************************************************

********************************************************************************/
InScopeAttributeDeclarationsIteratorState::~InScopeAttributeDeclarationsIteratorState()
{
}

void InScopeAttributeDeclarationsIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  ns_pos = 0;
  elem_pos = 0;
}


bool InScopeAttributeDeclarationsIterator::nextImpl(
    store::Item_t& aResult,
    PlanState& aPlanState) const
{
  InScopeAttributeDeclarationsIteratorState* state;

#ifndef ZORBA_NO_XMLSCHEMA
  XERCES_CPP_NAMESPACE_USE;
  zstring qname_ns;
  bool modelHasChanged;
  Schema* schema;
  XMLGrammarPool* grammarPool;
  XSModel* xsModel = NULL;
  StringList* namespaces = NULL;
  const XMLCh* nameSpace;
  XSNamedMap<XSObject>* xsElements;
  XSElementDeclaration* xsElement;
  const XMLCh* elemNameSpace;

  schema = theSctx->get_typemanager()->getSchema();
  if (schema != NULL)
  {
    grammarPool = schema->getGrammarPool();
    xsModel = grammarPool->getXSModel(modelHasChanged);
    namespaces = xsModel->getNamespaces();
  }

  DEFAULT_STACK_INIT(InScopeAttributeDeclarationsIteratorState, state, aPlanState);
  state->ns_pos = 0;
  state->elem_pos = 0;

  while (schema != NULL && state->ns_pos < namespaces->size())
  {
    nameSpace = namespaces->elementAt(state->ns_pos);
    if (nameSpace == NULL || XMLString::stringLen(nameSpace) <= 0)
    {
      state->ns_pos++;
      state->elem_pos = 0;
      continue;
    }

    xsElements = xsModel->getComponentsByNamespace(XSConstants::ATTRIBUTE_DECLARATION, nameSpace);
    if (xsElements == NULL || xsElements->getLength() <= 0 || state->elem_pos >= xsElements->getLength())
    {
      state->ns_pos++;
      state->elem_pos = 0;
      continue;
    }

    xsElement = (XSElementDeclaration*)xsElements->item(state->elem_pos);
    elemNameSpace = xsElement->getNamespace();
    if (elemNameSpace && (XMLString::stringLen(elemNameSpace )>0))
      qname_ns = StrX(elemNameSpace).localForm();

    state->elem_pos++;
    STACK_PUSH(GENV_ITEMFACTORY->createQName(aResult, qname_ns.c_str(), "", StrX(xsElement->getName()).localForm()), state);
  }
  STACK_END (state);

#else // #ifndef ZORBA_NO_XMLSCHEMA

  // In case Zorba is compiled without schema, the function will return an empty sequence
  DEFAULT_STACK_INIT(InScopeAttributeDeclarationsIteratorState, state, aPlanState);
  STACK_END (state);

#endif // #ifndef ZORBA_NO_XMLSCHEMA
}

/*******************************************************************************

********************************************************************************/
InScopeElementGroupsIteratorState::~InScopeElementGroupsIteratorState()
{
}

void InScopeElementGroupsIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  ns_pos = 0;
  elem_pos = 0;
}


bool InScopeElementGroupsIterator::nextImpl(
    store::Item_t& aResult,
    PlanState& aPlanState) const
{
  InScopeElementGroupsIteratorState* state;

#ifndef ZORBA_NO_XMLSCHEMA
  XERCES_CPP_NAMESPACE_USE;
  zstring qname_ns;
  bool modelHasChanged;
  Schema* schema;
  XMLGrammarPool* grammarPool;
  XSModel* xsModel = NULL;
  StringList* namespaces = NULL;
  const XMLCh* nameSpace;
  XSNamedMap<XSObject>* xsElements;
  XSElementDeclaration* xsElement;
  const XMLCh* elemNameSpace;

  schema = theSctx->get_typemanager()->getSchema();
  if (schema != NULL)
  {
    grammarPool = schema->getGrammarPool();
    xsModel = grammarPool->getXSModel(modelHasChanged);
    namespaces = xsModel->getNamespaces();
  }

  DEFAULT_STACK_INIT(InScopeElementGroupsIteratorState, state, aPlanState);

  state->ns_pos = 0;
  state->elem_pos = 0;
  while (schema != NULL && state->ns_pos < namespaces->size())
  {
    nameSpace = namespaces->elementAt(state->ns_pos);
    if (nameSpace == NULL || XMLString::stringLen(nameSpace) <= 0)
    {
      state->ns_pos++;
      state->elem_pos = 0;
      continue;
    }

    xsElements = xsModel->getComponentsByNamespace(XSConstants::MODEL_GROUP_DEFINITION, nameSpace);
    if (xsElements == NULL || xsElements->getLength() <= 0 || state->elem_pos >= xsElements->getLength())
    {
      state->ns_pos++;
      state->elem_pos = 0;
      continue;
    }

    xsElement = (XSElementDeclaration*)xsElements->item(state->elem_pos);
    elemNameSpace = xsElement->getNamespace();
    if (elemNameSpace && (XMLString::stringLen(elemNameSpace )>0))
      qname_ns = StrX(elemNameSpace).localForm();

    state->elem_pos++;
    STACK_PUSH(GENV_ITEMFACTORY->createQName(aResult, qname_ns.c_str(), "", StrX(xsElement->getName()).localForm()), state);
  }
  STACK_END (state);

#else // #ifndef ZORBA_NO_XMLSCHEMA

  // In case Zorba is compiled without schema, the function will return an empty sequence
  DEFAULT_STACK_INIT(InScopeElementGroupsIteratorState, state, aPlanState);
  STACK_END (state);

#endif // #ifndef ZORBA_NO_XMLSCHEMA
}

/*******************************************************************************

********************************************************************************/
InScopeAttributeGroupsIteratorState::~InScopeAttributeGroupsIteratorState()
{
}

void InScopeAttributeGroupsIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  ns_pos = 0;
  elem_pos = 0;
}


bool InScopeAttributeGroupsIterator::nextImpl(
                                            store::Item_t& aResult,
                                            PlanState& aPlanState) const
{
  InScopeAttributeGroupsIteratorState* state;

#ifndef ZORBA_NO_XMLSCHEMA
  XERCES_CPP_NAMESPACE_USE;
  zstring qname_ns;
  bool modelHasChanged;
  Schema* schema;
  XMLGrammarPool* grammarPool;
  XSModel* xsModel = NULL;
  StringList* namespaces = NULL;
  const XMLCh* nameSpace;
  XSNamedMap<XSObject>* xsElements;
  XSElementDeclaration* xsElement;
  const XMLCh* elemNameSpace;

  schema = theSctx->get_typemanager()->getSchema();
  if (schema != NULL)
  {
    grammarPool = schema->getGrammarPool();
    xsModel = grammarPool->getXSModel(modelHasChanged);
    namespaces = xsModel->getNamespaces();
  }

  DEFAULT_STACK_INIT(InScopeAttributeGroupsIteratorState, state, aPlanState);

  state->ns_pos = 0;
  state->elem_pos = 0;
  while (schema != NULL && state->ns_pos < namespaces->size())
  {
    nameSpace = namespaces->elementAt(state->ns_pos);
    if (nameSpace == NULL || XMLString::stringLen(nameSpace) <= 0)
    {
      state->ns_pos++;
      state->elem_pos = 0;
      continue;
    }

    xsElements = xsModel->getComponentsByNamespace(XSConstants::ATTRIBUTE_GROUP_DEFINITION, nameSpace);
    if (xsElements == NULL || xsElements->getLength() <= 0 || state->elem_pos >= xsElements->getLength())
    {
      state->ns_pos++;
      state->elem_pos = 0;
      continue;
    }

    xsElement = (XSElementDeclaration*)xsElements->item(state->elem_pos);
    elemNameSpace = xsElement->getNamespace();
    if (elemNameSpace && (XMLString::stringLen(elemNameSpace )>0))
      qname_ns = StrX(elemNameSpace).localForm();

    state->elem_pos++;
    STACK_PUSH(GENV_ITEMFACTORY->createQName(aResult, qname_ns.c_str(), "", StrX(xsElement->getName()).localForm()), state);
  }
  STACK_END (state);

#else // #ifndef ZORBA_NO_XMLSCHEMA

  // In case Zorba is compiled without schema, the function will return an empty sequence
  DEFAULT_STACK_INIT(InScopeAttributeGroupsIteratorState, state, aPlanState);
  STACK_END (state);

#endif // #ifndef ZORBA_NO_XMLSCHEMA
}

/*******************************************************************************
********************************************************************************/
bool
OptionIterator::nextImpl(store::Item_t& aResult, PlanState& aPlanState)
  const
{
  PlanIteratorState *lState;
  store::Item_t      lName;
  zstring            lValue;

  DEFAULT_STACK_INIT(PlanIteratorState, lState, aPlanState);

  consumeNext(lName, theChildren[0].getp(), aPlanState);
  if (theSctx->lookup_option(lName.getp(), lValue))
  {
    GENV_ITEMFACTORY->createString(aResult, lValue);
    STACK_PUSH( true, lState );
  }
  else
  {
    STACK_PUSH( false, lState );
  }
  STACK_END (lState);
}

/*******************************************************************************
********************************************************************************/
FunctionAnnotationsIteratorState::~FunctionAnnotationsIteratorState()
{
}

void FunctionAnnotationsIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  theFunction = NULL;
  thePosition = 0;
}

bool
FunctionAnnotationsIterator::nextImpl(store::Item_t& aResult, PlanState& aPlanState) const
{
  FunctionAnnotationsIteratorState *lState;
  store::Item_t      lName;
  store::Item_t      lArity;
  store::Item_t      temp;
  xs_int             arity;

  DEFAULT_STACK_INIT(FunctionAnnotationsIteratorState, lState, aPlanState);

  consumeNext(lName, theChildren[0].getp(), aPlanState);
  consumeNext(lArity, theChildren[1].getp(), aPlanState);

  try {
    arity = to_xs_int(lArity->getIntegerValue());
  } catch ( std::range_error const& ) {
    throw XQUERY_EXCEPTION(
              err::XPTY0004,
              ERROR_PARAMS( ZED( NoCastToCInt_2 ), lArity->getIntegerValue() ),
              ERROR_LOC( loc )
          );
  }

  lState->theFunction = theSctx->lookup_fn(lName.getp(), arity);
  lState->thePosition = 0;
  if (lState->theFunction != NULL && lState->theFunction->getAnnotationList() == NULL)   // no annotations
    lState->theFunction = NULL;

  while (lState->theFunction != NULL
         &&
         lState->thePosition < lState->theFunction->getAnnotationList()->size())
  {
    aResult = lState->theFunction->getAnnotationList()->getAnnotation(lState->thePosition)->getQName();
    STACK_PUSH(true, lState);
    ++lState->thePosition;
  }

  STACK_END (lState);
}


} /* namespace zorba */
/* vim:set et sw=2 ts=2: */
