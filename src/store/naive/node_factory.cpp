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

#include "store/naive/node_factory.h"
#include "store/naive/node_items.h"
#include "store/naive/simple_store.h"
#include "store/naive/store_defs.h"

namespace zorba 
{

namespace simplestore 
{


NodeFactory& NodeFactory::instance()
{
  return GET_STORE().getNodeFactory();
}


NodeFactory::NodeFactory() 
{
}


NodeFactory::~NodeFactory() 
{ 
}
      

XmlTree* NodeFactory::createXmlTree()
{
  return new XmlTree(NULL, GET_STORE().createTreeId());
}


DocumentNode* NodeFactory::createDocumentNode()
{
  return new DocumentNode();  
}


DocumentNode* NodeFactory::createDocumentNode(
    XmlTree* tree,
    const zstring& baseUri,
    const zstring& docUri)
{
  return new DocumentNode(tree, baseUri, docUri);
}
  

ElementNode* NodeFactory::createElementNode(
    store::Item_t&  nodeName,
    ulong           numBindings,
    ulong           numAttributes)
{
  return new ElementNode(nodeName, numBindings, numAttributes);
}


ElementNode* NodeFactory::createElementNode(
    XmlTree*                    tree,
    InternalNode*               parent,
    bool                        append,
    csize                       pos,
    store::Item_t&              nodeName,
    store::Item_t&              typeName,
    bool                        haveTypedValue,
    bool                        haveEmptyValue,
    bool                        isInSubstGroup,
    const store::NsBindings*    localBindings,
    zstring&                    baseUri)
{
  return new ElementNode(tree, parent, append, pos, nodeName, typeName,
                         haveTypedValue, haveEmptyValue, isInSubstGroup,
                         localBindings, baseUri);
}
  
  
AttributeNode* NodeFactory::createAttributeNode(
    store::Item_t&  qname)
{
  return new AttributeNode(qname);
}
  
  
AttributeNode* NodeFactory::createAttributeNode(
    XmlTree*                    tree,
    ElementNode*                parent,
    bool                        append,
    csize                       pos,
    store::Item_t&              attrName,
    store::Item_t&              typeName,
    store::Item_t&              typedValue,
    bool                        isListValue,
    bool                        hidden)
{
  return new AttributeNode(tree, parent, append, pos, attrName,
                           typeName, typedValue, isListValue, hidden);
}
  
  
TextNode* NodeFactory::createTextNode(zstring& content)
{
  return new TextNode(content);
}


TextNode* NodeFactory::createTextNode(
    XmlTree*          tree,
    InternalNode*     parent,
    bool              append,
    csize             pos,
    zstring&          content)
{
  return new TextNode(tree, parent, append, pos, content);
}


TextNode* NodeFactory::createTextNode(
    InternalNode*     parent,
    store::Item_t&    content,
    bool              isListValue)
{
  return new TextNode(parent, content, isListValue);
}


PiNode* NodeFactory::createPiNode(
    zstring& target,
    zstring& content)
{
  return new PiNode(target, content);
}
  
  
PiNode* NodeFactory::createPiNode(
    XmlTree*      tree,
    InternalNode* parent,
    bool          append,
    csize         pos,
    zstring&      target,
    zstring&      content)
{
  return new PiNode(tree, parent, append, pos, target, content);
}
  
  
CommentNode* NodeFactory::createCommentNode(
    zstring& content)
{
  return new CommentNode(content);
}


CommentNode* NodeFactory::createCommentNode(
    XmlTree*      tree,
    InternalNode* parent,
    bool          append,
    csize         pos,
    zstring&      content)
{
  return new CommentNode(tree, parent, append, pos, content);
}
  

} /* namespace simplestore */

} /* namespace store */
/* vim:set et sw=2 ts=2: */
