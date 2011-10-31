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
  namespace regex_xquery{

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

class CRegexXQuery_regex;
class CRegexXQuery_piece;

struct RegexAscii_pieceinfo
{
  union
  {
    CRegexXQuery_piece*  piece;
    CRegexXQuery_regex*  group_regex;
  };
  int nr_matches;

  RegexAscii_pieceinfo(CRegexXQuery_piece* piece) {nr_matches=0;this->piece=piece;}
  RegexAscii_pieceinfo(CRegexXQuery_regex* group_regex) {nr_matches=-1;this->group_regex=group_regex;}
};


class IRegexAtom
{
protected:
  friend class CRegexXQuery_piece;
  CRegexXQuery_regex *regex_intern;
public:
  IRegexAtom(CRegexXQuery_regex* regex)  : regex_intern(regex) {}
  virtual ~IRegexAtom() {}

  virtual bool match(const char *source, int *start_from_branch, int *matched_len,
                    std::list<RegexAscii_pieceinfo>::iterator next_piece,
                    std::list<RegexAscii_pieceinfo>::iterator end_piece);
  virtual bool match_internal(const char *source, int *start_from_branch, int *matched_len) = 0;
  virtual void reset_match() {}
//  virtual void restore_match() {}
};

class CRegexXQuery_branch;
class CRegexXQuery_piece;
class CRegexXQuery_chargroup;
class CRegexXQuery_parser;

class CRegexXQuery_regex : public IRegexAtom
{
  friend class CRegexXQuery_parser;
  friend class CRegexXQuery_branch;
  friend class CRegexXQuery_piece;
  friend class CRegexXQuery_chargroup;
  friend class CRegexXQuery_negchargroup;
  friend class CRegexXQuery_wildchar;
  friend class CRegexXQuery_backref;
  friend class CRegexXQuery_pinstart;
public:
  CRegexXQuery_regex(CRegexXQuery_regex *);
  virtual ~CRegexXQuery_regex();

  bool match_anywhere(const char *source, unsigned int flags, int *match_pos, int *matched_len);
  bool match_from(const char *source, unsigned int flags, int *match_pos, int *matched_len);

  //for replace $1, $2 ...
  bool  get_indexed_match(int index, const char **matched_source, int *matched_len);
  unsigned int get_indexed_regex_count();

  bool get_reachedEnd() {return reachedEnd;}
  void set_reachedEnd(const char *source) {if(source > source_start) reachedEnd = true;}
  unsigned int get_flags() {return flags;}
public:
  virtual bool match(const char *source, int *start_from_branch, int *matched_len,
                    std::list<RegexAscii_pieceinfo>::iterator next_piece,
                    std::list<RegexAscii_pieceinfo>::iterator end_piece);
  virtual bool match_internal(const char *source, int *start_from_branch, int *matched_len) {return false;}//not impl
  virtual void reset_match();
//  virtual void restore_match();
private:
  void add_branch(CRegexXQuery_branch *branch);

  void save_subregex_list(std::vector<std::pair<const char*, int> > &saved_subregex);
  void load_subregex_list(std::vector<std::pair<const char*, int> > &saved_subregex);
private:
  unsigned int flags;
  std::list<CRegexXQuery_branch*>   branch_list;

  const char  *source_start;

  const char  *matched_source;
  int         matched_len;
//  const unicode::code_point  *backup_matched_source;
//  int         backup_matched_len;
  std::vector<CRegexXQuery_regex*>    subregex;//for grouping

  bool        reachedEnd;
};

class CRegexXQuery_branch
{
  friend class CRegexXQuery_parser;
public:
  CRegexXQuery_branch(CRegexXQuery_regex* regex);
  ~CRegexXQuery_branch();

  bool match(const char *source, int *matched_len,
              CRegexXQuery_regex* group_regex,
              std::list<RegexAscii_pieceinfo>::iterator next_piece,
              std::list<RegexAscii_pieceinfo>::iterator end_piece);
  void reset();
//  void restore();
private:
  std::list<RegexAscii_pieceinfo>   piece_list;
private:
  void add_piece(CRegexXQuery_piece *piece);
 
};

class CRegexXQuery_piece //: public IRegexMatcher
{
  friend class CRegexXQuery_parser;
  friend class CRegexXQuery_branch;

  IRegexAtom *atom;
  CRegexXQuery_regex *regex_atom;

  //quantifier
  bool  strict_max;
  int   min;
  int   max;//-1 is infinite
  bool  is_reluctant;

public:
  CRegexXQuery_piece();
  ~CRegexXQuery_piece();
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
//CHARGROUP_FLAGS_CHAR_RANGE,
CHARGROUP_FLAGS_MULTICHAR_p,
CHARGROUP_FLAGS_MULTICHAR_Is,
CHARGROUP_FLAGS_MULTICHAR_OTHER,
CHARGROUP_FLAGS_ONECHAR_ASCII,
CHARGROUP_FLAGS_ONECHAR_UNICODE
//CHARGROUP_FLAGS_ENDLINE
};


class CRegexXQuery_charmatch : public IRegexAtom
{
  friend CRegexXQuery_parser;
protected:
  //enum CHARGROUP_t  type;
public:
  CRegexXQuery_charmatch(CRegexXQuery_regex* regex);//, enum CHARGROUP_t  type);
  virtual ~CRegexXQuery_charmatch() {}
  virtual bool match_internal(const char *source, int *start_from_branch, int *matched_len) = 0;
  virtual unicode::code_point get_c() {return 0;}
};

class CRegexXQuery_multicharP : public CRegexXQuery_charmatch
{
  char multichar_type;
  bool is_reverse;
public:
  CRegexXQuery_multicharP(CRegexXQuery_regex* regex, char type, bool is_reverse);
  virtual ~CRegexXQuery_multicharP() {}

  virtual bool match_internal(const char *source, int *start_from_branch, int *matched_len);
};

class CRegexXQuery_multicharIs : public CRegexXQuery_charmatch
{
  int block_index;
  bool is_reverse;
public:
  CRegexXQuery_multicharIs(CRegexXQuery_regex* regex, int block_index, bool is_reverse);
  virtual ~CRegexXQuery_multicharIs() {}

  virtual bool match_internal(const char *source, int *start_from_branch, int *matched_len);
};

class CRegexXQuery_multicharOther : public CRegexXQuery_charmatch
{
  char multichar_type;
public:
  CRegexXQuery_multicharOther(CRegexXQuery_regex* regex, char type);
  virtual ~CRegexXQuery_multicharOther() {}

  virtual bool match_internal(const char *source, int *start_from_branch, int *matched_len);
};

class CRegexXQuery_char_ascii : public CRegexXQuery_charmatch
{
  friend CRegexXQuery_parser;
protected:
  char c;
public:
  CRegexXQuery_char_ascii(CRegexXQuery_regex* regex, char c);
  virtual ~CRegexXQuery_char_ascii() {}

  virtual bool match_internal(const char *source, int *start_from_branch, int *matched_len);
  virtual unicode::code_point get_c() {return c;}
};

class CRegexXQuery_char_ascii_i : public CRegexXQuery_char_ascii
{
public:
  CRegexXQuery_char_ascii_i(CRegexXQuery_regex* regex, char c);
  virtual ~CRegexXQuery_char_ascii_i() {}

  virtual bool match_internal(const char *source, int *start_from_branch, int *matched_len);
  virtual unicode::code_point get_c()  {return c;}
};

class CRegexXQuery_char_range_ascii : public CRegexXQuery_charmatch
{
protected:
  char c1;
  char c2;
public:
  CRegexXQuery_char_range_ascii(CRegexXQuery_regex* regex, char c1, char c2);
  virtual ~CRegexXQuery_char_range_ascii() {}

  virtual bool match_internal(const char *source, int *start_from_branch, int *matched_len);
};

class CRegexXQuery_char_range_ascii_i : public CRegexXQuery_char_range_ascii
{
public:
  CRegexXQuery_char_range_ascii_i(CRegexXQuery_regex* regex, char c1, char c2);
  virtual ~CRegexXQuery_char_range_ascii_i() {}

  virtual bool match_internal(const char *source, int *start_from_branch, int *matched_len);
};

class CRegexXQuery_char_unicode : public CRegexXQuery_charmatch
{
  unsigned char c[6];
  int len;
public:
  CRegexXQuery_char_unicode(CRegexXQuery_regex* regex, const char *c, int len);
  virtual ~CRegexXQuery_char_unicode() {}

  virtual bool match_internal(const char *source, int *start_from_branch, int *matched_len);
  virtual unicode::code_point get_c();
};

class CRegexXQuery_char_unicode_cp : public CRegexXQuery_charmatch
{
protected:
  unicode::code_point c;
public:
  CRegexXQuery_char_unicode_cp(CRegexXQuery_regex* regex, unicode::code_point c);
  virtual ~CRegexXQuery_char_unicode_cp() {}

  virtual bool match_internal(const char *source, int *start_from_branch, int *matched_len);
  virtual unicode::code_point get_c()  {return c;}
};

class CRegexXQuery_char_unicode_i : public CRegexXQuery_char_unicode_cp
{
public:
  CRegexXQuery_char_unicode_i(CRegexXQuery_regex* regex, unicode::code_point c);
  virtual ~CRegexXQuery_char_unicode_i() {}

  virtual bool match_internal(const char *source, int *start_from_branch, int *matched_len);
  virtual unicode::code_point get_c()  {return c;}
};

class CRegexXQuery_char_range_unicode : public CRegexXQuery_charmatch
{
protected:
  unicode::code_point c1;
  unicode::code_point c2;
public:
  CRegexXQuery_char_range_unicode(CRegexXQuery_regex* regex, unicode::code_point c1, unicode::code_point c2);
  virtual ~CRegexXQuery_char_range_unicode() {}

  virtual bool match_internal(const char *source, int *start_from_branch, int *matched_len);
};

class CRegexXQuery_char_range_unicode_i : public CRegexXQuery_char_range_unicode
{
public:
  CRegexXQuery_char_range_unicode_i(CRegexXQuery_regex* regex, unicode::code_point c1, unicode::code_point c2);
  virtual ~CRegexXQuery_char_range_unicode_i() {}

  virtual bool match_internal(const char *source, int *start_from_branch, int *matched_len);
};

class CRegexXQuery_endline : public CRegexXQuery_charmatch
{
public:
  CRegexXQuery_endline(CRegexXQuery_regex* regex);
  virtual ~CRegexXQuery_endline() {}

  virtual bool match_internal(const char *source, int *start_from_branch, int *matched_len);
};


class CRegexXQuery_chargroup : public IRegexAtom
{
  friend class CRegexXQuery_parser;
public:
  CRegexXQuery_chargroup(CRegexXQuery_regex* regex);
  virtual ~CRegexXQuery_chargroup();
private:
/*  typedef struct
  {
    CHARGROUP_t  flags;
    char  c1;
    char  c2;
  }chargroup_t;
*/
  std::list<std::unique_ptr<CRegexXQuery_charmatch> >    chargroup_list;
  CRegexXQuery_chargroup *classsub;
public:
  //void addMultiChar(char c, CHARGROUP_t multichar_type);
  //void addEndLine();
  //void addCharRange(char c1, char c2);
  //void addOneChar(char c);
  void addCharMatch(CRegexXQuery_charmatch *charmatch);
  void addClassSub(CRegexXQuery_chargroup* classsub);

  virtual bool match_internal(const char *source, int *start_from_branch, int *matched_len);
};

class CRegexXQuery_negchargroup : public CRegexXQuery_chargroup
{
public:
  CRegexXQuery_negchargroup(CRegexXQuery_regex* regex);
  virtual ~CRegexXQuery_negchargroup();

  virtual bool match_internal(const char *source, int *start_from_branch, int *matched_len);
};

class CRegexXQuery_wildchar : public IRegexAtom
{
public:
  CRegexXQuery_wildchar(CRegexXQuery_regex* regex);
  virtual ~CRegexXQuery_wildchar();

  virtual bool match_internal(const char *source, int *start_from_branch, int *matched_len);
};

class CRegexXQuery_backref : public IRegexAtom
{
public:
  CRegexXQuery_backref(CRegexXQuery_regex* regex, unsigned int backref);
  virtual ~CRegexXQuery_backref();

  virtual bool match_internal(const char *source, int *start_from_branch, int *matched_len);
private:
  unsigned int backref;
};

class CRegexXQuery_pinstart : public IRegexAtom
{
public:
  CRegexXQuery_pinstart(CRegexXQuery_regex* regex);

  virtual bool match_internal(const char *source, int *start_from_branch, int *matched_len);
};

class CRegexXQuery_parser
{
public:
  typedef struct
  {
    const unicode::code_point    cp[2];//in pairs start, end
    const unicode::code_point    *ext_cp;
    const char    *group_name;
  }block_escape_t;

  CRegexXQuery_parser();
  ~CRegexXQuery_parser();

public:
  CRegexXQuery_regex* parse(const char *pattern, unsigned int flags);

protected:
  CRegexXQuery_regex* parse_regexp(const char *pattern, int *regex_len);
  CRegexXQuery_branch* parse_branch(const char *pattern, int *branch_len);
  CRegexXQuery_piece* parse_piece(const char *pattern, int *piece_len);
  char myishex(char c);
  bool myisdigit(char c);
  bool myisletterAZ(char c);
  CRegexXQuery_charmatch* readChar(const char *pattern, int *char_len, CHARGROUP_t *multichar_type);
  CRegexXQuery_charmatch *create_charmatch(unicode::code_point utf8c,
                                            const char *pattern, int utf8len,
                                            enum CHARGROUP_t *multichar_type);
  IRegexAtom* read_atom(const char *pattern, int *atom_len);
  CRegexXQuery_chargroup* readchargroup(const char *pattern, int *chargroup_len);
  void read_quantifier(CRegexXQuery_piece *piece, const char *pattern, int *quantif_len);

private:
  CRegexXQuery_regex   *current_regex;
  int   regex_depth;
  unsigned int flags;
};

}
}//end namespace zorba::regex_xquery

#endif
/* vim:set et sw=2 ts=2: */
