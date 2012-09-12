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

#include <stdexcept>

#include "diagnostics/xquery_diagnostics.h"
#include "zorbamisc/ns_consts.h"
#include "zorbatypes/numconversions.h"
#include "zorbautils/locale.h"

#include "ft_util.h"

using namespace zorba::locale;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

bool find_lang_attribute( store::Item const &item, iso639_1::type *lang ) {
  bool found_lang = false;
  if ( item.getNodeKind() == store::StoreConsts::elementNode ) {
    store::Iterator_t i( item.getAttributes() );
    i->open();
    for ( store::Item_t attr; i->next( attr ); ) {
      store::Item const *const qname = attr->getNodeName();
      if ( qname &&
           qname->getLocalName() == "lang" &&
           qname->getNamespace() == XML_NS ) {
        *lang = locale::find_lang( attr->getStringValue().c_str() );
        found_lang = true;
        break;
      }
    }
    i->close();
  }
  return found_lang;
}

ft_int to_ft_int( xs_integer const &i ) {
  try {
    return to_xs_unsignedInt( i );
  }
  catch ( std::invalid_argument const& ) {  // for negative numbers
    throw XQUERY_EXCEPTION( err::FOCA0003, ERROR_PARAMS( i.toString() ) );
  }
  catch ( std::range_error const& ) {
    throw XQUERY_EXCEPTION( err::FOCA0003, ERROR_PARAMS( i.toString() ) );
  }
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
