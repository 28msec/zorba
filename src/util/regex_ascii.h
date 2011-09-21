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
#ifndef ZORBA_MINIMAL_REGULAR_EXPRESSIONS_14_MAY_2008
#define ZORBA_MINIMAL_REGULAR_EXPRESSIONS_14_MAY_2008

#include <list>
#include <vector>

#include <zorba/config.h>
#include "util/unicode_util.h"

namespace zorba {
  namespace regex_ascii{

//matching flags
#define REGEX_ASCII_CASE_INSENSITIVE    1   //i
#define REGEX_ASCII_DOTALL              2   //s
#define REGEX_ASCII_MULTILINE           4   //m
#define REGEX_ASCII_NO_WHITESPACE       8   //x
#define REGEX_ASCII_LITERAL             16  //q

#define REGEX_ASCII_GET_LONGEST_BRANCH  32   //try all branches and get the longest match (or shortest for reluctant pieces)
#define REGEX_ASCII_MINIMAL_MATCH       64   //consider all pieces as reluctant
#define REGEX_ASCII_WHOLE_MATCH         128  //match only all string, like having "^regex$"
#define REGEX_ASCII_GROUPING_LEN_WHOLE_PIECE    256  //compute the len of a grouping as for the whole piece ( for example (a)+ when matching "aa" and referred as $1 will get string len 2 instead of last 1)

class CRegexAscii_regex;
class CRegexAscii_piece;

struct RegexAscii_pieceinfo
{
  union
  {
    CRegexAscii_piece*  piece;
    CRegexAscii_regex*  group_regex;
  };
  int nr_matches;

  RegexAscii_pieceinfo(CRegexAscii_piece* piece) {nr_matches=0;this->piece=piece;}
  RegexAscii_pieceinfo(CRegexAscii_regex* group_regex) {nr_matches=-1;this->group_regex=group_regex;}
};


class IRegexAtom
{
protected:
  friend class CRegexAscii_piece;
  CRegexAscii_regex *regex_intern;
public:
  IRegexAtom(CRegexAscii_regex* regex)  : regex_intern(regex) {}
  virtual ~IRegexAtom() {}

  virtual bool match(const char *source, int *start_from_branch, int *matched_len,
                    std::list<RegexAscii_pieceinfo>::iterator next_piece,
                    std::list<RegexAscii_pieceinfo>::iterator end_piece);
  virtual bool match_internal(const char *source, int *start_from_branch, int *matched_len) = 0;
  virtual void reset_match() {}
//  virtual void restore_match() {}
};

class CRegexAscii_branch;
class CRegexAscii_piece;
class CRegexAscii_chargroup;
class CRegexAscii_parser;

class CRegexAscii_regex : public IRegexAtom
{
  friend class CRegexAscii_parser;
  friend class CRegexAscii_branch;
  friend class CRegexAscii_piece;
  friend class CRegexAscii_chargroup;
  friend class CRegexAscii_negchargroup;
  friend class CRegexAscii_wildchar;
  friend class CRegexAscii_backref;
  friend class CRegexAscii_pinstart;
public:
  CRegexAscii_regex(CRegexAscii_regex *);
  virtual ~CRegexAscii_regex();

  bool match_anywhere(const char *source, unsigned int flags, int *match_pos, int *matched_len);
  bool match_from(const char *source, unsigned int flags, int *match_pos, int *matched_len);

  //for replace $1, $2 ...
  bool  get_indexed_match(int index, const char **matched_source, int *matched_len);
  unsigned int get_indexed_regex_count();

  bool get_reachedEnd() {return reachedEnd;}
public:
  virtual bool match(const char *source, int *start_from_branch, int *matched_len,
                    std::list<RegexAscii_pieceinfo>::iterator next_piece,
                    std::list<RegexAscii_pieceinfo>::iterator end_piece);
  virtual bool match_internal(const char *source, int *start_from_branch, int *matched_len) {return false;}//not impl
  virtual void reset_match();
//  virtual void restore_match();
private:
  void add_branch(CRegexAscii_branch *branch);

  void save_subregex_list(std::vector<std::pair<const char*, int> > &saved_subregex);
  void load_subregex_list(std::vector<std::pair<const char*, int> > &saved_subregex);
private:
  unsigned int flags;
  std::list<CRegexAscii_branch*>   branch_list;

  const char  *source_start;

  const char  *matched_source;
  int         matched_len;
//  const char  *backup_matched_source;
//  int         backup_matched_len;
  std::vector<CRegexAscii_regex*>    subregex;//for grouping

  bool        reachedEnd;
};

class CRegexAscii_branch
{
  friend class CRegexAscii_parser;
public:
  CRegexAscii_branch(CRegexAscii_regex* regex);
  ~CRegexAscii_branch();

  bool match(const char *source, int *matched_len,
              CRegexAscii_regex* group_regex,
              std::list<RegexAscii_pieceinfo>::iterator next_piece,
              std::list<RegexAscii_pieceinfo>::iterator end_piece);
  void reset();
//  void restore();
private:
  std::list<RegexAscii_pieceinfo>   piece_list;
private:
  void add_piece(CRegexAscii_piece *piece);
 
};

class CRegexAscii_piece //: public IRegexMatcher
{
  friend class CRegexAscii_parser;
  friend class CRegexAscii_branch;

