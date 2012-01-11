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

#include <limits>
#include <set>
#include <vector>

#include <zorba/tokenizer.h>
#include <context/uri_resolver.h>

#include "compiler/expression/ftnode.h"
#include "diagnostics/dict.h"
#include "diagnostics/xquery_diagnostics.h"
#include "store/api/item.h"
#include "store/api/store.h"
#include "store/api/item_factory.h"
#include "system/globalenv.h"
#include "util/cxx_util.h"
#include "util/indent.h"
#include "util/stl_util.h"
#include "zorbamisc/ns_consts.h"

#ifndef NDEBUG
# include "system/properties.h"
# define DOUT             Properties::instance()->debug_out()
# define TRACE_FULL_TEXT  Properties::instance()->traceFulltext()
#endif /* NDEBUG */

#include "apply.h"
#include "ft_single_token_iterator.h"
#include "ft_token_matcher.h"
#include "ft_token_seq_iterator.h"
#include "ft_token_span.h"
#include "ftcontains_visitor.h"
#include "thesaurus.h"

#ifdef WIN32
// Windows annoyingly defines these as macros.
# undef max
# undef min
#endif /* WIN32 */

using namespace std;
using namespace zorba::locale;

namespace zorba {

////////// Debugging macros ///////////////////////////////////////////////////

#ifndef NDEBUG

/**
 * An instance of this class is ued to perform RAII (Resource Acquisition Is
 * Initialization) to guarantee that the result is printed and that the proper
 * number of "dec_indent" calls are done regardless of how the enclosing
 * function exits.
 */
class trace_helper {
public:
  trace_helper( char const *fn_name, ft_all_matches &result ) :
    result_( result )
  {
    if ( TRACE_FULL_TEXT )
      DOUT << '\n' << indent << fn_name << "()\n" << inc_indent;
  }

