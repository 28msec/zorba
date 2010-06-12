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

#include <unicode/unistr.h>
#include <zorba/error.h>

#include "util/stl_util.h"
#include "zorbaerrors/error_manager.h"
#include "zorbautils/icu_tokenizer.h"
#include "zorbautils/unicode_util.h"

using namespace std;
U_NAMESPACE_USE

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

icu_tokenizer::icu_tokenizer() {
  UErrorCode err = U_ZERO_ERROR;

  // TODO: get actual locale
  word_it_ = BreakIterator_ptr(
    dynamic_cast<RuleBasedBreakIterator*>(
      BreakIterator::createWordInstance( Locale::getUS(), err )
    )
  );
  if ( U_FAILURE( err ) )
    ZORBA_ERROR( XQP0036_BREAKITERATOR_CREATION_FAILED );

  sent_it_ = BreakIterator_ptr(
    dynamic_cast<RuleBasedBreakIterator*>(
      BreakIterator::createSentenceInstance( Locale::getUS(), err )
    )
  );
  if ( U_FAILURE( err ) )
    ZORBA_ERROR( XQP0036_BREAKITERATOR_CREATION_FAILED );
}

///////////////////////////////////////////////////////////////////////////////

void icu_tokenizer::tokenize( char const *utf8_s, int utf8_len,
                              Callback &callback ) {
  int32_t utf16_len;
  auto_vec<UChar> const utf16_buf(
    utf8_to_utf16( utf8_s, utf8_len, &utf16_len )
  );

  // This UnicodeString wraps the existing buffer: no copy is made.
  UnicodeString const utf16_s( false, utf16_buf.get(), utf16_len );

  word_it_->setText( utf16_s );
  int32_t word_start = word_it_->first(), word_end = word_it_->next();

  sent_it_->setText( utf16_s );
  int32_t sent_start = sent_it_->first(), sent_end = sent_it_->next();

  while ( word_end != BreakIterator::DONE ) {
    if ( word_it_->getRuleStatus() != UBRK_WORD_NONE ) {
      int32_t const utf16_len = word_end - word_start;
      int32_t utf8_len;
      auto_vec<char> const utf8_buf(
        utf16_to_utf8( utf16_buf.get() + word_start, utf16_len, &utf8_len )
      );
      callback( utf8_buf.get(), utf8_len, token_no_++, sent_no_, para_no_ );
    }
    word_start = word_end, word_end = word_it_->next();
    if ( word_end >= sent_end && sent_end != BreakIterator::DONE ) {
      sent_start = sent_end, sent_end = sent_it_->next();
      ++sent_no_;
    }
  }
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
