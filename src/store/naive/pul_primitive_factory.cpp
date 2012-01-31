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

#include "store/naive/pul_primitive_factory.h"
#include "store/naive/pul_primitives.h"
#include "store/naive/simple_collection.h"

namespace zorba { namespace simplestore {


/***************************************************************************

***************************************************************************/
UpdDelete*
PULPrimitiveFactory::createUpdDelete(
    CollectionPul* pul,
    const QueryLoc* aLoc,
    store::Item_t& target)
{
  return new UpdDelete(pul, aLoc, target);
}

    
/***************************************************************************

***************************************************************************/
UpdInsertChildren*
PULPrimitiveFactory::createUpdInsertChildren(
    CollectionPul* pul,
    const QueryLoc* aLoc,
    store::UpdateConsts::UpdPrimKind kind,
    store::Item_t& target,
    store::Item_t& sibling,
    std::vector<store::Item_t>& children)
{
  return new UpdInsertChildren(pul, aLoc, kind, target, sibling, children);
}

    
    /***************************************************************************
    ***************************************************************************/
    UpdInsertAttributes*
    PULPrimitiveFactory::createUpdInsertAttributes(
          CollectionPul* pul,
          const QueryLoc* aLoc,
          store::Item_t& target,
          std::vector<store::Item_t>&  attrs)
    {
      return new UpdInsertAttributes(pul, aLoc, target, attrs);
    }
    
    /***************************************************************************
    ***************************************************************************/
    UpdReplaceAttribute*
    PULPrimitiveFactory::createUpdReplaceAttribute(
          CollectionPul* pul,
          const QueryLoc* aLoc,
          store::Item_t& target,
          store::Item_t& attr,
          std::vector<store::Item_t>& newAttrs)
    {
      return new UpdReplaceAttribute(pul, aLoc, target, attr, newAttrs);
    }
    
    /***************************************************************************
    ***************************************************************************/
    UpdReplaceChild*
    PULPrimitiveFactory::createUpdReplaceChild(
          CollectionPul* pul,
          const QueryLoc* aLoc,
          store::Item_t& target,
          store::Item_t& child,
          std::vector<store::Item_t>& newChildren)
    {
      return new UpdReplaceChild(pul, aLoc, target, child, newChildren);
    }
    
    /***************************************************************************
    ***************************************************************************/
    UpdReplaceElemContent*
    PULPrimitiveFactory::createUpdReplaceElemContent(
          CollectionPul* pul,
          const QueryLoc* aLoc,
          store::Item_t& target,
          store::Item_t& newChild)
    {
      return new UpdReplaceElemContent(pul, aLoc, target, newChild);
    }
    
