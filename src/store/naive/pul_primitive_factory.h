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
#ifndef ZORBA_SIMPLE_STORE_PUL_PRIMITIVE_FACTORY_H
#define ZORBA_SIMPLE_STORE_PUL_PRIMITIVE_FACTORY_H

#include "common/shared_types.h"

#include "zorbatypes/integer.h"
#include "zorbatypes/schema_types.h"

#include "store/api/update_consts.h"
#include "store/api/index.h"

#include "shared_types.h"

namespace zorba { namespace simplestore {

  class PULImpl;
  class CollectionPul;
  class UpdDelete;
  class UpdInsertChildren;
  class UpdInsertAttributes;
  class UpdReplaceAttribute;
  class UpdReplaceChild;
  class UpdReplaceElemContent;
  class UpdRenameElem;
  class UpdReplaceAttrValue;
  class UpdRenameAttr;
  class UpdReplaceTextValue;
  class UpdReplacePiValue;
  class UpdRenamePi;
  class UpdReplaceCommentValue;
  class UpdSetElementType;
  class UpdSetAttributeType;
  class UpdRevalidate;
  class UpdPut;
  class UpdCreateCollection;
  class UpdDeleteCollection;
  class UpdInsertIntoCollection;
  class UpdInsertFirstIntoCollection;
  class UpdInsertLastIntoCollection;
  class UpdInsertBeforeIntoCollection;
  class UpdInsertAfterIntoCollection;
  class UpdDeleteNodesFromCollection;
  class UpdTruncateCollection;
  class UpdCreateIndex;
  class UpdDeleteIndex;
  class UpdRefreshIndex;
  class UpdActivateIC;
  class UpdActivateForeignKeyIC;
  class UpdDeActivateIC;
  class UpdCreateDocument;
  class UpdDeleteDocument;
  class UpdCreateHashMap;
  class UpdDestroyHashMap;
  class UpdInsertIntoHashMap;
  class UpdRemoveFromHashMap;
#ifdef ZORBA_WITH_JSON
  class UpdJSONObjectInsert;
  class UpdJSONObjectDelete;
  class UpdJSONObjectReplaceValue;
  class UpdJSONObjectRename;
  class UpdJSONArrayInsert;
  class UpdJSONArrayDelete;
  class UpdJSONArrayReplaceValue;
#endif

class PULPrimitiveFactory 
{
public:
  virtual ~PULPrimitiveFactory() {}

  virtual UpdDelete*
  createUpdDelete(
      CollectionPul* pul,
      const QueryLoc*,
      store::Item_t& target);
    
  virtual UpdInsertChildren*
  createUpdInsertChildren(
      CollectionPul* pul,
      const QueryLoc*,
      store::UpdateConsts::UpdPrimKind kind,
      store::Item_t& target,
      store::Item_t& sibling,
      std::vector<store::Item_t>& children);
  
  virtual UpdInsertAttributes*
  createUpdInsertAttributes(
      CollectionPul* pul,
      const QueryLoc*,
      store::Item_t& target,
      std::vector<store::Item_t>&  attrs);
  
  virtual UpdReplaceAttribute*
  createUpdReplaceAttribute(
      CollectionPul* pul,
      const QueryLoc*,
      store::Item_t& target,
      store::Item_t& attr,
      std::vector<store::Item_t>& newAttrs);
  
  virtual UpdReplaceChild*
  createUpdReplaceChild(
      CollectionPul* pul,
      const QueryLoc*,
      store::Item_t& target,
      store::Item_t& child,
      std::vector<store::Item_t>& newChildren);
  
  virtual UpdReplaceElemContent*
  createUpdReplaceElemContent(
      CollectionPul* pul,
      const QueryLoc*,
      store::Item_t& target,
      store::Item_t& newChild);
  
  virtual UpdRenameElem*
  createUpdRenameElem(
      CollectionPul* pul,
      const QueryLoc*,
      store::Item_t& target,
      store::Item_t& newName); 
    
  virtual UpdReplaceAttrValue*
  createUpdReplaceAttrValue(
      CollectionPul* pul,
      const QueryLoc*,
      store::Item_t& target,
      zstring& newValue);
  
  virtual UpdRenameAttr*
  createUpdRenameAttr(
      CollectionPul* pul,
      const QueryLoc*,
      store::Item_t& target,
      store::Item_t& newName);
    
