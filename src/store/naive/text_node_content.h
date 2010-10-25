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

#include "store/api/item.h"

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
    void          * text;
    store::Item   * value;
  }
  theContent;

public:
  TextNodeContent() 
  {
    theContent.value = NULL;
  }

  ~TextNodeContent()
  {
    assert(theContent.value == NULL);
  }

  const zstring& getText() const
  {
    return *reinterpret_cast<const zstring*>(this);
  }

  void setText(zstring& text)
  {
    reinterpret_cast<zstring*>(this)->take(text);
  }

  void setText(TextNodeContent& other)
  {
    reinterpret_cast<zstring*>(this)->
    take(*reinterpret_cast<zstring*>(&other));
  }

  void copyText(const zstring& text)
  {
    *reinterpret_cast<zstring*>(this) = text;
  }

  void destroyText()
  {
    (*reinterpret_cast<zstring*>(this)).~zstring();
    theContent.text = NULL;
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

private:
  TextNodeContent(const TextNodeContent& other);
  TextNodeContent& operator=(const TextNodeContent& other);
};


}
}

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
