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
#include "runtime/full_text/ft_token_span.h"
#include "system/properties.h"
#include "zorbaerrors/error_manager.h"
#include "zorbautils/indent.h"
#include "zorbautils/stl_util.h"

#ifdef WIN32
// Windows annoyingly defines these as macros.
#undef max
#undef min
#endif

using namespace std;

namespace zorba {

////////// Debugging macros ///////////////////////////////////////////////////

#ifndef NDEBUG

#define DOUT Properties::instance()->debug_out()
#define TRACE_FULL_TEXT Properties::instance()->traceFulltext()

#define BEGIN_APPLY(NAME)             \
  if ( !TRACE_FULL_TEXT ) ; else      \
  DOUT << '\n' << indent <<  #NAME "()\n" << inc_indent

#define PUT_ALL_MATCHES(ARG)                        \
  if ( !TRACE_FULL_TEXT ) ; else                    \
  DOUT << indent << "ARG " #ARG "\n"                \
       << inc_indent << (ARG) << dec_indent

#define PUT_ARG(ARG)                                  \
  if ( !TRACE_FULL_TEXT ) ; else                      \
  DOUT << indent << "ARG " #ARG "=" << (ARG) << endl

#define PUT_ENUM(FT_ENUM,ARG)                                             \
  if ( !TRACE_FULL_TEXT ) ; else                                          \
  DOUT << indent << "ARG " #ARG "=" << FT_ENUM::string_of[ ARG ] << endl

#define END_APPLY(RESULT)                                               \
  if ( !TRACE_FULL_TEXT ) ; else                                        \
  DOUT  << indent << "RESULT\n" << inc_indent << (RESULT) << dec_indent \
        << dec_indent

#else /* NDEBUG */

#define BEGIN_APPLY(NAME)     /* nothing */
#define PUT_ALL_MATCHES(ARG)  /* nothing */
#define PUT_ARG(ARG)          /* nothing */
#define PUT_ENUM(FT_ENUM,ARG) /* nothing */
#define END_APPLY(RESULT)     /* nothing */

#endif /* NDEBUG */

///////////////////////////////////////////////////////////////////////////////

bool match_tokens( FTToken::string_t const&, FTToken::string_t const&,
                   ftmatch_options const& );

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
 * Computes max(N) from the given sequence of struct objects having an IntType
 * member.
 */
template<typename SequenceType,typename IntType>
IntType max( SequenceType &seq, IntType SequenceType::value_type::*ip ) {
  IntType result = numeric_limits<IntType>::min();
  FOR_EACH( typename SequenceType, i, seq ) {
    IntType const n = (*i).*ip;
    if ( n > result )
      result = n;
  }
  return result;
}

/**
 * Computes max(N) from the given sequence of ft_token_spans where N is
 * specified by the pointers-to-members.
 */
template<typename FTTokenSpanSequenceType>
ft_token_span::int_t max( FTTokenSpanSequenceType &seq,
                          ft_token_span::start_end_ptr sep,
                          ft_token_span::int_ptr ip ) {
  typedef ft_token_span::int_t int_t;
  int_t result = numeric_limits<int_t>::min();
  FOR_EACH( typename FTTokenSpanSequenceType, ts, seq ) {
    int_t const n = (*ts).*sep.*ip;
    if ( n > result )
      result = n;
  }
  return result;
}

#define MAX_TS(SEQ,SEP,IP) \
  max( SEQ, &ft_token_span::SEP, &ft_token_span::start_end::IP )

/**
 * Computes min(N) from the given sequence of ft_token_spans where N is
 * specified by the pointers-to-members.
 */
template<typename FTTokenSpanSequenceType>
ft_token_span::int_t min( FTTokenSpanSequenceType &seq,
                          ft_token_span::start_end_ptr sep,
                          ft_token_span::int_ptr ip ) {
  typedef ft_token_span::int_t int_t;
  int_t result = numeric_limits<int_t>::max();
  FOR_EACH( typename FTTokenSpanSequenceType, ts, seq ) {
    int_t const n = (*ts).*sep.*ip;
    if ( n < result )
      result = n;
  }
  return result;
}

#define MIN_TS(SEQ,SEP,IP) \
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

  typedef ft_token_span::int_t int_t;

  int_t const min_pos = MIN_TS( includes, pos, start );
  int_t const max_pos = MAX_TS( includes, pos, end );

