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

#include <zorba/internal/cxx_util.h>

#include "context/dynamic_context.h"
#include "context/static_context.h"
#include "context/static_context_consts.h"
#include "context/static_context_consts.h"
#include "diagnostics/assert.h"
#include "diagnostics/xquery_diagnostics.h"
#include "functions/function.h"
#include "runtime/sctx/sctx.h"
#include "store/api/collection.h"
#include "store/api/item_factory.h"
#include "store/api/iterator.h"
#include "store/api/store.h"
#include "system/globalenv.h"
#ifndef ZORBA_NO_XMLSCHEMA
#include "types/schema/PrintSchema.h"
#include "types/schema/schema.h"
#include "types/schema/StrX.h"
#include "types/schema/xercesIncludes.h"
#endif /* ZORBA_NO_XMLSCHEMA */
#include "zorbatypes/integer.h"
#include "zorbatypes/numconversions.h"

using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

bool SctxBaseUriIterator::nextImpl( store::Item_t &result,
                                    PlanState &plan_state ) const {
  zstring uri( theSctx->get_base_uri() );

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );

  if ( !uri.empty() )
    STACK_PUSH( GENV_ITEMFACTORY->createString( result, uri ), state );

  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

bool SctxBoundarySpacePolicyIterator::nextImpl( store::Item_t &result,
                                                PlanState &plan_state ) const {
  zstring policy(
    theSctx->boundary_space_mode() == StaticContextConsts::preserve_space ?
    "preserve" : "strip"
  );

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );
  GENV_ITEMFACTORY->createString( result, policy );
  STACK_PUSH( true, state );
  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

bool SctxConstructionModeIterator::nextImpl( store::Item_t &result,
                                             PlanState &plan_state ) const {
  zstring mode(
    theSctx->construction_mode() == StaticContextConsts::cons_preserve ?
    "preserve" : "strip"
  );

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );
  GENV_ITEMFACTORY->createString( result, mode );
  STACK_PUSH( true, state );
  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

bool SctxCopyNamespacesModeIterator::nextImpl( store::Item_t &result,
                                               PlanState &plan_state ) const {
  zstring inherit( theSctx->inherit_ns() ? "inherit" : "no-inherit" );
  zstring preserve( theSctx->preserve_ns() ? "preserve" : "no-preserve" );

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );
  STACK_PUSH( GENV_ITEMFACTORY->createString( result, inherit ), state );
  STACK_PUSH( GENV_ITEMFACTORY->createString( result, preserve ), state );
  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

bool SctxDefaultCollationIterator::nextImpl( store::Item_t& result,
                                             PlanState &plan_state ) const {
  zstring collation( theSctx->get_default_collation( loc ) );

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );
  GENV_ITEMFACTORY->createString( result, collation );
  STACK_PUSH( true, state );
  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

bool SctxDefaultCollectionTypeIterator::
nextImpl( store::Item_t& result, PlanState &plan_state ) const {
  zstring type( theSctx->get_default_w3c_collection_type()->toSchemaString() );

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );
  GENV_ITEMFACTORY->createString( result, type );
  STACK_PUSH( true, state );
  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

bool SctxDefaultFunctionNamespaceIterator::
nextImpl( store::Item_t& result, PlanState &plan_state ) const {
  zstring ns( static_context::W3C_FN_NS );

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );
  GENV_ITEMFACTORY->createString( result, ns );
  STACK_PUSH( true, state );
  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

bool SctxDefaultOrderIterator::nextImpl( store::Item_t &result,
                                         PlanState &plan_state ) const {
  zstring order(
    theSctx->empty_order_mode() == StaticContextConsts::empty_greatest ?
    "greatest" : "least"
  );

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );
  GENV_ITEMFACTORY->createString( result, order );
  STACK_PUSH( true, state );
  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

void SctxFunctionAnnotationsIteratorState::reset( PlanState &plan_state ) {
  PlanIteratorState::reset(plan_state);
  theFunction = nullptr;
  thePosition = 0;
}

