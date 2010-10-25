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
#include "store/api/update_consts.h"
#include "store/api/index.h"
#include "store/naive/shared_types.h"

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
  class UpdPut;
  class UpdCreateCollection;
  class UpdDeleteCollection;
  class UpdInsertIntoCollection;
  class UpdInsertFirstIntoCollection;
  class UpdInsertLastIntoCollection;
  class UpdInsertBeforeIntoCollection;
  class UpdInsertAfterIntoCollection;
  class UpdDeleteNodesFromCollection;
  class UpdCreateIndex;
  class UpdDeleteIndex;
  class UpdRefreshIndex;
  class UpdActivateIC;
  class UpdActivateForeignKeyIC;
  class UpdDeActivateIC;

class PULPrimitiveFactory 
{
 public:
  virtual ~PULPrimitiveFactory() {}

  /***************************************************************************
   ***************************************************************************/
  virtual UpdDelete*
  createUpdDelete(CollectionPul* pul, store::Item_t& target);
    
  /***************************************************************************
   ***************************************************************************/
  virtual UpdInsertChildren*
  createUpdInsertChildren(
        CollectionPul* pul,
        store::UpdateConsts::UpdPrimKind kind,
        store::Item_t& target,
        store::Item_t& sibling,
        std::vector<store::Item_t>& children);
  
  /***************************************************************************
   ***************************************************************************/
  virtual UpdInsertAttributes*
  createUpdInsertAttributes(
        CollectionPul* pul,
        store::Item_t& target,
        std::vector<store::Item_t>&  attrs);
  
  /***************************************************************************
   ***************************************************************************/
  virtual UpdReplaceAttribute*
  createUpdReplaceAttribute(
        CollectionPul* pul,
        store::Item_t& target,
        store::Item_t& attr,
        std::vector<store::Item_t>& newAttrs);
  
  /***************************************************************************
   ***************************************************************************/
  virtual UpdReplaceChild*
  createUpdReplaceChild(
        CollectionPul* pul,
        store::Item_t& target,
        store::Item_t& child,
        std::vector<store::Item_t>& newChildren);
    
  /***************************************************************************
   ***************************************************************************/
  virtual UpdReplaceElemContent*
  createUpdReplaceElemContent(
        CollectionPul* pul,
        store::Item_t& target,
        store::Item_t& newChild);
  
  /***************************************************************************
   ***************************************************************************/
  virtual UpdRenameElem*
  createUpdRenameElem(
        CollectionPul* pul,
        store::Item_t& target,
        store::Item_t& newName); 
    
  /***************************************************************************
   ***************************************************************************/
  virtual UpdReplaceAttrValue*
  createUpdReplaceAttrValue(
        CollectionPul* pul,
        store::Item_t& target,
        zstring& newValue);
  
  /***************************************************************************
   ***************************************************************************/
  virtual UpdRenameAttr*
  createUpdRenameAttr(
        CollectionPul* pul,
        store::Item_t& target,
        store::Item_t& newName);
    
  /***************************************************************************
   ***************************************************************************/
  virtual UpdReplaceTextValue*
  createUpdReplaceTextValue(
        CollectionPul* pul,
        store::Item_t& target,
        zstring& newValue); 
  
  /***************************************************************************
   ***************************************************************************/
  virtual UpdReplacePiValue*
  createUpdReplacePiValue(
        CollectionPul* pul,
        store::Item_t& target,
        zstring& newValue);
  
  /***************************************************************************
   ***************************************************************************/
  virtual UpdRenamePi*
  createUpdRenamePi(
        CollectionPul* pul,
        store::Item_t& target,
        zstring& newName); 
    
  /***************************************************************************
   ***************************************************************************/
  virtual UpdReplaceCommentValue*
  createUpdReplaceCommentValue(
        CollectionPul* pul,
        store::Item_t& target,
        zstring& newValue);
  
  /***************************************************************************
   ***************************************************************************/
  virtual UpdSetElementType*
  createUpdSetElementType(
        PULImpl*       pul,
        store::Item_t& target,
        store::Item_t& typeName,
        store::Item_t& typedValue,
        bool           haveValue,
        bool           haveEmptyValue,
        bool           haveTypedValue,
        bool           haveListValue,
        bool           isInSubstitutionGroup);
  
