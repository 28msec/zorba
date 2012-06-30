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

#include "api/unmarshaller.h"
#include "context/static_context.h"
#include "store/api/item_factory.h"
#include "system/globalenv.h"

#include "ft_module_util.h"

using namespace std;
using namespace zorba::locale;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

void TokenizeNodesCallback::token( char const *utf8_s, size_type utf8_len,
                                   iso639_1::type lang, size_type token_no,
                                   size_type sent_no, size_type para_no,
                                   Item const *api_item ) {
  store::Item const *const item = Unmarshaller::getInternalItem( *api_item );
  tokens_->push_back(
    FTToken( utf8_s, utf8_len, token_no, sent_no, para_no, item )
  );
}

///////////////////////////////////////////////////////////////////////////////

TokenQNames::TokenQNames() {
  GENV_ITEMFACTORY->createQName(
    token, static_context::ZORBA_FULL_TEXT_FN_NS, "", "token"
  );
  GENV_ITEMFACTORY->createQName( lang, "", "", "lang" );
  GENV_ITEMFACTORY->createQName( paragraph, "", "", "paragraph" );
  GENV_ITEMFACTORY->createQName( sentence, "", "", "sentence" );
  GENV_ITEMFACTORY->createQName( value, "", "", "value" );
  GENV_ITEMFACTORY->createQName( node_ref, "", "", "node-ref" );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
