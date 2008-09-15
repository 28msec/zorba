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

#include <simplestore/msdom/import.h>
#include "api/unmarshaller.h"
#include "store/naive/store_defs.h"
#include "store/naive/simple_store.h"

namespace zorba { 

namespace simplestore {

/*******************************************************************************
  Export the Microsoft DOM tree representation of a Node Item.
  Exporting MS DOM tree is valid only for the MS DOM store.
  Compile the simple store with ZORBA_STORE_MSDOM in order to use this feature on Windows machines.
  For atomic items it returns NULL.

  This function redirects to Simple Store implementation.
********************************************************************************/
IXMLDOMNode   *MSDOM2SimpleStore::exportItemAsMSDOM(zorba::Item it)
{
  store::Item_t   store_item = Unmarshaller::getInternalItem(it);
  return GET_STORE().exportItemAsMSDOM(store_item);
}

/*******************************************************************************
  Import a Microsoft DOM tree into the store as a xml document.
  This function is equivalent with loadDocument,  only that it loads the xml from an existing MS DOM tree.
  The existing MS DOM is kept unchanged at import time.
  Further updates on the document are reflected into the original MS DOM tree.
  Compile the simple store with ZORBA_STORE_MSDOM in order to use this feature on Windows machines.

  This function redirects to Simple Store implementation.
*******************************************************************************/
zorba::Item  MSDOM2SimpleStore::importMSDOM(IXMLDOMNode* domNode,
                          String docUri,
                          String baseUri)
{
  return Item(GET_STORE().importMSDOM(domNode, 
                                  Unmarshaller::getInternalString(docUri),
                                  Unmarshaller::getInternalString(baseUri)));
}

}
}
