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

PlanIter_t
fn_string_to_codepoints::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new StringToCodepointsIterator(loc, argv[0]);
}



/*end class fn_string_to_codepoints*/


/*
 * 7.3.3 fn:codepoint-equal
 * --------------------*/
/*begin class fn_codepoint_equal*/


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


PlanIter_t
fn_string_join::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new StringJoinIterator(loc, argv[0], argv[1]);
}


/*end class fn_string_join*/


/*
 * 7.4.4 fn:string-length
 * --------------------*/
/*begin class fn_string_length*/


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


PlanIter_t
fn_normalize_space::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new NormalizeSpaceIterator(loc, argv[0]);
}


/*end class fn_normalize_space*/


/*
 * 7.4.7 fn:upper-case
 * --------------------*/
/*begin class fn_upper_case*/


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


PlanIter_t
fn_lower_case::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new LowerCaseIterator(loc, argv[0]);
}


/*end class fn_lower_case*/


/*
 * 7.4.10 fn:encode-for-uri
 * --------------------*/
/*begin class fn_encode_for_uri*/


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

PlanIter_t
fn_escape_html_uri::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new EscapeHtmlUriIterator(loc, argv[0]);
}


/*end class fn_escape_html_uri*/


}/*namespace zorba*/
