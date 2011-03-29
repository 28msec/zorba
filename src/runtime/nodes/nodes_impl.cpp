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

#include "runtime/nodes/nodes.h"
#include "zorbamisc/ns_consts.h"

#include "system/globalenv.h"

#include "store/api/item.h"
#include "store/api/iterator.h"
#include "store/api/item_factory.h"
#include "store/api/store.h"

#include "util/string_util.h"
#include "zorbautils/string_util.h"

using namespace std;

namespace zorba {

bool NodeReferenceIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState *state;
  bool valid;
  store::Item_t inNode;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  valid = consumeNext(inNode, theChildren[0], planState);
  assert(valid);

  STACK_PUSH(GENV_STORE.getReference(result, inNode), state);
  STACK_END(state);
}

bool NodeByReferenceIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t inUri;
  bool valid;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  valid = consumeNext(inUri, theChildren[0], planState);
  assert(valid);

  STACK_PUSH(GENV_STORE.getNodeByReference(result, inUri), state);
  STACK_END (state);
}


// 14.2 fn:local-name
//---------------------
bool FnLocalNameIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t inNode;
  zstring strRes;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(inNode, theChildren[0], planState))
  {
    if(inNode->getNodeKind() == store::StoreConsts::documentNode ||
       inNode->getNodeKind() == store::StoreConsts::commentNode ||
       inNode->getNodeKind() == store::StoreConsts::textNode)
    {
      ;
    }
    else if(inNode->getNodeKind() == store::StoreConsts::piNode)
    {
      strRes = inNode->getTarget();
    }
    else
    {
      strRes = inNode->getNodeName()->getLocalName();
    }

    STACK_PUSH(GENV_ITEMFACTORY->createString(result, strRes), state);
  }
  else
  {
    STACK_PUSH(GENV_ITEMFACTORY->createString(result, strRes), state);
  }

  STACK_END (state);
}


// 14.3 fn:namespace-uri
//---------------------
bool FnNamespaceUriIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t inNode;
  zstring  uriStr;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(inNode, theChildren[0].getp(), planState)) 
  {
    if(inNode->getNodeKind() == store::StoreConsts::elementNode ||
       inNode->getNodeKind() == store::StoreConsts::attributeNode) 
    {
      uriStr = inNode->getNodeName()->getNamespace();
    }

    STACK_PUSH(GENV_ITEMFACTORY->createAnyURI(result, uriStr), state);
  }
  else
  {
    STACK_PUSH(GENV_ITEMFACTORY->createAnyURI(result, uriStr), state);
  }

  STACK_END (state);
}


// 14.5 fn:lang
//---------------------
bool
FnLangIterator::isLangAttr(const store::Item_t& aAttr) const
{
  store::Item* lAttrName = aAttr->getNodeName();

  return (ZSTREQ(lAttrName->getLocalName(), "lang") &&
          ZSTREQ(lAttrName->getNamespace(), XML_NS));
}

bool
FnLangIterator::matchesReqLang(
    const store::Item_t& aAttr,
    const zstring& aRequestLang) const
{
  return utf8::match_whole( 
            aAttr->getStringValue(), aRequestLang.str() + "(?:-.+)?", "i");
}

bool FnLangIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t     item, attr;
  store::Iterator_t lAttributes;
  bool              lLangAttrFound = false, lLangAttrMatched = false;
  zstring reqLang;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if(consumeNext(item, theChildren[0].getp(), planState))
  {
    item->getStringValue2(reqLang);

    if (consumeNext(item, theChildren[1].getp(), planState)) 
    {
      // nearest ancestor
      while (item != NULL)
      {
        if(item->getNodeKind () == store::StoreConsts::elementNode)
        {
          lAttributes = item->getAttributes();
          lAttributes->open();
          while (lAttributes->next(attr))
          {
            if (isLangAttr(attr)) {
              lLangAttrFound = true;
              if (matchesReqLang(attr, reqLang)) {
                lLangAttrMatched = true;
              }
              break; // inner attribute loop
            }
          }
          lAttributes->close();
        }
        else if(item->getNodeKind () == store::StoreConsts::attributeNode)
        {
          if(item->getParent() != NULL)
          {
            if (isLangAttr(item)) {
              lLangAttrFound = true;
              if (matchesReqLang(item, reqLang)) {
                lLangAttrMatched = true;
              }
            }
          }
        }
        if (lLangAttrFound || lLangAttrMatched ) {
          break; // break outer loop
        }
        item = item->getParent();
      }
    }
  }

  STACK_PUSH(GENV_ITEMFACTORY->createBoolean(result, lLangAttrMatched), state);

  STACK_END (state);
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