    /***************************************************************************
    ***************************************************************************/
    UpdRenameElem*
    PULPrimitiveFactory::createUpdRenameElem(
          CollectionPul* pul,
          const QueryLoc* aLoc,
          store::Item_t& target,
          store::Item_t& newName)
    {
      return new UpdRenameElem(pul, aLoc, target, newName);
    }
    

/***************************************************************************

***************************************************************************/
UpdReplaceAttrValue* PULPrimitiveFactory::createUpdReplaceAttrValue(
    CollectionPul* pul,
    const QueryLoc* aLoc,
    store::Item_t& target,
    zstring& newValue)
{
  return new UpdReplaceAttrValue(pul, aLoc, target, newValue);
}

    
/***************************************************************************

***************************************************************************/
UpdRenameAttr* PULPrimitiveFactory::createUpdRenameAttr(
    CollectionPul* pul,
    const QueryLoc* aLoc,
    store::Item_t& target,
    store::Item_t& newName)
{
  return new UpdRenameAttr(pul, aLoc, target, newName);
}
    

/***************************************************************************

***************************************************************************/
UpdReplaceTextValue* PULPrimitiveFactory::createUpdReplaceTextValue(
    CollectionPul* pul,
    const QueryLoc* aLoc,
    store::Item_t& target,
    zstring& newValue)
{
  return new UpdReplaceTextValue(pul, aLoc, target, newValue);
}
    

/***************************************************************************

***************************************************************************/
UpdReplacePiValue* PULPrimitiveFactory::createUpdReplacePiValue(
    CollectionPul* pul,
    const QueryLoc* aLoc,
    store::Item_t& target,
    zstring& newValue)
{
  return new UpdReplacePiValue(pul, aLoc, target, newValue);
}
    

/***************************************************************************

***************************************************************************/
UpdRenamePi*
PULPrimitiveFactory::createUpdRenamePi(
    CollectionPul* pul,
    const QueryLoc* aLoc,
    store::Item_t& target,
    zstring& newName)
{
  return new UpdRenamePi(pul, aLoc, target, newName);
}

    
/***************************************************************************

***************************************************************************/
UpdReplaceCommentValue*
PULPrimitiveFactory::createUpdReplaceCommentValue(
    CollectionPul* pul,
    const QueryLoc* aLoc,
    store::Item_t& target,
    zstring& newValue)
{
  return new UpdReplaceCommentValue(pul, aLoc, target, newValue);
}
    

/***************************************************************************

***************************************************************************/
UpdSetElementType*
PULPrimitiveFactory::createUpdSetElementType(
    PULImpl*       pul,
    const QueryLoc* aLoc,
    store::Item_t& target,
    store::Item_t& typeName,
    store::Item_t& typedValue,
    bool           haveValue,
    bool           haveEmptyValue,
    bool           haveTypedValue,
    bool           haveListValue,
    bool           isInSubstitutionGroup)
{
  return new UpdSetElementType(pul, aLoc, target, typeName, typedValue,
                               haveValue, haveEmptyValue, haveTypedValue, haveListValue,
                               isInSubstitutionGroup);
}
    

/***************************************************************************

***************************************************************************/
UpdSetAttributeType*
PULPrimitiveFactory::createUpdSetAttributeType(
    PULImpl*       pul,
    const QueryLoc* aLoc,
    store::Item_t& target,
    store::Item_t& typeName,
    store::Item_t& typedValue,
    bool           haveListValue)
{
  return new UpdSetAttributeType(pul, aLoc, target, typeName, typedValue, haveListValue);
}

/***************************************************************************

***************************************************************************/
UpdRevalidate*
PULPrimitiveFactory::createUpdRevalidate(
    PULImpl*       pul,
    const QueryLoc* aLoc,
    store::Item_t& target)
{
  return new UpdRevalidate(pul, aLoc, target);
}

/***************************************************************************

***************************************************************************/
UpdPut*
PULPrimitiveFactory::createUpdPut(
    PULImpl* pul,
    const QueryLoc* aLoc,
    store::Item_t& target,
    store::Item_t& uri)
{
  return new UpdPut(pul, aLoc, target, uri);
}

    
    /***************************************************************************
    ***************************************************************************/
    UpdCreateCollection*
    PULPrimitiveFactory::createUpdCreateCollection(
          CollectionPul* pul,
          const QueryLoc* aLoc,
          store::Item_t& name,
          const std::vector<store::Annotation_t>& annotations,
          const store::Item_t& nodeType,
          bool dyn_collection)
    {
      return new UpdCreateCollection(
          pul,
          aLoc,
          name,
          annotations,
          nodeType,
          dyn_collection);
    }

    
    /***************************************************************************
    ***************************************************************************/
    UpdDeleteCollection*
    PULPrimitiveFactory::createUpdDeleteCollection(
          CollectionPul* pul,
          const QueryLoc* aLoc,
          store::Item_t& name,
          bool dyn_collection)
    {
      return new UpdDeleteCollection(pul, aLoc, name, dyn_collection);
    }

    
    /***************************************************************************
    ***************************************************************************/
    UpdInsertIntoCollection*
    PULPrimitiveFactory::createUpdInsertIntoCollection(
          CollectionPul* pul,
          const QueryLoc* aLoc,
          store::Item_t& name, 
          std::vector<store::Item_t>& nodes,
          bool dyn_collection)
    {
      return new UpdInsertIntoCollection(pul, aLoc, name, nodes, dyn_collection);
    }

    
    /***************************************************************************
    ***************************************************************************/
    UpdInsertFirstIntoCollection*
    PULPrimitiveFactory::createUpdInsertFirstIntoCollection(
        CollectionPul* pul,
          const QueryLoc* aLoc,
        store::Item_t& name,
        std::vector<store::Item_t>& nodes,
        bool dyn_collection)
    {
      return new UpdInsertFirstIntoCollection(pul, aLoc, name, nodes, dyn_collection);
    }

    
    /***************************************************************************
    ***************************************************************************/
    UpdInsertLastIntoCollection*
    PULPrimitiveFactory::createUpdInsertLastIntoCollection(
          CollectionPul* pul,
          const QueryLoc* aLoc,
          store::Item_t& name,
          std::vector<store::Item_t>& nodes,
          bool dyn_collection)
    {
      return new UpdInsertLastIntoCollection(pul, aLoc, name, nodes, dyn_collection);
    }

    
    /***************************************************************************
    ***************************************************************************/
    UpdInsertBeforeIntoCollection*
    PULPrimitiveFactory::createUpdInsertBeforeIntoCollection(
          CollectionPul* pul,
          const QueryLoc* aLoc,
          store::Item_t& name,
          store::Item_t& target,
          std::vector<store::Item_t>& nodes,
          bool dyn_collection)
    {
      return new UpdInsertBeforeIntoCollection(pul, aLoc, name, target, nodes, dyn_collection);
    }

    
    /***************************************************************************
    ***************************************************************************/
    UpdInsertAfterIntoCollection*
    PULPrimitiveFactory::createUpdInsertAfterIntoCollection(
          CollectionPul* pul,
          const QueryLoc* aLoc,
          store::Item_t& name,
          store::Item_t& target,
          std::vector<store::Item_t>& nodes,
          bool dyn_collection)
    {
      return new UpdInsertAfterIntoCollection(pul, aLoc, name, target, nodes, dyn_collection);
    }

    
    /***************************************************************************
    ***************************************************************************/
    UpdDeleteNodesFromCollection*
    PULPrimitiveFactory::createUpdDeleteNodesFromCollection(
          CollectionPul* pul,
          const QueryLoc* aLoc,
          store::Item_t& name,
          std::vector<store::Item_t>& nodes,
          bool isLast,
          bool dyn_collection)
    {
      return new UpdDeleteNodesFromCollection(pul, aLoc, name, nodes, isLast, dyn_collection);
    }

    
    /***************************************************************************
    ***************************************************************************/
    UpdCreateIndex*
    PULPrimitiveFactory::createUpdCreateIndex(
          PULImpl* pul,
          const QueryLoc* aLoc,
          const store::Item_t& qname,
          const store::IndexSpecification& spec,
          store::Iterator* sourceIter)
    {
      return new UpdCreateIndex(pul, aLoc, qname, spec, sourceIter);
    }

    
    /***************************************************************************
    ***************************************************************************/
    UpdDeleteIndex*
    PULPrimitiveFactory::createUpdDeleteIndex(
        PULImpl* pul,
        const QueryLoc* aLoc,
        const store::Item_t& qname)
    {
      return new UpdDeleteIndex(pul, aLoc, qname);
    }

    
    /***************************************************************************
    ***************************************************************************/
    UpdRefreshIndex*
    PULPrimitiveFactory::createUpdRefreshIndex(
          PULImpl* pul,
          const QueryLoc* aLoc,
          const store::Item_t& qname,
          store::Iterator* sourceIter)
    {
      return new UpdRefreshIndex(pul, aLoc, qname, sourceIter);
    }

    
    /***************************************************************************
    ***************************************************************************/
    UpdActivateIC*
    PULPrimitiveFactory::createUpdActivateIC(
          PULImpl* pul,
          const QueryLoc* aLoc,
          const store::Item_t& aQName,
          const store::Item_t& aCollectionName)
    {
      return new UpdActivateIC(pul, aLoc, aQName, aCollectionName);
    }
    