  virtual UpdReplaceTextValue*
  createUpdReplaceTextValue(
      CollectionPul* pul,
      const QueryLoc*,
      store::Item_t& target,
      zstring& newValue); 
  
  virtual UpdReplacePiValue*
  createUpdReplacePiValue(
        CollectionPul* pul,
        const QueryLoc*,
        store::Item_t& target,
        zstring& newValue);
  
  virtual UpdRenamePi*
  createUpdRenamePi(
        CollectionPul* pul,
        const QueryLoc*,
        store::Item_t& target,
        zstring& newName); 
    
  virtual UpdReplaceCommentValue*
  createUpdReplaceCommentValue(
        CollectionPul* pul,
        const QueryLoc*,
        store::Item_t& target,
        zstring& newValue);
  
  virtual UpdSetElementType*
  createUpdSetElementType(
        PULImpl*       pul,
        const QueryLoc*,
        store::Item_t& target,
        store::Item_t& typeName,
        store::Item_t& typedValue,
        bool           haveValue,
        bool           haveEmptyValue,
        bool           haveTypedValue,
        bool           haveListValue,
        bool           isInSubstitutionGroup);
  
  virtual UpdSetAttributeType*
  createUpdSetAttributeType(
        PULImpl*       pul,
        const QueryLoc*,
        store::Item_t& target,
        store::Item_t& typeName,
        store::Item_t& typedValue,
        bool           haveListValue);
  
  virtual UpdRevalidate*
  createUpdRevalidate(
        PULImpl*       pul,
        const QueryLoc*,
        store::Item_t& target);

  virtual UpdPut*
  createUpdPut(PULImpl* pul, const QueryLoc*, store::Item_t& target, store::Item_t& uri);
  
  /***************************************************************************/

  virtual UpdCreateCollection*
  createUpdCreateCollection(
        CollectionPul* pul,
        const QueryLoc*,
        store::Item_t& name,
        const std::vector<store::Annotation_t>& annotations,
        const store::Item_t& nodeType,
        bool isDynamic);
    
  virtual UpdDeleteCollection*
  createUpdDeleteCollection(
        CollectionPul* pul,
        const QueryLoc*,
        store::Item_t& name,
        bool isDynamic);
    
  virtual UpdInsertIntoCollection*
  createUpdInsertIntoCollection(
        CollectionPul* pul,
        const QueryLoc*,
        store::Item_t& name, 
        std::vector<store::Item_t>& nodes,
        bool isDynamic);
  
  virtual UpdInsertFirstIntoCollection*
  createUpdInsertFirstIntoCollection(
      CollectionPul* pul,
      const QueryLoc*,
      store::Item_t& name,
      std::vector<store::Item_t>& nodes,
      bool isDynamic);
    
  virtual UpdInsertLastIntoCollection*
  createUpdInsertLastIntoCollection(
        CollectionPul* pul,
        const QueryLoc*,
        store::Item_t& name,
        std::vector<store::Item_t>& nodes,
        bool isDynamic);
    
  virtual UpdInsertBeforeIntoCollection*
  createUpdInsertBeforeIntoCollection(
        CollectionPul* pul,
        const QueryLoc*,
        store::Item_t& name,
        store::Item_t& target,
        std::vector<store::Item_t>& nodes,
        bool isDynamic);
    
  virtual UpdInsertAfterIntoCollection*
  createUpdInsertAfterIntoCollection(
        CollectionPul* pul,
        const QueryLoc*,
        store::Item_t& name,
        store::Item_t& target,
        std::vector<store::Item_t>& nodes,
        bool isDynamic);
  
  virtual UpdDeleteNodesFromCollection*
  createUpdDeleteNodesFromCollection(
        CollectionPul* pul,
        const QueryLoc*,
        store::Item_t& name,
        std::vector<store::Item_t>& nodes,
        bool isLast,
        bool isDynamic);

  virtual UpdTruncateCollection*
  createUpdTruncateCollection(
        CollectionPul* pul,
        const QueryLoc*,
        store::Item_t& name,
        bool isDynamic);
    
  virtual UpdCreateIndex*
  createUpdCreateIndex(
        PULImpl* pul,
        const QueryLoc*,
        const store::Item_t& qname,
        const store::IndexSpecification& spec,
        store::Iterator* sourceIter);
    
