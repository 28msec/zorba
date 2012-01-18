/*
 * Copyright 2006-2012 The FLWOR Foundation.
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
#ifndef ZORBA_INDEX_UTIL_H
#define ZORBA_INDEX_UTIL_H

#include "stdafx.h"

#include "context/namespace_context.h"

#include "store/api/pul.h"
#include "store/api/store.h"
#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "store/api/iterator.h"
#include "store/api/index.h"

#include "types/typeimpl.h"
#include "types/typeops.h"
#include "types/casting.h"

namespace zorba {

class IndexUtil
{
public:
  /*******************************************************************************
    generate result elements of the form
    <aBase:key>
      <aBase:attribute aBase:value="key1_value"/>
      <aBase:attribute aBase:value="key2_value"/>
      <aBase:attribute aBase:value="key3_value"/>
    </aBase:key>
  ********************************************************************************/
  static void
  createIndexKeyElement(
      store::Item_t& result,
      store::IndexKey& aKey,
      const zstring& aBase)
  {
    store::Item_t lKeyNodeName;
    GENV_ITEMFACTORY->createQName(lKeyNodeName,
        aBase, "", "key");

    zstring lBase = aBase;
  
    store::Item_t lTypeName = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
  
    const store::NsBindings lBindings;

    GENV_ITEMFACTORY->createElementNode(
        result, NULL, lKeyNodeName, lTypeName,
        true, false, lBindings, lBase);
  
    for (store::ItemVector::iterator lIter = aKey.begin();
         lIter != aKey.end();
         ++lIter)
    {
      store::Item_t lAttrElem, lAttrNodeName;
      store::Item_t lNameAttr, lValueAttr, lValueAttrName;
  
      GENV_ITEMFACTORY->createQName(lAttrNodeName,
          lBase, "", "attribute");

      lTypeName = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
      GENV_ITEMFACTORY->createElementNode(
          lAttrElem, result, lAttrNodeName, lTypeName,
          true, false, lBindings, lBase);
  
      if (*lIter != NULL)
      {
        GENV_ITEMFACTORY->createQName(lValueAttrName,
             "", "", "value");
  
        lTypeName = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
        GENV_ITEMFACTORY->createAttributeNode(
            lValueAttr, lAttrElem.getp(), lValueAttrName, lTypeName, (*lIter));
      }
    }
  }
}; /* class IndexUtil */

} // namespace zorba
/* vim:set et sw=2 ts=2: */
#endif