  bool is_contiguous = true;
  FOR_EACH( ft_match::includes_t, i, includes ) {
    if ( !i->is_contiguous ) {
      is_contiguous = false;
      break;
    }
  }
  if ( is_contiguous ) {
    ft_pos_set const pos_set = covered_include_positions( includes );
    for ( int_t pos = min_pos; pos <= max_pos; ++pos ) {
      if ( !contains( pos_set, pos ) ) {
        is_contiguous = false;
        break;
      }
    }
  }

  ft_string_include si;
  si.pos.start     = min_pos;
  si.pos.end       = max_pos;
  si.sent.start    = MIN_TS( includes, sent, start );
  si.sent.end      = MAX_TS( includes, sent, end   );
  si.para.start    = MIN_TS( includes, para, start );
  si.para.end      = MAX_TS( includes, para, end   );
  si.query_pos     = includes.begin()->query_pos;
  si.is_contiguous = is_contiguous;
  result.push_back( si );
}

#ifdef DEBUG_FT
static void dump( char const *label, FTTokenIterator &it ) {
  it->reset();
  cout << indent << label << ' ';
  FTToken const *t;
  while ( it->next( &t ) )
    cout << *t;
  cout << endl;
}
#endif

/**
 * Matches query tokens against document tokens.
 */
static void match_tokens( FTTokenIterator &doc_tokens,
                          FTTokenIterator &query_tokens,
                          ftmatch_options const &options,
                          ft_token_spans &result ) {
#ifdef DEBUG_FT
  dump( "match_tokens(): d_tokens: ", *doc_tokens );
  dump( "match_tokens(): q_tokens: ", query_tokens );
#endif
  doc_tokens.reset();
  while ( doc_tokens.hasNext() ) {
    doc_tokens.mark( true );
    query_tokens.reset();
    FTToken const *dt_start = 0, *dt_end = 0;
    while ( doc_tokens.hasNext() && query_tokens.hasNext() ) {
      dt_end = &doc_tokens.current();
      if ( !dt_start )
        dt_start = dt_end;
      FTToken const &qt = query_tokens.current();
      if ( !match_tokens( dt_end->word, qt.word, options ) )
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
      doc_tokens.mark( false );
      doc_tokens.next();
    }
  }
}

////////// ApplyFTAnd /////////////////////////////////////////////////////////

void apply_ftand( ft_all_matches const &ami, ft_all_matches const &amj,
                  ft_all_matches &result ) {
  BEGIN_APPLY( apply_ftand );
  PUT_ALL_MATCHES( ami );
  PUT_ALL_MATCHES( amj );

  if ( !amj.empty() ) {
    FOR_EACH( ft_all_matches, mi, ami ) {
      ft_match m_new;
      copy_seq( mi->includes, m_new.includes );
      copy_seq( mi->excludes, m_new.excludes );
      FOR_EACH( ft_all_matches, mj, amj ) {
        copy_seq( mj->includes, m_new.includes );
        copy_seq( mj->excludes, m_new.excludes );
      }
      result.push_back( m_new );
    }
  }

  END_APPLY( result );
}

////////// ApplyFTContent /////////////////////////////////////////////////////

/**
 * Helper function for applyft_content(): checks if the given ft_token_span
 * spans the given token position.
 */
inline bool token_covers_pos( ft_token_span const &ts,
                              ft_token_span::int_t token_pos ) {
  return token_pos >= ts.pos.start && token_pos <= ts.pos.end;
}

