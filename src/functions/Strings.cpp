/**
 * @copyright
 * ========================================================================
 *  Copyright FLWOR Foundation
 * ========================================================================
 *
 * @author Sorin Nasoi (sorin.nasoi@ipdevel.ro)
 * @file functions/Strings.cpp
 *
 */

#include <iostream>
#include "system/globalenv.h"
#include "functions/Strings.h"
#include "runtime/strings/StringsImpl.h"

using namespace std;
namespace xqp {

/*
 * 7.2.1 fn:codepoints-to-string
 * --------------------*/
/*begin class fn_codepoints_to_string*/
fn_codepoints_to_string::fn_codepoints_to_string(
  const signature& sig)
:
  function(sig)
{
}

PlanIter_t
fn_codepoints_to_string::operator()(
  const yy::location& loc,
  vector<PlanIter_t>& argv) const
{
  return new CodepointsToStringIterator(loc, argv[0]);
}

TypeSystem::xqtref_t
fn_codepoints_to_string::type_check(
  signature& sig) const
{
  return GENV_TYPESYSTEM.INTEGER_TYPE_STAR;
}

bool
fn_codepoints_to_string::validate_args(
  vector<PlanIter_t>& argv) const
{
  return true;
}
/*end class fn_codepoints_to_string*/

/*
 * 7.2.2 fn:string-to-codepoints
 * --------------------*/
/*begin class fn_string_to_codepoints*/
fn_string_to_codepoints::fn_string_to_codepoints(
  const signature& sig)
:
  function(sig)
  {
  }

PlanIter_t
fn_string_to_codepoints::operator()(
  const yy::location& loc,
  vector<PlanIter_t>& argv) const
{
  return new StringToCodepointsIterator(loc, argv[0]);
}

TypeSystem::xqtref_t
fn_string_to_codepoints::type_check(
  signature& sig) const
{
  return GENV_TYPESYSTEM.STRING_TYPE_QUESTION;
}

bool
fn_string_to_codepoints::validate_args(
    vector<PlanIter_t>& argv) const
{
  return true;
}
/*end class fn_string_to_codepoints*/

/*
 * 7.3.2 fn:compare
 * --------------------*/
/*begin class fn_string_compare*/
fn_string_compare_2::fn_string_compare_2(
  const signature& sig)
:
  function(sig)
{
}

PlanIter_t
fn_string_compare_2::operator()(
  const yy::location& loc,
  vector<PlanIter_t>& argv) const
{
  return new CompareStrIterator(loc, argv);
}

TypeSystem::xqtref_t
fn_string_compare_2::type_check(
  signature& sig) const
{
  return GENV_TYPESYSTEM.STRING_TYPE_QUESTION;
}

bool
fn_string_compare_2::validate_args(
  vector<PlanIter_t>& argv) const
{
  return (argv.size() == 2);
}

fn_string_compare_3::fn_string_compare_3(
    const signature& sig)
  :
    function(sig)
{
}

PlanIter_t
fn_string_compare_3::operator()(
    const yy::location& loc,
  vector<PlanIter_t>& argv) const
{
  return new CompareStrIterator(loc, argv);
}

TypeSystem::xqtref_t
fn_string_compare_3::type_check(
    signature& sig) const
{
  return GENV_TYPESYSTEM.STRING_TYPE_QUESTION;
}

bool
fn_string_compare_3::validate_args(
    vector<PlanIter_t>& argv) const
{
  return (argv.size() == 3);
}
/*end class fn_string_compare*/

/*
 * 7.3.3 fn:codepoint-equal
 * --------------------*/
/*begin class fn_codepoint_equal*/
fn_codepoint_equal::fn_codepoint_equal(
    const signature& sig)
  :
    function(sig)
{
}

PlanIter_t
fn_codepoint_equal::operator()(
  const yy::location& loc,
  vector<PlanIter_t>& argv) const
{
  return new CodepointEqualIterator(loc, argv[0], argv[1]);
}

TypeSystem::xqtref_t
fn_codepoint_equal::type_check(
  signature& sig) const
{
  return GENV_TYPESYSTEM.STRING_TYPE_QUESTION;
}

bool
fn_codepoint_equal::validate_args(
  vector<PlanIter_t>& argv) const
{
  return (argv.size() == 2);
}
/*end class fn_codepoint_equal*/

/*
 * 7.4.1 fn:string-concat
 * --------------------*/
/*begin class fn_concat*/
fn_concat::fn_concat(
  const signature& sig)
:
  function(sig)
{
}

PlanIter_t
fn_concat::operator()(
  const yy::location& loc,
  vector<PlanIter_t>& argv) const
{
    return new ConcatStrIterator(loc,argv);
}

bool
fn_concat::validate_args(
  vector<PlanIter_t>& argv) const
{
  return true;
}

TypeSystem::xqtref_t
fn_concat::type_check(
  signature& sig) const
{
  return GENV_TYPESYSTEM.ITEM_TYPE_STAR;
}
/*end class fn_concat*/

/*
 * 7.4.2 fn:string-join
 * --------------------*/
/*begin class fn_string_join*/
fn_string_join::fn_string_join(
  const signature& sig)
:
  function(sig)
{
}

PlanIter_t
fn_string_join::operator()(
  const yy::location& loc,
  vector<PlanIter_t>& argv) const
{
  return new StringJoinIterator(loc, argv[0], argv[1]);
}

TypeSystem::xqtref_t
fn_string_join::type_check(
  signature& sig) const
{
  return GENV_TYPESYSTEM.STRING_TYPE_STAR;
}

bool
fn_string_join::validate_args(
  vector<PlanIter_t>& argv) const
{
  return (/*argv.size() == 1 || */argv.size() == 2);
}
/*end class fn_string_join*/

/*
 * 7.4.3 fn:substring
 * --------------------*/
/*begin class fn_substring*/
fn_substring_2::fn_substring_2(
  const signature& sig)
:
  function(sig)
{
}

PlanIter_t
fn_substring_2::operator()(
  const yy::location& loc,
  vector<PlanIter_t>& argv) const
{
  return new SubstringIterator(loc, argv);
}

TypeSystem::xqtref_t
fn_substring_2::type_check(
  signature& sig) const
{
  return GENV_TYPESYSTEM.STRING_TYPE_QUESTION;
}

bool
fn_substring_2::validate_args(
  vector<PlanIter_t>& argv) const
{
  return (argv.size()==2);
}

fn_substring_3::fn_substring_3(
  const signature& sig)
:
  function(sig)
{
}

PlanIter_t
fn_substring_3::operator()(
  const yy::location& loc,
  vector<PlanIter_t>& argv) const
{
  return new SubstringIterator(loc, argv);
}

TypeSystem::xqtref_t
fn_substring_3::type_check(
  signature& sig) const
{
  return GENV_TYPESYSTEM.STRING_TYPE_QUESTION;
}

bool
fn_substring_3::validate_args(
  vector<PlanIter_t>& argv) const
{
  return (argv.size()==3);
}
/*end class fn_substring*/

/*
 * 7.4.4 fn:string-length
 * --------------------*/
/*begin class fn_string_length*/
fn_string_length::fn_string_length(
  const signature& sig)
:
  function(sig)
{
}

PlanIter_t
fn_string_length::operator()(
  const yy::location& loc,
  vector<PlanIter_t>& argv) const
{
  return new StringLengthIterator(loc, argv[0]);
}

TypeSystem::xqtref_t
fn_string_length::type_check(
  signature& sig) const
{
  return GENV_TYPESYSTEM.STRING_TYPE_QUESTION;
}

bool
fn_string_length::validate_args(
  vector<PlanIter_t>& argv) const
{
  return (argv.size() == 1);
}
/*end class fn_string_length*/

/*
 * 7.4.5 fn:normalize-space
 * --------------------*/
/*begin class fn_normalize_space*/
fn_normalize_space::fn_normalize_space(
  const signature& sig)
:
  function(sig)
{
}

PlanIter_t
fn_normalize_space::operator()(
  const yy::location& loc,
  vector<PlanIter_t>& argv) const
{
  return new NormalizeSpaceIterator(loc, argv[0]);
}

TypeSystem::xqtref_t
fn_normalize_space::type_check(
  signature& sig) const
{
  return GENV_TYPESYSTEM.STRING_TYPE_QUESTION;
}

bool
fn_normalize_space::validate_args(
  vector<PlanIter_t>& argv) const
{
  return (argv.size() == 1);
}
/*end class fn_normalize_space*/

/*
 * 7.4.6 fn:normalize-unicode
 * --------------------*/
/*begin class fn_normalize_unicode*/
fn_normalize_unicode_1::fn_normalize_unicode_1(
  const signature& sig)
:
  function(sig)
{
}

PlanIter_t
fn_normalize_unicode_1::operator()(
  const yy::location& loc,
  vector<PlanIter_t>& argv) const
{
  return new NormalizeUnicodeIterator(loc, argv);
}

TypeSystem::xqtref_t
fn_normalize_unicode_1::type_check(
  signature& sig) const
{
  return GENV_TYPESYSTEM.STRING_TYPE_QUESTION;
}

bool
fn_normalize_unicode_1::validate_args(
  vector<PlanIter_t>& argv) const
{
  return (argv.size()==1);
}

fn_normalize_unicode_2::fn_normalize_unicode_2(
  const signature& sig)
:
  function(sig)
{
}

PlanIter_t
fn_normalize_unicode_2::operator()(
  const yy::location& loc,
  vector<PlanIter_t>& argv) const
{
  return new NormalizeUnicodeIterator(loc, argv);
}

TypeSystem::xqtref_t
fn_normalize_unicode_2::type_check(
  signature& sig) const
{
  return GENV_TYPESYSTEM.STRING_TYPE_QUESTION;
}

bool
fn_normalize_unicode_2::validate_args(
  vector<PlanIter_t>& argv) const
{
  return (argv.size()==2);
}
/*end class fn_normalize_unicode*/


/*
 * 7.4.7 fn:upper-case
 * --------------------*/
/*begin class fn_upper_case*/
fn_upper_case::fn_upper_case(
  const signature& sig)
:
  function(sig)
{
}

PlanIter_t
fn_upper_case::operator()(
  const yy::location& loc,
  vector<PlanIter_t>& argv) const
{
  return new UpperCaseIterator(loc, argv[0]);
}

TypeSystem::xqtref_t
fn_upper_case::type_check(
  signature& sig) const
{
  return GENV_TYPESYSTEM.STRING_TYPE_QUESTION;
}

bool
fn_upper_case::validate_args(
  vector<PlanIter_t>& argv) const
{
    return (argv.size()==1);
}
/*end class fn_upper_case*/


/*
 * 7.4.8 fn:lower-case
 * --------------------*/
/*begin class fn_lower_case*/
fn_lower_case::fn_lower_case(
  const signature& sig)
:
  function(sig)
{
}

PlanIter_t
fn_lower_case::operator()(
  const yy::location& loc,
  vector<PlanIter_t>& argv) const
{
  return new LowerCaseIterator(loc, argv[0]);
}

TypeSystem::xqtref_t
fn_lower_case::type_check(
  signature& sig) const
{
  return GENV_TYPESYSTEM.STRING_TYPE_QUESTION;
}

bool
fn_lower_case::validate_args(
  vector<PlanIter_t>& argv) const
{
    return (argv.size()==1);
}
/*end class fn_lower_case*/


/*
 * 7.4.9 fn:translate
 * --------------------*/
/*begin class fn_translate*/
fn_translate::fn_translate(
  const signature& sig)
:
  function(sig)
{
}

PlanIter_t
fn_translate::operator()(
  const yy::location& loc,
  vector<PlanIter_t>& argv) const
{
  return new TranslateIterator(loc, argv);
}

TypeSystem::xqtref_t
fn_translate::type_check(
  signature& sig) const
{
  return GENV_TYPESYSTEM.STRING_TYPE_QUESTION;
}

bool
fn_translate::validate_args(
vector<PlanIter_t>& argv) const
{
  return (argv.size()==3);
}
/*end class fn_translate*/

/*
 * 7.4.10 fn:encode-for-uri
 * --------------------*/
/*begin class fn_encode_for_uri*/
fn_encode_for_uri::fn_encode_for_uri(
const signature& sig)
:
function(sig)
{
}

PlanIter_t
fn_encode_for_uri::operator()(
const yy::location& loc,
vector<PlanIter_t>& argv) const
{
  return new EncodeForUriIterator(loc, argv[0]);
}

TypeSystem::xqtref_t
fn_encode_for_uri::type_check(
  signature& sig) const
{
  return GENV_TYPESYSTEM.STRING_TYPE_QUESTION;
}

bool
fn_encode_for_uri::validate_args(
    vector<PlanIter_t>& argv) const
{
  return true;
}
/*end class fn_encode_for_uri*/

/*
 * 7.4.11 fn:iri-to-uri
 * --------------------*/
/*begin class fn_iri_to_uri*/
fn_iri_to_uri::fn_iri_to_uri(
const signature& sig)
:
function(sig)
{
}

PlanIter_t
fn_iri_to_uri::operator()(
const yy::location& loc,
vector<PlanIter_t>& argv) const
{
  return new IriToUriIterator(loc, argv[0]);
}

TypeSystem::xqtref_t
fn_iri_to_uri::type_check(
signature& sig) const
{
  return GENV_TYPESYSTEM.STRING_TYPE_QUESTION;
}

bool
fn_iri_to_uri::validate_args(
    vector<PlanIter_t>& argv) const
{
  return true;
}
/*end class fn_iri_to_uri*/

/*
 * 7.4.12 fn:escape-html-uri
 * --------------------*/
/*begin class fn_escape_html_uri*/
fn_escape_html_uri::fn_escape_html_uri(
const signature& sig)
:
  function(sig)
  {
  }

PlanIter_t
fn_escape_html_uri::operator()(
  const yy::location& loc,
  vector<PlanIter_t>& argv) const
{
  return new EscapeHtmlUriIterator(loc, argv[0]);
}

TypeSystem::xqtref_t
fn_escape_html_uri::type_check(
  signature& sig) const
{
  return GENV_TYPESYSTEM.STRING_TYPE_QUESTION;
}

bool
fn_escape_html_uri::validate_args(
    vector<PlanIter_t>& argv) const
{
  return true;
}
/*end class fn_escape_html_uri*/


/*
 * 7.5.1 fn:contains
 * --------------------*/
/*begin class fn_contains*/
fn_contains_2::fn_contains_2(
  const signature& sig)
:
  function(sig)
{
}

PlanIter_t
fn_contains_2::operator()(
  const yy::location& loc,
  vector<PlanIter_t>& argv) const
{
  return new ContainsIterator(loc, argv);
}

TypeSystem::xqtref_t
fn_contains_2::type_check(
  signature& sig) const
{
  return GENV_TYPESYSTEM.STRING_TYPE_QUESTION;
}

bool
fn_contains_2::validate_args(
  vector<PlanIter_t>& argv) const
{
    return (argv.size() == 2);
}

fn_contains_3::fn_contains_3(
  const signature& sig)
:
  function(sig)
{
}

PlanIter_t
fn_contains_3::operator()(
  const yy::location& loc,
  vector<PlanIter_t>& argv) const
{
  return new ContainsIterator(loc, argv);
}

TypeSystem::xqtref_t
fn_contains_3::type_check(
  signature& sig) const
{
  return GENV_TYPESYSTEM.STRING_TYPE_QUESTION;
}

bool
fn_contains_3::validate_args(
  vector<PlanIter_t>& argv) const
{
    return (argv.size() == 3);
}
/*end class fn_contains*/

/*
 * 7.5.2 fn:starts-with
 * --------------------*/
/*begin class fn_starts_with*/
fn_starts_with_2::fn_starts_with_2(
  const signature& sig)
:
  function(sig)
{
}

PlanIter_t
fn_starts_with_2::operator()(
  const yy::location& loc,
  vector<PlanIter_t>& argv) const
{
  return new StartsWithIterator(loc, argv);
}

TypeSystem::xqtref_t
fn_starts_with_2::type_check(
  signature& sig) const
{
  return GENV_TYPESYSTEM.STRING_TYPE_QUESTION;
}

bool
fn_starts_with_2::validate_args(
  vector<PlanIter_t>& argv) const
{
    return (argv.size() == 2);
}

fn_starts_with_3::fn_starts_with_3(
  const signature& sig)
:
  function(sig)
{
}

PlanIter_t
fn_starts_with_3::operator()(
  const yy::location& loc,
  vector<PlanIter_t>& argv) const
{
  return new StartsWithIterator(loc, argv);
}

TypeSystem::xqtref_t
fn_starts_with_3::type_check(
  signature& sig) const
{
  return GENV_TYPESYSTEM.STRING_TYPE_QUESTION;
}

bool
fn_starts_with_3::validate_args(
  vector<PlanIter_t>& argv) const
{
    return (argv.size() == 3);
}
/*end class fn_starts_with*/

/*
 * 7.5.3 fn:ends-with
 * --------------------*/
/*begin class fn_ends_with*/
fn_ends_with_2::fn_ends_with_2(
  const signature& sig)
:
  function(sig)
{
}

PlanIter_t
fn_ends_with_2::operator()(
  const yy::location& loc,
  vector<PlanIter_t>& argv) const
{
  return new EndsWithIterator(loc, argv);
}

TypeSystem::xqtref_t
fn_ends_with_2::type_check(
  signature& sig) const
{
  return GENV_TYPESYSTEM.STRING_TYPE_QUESTION;
}

bool
fn_ends_with_2::validate_args(
  vector<PlanIter_t>& argv) const
{
    return (argv.size() == 2);
}

fn_ends_with_3::fn_ends_with_3(
  const signature& sig)
:
  function(sig)
{
}

PlanIter_t
fn_ends_with_3::operator()(
  const yy::location& loc,
  vector<PlanIter_t>& argv) const
{
  return new EndsWithIterator(loc, argv);
}

TypeSystem::xqtref_t
fn_ends_with_3::type_check(
  signature& sig) const
{
  return GENV_TYPESYSTEM.STRING_TYPE_QUESTION;
}

bool
fn_ends_with_3::validate_args(
  vector<PlanIter_t>& argv) const
{
    return (argv.size() == 3);
}
/*end class fn_ends_with*/

/*
 * 7.5.4 fn:substring-before
 * --------------------*/
/*begin class fn_substring_before*/
fn_substring_before_2::fn_substring_before_2(
  const signature& sig)
:
  function(sig)
{
}

PlanIter_t
fn_substring_before_2::operator()(
  const yy::location& loc,
  vector<PlanIter_t>& argv) const
{
  return new SubstringBeforeIterator(loc, argv);
}

TypeSystem::xqtref_t
fn_substring_before_2::type_check(
  signature& sig) const
{
  return GENV_TYPESYSTEM.STRING_TYPE_QUESTION;
}

bool
fn_substring_before_2::validate_args(
  vector<PlanIter_t>& argv) const
{
  return (argv.size() == 2);
}

fn_substring_before_3::fn_substring_before_3(
  const signature& sig)
:
  function(sig)
{
}

PlanIter_t
fn_substring_before_3::operator()(
  const yy::location& loc,
  vector<PlanIter_t>& argv) const
{
  return new SubstringBeforeIterator(loc, argv);
}

TypeSystem::xqtref_t
fn_substring_before_3::type_check(
  signature& sig) const
{
  return GENV_TYPESYSTEM.STRING_TYPE_QUESTION;
}

bool
fn_substring_before_3::validate_args(
  vector<PlanIter_t>& argv) const
{
  return (argv.size() == 3);
}
/*end class fn_substring_before*/

/*
 * 7.5.5 fn:substring-after
 * --------------------*/
/*begin class fn_substring_after*/
fn_substring_after_2::fn_substring_after_2(
  const signature& sig)
:
  function(sig)
{
}

PlanIter_t
fn_substring_after_2::operator()(
  const yy::location& loc,
  vector<PlanIter_t>& argv) const
{
  return new SubstringAfterIterator(loc, argv);
}

TypeSystem::xqtref_t
fn_substring_after_2::type_check(
  signature& sig) const
{
  return GENV_TYPESYSTEM.STRING_TYPE_QUESTION;
}

bool
fn_substring_after_2::validate_args(
  vector<PlanIter_t>& argv) const
{
  return (argv.size() == 2);
}

fn_substring_after_3::fn_substring_after_3(
  const signature& sig)
:
  function(sig)
{
}

PlanIter_t
fn_substring_after_3::operator()(
  const yy::location& loc,
  vector<PlanIter_t>& argv) const
{
  return new SubstringAfterIterator(loc, argv);
}

TypeSystem::xqtref_t
fn_substring_after_3::type_check(
  signature& sig) const
{
  return GENV_TYPESYSTEM.STRING_TYPE_QUESTION;
}

bool
fn_substring_after_3::validate_args(
  vector<PlanIter_t>& argv) const
{
  return (argv.size() == 3);
}
/*end class fn_substring_after*/
}/*namespace xqp*/
