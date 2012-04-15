/*
 * Copyright 2006-2010 The FLWOR Foundation.
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
#include <functional>

#include <zorba/diagnostic_list.h>

#include "diagnostics/dict.h"
#include "diagnostics/xquery_exception.h"

#include "latin_tokenizer.h"

using namespace std;
using namespace zorba::locale;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

void LatinTokenizer::destroy() const {
  delete this;
}

inline bool LatinTokenizer::is_word_begin_char( char c ) {
  return !!isalnum( c );
}

bool LatinTokenizer::is_word_char( char c ) {
  if ( t_type_ == t_integer ) {
    switch ( c ) {
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
        break;
      case ',':
      case '.':
        t_type_ = t_floating_point;
        break;
      case ':':
        t_type_ = t_time;
        break;
      default:
        t_type_ = t_generic;
    }
  }
  switch ( t_type_ ) {
    case t_floating_point:
      return isdigit( c ) || c == '.' || c == ',';
    case t_time:
      return isdigit( c ) || c == ':';
    default:
      return is_word_begin_char( c ) 
          || c == '&'                   // AT&T
          || c == '\''                  // men's
          || c == '-'                   // set-top
          || c == '_';                  // language_identifier
  }
}

inline char LatinTokenizer::peek( char const *s, char const *end ) {
  return ++s < end ? *s : '\0';
}

void LatinTokenizer::properties( Properties *p ) const {
  p->comments_separate_tokens = true;
  p->elements_separate_tokens = true;
  p->processing_instructions_separate_tokens = true;

  p->languages.clear();
  p->languages.push_back( iso639_1::en );

  p->uri = "http://www.zorba-xquery.com/full-text/tokenizer/latin";
}

#define HANDLE_BACKSLASH()            \
  if ( !got_backslash ) ; else {      \
    got_backslash = in_wild = false;  \
    break;                            \
  }

void LatinTokenizer::tokenize_string( char const *s, size_type s_len,
                                      iso639_1::type lang, bool wildcards,
                                      Callback &callback, Item const *item ) {
  bool got_backslash = false;
  bool in_wild = false;
  string_type token;

  t_type_ = t_generic;

  for ( char const *const end = s + s_len; s < end; ++s ) {
    if ( wildcards ) {
      switch ( *s ) {
        case '.':
          HANDLE_BACKSLASH();
          in_wild = true;
          break;
        case '\\':
          HANDLE_BACKSLASH();
          got_backslash = true;
          break;
        case '*':
        case '+':
        case '?':
          HANDLE_BACKSLASH();
          break;
        case '{':
          HANDLE_BACKSLASH();
          if ( in_wild ) {
            //
            // Validate that the regex "{[0-9]+,[0-9]+}" is matched.
            //
            bool got_comma = false;
            bool got_digit = false;
            while ( ++s < end ) {
              if ( got_digit && *s == ',' ) {
                got_comma = true;
                break;
              }
              if ( !isdigit( *s ) )
                throw XQUERY_EXCEPTION(
                  err::FTDY0020, ERROR_PARAMS( "", ZED( BadDecDigit_3 ), *s )
                );
              got_digit = true;
            }
            if ( !got_comma )
              throw XQUERY_EXCEPTION(
                err::FTDY0020, ERROR_PARAMS( "", ZED( CharExpected_3 ), ',' )
              );
            got_digit = false;
            while ( ++s < end ) {
              if ( *s == '}' ) {
                if ( !got_digit )
                  throw XQUERY_EXCEPTION(
                    err::FTDY0020, ERROR_PARAMS( "", ZED( BadDecDigit_3 ), *s )
                  );
                break;
              }
              if ( !isdigit( *s ) )
                throw XQUERY_EXCEPTION(
                  err::FTDY0020, ERROR_PARAMS( "", ZED( BadDecDigit_3 ), *s )
                );
              got_digit = true;
            }
          }
          break;
        default:
          in_wild = false;
      } // switch
    } // if ( wildcards )

    if ( token.empty() ) {
      if ( is_word_begin_char( *s ) ) {
        token += *s;
        if ( isdigit( *s ) )
          t_type_ = t_integer;
      }
    } else {
      if ( is_word_char( *s ) )
        token += *s;
      else if ( send_token( token, lang, callback, item ) ) {
        token.clear();
        t_type_ = t_generic;
      }
    }

    if ( !wildcards )
      switch ( *s ) {
        case '.':
          switch ( peek( s, end ) ) {
            //
            // A '.' ends a sentence only if it's immediately followed by one
            // of these characters.
            //
            case '"':
            case '\'':
            case ')':
            case ']':
            case '}':
            case ' ':
            case '\f':
            case '\n':
            case '\r':
            case '\t':
            case '\v':
              break;
            default:
              continue;
          }
          // no break;
        case '!':
        case '?':
          ++numbers().sent;
      }
  } // for

  send_token( token, lang, callback, item );
}

#define PRINT_TOKENS 0

bool LatinTokenizer::send_token( string_type const &token, iso639_1::type lang,
                                 Callback &callback, Item const *item ) {
  if ( !token.empty() ) {
#if PRINT_TOKENS
    cout <<   "t=" << setw(2) << numbers().token
         << ", s=" << setw(2) << numbers().sent
         << ", p=" << setw(2) << numbers().para
         << ": \"" << token << "\"\n";
#endif /* PRINT_TOKENS */

    callback(
      token.data(), token.size(), lang,
      numbers().token, numbers().sent, numbers().para, item
    );
    ++numbers().token;
    return true;
  }
  return false;
}

///////////////////////////////////////////////////////////////////////////////

Tokenizer::ptr
LatinTokenizerProvider::getTokenizer( iso639_1::type lang,
                                      Tokenizer::Numbers &num ) const {
  return Tokenizer::ptr( new LatinTokenizer( num ) );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
