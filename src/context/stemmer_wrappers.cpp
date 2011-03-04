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

#include <zorba/config.h>

#ifndef ZORBA_NO_FULL_TEXT

#include "stemmer_wrappers.h"
#include "api/unmarshaller.h"
#include "zorbaerrors/Assert.h"

using namespace zorba::locale;

namespace zorba {
namespace core {

///////////////////////////////////////////////////////////////////////////////

StemmerWrapper::StemmerWrapper( zorba::Stemmer const *s ) :
  api_stemmer_( s )
{
  ZORBA_ASSERT( api_stemmer_ );
}

void StemmerWrapper::stem( zstring const &word, zstring *result ) const {
  String const api_word( Unmarshaller::newString( word ) );
  String api_result( Unmarshaller::newString( *result ) );
  api_stemmer_->stem( api_word, &api_result );
}

///////////////////////////////////////////////////////////////////////////////

StemmerProviderWrapper::
StemmerProviderWrapper( zorba::StemmerProvider const *p ) :
  api_stemmer_provider_( p )
{
  ZORBA_ASSERT( api_stemmer_provider_ );
}

Stemmer const*
StemmerProviderWrapper::get_stemmer( iso639_1::type lang ) const {
  zorba::Stemmer const *const s = api_stemmer_provider_->getStemmer( lang );
  return s ? new StemmerWrapper( s ) : 0;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace core
} // namespace zorba

#endif /* ZORBA_NO_FULL_TEXT */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
