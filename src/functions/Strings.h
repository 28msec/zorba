/**
 * @copyright
 * ========================================================================
 *  Copyright FLWOR Foundation
 * ========================================================================
 *
 * @author Sorin Nasoi (sorin.nasoi@ipdevel.ro)
 * @file functions/Strings.h
 *
 */

#ifndef XQP_STRINGS_H
#define XQP_STRINGS_H

#include <vector>

#include "context/common.h"
#include "functions/function.h"

namespace xqp {
/*______________________________________________________________________
 *
 * 7.2 Functions to Assemble and Disassemble Strings
 *_______________________________________________________________________*/

/*
 * 7.2.1 fn:codepoints-to-string
 *-----------------------*/
class fn_codepoints_to_string: public function
{
public:
  fn_codepoints_to_string(const signature&);
  ~fn_codepoints_to_string() {}

public:
  PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
  TypeSystem::xqtref_t type_check(signature&) const;
  bool validate_args(std::vector<PlanIter_t>&) const;
};

/*
 * 7.2.2 fn:string-to-codepoints
 *-----------------------*/
  class fn_string_to_codepoints: public function
{
  public:
    fn_string_to_codepoints(const signature&);
    ~fn_string_to_codepoints() {}

  public:
    PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
    TypeSystem::xqtref_t type_check(signature&) const;
    bool validate_args(std::vector<PlanIter_t>&) const;
};

/*______________________________________________________________________
 *
 * 7.3 Equality and Comparison of Strings
 *_______________________________________________________________________*/
/*
 * 7.3.2 fn:compare
 *-----------------------*/
class fn_string_compare: public function
{
  public:
    fn_string_compare(const signature&);
    ~fn_string_compare() {}

  public:
    PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
    TypeSystem::xqtref_t type_check(signature&) const;
    bool validate_args(std::vector<PlanIter_t>&) const;
};

/*
 * 7.3.3 fn:codepoint-equal
 *-----------------------*/
class fn_codepoint_equal: public function
{
  public:
    fn_codepoint_equal(const signature&);
    ~fn_codepoint_equal() {}

  public:
    PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
    TypeSystem::xqtref_t type_check(signature&) const;
    bool validate_args(std::vector<PlanIter_t>&) const;
};

/*______________________________________________________________________
 *
 * 7.4 Functions on String Values
 *_______________________________________________________________________*/

/*
 * 7.4.1 fn:concat
 *-----------------------*/
class fn_concat: public function
{
  public:
    fn_concat(const signature&);
    ~fn_concat() {}

  public:
    PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
    TypeSystem::xqtref_t type_check(signature&) const;
    bool validate_args(std::vector<PlanIter_t>&) const;
};

/*
 * 7.4.2 fn:string-join
 *-----------------------*/
class fn_string_join: public function
{
  public:
    fn_string_join(const signature&);
    ~fn_string_join() {}

  public:
    PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
    TypeSystem::xqtref_t type_check(signature&) const;
    bool validate_args(std::vector<PlanIter_t>&) const;
};

/*
 * 7.4.3 fn:substring
 *-----------------------*/
class fn_substring: public function
{
  public:
    fn_substring(const signature&);
    ~fn_substring() {}

  public:
    PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
    TypeSystem::xqtref_t type_check(signature&) const;
    bool validate_args(std::vector<PlanIter_t>&) const;
};

/*
 * 7.4.4 fn:string-length
 * --------------------*/
class fn_string_length: public function
{
  public:
    fn_string_length(const signature&);
    ~fn_string_length() {}

  public:
    PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
    TypeSystem::xqtref_t type_check(signature&) const;
    bool validate_args(std::vector<PlanIter_t>&) const;
};

/*
 * 7.4.5 fn:normalize-space
 *-----------------------*/
class fn_normalize_space: public function
{
public:
  fn_normalize_space(const signature&);
  ~fn_normalize_space() {}

public:
  PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
  TypeSystem::xqtref_t type_check(signature&) const;
  bool validate_args(std::vector<PlanIter_t>&) const;
};

/*
 * 7.4.6 fn:normalize-unicode
 *-----------------------*/
class fn_normalize_unicode: public function
{
public:
  fn_normalize_unicode(const signature&);
  ~fn_normalize_unicode() {}

public:
  PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
  TypeSystem::xqtref_t type_check(signature&) const;
  bool validate_args(std::vector<PlanIter_t>&) const;
};

/*
 * 7.4.7 fn:upper-case
 *-----------------------*/
class fn_upper_case: public function
{
public:
  fn_upper_case(const signature&);
  ~fn_upper_case() {}

public:
  PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
  TypeSystem::xqtref_t type_check(signature&) const;
  bool validate_args(std::vector<PlanIter_t>&) const;
};

/*
 * 7.4.8 fn:lower-case
 *-----------------------*/
class fn_lower_case: public function
{
public:
  fn_lower_case(const signature&);
  ~fn_lower_case() {}

public:
  PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
  TypeSystem::xqtref_t type_check(signature&) const;
  bool validate_args(std::vector<PlanIter_t>&) const;
};

/*
 * 7.4.9 fn:translate
 *-----------------------*/
class fn_translate: public function
{
public:
  fn_translate(const signature&);
  ~fn_translate() {}

public:
  PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
  TypeSystem::xqtref_t type_check(signature&) const;
  bool validate_args(std::vector<PlanIter_t>&) const;
};

/*______________________________________________________________________
 *
 * 7.5 Functions Based on Substring Matching
 *_______________________________________________________________________*/
/*
 * 7.5.1 fn:contains
 *-----------------------*/
class fn_contains: public function
{
  public:
    fn_contains(const signature&);
    ~fn_contains() {}

  public:
    PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
    TypeSystem::xqtref_t type_check(signature&) const;
    bool validate_args(std::vector<PlanIter_t>&) const;
};

/*
 * 7.5.2 fn:starts-with
 *-----------------------*/
class fn_starts_with: public function
{
  public:
    fn_starts_with(const signature&);
    ~fn_starts_with() {}

  public:
    PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
    TypeSystem::xqtref_t type_check(signature&) const;
    bool validate_args(std::vector<PlanIter_t>&) const;
};

/*
 * 7.5.3 fn:ends-with
 *-----------------------*/
class fn_ends_with: public function
{
  public:
    fn_ends_with(const signature&);
    ~fn_ends_with() {}

  public:
    PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
    TypeSystem::xqtref_t type_check(signature&) const;
    bool validate_args(std::vector<PlanIter_t>&) const;
};

/*
 * 7.5.4 fn:substring-before
 *-----------------------*/
class fn_substring_before: public function
{
  public:
    fn_substring_before(const signature&);
    ~fn_substring_before() {}

  public:
    PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
    TypeSystem::xqtref_t type_check(signature&) const;
    bool validate_args(std::vector<PlanIter_t>&) const;
};

/*
 * 7.5.5 fn:substring-after
 *-----------------------*/
class fn_substring_after: public function
{
  public:
    fn_substring_after(const signature&);
    ~fn_substring_after() {}

  public:
    PlanIter_t operator()(const yy::location& loc, std::vector<PlanIter_t>&) const;
    TypeSystem::xqtref_t type_check(signature&) const;
    bool validate_args(std::vector<PlanIter_t>&) const;
};

} /* namespace xqp */
#endif /* XQP_STRINGS_H */
