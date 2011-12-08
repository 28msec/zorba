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

#include <cctype>
#include <unicode/unistr.h>

#define DEBUG_TOKENIZER 0
#if DEBUG_TOKENIZER
#include <iostream>
#endif /* DEBUG_TOKENIZER */

#include <zorba/diagnostic_list.h>
#include <zorba/internal/unique_ptr.h>

#include "diagnostics/assert.h"
#include "diagnostics/dict.h"
#include "diagnostics/xquery_exception.h"
#include "diagnostics/zorba_exception.h"
#include "util/ascii_util.h"
#include "util/cxx_util.h"
#include "util/stl_util.h"
#include "util/unicode_util.h"
#include "util/utf8_util.h"
#include "zorbautils/locale.h"
#include "zorbautils/mutex.h"

#include "icu_tokenizer.h"

using namespace std;
U_NAMESPACE_USE
using namespace zorba::locale;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

namespace {

class temp_token {
public:
  typedef Tokenizer::size_type size_type;

  void append( char const *s, size_type slen ) {
    value_.append( s, slen );
  }

  void clear() {
    value_.clear();
  }

  bool empty() {
    return value_.empty();
  }

  void send( void *payload, Tokenizer::Callback &callback ) {
    if ( !empty() ) {
#     if DEBUG_TOKENIZER
      cout << "TOKEN: \"" << value_ << "\" (" << pos_ << ',' << sent_ << ',' << para_ << ")\n";
#     endif
      callback( value_.data(), value_.size(), pos_, sent_, para_, payload );
      clear();
    }
  }

  void set( char const *s, size_type slen, size_type pos, size_type sent,
            size_type para ) {
    clear();
    append( s, slen );
    pos_  = pos;
    sent_ = sent;
    para_ = para;
  }

private:
  string value_;
  size_type pos_, sent_, para_;
};

} // anonymous namespace

///////////////////////////////////////////////////////////////////////////////

/**
 * For a given language, get its corresponding ICU Locale.
 *
 * @param lang The language to get the ICU locale for.
 * @return Returns said Locale.
 */
static Locale const& get_icu_locale_for( iso639_1::type lang ) {
  typedef map<iso639_1::type,Locale> locale_cache_t;
  static locale_cache_t locale_cache;
  static Mutex mutex;

  if ( lang == iso639_1::unknown )
    lang = get_host_lang();

  AutoMutex const lock( &mutex );

  locale_cache_t::const_iterator const i = locale_cache.find( lang );
  if ( i != locale_cache.end() )
    return i->second;

  iso3166_1::type const country_code = get_host_country();
  char const *const country = country_code != iso3166_1::unknown ?
    iso3166_1::string_of[ country_code ] : nullptr;
  Locale &icu_locale = locale_cache[ lang ];
  icu_locale = Locale( iso639_1::string_of[ lang ], country );
  return icu_locale;
}

///////////////////////////////////////////////////////////////////////////////

ICU_Tokenizer::ICU_Tokenizer( iso639_1::type lang, Numbers &no ) :
  Tokenizer( no ),
  lang_( lang )
{
  Locale const &icu_locale = get_icu_locale_for( lang );
  UErrorCode status = U_ZERO_ERROR;

  word_it_.reset(
    dynamic_cast<RuleBasedBreakIterator*>(
      BreakIterator::createWordInstance( icu_locale, status )
    )
  );
  if ( U_FAILURE( status ) )
    throw ZORBA_EXCEPTION( zerr::ZXQP0036_BREAKITERATOR_CREATION_FAILED );

  sent_it_.reset(
    dynamic_cast<RuleBasedBreakIterator*>(
      BreakIterator::createSentenceInstance( Locale::getUS(), status )
    )
  );
  if ( U_FAILURE( status ) )
    throw ZORBA_EXCEPTION( zerr::ZXQP0036_BREAKITERATOR_CREATION_FAILED );
}

ICU_Tokenizer::~ICU_Tokenizer() {
  // out-of-line since it's virtual
}

///////////////////////////////////////////////////////////////////////////////

void ICU_Tokenizer::destroy() const {
  delete this;
}

#define HANDLE_BACKSLASH()            \
  if ( !got_backslash ) ; else {      \
    got_backslash = in_wild = false;  \
    break;                            \
  }

#define IF_GOT_BACKSLASH_APPEND_AND_GOTO(GOTO)  \
  if ( !got_backslash ) ; else {                \
    t.append( utf8_buf, utf8_len );             \
    got_backslash = false;                      \
    goto GOTO;                                  \
  }