void apply_ftcontent( ft_all_matches &am, ft_content_mode::type mode,
                      ft_int start_pos, ft_int end_pos ) {
  BEGIN_APPLY( apply_ftcontent );
  PUT_ENUM( ft_content_mode, mode );
  PUT_ARG( start_pos );
  PUT_ARG( end_pos );
  PUT_ALL_MATCHES( am );

  typedef ft_token_span::int_t int_t;

  if ( mode == ft_content_mode::entire ) {
    for ( ft_all_matches::iterator m = am.begin(); m != am.end(); ) {
      bool every_satisfies = true;
      for ( int_t pos = start_pos; pos <= end_pos; ++pos ) {
        bool some_satisfies = false;
        FOR_EACH( ft_match::includes_t, i, m->includes ) {
          if ( i->is_contiguous && token_covers_pos( *i, pos ) ) {
            some_satisfies = true;
            break;
          }
        }
        if ( !some_satisfies ) {
          every_satisfies = false;
          break;
        }
      }
      if ( every_satisfies )
        ++m;
      else
        m = am.erase( m );
    }
  } else {
    int_t const pos = mode == ft_content_mode::at_start ? start_pos : end_pos;

    for ( ft_all_matches::iterator m = am.begin(); m != am.end(); ) {
      bool some_satisfies = false;
      FOR_EACH( ft_match::includes_t, i, m->includes ) {
        if ( token_covers_pos( *i, pos ) ) {
          some_satisfies = true;
          break;
        }
      }
      if ( some_satisfies )
        ++m;
      else
        m = am.erase( m );
    }
  }

  END_APPLY( am );
}

////////// ApplyFTDistance ////////////////////////////////////////////////////

/**
 * Helper function for apply_ftdistance(): computes the distance of N between 2
 * ft_token_spans where N is specified by the pointer-to-member.
 */
static ft_int distance( ft_token_span const &tsi, ft_token_span const &tsj,
                        ft_token_span::start_end_ptr sep ) {
  ft_token_span const *p1, *p2;
  if ( tsi > tsj )                      // do it this way to remain "stable"
    p1 = &tsj, p2 = &tsi;
  else
    p1 = &tsi, p2 = &tsj;
  return (p2->*sep).start - (p1->*sep).end - 1;
}

void apply_ftdistance( ft_all_matches const &am,
                       ft_int at_least, ft_int at_most,
                       ft_unit::type unit, ft_all_matches &result ) {
  BEGIN_APPLY( apply_ftdistance );
  PUT_ARG( at_least );
  PUT_ARG( at_most );
  PUT_ENUM( ft_unit, unit );
  PUT_ALL_MATCHES( am );

  ft_token_span::start_end_ptr const sep = get_sep_for( unit );
  FOR_EACH( ft_all_matches, m, am ) {
    bool every_satisfies = true;
    if ( m->includes.size() > 1 ) {
      m->sort_includes();
      FOR_EACH( ft_match::includes_t, i, m->includes ) {
        ft_match::includes_t::const_iterator j = i;
        if ( ++j == m->includes.end() )
          break;
        ft_int const d = distance( *i, *j, sep );
        if ( d < at_least || d > at_most ) {
          every_satisfies = false;
          break;
        }
      }
    }
    if ( every_satisfies ) {
      ft_match m_new;
      join_includes( m->includes, m_new.includes );
      FOR_EACH( ft_match::excludes_t, e, m->excludes ) {
        FOR_EACH( ft_match::includes_t, i, m->includes ) {
          ft_int const d = distance( *i, *e, sep );
          if ( d >= at_least && d <= at_most ) {
            m_new.excludes.push_back( *e );
            break;
          }
        }
      }
      result.push_back( m_new );
    }
  }

  END_APPLY( result );
}

////////// ApplyFTMildNot /////////////////////////////////////////////////////

void apply_ftmild_not( ft_all_matches const &ami, ft_all_matches const &amj,
                       ft_all_matches &result ) {

  BEGIN_APPLY( apply_ftmild_not );
  PUT_ALL_MATCHES( ami );
  PUT_ALL_MATCHES( amj );

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

  END_APPLY( result );
}

////////// ApplyFTOr //////////////////////////////////////////////////////////

void apply_ftor( ft_all_matches const &ami, ft_all_matches const &amj,
                 ft_all_matches &result ) {
  BEGIN_APPLY( apply_ftor );
  PUT_ALL_MATCHES( ami );
  PUT_ALL_MATCHES( amj );

  copy_seq( ami, result );
  copy_seq( amj, result );

  END_APPLY( result );
}

////////// ApplyFTOrder ///////////////////////////////////////////////////////

/**
 * Helper function for apply_ftorder(): checks whether the given two string
 * matches are ordered.
 */
inline bool ordered( ft_string_match const &smi, ft_string_match const &smj ) {
  return
    ( smi.pos.start <= smj.pos.start && smi.query_pos <= smj.query_pos ) ||
    ( smi.pos.start >= smj.pos.start && smi.query_pos >= smj.query_pos );
}

