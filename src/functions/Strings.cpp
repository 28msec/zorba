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
#include "errors/error_manager.h"
#include "zorbatypes/Unicode_util.h"

using namespace std;
namespace zorba {

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
fn_codepoints_to_string::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new CodepointsToStringIterator(loc, argv[0]);
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
fn_string_to_codepoints::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new StringToCodepointsIterator(loc, argv[0]);
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
fn_string_compare_2::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new CompareStrIterator(loc, argv);
}



fn_string_compare_3::fn_string_compare_3(
    const signature& sig)
  :
    function(sig)
{
}

PlanIter_t
fn_string_compare_3::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new CompareStrIterator(loc, argv);
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
fn_codepoint_equal::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new CodepointEqualIterator(loc, argv[0], argv[1]);
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
fn_concat::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  unsigned sz = argv.size ();
  if (sz < 2)
    ZORBA_ERROR_PARAM (ZorbaError::XPST0017, "fn_concat", to_string (sz));
  return new ConcatStrIterator(loc,argv);
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
fn_string_join::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new StringJoinIterator(loc, argv[0], argv[1]);
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
fn_substring_2::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new SubstringIterator(loc, argv);
}



fn_substring_3::fn_substring_3(
  const signature& sig)
:
  function(sig)
{
}

PlanIter_t
fn_substring_3::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new SubstringIterator(loc, argv);
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
fn_string_length::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new StringLengthIterator(loc, argv[0]);
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
fn_normalize_space::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new NormalizeSpaceIterator(loc, argv[0]);
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
fn_normalize_unicode_1::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new NormalizeUnicodeIterator(loc, argv);
}



fn_normalize_unicode_2::fn_normalize_unicode_2(
  const signature& sig)
:
  function(sig)
{
}

PlanIter_t
fn_normalize_unicode_2::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new NormalizeUnicodeIterator(loc, argv);
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
fn_upper_case::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new UpperCaseIterator(loc, argv[0]);
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
fn_lower_case::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new LowerCaseIterator(loc, argv[0]);
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
fn_translate::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new TranslateIterator(loc, argv);
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
fn_encode_for_uri::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new EncodeForUriIterator(loc, argv[0]);
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
fn_iri_to_uri::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new IriToUriIterator(loc, argv[0]);
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
fn_escape_html_uri::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new EscapeHtmlUriIterator(loc, argv[0]);
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
fn_contains_2::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new ContainsIterator(loc, argv);
}



fn_contains_3::fn_contains_3(
  const signature& sig)
:
  function(sig)
{
}

PlanIter_t
fn_contains_3::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new ContainsIterator(loc, argv);
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
fn_starts_with_2::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new StartsWithIterator(loc, argv);
}



fn_starts_with_3::fn_starts_with_3(
  const signature& sig)
:
  function(sig)
{
}

PlanIter_t
fn_starts_with_3::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new StartsWithIterator(loc, argv);
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
fn_ends_with_2::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new EndsWithIterator(loc, argv);
}



fn_ends_with_3::fn_ends_with_3(
  const signature& sig)
:
  function(sig)
{
}

PlanIter_t
fn_ends_with_3::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new EndsWithIterator(loc, argv);
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
fn_substring_before_2::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new SubstringBeforeIterator(loc, argv);
}



fn_substring_before_3::fn_substring_before_3(
  const signature& sig)
:
  function(sig)
{
}

PlanIter_t
fn_substring_before_3::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new SubstringBeforeIterator(loc, argv);
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
fn_substring_after_2::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new SubstringAfterIterator(loc, argv);
}



fn_substring_after_3::fn_substring_after_3(
  const signature& sig)
:
  function(sig)
{
}

PlanIter_t
fn_substring_after_3::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new SubstringAfterIterator(loc, argv);
}


/*end class fn_substring_after*/


/*
 * 7.6.2 fn:matches
 * --------------------*/
/*begin class fn_matches*/
fn_matches::fn_matches( const signature& sig ) : function(sig)
{
}

PlanIter_t
fn_matches::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new FnMatchesIterator(loc, argv);
}


/*end class fn_matches*/

/*
 * 7.6.3 fn:replace
 * --------------------*/
/*begin class fn_replace*/
fn_replace::fn_replace( const signature& sig ) : function(sig)
{
}

PlanIter_t
fn_replace::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new FnReplaceIterator(loc, argv);
}


/*end class fn_replace*/

/*
 * 7.6.4 fn:tokenize
 * --------------------*/
/*begin class fn_tokenize*/
fn_tokenize::fn_tokenize( const signature& sig ) : function(sig)
{
}

PlanIter_t
fn_tokenize::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new FnTokenizeIterator(loc, argv);
}


/*end class fn_tokenize*/
}/*namespace zorba*/