  /***************************************************************************
   ***************************************************************************/
  virtual UpdSetAttributeType*
  createUpdSetAttributeType(
        PULImpl*       pul,
        store::Item_t& target,
        store::Item_t& typeName,
        store::Item_t& typedValue,
        bool           haveListValue);
  
  /***************************************************************************
   ***************************************************************************/
  virtual UpdPut*
  createUpdPut(PULImpl* pul, store::Item_t& target, store::Item_t& uri);
  
  /***************************************************************************
   ***************************************************************************/
  virtual UpdCreateCollection*
  createUpdCreateCollection(
        CollectionPul* pul,
        store::Item_t& name);
    
  /***************************************************************************
   ***************************************************************************/
  virtual UpdDeleteCollection*
  createUpdDeleteCollection(
        CollectionPul* pul,
        store::Item_t& name);
    
    
  /***************************************************************************
   ***************************************************************************/
  virtual UpdInsertIntoCollection*
  createUpdInsertIntoCollection(
        CollectionPul* pul,
        store::Item_t& name, 
        std::vector<store::Item_t>& nodes);
  
    
  /***************************************************************************
   ***************************************************************************/
  virtual UpdInsertFirstIntoCollection*
  createUpdInsertFirstIntoCollection(
      CollectionPul* pul,
      store::Item_t& name,
      std::vector<store::Item_t>& nodes);
    
  /***************************************************************************
   ***************************************************************************/
  virtual UpdInsertLastIntoCollection*
  createUpdInsertLastIntoCollection(
        CollectionPul* pul,
        store::Item_t& name,
        std::vector<store::Item_t>& nodes);
    
  /***************************************************************************
   ***************************************************************************/
  virtual UpdInsertBeforeIntoCollection*
  createUpdInsertBeforeIntoCollection(
        CollectionPul* pul,
        store::Item_t& name,
        store::Item_t& target,
        std::vector<store::Item_t>& nodes);
    
  /***************************************************************************
   ***************************************************************************/
  virtual UpdInsertAfterIntoCollection*
  createUpdInsertAfterIntoCollection(
        CollectionPul* pul,
        store::Item_t& name,
        store::Item_t& target,
        std::vector<store::Item_t>& nodes);
  
  /***************************************************************************
   ***************************************************************************/
  virtual UpdDeleteNodesFromCollection*
  createUpdDeleteNodesFromCollection(
        CollectionPul* pul,
        store::Item_t& name,
        std::vector<store::Item_t>& nodes,
        bool isLast);
    
  /***************************************************************************
   ***************************************************************************/
  virtual UpdCreateIndex*
  createUpdCreateIndex(
        PULImpl* pul,
        const store::Item_t& qname,
        const store::IndexSpecification& spec,
        store::Iterator* sourceIter);
    
  /***************************************************************************
   ***************************************************************************/
  virtual UpdDeleteIndex*
  createUpdDeleteIndex(PULImpl* pul, const store::Item_t& qname);
    
  /***************************************************************************
   ***************************************************************************/
  virtual UpdRefreshIndex*
  createUpdRefreshIndex(
        PULImpl* pul,
        const store::Item_t& qname,
        store::Iterator* sourceIter);
    
  /***************************************************************************
   ***************************************************************************/
  virtual UpdActivateIC*
  createUpdActivateIC(
        PULImpl* pul,
        const store::Item_t& aQName,
        const store::Item_t& aCollectionName);
  
  /***************************************************************************
   ***************************************************************************/
  virtual UpdActivateForeignKeyIC*
  createUpdActivateForeignKeyIC(
        PULImpl* pul,
        const store::Item_t& qQName,
        const store::Item_t& aFromCollectionName,
        const store::Item_t& aToCollectionName);
  
  /***************************************************************************
   ***************************************************************************/
  virtual UpdDeActivateIC*
  createUpdDeActivateIC(
        PULImpl* pul,
        const store::Item_t& qname);
}; /* class PULPrimitiveFactory */
    

} /* namespace simplestore */ } /* namespace zorba */

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