void apply_ftorder( ft_all_matches const &am, ft_all_matches &result ) {
  BEGIN_APPLY( apply_ftorder );
  PUT_ALL_MATCHES( am );

  FOR_EACH( ft_all_matches, m, am ) {
    bool every_satisfies = true;
    FOR_EACH( ft_match::includes_t, i1, m->includes ) {
      FOR_EACH( ft_match::includes_t, i2, m->includes ) {
        if ( &*i1 == &*i2 )
          continue;
        if ( !ordered( *i1, *i2 ) ) {
          every_satisfies = false;
          break;
        }
      }
    }
    if ( every_satisfies ) {
      ft_match m_new;
      copy_seq( m->includes, m_new.includes );
      FOR_EACH( ft_match::excludes_t, e, m->excludes ) {
        FOR_EACH( ft_match::includes_t, i, m->includes ) {
          if ( ordered( *e, *i ) )
            m_new.excludes.push_back( *e );
        }
      }
      result.push_back( m_new );
    }
  }

  END_APPLY( result );
}

////////// ApplyFTScope ///////////////////////////////////////////////////////

static void apply_ftscope_diff( ft_all_matches const &am,
                                ft_token_span::start_end_ptr sep,
                                ft_all_matches &result ) {
  BEGIN_APPLY( apply_ftscope_diff );
  PUT_ALL_MATCHES( am );

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

  END_APPLY( result );
}

/**
 * Helper function for apply_ftscope_same(): checks if every start
 * pos/sent/para equals the given start.
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
  BEGIN_APPLY( apply_ftscope_same );
  PUT_ALL_MATCHES( am );

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

  END_APPLY( result );
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

////////// ApplyFTTimes ///////////////////////////////////////////////////////

/**
 * Finds all combinations of exactly \a k elements from \a ms and, for each
 * such combination, constructs a match whose children are copies of all the
 * children of all the elements in the combination.
 *
 * @param ms      The match-sequence to form combinations of.
 * @param k       The number of combinations of elements.
 * @param result  The cumulative result.
 *
 * @return Returns the sequence of all such matches.
 */
static void form_combinations( ft_match_seq const &ms, ft_int k,
                               ft_match_seq &result ) {
  if ( !k ) {
    result.push_back( ft_match() );
    return;
  }
  ft_int const count = ms.size();
  if ( count < k )
    return;
  if ( count == k )
    copy_seq( ms, result );
  else {
    ft_match_seq rest( ms );
    ft_match const first = POP_FRONT( rest );
    form_combinations( rest, k, result );

    ft_match_seq temp;
    form_combinations( rest, k - 1, temp );
    FOR_EACH( ft_match_seq, combination, temp ) {
      ft_match m_new;
      copy_seq( first.includes, m_new.includes );
      copy_seq( first.excludes, m_new.excludes );
      copy_seq( combination->includes, m_new.includes );
      copy_seq( combination->excludes, m_new.excludes );
      result.push_back( m_new );
    }
  }
}

/**
 * Finds all combinations of \a times or more elements from \a ms and, for each
 * such combination, constructs a match whose children are copies of all the
 * children of all the elements in the combination.
 *
 * @param ms      The match-sequence to form combinations of.
 * @param times   The number of combinations of elements.
 * @param result  The result.
 *
 * @return Return the sequence of all such matches.
 */
static void form_combinations_at_least( ft_match_seq const &ms, ft_int times,
                                        ft_match_seq &result ) {
  ft_int const count = ms.size();
  for ( ft_int k = times; k <= count; ++k ) {
    form_combinations( ms, k, result );
  }
}

/**
 * Finds all combinations of at least \a at_least and at most \a at_most
 * elements from \a ms and, for each such combination, constructs a match whose
 * children are copies of all the children of all the elements in the
 * combination.
 *
 * @param ms        The match-sequence to form combinations of.
 * @param at_least  The least number of combinations of elements.
 * @param at_most   The most number of combinations of elements.
 * @param result    The result.
 *
 * @return Return the sequence of all such matches.
 */
static void form_range( ft_match_seq const &ms, ft_int at_least, ft_int at_most,
                        ft_match_seq &result ) {
  if ( at_least <= at_most ) {
    ft_all_matches ami, amj;
    form_combinations_at_least( ms, at_least, ami );
    form_combinations_at_least( ms, at_most + 1, amj );
    apply_ftunary_not( amj );
    apply_ftand( ami, amj, result );
  }
}

