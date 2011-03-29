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

#include "util/ascii_util.h"
#include "util/mmap_file.h"
#include "util/stl_util.h"
#include "util/uri_util.h"
#ifndef ZORBA_WITH_FILE_ACCESS
#include "zorbaerrors/error_manager.h"
#endif
#include "zorbautils/locale.h"

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

#if 0
    case LANG(ru);
#endif
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

void ft_stop_words_set::apply_word( zstring const &word, set_t &word_set,
                                    ft_stop_words_unex::type mode ) {
  // TODO: should "word" be converted to lower-case?
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
                                    set_t &word_set,
                                    ft_stop_words_unex::type mode ) {
  set_t::value_type const word( begin, end - begin );
  apply_word( word, word_set, mode );
}

ft_stop_words_set const*
ft_stop_words_set::construct( ftstop_word_option const &option,
                              iso639_1::type lang ) {
  bool must_delete = false;
  set_t *word_set = 0;                  // pointless init. to stifle warning

  switch ( option.get_mode() ) {
    case ft_stop_words_mode::with:
      word_set = new set_t;
      must_delete = true;
      break;
    case ft_stop_words_mode::with_default:
      word_set = get_default_word_set_for( lang );
      if ( !word_set ) {
        // TODO: throw exception?
        return 0;
      }
      break;
    case ft_stop_words_mode::without:
      return 0;
  }

  FOR_EACH( ftstop_word_option::list_t, ftsw, option.get_stop_words() ) {
    ft_stop_words_unex::type const mode = (*ftsw)->get_mode();
    zstring const &uri = (*ftsw)->get_uri();

#ifdef ZORBA_WITH_FILE_ACCESS
    if ( !uri.empty() ) {
      if ( !must_delete ) {
        word_set = new set_t( *word_set );
        must_delete = true;
      }

      zstring file_path;
      bool is_temp_file;
      uri::fetch( uri, &file_path, &is_temp_file );
      fs::auto_remover<zstring> file_remover;
      if ( is_temp_file )
        file_remover.reset( file_path );

      mmap_file const words_file( file_path.c_str() );
      mmap_file::const_iterator word_start;
      bool in_word = false;
      FOR_EACH( mmap_file, c, words_file ) {
        if ( is_word_char( *c ) ) {
          if ( !in_word ) {
            word_start = c;
            in_word = true;
          }
        } else {
          if ( in_word ) {
            apply_word( word_start, c, *word_set, mode );
            in_word = false;
          }
        }
      }
      if ( in_word )
        apply_word( word_start, words_file.end(), *word_set, mode );
    }
#else
    throw ZORBA_EXCEPTION( XQP0017_FILE_ACCESS_DISABLED );
#endif /* ZORBA_WITH_FILE_ACCESS */

    ftstop_words::list_t const &word_list = (*ftsw)->get_list();
    if ( !word_list.empty() ) {
      if ( !must_delete ) {
        word_set = new set_t( *word_set );
        must_delete = true;
      }
      FOR_EACH( ftstop_words::list_t, word, word_list )
        apply_word( *word, *word_set, mode );
    }
  }
  return new ft_stop_words_set( word_set, must_delete );
}

ft_stop_words_set::set_t*
ft_stop_words_set::get_default_word_set_for( iso639_1::type lang ) {
  static set_t* cached_word_sets[ iso639_1::NUM_ENTRIES ];
  if ( !lang )
    lang = get_host_lang();
  set_t *&word_set = cached_word_sets[ lang ];
  if ( !word_set ) {
    if ( ft_stop_table const table = get_table_for( lang ) ) {
      word_set = new set_t;
      for ( ft_stop_table word = table; *word; ++word )
        word_set->insert( *word );
    }
  }
  return word_set;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
