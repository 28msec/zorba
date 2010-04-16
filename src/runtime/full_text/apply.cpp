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
#include "runtime/full_text/stl_helpers.h"
#include "zorbaerrors/error_manager.h"

using namespace std;

namespace zorba {

//for Windows build
#undef max
#undef min

typedef set<ft_token::int_t> ft_pos_set;

////////// Helper algorithms /////////////////////////////////////////////////

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
    for ( ft_token::int_t pos = i->pos.start; pos <= i->pos.end; ++pos )
      s.insert( pos );
  return s;
}

/**
 * For the given ft_unit, gets its corresponding ft_token pointer-to-member.
 */
static ft_token::start_end_ptr get_sep_for( ft_unit::type unit ) {
  switch ( unit ) {
    case ft_unit::words:
      return &ft_token::pos;
    case ft_unit::sentences:
      return &ft_token::sent;
    case ft_unit::paragraphs:
      return &ft_token::para;
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
 * Sorts the 2 ft_tokens by their positions.
 */
static void sort( ft_token const **ti, ft_token const **tj ) {
  if ( **ti > **tj ) {
    ft_token const *const temp = *ti;
    *ti = *tj;
    *tj = temp;
  }
}

/**
 * Computes the distance of N between 2 ft_tokens where N is specified by the
 * pointer-to-member.
 */
static ft_token::int_t distance( ft_token const &ti, ft_token const &tj,
                                 ft_token::start_end_ptr sep ) {
  ft_token const *pi = &ti, *pj = &tj;
  sort( &pi, &pj );
  return (pj->*sep).start - (pi->*sep).end - 1;
}

/**
 * Computes max(N) from the given sequence of ft_tokens where N is specified by
 * the pointers-to-members.
 */
template<typename FTTokenSequenceType>
ft_token::int_t max( FTTokenSequenceType &seq, ft_token::start_end_ptr sep,
                     ft_token::int_ptr ip ) {
  ft_token::int_t result = numeric_limits<ft_token::int_t>::min();
  FOR_EACH( typename FTTokenSequenceType, t, seq ) {
    ft_token::int_t const n = (*t).*sep.*ip;
    if ( n > result )
      result = n;
  }
  return result;
}

#define MAX(SEQ,SEP,IP) \
  max( SEQ, &ft_token::SEP, &ft_token::start_end::IP )

/**
 * Find the max query_pos among all the match's include/exclude lists.
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
 * Computes min(N) from the given sequence of ft_tokens where N is specified by
 * the pointers-to-members.
 */
template<typename FTTokenSequenceType>
ft_token::int_t min( FTTokenSequenceType &seq, ft_token::start_end_ptr sep,
                     ft_token::int_ptr ip ) {
  ft_token::int_t result = numeric_limits<ft_token::int_t>::max();
  FOR_EACH( typename FTTokenSequenceType, t, seq ) {
    ft_token::int_t const n = (*t).*sep.*ip;
    if ( n < result )
      result = n;
  }
  return result;
}

#define MIN(SEQ,SEP,IP) \
  min( SEQ, &ft_token::SEP, &ft_token::start_end::IP )

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

  ft_token::int_t const min_pos = MIN( includes, pos, start );
  ft_token::int_t const max_pos = MAX( includes, pos, end );
  bool is_contiguous = true;

  FOR_EACH( ft_match::includes_t, i, includes ) {
    if ( !i->is_contiguous ) {
      is_contiguous = false;
      break;
    }
  }
  if ( is_contiguous ) {
    ft_pos_set const pos_set = covered_include_positions( includes );
    for ( ft_token::int_t pos = min_pos; pos <= max_pos; ++pos ) {
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

static void match_tokens( ft_tokens const &search_ctx,
                          ft_query_tokens const &qtokens, ft_tokens &result ) {
  // TODO
}

inline bool token_covers_pos( ft_token const &t, int token_pos ) {
  return token_pos >= t.pos.start && token_pos <= t.pos.end;
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
  ft_token::int_t const start_pos = 0;  // TODO: get_lowest_token_pos();
  ft_token::int_t const end_pos = 0;    // TODO: get_highest_token_pos();

  if ( mode == ft_content_mode::entire ) {
    for ( ft_all_matches::iterator m = am.begin(); m != am.end(); ) {
      bool keep = false;
      FOR_EACH( ft_match::includes_t, t, m->includes ) {
        if ( t->is_contiguous ) {
          for ( ft_token::int_t pos = start_pos; pos <= end_pos; ++pos ) {
            if ( token_covers_pos( *t, pos ) ) {
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
    ft_token::int_t const pos = mode == ft_content_mode::at_start ?
      start_pos : end_pos;

    for ( ft_all_matches::iterator m = am.begin(); m != am.end(); ) {
      bool keep = false;
      FOR_EACH( ft_match::includes_t, t, m->includes ) {
        if ( token_covers_pos( *t, pos ) ) {
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
  ft_token::start_end_ptr const sep = get_sep_for( unit );
  FOR_EACH( ft_all_matches, m, am ) {
    bool satisfies = true;
    if ( m->includes.size() > 1 ) {
      m->sort_includes();
      FOR_EACH( ft_match::includes_t, i, m->includes ) {
        ft_match::includes_t::const_iterator j = i;
        if ( ++j == m->includes.end() )
          break;
        ft_token::int_t const d = distance( *i, *j, sep );
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
          ft_token::int_t const d = distance( *i, *e, sep );
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
                                ft_token::start_end_ptr sep,
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
                            ft_token::start_end_ptr sep,
                            ft_token::int_t start ) {
  FOR_EACH( ft_match::includes_t, i, includes ) {
    if ( ((*i).*sep).start != start )
      return false;
  }
  return true;
}

static void apply_ftscope_same( ft_all_matches const &am,
                                ft_token::start_end_ptr sep,
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
                 ((*e).*sep).start == ((*e).*sep).end &&
                 every_start_is( m->includes, sep, ((*e).*sep).start ) ) {
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
  ft_token::start_end_ptr sep;
  switch ( unit ) {
    case ft_big_unit::sentence:
      sep = &ft_token::sent;
      break;
    case ft_big_unit::paragraph:
      sep = &ft_token::para;
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

static void apply_query_tokens_as_phrase( ft_tokens const &search_ctx,
                                          ft_query_tokens const &qtokens,
                                          int query_pos,
                                          ft_all_matches &result ) {
  ft_tokens tokens;
  match_tokens( search_ctx, qtokens, tokens );
  FOR_EACH( ft_tokens, t, tokens ) {
    ft_string_include si;
    si.pos.start     = t->pos.start;
    si.pos.end       = t->pos.end;
    si.sent.start    = t->sent.start;
    si.sent.end      = t->sent.end;
    si.para.start    = t->para.start;
    si.para.end      = t->para.end;
    si.query_pos     = query_pos;
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

static void apply_ftwords_phrase( ft_tokens const &search_ctx,
                                  ft_query_tokens const &qtokens,
                                  int query_pos,
                                  ft_all_matches &result ) {
  if ( !qtokens.empty() )
    apply_query_tokens_as_phrase( search_ctx, qtokens, query_pos, result );
}

static void apply_ftwords_all( ft_tokens const &search_ctx,
                               ft_query_tokens &qtokens,
                               int query_pos,
                               ft_all_matches &result ) {
  if ( !qtokens.empty() ) {
    ft_query_tokens first_qtokens;
    move_front_to_back( qtokens, first_qtokens );

    ft_all_matches first_am;
    apply_ftwords_phrase( search_ctx, first_qtokens, query_pos, first_am );

    if ( !qtokens.empty() ) {
      int const temp_pos = max_query_pos( first_am );
      if ( is_max_valid( temp_pos ) )
        query_pos = temp_pos + 1;
      ft_all_matches rest_am;
      apply_ftwords_all( search_ctx, qtokens, query_pos, rest_am );
      apply_ftand( first_am, rest_am, result );
    } else {
      result.swap( first_am );
    }
  }
}

static void apply_ftwords_any( ft_tokens const &search_ctx,
                               ft_query_tokens &qtokens,
                               int query_pos,
                               ft_all_matches &result ) {
  if ( !qtokens.empty() ) {
    ft_query_tokens first_qtokens;
    move_front_to_back( qtokens, first_qtokens );

    ft_all_matches first_am;
    apply_ftwords_phrase( search_ctx, first_qtokens, query_pos, first_am );

    int const temp_pos = max_query_pos( first_am );
    if ( is_max_valid( temp_pos ) )
      query_pos = temp_pos + 1;

    ft_all_matches rest_am;
    apply_ftwords_any( search_ctx, qtokens, query_pos, rest_am );
    apply_ftor( first_am, rest_am, result );
  }
}

static void apply_ftwords_xxx_word( ft_tokens const &search_ctx,
                                    ft_query_tokens const &qtokens,
                                    int query_pos,
                                    apply_fn_3arg_t apply_fn,
                                    ft_all_matches &result ) {
  if ( !qtokens.empty() ) {
    ft_all_matches_seq all_am_seq;
    int pos = 0;
    FOR_EACH( ft_query_tokens, qtoken, qtokens ) {
      ft_query_tokens qtokens2;
      qtokens2.push_back( *qtoken );
      ft_all_matches am;
      apply_query_tokens_as_phrase(
        search_ctx, qtokens2, query_pos + pos++, am
      );
      all_am_seq.push_back( am );
    }
    ft_all_matches const first_am = POP_FRONT( all_am_seq );
    make_conj_disj( first_am, all_am_seq, apply_fn, result );
  }
}

void apply_ftwords( ft_tokens const &search_ctx,
                    ft_query_tokens const &qtokens, int query_pos,
                    ft_anyall_mode::type mode, ft_all_matches &result ) {
  ft_query_tokens qtokens_copy( qtokens );
  switch ( mode ) {
    case ft_anyall_mode::any:
      apply_ftwords_any( search_ctx, qtokens_copy, query_pos, result );
      break;
    case ft_anyall_mode::any_word:
      apply_ftwords_xxx_word(
        search_ctx, qtokens_copy, query_pos, &apply_ftor, result
      );
      break;
    case ft_anyall_mode::all:
      apply_ftwords_all( search_ctx, qtokens_copy, query_pos, result );
      break;
    case ft_anyall_mode::all_words:
      apply_ftwords_xxx_word(
        search_ctx, qtokens_copy, query_pos, &apply_ftand, result
      );
      break;
    case ft_anyall_mode::phrase:
      apply_ftwords_phrase( search_ctx, qtokens, query_pos, result );
      break;
  }
}

////////// ApplyFTWindow //////////////////////////////////////////////////////

void apply_ftwindow( ft_all_matches const &am, int window_size,
                     ft_unit::type unit, ft_all_matches &result ) {
  ft_token::start_end_ptr const sep = get_sep_for( unit );
  FOR_EACH( ft_all_matches, m, am ) {
    ft_token::int_t const min_pos = MIN( m->includes, pos, start );
    ft_token::int_t const max_pos = MAX( m->includes, pos, end );
    for ( ft_token::int_t win_start_pos = max_pos - window_size + 1;
          win_start_pos < min_pos; ++win_start_pos ) {
      ft_token::int_t const win_end_pos = win_start_pos + window_size - 1;
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
