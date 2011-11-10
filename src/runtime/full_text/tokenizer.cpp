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

using namespace zorba::locale;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

Tokenizer::Tokenizer( Numbers &no, int trace_options ) :
  trace_options_( trace_options ),
  no_( &no )
{
}

Tokenizer::~Tokenizer() {
  // out-of-line since it's virtual
}

void Tokenizer::element( Item const&, int ) {
  // do nothing
}

void Tokenizer::tokenize_node( Item const &item, iso639_1::type lang,
                               Callback &callback ) {
  tokenize_node_impl( item, lang, callback, true );
}

void Tokenizer::tokenize_node_impl( Item const &item, iso639_1::type lang,
                                    Callback &callback, bool tokenize_acp ) {
  if ( item.isNode() ) {
    switch ( item.getNodeKind() ) {
      case store::StoreConsts::documentNode:
      case store::StoreConsts::elementNode: {
        Iterator_t i( item.getChildren() );
        i->open();
        for ( Item child; i->next( child ); )
          tokenize_node_impl( child, lang, callback, false );
        i->close();
        break;
      }
      case store::StoreConsts::attributeNode:
      case store::StoreConsts::commentNode:
      case store::StoreConsts::piNode:
        if ( !tokenize_acp )
          break;
      case store::StoreConsts::textNode: {
        String const s( item.getStringValue() );
        tokenize_string( s.data(), s.size(), lang, false, callback );
        break;
      }
    }
  }
}

Tokenizer::Numbers::Numbers() {
  token = para = 0;
  sent = 1;
}

Tokenizer::Callback::~Callback() {
  // out-of-line since it's virtual
}

///////////////////////////////////////////////////////////////////////////////

TokenizerProvider::~TokenizerProvider() {
  // out-of-line since it's virtual
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