void apply_fttimes( ft_all_matches const &am, ft_range_mode::type mode,
                    ft_int at_least, ft_int at_most, ft_all_matches &result ) {
  BEGIN_APPLY( apply_fttimes );
  PUT_ENUM( ft_range_mode, mode );
  PUT_ARG( at_least );
  PUT_ARG( at_most );
  PUT_ALL_MATCHES( am );

  if ( !all_empty( am, &ft_match::excludes ) )
    ZORBA_ERROR( XPST0003 );

  if ( mode == ft_range_mode::at_least )
    form_combinations_at_least( am, at_least, result );
  else
    form_range( am, at_least, at_most, result );

  END_APPLY( result );
}

////////// ApplyFTUnaryNot ////////////////////////////////////////////////////

void apply_ftunary_not( ft_all_matches &am ) {
  BEGIN_APPLY( apply_ftunary_not );
  PUT_ALL_MATCHES( am );

  if ( am.empty() )
    am.push_back( ft_match() );
  else
    MUTATE_EACH( ft_all_matches, m, am )
      m->includes.swap( m->excludes );

  END_APPLY( am );
}

////////// ApplyFTWords ///////////////////////////////////////////////////////

typedef list<ft_all_matches> ft_all_matches_seq;

/**
 * Helper function for apply_ftwords(): finds the max query_pos among all the
 * match's include/exclude lists.
 */
static ft_string_match::int_t max_query_pos( ft_all_matches const &am ) {
  typedef ft_string_match::int_t int_t;
  int_t result = numeric_limits<int_t>::min();
  FOR_EACH( ft_all_matches, m, am ) {
    int_t const mi = max( m->includes, &ft_string_match::query_pos );
    if ( mi > result )
      result = mi;
    int_t const me = max( m->excludes, &ft_string_match::query_pos );
    if ( me > result )
      result = me;
  }
  return result;
}

