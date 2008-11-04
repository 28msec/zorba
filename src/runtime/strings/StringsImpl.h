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
#ifndef ZORBA_STRINGS_IMPL_H
#define ZORBA_STRINGS_IMPL_H

#include "zorbautils/checked_vector.h"

#include "common/common.h"
#include "common/shared_types.h"

#include "runtime/base/binarybase.h"
#include "runtime/base/unarybase.h"
#include "runtime/base/narybase.h"


namespace zorba {


/*______________________________________________________________________
 *
 * 7.2 Functions to Assemble and Disassemble Strings
 *_______________________________________________________________________*/

 /*
 * 7.2.1 fn:codepoints-to-string
 * -------------------- */
/* begin class CodepointsToStringIterator */
NARY_ITER (CodepointsToStringIterator);
/* end class CodepointsToStringIterator */


/*
 * 7.2.2 fn:string-to-codepoints
 * --------------------*/
/*begin class StringToCodepointsIterator*/
class StringToCodepointsState : public PlanIteratorState
{
private:
  checked_vector<xqp_uint> resVector;
  xqp_uint iter;
public:
  void init(PlanState&);
  void reset(PlanState&);

  // TODO for performance reasons we should inline these functions or provide direct access to the members
  void setIterator(xqp_uint);
  void setVector(checked_vector<xqp_uint> vect);
  
  xqp_uint getItem(xqp_uint iter);
  xqp_uint getVectSize();
  xqp_uint getIterator();
};


NARY_ITER_STATE (StringToCodepointsIterator, StringToCodepointsState);
/*end class StringToCodepointsIterator*/

/*______________________________________________________________________
 *
 * 7.3 Equality and Comparison of Strings
 *_______________________________________________________________________*/

/*
 * 7.3.2 fn:compare
 * --------------------*/
/* begin class CompareStrIterator */
NARY_ITER (CompareStrIterator);
/* end class CompareStrIterator */

/*
 * 7.3.3 fn:codepoint-equal
 * --------------------*/
/*begin class CodepointEqualIterator */
NARY_ITER (CodepointEqualIterator);
/*end class CodepointEqualIterator */

/*______________________________________________________________________
 *
 * 7.4 Functions on String Values
 *_______________________________________________________________________*/

/*
 * 7.4.1 fn:concat
 * --------------------*/
/*begin class ConcatStrIterator */
NARY_ITER (ConcatStrIterator);
/*end class ConcatStrIterator */


/*
 * 7.4.2 fn:string-join
 * --------------------*/
/*begin class StringJoinIterator*/
NARY_ITER (StringJoinIterator);
/*end class StringJoinIterator*/

/*
 * 7.4.3 fn:substring
 * --------------------*/
/*begin class SubstringIterator*/
NARY_ITER (SubstringIterator);
/*end class SubstringIterator*/

/*
 * 7.4.4 fn:string-length
 * --------------------*/
/*begin class StringLengthIterator*/
NARY_ITER (StringLengthIterator);
/*end class StringLengthIterator*/

/*
 * 7.4.5 fn:normalize-space
 * --------------------*/
/*begin class NormalizeSpaceIterator*/
NARY_ITER (NormalizeSpaceIterator);
/*end class NormalizeSpaceIterator*/

/*
 * 7.4.6 fn:normalize-unicode
 * --------------------*/
/*begin class NormalizeUnicodeIterator*/
NARY_ITER (NormalizeUnicodeIterator);
/*end class NormalizeUnicodeIterator*/

/*
 * 7.4.7 fn:upper-case
 * --------------------*/
/*begin class UpperCaseIterator*/
NARY_ITER (UpperCaseIterator);
/*end class UpperCaseIterator*/

/*
 * 7.4.8 fn:lower-case
 * --------------------*/
/*begin class LowerCaseIterator*/
NARY_ITER (LowerCaseIterator);
/*end class LowerCaseIterator*/

 /*
 * 7.4.9 fn:translate
 * -------------------- */
/*begin class TranslateIterator*/
NARY_ITER (TranslateIterator);
/*end class TranslateIterator*/

 /*
 * 7.4.10 fn:encode-for-uri
 * -------------------- */
/*begin class EncodeForUriIterator*/
NARY_ITER (EncodeForUriIterator);
/*end class EncodeForUriIterator*/

 /*
 * 7.4.11 fn:iri-to-uri
 * -------------------- */
/*begin class IriToUriIterator*/
NARY_ITER (IriToUriIterator);
/*end class IriToUriIterator*/

 /*
 * 7.4.12 fn:escape-html-uri
 * -------------------- */
/*begin class EscapeHtmlUriIterator*/
NARY_ITER (EscapeHtmlUriIterator);
/*end class EscapeHtmlUriIterator*/

/*______________________________________________________________________
 *
 * 7.5 Functions Based on Substring Matching
 *_______________________________________________________________________*/

 /*
 * 7.5.1 fn:contains
 * -------------------- */
/*begin class ContainsIterator*/
NARY_ITER (ContainsIterator);
/*end class ContainsIterator*/

 /*
 * 7.5.2 fn:starts-with
 * -------------------- */
/*begin class StartsWithIterator*/
NARY_ITER (StartsWithIterator);
/*end class StartsWithIterator*/

 /*
 * 7.5.3 fn:ends-with
 * -------------------- */
/*begin class EndsWithIterator*/
NARY_ITER (EndsWithIterator);
/*end class EndsWithIterator*/

 /*
 * 7.5.4 fn:substring-before
 * -------------------- */
/*begin class SubstringBeforeIterator*/
NARY_ITER (SubstringBeforeIterator);
/*end class SubstringBeforeIterator*/

 /*
 * 7.5.5 fn:substring-after
 * -------------------- */
/*begin class SubstringAfterIterator*/
NARY_ITER (SubstringAfterIterator);
/*end class SubstringAfterIterator*/

// 7.6.2 fn:matches
NARY_ITER(FnMatchesIterator);

// 7.6.3 fn:replace
NARY_ITER(FnReplaceIterator);

// 7.6.4 fn:tokenize
class FnTokenizeIteratorState : public PlanIteratorState {
  public:
    xqp_string  theString; // the remaining string
    xqp_int     start_pos;
    xqp_boolean hasmatched;
    xqp_string  thePattern, theFlags;

    void init(PlanState&);
    void reset(PlanState&);
};

NARY_ITER_STATE(FnTokenizeIterator, FnTokenizeIteratorState);

}/*namespace zorba*/
#endif /* ZORBA_STRINGS_IMPL_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
