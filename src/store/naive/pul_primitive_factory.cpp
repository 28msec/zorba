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
PULPrimitiveFactory::createUpdDelete(CollectionPul* pul, store::Item_t& target)
{
  return new UpdDelete(pul, target);
}

    
/***************************************************************************

***************************************************************************/
UpdInsertChildren*
PULPrimitiveFactory::createUpdInsertChildren(
    CollectionPul* pul,
    store::UpdateConsts::UpdPrimKind kind,
    store::Item_t& target,
    store::Item_t& sibling,
    std::vector<store::Item_t>& children)
{
  return new UpdInsertChildren(pul, kind, target, sibling, children);
}

    
    /***************************************************************************
    ***************************************************************************/
    UpdInsertAttributes*
    PULPrimitiveFactory::createUpdInsertAttributes(
          CollectionPul* pul,
          store::Item_t& target,
          std::vector<store::Item_t>&  attrs)
    {
      return new UpdInsertAttributes(pul, target, attrs);
    }
    
    /***************************************************************************
    ***************************************************************************/
    UpdReplaceAttribute*
    PULPrimitiveFactory::createUpdReplaceAttribute(
          CollectionPul* pul,
          store::Item_t& target,
          store::Item_t& attr,
          std::vector<store::Item_t>& newAttrs)
    {
      return new UpdReplaceAttribute(pul, target, attr, newAttrs);
    }
    
    /***************************************************************************
    ***************************************************************************/
    UpdReplaceChild*
    PULPrimitiveFactory::createUpdReplaceChild(
          CollectionPul* pul,
          store::Item_t& target,
          store::Item_t& child,
          std::vector<store::Item_t>& newChildren)
    {
      return new UpdReplaceChild(pul, target, child, newChildren);
    }
    
    /***************************************************************************
    ***************************************************************************/
    UpdReplaceElemContent*
    PULPrimitiveFactory::createUpdReplaceElemContent(
          CollectionPul* pul,
          store::Item_t& target,
          store::Item_t& newChild)
    {
      return new UpdReplaceElemContent(pul, target, newChild);
    }
    
    /***************************************************************************
    ***************************************************************************/
    UpdRenameElem*
    PULPrimitiveFactory::createUpdRenameElem(
          CollectionPul* pul,
          store::Item_t& target,
          store::Item_t& newName)
    {
      return new UpdRenameElem(pul, target, newName);
    }
    

/***************************************************************************

***************************************************************************/
UpdReplaceAttrValue* PULPrimitiveFactory::createUpdReplaceAttrValue(
    CollectionPul* pul,
    store::Item_t& target,
    zstring& newValue)
{
  return new UpdReplaceAttrValue(pul, target, newValue);
}

    
/***************************************************************************

***************************************************************************/
UpdRenameAttr* PULPrimitiveFactory::createUpdRenameAttr(
    CollectionPul* pul,
    store::Item_t& target,
    store::Item_t& newName)
{
  return new UpdRenameAttr(pul, target, newName);
}
    

/***************************************************************************

***************************************************************************/
UpdReplaceTextValue* PULPrimitiveFactory::createUpdReplaceTextValue(
    CollectionPul* pul,
    store::Item_t& target,
    zstring& newValue)
{
  return new UpdReplaceTextValue(pul, target, newValue);
}
    

/***************************************************************************

***************************************************************************/
UpdReplacePiValue* PULPrimitiveFactory::createUpdReplacePiValue(
    CollectionPul* pul,
    store::Item_t& target,
    zstring& newValue)
{
  return new UpdReplacePiValue(pul, target, newValue);
}
    

/***************************************************************************

***************************************************************************/
UpdRenamePi*
PULPrimitiveFactory::createUpdRenamePi(
    CollectionPul* pul,
    store::Item_t& target,
    zstring& newName)
{
  return new UpdRenamePi(pul, target, newName);
}

    
/***************************************************************************

***************************************************************************/
UpdReplaceCommentValue*
PULPrimitiveFactory::createUpdReplaceCommentValue(
    CollectionPul* pul,
    store::Item_t& target,
    zstring& newValue)
{
  return new UpdReplaceCommentValue(pul, target, newValue);
}
    

/***************************************************************************

***************************************************************************/
UpdSetElementType*
PULPrimitiveFactory::createUpdSetElementType(
    PULImpl*       pul,
    store::Item_t& target,
    store::Item_t& typeName,
    store::Item_t& typedValue,
    bool           haveValue,
    bool           haveEmptyValue,
    bool           haveTypedValue,
    bool           haveListValue,
    bool           isInSubstitutionGroup)
{
  return new UpdSetElementType(pul, target, typeName, typedValue,
                               haveValue, haveEmptyValue, haveTypedValue, haveListValue,
                               isInSubstitutionGroup);
}
    

/***************************************************************************

***************************************************************************/
UpdSetAttributeType*
PULPrimitiveFactory::createUpdSetAttributeType(
    PULImpl*       pul,
    store::Item_t& target,
    store::Item_t& typeName,
    store::Item_t& typedValue,
    bool           haveListValue)
{
  return new UpdSetAttributeType(pul, target, typeName, typedValue, haveListValue);
}
    