  ~trace_helper() {
    if ( TRACE_FULL_TEXT )
      DOUT  << indent << "RESULT\n" << inc_indent << result_ << dec_indent
            << dec_indent;
  }

private:
  ft_all_matches &result_;
};

#define TRACE_APPLY(RESULT) \
  trace_helper const trace_helper_##__LINE__( __FUNCTION__, RESULT )

#define PUT_ALL_MATCHES(ARG)                \
  if ( !TRACE_FULL_TEXT ) ; else            \
  DOUT << indent << "ARG " #ARG "\n"        \
       << inc_indent << (ARG) << dec_indent

#define PUT_ARG(ARG)                                  \
  if ( !TRACE_FULL_TEXT ) ; else                      \
  DOUT << indent << "ARG " #ARG "=" << (ARG) << endl

#else /* NDEBUG */

#define TRACE_APPLY(RESULT)   /* nothing */
#define PUT_ALL_MATCHES(ARG)  /* nothing */
#define PUT_ARG(ARG)          /* nothing */

#endif /* NDEBUG */

////////// Typedefs ///////////////////////////////////////////////////////////

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
 * Shorthand for calling all_empty() with an ft_match (N)ame.
 */
#define ALL_EMPTY_N(ALL_MATCHES,SMP_NAME) \
  all_empty( ALL_MATCHES, &ft_match::SMP_NAME )

/**
 * Given a sequence of ft_string_include objects, constructs a set of all the
 * positions spanned by all the contained tokens.
 */
static void covered_include_positions( ft_match::includes_t const &includes,
                                       ft_pos_set &result ) {
  FOR_EACH( ft_match::includes_t, i, includes )
    for ( ft_token_span::int_t pos = i->pos.start; pos <= i->pos.end; ++pos )
      result.insert( pos );
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
template<typename IntType> inline bool is_max_valid( IntType n ) {
  return n != numeric_limits<IntType>::min();
}

/**
 * Computes max(N) from the given sequence of struct objects having an IntType
 * member.
 */
template<class SequenceType,typename IntType>
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
template<class FTTokenSpanSequenceType>
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

/**
 * Computes min(N) from the given sequence of ft_token_spans where N is
 * specified by the pointers-to-members.
 */
template<class FTTokenSpanSequenceType>
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

/**
 * Shorthand for calling a function with a sep (P)ointer and an ip (N)ame.
 */
#define F_PN(FN_NAME,SEQ,SEP,IP_NAME) \
  FN_NAME( SEQ, SEP, &ft_token_span::start_end::IP_NAME )

/**
 * Shorthand for calling a function with a sep (N)ame and an ip (N)ame.
 */
#define F_NN(FN_NAME,SEQ,SEP_NAME,IP_NAME) \
  F_PN( FN_NAME, SEQ, &ft_token_span::SEP_NAME, IP_NAME )

#define MAX_PN(SEQ,SEP,IP_NAME)       F_PN( max, SEQ, SEP, IP_NAME)
#define MAX_NN(SEQ,SEP_NAME,IP_NAME)  F_NN( max, SEQ, SEP_NAME, IP_NAME)
#define MIN_PN(SEQ,SEP,IP_NAME)       F_PN( min, SEQ, SEP, IP_NAME )
#define MIN_NN(SEQ,SEP_NAME,IP_NAME)  F_NN( min, SEQ, SEP_NAME, IP_NAME )

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

  int_t const min_pos = MIN_NN( includes, pos, start );
  int_t const max_pos = MAX_NN( includes, pos, end );

  bool is_contiguous = true;
  FOR_EACH( ft_match::includes_t, i, includes ) {
    if ( !i->is_contiguous ) {
      is_contiguous = false;
      break;
    }
  }
  if ( is_contiguous ) {
    ft_pos_set pos_set;
    covered_include_positions( includes, pos_set );
    for ( int_t pos = min_pos; pos <= max_pos; ++pos ) {
      if ( !ztd::contains( pos_set, pos ) ) {
        is_contiguous = false;
        break;
      }
    }
  }

  ft_string_include si;
  si.pos.start     = min_pos;
  si.pos.end       = max_pos;
  si.sent.start    = MIN_NN( includes, sent, start );
  si.sent.end      = MAX_NN( includes, sent, end   );
  si.para.start    = MIN_NN( includes, para, start );
  si.para.end      = MAX_NN( includes, para, end   );
  si.query_pos     = includes.front().query_pos;
  si.is_contiguous = is_contiguous;
  result.push_back( si );
}

/**
 * Joins all the tokens from the given FTTokenIterator into a single string
 * seperated by spaces.
 *
 * @param tokens The FTTokenIterator to get the tokens to join.
 * @param phrase The result string.
 * @param selector The token value selector to use.
 * @return Returns a pointer to the first token returned by the iterator or \c
 * nullptr if the iterator returned no tokens.
 */
static FTToken const* to_string( FTTokenIterator &tokens, zstring *phrase,
                                 int selector ) {
  FTToken const *t0 = nullptr;
  FTTokenIterator::Mark_t const mark( tokens.pos() );
  for ( FTToken const *t; (t = tokens.next()); ) {
    if ( phrase->empty() )
      t0 = t;
    else
      *phrase += ' ';
    *phrase += t->value( selector );
  }
  tokens.pos( mark );
  return t0;
}

////////// Token matching /////////////////////////////////////////////////////

#define DEBUG_FT_IS_DESCENDANT 0
#define DEBUG_FT_MATCH_TOKENS 0

#if DEBUG_FT_MATCH_TOKENS
static void dump( char const *label, FTTokenIterator &it ) {
  it.reset();
  cout << indent << label;
  FTToken const *t;
  while ( (t = it.next()) )
    cout << *t;
  cout << endl;
}
#endif

/**
 * Returns whether the first Item is a descendent of the second.
 */
static bool is_decendant( store::Item const *i, store::Item const *j ) {
  store::Item const *const j_name = j->getNodeName();
# if DEBUG_FT_IS_DESCENDANT
  cout << "----------------" << endl;
  cout << "is_descendant_of: " << j->show() << endl;
# endif
  while ( i ) {
#   if DEBUG_FT_IS_DESCENDANT
    cout << "i=" << i->show() << endl;
#   endif
    store::Item *const i_name = i->getNodeName();
    if ( i_name && i_name->equals( j_name ) ) {
#     if DEBUG_FT_IS_DESCENDANT
      cout << "--> MATCH" << endl;
#     endif
      return true;
    }
    i = i->getParent();
  }
# if DEBUG_FT_IS_DESCENDANT
  cout << "--> NO MATCH" << endl;
# endif
  return false;
}

/**
 * Matches query tokens against document tokens.
 */
static void match_tokens( FTTokenIterator &doc_tokens,
                          FTTokenIterator &query_tokens,
                          store::Item const *ignore_item,
                          ft_token_matcher const &matcher,
                          ft_token_spans &result ) {
#if DEBUG_FT_MATCH_TOKENS
  dump( "match_tokens(): d_tokens: ", doc_tokens );
  dump( "match_tokens(): q_tokens: ", query_tokens );
#endif
  doc_tokens.reset();
  while ( doc_tokens.hasNext() ) {
    FTTokenIterator::Mark_t mark( doc_tokens.pos() );
    FTToken const *dt;
    store::Item const *dt_item = nullptr;
    bool ignore = false;                // pointless init. to stifle warning

    if ( ignore_item ) {
      //
      // We are ignoring some item: see if this document token's item is a
      // descendant of the ignored item.
      //
      while ( (dt = doc_tokens.next()) ) {
        if ( dt->item() != dt_item ) {
          dt_item = dt->item();
          ignore = is_decendant( dt_item, ignore_item );
        }
        if ( ignore ) {
          //
          // The document token is to be ignored: bump up the mark.
          //
          mark = doc_tokens.pos();
        } else {
          doc_tokens.pos( mark );
          break;
        }
      }
    }

    FTToken const *dt_start = nullptr, *dt_end = nullptr;
    dt_item = nullptr;
    bool matched = false;

    query_tokens.reset();
    while ( (dt = doc_tokens.next()) ) {
      if ( ignore_item ) {
        //
        // We are ignoring some item: see if this document token's item is a
        // descendant of the ignored item.
        //
        if ( dt->item() != dt_item ) {
          dt_item = dt->item();
          ignore = is_decendant( dt_item, ignore_item );
        }
        if ( ignore )
          continue;
      }
      FTToken const *const qt = query_tokens.next();
      if ( !qt )
        break;
      if ( !matcher.match( *dt, *qt ) ) {
        matched = false;
        break;
      }
      matched = true;
      if ( !dt_start )
        dt_start = dt;
      dt_end = dt;
    }

    if ( matched && !query_tokens.hasNext() ) {
      ft_token_span ts;
      ts.pos.start  = dt_start->pos();
      ts.pos.end    = dt_end->pos();
      ts.sent.start = dt_start->sent();
      ts.sent.end   = dt_end->sent();
      ts.para.start = dt_start->para();
      ts.para.end   = dt_end->para();
      result.push_back( ts );
    } else {
      doc_tokens.pos( mark );
      doc_tokens.next();
    }
  }
}

////////// ApplyFTAnd /////////////////////////////////////////////////////////

void apply_ftand( ft_all_matches const &ami, ft_all_matches const &amj,
                  ft_all_matches &result ) {
  TRACE_APPLY( result );
  PUT_ALL_MATCHES( ami );
  PUT_ALL_MATCHES( amj );

  if ( !amj.empty() ) {
    FOR_EACH( ft_all_matches, mi, ami ) {
      FOR_EACH( ft_all_matches, mj, amj ) {
        ft_match m_new;
        ztd::copy_seq( mi->includes, m_new.includes );
        ztd::copy_seq( mi->excludes, m_new.excludes );
        ztd::copy_seq( mj->includes, m_new.includes );
        ztd::copy_seq( mj->excludes, m_new.excludes );
        result.push_back( m_new );
      }
    }
  }
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
  TRACE_APPLY( am );
  PUT_ARG( mode );
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
  TRACE_APPLY( result );
  PUT_ARG( at_least );
  PUT_ARG( at_most );
  PUT_ARG( unit );
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
}

////////// ApplyFTMildNot /////////////////////////////////////////////////////

void apply_ftmild_not( ft_all_matches const &ami, ft_all_matches const &amj,
                       ft_all_matches &result ) {
  TRACE_APPLY( result );
  PUT_ALL_MATCHES( ami );
  PUT_ALL_MATCHES( amj );

  if ( !ALL_EMPTY_N( ami, excludes ) || !ALL_EMPTY_N( amj, excludes ) )
    throw XQUERY_EXCEPTION( err::FTDY0017 );

  if ( ALL_EMPTY_N( amj, includes ) )
    result = ami;
  else {
    typedef list<ft_pos_set> ft_pos_set_cache_t;

    ft_pos_set_cache_t psj_cache( amj.size() );
    FOR_EACH( ft_all_matches, mj, amj ) {
      psj_cache.push_back( ft_pos_set() );
      covered_include_positions( mj->includes, psj_cache.back() );
    }

    FOR_EACH( ft_all_matches, mi, ami ) {
      ft_pos_set psi;
      covered_include_positions( mi->includes, psi );

      bool every_satisfies = true;
      FOR_EACH( ft_pos_set_cache_t, psj, psj_cache ) {
        bool some_satisfies = false;
        FOR_EACH( ft_pos_set, pos, psi ) {
          if ( !ztd::contains( *psj, *pos ) ) {
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
        result.push_back( *mi );
    }
  }
}

////////// ApplyFTOr //////////////////////////////////////////////////////////

void apply_ftor( ft_all_matches const &ami, ft_all_matches const &amj,
                 ft_all_matches &result ) {
  TRACE_APPLY( result );
  PUT_ALL_MATCHES( ami );
  PUT_ALL_MATCHES( amj );

  ztd::copy_seq( ami, result );
  ztd::copy_seq( amj, result );
}

////////// ApplyFTOrder ///////////////////////////////////////////////////////

/**
 * Helper function for apply_ftorder(): checks whether the given two string
 * matches are ordered.
 */
inline bool are_ordered( ft_string_match const &smi,
                         ft_string_match const &smj ) {
  return
    ( smi.pos.start <= smj.pos.start && smi.query_pos <= smj.query_pos ) ||
    ( smi.pos.start >= smj.pos.start && smi.query_pos >= smj.query_pos );
}

void apply_ftorder( ft_all_matches const &am, ft_all_matches &result ) {
  TRACE_APPLY( result );
  PUT_ALL_MATCHES( am );

  FOR_EACH( ft_all_matches, m, am ) {
    bool every_satisfies = true;
    FOR_EACH( ft_match::includes_t, i1, m->includes ) {
      FOR_EACH( ft_match::includes_t, i2, m->includes ) {
        if ( &*i1 != &*i2 && !are_ordered( *i1, *i2 ) ) {
          every_satisfies = false;
          break;
        }
      }
    }
    if ( every_satisfies ) {
      ft_match m_new;
      ztd::copy_seq( m->includes, m_new.includes );
      FOR_EACH( ft_match::excludes_t, e, m->excludes ) {
        FOR_EACH( ft_match::includes_t, i, m->includes ) {
          if ( are_ordered( *e, *i ) )
            m_new.excludes.push_back( *e );
        }
      }
      result.push_back( m_new );
    }
  }
}

////////// ApplyFTScope ///////////////////////////////////////////////////////

/**
 * Helper function for apply_ftscope_diff(): checks whether the given two
 * string matches are in different pos/sent/para.
 */
inline bool different( ft_string_match const &smi, ft_string_match const &smj,
                       ft_token_span::start_end_ptr sep ) {
  return
    ( (smi.*sep).start != (smj.*sep).start ||
      (smi.*sep).start != (smi.*sep).end   ||
      (smj.*sep).start != (smj.*sep).end )
    && (smi.*sep).start > 0 && (smj.*sep).end > 0;
}

static void apply_ftscope_diff( ft_all_matches const &am,
                                ft_token_span::start_end_ptr sep,
                                ft_all_matches &result ) {
  TRACE_APPLY( result );
  PUT_ALL_MATCHES( am );

  FOR_EACH( ft_all_matches, m, am ) {
    //
    // See: http://www.w3.org/Bugs/Public/show_bug.cgi?id=9448
    //
    bool every_satisfies = false;
    if ( m->includes.size() > 1 ) {
      every_satisfies = true;
      FOR_EACH( ft_match::includes_t, i1, m->includes ) {
        FOR_EACH( ft_match::includes_t, i2, m->includes ) {
          if ( &*i1 != &*i2 && !different( *i1, *i2, sep ) ) {
            every_satisfies = false;
            break;
          }
        }
      }
    }
    if ( every_satisfies ) {
      ft_match m_new;
      ztd::copy_seq( m->includes, m_new.includes );
      FOR_EACH( ft_match::excludes_t, e, m->excludes ) {
        FOR_EACH( ft_match::includes_t, i, m->includes ) {
          if ( different( *i, *e, sep ) )
            m_new.excludes.push_back( *e );
        }
      }
      result.push_back( m_new );
    }
  }
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

/**
 * Helper function for apply_ftscope_same(): checks whether the given two
 * string matches are in the same pos/sent/para.
 */
inline bool same( ft_string_match const &smi, ft_string_match const &smj,
                  ft_token_span::start_end_ptr sep ) {
  return
    (smi.*sep).start == (smj.*sep).start &&
    (smi.*sep).start == (smi.*sep).end   &&
    (smj.*sep).start == (smj.*sep).end   &&
    (smi.*sep).start > 0 && (smj.*sep).start > 0;
}

static void apply_ftscope_same( ft_all_matches const &am,
                                ft_token_span::start_end_ptr sep,
                                ft_all_matches &result ) {
  TRACE_APPLY( result );
  PUT_ALL_MATCHES( am );

  FOR_EACH( ft_all_matches, m, am ) {
    bool every_satisfies = true;
    FOR_EACH( ft_match::includes_t, i1, m->includes ) {
      FOR_EACH( ft_match::includes_t, i2, m->includes ) {
        if ( &*i1 != &*i2 && !same( *i1, *i2, sep ) ) {
          every_satisfies = false;
          break;
        }
      }
    }
    if ( every_satisfies ) {
      ft_match m_new;
      ztd::copy_seq( m->includes, m_new.includes );
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

void apply_ftscope( ft_all_matches const &am, ft_scope::type scope,
                    ft_big_unit::type unit, ft_all_matches &result ) {
  TRACE_APPLY( result );
  PUT_ALL_MATCHES( am );
  PUT_ARG( scope );
  PUT_ARG( unit );

  ft_token_span::start_end_ptr sep = nullptr;
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
  ft_int const count = (ft_int)ms.size();
  if ( count < k )
    return;
  if ( count == k )
    ztd::copy_seq( ms, result );
  else {
    ft_match_seq rest( ms );
    ft_match const first( ztd::pop_front( rest ) );
    form_combinations( rest, k, result );

    ft_match_seq temp;
    form_combinations( rest, k - 1, temp );
    FOR_EACH( ft_match_seq, combination, temp ) {
      ft_match m_new;
      ztd::copy_seq( first.includes, m_new.includes );
      ztd::copy_seq( first.excludes, m_new.excludes );
      ztd::copy_seq( combination->includes, m_new.includes );
      ztd::copy_seq( combination->excludes, m_new.excludes );
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
  ft_int const count = (ft_int)ms.size();
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
                        ft_all_matches &result ) {
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
  TRACE_APPLY( result );
  PUT_ARG( mode );
  PUT_ARG( at_least );
  PUT_ARG( at_most );
  PUT_ALL_MATCHES( am );

  if ( !ALL_EMPTY_N( am, excludes ) )
    throw XQUERY_EXCEPTION(
      err::XPST0003, ERROR_PARAMS( ZED( AllMatchesHasExcludes ) )
    );

  if ( mode == ft_range_mode::at_least )
    form_combinations_at_least( am, at_least, result );
  else
    form_range( am, at_least, at_most, result );
}

////////// ApplyFTUnaryNot ////////////////////////////////////////////////////

void apply_ftunary_not( ft_all_matches &am ) {
  TRACE_APPLY( am );
  PUT_ALL_MATCHES( am );

  if ( am.empty() )
    am.push_back( ft_match() );
  else
    MUTATE_EACH( ft_all_matches, m, am )
      m->includes.swap( m->excludes );
}

////////// ApplyFTWords ///////////////////////////////////////////////////////

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

void ftcontains_visitor::
apply_query_tokens_as_phrase( FTTokenIterator &query_tokens,
                              FTToken::int_t query_pos,
                              store::Item const *ignore_item,
                              ftmatch_options const &options,
                              ft_token_matcher const &matcher,
                              ft_all_matches &result ) {
  TRACE_APPLY( result );
  PUT_ARG( query_pos );

  if ( ftthesaurus_option const *topt = get_thesaurus_option( &options ) ) {
    zstring query_phrase;
    FTToken const *const qt0 =
      to_string( query_tokens, &query_phrase, FTToken::lower );
    if ( qt0 ) {
      query_item_star_t synonyms;
      apply_thesaurus_option( topt, query_phrase, *qt0, synonyms );

      ftmatch_options options_no_thesaurus( options );
      options_no_thesaurus.set_thesaurus_option( nullptr );

      apply_ftwords_any(
        synonyms, query_pos, ignore_item, options_no_thesaurus, matcher, result
      );
      return;
    }
  }

  ft_token_spans token_spans;
  match_tokens(
    *search_ctx_.getp(), query_tokens, ignore_item, matcher, token_spans
  );
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

static void make_conj_disj( ft_all_matches const &cur_res,
                            ft_all_matches_seq &rest, apply_binary_fn apply_fn,
                            ft_all_matches &result ) {
  if ( rest.empty() )
    result = cur_res;
  else {
    ft_all_matches const first_am( ztd::pop_front( rest ) );
    ft_all_matches new_cur_res;
    apply_fn( cur_res, first_am, new_cur_res );
    make_conj_disj( new_cur_res, rest, apply_fn, result );
  }
}

void ftcontains_visitor::
apply_ftwords_phrase( query_item_star_t &query_items, FTToken::int_t query_pos,
                      store::Item const *ignore_item,
                      ftmatch_options const &options,
                      ft_token_matcher const &matcher,
                      ft_all_matches &result ) {
  query_item_star_iterator query_tokens( query_items );
  if ( query_tokens.hasNext() ) {
    apply_query_tokens_as_phrase(
      query_tokens, query_pos, ignore_item, options, matcher, result
    );
  }
}

void ftcontains_visitor::
apply_ftwords_all( query_item_star_t &query_items, FTToken::int_t query_pos,
                   store::Item const *ignore_item,
                   ftmatch_options const &options,
                   ft_token_matcher const &matcher, ft_all_matches &result ) {
  if ( !query_items.empty() ) {
    TRACE_APPLY( result );
    PUT_ARG( query_pos );

    query_item_star_t first_query_item;
    ztd::move_front_to_back( query_items, first_query_item );

    ft_all_matches first_am;
    apply_ftwords_phrase(
      first_query_item, query_pos, ignore_item, options, matcher, first_am
    );

    if ( !query_items.empty() ) {
      FTToken::int_t const temp_pos = max_query_pos( first_am );
      if ( is_max_valid( temp_pos ) )
        query_pos = temp_pos + 1;
      ft_all_matches rest_am;
      apply_ftwords_all(
        query_items, query_pos, ignore_item, options, matcher, rest_am
      );
      apply_ftand( first_am, rest_am, result );
    } else {
      result.swap( first_am );
    }
  }
}

void ftcontains_visitor::
apply_ftwords_any( query_item_star_t &query_items, FTToken::int_t query_pos,
                   store::Item const *ignore_item,
                   ftmatch_options const &options,
                   ft_token_matcher const &matcher, ft_all_matches &result ) {
  if ( !query_items.empty() ) {
    TRACE_APPLY( result );
    PUT_ARG( query_pos );

    query_item_star_t first_query_item;
    ztd::move_front_to_back( query_items, first_query_item );

    ft_all_matches first_am;
    apply_ftwords_phrase(
      first_query_item, query_pos, ignore_item, options, matcher, first_am
    );

    FTToken::int_t const temp_pos = max_query_pos( first_am );
    if ( is_max_valid( temp_pos ) )
      query_pos = temp_pos + 1;

    ft_all_matches rest_am;
    apply_ftwords_any(
      query_items, query_pos, ignore_item, options, matcher, rest_am
    );
    if ( rest_am.empty() )
      result.swap( first_am );
    else
      apply_ftor( first_am, rest_am, result );
  }
}

/**
 * Helper function for apply_ftwords(): this function combines
 * \c ApplyFTWordsAnyWord() and \c ApplyFTWordsAllWord() since the code is the
 * same except that the former calls \c MakeDisjunction() and the latter calls
 * \c MakeConjunction().
 */
void ftcontains_visitor::
apply_ftwords_xxx_word( query_item_star_t &query_items,
                        FTToken::int_t query_pos,
                        store::Item const *ignore_item,
                        ftmatch_options const &options,
                        ft_token_matcher const &matcher,
                        apply_binary_fn apply_fn, ft_all_matches &result ) {
  query_item_star_iterator query_tokens( query_items );
  if ( query_tokens.hasNext() ) {
    TRACE_APPLY( result );
    PUT_ARG( query_pos );

    ft_all_matches_seq all_am_seq;
    FTToken const *t;

    for ( FTToken::int_t pos = 0; (t = query_tokens.next()); ++pos ) {
      FTSingleTokenIterator query_token( *t, query_tokens.begin() + pos );
      ft_all_matches am;
      apply_query_tokens_as_phrase(
        query_token, query_pos + pos, ignore_item, options, matcher, am
      );
      all_am_seq.push_back( am );
    }

    ft_all_matches first_am;
    if ( !all_am_seq.empty() )
      first_am = ztd::pop_front( all_am_seq );
    make_conj_disj( first_am, all_am_seq, apply_fn, result );
  }
}

void ftcontains_visitor::
apply_ftwords( query_item_star_t &query_items, FTToken::int_t query_pos,
               store::Item const *ignore_item, ft_anyall_mode::type mode,
               ftmatch_options const &options, ft_all_matches &result ) {
  ft_token_matcher const matcher( options, static_ctx_ );
  switch ( mode ) {
    case ft_anyall_mode::any:
      apply_ftwords_any(
        query_items, query_pos, ignore_item, options, matcher, result
      );
      break;
    case ft_anyall_mode::any_word:
      apply_ftwords_xxx_word(
        query_items, query_pos, ignore_item, options, matcher, &apply_ftor,
        result
      );
      break;
    case ft_anyall_mode::all:
      apply_ftwords_all(
        query_items, query_pos, ignore_item, options, matcher, result
      );
      break;
    case ft_anyall_mode::all_words:
      apply_ftwords_xxx_word(
        query_items, query_pos, ignore_item, options, matcher, &apply_ftand,
        result
      );
      break;
    case ft_anyall_mode::phrase:
      apply_ftwords_phrase(
        query_items, query_pos, ignore_item, options, matcher, result
      );
      break;
    default:
      ZORBA_ASSERT( false );
  }
}

////////// ApplyThesaurusOption ///////////////////////////////////////////////

namespace {

/**
 * This is used to tokenize synonym phrases returned from thesaurus look-ups.
 */
class thesaurus_callback : public Tokenizer::Callback {
public:
  thesaurus_callback( int token_no, iso639_1::type lang,
                      FTTokenSeqIterator::FTTokens &tokens ) :
    tokens_( tokens ), token_no_( token_no ), lang_( lang )
  {
  }

  void operator()( char const *utf8_s, size_type utf8_len, size_type,
                   size_type, size_type, void* ) {
    FTToken const t( utf8_s, (int)utf8_len, token_no_, lang_ );
    tokens_.push_back( t );
  }

private:
  FTTokenSeqIterator::FTTokens &tokens_;
  int const token_no_;
  iso639_1::type const lang_;
};

} // anonymous namespace

void ftcontains_visitor::
lookup_thesaurus( ftthesaurus_id const &tid, zstring const &query_phrase,
                  FTToken const &qt0, query_item_star_t &result ) {
  ft_int at_least, at_most;
  if ( ftrange const *const levels = tid.get_levels() )
    eval_ftrange( *levels, &at_least, &at_most );
  else
    at_least = 0, at_most = numeric_limits<ft_int>::max();

  zstring const &uri = tid.get_uri();

  zstring error_msg;
  auto_ptr<internal::Resource> rsrc = static_ctx_.resolve_uri(
    uri, internal::ThesaurusEntityData( qt0.lang() ), error_msg
  );
  if ( !rsrc.get() )
    throw XQUERY_EXCEPTION( err::FTST0018, ERROR_PARAMS( uri ) );

  internal::Thesaurus::ptr thesaurus(
    dynamic_cast<internal::Thesaurus*>( rsrc.release() )
  );
  ZORBA_ASSERT( thesaurus );

  internal::Thesaurus::iterator::ptr tresult(
    thesaurus->lookup(
      query_phrase, tid.get_relationship(), at_least, at_most
    )
  );
  if ( !tresult )
    return;

  FTTokenSeqIterator::FTTokens synonyms;
  thesaurus_callback cb( qt0.pos(), qt0.lang(), synonyms );

  Tokenizer::Numbers tno;
  Tokenizer::ptr tokenizer(
    GENV_STORE.getTokenizerProvider()->getTokenizer( qt0.lang(), tno )
  );

  for ( zstring synonym; tresult->next( &synonym ); ) {
    synonyms.clear();
    tokenizer->tokenize(
      synonym.data(), synonym.size(), qt0.lang(), false, cb
    );
    query_item_t const query_item( new FTTokenSeqIterator( synonyms ) );
    result.push_back( query_item );
  }
}

void ftcontains_visitor::
apply_thesaurus_option( ftthesaurus_option const *topt,
                        zstring const &query_phrase, FTToken const &qt0,
                        query_item_star_t &result, bool check_sctx ) {
  ftthesaurus_id const *const default_tid = topt->get_default_thesaurus_id();
  if ( default_tid ) {
    ftmatch_options const *const sctx_mo = static_ctx_.get_match_options();
    if ( check_sctx && sctx_mo ) {
      ftthesaurus_option const *sctx_topt = get_thesaurus_option( sctx_mo );
      if ( sctx_topt )
        apply_thesaurus_option( sctx_topt, query_phrase, qt0, result, false );
    } else {
      lookup_thesaurus( *default_tid, query_phrase, qt0, result );
    }
  }

  FOR_EACH( ftthesaurus_option::thesaurus_id_list_t, pptid,
            topt->get_thesaurus_id_list() ) {
    lookup_thesaurus( **pptid, query_phrase, qt0, result );
  }
}

////////// ApplyFTWindow //////////////////////////////////////////////////////

void apply_ftwindow( ft_all_matches const &am, ft_int window_size,
                     ft_unit::type unit, ft_all_matches &result ) {
  TRACE_APPLY( result );
  PUT_ARG( window_size );
  PUT_ARG( unit );
  PUT_ALL_MATCHES( am );

  //
  // Token positions are unsigned, but we must use signed arithmetic here:
  // declare a signed integer type and cast all values to it.
  //
  typedef long signed_t;

  signed_t const s_window_size = window_size;
  ft_token_span::start_end_ptr const sep = get_sep_for( unit );

  FOR_EACH( ft_all_matches, m, am ) {
    signed_t const s_min_pos = MIN_PN( m->includes, sep, start );
    signed_t const s_max_pos = MAX_PN( m->includes, sep, end );
    for ( signed_t s_win_start_pos = s_max_pos - s_window_size + 1;
          s_win_start_pos <= s_min_pos; ++s_win_start_pos ) {
      signed_t const s_win_end_pos = s_win_start_pos + s_window_size - 1;
      ft_match m_new;
      join_includes( m->includes, m_new.includes );
      FOR_EACH( ft_match::excludes_t, e, m->excludes ) {
        signed_t const s_start = ((*e).*sep).start;
        signed_t const s_end   = ((*e).*sep).end;
        if ( s_start >= s_win_start_pos && s_end <= s_win_end_pos )
          m_new.excludes.push_back( *e );
      }
      result.push_back( m_new );
    }
  }
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
