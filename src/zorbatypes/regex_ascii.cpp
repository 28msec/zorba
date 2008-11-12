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

#include "regex_ascii.h"
#include "string.h"
#include <ctype.h>
#include "chartype.h"
#include "zorbatypesError.h"

namespace zorba {
  namespace regex_ascii{
//ascii regular expression matching

/*http://www.w3.org/TR/xmlschema-2/#regexs

~regExp    ::=    branch ( '|' branch )*  
~branch    ::=    piece* 
~piece     ::=    atom quantifier? 
~quantifier    ::=    [?*+] | ( '{' quantity '}' ) 
~quantity    ::=    quantRange | quantMin | QuantExact 
~quantRange    ::=    QuantExact ',' QuantExact 
~quantMin    ::=    QuantExact ',' 
~QuantExact    ::=    [0-9]+ 
~atom    ::=    Char | charClass | ( '(' regExp ')' ) 
~Char    ::=    [^.\?*+()|#x5B#x5D] 
~charClass    ::=    charClassEsc | charClassExpr | WildcardEsc 
~charClassExpr    ::=    '[' charGroup ']' 
~charGroup    ::=    posCharGroup | negCharGroup | charClassSub 
~posCharGroup    ::=    ( charRange | charClassEsc )+  
~negCharGroup    ::=    '^' posCharGroup 
~charClassSub    ::=    ( posCharGroup | negCharGroup ) '-' charClassExpr 
~charRange    ::=    seRange | XmlCharIncDash 
~seRange    ::=    charOrEsc '-' charOrEsc 
~charOrEsc    ::=    XmlChar | SingleCharEsc 
~XmlChar    ::=    [^\#x2D#x5B#x5D] 
~XmlCharIncDash    ::=    [^\#x5B#x5D] 
~charClassEsc    ::=    ( SingleCharEsc | MultiCharEsc | catEsc | complEsc )  
~SingleCharEsc    ::=    '\' [nrt\|.?*+(){}#x2D#x5B#x5D#x5E] 
~catEsc    ::=    '\p{' charProp '}' 
~complEsc    ::=    '\P{' charProp '}' 
charProp    ::=    IsCategory | IsBlock 
~MultiCharEsc    ::=    '\' [sSiIcCdDwW] 
~WildcardEsc    ::=    '.' 


+ http://www.w3.org/TR/xquery-operators/#regex-syntax (not implemented)
*/

////////////////////////////////////
////Regular expression parsing and building of the tree
////////////////////////////////////

CRegexAscii_regex* CRegexAscii_parser::parse(const char *pattern)
{
  bool align_begin = false;
  
  if(pattern[0] == '^')
    align_begin = true;

  int   regex_len;
  CRegexAscii_regex*  regex = parse_regexp(pattern + (align_begin?1:0), &regex_len);
  
  if(regex)
    regex->set_align_begin(align_begin);

  return regex;
}

//until '\0' or ')'
CRegexAscii_regex* CRegexAscii_parser::parse_regexp(const char *pattern, 
                                                    int *regex_len)
{
  *regex_len = 0;
  int   branch_len;
  regex_depth++;
  CRegexAscii_regex *regex = new CRegexAscii_regex(current_regex);
  if(!current_regex)
    current_regex = regex;
  if(regex_depth == 2)
    current_regex->subregex.push_back(regex);
  CRegexAscii_branch  *branch;
  while(pattern[*regex_len] && (pattern[*regex_len] != ')'))
  {
    branch = parse_branch(pattern+*regex_len, &branch_len);
    if(!branch)
    {
      regex_depth--;
      delete regex;
      return NULL;
    }
    regex->add_branch(branch);
    *regex_len += branch_len;
  }
  if(pattern[*regex_len])
    (*regex_len)++;

  regex_depth--;
  return regex;
}

CRegexAscii_branch* CRegexAscii_parser::parse_branch(const char *pattern, int *branch_len)
{
  int piece_len;

  CRegexAscii_branch    *branch = new CRegexAscii_branch(current_regex);
  CRegexAscii_piece     *piece;
  *branch_len = 0;
  while(pattern[*branch_len] && (pattern[*branch_len] != '|') && (pattern[*branch_len] != ')'))
  {
    piece = parse_piece(pattern+*branch_len, &piece_len);
    if(!piece)
    {
      delete branch;
      return NULL;
    }
    branch->add_piece(piece);
    *branch_len += piece_len;
  }
  if(pattern[*branch_len] == '|')
    (*branch_len)++;
  return branch;
}

//piece = atom + quantifier
CRegexAscii_piece* CRegexAscii_parser::parse_piece(const char *pattern, int *piece_len)
{
  CRegexAscii_piece *piece = new CRegexAscii_piece;
  IRegexAtom  *atom;
  *piece_len = 0;

  int   atom_len;
  int   quantif_len;
  atom = read_atom(pattern, &atom_len);
  if(!atom)
  {
    delete piece;
    return NULL;
  }
  piece->set_atom(atom);
  read_quantifier(piece, pattern+atom_len, &quantif_len);

  *piece_len += atom_len + quantif_len;

  return piece;
}

char CRegexAscii_parser::myishex(char c)
{
  if((c >= '0') && (c <= '9'))
    return c-'0'+1;
  else if((c >= 'a') && (c <= 'f'))
    return c-'a'+10+1;
  else if((c >= 'A') && (c <= 'F'))
    return c-'a'+10+1;
  return 0;//not a hex
}

bool CRegexAscii_parser::myisdigit(char c)
{
  return (c >= '0') || (c <= '9');
}

char CRegexAscii_parser::readChar(const char *pattern, int *char_len, bool *is_multichar)
{
  char  c = 0;
  *char_len = 0;
  *is_multichar = false;
  switch(pattern[*char_len])
  {
  case '\\':
  {  (*char_len)++;
    switch(pattern[*char_len])
    {
    case 'n': c = '\n';break;
    case 'r': c = '\r';break;
    case 't': c = '\t';break;
    case '\\':
    case '|':
    case '.':
    case '?':
    case '*':
    case '+':
    case '(':
    case ')':
    case '{':
    case '}':
    case '-'://#x2D
    case '['://#x5B
    case ']'://#x5D
    case '^'://#x5E
       c = pattern[*char_len];
       break;
    case 'p'://catEsc
    case 'P'://complEsc
      //ignore the prop for now
      c = pattern[*char_len];
      *is_multichar = true;
      if(pattern[*char_len+1] == '{')
      {
        while(pattern[*char_len] != '}')
          (*char_len)++;

      }
      break;
      //multiCharEsc
    case 's':
    case 'S':
    case 'i':
    case 'I':
    case 'c':
    case 'C':
    case 'd':
    case 'D':
    case 'w':
    case 'W':
      *is_multichar = true;
       c = pattern[*char_len];
       break;
    }
    break;
  }
  case '#':///might be #xXX
  {
    if((pattern[*char_len+1] == 'x') &&
      myishex(pattern[*char_len+2]) && myishex(pattern[*char_len+3]))
    {
      c = (myishex(pattern[*char_len+2])-1)<<4 | (myishex(pattern[*char_len+3])-1);
      *char_len += 3;
      break;
    }
  }
  default:
     c = pattern[*char_len];
     break;
  }

  (*char_len)++;
  return c;
}



IRegexAtom* CRegexAscii_parser::read_atom(const char *pattern, int *atom_len)
{
  *atom_len = 0;
  char  c;
  bool is_end_line = false;
  c = pattern[*atom_len];
  switch(c)
  {
  case '[':
  {
    (*atom_len)++;
    CRegexAscii_chargroup *chargroup = NULL;
    int chargroup_len;
    chargroup = readchargroup(pattern+*atom_len, &chargroup_len);
    *atom_len += chargroup_len;
    return chargroup;
  }
  case '.'://WildCharEsc
  {
    CRegexAscii_wildchar  *wildchar = new CRegexAscii_wildchar(current_regex);
    (*atom_len)++;
    return wildchar;
  }
  case '('://begin an embedded reg exp
  {  (*atom_len)++;
    CRegexAscii_regex *emb_regex = NULL;
    int   regex_len;
    emb_regex = parse_regexp(pattern + *atom_len, &regex_len);
    *atom_len += regex_len;
    return emb_regex;
  }
  case '$'://end line
    is_end_line = true;
  default:
  {  char  c;
    int   c_len;
    bool  is_multichar;
    c = readChar(pattern+*atom_len, &c_len, &is_multichar);
    CRegexAscii_chargroup *chargroup = new CRegexAscii_chargroup(current_regex);
    if(is_multichar)
      chargroup->addMultiChar(c);
    else if(is_end_line)
      chargroup->addEndLine();
    else
      chargroup->addCharRange(c, c);
    *atom_len += c_len;
    return chargroup;
  }
  }
}

//read until ']'
//posCharGroup  ::=   ( charRange | charClassEsc )+  
//charRange     ::=    seRange | XmlCharIncDash
CRegexAscii_chargroup* CRegexAscii_parser::readchargroup(const char *pattern, int *chargroup_len)
{
  CRegexAscii_chargroup *chargroup = NULL;
  *chargroup_len = 0;
  if(pattern[*chargroup_len] == '^')//negative group
  {
    (*chargroup_len)++;
    chargroup = new CRegexAscii_negchargroup(current_regex);
  }
  else
    chargroup = new CRegexAscii_chargroup(current_regex);
  while(pattern[*chargroup_len] && (pattern[*chargroup_len]!=']'))
  {
    char  c1, c2;
    bool  is_multichar;
    int   c1_len;
    c1 = pattern[*chargroup_len];
    c2 = pattern[*chargroup_len+1];
    if((c1 == '-') && (c2 == '['))//charClassSub
    {
      int classsub_len;
      CRegexAscii_chargroup *classsub = readchargroup(pattern + *chargroup_len+1 + 1, &classsub_len);
      if(!classsub)
      {
        delete chargroup;
        return NULL;
      }
      chargroup->addClassSub(classsub);
      *chargroup_len += 2 + classsub_len + 1;
      if(pattern[*chargroup_len-1] != ']')
      {
        delete chargroup;
        return NULL;
      }
      return chargroup;
    }

    c1 = readChar(pattern+*chargroup_len, &c1_len, &is_multichar);
    if(is_multichar)//first char is multichar
    {
      chargroup->addMultiChar(c1);
      *chargroup_len += c1_len;
      continue;
    }
    if(pattern[*chargroup_len+c1_len] == '-')///might be a range
    {
      if(pattern[*chargroup_len+c1_len+1] == ']')//no range, just the last char is '-'
      {
        chargroup->addCharRange(c1, c1);
        chargroup->addCharRange('-', '-');
        *chargroup_len += c1_len + 1;
        continue;
      }
      else
      {
        //it is a range
        char c3;
        int  c3_len;
        c3 = readChar(pattern+*chargroup_len+c1_len+1, &c3_len, &is_multichar);
        if(is_multichar)
          return NULL;//error
        chargroup->addCharRange(c1, c3);
        *chargroup_len += c1_len + 1 + c3_len;
        continue;
      }
    }
    chargroup->addCharRange(c1, c1);
    *chargroup_len += c1_len;
  }
  if(pattern[*chargroup_len])
    (*chargroup_len)++;
  return chargroup;
}

void CRegexAscii_parser::read_quantifier(CRegexAscii_piece *piece,
                                         const char *pattern, int *quantif_len)
{
  *quantif_len = 0;
  switch(pattern[*quantif_len])
  {
  case '?':
    piece->set_quantifier_min_max(0, 1, false);
    (*quantif_len)++;
    break;
  case '*':
    piece->set_quantifier_min_max(0, -1, false);
    (*quantif_len)++;
    break;
  case '+':
    piece->set_quantifier_min_max(1, -1, false);
    (*quantif_len)++;
    break;
  case '{':
  {
    int min = 0, max = 0;
    (*quantif_len)++;
    while(pattern[*quantif_len] && (pattern[*quantif_len] != ',') &&
      myisdigit(pattern[*quantif_len]) && (pattern[*quantif_len] != '}'))
    {
      min = min*10 + pattern[*quantif_len] - '0';
      (*quantif_len)++;
    }
    if(pattern[*quantif_len] == '}')
    {
      (*quantif_len)++;
      piece->set_quantifier_min_max(min, min, true);
      break;
    }
    if((pattern[*quantif_len] == ',') && (!isdigit(pattern[*quantif_len+1])))
    {
      (*quantif_len)++;
      piece->set_quantifier_min_max(min, -1, false);
    }
    else
    {
      (*quantif_len)++;
      while(pattern[*quantif_len] &&
        isdigit(pattern[*quantif_len]) && (pattern[*quantif_len] != '}'))
      {
        max = max*10 + pattern[*quantif_len] - '0';
        (*quantif_len)++;
      }
      piece->set_quantifier_min_max(min, max, true);
    }
    while(pattern[*quantif_len] && (pattern[*quantif_len] != '}'))
    {
      (*quantif_len)++;
    }
    if(pattern[*quantif_len] == '}')
      (*quantif_len)++;
    break;
  }
  default:
    piece->set_quantifier_min_max(1, 1, false);
    break;
  }
  if(*quantif_len && (pattern[*quantif_len] == '?'))
  {
    piece->set_is_reluctant(true);
    (*quantif_len)++;
  }
  else
    piece->set_is_reluctant(false);
}


////////////////////////////
///Constructors and destructors and internal functions
////////////////////////////

CRegexAscii_regex::CRegexAscii_regex(CRegexAscii_regex *topregex) : IRegexAtom(topregex?topregex:this)
{
  matched_source = NULL;
  matched_len = 0;
}

CRegexAscii_regex::~CRegexAscii_regex()
{
  std::list<CRegexAscii_branch*>::iterator  branch_it;

  for(branch_it = branch_list.begin(); branch_it != branch_list.end(); branch_it++)
  {
    delete (*branch_it);
  }
}

void CRegexAscii_regex::set_align_begin(bool align_begin)
{
  this->align_begin = align_begin;
}

void CRegexAscii_regex::add_branch(CRegexAscii_branch *branch)
{
  branch_list.push_back(branch);
}

bool  CRegexAscii_regex::get_indexed_match(int index, 
                                           const char **matched_source, 
                                           int *matched_len)
{
  if(!index || index > subregex.size())
    return false;
  CRegexAscii_regex *subr = subregex[index-1];
  *matched_source = subr->matched_source;
  *matched_len = subr->matched_len;
  return true;
}

int CRegexAscii_regex::get_indexed_regex_count()
{
  return subregex.size();
}

CRegexAscii_branch::CRegexAscii_branch(CRegexAscii_regex* regex) :
      IRegexMatcher(regex)
{
}

CRegexAscii_branch::~CRegexAscii_branch()
{
  std::list<CRegexAscii_piece*>::iterator  piece_it;

  for(piece_it = piece_list.begin(); piece_it != piece_list.end(); piece_it++)
  {
    delete (*piece_it);
  }
}

void CRegexAscii_branch::add_piece(CRegexAscii_piece *piece)
{
  piece_list.push_back(piece);
}

CRegexAscii_piece::CRegexAscii_piece()
{
}

CRegexAscii_piece::~CRegexAscii_piece()
{
  delete atom;
}

void CRegexAscii_piece::set_atom(IRegexAtom *atom)
{
  this->atom = atom;
}

void CRegexAscii_piece::set_quantifier_min_max(int min, int max, bool strict_max)
{
  this->min = min;
  this->max = max;
  this->strict_max = strict_max;
}
void CRegexAscii_piece::set_is_reluctant(bool is_reluctant)
{
  this->is_reluctant = is_reluctant;
}
void CRegexAscii_piece::get_quantifier(int *min, int *max, bool *strict_max)
{
  *min = this->min;
  *max = this->max;
  *strict_max = this->strict_max;
}
bool CRegexAscii_piece::get_is_reluctant()
{
  return is_reluctant;
}


CRegexAscii_chargroup::CRegexAscii_chargroup(CRegexAscii_regex* regex) :
    IRegexAtom(regex)
{
  classsub = NULL;
}

CRegexAscii_chargroup::~CRegexAscii_chargroup()
{
  delete classsub;
}

void CRegexAscii_chargroup::addMultiChar(char c)
{
  chargroup_t cgt;
  cgt.flags = CHARGROUP_FLAGS_MULTICHAR;
  cgt.c1 = c;
  cgt.c2 = 0;
  chargroup_list.push_back(cgt);
}

void CRegexAscii_chargroup::addEndLine()
{
  chargroup_t cgt;
  cgt.flags = CHARGROUP_FLAGS_ENDLINE;
  cgt.c1 = '$';
  cgt.c2 = 0;
  chargroup_list.push_back(cgt);
}

void CRegexAscii_chargroup::addCharRange(char c1, char c2)
{
  chargroup_t cgt;
  cgt.flags = 0;
  cgt.c1 = c1;
  cgt.c2 = c2;
  chargroup_list.push_back(cgt);
}

void CRegexAscii_chargroup::addClassSub(CRegexAscii_chargroup* classsub)
{
  this->classsub = classsub;
}

CRegexAscii_negchargroup::CRegexAscii_negchargroup(CRegexAscii_regex* regex) :
  CRegexAscii_chargroup(regex)
{
}

CRegexAscii_negchargroup::~CRegexAscii_negchargroup()
{
}

CRegexAscii_wildchar::CRegexAscii_wildchar(CRegexAscii_regex* regex) :
      IRegexAtom(regex)
{
}

CRegexAscii_wildchar::~CRegexAscii_wildchar()
{
}

CRegexAscii_parser::CRegexAscii_parser()
{
  current_regex = NULL;
  regex_depth = 0;
}

CRegexAscii_parser::~CRegexAscii_parser()
{
}


//////////////////////////////////////////
////Matching the pattern on a string
/////////////////////////////////////////

//try every position in source to match the pattern
bool CRegexAscii_regex::match_anywhere(const char *source, int flags,
                                       int *match_pos, int *matched_len)
{
  *match_pos = 0;
  return match_from(source, flags, match_pos, matched_len);
}

bool CRegexAscii_regex::match_from(const char *source, int flags,
                                       int *match_pos, int *matched_len)
{
  this->flags = flags;

//  if(!source[0])
//  {
//    if(branch_list.empty())
//      return true;
//    else
//      return false;
//  }

  bool  skip_first_match = false;
  if(*match_pos && align_begin)
    skip_first_match = true;
  do
  {
    if(!skip_first_match)
    {
      if(match(source + *match_pos, matched_len))
        return true;
    }
    skip_first_match = false;
    if(align_begin)
    {
      if(flags & REGEX_ASCII_MULTILINE)
      {
        //goto the next line
        while(source[*match_pos] && (source[*match_pos] != '\n') && (source[*match_pos] != '\r'))
          (*match_pos)++;
        if(source[*match_pos] == '\n')
        {
          (*match_pos)++;
          if(source[*match_pos] == '\r')
            (*match_pos)++;
        }
        else if(source[*match_pos] == '\r')
        {
          (*match_pos)++;
          if(source[*match_pos] == '\n')
            (*match_pos)++;
        }
        if(!source[*match_pos])
          return false;
        continue;
      }
      return false;
    }
    if(!source[*match_pos])
      break;
    (*match_pos)++;
  }
  while(source[*match_pos]);
  return false;
}

//match any of the branches
bool CRegexAscii_regex::match(const char *source, int *matched_len)
{
  std::list<CRegexAscii_branch*>::iterator  branch_it;

  for(branch_it = branch_list.begin(); branch_it != branch_list.end(); branch_it++)
  {
    if((*branch_it)->match(source, matched_len))
    {
      matched_source = source;
      this->matched_len = *matched_len;
      return true;
    }
  }
  matched_source = NULL;
  matched_len = 0;
  return false;
}

//match all the pieces
bool CRegexAscii_branch::match(const char *source, int *matched_len)
{
  std::list<CRegexAscii_piece*>::iterator  piece_it;

  piece_it = piece_list.begin(); 
  if(piece_it == piece_list.end())
    if(source[0])
      return false;
    else
      return true;
  if(!(*piece_it)->get_is_reluctant())
    return match_piece_iter_normal(piece_it, source, matched_len);
  else
    return match_piece_iter_reluctant(piece_it, source, matched_len);
}

//match as less as possible
bool CRegexAscii_branch::match_piece_iter_reluctant(
                                        std::list<CRegexAscii_piece*>::iterator piece_it,
                                        const char *source, int *matched_len)
{
  *matched_len = 0;
  if(piece_it == piece_list.end())
    return true;

  int min, max;
  bool  strict_max;
  //std::vector<int>    match_lens;
  (*piece_it)->get_quantifier(&min, &max, &strict_max);
  if(strict_max && (max >= 0))
  {
    int   timeslen;
    //check if the piece doesn't exceed the max match
    if((*piece_it)->match_piece_times(source, &timeslen, max+1, NULL))
      return false;///too many matches
  }

  int i=min;
  std::list<CRegexAscii_piece*>::iterator next_it = piece_it;
  next_it++;
  int pieceslen = 0;
  while(1)
  {
    if((max > 0) && (i>max))
      break;
   int piecelen = 0;
   if((*piece_it)->match_piece_times(source+pieceslen, &piecelen, !pieceslen ? i : 1, NULL))
   {
      pieceslen += piecelen;
      int   otherpieces = 0;
      if((next_it == piece_list.end()) ||
        ((*next_it)->get_is_reluctant() && match_piece_iter_reluctant(next_it, source+pieceslen, &otherpieces)) ||
        (!(*next_it)->get_is_reluctant() && match_piece_iter_normal(next_it, source+pieceslen, &otherpieces)))
      {
        *matched_len = pieceslen + otherpieces;
        return true;
      }
    }
    else
      break;
    i++;
  }

  return false;
}

//match as much as possible
bool CRegexAscii_branch::match_piece_iter_normal(
                                        std::list<CRegexAscii_piece*>::iterator piece_it,
                                        const char *source, int *matched_len)
{
  *matched_len = 0;

  int min, max;
  bool  strict_max;
  std::vector<int>    match_lens;
  (*piece_it)->get_quantifier(&min, &max, &strict_max);
  int   timeslen;
  if(strict_max && (max >= 0))
  {
    //check if the piece doesn't exceed the max match
    //if((*piece_it)->match_piece_times(source, &timeslen, max+1, &match_lens))
    //  return false;///too many matches
    (*piece_it)->match_piece_times(source, &timeslen, max, &match_lens);
  }
  else if(!strict_max && (max >= 0))
    (*piece_it)->match_piece_times(source, &timeslen, max, &match_lens);
  else
    (*piece_it)->match_piece_times(source, &timeslen, -1, &match_lens);

  int i;
  std::list<CRegexAscii_piece*>::iterator next_it = piece_it;
  next_it++;
  if(next_it == piece_list.end())
  {
    if(match_lens.size() > min)
    {
      *matched_len = timeslen;
      return true;
    }
    else
      return false;
  }
  for(i=match_lens.size()-1; i>=min; i--)
  {
    int piecelen = 0;
    int   otherpieces = 0;
    if(((*next_it)->get_is_reluctant() && match_piece_iter_reluctant(next_it, source+match_lens[i]+piecelen, &otherpieces)) ||
      (!(*next_it)->get_is_reluctant() && match_piece_iter_normal(next_it, source+match_lens[i]+piecelen, &otherpieces)))
    {
      *matched_len = match_lens[i] + piecelen + otherpieces;
      return true;
    }
  }

  return false;
}

bool CRegexAscii_piece::match_piece_times(const char *source, 
                                          int *piecelen, 
                                          int times,
                                          std::vector<int>    *match_lens)
{
  *piecelen = 0;
  for(int i=0;(times < 0) || (i<times);i++)
  {
    if(match_lens)
      match_lens->push_back(*piecelen);
    int   atomlen;
    if(!atom->match(source+*piecelen, &atomlen))
      return false;
    *piecelen += atomlen;
    if(!atomlen && !source[*piecelen])
      break;
  }
  if(match_lens)
    match_lens->push_back(*piecelen);

  return true;
}

//match any of chargroups
bool CRegexAscii_chargroup::match(const char *source, int *matched_len)
{
  *matched_len = 0;
  std::list<chargroup_t>::iterator  cgt_it;

  if(!source[0])
  {
    if(chargroup_list.empty())
      return true;
    else if((chargroup_list.size() == 1) && (chargroup_list.begin()->flags == CHARGROUP_FLAGS_ENDLINE))
      return true;
    else
      return false;
  }

  if(source[0] == 0x0A)
  {
    if((regex_intern->flags & REGEX_ASCII_MULTILINE) &&
        (chargroup_list.size() == 1) && (chargroup_list.begin()->flags == CHARGROUP_FLAGS_ENDLINE))
    {
      *matched_len = 1;
      return true;
    }
  }

  for(cgt_it = chargroup_list.begin(); cgt_it != chargroup_list.end(); cgt_it++)
  {
    if(cgt_it->flags == CHARGROUP_FLAGS_MULTICHAR)
    {
      switch(cgt_it->c1)
      {
        case 'p'://catEsc
        case 'P'://complEsc
          //ignore the prop for now
          throw zorbatypesException("", ZorbatypesError::FORX0002);
          break;
        case 's'://[#x20\t\n\r]
          switch(source[0])
          {
          case '\t':
          case '\r':
          case '\n':
          case ' ':
            *matched_len = 1;
            return true;
          default:
            return false;
          }
        case 'S'://[^\s]
          switch(source[0])
          {
          case 0:
          case '\t':
          case '\r':
          case '\n':
          case ' ':
            return false;
          default:
            *matched_len = 1;
            return true;
          }
        case 'i'://the set of initial name characters, those ·match·ed by Letter | '_' | ':'
          if((source[0] == '_') ||
            (source[0] == ':') ||
            XQCharType::isLetter(source[0]))
          {
            *matched_len = 1;
            return true;
          }
          return false;
        case 'I':
          if((source[0] == '_') ||
            (source[0] == ':') ||
            XQCharType::isLetter(source[0]))
          {
            return false;
          }
          *matched_len = 1;
          return true;
        case 'c'://the set of name characters, those ·match·ed by NameChar
          if(XQCharType::isNameChar(source[0]))
          {
            *matched_len = 1;
            return true;
          }
          return false;
        case 'C':
          if(XQCharType::isNameChar(source[0]))
          {
            return false;
          }
          *matched_len = 1;
          return true;
        case 'd':
        case 'D':
        case 'w':
        case 'W':
        default:
          throw zorbatypesException("", ZorbatypesError::FORX0002);
          break;
      }
      return false;
    }
    else if(cgt_it->flags == CHARGROUP_FLAGS_ENDLINE)
    {
      return false;
    }
    else
    {
      if(regex_intern->flags & REGEX_ASCII_CASE_INSENSITIVE)
      {
        char  sup = toupper(source[0]);
        if((sup >= toupper(cgt_it->c1)) &&
          (sup <= toupper(cgt_it->c2)))
          break;
      }
      else
      {
        if((source[0] >= cgt_it->c1) &&
          (source[0] <= cgt_it->c2))
          break;
      }
    }
  }
  if(cgt_it == chargroup_list.end())
    return false;

  if(classsub)
  {
    int   classsub_len;
    if(classsub->match(source, &classsub_len))
      return false;
  }

  *matched_len = 1;
  return true;
}

bool CRegexAscii_negchargroup::match(const char *source, int *matched_len)
{
  if(!source[0])
    return false;
  if(!CRegexAscii_chargroup::match(source, matched_len))
  {
    *matched_len = 1;
    return true;
  }
  return false;
}

bool CRegexAscii_wildchar::match(const char *source, int *matched_len)
{
  if(source[0] && (source[0] != '\n') && (source[0] != '\r'))
  {
    *matched_len = 1;
    return true;
  }
  else
  {
    *matched_len = 0;
    return false;
  }
}


  }//end namespace regex_ascii
}//end namespace zorba