  IRegexAtom *atom;
  CRegexAscii_regex *regex_atom;

  //quantifier
  bool  strict_max;
  int   min;
  int   max;//-1 is infinite
  bool  is_reluctant;

public:
  CRegexAscii_piece();
  ~CRegexAscii_piece();
public:
  void set_atom(IRegexAtom *atom);
  void set_quantifier_min_max(int min, int max, bool strict_max);
  void set_is_reluctant(bool is_reluctant);
  void get_quantifier(int *min, int *max, bool *strict_max);
  bool get_is_reluctant();
//  bool match(const char *source, int *matched_len);
  bool match_piece(std::list<RegexAscii_pieceinfo>::iterator next_piece,
                   std::list<RegexAscii_pieceinfo>::iterator end_piece,
                   const char *source, int *matched_len);
protected:
  bool match_piece_times(const char *source, 
                         int *piecelen, 
                         int times,
                         std::vector<std::pair<int,int> >    *match_lens);
  int  choose_another_branch(std::vector<std::pair<int,int> > &match_lens);
  bool match_piece_iter_reluctant(std::list<RegexAscii_pieceinfo>::iterator next_piece,
                        std::list<RegexAscii_pieceinfo>::iterator end_piece,
                        const char *source, int *matched_len);
  bool match_piece_iter_normal(std::list<RegexAscii_pieceinfo>::iterator next_piece,
                        std::list<RegexAscii_pieceinfo>::iterator end_piece,
                        const char *source, int *matched_len);
  bool is_regex_atom();
};


enum CHARGROUP_t
{
CHARGROUP_NO_MULTICHAR = 0,
CHARGROUP_FLAGS_CHAR_RANGE,
CHARGROUP_FLAGS_MULTICHAR_p,
CHARGROUP_FLAGS_MULTICHAR_Is,
CHARGROUP_FLAGS_MULTICHAR_OTHER,
CHARGROUP_FLAGS_ONECHAR,
CHARGROUP_FLAGS_ENDLINE
};

class CRegexAscii_chargroup : public IRegexAtom
{
  friend class CRegexAscii_parser;
public:
  CRegexAscii_chargroup(CRegexAscii_regex* regex);
  virtual ~CRegexAscii_chargroup();
private:
  typedef struct
  {
    CHARGROUP_t  flags;
    char  c1;
    char  c2;
  }chargroup_t;
  std::list<chargroup_t>    chargroup_list;
  CRegexAscii_chargroup *classsub;
public:
  void addMultiChar(char c, CHARGROUP_t multichar_type);
  void addEndLine();
  void addCharRange(char c1, char c2);
  void addOneChar(char c);
  void addClassSub(CRegexAscii_chargroup* classsub);

  virtual bool match_internal(const char *source, int *start_from_branch, int *matched_len);
};

class CRegexAscii_negchargroup : public CRegexAscii_chargroup
{
public:
  CRegexAscii_negchargroup(CRegexAscii_regex* regex);
  virtual ~CRegexAscii_negchargroup();

  virtual bool match_internal(const char *source, int *start_from_branch, int *matched_len);
};

class CRegexAscii_wildchar : public IRegexAtom
{
public:
  CRegexAscii_wildchar(CRegexAscii_regex* regex);
  virtual ~CRegexAscii_wildchar();

  virtual bool match_internal(const char *source, int *start_from_branch, int *matched_len);
};

class CRegexAscii_backref : public IRegexAtom
{
public:
  CRegexAscii_backref(CRegexAscii_regex* regex, unsigned int backref);
  virtual ~CRegexAscii_backref();

  virtual bool match_internal(const char *source, int *start_from_branch, int *matched_len);
private:
  unsigned int backref;
};

class CRegexAscii_pinstart : public IRegexAtom
{
public:
  CRegexAscii_pinstart(CRegexAscii_regex* regex);

  virtual bool match_internal(const char *source, int *start_from_branch, int *matched_len);
};

class CRegexAscii_parser
{
public:
  typedef struct
  {
    const unicode::code_point    cp[2];//in pairs start, end
    const unicode::code_point    *ext_cp;
    const char    *group_name;
  }block_escape_t;

  CRegexAscii_parser();
  ~CRegexAscii_parser();

public:
  CRegexAscii_regex* parse(const char *pattern, unsigned int flags);

protected:
  CRegexAscii_regex* parse_regexp(const char *pattern, int *regex_len);
  CRegexAscii_branch* parse_branch(const char *pattern, int *branch_len);
  CRegexAscii_piece* parse_piece(const char *pattern, int *piece_len);
  char myishex(char c);
  bool myisdigit(char c);
  bool myisletterAZ(char c);
  char readChar(const char *pattern, bool for_atom, int *char_len, CHARGROUP_t *multichar_type);
  IRegexAtom* read_atom(const char *pattern, int *atom_len);
  CRegexAscii_chargroup* readchargroup(const char *pattern, int *chargroup_len);
  void read_quantifier(CRegexAscii_piece *piece, const char *pattern, int *quantif_len);

private:
  CRegexAscii_regex   *current_regex;
  int   regex_depth;
  unsigned int flags;
};

}
}//end namespace zorba::regex_ascii

#endif
/* vim:set et sw=2 ts=2: */