static void apply_query_tokens_as_phrase( FTTokenIterator &search_ctx,
                                          FTTokenIterator &query_tokens,
                                          FTToken::int_t query_pos,
                                          ftmatch_options const &options,
                                          ft_all_matches &result ) {
  BEGIN_APPLY( apply_query_tokens_as_phrase );
  PUT_ARG( query_pos );

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

  END_APPLY( result );
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

static void apply_ftwords_phrase( FTTokenIterator &search_ctx,
                                  FTQueryItemSeq &query_items,
                                  FTToken::int_t query_pos,
                                  ftmatch_options const &options,
                                  ft_all_matches &result ) {
  FTQueryItemSeqIterator query_tokens( query_items );
  if ( !query_tokens.empty() ) {
    BEGIN_APPLY( apply_ftwords_phrase );
    PUT_ARG( query_pos );

    apply_query_tokens_as_phrase(
      search_ctx, query_tokens, query_pos, options, result
    );

    END_APPLY( result );
  }
}

static void apply_ftwords_all( FTTokenIterator &search_ctx,
                               FTQueryItemSeq &query_items,
                               FTToken::int_t query_pos,
                               ftmatch_options const &options,
                               ft_all_matches &result ) {
  if ( !query_items.empty() ) {
    BEGIN_APPLY( apply_ftwords_all );
    PUT_ARG( query_pos );

    FTQueryItemSeq first_query_item;
    move_front_to_back( query_items, first_query_item );

    ft_all_matches first_am;
    apply_ftwords_phrase(
      search_ctx, first_query_item, query_pos, options, first_am
    );

    if ( !query_items.empty() ) {
      FTToken::int_t const temp_pos = max_query_pos( first_am );
      if ( is_max_valid( temp_pos ) )
        query_pos = temp_pos + 1;
      ft_all_matches rest_am;
      apply_ftwords_all(
        search_ctx, query_items, query_pos, options, rest_am
      );
      if ( rest_am.empty() )
        result.swap( first_am );
      else
        apply_ftand( first_am, rest_am, result );
    } else {
      result.swap( first_am );
    }

    END_APPLY( result );
  }
}

static void apply_ftwords_any( FTTokenIterator &search_ctx,
                               FTQueryItemSeq &query_items,
                               FTToken::int_t query_pos,
                               ftmatch_options const &options,
                               ft_all_matches &result ) {
  if ( !query_items.empty() ) {
    BEGIN_APPLY( apply_ftwords_any );
    PUT_ARG( query_pos );

    FTQueryItemSeq first_query_item;
    move_front_to_back( query_items, first_query_item );

    ft_all_matches first_am;
    apply_ftwords_phrase(
      search_ctx, first_query_item, query_pos, options, first_am
    );

    FTToken::int_t const temp_pos = max_query_pos( first_am );
    if ( is_max_valid( temp_pos ) )
      query_pos = temp_pos + 1;

    ft_all_matches rest_am;
    apply_ftwords_any( search_ctx, query_items, query_pos, options, rest_am );
    if ( rest_am.empty() )
      result.swap( first_am );
    else
      apply_ftor( first_am, rest_am, result );

    END_APPLY( result );
  }
}

/**
 * Helper function for apply_ftwords(): this function combines
 * \c ApplyFTWordsAnyWord() and \c ApplyFTWordsAllWord() since the code is the
 * same except that the former calls \c MakeDisjunction() and the latter calls
 * \c MakeConjunction().
 */
static void apply_ftwords_xxx_word( FTTokenIterator &search_ctx,
                                    FTQueryItemSeq &query_items,
                                    FTToken::int_t query_pos,
                                    ftmatch_options const &options,
                                    apply_fn_3arg_t apply_fn,
                                    ft_all_matches &result ) {
  FTQueryItemSeqIterator query_tokens( query_items );
  if ( !query_tokens.empty() ) {
    BEGIN_APPLY( apply_ftwords_xxx_word );
    PUT_ARG( query_pos );

    ft_all_matches_seq all_am_seq;
    for ( FTToken::int_t pos = 0; query_tokens.hasNext();
          ++pos, query_tokens.next() ) {

      FTQueryItemSeq qi_seq;
      qi_seq.push_back( query_tokens.currentItem() );
      FTQueryItemSeqIterator query_token( qi_seq );

      ft_all_matches am;
      apply_query_tokens_as_phrase(
        search_ctx, query_token, query_pos + pos, options, am
      );
      all_am_seq.push_back( am );
    }
    ft_all_matches const first_am = POP_FRONT( all_am_seq );
    make_conj_disj( first_am, all_am_seq, apply_fn, result );

    END_APPLY( result );
  }
}

void apply_ftwords( FTTokenIterator &search_ctx,
                    FTQueryItemSeq &query_items,
                    FTToken::int_t query_pos,
                    ft_anyall_mode::type mode,
                    ftmatch_options const &options,
                    ft_all_matches &result ) {
  switch ( mode ) {
    case ft_anyall_mode::any:
      apply_ftwords_any( search_ctx, query_items, query_pos, options, result );
      break;
    case ft_anyall_mode::any_word:
      apply_ftwords_xxx_word(
        search_ctx, query_items, query_pos, options, &apply_ftor, result
      );
      break;
    case ft_anyall_mode::all:
      apply_ftwords_all( search_ctx, query_items, query_pos, options, result );
      break;
    case ft_anyall_mode::all_words:
      apply_ftwords_xxx_word(
        search_ctx, query_items, query_pos, options, &apply_ftand, result
      );
      break;
    case ft_anyall_mode::phrase:
      apply_ftwords_phrase(
        search_ctx, query_items, query_pos, options, result
      );
      break;
  }
}

////////// ApplyFTWindow //////////////////////////////////////////////////////

void apply_ftwindow( ft_all_matches const &am, ft_int window_size,
                     ft_unit::type unit, ft_all_matches &result ) {
  BEGIN_APPLY( apply_ftwindow );
  PUT_ARG( window_size );
  PUT_ENUM( ft_unit, unit );
  PUT_ALL_MATCHES( am );

  typedef ft_token_span::int_t int_t;

  ft_token_span::start_end_ptr const sep = get_sep_for( unit );
  FOR_EACH( ft_all_matches, m, am ) {
    int_t const min_pos = MIN_TS( m->includes, pos, start );
    int_t const max_pos = MAX_TS( m->includes, pos, end );
    for ( int_t win_start_pos = max_pos - window_size + 1;
          win_start_pos < min_pos; ++win_start_pos ) {
      int_t const win_end_pos = win_start_pos + window_size - 1;
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

  END_APPLY( result );
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
