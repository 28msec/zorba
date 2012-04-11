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
#ifndef ZORBA_SIMPLESTORE_NODE_FACTORY_H
#define ZORBA_SIMPLESTORE_NODE_FACTORY_H

#include <vector>

#include "zorbamisc/config/platform.h"
#include "common/shared_types.h"

#include "shared_types.h"


namespace zorba 
{


namespace simplestore 
{
  class XmlTree;
  class XmlNode;
  class InternalNode;
  class DocumentNode;
  class ElementNode;
  class AttributeNode;
  class TextNode;
  class PiNode;
  class CommentNode;


/*******************************************************************************
  This class implements the Abstract Factory Pattern and is responsible for
  creating node items of the SimpleStore. Having a factory for node items
  allows other stores to derive from the node items of the SimpleStore without
  modifying a lot of code (e.g. of the loader). The class can only be
  instantiated by the SimpleStore.
********************************************************************************/
class NodeFactory 
{
 protected:
  // prevent instantion from anybody
  // except the SimpleStore and subclasses
  friend class SimpleStore;

  NodeFactory();
  
public:
  static NodeFactory& instance();

  virtual ~NodeFactory();
        
  virtual XmlTree* createXmlTree();

  virtual DocumentNode* createDocumentNode();

  virtual DocumentNode* createDocumentNode(
        XmlTree* tree,
        const zstring& baseUri,
        const zstring& docUri);

  virtual ElementNode* createElementNode(
        store::Item_t&  nodeName,
        ulong           numBindings,
        ulong           numAttributes);

  virtual ElementNode* createElementNode(
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
        zstring&                    baseUri);

  virtual AttributeNode* createAttributeNode(
        store::Item_t&  qname);

  virtual AttributeNode* createAttributeNode(
        XmlTree*         tree,
        ElementNode*     parent,
        bool             append,
        csize            pos,
        store::Item_t&   attrName,
        store::Item_t&   typeName,
        store::Item_t&   typedValue,
        bool             isListValue,
        bool             hidden);

  virtual TextNode* createTextNode(zstring& content);

  virtual TextNode* createTextNode(
        XmlTree*       tree,
        InternalNode*  parent,
        bool           append,
        csize          pos,
        zstring&       content);

  virtual TextNode* createTextNode(
        InternalNode*     parent,
        store::Item_t&    content,
        bool              isListValue);

  virtual PiNode* createPiNode(
        zstring& target,
        zstring& content);

  virtual PiNode* createPiNode(
        XmlTree*      tree,
        InternalNode* parent,
        bool          append,
        csize         pos,
        zstring&      target,
        zstring&      content);

  virtual CommentNode* createCommentNode(
        zstring& content);

  virtual CommentNode* createCommentNode(
        XmlTree*      tree,
        InternalNode* parent,
        bool          append,
        csize         pos,
        zstring&      content);
}; /* class NodeFactory */


} /* namespace simplestore */

} /* namespace zorba */

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
