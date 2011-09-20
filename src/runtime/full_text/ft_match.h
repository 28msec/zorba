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
#pragma once
#ifndef ZORBA_FULL_TEXT_FT_MATCH_H
#define ZORBA_FULL_TEXT_FT_MATCH_H

#include <algorithm>
#include <list>

#include "ft_token_span.h"

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

/**
 * An %ft_string_match is a possible match of a sequence of query tokens with a
 * corresponding sequence of tokens in a document.  An %ft_string_match may be
 * an ft_string_include or ft_string_exclude.
 */
struct ft_string_match : ft_token_span {

  /**
   * This position of the query token in the query.  This is needed for
   * FTOrder.
   */
  int_t query_pos;

  /**
   * This is \c true only when the token span si comprised of tokens that are
   * contiguous with respect to their \c pos, i.e., there are no "holes".
   */
  bool is_contiguous;
};

#ifndef NDEBUG
std::ostream& operator<<( std::ostream&, ft_string_match const& );
#endif /* NDEBUG */

/**
 * An %ft_string_include is an ft_string_match that describes an ft_token_span
 * that must be contained in the document.
 */
typedef ft_string_match ft_string_include;

/**
 * An %ft_string_exclude is an ft_string_match that describes an ft_token_span
 * that must not be contained in the document.
 */
typedef ft_string_match ft_string_exclude;

/**
 * An %ft_string_matches contains zero or more ft_string_match objects.
 */
typedef std::list<ft_string_match> ft_string_matches;

///////////////////////////////////////////////////////////////////////////////

#define FT_MATCH_OPTIMIZE_SORT 0

/**
 * An %ft_match describes one result to the FTSelection.
 */
class ft_match {
public:
  typedef ft_string_matches includes_t;
  typedef ft_string_matches excludes_t;
  typedef ft_string_matches ft_match::*string_match_ptr;

#if FT_MATCH_OPTIMIZE_SORT
  includes_t const& includes() const { return includes_; }
  excludes_t const& excludes() const { return excludes_; }
#endif

  mutable includes_t includes;
  excludes_t excludes;

  void sort_includes() const {
#if FT_MATCH_OPTIMIZE_SORT
    // TODO: optimize later
    if ( !includes_sorted_ ) {
      includes_sorted_ = true;
#endif
      includes.sort();
#if FT_MATCH_OPTIMIZE_SORT
    }
#endif
  }

#if FT_MATCH_OPTIMIZE_SORT
private:
  mutable bool includes_sorted_;
#endif
};

/**
 * An %ft_match_seq is a sequence of zero or more ft_match objects.
 */
typedef std::list<ft_match> ft_match_seq;

/**
 * This type synonym is defined to use the same name as in the specification.
 */
typedef ft_match_seq ft_all_matches;

/**
 * An ft_all_matches_seq is a sequence of zero or more ft_all_matches objects.
 */
typedef std::list<ft_all_matches> ft_all_matches_seq;

#ifndef NDEBUG
std::ostream& operator<<( std::ostream&, ft_match const& );
std::ostream& operator<<( std::ostream&, ft_all_matches const& );
#endif /* NDEBUG */

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif  /* ZORBA_FULL_TEXT_FT_MATCH_H */
/* vim:set et sw=2 ts=2: */
