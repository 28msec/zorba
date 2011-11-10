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

#include <util/ascii_util.h>
#include <util/cxx_util.h>
#include <util/mmap_file.h>
#include <util/stl_util.h>
#include <util/uri_util.h>
#include <context/static_context.h>
#include <context/uri_resolver.h>
#include <zorbautils/locale.h>

#include "ft_stop_words_set.h"

using namespace std;
using namespace zorba::locale;

namespace zorba {

typedef char const *const *ft_stop_table;

////////// Helper functions ///////////////////////////////////////////////////

#define LANG(CODE)                                \
  iso639_1::CODE:                                 \
    extern char const *const stop_words_##CODE[]; \
    return stop_words_##CODE

static ft_stop_table get_table_for( iso639_1::type lang ) {
  switch ( lang ) {
    case LANG(da);
    case LANG(de);
    case LANG(en);
    case LANG(es);
    case LANG(fi);
    case LANG(fr);
    case LANG(hu);
    case LANG(it);
    case LANG(nl);
    case LANG(no);
    case LANG(pt);
    case LANG(sv);
    default:
      return 0;
  }
}

static bool is_word_char( char c ) {
  switch ( c ) {                        // exceptions to is_punct()
    case '&':                           // e.g.: "AT&T"
    case '-':                           // hyphenated words
      return true;
  }
  return !( ascii::is_space( c ) || ascii::is_punct( c ) );
}

///////////////////////////////////////////////////////////////////////////////

void ft_stop_words_set::apply_word( zstring const &word, word_set_t &word_set,
                                    ft_stop_words_unex::type mode ) {
  // TODO: should "word" be converted to lower-case?
  std::cout << "applying word " << word << std::endl;
  switch ( mode ) {
    case ft_stop_words_unex::union_:
      word_set.insert( word );
      break;
    case ft_stop_words_unex::except:
      word_set.erase( word );
      break;
  }
}

void ft_stop_words_set::apply_word( char const *begin, char const *end,
                                    word_set_t &word_set,
                                    ft_stop_words_unex::type mode ) {
  word_set_t::value_type const word( begin, end - begin );
  apply_word( word, word_set, mode );
}

ft_stop_words_set::ptr
ft_stop_words_set::construct( ftstop_word_option const &option,
                              iso639_1::type lang,
                              static_context const& sctx ) {
  bool must_delete = false;
  word_set_t *word_set = nullptr;       // pointless init. to stifle warning

  switch ( option.get_mode() ) {
    case ft_stop_words_mode::with:
      word_set = new word_set_t;
      must_delete = true;
      break;
    case ft_stop_words_mode::with_default:
      word_set = get_default_word_set_for( lang );
      if ( !word_set ) {
        // TODO: throw exception?
        return ptr();
      }
      break;
    case ft_stop_words_mode::without:
      return ptr();
  }

  FOR_EACH( ftstop_word_option::list_t, ftsw, option.get_stop_words() ) {
    ft_stop_words_unex::type const mode = (*ftsw)->get_mode();
    zstring const &uri = (*ftsw)->get_uri();

    if ( !uri.empty() ) {
      if ( !must_delete ) {
        word_set = new word_set_t( *word_set );
        must_delete = true;
      }

      zstring error_msg;
      std::auto_ptr<internal::Resource> rsrc =
          sctx.resolve_uri(uri, internal::EntityData::STOP_WORDS, error_msg);
      internal::StreamResource* stream_rsrc =
          dynamic_cast<internal::StreamResource*>(rsrc.get());
      if ( !stream_rsrc ) {
        // Technically this should be thrown during static analysis.
        throw ZORBA_EXCEPTION(err::FTST0008, ERROR_PARAMS(uri));
      }
      std::istream* stream = stream_rsrc->getStream();

      bool in_word = false;
      zstring cur_word;
      cur_word.reserve(128);
      char c;
      while (stream->good()) {
        stream->get(c);
        // Have to check for EOF *after* attempting the read
        if (stream->eof()) {
          break;
        }
        if ( is_word_char( c ) ) {
          if ( !in_word ) {
            cur_word.clear();
            in_word = true;
          }
          cur_word += c;
        } else {
          if ( in_word ) {
            apply_word( cur_word, *word_set, mode );
            in_word = false;
          }
        }
      }
      if ( in_word )
        apply_word( cur_word, *word_set, mode );
    }

    ftstop_words::list_t const &word_list = (*ftsw)->get_list();
    if ( !word_list.empty() ) {
      if ( !must_delete ) {
        word_set = new word_set_t( *word_set );
        must_delete = true;
      }
      FOR_EACH( ftstop_words::list_t, word, word_list )
        apply_word( *word, *word_set, mode );
    }
  }
  return ptr( new ft_stop_words_set( word_set, must_delete ) );
}

ft_stop_words_set const*
ft_stop_words_set::get_default( iso639_1::type lang ) {
  return new ft_stop_words_set( get_default_word_set_for( lang ), false );
}

ft_stop_words_set::word_set_t*
ft_stop_words_set::get_default_word_set_for( iso639_1::type lang ) {
  static word_set_t *cached_word_sets[ iso639_1::NUM_ENTRIES ];
  if ( !lang )
    lang = get_host_lang();
  word_set_t *&word_set = cached_word_sets[ lang ];
  if ( !word_set ) {
    if ( ft_stop_table const table = get_table_for( lang ) ) {
      word_set = new word_set_t;
      for ( ft_stop_table word = table; *word; ++word )
        word_set->insert( *word );
    }
  }
  return word_set;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
