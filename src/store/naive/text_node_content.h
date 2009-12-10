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
#ifndef ZORBA_SIMPLE_STORE_TEXT_NODE_CONTENT
#define ZORBA_SIMPLE_STORE_TEXT_NODE_CONTENT


#include "store/naive/shared_types.h"

namespace zorba 
{ 

namespace simplestore 
{

/*******************************************************************************
  A helper class to model the content of text nodes, which can be either a
  string or an item representing an atomic value or a sequence of atomic values.
********************************************************************************/
class TextNodeContent
{
private:
  union
  {
    xqpStringStore  * text;
    store::Item     * value;
  }
  theContent;

public:
  TextNodeContent() 
  {
    theContent.text = NULL;
  }

  ~TextNodeContent()
  {
    assert(theContent.text == NULL);
  }

  xqpStringStore* getText() const
  {
    return theContent.text;
  }

  xqpStringStore* releaseText()
  {
    xqpStringStore* tmp = theContent.text;
    theContent.text = NULL;
    return tmp; 
  }

  void setText(xqpStringStore_t& text)
  {
    if (theContent.text != NULL)
      theContent.text->removeReference(NULL
                                       SYNC_PARAM2(theContent.text->getRCLock()));

    theContent.text = text.release();
  }

  void setText(xqpStringStore* text)
  {
    if (theContent.text != NULL)
      theContent.text->removeReference(NULL
                                       SYNC_PARAM2(theContent.text->getRCLock()));

    theContent.text = text;
  }

  void copyText(xqpStringStore* text)
  {
    if (theContent.text != NULL)
      theContent.text->removeReference(NULL
                                       SYNC_PARAM2(theContent.text->getRCLock()));

    theContent.text = text;

    if (text)
      theContent.text->addReference(NULL
                                    SYNC_PARAM2(theContent.text->getRCLock()));
  }


  store::Item* getValue() const
  {
    return theContent.value; 
  }

  store::Item* releaseValue()
  {
    store::Item* tmp = theContent.value;
    theContent.value = NULL;
    return tmp; 
  }

  void setValue(store::Item_t& val)
  {
    if (theContent.value != NULL)
      theContent.value->removeReference(
                                NULL
                                SYNC_PARAM2(theContent.value->getRCLock()));

    theContent.value = val.release();
  }

  void setValue(store::Item* val)
  {
    if (theContent.value != NULL)
      theContent.value->removeReference(
                                NULL
                                SYNC_PARAM2(theContent.value->getRCLock()));

    theContent.value = val;
  }

  void copyValue(store::Item* val)
  {
    if (theContent.value != NULL)
      theContent.value->removeReference(NULL
                                        SYNC_PARAM2(theContent.value->getRCLock()));

    theContent.value = val;

    if (val)
      theContent.value->addReference(NULL
                                     SYNC_PARAM2(theContent.value->getRCLock()));
  }
};


}
}

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
