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

#include <cstring>

#include <zorba/diagnostic_list.h>
#include "diagnostics/dict.h"
#include "diagnostics/xquery_exception.h"

#include "stl_util.h"
#include "zorba_regex.h"

#define INVALID_RE_EXCEPTION(...) \
  XQUERY_EXCEPTION( err::FORX0002, ERROR_PARAMS( __VA_ARGS__ ) )

namespace zorba {
namespace unicode {

///////////////////////////////////////////////////////////////////////////////

uint32_t regex::parse_regex_flags(const char* flag_cstr) 
{
  uint32_t flags = 0;
  for (const char* p = flag_cstr; *p != '\0'; ++p) 
  {
    switch (*p) 
    {
    case 'i': flags |= REGEX_ASCII_CASE_INSENSITIVE; break;
    case 's': flags |= REGEX_ASCII_DOTALL; break;
    case 'm': flags |= REGEX_ASCII_MULTILINE; break;
    case 'x': flags |= REGEX_ASCII_NO_WHITESPACE; break;
    case 'q': flags |= REGEX_ASCII_LITERAL; break;
    default:
      throw XQUERY_EXCEPTION( err::FORX0001, ERROR_PARAMS( *p ) );
      break;
    }
  }
  return flags;
}

void regex::compile( char const *pattern, char const *flags)
{
  parsed_flags = parse_regex_flags(flags);
  regex_engine::CRegexXQuery_parser regex_parser;
  regex_matcher = regex_parser.parse(pattern, parsed_flags);
  if(!regex_matcher)
    throw INVALID_RE_EXCEPTION(pattern);
}

bool regex::match_part( char const *s )
{
  bool  retval;
  int   match_pos;
  int   matched_len;

  retval = regex_matcher->match_anywhere(s, parsed_flags, &match_pos, &matched_len);

  return retval;
}

bool regex::next_match( char const *s, size_type *pos, zstring *match )
{
  bool  retval;
  int   match_pos;
  int   matched_len;

  retval = regex_matcher->match_anywhere(s+*pos, parsed_flags, &match_pos, &matched_len);
  if(retval)
  {
    match->assign(s+*pos+match_pos, matched_len);
    *pos += match_pos + matched_len;
  }
  return retval;
}

bool regex::next_token( char const *s, size_type *pos, zstring *token,
                  bool *matched)
{
  if(!s[*pos])
    return false;
  bool  retval;
  int   match_pos;
  int   matched_len;

  retval = regex_matcher->match_anywhere(s+*pos, parsed_flags, &match_pos, &matched_len);
  if(retval)
  {
    if(token)
      token->assign(s+*pos, match_pos);
    *pos += match_pos + matched_len;
    if(matched)
      *matched = true;
    return true;
  }
  else
  {
    if(token)
      token->assign(s+*pos);
    *pos += strlen(s+*pos);
    if(matched)
      *matched = false;
    return true;
  }
}

bool regex::match_whole( char const *s )
{
  bool  retval;
  int   matched_pos;
  int   matched_len;

  retval = regex_matcher->match_anywhere(s, parsed_flags|REGEX_ASCII_WHOLE_MATCH, &matched_pos, &matched_len);
  if(!retval)
    return false;
  return true;
}

bool regex::replace_all( char const *in, char const *replacement, zstring *result )
{
  int   match_pos;
  int   matched_len;

  const char  *start_str = in;
  int  subregex_count = regex_matcher->get_indexed_regex_count();
  bool retval = false;

  while(regex_matcher->match_anywhere(start_str, parsed_flags, &match_pos, &matched_len))
  {
    if(match_pos)
      result->append(start_str , match_pos);
    retval = true;
    const char *temprepl = replacement;
    const char *submatched_source;
    int   submatched_len;
    int index;
    while(*temprepl)
    {
      //look for dollars
      if(*temprepl == '\\')
      {
        if(!(parsed_flags & REGEX_ASCII_LITERAL))
        {
          temprepl++;
          if(!*temprepl) 
            temprepl--;
          else if((*temprepl != '\\') && (*temprepl != '$'))//Invalid replacement string.
            throw XQUERY_EXCEPTION( err::FORX0004, ERROR_PARAMS( replacement ) );
        }
        result->append(1, *temprepl);
        temprepl++;
        continue;
      }
      if((*temprepl == '$') && !(parsed_flags & REGEX_ASCII_LITERAL))
      {
        temprepl++;
        index = 0;
        int   nr_digits = 0;
        while(isdigit(*temprepl))
        {
          if(nr_digits && ((index*10 + (*temprepl)-'0') > subregex_count))
            break;
          index = index*10 + (*temprepl)-'0';
          temprepl++;
          nr_digits++;
        }
        if(!nr_digits)//Invalid replacement string.
          throw XQUERY_EXCEPTION( err::FORX0004, ERROR_PARAMS( replacement ) );
        else if(!index)
        {
          result->append(start_str+match_pos, matched_len);
        }
        else if(regex_matcher->get_indexed_match(index, &submatched_source, &submatched_len))
        {
          if(submatched_source && submatched_len)
            result->append(submatched_source, submatched_len);
        }
      }
      else
      {
        result->append(1, *temprepl);
        temprepl++;
      }
    }
    start_str += match_pos + matched_len;
  }
  result->append(start_str);

  return retval;
}

void regex::set_string( const char* in, size_type len )
{
  s_in_.assign(in, len);
  m_pos = 0;
  m_match_pos = 0;
  m_matched_len = 0;
}

bool regex::next_match( bool *reachedEnd )
{
  bool  retval;

  retval = regex_matcher->match_anywhere(s_in_.c_str()+m_pos, parsed_flags, &m_match_pos, &m_matched_len);
  if(retval)
  {
    m_match_pos += m_pos;
    m_pos = m_match_pos + m_matched_len;
  }
  else
  {
    m_pos = s_in_.length();
    m_match_pos = 0;
    m_matched_len = 0;
  }
  if(reachedEnd)
    *reachedEnd = regex_matcher->get_reachedEnd();
  return retval;
}

int regex::get_group_count()
{
  return (int)regex_matcher->get_indexed_regex_count();
}

bool regex::get_match_start_end_bytes( int groupId, int *start, int *end )
{
  *start = -1;
  *end = -1;
  if(groupId == 0)
  {
    *start = m_match_pos;
    *end = m_match_pos + m_matched_len;
    return true;
  }
  if(groupId > (int)regex_matcher->get_indexed_regex_count())
    return false;
  const char *submatched_source;
  int   submatched_len;
  if(!regex_matcher->get_indexed_match(groupId, &submatched_source, &submatched_len))
    return false;
  *start = submatched_source - s_in_.c_str();
  *end = *start + submatched_len;
  return true;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace unicode
} // namespace zorba

/* vim:set et sw=2 ts=2: */