  virtual UpdDeleteIndex*
  createUpdDeleteIndex(PULImpl* pul, const QueryLoc*, const store::Item_t& qname);
    
  virtual UpdRefreshIndex*
  createUpdRefreshIndex(
        PULImpl* pul,
        const QueryLoc* aLoc,
        const store::Item_t& qname,
        store::Iterator* sourceIter);
    
  virtual UpdActivateIC*
  createUpdActivateIC(
        PULImpl* pul,
        const QueryLoc* aLoc,
        const store::Item_t& aQName,
        const store::Item_t& aCollectionName);
  
  virtual UpdActivateForeignKeyIC*
  createUpdActivateForeignKeyIC(
        PULImpl* pul,
        const QueryLoc* aLoc,
        const store::Item_t& qQName,
        const store::Item_t& aFromCollectionName,
        const store::Item_t& aToCollectionName);
  
  virtual UpdDeActivateIC*
  createUpdDeActivateIC(
        PULImpl* pul,
        const QueryLoc* aLoc,
        const store::Item_t& qname);

  virtual UpdCreateDocument*
  createUpdCreateDocument(
        PULImpl* pul,
        const QueryLoc* aLoc,
        const store::Item_t& uri,
        store::Item_t& aDocument);

  virtual UpdDeleteDocument*
  createUpdDeleteDocument(
        PULImpl* pul,
        const QueryLoc* aLoc,
        const store::Item_t& uri);

  virtual UpdCreateHashMap*
  createUpdCreateHashMap(
        PULImpl* pul,
        const QueryLoc* aLoc,
        const store::Item_t& aQName,
        const std::vector<store::Item_t>& aKeyTypes,
        const std::vector<zstring>& aCollations,
        long aTimezone);

  virtual UpdDestroyHashMap*
  createUpdDestroyHashMap(
        PULImpl* pul,
        const QueryLoc* aLoc,
        const store::Item_t& aQName);

  virtual UpdInsertIntoHashMap*
  createUpdInsertIntoHashMap(
        PULImpl* pul,
        const QueryLoc* aLoc,
        const store::Item_t& aQName,
        const std::vector<store::Item_t>& aKey,
        const store::Iterator_t& aValue);

  virtual UpdRemoveFromHashMap*
  createUpdRemoveFromHashMap(
        PULImpl* pul,
        const QueryLoc* aLoc,
        const store::Item_t& aQName,
        const std::vector<store::Item_t>& aKey);

  /***************************************************************************/

#ifdef ZORBA_WITH_JSON

  virtual UpdJSONObjectInsert*
  createUpdJSONObjectInsert(
      CollectionPul* pul,
      const QueryLoc* loc,
      store::Item_t& target,
      std::vector<store::Item_t>& names,
      std::vector<store::Item_t>& values);

  virtual UpdJSONObjectDelete*
  createUpdJSONObjectDelete(
        CollectionPul* pul,
        const QueryLoc* loc,
        store::Item_t& target,
        store::Item_t& name);

  virtual UpdJSONObjectReplaceValue*
  createUpdJSONObjectReplaceValue(
        CollectionPul* pul,
        const QueryLoc* loc,
        store::Item_t& target,
        store::Item_t& name,
        store::Item_t& newValue);

  virtual UpdJSONObjectRename*
  createUpdJSONObjectRename(
        CollectionPul* pul,
        const QueryLoc* loc,
        store::Item_t& target,
        store::Item_t& name,
        store::Item_t& newName);

  virtual UpdJSONArrayInsert*
  createUpdJSONArrayInsert(
        CollectionPul* pul,
        const QueryLoc* loc,
        store::Item_t& target,
        xs_integer& pos,
        std::vector<store::Item_t>& members);

  virtual UpdJSONArrayDelete*
  createUpdJSONArrayDelete(
        CollectionPul* pul,
        const QueryLoc* loc,
        store::Item_t& target,
        xs_integer& pos);

  virtual UpdJSONArrayReplaceValue*
  createUpdJSONArrayReplaceValue(
        CollectionPul* pul,
        const QueryLoc* loc,
        store::Item_t& target,
        xs_integer& pos,
        store::Item_t& newValue);
#endif

}; /* class PULPrimitiveFactory */
    

} /* namespace simplestore */ } /* namespace zorba */

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
