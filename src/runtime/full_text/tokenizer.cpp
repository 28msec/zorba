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

#include <zorba/item.h>
#include <zorba/iterator.h>
#include <zorba/store_consts.h>
#include <zorba/tokenizer.h>
#include <zorba/zorba_string.h>

#include "diagnostics/assert.h"
#include "store/api/store.h"
#include "system/globalenv.h"
#include "zorbamisc/ns_consts.h"
#include "zorbautils/locale.h"

using namespace zorba::locale;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

Tokenizer::~Tokenizer() {
  // out-of-line since it's virtual
}

bool Tokenizer::find_lang_attribute( Item const &item, iso639_1::type *lang ) {
  bool found_lang = false;
  if ( item.getNodeKind() == store::StoreConsts::elementNode ) {
    Iterator_t i( item.getAttributes() );
    i->open();
    for ( Item attr; i->next( attr ); ) {
      Item qname;
      if ( attr.getNodeName( qname ) &&
          qname.getLocalName() == "lang" && qname.getNamespace() == XML_NS ) {
        *lang = locale::find_lang( attr.getStringValue().c_str() );
        found_lang = true;
        break;
      }
    }
    i->close();
  }
  return found_lang;
}

void Tokenizer::item( Item const &item, bool entering ) {
  if ( entering && item.isNode() &&
       item.getNodeKind() == store::StoreConsts::elementNode ) {
    ++numbers().para;
  }
}

void Tokenizer::tokenize_node_impl( Item const &item, iso639_1::type lang,
                                    Callback &callback, bool tokenize_acp ) {
  if ( item.isNode() ) {
    Iterator_t i;
    Tokenizer *t_raw = this;
    Tokenizer::ptr t_ptr;

    this->item( item, true );
    callback.item( item, true );

    switch ( item.getNodeKind() ) {
      case store::StoreConsts::elementNode:
        if ( find_lang_attribute( item, &lang ) ) {
          TokenizerProvider const *const p = GENV_STORE.getTokenizerProvider();
          ZORBA_ASSERT( p );
          if ( !p->getTokenizer( lang, numbers_, &t_ptr ) )
            break;
          t_raw = t_ptr.get();
        }
        // no break;

      case store::StoreConsts::documentNode:
        i = item.getChildren();
        i->open();
        for ( Item child; i->next( child ); )
          t_raw->tokenize_node_impl( child, lang, callback, false );
        i->close();
        break;

      case store::StoreConsts::attributeNode:
      case store::StoreConsts::commentNode:
      case store::StoreConsts::piNode:
        if ( !tokenize_acp )
          break;
      case store::StoreConsts::textNode: {
        String const s( item.getStringValue() );
        tokenize_string( s.data(), s.size(), lang, false, callback, &item );
        break;
      }
    } // switch

    this->item( item, false );
    callback.item( item, false );
  }
}

Tokenizer::Numbers::Numbers() {
  token = para = 0;
  sent = 1;
}

Tokenizer::Callback::~Callback() {
  // out-of-line since it's virtual
}

void Tokenizer::Callback::item( Item const&, bool ) {
  // out-of-line since it's virtual
}

///////////////////////////////////////////////////////////////////////////////

TokenizerProvider::~TokenizerProvider() {
  // out-of-line since it's virtual
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
