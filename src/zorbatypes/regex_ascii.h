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
#ifndef ZORBA_MINIMAL_REGULAR_EXPRESSIONS_14_MAY_2008
#define ZORBA_MINIMAL_REGULAR_EXPRESSIONS_14_MAY_2008

#include <list>
#include <vector>

namespace zorba {
  namespace regex_ascii{

//matching flags
#define REGEX_ASCII_CASE_INSENSITIVE    1
#define REGEX_ASCII_DOTALL              2
#define REGEX_ASCII_MULTILINE           4
#define REGEX_ASCII_COMMENTS            8

class CRegexAscii_regex;

class IRegexMatcher
{
public:
  CRegexAscii_regex *regex_intern;
public:
  IRegexMatcher(CRegexAscii_regex* regex) : regex_intern(regex) {}
  virtual ~IRegexMatcher() {}

  virtual bool match(const char *source, int *matched_len) = 0;
};

class IRegexAtom : public IRegexMatcher
{
public:
  IRegexAtom(CRegexAscii_regex* regex) : IRegexMatcher(regex) {}
  virtual ~IRegexAtom() {}
};

class CRegexAscii_branch;
class CRegexAscii_piece;
class CRegexAscii_chargroup;
class CRegexAscii_parser;

class CRegexAscii_regex : public IRegexAtom
{
  friend class CRegexAscii_parser;
public:
  CRegexAscii_regex(CRegexAscii_regex *);
  virtual ~CRegexAscii_regex();

  bool match_anywhere(const char *source, int flags, int *match_pos, int *matched_len);
  virtual bool match(const char *source, int *matched_len);
public:
  int flags;
private:
  std::list<CRegexAscii_branch*>   branch_list;
  bool  align_begin;
private:
  void set_align_begin(bool align_begin);
  void add_branch(CRegexAscii_branch *branch);
};

class CRegexAscii_branch : public IRegexMatcher
{
  friend class CRegexAscii_parser;
public:
  CRegexAscii_branch(CRegexAscii_regex* regex);
  ~CRegexAscii_branch();

  virtual bool match(const char *source, int *matched_len);
private:
  std::list<CRegexAscii_piece*>   piece_list;
private:
  void add_piece(CRegexAscii_piece *piece);
 
  bool match_piece_iter_reluctant(std::list<CRegexAscii_piece*>::iterator piece_it,
                        const char *source, int *matched_len);
  bool match_piece_iter_normal(std::list<CRegexAscii_piece*>::iterator piece_it,
                        const char *source, int *matched_len);
};

class CRegexAscii_piece //: public IRegexMatcher
{
  friend class CRegexAscii_parser;
public:
  IRegexAtom *atom;
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
  bool match_piece_times(const char *source, 
                         int *piecelen, 
                         int times,
                         std::vector<int>    *match_lens);
};

#define   CHARGROUP_FLAGS_MULTICHAR   1
#define   CHARGROUP_FLAGS_ENDLINE     2

class CRegexAscii_chargroup : public IRegexAtom
{
  friend class CRegexAscii_parser;
public:
  CRegexAscii_chargroup(CRegexAscii_regex* regex);
  virtual ~CRegexAscii_chargroup();
private:
  typedef struct
  {
    unsigned char  flags;
    char  c1;
    char  c2;
  }chargroup_t;
  std::list<chargroup_t>    chargroup_list;
  CRegexAscii_chargroup *classsub;
public:
  void addMultiChar(char c);
  void addEndLine();
  void addCharRange(char c1, char c2);
  void addClassSub(CRegexAscii_chargroup* classsub);

  virtual bool match(const char *source, int *matched_len);
};

class CRegexAscii_negchargroup : public CRegexAscii_chargroup
{
public:
  CRegexAscii_negchargroup(CRegexAscii_regex* regex);
  virtual ~CRegexAscii_negchargroup();

  virtual bool match(const char *source, int *matched_len);
};

class CRegexAscii_wildchar : public IRegexAtom
{
public:
  CRegexAscii_wildchar(CRegexAscii_regex* regex);
  virtual ~CRegexAscii_wildchar();

  virtual bool match(const char *source, int *matched_len);
};

class CRegexAscii_parser
{
public:
  CRegexAscii_parser();
  ~CRegexAscii_parser();

public:
  CRegexAscii_regex* parse(const char *pattern);

protected:
  CRegexAscii_regex* parse_regexp(const char *pattern, int *regex_len);
  CRegexAscii_branch* parse_branch(const char *pattern, int *branch_len);
  CRegexAscii_piece* parse_piece(const char *pattern, int *piece_len);
  char myishex(char c);
  bool myisdigit(char c);
  char readChar(const char *pattern, int *char_len, bool *is_multichar);
  IRegexAtom* read_atom(const char *pattern, int *atom_len);
  CRegexAscii_chargroup* readchargroup(const char *pattern, int *chargroup_len);
  void read_quantifier(CRegexAscii_piece *piece, const char *pattern, int *quantif_len);

private:
  CRegexAscii_regex   *current_regex;
};

}}//end namespace zorba::regex_ascii

#endif