#define IS_WORD_BREAK(TYPE,STATUS) \
  ( (STATUS) >= UBRK_WORD_##TYPE && (STATUS) < UBRK_WORD_##TYPE##_LIMIT )

void ICU_Tokenizer::tokenize( char const *utf8_s, size_type utf8_len,
                              iso639_1::type lang, bool wildcards,
                              Callback &callback, void *payload ) {
  ZORBA_ASSERT( lang == lang_ );

  unicode::char_type *utf16_buf;
  unicode::size_type utf16_len;
  if ( !unicode::to_string( utf8_s, (unicode::size_type)utf8_len, &utf16_buf, &utf16_len ) ) {
    // TODO
  }
  unique_ptr<unicode::char_type[]> const auto_utf16_buf( utf16_buf );

  //
  // ICU bizarrely treats newline and carriage-return as sentence terminators
  // so convert all non-space whitespace characters to space characters.
  //
  unicode::char_type *c = utf16_buf;
  for ( int i = 0; i < utf16_len; ++i, ++c ) {
    if ( u_isspace( *c ) )
      *c = L' ';
  }

  // This unicode::string wraps the existing buffer: no copy is made.
  unicode::string const utf16_s( false, utf16_buf, utf16_len );

  word_it_->setText( utf16_s );
  unicode::size_type word_start = word_it_->first();
  unicode::size_type word_end   = word_it_->next();

  sent_it_->setText( utf16_s );
  unicode::size_type sent_end = sent_it_->first(); sent_end = sent_it_->next();

  temp_token t;

  // True only if the previous token was a backslash ('\').
  bool got_backslash = false;

  // True only if we're actually processing wildcard syntax (started by '.').
  bool in_wild = false;

  // True only if we're within braces (started by '{', ended by '}').
  bool in_brace = false;

  while ( word_end != BreakIterator::DONE ) {
    unicode::char_type const *const word = utf16_buf + word_start;
    unicode::size_type const word_len = word_end - word_start;

    utf8::storage_type *utf8_buf;
    utf8::size_type utf8_len;
    if ( !utf8::to_string( word, word_len, &utf8_buf, &utf8_len ) ) {
      // TODO
    }
    unique_ptr<utf8::storage_type[]> const auto_utf8_buf( utf8_buf );

    zstring_b utf8_word; // used only for debugging & error reporting
    utf8_word.wrap_memory( utf8_buf, utf8_len );
#   if DEBUG_TOKENIZER
    cout << "GOT: \"" << utf8_word << "\" ";
#   endif

    //
    // "Junk" tokens are whitespace and punctuation -- except some punctuation
    // isn't junk when we're tokenizing with XQuery wildcard syntax.
    //
    bool is_junk = false;

    int32_t const rule_status = word_it_->getRuleStatus();
    if ( IS_WORD_BREAK( NONE, rule_status ) ) {
      //
      // "NONE" tokens are what ICU calls whitespace and punctuation.
      //
#     if DEBUG_TOKENIZER
      cout << "(NONE)" << endl;
#     endif
      if ( wildcards ) {
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
              throw XQUERY_EXCEPTION(
                err::FTDY0020,
                ERROR_PARAMS( "", ZED( BadCharInBraces_3 ), *utf8_buf  )
              );
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
              throw XQUERY_EXCEPTION(
                err::FTDY0020,
                ERROR_PARAMS( "", ZED( ClosingBraceWithoutOpen ) )
              );
            break;
          default:
            in_wild = false;
        }
      } // if ( wildcards )
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
        utf8::storage_type const *c = utf8_buf;
        utf8::size_type i;
        for ( i = 0; i < utf8_len; ++i, ++c ) {
          if ( i && *c == ',' )
            break;
          if ( !ascii::is_digit( *c ) )
            throw XQUERY_EXCEPTION(
              err::FTDY0020, ERROR_PARAMS( "", ZED( BadDecDigit_3 ), *c )
            );
        }
        if ( i == utf8_len || *c != ',' )
          throw XQUERY_EXCEPTION(
            err::FTDY0020, ERROR_PARAMS( "", ZED( CharExpected_3 ), ',' )
          );
        for ( ++i, ++c; i < utf8_len; ++i, ++c ) {
          if ( !ascii::is_digit( *c ) )
            throw XQUERY_EXCEPTION(
              err::FTDY0020, ERROR_PARAMS( "", ZED( BadDecDigit_3 ), *c )
            );
        }
      }
    }

    else /* if ( IS_WORD_BREAK( OTHER, rule_status ) ) */ {
      //
      // "OTHER" tokens are for non-whitespace, non-punctuation, and
      // non-numbers, i.e., word tokens.
      //
#     if DEBUG_TOKENIZER
      cout << "(OTHER)" << endl;
#     endif
      if ( in_brace )
        throw XQUERY_EXCEPTION(
          err::FTDY0020,
          ERROR_PARAMS( "", ZED( BadTokenInBraces_3 ), utf8_word )
        );
      IF_GOT_BACKSLASH_APPEND_AND_GOTO( next );
    }

    if ( !in_wild && !got_backslash )
      t.send( payload, callback );

set_token:
#   if DEBUG_TOKENIZER
    cout << "at set_token" << endl;
#   endif
    if ( !is_junk ) {
      if ( in_wild || got_backslash )
        t.append( utf8_buf, utf8_len );
      else {
#       if DEBUG_TOKENIZER
        cout << "setting token" << endl;
#       endif
        t.set(
          utf8_buf, utf8_len, numbers().token, numbers().sent, numbers().para
        );
        ++numbers().token;
      }
    }

next:
#   if DEBUG_TOKENIZER
    cout << "at next" << endl;
#   endif
    word_start = word_end, word_end = word_it_->next();
    if ( word_end >= sent_end && sent_end != BreakIterator::DONE ) {
      sent_end = sent_it_->next();
      // The addition of the "if" fixes:
      // https://bugs.launchpad.net/bugs/863320
#if 0
      if ( sent_end != BreakIterator::DONE )
#endif
        ++numbers().sent;
    }
  } // while

  if ( in_brace )
    throw XQUERY_EXCEPTION(
      err::FTDY0020, ERROR_PARAMS( "", ZED( UnbalancedChar_3 ), '}' )
    );
  t.send( payload, callback );
  // Incrementing "sent" here fixes:
  // https://bugs.launchpad.net/bugs/897800
#if 0
  ++numbers().sent;
#endif
#if DEBUG_TOKENIZER
  cout << "--------------------\n";
#endif /* DEBUG_TOKENIZER */
}

///////////////////////////////////////////////////////////////////////////////

Tokenizer::ptr
ICU_TokenizerProvider::getTokenizer( iso639_1::type lang,
                                     Tokenizer::Numbers &no ) const {
  return Tokenizer::ptr( new ICU_Tokenizer( lang, no ) );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
