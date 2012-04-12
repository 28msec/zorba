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

#include <zorba/config.h>

#ifndef ZORBA_NO_FULL_TEXT

#include "api/unmarshaller.h"
#include "diagnostics/assert.h"
#include "util/cxx_util.h"

#include "thesaurus_wrappers.h"

using namespace zorba::locale;

namespace zorba {
namespace internal {

///////////////////////////////////////////////////////////////////////////////

ThesaurusWrapper::iterator_wrapper::iterator_wrapper( api_iterator_ptr p ) :
  api_ptr_( std::move( p ) )
{
  ZORBA_ASSERT( api_ptr_.get() );
}

ThesaurusWrapper::iterator_wrapper::~iterator_wrapper() {
  // out-of-line since it's virtual
}

void ThesaurusWrapper::iterator_wrapper::destroy() const {
  delete this;
}

bool ThesaurusWrapper::iterator_wrapper::next( zstring *synonym ) {
  if ( api_ptr_.get() ) {
    String api_synonym;
    if ( api_ptr_->next( &api_synonym ) ) {
      *synonym = Unmarshaller::getInternalString( api_synonym );
      return true;
    }
  }
  return false;
}

ThesaurusWrapper::ThesaurusWrapper( zorba::Thesaurus::ptr p ) :
  api_thesaurus_( std::move( p ) )
{
  ZORBA_ASSERT( api_thesaurus_.get() );
}

ThesaurusWrapper::~ThesaurusWrapper() {
  // out-of-line since it's virtual
}

void ThesaurusWrapper::destroy() const {
  delete this;
}

ThesaurusWrapper::iterator::ptr
ThesaurusWrapper::lookup( zstring const &phrase, zstring const &relationship,
                          ft_int at_least, ft_int at_most ) const {
  String const api_phrase( Unmarshaller::newString( phrase ) );
  String const api_relationship( Unmarshaller::newString( relationship ) );
  api_iterator_ptr api_iter(
    api_thesaurus_->lookup( api_phrase, api_relationship, at_least, at_most )
  );
  iterator::ptr result(
    api_iter.get() ? new iterator_wrapper( std::move( api_iter ) ) : nullptr
  );
  return std::move( result );
}

///////////////////////////////////////////////////////////////////////////////

ThesaurusProviderWrapper::
ThesaurusProviderWrapper( zorba::ThesaurusProvider const *p ) :
  api_thesaurus_provider_( p )
{
  ZORBA_ASSERT( api_thesaurus_provider_ );
}

bool ThesaurusProviderWrapper::getThesaurus( iso639_1::type lang,
                                             Thesaurus::ptr *result ) const {
  zorba::Thesaurus::ptr api_ptr;
  zorba::Thesaurus::ptr *const api_ptr_ptr = result ? &api_ptr : nullptr;
  if ( api_thesaurus_provider_->getThesaurus( lang, api_ptr_ptr ) ) {
    if ( result )
      result->reset( new ThesaurusWrapper( std::move( api_ptr ) ) );
    return true;
  }
  return false;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace internal
} // namespace zorba

#endif /* ZORBA_NO_FULL_TEXT */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
