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

#include <cstring>                      /* for memset(3) */

#include "shared_types.h"

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
    char        text[ sizeof( zstring ) ];
    store::Item *value;
  }
  theContent;

  static zstring* string_of( TextNodeContent const &tnc ) {
    return const_cast<zstring*>(
      reinterpret_cast<zstring const*>( tnc.theContent.text )
    );
  }

  zstring* this_string() {
    return string_of( *this );
  }

  zstring const* this_string() const {
    return string_of( *this );
  }

public:
  TextNodeContent() 
  {
    std::memset( &theContent, 0, sizeof( theContent ) );
  }

  ~TextNodeContent()
  {
    assert(theContent.value == NULL);
  }

  const zstring& getText() const
  {
    return *this_string();
  }

  void setText(zstring& text)
  {
    this_string()->take( text );
  }

  void setText(TextNodeContent& other)
  {
    this_string()->take( *string_of( other ) );
  }

  void copyText(const zstring& text)
  {
    *this_string() = text;
  }

  void destroyText()
  {
    this_string()->~zstring();
    std::memset( &theContent, 0, sizeof( theContent ) );
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
      theContent.value->removeReference();

    theContent.value = val.release();
  }

  void setValue(store::Item* val)
  {
    if (theContent.value != NULL)
      theContent.value->removeReference();

    theContent.value = val;
  }

  void copyValue(store::Item* val)
  {
    if (theContent.value != NULL)
      theContent.value->removeReference();

    theContent.value = val;

    if (val)
      theContent.value->addReference();
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
/* vim:set et sw=2 ts=2: */
