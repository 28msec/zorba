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

#include <cctype>
#include <unicode/unistr.h>

#define DEBUG_TOKENIZER 0
#if DEBUG_TOKENIZER
#include <iostream>
#endif

#include <zorba/error.h>

#include "util/stl_util.h"
#include "zorbaerrors/error_manager.h"
#include "zorbautils/icu_tokenizer.h"
#include "zorbautils/unicode_util.h"

using namespace std;
U_NAMESPACE_USE

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

namespace {

class token {
public:
  void append( char const *s, int slen ) {
    value_.append( s, slen );
  }

  void clear() {
    value_.clear();
  }

  bool empty() {
    return value_.empty();
  }

  void send_to( Tokenizer::Callback &callback ) {
    if ( !empty() ) {
#     if DEBUG_TOKENIZER
      cout << "TOKEN: \"" << value_ << "\"\n";
#     endif
      callback( value_.c_str(), value_.length(), pos_, sent_, para_ );
      clear();
    }
  }

  void set( char const *s, int slen, int pos, int sent, int para ) {
    clear();
    append( s, slen );
    pos_  = pos;
    sent_ = sent;
    para_ = para;
  }

private:
  string value_;
  int pos_, sent_, para_;
};

} // anonymous namespace

///////////////////////////////////////////////////////////////////////////////

icu_tokenizer::icu_tokenizer( bool wildcards ) : wildcards_( wildcards ) {
  UErrorCode status = U_ZERO_ERROR;

  // TODO: get actual locale
  word_it_ = BreakIterator_ptr(
    dynamic_cast<RuleBasedBreakIterator*>(
      BreakIterator::createWordInstance( Locale::getUS(), status )
    )
  );
  if ( U_FAILURE( status ) )
    ZORBA_ERROR( XQP0036_BREAKITERATOR_CREATION_FAILED );

  sent_it_ = BreakIterator_ptr(
    dynamic_cast<RuleBasedBreakIterator*>(
      BreakIterator::createSentenceInstance( Locale::getUS(), status )
    )
  );
  if ( U_FAILURE( status ) )
    ZORBA_ERROR( XQP0036_BREAKITERATOR_CREATION_FAILED );
}

///////////////////////////////////////////////////////////////////////////////

#define HANDLE_BACKSLASH()            \
  if ( !got_backslash ) ; else {      \
    got_backslash = in_wild = false;  \
    break;                            \
  }

#define IF_GOT_BACKSLASH_APPEND_AND_GOTO(GOTO)  \
  if ( !got_backslash ) ; else {                \
    t.append( utf8_buf.get(), utf8_len );       \
    got_backslash = false;                      \
    goto GOTO;                                  \
  }

#define IS_WORD_BREAK(TYPE,STATUS) \
  ( (STATUS) >= UBRK_WORD_##TYPE && (STATUS) < UBRK_WORD_##TYPE##_LIMIT )

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

  token t;

  // True only if the previous token was a backslash ('\').
  bool got_backslash = false;

  // True only if we're actually processing wildcard syntax (started by '.').
  bool in_wild = false;

  // True only if we're within braces (started by '{', ended by '}').
  bool in_brace = false;

  while ( word_end != BreakIterator::DONE ) {
    int32_t const utf16_len = word_end - word_start;
    int32_t utf8_len;
    auto_vec<char> const utf8_buf(
      utf16_to_utf8( utf16_buf.get() + word_start, utf16_len, &utf8_len )
    );
    int32_t const rule_status = word_it_->getRuleStatus();

    //
    // "Junk" tokens are whitespace and punctuation -- except some punctuation
    // isn't junk when we're tokenizing with XQuery wildcard syntax.
    //
    bool is_junk = false;

#   if DEBUG_TOKENIZER
    cout << "GOT: \"" << string( utf8_buf.get(), utf8_len ) << "\" ";
#   endif

    if ( IS_WORD_BREAK( NONE, rule_status ) ) {
      //
      // "NONE" tokens are what ICU calls whitespace and punctuation.
      //
#     if DEBUG_TOKENIZER
      cout << "(NONE)" << endl;
#     endif
      if ( wildcards_ ) {
        switch ( *utf8_buf ) {
          case '.':
            HANDLE_BACKSLASH();
            in_wild = true;
            goto set_token;
          case '\\':
            HANDLE_BACKSLASH();
            got_backslash = true;
            break;
          case '*':
          case '+':
          case '?':
          case '{':
            if ( in_brace )
              ZORBA_ERROR( FTDY0020 );
            HANDLE_BACKSLASH();
            if ( in_wild ) {
              in_brace = *utf8_buf == '{';
              goto set_token;
            }
            break;
          case '}':
            HANDLE_BACKSLASH();
            if ( in_brace ) {
              in_brace = false;
              goto set_token;
            }
            if ( in_wild )
              ZORBA_ERROR( FTDY0020 );
            break;
          default:
            in_wild = false;
        }
      }
      is_junk = true;
    }

    else if ( IS_WORD_BREAK( NUMBER, rule_status ) ) {
      //
      // "NUMBER" tokens are obviously for numbers.  Note that a sequence of
      // digits containing a ',' (e.g., "1,2") is considered a single token by
      // ICU.
      //
#     if DEBUG_TOKENIZER
      cout << "(NUMBER)" << endl;
#     endif
      IF_GOT_BACKSLASH_APPEND_AND_GOTO( next );
      if ( in_brace ) {
        //
        // Validate that the token matches the regex "[0-9]+,[0-9]+".
        //
        char const *c = utf8_buf.get();
        int i;
        for ( i = 0; i < utf8_len; ++i, ++c ) {
          if ( i && *c == ',' )
            break;
          if ( !isdigit( *c ) )
            ZORBA_ERROR( FTDY0020 );
        }
        if ( i == utf8_len || *c != ',' )
          ZORBA_ERROR( FTDY0020 );
        for ( ++i, ++c; i < utf8_len; ++i, ++c ) {
          if ( !isdigit( *c ) )
            ZORBA_ERROR( FTDY0020 );
        }
      }
    }

    else {
      //
      // "OTHER" tokens are for non-whitespace, non-digits, and non-numbers,
      // i.e., word tokens.
      //
#     if DEBUG_TOKENIZER
      cout << "(OTHER)" << endl;
#     endif
      if ( in_brace )
        ZORBA_ERROR( FTDY0020 );
      IF_GOT_BACKSLASH_APPEND_AND_GOTO( next );
    }

    if ( !in_wild && !got_backslash )
      t.send_to( callback );

set_token:
    if ( !is_junk ) {
      if ( in_wild || got_backslash )
        t.append( utf8_buf.get(), utf8_len );
      else
        t.set( utf8_buf.get(), utf8_len, token_no_++, sent_no_, para_no_ );
    }

next:
    word_start = word_end, word_end = word_it_->next();
    if ( word_end >= sent_end && sent_end != BreakIterator::DONE ) {
      sent_start = sent_end, sent_end = sent_it_->next();
      ++sent_no_;
    }
  } // while

  if ( in_brace )
    ZORBA_ERROR( FTDY0020 );
  t.send_to( callback );
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