    /***************************************************************************
    ***************************************************************************/
    UpdActivateForeignKeyIC*
    PULPrimitiveFactory::createUpdActivateForeignKeyIC(
          PULImpl* pul,
          const QueryLoc* aLoc,
          const store::Item_t& qQName,
          const store::Item_t& aFromCollectionName,
          const store::Item_t& aToCollectionName)
    {
      return new UpdActivateForeignKeyIC(pul, aLoc, qQName, aFromCollectionName, aToCollectionName);
    }
    

    /***************************************************************************
    ***************************************************************************/
    UpdDeActivateIC*
    PULPrimitiveFactory::createUpdDeActivateIC(
        PULImpl* pul,
          const QueryLoc* aLoc,
        const store::Item_t& qname)
    {
      return new UpdDeActivateIC(pul, aLoc, qname);
    }


    /***************************************************************************
     ***************************************************************************/
    UpdCreateDocument*
    PULPrimitiveFactory::createUpdCreateDocument(
          PULImpl* pul,
          const QueryLoc* aLoc,
          const store::Item_t& uri,
          store::Item_t& doc)
    {
      return new UpdCreateDocument(pul, aLoc, uri, doc);
    }
    
    /***************************************************************************
     ***************************************************************************/
    UpdDeleteDocument*
    PULPrimitiveFactory::createUpdDeleteDocument(
          PULImpl* pul,
          const QueryLoc* aLoc,
          const store::Item_t& uri)
   {
     return new UpdDeleteDocument(pul, aLoc, uri);
   }

