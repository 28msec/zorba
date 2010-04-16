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

#include "runtime/full_text/icu_tokenizer.h"

#if U_ICU_VERSION_MAJOR_NUM > 4 || \
   (U_ICU_VERSION_MAJOR_NUM == 4 && U_ICU_VERSION_MINOR_NUM >= 2)
# define HAVE_ICU_UnicodeString_FromUTF8 1
#endif

#ifndef HAVE_ICU_UnicodeString_FromUTF8
#include <memory>                       /* for auto_ptr */
#include <unicode/ustring.h>
#endif

using namespace std;
U_NAMESPACE_USE

namespace zorba {

icu_tokenizer::~icu_tokenizer() {
  delete word_it_;
  delete sent_it_;
}

BreakIterator* icu_tokenizer::get_word_it() const {
  if ( !word_it_ ) {
    UErrorCode err = U_ZERO_ERROR;
    // TODO: get actual locale
    word_it_ = BreakIterator::createWordInstance( Locale::getUS(), err );
    // TODO: check err
  }
  return word_it_;
}

BreakIterator* icu_tokenizer::get_sent_it() const {
  if ( !sent_it_ ) {
    UErrorCode err = U_ZERO_ERROR;
    // TODO: get actual locale
    sent_it_ = BreakIterator::createSentenceInstance( Locale::getUS(), err );
    // TODO: check err
  }
  return sent_it_;
}

void icu_tokenizer::tokenize( string const &utf8_text,
                              ft_tokens &result ) const {
#ifdef HAVE_ICU_UnicodeString_FromUTF8
  UnicodeString const utf16_text = UnicodeString::fromUTF8( utf8_text );
#else
  int32_t utf16_buflen;
  UChar32 const subchar = 0xFFFD;       // replacement character
  UErrorCode err = U_ZERO_ERROR;;

  u_strFromUTF8WithSub(
    NULL, 0, &utf16_buflen,             // determine ut16_buflen only
    utf8_text.c_str(), -1,
    subchar, NULL,
    &err
  );
  // TODO: check err

  auto_ptr<UChar> const utf16_buf( new UChar[ utf16_buflen ] );
  err = U_ZERO_ERROR;;
  u_strFromUTF8WithSub(
    utf16_buf.get(), utf16_buflen, NULL,
    utf8_text.c_str(), -1,
    subchar, NULL,
    &err
  );
  // TODO: check err

  UnicodeString const utf16_text( true, utf16_buf.get(), utf16_buflen );
#endif

  BreakIterator *const word_it = get_word_it();
  word_it->setText( utf16_text );
  for ( int32_t pos = word_it->first(); pos != BreakIterator::DONE;
        pos = word_it->next() ) {
    ft_token t;
    t.pos.start = t.pos.end = pos;
    t.para.start = t.para.end = para_no_;
    result.push_back( t );
  }

#if 0
  BreakIterator *const sent_it = get_sent_it();
  sent_it->setText( utf16_text );
  for ( int32_t sent = sent_it->first(); sent != BreakIterator::DONE;
        sent = sent_it->next() ) {
    // TODO
    t.sent.start = sent;
    t.sent.end = sent;
  }
#endif
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
