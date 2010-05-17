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

#include <limits>
#include <set>
#include <vector>

#include <zorba/error.h>

#include "runtime/full_text/apply.h"
#include "runtime/full_text/ft_token.h"
#include "zorbaerrors/error_manager.h"
#include "zorbautils/stl_util.h"

#ifdef WIN32
// Windows annoyingly defines these as macros.
#undef max
#undef min
#endif

using namespace std;

namespace zorba {

typedef set<ft_token_span::int_t> ft_pos_set;

////////// Helper algorithms //////////////////////////////////////////////////

/**
 * Given an ft_all_matches, see if all of its includes/excludes are empty.
 */
static bool all_empty( ft_all_matches const &am,
                       ft_match::string_match_ptr smp ) {
  FOR_EACH( ft_all_matches, m, am ) {
    if ( !((*m).*smp).empty() )
      return false;
  }
  return true;
}

/**
 * Given a sequence of ft_string_include objects, constructs a set of all the
 * positions spanned by all the contained tokens.
 */
static ft_pos_set
covered_include_positions( ft_match::includes_t const &includes ) {
  ft_pos_set s;
  FOR_EACH( ft_match::includes_t, i, includes )
    for ( ft_token_span::int_t pos = i->pos.start; pos <= i->pos.end; ++pos )
      s.insert( pos );
  return s;
}

/**
 * For the given ft_unit, gets its corresponding ft_token_span
 * pointer-to-member.
 */
static ft_token_span::start_end_ptr get_sep_for( ft_unit::type unit ) {
  switch ( unit ) {
    case ft_unit::words:
      return &ft_token_span::pos;
    case ft_unit::sentences:
      return &ft_token_span::sent;
    case ft_unit::paragraphs:
      return &ft_token_span::para;
  }
  return 0;                             // to suppress warning
}

/**
 * Returns whether the given value is a valid max value.
 */
template<typename T> inline bool is_max_valid( T n ) {
  return n != numeric_limits<T>::min();
}

/**
 * Sorts the 2 ft_token_spans by their positions.
 */
static void sort( ft_token_span const *&tsi, ft_token_span const *&tsj ) {
  if ( *tsi > *tsj ) {
    ft_token_span const *const temp = tsi;
    tsi = tsj;
    tsj = temp;
  }
}

/**
 * Computes the distance of N between 2 ft_token_spans where N is specified by
 * the pointer-to-member.
 */
static ft_token_span::distance_t distance( ft_token_span const &tsi,
                                           ft_token_span const &tsj,
                                           ft_token_span::start_end_ptr sep ) {
  ft_token_span const *pi = &tsi, *pj = &tsj;
  sort( pi, pj );
  return  static_cast<ft_token_span::distance_t>( (pj->*sep).start )
        - static_cast<ft_token_span::distance_t>( (pi->*sep).end   )
        - 1;
}

/**
 * Computes max(N) from the given sequence of ft_token_spans where N is
 * specified by the pointers-to-members.
 */
template<typename FTTokenSpanSequenceType>
ft_token_span::int_t max( FTTokenSpanSequenceType &seq,
                          ft_token_span::start_end_ptr sep,
                          ft_token_span::int_ptr ip ) {
  ft_token_span::int_t result = numeric_limits<ft_token_span::int_t>::min();
  FOR_EACH( typename FTTokenSpanSequenceType, ts, seq ) {
    ft_token_span::int_t const n = (*ts).*sep.*ip;
    if ( n > result )
      result = n;
  }
  return result;
}

#define MAX(SEQ,SEP,IP) \
  max( SEQ, &ft_token_span::SEP, &ft_token_span::start_end::IP )

/**
 * Finds the max query_pos among all the match's include/exclude lists.
 */
ft_string_match::int_t max_query_pos( ft_all_matches const &am ) {
  ft_string_match::int_t result = numeric_limits<ft_string_match::int_t>::min();
  FOR_EACH( ft_all_matches, m, am ) {
    FOR_EACH( ft_match::includes_t, i, m->includes ) {
      ft_string_match::int_t const n = i->query_pos;
      if ( n > result )
        result = n;
    }
    FOR_EACH( ft_match::excludes_t, e, m->excludes ) {
      ft_string_match::int_t const n = e->query_pos;
      if ( n > result )
        result = n;
    }
  }
  return result;
}

/**
 * Computes min(N) from the given sequence of ft_token_spans where N is
 * specified by the pointers-to-members.
 */
template<typename FTTokenSpanSequenceType>
ft_token_span::int_t min( FTTokenSpanSequenceType &seq,
                          ft_token_span::start_end_ptr sep,
                          ft_token_span::int_ptr ip ) {
  ft_token_span::int_t result = numeric_limits<ft_token_span::int_t>::max();
  FOR_EACH( typename FTTokenSpanSequenceType, ts, seq ) {
    ft_token_span::int_t const n = (*ts).*sep.*ip;
    if ( n < result )
      result = n;
  }
  return result;
}

#define MIN(SEQ,SEP,IP) \
  min( SEQ, &ft_token_span::SEP, &ft_token_span::start_end::IP )

/**
 * From [1] 4.2.6.8:
 *
 *  joinIncludes takes a sequence of StringIncludes of a Match and transforms
 *  it into either the empty sequence, in case the input sequence was empty, or
 *  otherwise a single StringInclude representing the span from the first
 *  position of the match to the last. For the purpose of being able to
 *  evaluate an "entire content" operator further up in the tree, we
 *  pre-evaluate whether all possible positions between first and last are
 *  covered in the input StringIncludes and store that boolean in the attribute
 *  "isContiguous".
 */
static void join_includes( ft_match::includes_t const &includes,
                           ft_match::includes_t &result ) {
  if ( includes.empty() )
    return;

  ft_token_span::int_t const min_pos = MIN( includes, pos, start );
  ft_token_span::int_t const max_pos = MAX( includes, pos, end );
  bool is_contiguous = true;

  FOR_EACH( ft_match::includes_t, i, includes ) {
    if ( !i->is_contiguous ) {
      is_contiguous = false;
      break;
    }
  }
  if ( is_contiguous ) {
    ft_pos_set const pos_set = covered_include_positions( includes );
    for ( ft_token_span::int_t pos = min_pos; pos <= max_pos; ++pos ) {
      if ( !contains( pos_set, pos ) ) {
        is_contiguous = false;
        break;
      }
    }
  }

  ft_string_include si;
  si.pos.start     = min_pos;
  si.pos.end       = max_pos;
  si.sent.start    = MIN( includes, sent, start );
  si.sent.end      = MAX( includes, sent, end   );
  si.para.start    = MIN( includes, para, start );
  si.para.end      = MAX( includes, para, end   );
  si.query_pos     = includes.begin()->query_pos;
  si.is_contiguous = is_contiguous;
  result.push_back( si );
}

#if 0
static void dump( char const *label, FTTokenIterator it ) {
  it.reset();
  cout << label << flush;
  FTToken const *t;
  while ( it.next( &t ) )
    cout << " \"" << t->word << '"';
  cout << endl;
}
#endif

/**
 * Test whether the 2 given tokens match given the match options.
 */
static bool match_tokens( FTToken const &i, FTToken const &j,
                          ftmatch_options const &options ) {

  if ( ftcase_option const *const c = options.get_case_option() ) {
    switch ( c->get_mode() ) {
      case ft_case_mode::insensitive:
        // TODO
        break;
      case ft_case_mode::sensitive:
        // do nothing
        break;
      case ft_case_mode::lower:
        // TODO: make the query string lower-case
        break;
      case ft_case_mode::upper:
        // TODO: make the query string upper-case
        break;
    }
  }

  if ( ftdiacritics_option const *const d = options.get_diacritics_option() ) {
    switch ( d->get_mode() ) {
      case ft_diacritics_mode::insensitive:
        // TODO
        break;
      case ft_diacritics_mode::sensitive:
        // do nothing
        break;
    }
  }

  if ( ftextension_option const *const e = options.get_extension_option() ) {
    // TODO
  }

  if ( ftlanguage_option const *const l = options.get_language_option() ) {
    // string const &lang = l->get_language();
    // TODO
  }

  if ( ftstem_option const *const s = options.get_stem_option() ) {
    switch ( s->get_mode() ) {
      case ft_stem_mode::with:
        // TODO
        break;
      case ft_stem_mode::without:
        // do nothing
        break;
    }
  }

  if ( ftstop_word_option const *const sw = options.get_stop_word_option() ) {
    switch ( sw->get_mode() ) {
      case ft_stop_words_mode::with:
        // TODO
        break;
      case ft_stop_words_mode::with_default:
        // TODO
        break;
      case ft_stop_words_mode::without:
        // do nothing
        break;
    }
  }

  if ( ftthesaurus_option const *const t = options.get_thesaurus_option() ) {
    // TODO
  }

  if ( ftwild_card_option const *const w = options.get_wild_card_option() ) {
    switch ( w->get_mode() ) {
      case ft_wild_card_mode::with:
        // TODO
        break;
      case ft_wild_card_mode::without:
        // do nothing
        break;
    }
  }

  return i.word == j.word;
}

/**
 * Matches query tokens against document tokens.
 */
static void match_tokens( FTTokenIterator doc_tokens,
                          FTTokenIterator query_tokens,
                          ftmatch_options const &options,
                          ft_token_spans &result ) {

#if 0
  dump( "match_tokens(): doc_tokens: ", doc_tokens );
  dump( "match_tokens(): query_tokens: ", query_tokens );
#endif
  doc_tokens.reset();
  while ( doc_tokens.hasNext() ) {
    FTTokenIterator const doc_tokens_copy( doc_tokens );
    query_tokens.reset();
    FTToken const *dt_start = 0, *dt_end = 0;
    while ( doc_tokens.hasNext() && query_tokens.hasNext() ) {
      dt_end = &doc_tokens.current();
      if ( !dt_start )
        dt_start = dt_end;
      FTToken const &qt = query_tokens.current();
      if ( !match_tokens( *dt_end, qt, options ) )
        break;
      doc_tokens.next();
      query_tokens.next();
    }
    if ( !query_tokens.hasNext() ) {
      ft_token_span ts;
      ts.pos.start  = dt_start->pos;
      ts.pos.end    = dt_end->pos;
      ts.sent.start = dt_start->sent;
      ts.sent.end   = dt_end->sent;
      ts.para.start = dt_start->para;
      ts.para.end   = dt_end->para;
      result.push_back( ts );
    } else {
      doc_tokens = doc_tokens_copy;
      doc_tokens.next();
    }
  }
}

/**
 * Checks whether the given ft_token_span spans the given token position.
 */
inline bool token_covers_pos( ft_token_span const &ts,
                              ft_token_span::int_t token_pos ) {
  return token_pos >= ts.pos.start && token_pos <= ts.pos.end;
}

////////// ApplyFTAnd /////////////////////////////////////////////////////////

void apply_ftand( ft_all_matches const &ami, ft_all_matches const &amj,
                  ft_all_matches &result ) {
  FOR_EACH( ft_all_matches, mi, ami ) {
    FOR_EACH( ft_all_matches, mj, amj ) {
      ft_match m_new;
      copy_seq( mi->includes, m_new.includes );
      copy_seq( mj->includes, m_new.includes );
      copy_seq( mi->excludes, m_new.excludes );
      copy_seq( mj->excludes, m_new.excludes );
      result.push_back( m_new );
    }
  }
}

////////// ApplyFTContent /////////////////////////////////////////////////////

void apply_ftcontent( ft_all_matches &am, ft_content_mode::type mode ) {
  ft_token_span::int_t const start_pos = 0;  // TODO: get_lowest_token_pos();
  ft_token_span::int_t const end_pos = 0;    // TODO: get_highest_token_pos();

  if ( mode == ft_content_mode::entire ) {
    for ( ft_all_matches::iterator m = am.begin(); m != am.end(); ) {
      bool keep = false;
      FOR_EACH( ft_match::includes_t, i, m->includes ) {
        if ( i->is_contiguous ) {
          for ( ft_token_span::int_t pos = start_pos; pos <= end_pos; ++pos ) {
            if ( token_covers_pos( *i, pos ) ) {
              keep = true;
              break;
            }
          }
        }
      }
      if ( keep )
        ++m;
      else
        m = am.erase( m );
    }
  } else {
    ft_token_span::int_t const pos = mode == ft_content_mode::at_start ?
      start_pos : end_pos;

    for ( ft_all_matches::iterator m = am.begin(); m != am.end(); ) {
      bool keep = false;
      FOR_EACH( ft_match::includes_t, i, m->includes ) {
        if ( token_covers_pos( *i, pos ) ) {
          keep = true;
          break;
        }
      }
      if ( keep )
        ++m;
      else
        m = am.erase( m );
    }
  }
}

////////// ApplyFTDistance ////////////////////////////////////////////////////

void apply_ftdistance( ft_all_matches const &am, int at_least, int at_most,
                       ft_unit::type unit, ft_all_matches &result ) {
  ft_token_span::start_end_ptr const sep = get_sep_for( unit );
  FOR_EACH( ft_all_matches, m, am ) {
    bool satisfies = true;
    if ( m->includes.size() > 1 ) {
      m->sort_includes();
      FOR_EACH( ft_match::includes_t, i, m->includes ) {
        ft_match::includes_t::const_iterator j = i;
        if ( ++j == m->includes.end() )
          break;
        ft_token_span::distance_t const d = distance( *i, *j, sep );
        if ( d < at_least || d > at_most ) {
          satisfies = false;
          break;
        }
      }
    }
    if ( satisfies ) {
      ft_match m_new;
      join_includes( m->includes, m_new.includes );
      FOR_EACH( ft_match::excludes_t, e, m->excludes ) {
        FOR_EACH( ft_match::includes_t, i, m->includes ) {
          ft_token_span::distance_t const d = distance( *i, *e, sep );
          if ( d >= at_least && d <= at_most ) {
            m_new.excludes.push_back( *e );
            break;
          }
        }
      }
      result.push_back( m_new );
    }
  }
}

////////// ApplyFTMildNot /////////////////////////////////////////////////////

void apply_ftmild_not( ft_all_matches const &ami, ft_all_matches const &amj,
                       ft_all_matches &result ) {
  
  if ( all_empty( ami, &ft_match::excludes ) ||
       all_empty( amj, &ft_match::excludes ) )
    ZORBA_ERROR( FTDY0017 );

  if ( all_empty( amj, &ft_match::includes ) )
    result = ami;
  else {
    typedef vector<ft_pos_set> ft_pos_set_cache_t;

    ft_pos_set_cache_t psj_cache( amj.size() );
    FOR_EACH( ft_all_matches, mj, amj ) {
      psj_cache.push_back( covered_include_positions( mj->includes ) );
    }

    FOR_EACH( ft_all_matches, mi, ami ) {
      ft_pos_set const psi = covered_include_positions( mi->includes );
      FOR_EACH( ft_pos_set_cache_t, psj, psj_cache ) {
        FOR_EACH( ft_pos_set, pos, psi ) {
          if ( !contains( *psj, *pos ) )
            result.push_back( *mi );
        }
      }
    }
  }
}

////////// ApplyFTOr //////////////////////////////////////////////////////////

void apply_ftor( ft_all_matches const &ami, ft_all_matches const &amj,
                 ft_all_matches &result ) {
  copy_seq( ami, result );
  copy_seq( amj, result );
}

////////// ApplyFTOrder ///////////////////////////////////////////////////////

void apply_ftorder( ft_all_matches &am ) {
  // TODO
}

////////// ApplyFTScope ///////////////////////////////////////////////////////

static void apply_ftscope_diff( ft_all_matches const &am,
                                ft_token_span::start_end_ptr sep,
                                ft_all_matches &result ) {
  FOR_EACH( ft_all_matches, m, am ) {
    FOR_EACH( ft_match::includes_t, i1, m->includes ) {
      FOR_EACH( ft_match::includes_t, i2, m->includes ) {
        if ( &*i1 == &*i2 )
          continue;
        if ( ( ((*i1).*sep).start != ((*i2).*sep).start
            || ((*i1).*sep).start != ((*i1).*sep).end
            || ((*i2).*sep).start != ((*i2).*sep).end )
            && ((*i1).*sep).start > 0 && ((*i2).*sep).end > 0 ) {
          ft_match m_new;
          copy_seq( m->includes, m_new.includes );
          FOR_EACH( ft_match::excludes_t, e, m->excludes ) {
            FOR_EACH( ft_match::includes_t, i, m->includes ) {
              if ( ( ((*i).*sep).start != ((*e).*sep).end
                  || ((*i).*sep).start != ((*i).*sep).end
                  || ((*e).*sep).start != ((*e).*sep).end )
                  && ((*i).*sep).start > 0 && ((*e).*sep).end > 0 ) {
                m_new.excludes.push_back( *e );
              }
            }
          }
          result.push_back( m_new );
        }
      }
    }
  }
}

/**
 * Helper function for apply_ftscope_same().
 */
static bool every_start_is( ft_match::includes_t const &includes,
                            ft_token_span::start_end_ptr sep,
                            ft_token_span::int_t start ) {
  FOR_EACH( ft_match::includes_t, i, includes ) {
    if ( ((*i).*sep).start != start )
      return false;
  }
  return true;
}

static void apply_ftscope_same( ft_all_matches const &am,
                                ft_token_span::start_end_ptr sep,
                                ft_all_matches &result ) {
  FOR_EACH( ft_all_matches, m, am ) {
    FOR_EACH( ft_match::includes_t, i1, m->includes ) {
      FOR_EACH( ft_match::includes_t, i2, m->includes ) {
        if ( &*i1 == &*i2 )
          continue;
        if ( ((*i1).*sep).start == ((*i2).*sep).start &&
             ((*i1).*sep).start == ((*i1).*sep).end &&
             ((*i2).*sep).start == ((*i2).*sep).end &&
             ((*i1).*sep).start > 0 && ((*i2).*sep).start > 0 ) {
          ft_match m_new;
          copy_seq( m->includes, m_new.includes );
          FOR_EACH( ft_match::excludes_t, e, m->excludes ) {
            if ( ((*e).*sep).start == 0 ||
                 (((*e).*sep).start == ((*e).*sep).end &&
                  every_start_is( m->includes, sep, ((*e).*sep).start ) ) ) {
              m_new.excludes.push_back( *e );
            }
          }
          result.push_back( m_new );
        }
      }
    }
  }
}

void apply_ftscope( ft_all_matches const &am, ft_scope::type scope,
                    ft_big_unit::type unit, ft_all_matches &result ) {
  ft_token_span::start_end_ptr sep = 0;
  switch ( unit ) {
    case ft_big_unit::sentence:
      sep = &ft_token_span::sent;
      break;
    case ft_big_unit::paragraph:
      sep = &ft_token_span::para;
      break;
  }
  switch ( scope ) {
    case ft_scope::same:
      apply_ftscope_same( am, sep, result );
      break;
    case ft_scope::different:
      apply_ftscope_diff( am, sep, result );
      break;
  }
}

////////// ApplyFTUnaryNot ////////////////////////////////////////////////////

void apply_ftunary_not( ft_all_matches &am ) {
  MUTATE_EACH( ft_all_matches, m, am )
    m->includes.swap( m->excludes );
}

////////// ApplyFTWords ///////////////////////////////////////////////////////

typedef list<ft_all_matches> ft_all_matches_seq;

static void apply_query_tokens_as_phrase( FTTokenIterator &search_ctx,
                                          FTTokenIterator &query_tokens,
                                          FTToken::int_t query_pos,
                                          ftmatch_options const &options,
                                          ft_all_matches &result ) {
  ft_token_spans token_spans;
  match_tokens( search_ctx, query_tokens, options, token_spans );
  FOR_EACH( ft_token_spans, ts, token_spans ) {
    ft_string_include si;
    si.pos.start  = ts->pos.start;
    si.pos.end    = ts->pos.end;
    si.sent.start = ts->sent.start;
    si.sent.end   = ts->sent.end;
    si.para.start = ts->para.start;
    si.para.end   = ts->para.end;
    si.query_pos  = query_pos;
    si.is_contiguous = true;
    ft_match m_new;
    m_new.includes.push_back( si );
    result.push_back( m_new );
  }
}

typedef void (*apply_fn_3arg_t)( ft_all_matches const&, ft_all_matches const&,
                                 ft_all_matches& );

static void make_conj_disj( ft_all_matches const &cur_res,
                            ft_all_matches_seq &rest,
                            apply_fn_3arg_t apply_fn, ft_all_matches &result ) {
  if ( rest.empty() )
    result = cur_res;
  else {
    ft_all_matches const first_am = POP_FRONT( rest );
    ft_all_matches new_cur_res;
    apply_fn( cur_res, first_am, new_cur_res );
    make_conj_disj( new_cur_res, rest, apply_fn, result );
  }
}

inline void apply_ftwords_phrase( FTTokenIterator &search_ctx,
                                  FTTokenIterator &query_tokens,
                                  FTToken::int_t query_pos,
                                  ftmatch_options const &options,
                                  ft_all_matches &result ) {
  if ( !query_tokens.empty() )
    apply_query_tokens_as_phrase(
      search_ctx, query_tokens, query_pos, options, result
    );
}

static void apply_ftwords_all( FTTokenIterator &search_ctx,
                               FTTokenIterator &query_tokens,
                               FTToken::int_t query_pos,
                               ftmatch_options const &options,
                               ft_all_matches &result ) {
  if ( query_tokens.hasNext() ) {
    FTTokenIterator first_query_token( query_tokens.iterator() );
    query_tokens.next();

    ft_all_matches first_am;
    apply_ftwords_phrase(
      search_ctx, first_query_token, query_pos, options, first_am
    );

    if ( query_tokens.hasNext() ) {
      FTToken::int_t const temp_pos = max_query_pos( first_am );
      if ( is_max_valid( temp_pos ) )
        query_pos = temp_pos + 1;
      ft_all_matches rest_am;
      apply_ftwords_all(
        search_ctx, query_tokens, query_pos, options, rest_am
      );
      apply_ftand( first_am, rest_am, result );
    } else {
      result.swap( first_am );
    }
  }
}

static void apply_ftwords_any( FTTokenIterator &search_ctx,
                               FTTokenIterator &query_tokens,
                               FTToken::int_t query_pos,
                               ftmatch_options const &options,
                               ft_all_matches &result ) {
  if ( query_tokens.hasNext() ) {
    FTTokenIterator first_query_token( query_tokens.iterator() );
    query_tokens.next();

    ft_all_matches first_am;
    apply_ftwords_phrase(
      search_ctx, first_query_token, query_pos, options, first_am
    );

    FTToken::int_t const temp_pos = max_query_pos( first_am );
    if ( is_max_valid( temp_pos ) )
      query_pos = temp_pos + 1;

    ft_all_matches rest_am;
    apply_ftwords_any( search_ctx, query_tokens, query_pos, options, rest_am );
    apply_ftor( first_am, rest_am, result );
  }
}

/**
 * This function combines ApplyFTWordsAnyWord() and ApplyFTWordsAllWord() since
 * the code is the same except that the former calls MakeDisjunction() and the
 * latter calls MakeConjunction().
 */
static void apply_ftwords_xxx_word( FTTokenIterator &search_ctx,
                                    FTTokenIterator &query_tokens,
                                    FTToken::int_t query_pos,
                                    ftmatch_options const &options,
                                    apply_fn_3arg_t apply_fn,
                                    ft_all_matches &result ) {
  if ( !query_tokens.empty() ) {
    ft_all_matches_seq all_am_seq;
    for ( FTToken::int_t pos = 0; query_tokens.hasNext();
          ++pos, query_tokens.next() ) {
      FTTokenIterator query_token( query_tokens.iterator() );
      ft_all_matches am;
      apply_query_tokens_as_phrase(
        search_ctx, query_token, query_pos + pos, options, am
      );
      all_am_seq.push_back( am );
    }
    ft_all_matches const first_am = POP_FRONT( all_am_seq );
    make_conj_disj( first_am, all_am_seq, apply_fn, result );
  }
}

void apply_ftwords( FTTokenIterator &search_ctx,
                    FTTokenIterator &query_tokens,
                    FTToken::int_t query_pos,
                    ft_anyall_mode::type mode,
                    ftmatch_options const &options,
                    ft_all_matches &result ) {
  switch ( mode ) {
    case ft_anyall_mode::any:
      apply_ftwords_any( search_ctx, query_tokens, query_pos, options, result );
      break;
    case ft_anyall_mode::any_word:
      apply_ftwords_xxx_word(
        search_ctx, query_tokens, query_pos, options, &apply_ftor, result
      );
      break;
    case ft_anyall_mode::all:
      apply_ftwords_all( search_ctx, query_tokens, query_pos, options, result );
      break;
    case ft_anyall_mode::all_words:
      apply_ftwords_xxx_word(
        search_ctx, query_tokens, query_pos, options, &apply_ftand, result
      );
      break;
    case ft_anyall_mode::phrase:
      apply_ftwords_phrase(
        search_ctx, query_tokens, query_pos, options, result
      );
      break;
  }
}

////////// ApplyFTWindow //////////////////////////////////////////////////////

void apply_ftwindow( ft_all_matches const &am, int window_size,
                     ft_unit::type unit, ft_all_matches &result ) {
  ft_token_span::start_end_ptr const sep = get_sep_for( unit );
  FOR_EACH( ft_all_matches, m, am ) {
    ft_token_span::int_t const min_pos = MIN( m->includes, pos, start );
    ft_token_span::int_t const max_pos = MAX( m->includes, pos, end );
    for ( ft_token_span::int_t win_start_pos = max_pos - window_size + 1;
          win_start_pos < min_pos; ++win_start_pos ) {
      ft_token_span::int_t const win_end_pos = win_start_pos + window_size - 1;
      ft_match m_new;
      join_includes( m->includes, m_new.includes );
      FOR_EACH( ft_match::excludes_t, e, m->excludes ) {
        if ( ((*e).*sep).start >= win_start_pos &&
             ((*e).*sep).end <= win_end_pos )
          m_new.excludes.push_back( *e );
      }
      result.push_back( m_new );
    }
  }
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
