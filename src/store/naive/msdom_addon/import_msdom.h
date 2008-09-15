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

#ifndef ZORBA_SIMPLE_STORE_IMPORT_MSDOM_NODE_ITEMS
#define ZORBA_SIMPLE_STORE_IMPORT_MSDOM_NODE_ITEMS

#include <windows.h>
#include <msxml.h>
#include <stack>

#include "common/shared_types.h"
#include "store/naive/msdom_addon/msdom_node_items.h"
#include "store/api/item_factory.h"

namespace zorba 
{ 
namespace simplestore 
{

//load MS DOM tree into simple store internal format
class ImportMSDOM
{
  //SimpleXmlLoader   simple_loader;
  store::ItemFactory *theFactory;
  XmlTree   *xmlTree;
  XmlNode   *rootNode;
  std::stack<XmlNode*>    elem_stack;
  xqpStringStore_t  theDocUri;
  xqpStringStore_t  theBaseUri;

public:
  ImportMSDOM( store::ItemFactory *factory);
  ~ImportMSDOM();

  static char *fromBSTR(BSTR inbstr);

  rchandle<XmlNode>   importMSDOM(IXMLDOMNode* domNode,
                              xqpStringStore_t docUri,
                              xqpStringStore_t baseUri);
protected:
  bool import_node(IXMLDOMNode *domNode);
  void import_document(IXMLDOMDocument *dom_doc, IXMLDOMDocumentFragment *dom_frag);
  void end_document();
  bool import_element(IXMLDOMElement *dom_elem);
  bool end_element();
  bool import_characters(IXMLDOMText *dom_text, bool is_cdata);
  bool import_pi(IXMLDOMProcessingInstruction *dom_pi);
  bool import_comment(IXMLDOMComment *dom_comment);
};


class CMyBSTR
{
  BSTR  internal_bstr;
public:
  CMyBSTR(const char* str);
  ~CMyBSTR();

  operator BSTR();
};

} // namespace simplestore
} // namespace zorba

#endif