bool SctxFunctionAnnotationsIterator::nextImpl( store::Item_t& result,
                                                PlanState &plan_state ) const {
  store::Item_t      lName;
  store::Item_t      lArity;
  store::Item_t      temp;
  xs_int             arity;

  SctxFunctionAnnotationsIteratorState *state;
  DEFAULT_STACK_INIT( SctxFunctionAnnotationsIteratorState, state, plan_state );

  consumeNext(lName, theChildren[0].getp(), plan_state);
  consumeNext(lArity, theChildren[1].getp(), plan_state);

  try {
    arity = to_xs_int( lArity->getIntegerValue() );
  }
  catch ( std::range_error const& ) {
    throw XQUERY_EXCEPTION(
      err::XPTY0004,
      ERROR_PARAMS( ZED( NoCastToCInt_2 ), lArity->getIntegerValue() ),
      ERROR_LOC( loc )
    );
  }

  state->theFunction = theSctx->lookup_fn( lName.getp(), arity );
  state->thePosition = 0;
  if ( state->theFunction && !state->theFunction->getAnnotationList() )
    state->theFunction = nullptr;

  while (state->theFunction
         &&
         state->thePosition < state->theFunction->getAnnotationList()->size())
  {
    result = state->theFunction->getAnnotationList()->get(state->thePosition)->getQName();
    STACK_PUSH(true, state);
    ++state->thePosition;
  }

  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

void SctxFunctionArgumentsCountIteratorState::reset( PlanState &plan_state ) {
  PlanIteratorState::reset( plan_state );
  arities_.clear();
}

bool SctxFunctionArgumentsCountIterator::
nextImpl( store::Item_t &result, PlanState &plan_state ) const {
  store::Item_t lName;
  std::vector<function*> funcs;

  SctxFunctionArgumentsCountIteratorState *state;
  DEFAULT_STACK_INIT( SctxFunctionArgumentsCountIteratorState, state, plan_state );

  consumeNext( lName, theChildren[0].getp(), plan_state );

  theSctx->find_functions( lName, funcs );

  FOR_EACH( std::vector<function*>, f, funcs )
    if ( (*f)->getXQueryVersion() <= theSctx->xquery_version() )
      state->arities_.push_back( (*f)->getArity() );

  for ( state->it_ = state->arities_.begin();
        state->it_ != state->arities_.end(); ++state->it_ ) {
    GENV_ITEMFACTORY->createInt( result, *state->it_ );
    STACK_PUSH( true, state );
  }

  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

void SctxFunctionNamesIteratorState::reset( PlanState &plan_state )
{
  PlanIteratorState::reset( plan_state );
  theFunctions.clear();
  thePosition = 0;
}


bool SctxFunctionNamesIterator::nextImpl( store::Item_t &result,
                                          PlanState &plan_state) const {
  bool already_returned;

  SctxFunctionNamesIteratorState *state;
  DEFAULT_STACK_INIT( SctxFunctionNamesIteratorState, state, plan_state );

  theSctx->get_functions( state->theFunctions );

  state->thePosition = 0;

  while ( state->thePosition < state->theFunctions.size() )
  {
    result = state->theFunctions[state->thePosition]->getName();
    already_returned = false;

    for ( unsigned i = 0; i < state->thePosition; ++i ) {
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

  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

void SctxFunctionsIteratorState::reset( PlanState &plan_state )
{
  PlanIteratorState::reset( plan_state );
  funcs_.clear();
}


bool SctxFunctionsIterator::nextImpl(
    store::Item_t &result,
    PlanState &plan_state) const
{
  AnnotationList const *annotations;
  function const *func;
  store::Item_t item;
  vector<store::Item_t> keys, values;
  zstring s;

  SctxFunctionsIteratorState *state;
  DEFAULT_STACK_INIT( SctxFunctionsIteratorState, state, plan_state );

  theSctx->get_functions( state->funcs_ );

  for ( state->it_ = state->funcs_.begin(); state->it_ != state->funcs_.end();
        ++state->it_ )
  {
    func = *state->it_;
    if ( func->getXQueryVersion() > theSctx->xquery_version() )
      continue;

    s = "name";
    GENV_ITEMFACTORY->createString( item, s );
    keys.push_back( item );
    values.push_back( func->getName() );

    s = "arity";
    GENV_ITEMFACTORY->createString( item, s );
    keys.push_back( item );
    GENV_ITEMFACTORY->createInt( item, func->getArity() );
    values.push_back( item );

    if ( (annotations = func->getAnnotationList()) )
    {
      s = "annotations";
      GENV_ITEMFACTORY->createString( item, s );
      keys.push_back( item );

      vector<store::Item_t> elements;
      AnnotationList::size_type const size = annotations->size();
      for ( AnnotationList::size_type i = 0; i < size; ++i )
      {
        item = annotations->get( i )->getQName();
        elements.push_back( item );
      }
      GENV_ITEMFACTORY->createJSONArray( item, elements );
      values.push_back( item );
    }

    GENV_ITEMFACTORY->createJSONObject( result, keys, values );
    STACK_PUSH( true, state );
  }

  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

void SctxInScopeAttributeDeclarationsIteratorState::
reset( PlanState &plan_state ) {
  PlanIteratorState::reset( plan_state );
  ns_pos = 0;
  elem_pos = 0;
}

bool SctxInScopeAttributeDeclarationsIterator::
nextImpl( store::Item_t &result, PlanState &plan_state ) const {
  SctxInScopeAttributeDeclarationsIteratorState *state;

#ifndef ZORBA_NO_XMLSCHEMA
  XERCES_CPP_NAMESPACE_USE;
  zstring qname_ns;
  bool modelHasChanged;
  Schema* schema;
  XMLGrammarPool* grammarPool;
  XSModel* xsModel = nullptr;
  StringList* namespaces = nullptr;
  const XMLCh* nameSpace;
  XSNamedMap<XSObject>* xsElements;
  XSElementDeclaration* xsElement;
  const XMLCh* elemNameSpace;

  schema = theSctx->get_typemanager()->getSchema();
  if ( schema )
  {
    grammarPool = schema->getGrammarPool();
    xsModel = grammarPool->getXSModel(modelHasChanged);
    namespaces = xsModel->getNamespaces();
  }

  DEFAULT_STACK_INIT(SctxInScopeAttributeDeclarationsIteratorState, state, plan_state);
  state->ns_pos = 0;
  state->elem_pos = 0;

  while (schema && state->ns_pos < namespaces->size())
  {
    nameSpace = namespaces->elementAt(state->ns_pos);
    if (!nameSpace || XMLString::stringLen(nameSpace) <= 0)
    {
      state->ns_pos++;
      state->elem_pos = 0;
      continue;
    }

    xsElements = xsModel->getComponentsByNamespace(XSConstants::ATTRIBUTE_DECLARATION, nameSpace);
    if (!xsElements || xsElements->getLength() <= 0 || state->elem_pos >= xsElements->getLength())
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
    STACK_PUSH(GENV_ITEMFACTORY->createQName(result, qname_ns.c_str(), "", StrX(xsElement->getName()).localForm()), state);
  }

#else /* ZORBA_NO_XMLSCHEMA */

  // In case Zorba is compiled without schema, the function will return an empty sequence
  DEFAULT_STACK_INIT(SctxInScopeAttributeDeclarationsIteratorState, state, plan_state);

#endif /* ZORBA_NO_XMLSCHEMA */
  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

void SctxInScopeAttributeGroupsIteratorState::reset( PlanState &plan_state ) {
  PlanIteratorState::reset( plan_state );
  ns_pos = 0;
  elem_pos = 0;
}

bool SctxInScopeAttributeGroupsIterator::
nextImpl( store::Item_t &result, PlanState &plan_state) const {
  SctxInScopeAttributeGroupsIteratorState *state;

#ifndef ZORBA_NO_XMLSCHEMA
  XERCES_CPP_NAMESPACE_USE;
  zstring qname_ns;
  bool modelHasChanged;
  Schema* schema;
  XMLGrammarPool* grammarPool;
  XSModel* xsModel = nullptr;
  StringList* namespaces = nullptr;
  const XMLCh* nameSpace;
  XSNamedMap<XSObject>* xsElements;
  XSElementDeclaration* xsElement;
  const XMLCh* elemNameSpace;

  schema = theSctx->get_typemanager()->getSchema();
  if ( schema )
  {
    grammarPool = schema->getGrammarPool();
    xsModel = grammarPool->getXSModel(modelHasChanged);
    namespaces = xsModel->getNamespaces();
  }

  DEFAULT_STACK_INIT(SctxInScopeAttributeGroupsIteratorState, state, plan_state);

  state->ns_pos = 0;
  state->elem_pos = 0;
  while (schema && state->ns_pos < namespaces->size())
  {
    nameSpace = namespaces->elementAt(state->ns_pos);
    if (!nameSpace || XMLString::stringLen(nameSpace) <= 0)
    {
      state->ns_pos++;
      state->elem_pos = 0;
      continue;
    }

    xsElements = xsModel->getComponentsByNamespace(XSConstants::ATTRIBUTE_GROUP_DEFINITION, nameSpace);
    if (!xsElements || xsElements->getLength() <= 0 || state->elem_pos >= xsElements->getLength())
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
    STACK_PUSH(GENV_ITEMFACTORY->createQName(result, qname_ns.c_str(), "", StrX(xsElement->getName()).localForm()), state);
  }

#else /* ZORBA_NO_XMLSCHEMA */

  // In case Zorba is compiled without schema, the function will return an empty sequence
  DEFAULT_STACK_INIT( SctxInScopeAttributeGroupsIteratorState, state, plan_state );

#endif /* ZORBA_NO_XMLSCHEMA */
  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

void SctxInScopeElementDeclarationsIteratorState::
reset( PlanState &plan_state ) {
  PlanIteratorState::reset( plan_state );
  ns_pos = 0;
  elem_pos = 0;
}

bool SctxInScopeElementDeclarationsIterator::
nextImpl( store::Item_t &result, PlanState &plan_state ) const {
#ifndef ZORBA_NO_XMLSCHEMA
  XERCES_CPP_NAMESPACE_USE;
  zstring qname_ns;
  bool modelHasChanged;
  Schema* schema;
  XMLGrammarPool* grammarPool;
  XSModel* xsModel = nullptr;
  StringList* namespaces = nullptr;
  const XMLCh* nameSpace;
  XSNamedMap<XSObject>* xsElements;
  XSElementDeclaration* xsElement;
  const XMLCh* elemNameSpace;

  schema = theSctx->get_typemanager()->getSchema();
  if ( schema ) {
    grammarPool = schema->getGrammarPool();
    xsModel = grammarPool->getXSModel(modelHasChanged);
    namespaces = xsModel->getNamespaces();
  }

  SctxInScopeElementDeclarationsIteratorState *state;
  DEFAULT_STACK_INIT(SctxInScopeElementDeclarationsIteratorState, state, plan_state);

  state->ns_pos = 0;
  state->elem_pos = 0;
  while (schema && state->ns_pos < namespaces->size())
  {
    nameSpace = namespaces->elementAt(state->ns_pos);
    if (!nameSpace || XMLString::stringLen(nameSpace) <= 0)
    {
      state->ns_pos++;
      state->elem_pos = 0;
      continue;
    }

    xsElements = xsModel->getComponentsByNamespace(XSConstants::ELEMENT_DECLARATION, nameSpace);
    if (!xsElements || xsElements->getLength() <= 0 || state->elem_pos >= xsElements->getLength())
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
    STACK_PUSH(GENV_ITEMFACTORY->createQName(result,
                                             qname_ns.c_str(),
                                             "",
                                             StrX(xsElement->getName()).localForm()),
                                             state);
  }

#else /* ZORBA_NO_XMLSCHEMA */

  // In case Zorba is compiled without schema, the function will return an empty sequence
  SctxInScopeElementDeclarationsIteratorState* state;
  DEFAULT_STACK_INIT(SctxInScopeElementDeclarationsIteratorState, state, plan_state);

#endif /* ZORBA_NO_XMLSCHEMA */
  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

void SctxInScopeElementGroupsIteratorState::reset( PlanState &plan_state ) {
  PlanIteratorState::reset(plan_state);
  ns_pos = 0;
  elem_pos = 0;
}

bool SctxInScopeElementGroupsIterator::nextImpl(
    store::Item_t& result,
    PlanState &plan_state) const
{
  SctxInScopeElementGroupsIteratorState* state;

#ifndef ZORBA_NO_XMLSCHEMA
  XERCES_CPP_NAMESPACE_USE;
  zstring qname_ns;
  bool modelHasChanged;
  Schema* schema;
  XMLGrammarPool* grammarPool;
  XSModel* xsModel = nullptr;
  StringList* namespaces = nullptr;
  const XMLCh* nameSpace;
  XSNamedMap<XSObject>* xsElements;
  XSElementDeclaration* xsElement;
  const XMLCh* elemNameSpace;

  schema = theSctx->get_typemanager()->getSchema();
  if ( schema )
  {
    grammarPool = schema->getGrammarPool();
    xsModel = grammarPool->getXSModel(modelHasChanged);
    namespaces = xsModel->getNamespaces();
  }

  DEFAULT_STACK_INIT(SctxInScopeElementGroupsIteratorState, state, plan_state);

  state->ns_pos = 0;
  state->elem_pos = 0;
  while (schema && state->ns_pos < namespaces->size())
  {
    nameSpace = namespaces->elementAt(state->ns_pos);
    if (!nameSpace || XMLString::stringLen(nameSpace) <= 0)
    {
      state->ns_pos++;
      state->elem_pos = 0;
      continue;
    }

    xsElements = xsModel->getComponentsByNamespace(XSConstants::MODEL_GROUP_DEFINITION, nameSpace);
    if (!xsElements || xsElements->getLength() <= 0 || state->elem_pos >= xsElements->getLength())
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
    STACK_PUSH(GENV_ITEMFACTORY->createQName(result, qname_ns.c_str(), "", StrX(xsElement->getName()).localForm()), state);
  }

#else // #ifndef ZORBA_NO_XMLSCHEMA

  // In case Zorba is compiled without schema, the function will return an empty sequence
  DEFAULT_STACK_INIT(SctxInScopeElementGroupsIteratorState, state, plan_state);

#endif // #ifndef ZORBA_NO_XMLSCHEMA
  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

void SctxInScopeSchemaTypesIteratorState::reset( PlanState &plan_state ) {
  PlanIteratorState::reset(plan_state);
  ns_pos = 0;
  elem_pos = 0;
}

bool SctxInScopeSchemaTypesIterator::nextImpl( store::Item_t &result,
                                               PlanState &plan_state ) const {
#ifndef ZORBA_NO_XMLSCHEMA
  XERCES_CPP_NAMESPACE_USE;
  zstring qname_ns;
  bool modelHasChanged;
  Schema* schema;
  XMLGrammarPool* grammarPool;
  XSModel* xsModel = nullptr;
  StringList* namespaces = nullptr;
  const XMLCh* nameSpace;
  XSNamedMap<XSObject>* xsElements;
  XSElementDeclaration* xsElement;
  const XMLCh* elemNameSpace;

  schema = theSctx->get_typemanager()->getSchema();
  if ( schema )
  {
    grammarPool = schema->getGrammarPool();
    xsModel = grammarPool->getXSModel(modelHasChanged);
    namespaces = xsModel->getNamespaces();
  }

  SctxInScopeSchemaTypesIteratorState* state;
  DEFAULT_STACK_INIT(SctxInScopeSchemaTypesIteratorState, state, plan_state);

  state->ns_pos = 0;
  state->elem_pos = 0;
  while (schema && state->ns_pos < namespaces->size())
  {
    nameSpace = namespaces->elementAt(state->ns_pos);
    if ( !nameSpace || XMLString::stringLen(nameSpace) <= 0)
    {
      state->ns_pos++;
      state->elem_pos = 0;
      continue;
    }

    xsElements = xsModel->getComponentsByNamespace(XSConstants::TYPE_DEFINITION,
                                                   nameSpace);

    if (!xsElements ||
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

    STACK_PUSH(GENV_ITEMFACTORY->createQName(result,
                                             qname_ns.c_str(),
                                             "",
                                             StrX(xsElement->getName()).localForm()),
                                             state);
  }

#else /* ZORBA_NO_XMLSCHEMA */

  // In case Zorba is compiled without schema, the function will return an empty sequence
  // TODO: the function should return the predefined xs: types even without schema
  SctxInScopeSchemaTypesIteratorState* state;
  DEFAULT_STACK_INIT(SctxInScopeSchemaTypesIteratorState, state, plan_state);

#endif /* ZORBA_NO_XMLSCHEMA */
  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

void SctxInscopeVariablesIteratorState::reset( PlanState &plan_state ) {
  PlanIteratorState::reset(plan_state);
  vars_.clear();
}

bool SctxInscopeVariablesIterator::nextImpl( store::Item_t& result,
                                             PlanState &plan_state ) const {
  SctxInscopeVariablesIteratorState *state;
  DEFAULT_STACK_INIT( SctxInscopeVariablesIteratorState, state, plan_state );

  theSctx->getVariables( state->vars_ );

  for ( state->it_ = state->vars_.begin(); state->it_ != state->vars_.end();
        ++state->it_ ) {
    result = (*state->it_)->getName();
    STACK_PUSH( true, state );
  }

  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

bool SctxOptionIterator::nextImpl( store::Item_t &result,
                                   PlanState &plan_state ) const
{
  store::Item_t      lName;
  zstring            lValue;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );

  consumeNext( lName, theChildren[0].getp(), plan_state );
  if ( theSctx->lookup_option( lName.getp(), lValue ) ) {
    GENV_ITEMFACTORY->createString( result, lValue );
    STACK_PUSH( true, state );
  } else {
    STACK_PUSH( false, state );
  }
  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

bool SctxOrderingModeIterator::nextImpl( store::Item_t &result,
                                         PlanState &plan_state ) const {
  zstring mode(
    theSctx->ordering_mode() == StaticContextConsts::ordered ?
    "ordered" : "unordered"
  );

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );
  GENV_ITEMFACTORY->createString( result, mode );
  STACK_PUSH( true, state );
  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

void SctxStaticallyKnownCollationsIteratorState::
reset( PlanState &plan_state ) {
  PlanIteratorState::reset( plan_state );
  coll_.clear();
}

bool SctxStaticallyKnownCollationsIterator::
nextImpl( store::Item_t &result, PlanState &plan_state ) const {
  zstring temp;

  SctxStaticallyKnownCollationsIteratorState *state;
  DEFAULT_STACK_INIT( SctxStaticallyKnownCollationsIteratorState, state, plan_state );

  theSctx->get_collations( state->coll_ );

  for ( state->it_ = state->coll_.begin(); state->it_ != state->coll_.end();
        ++state->it_ ) {
    temp = *state->it_;
    STACK_PUSH( GENV_ITEMFACTORY->createString( result, temp ), state );
  }

  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

void SctxStaticallyKnownDocumentsIteratorState::reset( PlanState &plan_state ) {
  PlanIteratorState::reset(plan_state);
  docs_.clear();
}

bool SctxStaticallyKnownDocumentsIterator::
nextImpl( store::Item_t& result, PlanState &plan_state ) const {
  zstring temp;

  SctxStaticallyKnownDocumentsIteratorState *state;
  DEFAULT_STACK_INIT( SctxStaticallyKnownDocumentsIteratorState, state, plan_state );

  theSctx->get_all_documents( state->docs_ );

  for ( state->it_ = state->docs_.begin(); state->it_ != state->docs_.end();
        ++state->it_ ) {
    temp = *state->it_;
    GENV_ITEMFACTORY->createString( result, temp );
    STACK_PUSH( true, state );
  }

  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

bool SctxStaticallyKnownDocumentTypeIterator::
nextImpl( store::Item_t &result, PlanState &plan_state ) const {
  store::Item_t item;
  zstring type_str;
  xqtref_t type;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );

  consumeNext( item, theChildren[0].getp(), plan_state );
  type = theSctx->lookup_document( item->getStringValue() );
  type_str = type.getp() ? type->toSchemaString() : "document-node()?";

  GENV_ITEMFACTORY->createString( result, type_str );
  STACK_PUSH( true, state );
  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

bool SctxStaticallyKnownNamespaceBindingIterator::
nextImpl( store::Item_t& result, PlanState &plan_state ) const {
  store::Item_t item;
  zstring ns;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );

  consumeNext( item, theChildren[0].getp(), plan_state );

  if ( theSctx->lookup_ns( ns, item->getStringValue(), loc, false ) ) {
    GENV_ITEMFACTORY->createString( result, ns );
    STACK_PUSH( true, state );
  }

  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

void SctxStaticallyKnownNamespacesIteratorState::reset( PlanState &plan_state ) {
  PlanIteratorState::reset( plan_state );
  bindings_.clear();
}

bool SctxStaticallyKnownNamespacesIterator::
nextImpl( store::Item_t& result, PlanState &plan_state ) const {
  zstring prefix;

  SctxStaticallyKnownNamespacesIteratorState *state;
  DEFAULT_STACK_INIT( SctxStaticallyKnownNamespacesIteratorState, state, plan_state );

  theSctx->get_namespace_bindings( state->bindings_ );

  for ( state->it_ = state->bindings_.begin();
        state->it_ != state->bindings_.end(); ++state->it_ ) {
    prefix = (*state->it_).first;
    GENV_ITEMFACTORY->createString( result, prefix );
    STACK_PUSH( true, state );
  }

  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

bool SctxXPath10CompatModeIterator::nextImpl( store::Item_t &result,
                                              PlanState &plan_state ) const {
  PlanIteratorState *state;
  DEFAULT_STACK_INIT( PlanIteratorState, state, plan_state );

  GENV_ITEMFACTORY->createBoolean(
    result,
    theSctx->xpath_compatibility() == StaticContextConsts::xpath1_0_only
  );
  STACK_PUSH( true, state );

  STACK_END( state );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