/***************************************************************************

***************************************************************************/
UpdPut*
PULPrimitiveFactory::createUpdPut(
    PULImpl* pul,
    store::Item_t& target,
    store::Item_t& uri)
{
  return new UpdPut(pul, target, uri);
}

    
    /***************************************************************************
    ***************************************************************************/
    UpdCreateCollection*
    PULPrimitiveFactory::createUpdCreateCollection(
          CollectionPul* pul,
          store::Item_t& name,
          bool dyn_collection)
    {
      return new UpdCreateCollection(pul, name, dyn_collection);
    }

    
    /***************************************************************************
    ***************************************************************************/
    UpdDeleteCollection*
    PULPrimitiveFactory::createUpdDeleteCollection(
          CollectionPul* pul,
          store::Item_t& name,
          bool dyn_collection)
    {
      return new UpdDeleteCollection(pul, name, dyn_collection);
    }

    
    /***************************************************************************
    ***************************************************************************/
    UpdInsertIntoCollection*
    PULPrimitiveFactory::createUpdInsertIntoCollection(
          CollectionPul* pul,
          store::Item_t& name, 
          std::vector<store::Item_t>& nodes,
          bool dyn_collection)
    {
      return new UpdInsertIntoCollection(pul, name, nodes, dyn_collection);
    }

    
    /***************************************************************************
    ***************************************************************************/
    UpdInsertFirstIntoCollection*
    PULPrimitiveFactory::createUpdInsertFirstIntoCollection(
        CollectionPul* pul,
        store::Item_t& name,
        std::vector<store::Item_t>& nodes,
        bool dyn_collection)
    {
      return new UpdInsertFirstIntoCollection(pul, name, nodes, dyn_collection);
    }

    
    /***************************************************************************
    ***************************************************************************/
    UpdInsertLastIntoCollection*
    PULPrimitiveFactory::createUpdInsertLastIntoCollection(
          CollectionPul* pul,
          store::Item_t& name,
          std::vector<store::Item_t>& nodes,
          bool dyn_collection)
    {
      return new UpdInsertLastIntoCollection(pul, name, nodes, dyn_collection);
    }

    
    /***************************************************************************
    ***************************************************************************/
    UpdInsertBeforeIntoCollection*
    PULPrimitiveFactory::createUpdInsertBeforeIntoCollection(
          CollectionPul* pul,
          store::Item_t& name,
          store::Item_t& target,
          std::vector<store::Item_t>& nodes,
          bool dyn_collection)
    {
      return new UpdInsertBeforeIntoCollection(pul, name, target, nodes, dyn_collection);
    }

    
    /***************************************************************************
    ***************************************************************************/
    UpdInsertAfterIntoCollection*
    PULPrimitiveFactory::createUpdInsertAfterIntoCollection(
          CollectionPul* pul,
          store::Item_t& name,
          store::Item_t& target,
          std::vector<store::Item_t>& nodes,
          bool dyn_collection)
    {
      return new UpdInsertAfterIntoCollection(pul, name, target, nodes, dyn_collection);
    }

    
    /***************************************************************************
    ***************************************************************************/
    UpdDeleteNodesFromCollection*
    PULPrimitiveFactory::createUpdDeleteNodesFromCollection(
          CollectionPul* pul,
          store::Item_t& name,
          std::vector<store::Item_t>& nodes,
          bool isLast,
          bool dyn_collection)
    {
      return new UpdDeleteNodesFromCollection(pul, name, nodes, isLast, dyn_collection);
    }

    
    /***************************************************************************
    ***************************************************************************/
    UpdCreateIndex*
    PULPrimitiveFactory::createUpdCreateIndex(
          PULImpl* pul,
          const store::Item_t& qname,
          const store::IndexSpecification& spec,
          store::Iterator* sourceIter)
    {
      return new UpdCreateIndex(pul, qname, spec, sourceIter);
    }

    
    /***************************************************************************
    ***************************************************************************/
    UpdDeleteIndex*
    PULPrimitiveFactory::createUpdDeleteIndex(PULImpl* pul, const store::Item_t& qname)
    {
      return new UpdDeleteIndex(pul, qname);
    }

    
    /***************************************************************************
    ***************************************************************************/
    UpdRefreshIndex*
    PULPrimitiveFactory::createUpdRefreshIndex(
          PULImpl* pul,
          const store::Item_t& qname,
          store::Iterator* sourceIter)
    {
      return new UpdRefreshIndex(pul, qname, sourceIter);
    }

    
    /***************************************************************************
    ***************************************************************************/
    UpdActivateIC*
    PULPrimitiveFactory::createUpdActivateIC(
          PULImpl* pul,
          const store::Item_t& aQName,
          const store::Item_t& aCollectionName)
    {
      return new UpdActivateIC(pul, aQName, aCollectionName);
    }
    

    /***************************************************************************
    ***************************************************************************/
    UpdActivateForeignKeyIC*
    PULPrimitiveFactory::createUpdActivateForeignKeyIC(
          PULImpl* pul,
          const store::Item_t& qQName,
          const store::Item_t& aFromCollectionName,
          const store::Item_t& aToCollectionName)
    {
      return new UpdActivateForeignKeyIC(pul, qQName, aFromCollectionName, aToCollectionName);
    }
    

    /***************************************************************************
    ***************************************************************************/
    UpdDeActivateIC*
    PULPrimitiveFactory::createUpdDeActivateIC(
        PULImpl* pul,
        const store::Item_t& qname)
    {
      return new UpdDeActivateIC(pul, qname);
    }


    /***************************************************************************
     ***************************************************************************/
    UpdCreateDocument*
    PULPrimitiveFactory::createUpdCreateDocument(
          PULImpl* pul,
          const store::Item_t& uri,
          store::Item_t& doc)
    {
      return new UpdCreateDocument(pul, uri, doc);
    }
    
    /***************************************************************************
     ***************************************************************************/
    UpdDeleteDocument*
    PULPrimitiveFactory::createUpdDeleteDocument(
          PULImpl* pul,
          const store::Item_t& uri)
   {
     return new UpdDeleteDocument(pul, uri);
   }

} /* namespace simplestore */ } /* namespace zorba */