  /***************************************************************************
   ***************************************************************************/
  UpdCreateHashMap*
  PULPrimitiveFactory::createUpdCreateHashMap(
        PULImpl* pul,
        const QueryLoc* aLoc,
        const store::Item_t& aQName,
        const std::vector<store::Item_t>& aKeyTypes,
        const std::vector<zstring>& aCollations,
        long aTimezone)
  {
    return new UpdCreateHashMap(
        pul, aLoc, aQName, aKeyTypes, aCollations, aTimezone);;
  }

  /***************************************************************************
   ***************************************************************************/
  UpdDestroyHashMap*
  PULPrimitiveFactory::createUpdDestroyHashMap(
        PULImpl* pul,
        const QueryLoc* aLoc,
        const store::Item_t& aQName)
  {
    return new UpdDestroyHashMap(pul, aLoc, aQName);
  }

  /***************************************************************************
   ***************************************************************************/
  UpdInsertIntoHashMap*
  PULPrimitiveFactory::createUpdInsertIntoHashMap(
        PULImpl* pul,
        const QueryLoc* aLoc,
        const store::Item_t& aQName,
        const std::vector<store::Item_t>& aKey,
        const store::Iterator_t& aValue)
  {
    return new UpdInsertIntoHashMap(pul, aLoc, aQName, aKey, aValue);
  }

  /***************************************************************************
   ***************************************************************************/
  UpdRemoveFromHashMap*
  PULPrimitiveFactory::createUpdRemoveFromHashMap(
        PULImpl* pul,
        const QueryLoc* aLoc,
        const store::Item_t& aQName,
        const std::vector<store::Item_t>& aKey)
  {
    return new UpdRemoveFromHashMap(pul, aLoc, aQName, aKey);
  }

#ifdef ZORBA_WITH_JSON
  /***************************************************************************
   ***************************************************************************/
  UpdJSONInsert*
  PULPrimitiveFactory::createUpdJSONInsert(
        CollectionPul* pul,
        const QueryLoc* aLoc,
        store::Item_t& aObject,
        std::vector<store::Item_t>& aPairs)
  {
    return new UpdJSONInsert(pul, aLoc, aObject, aPairs);
  }

  /***************************************************************************
   ***************************************************************************/
  UpdJSONDelete*
  PULPrimitiveFactory::createUpdJSONDelete(
        CollectionPul* pul,
        const QueryLoc* aLoc,
        store::Item_t& aTarget,
        store::Item_t& aSelector)
  {
    return new UpdJSONDelete(pul, aLoc, aTarget, aSelector);
  }
#endif

} /* namespace simplestore */ } /* namespace zorba */
/* vim:set et sw=2 ts=2: */
