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
#ifndef ZORBA_UNICODE_CATEGORIES
#define ZORBA_UNICODE_CATEGORIES

#include "util/unicode_util.h"

namespace zorba {
namespace unicode {

//Unicode codepoint categories, as from http://www.fileformat.info/info/unicode/category/index.htm

enum UnicodeCategoriesEnum {
UNICODE_Cc, //Other, Control
UNICODE_Cf, //Other, Format
UNICODE_Co, //Other, Private Use
UNICODE_Cs, //Other, Surrogate
UNICODE_Ll, //Letter, Lowercase
UNICODE_Lm, //Letter, Modifier
UNICODE_Lo, //Letter, Other
UNICODE_Lt, //Letter, Titlecase
UNICODE_Lu, //Letter, Uppercase
UNICODE_Mc, //Mark, Spacing Combining
UNICODE_Me, //Mark, Enclosing
UNICODE_Mn, //Mark, Nonspacing
UNICODE_Nd, //Number, Decimal Digit
UNICODE_Nl, //Number, Letter
UNICODE_No, //Number, Other
UNICODE_Pc, //Punctuation, Connector
UNICODE_Pd, //Punctuation, Dash
UNICODE_Pe, //Punctuation, Close
UNICODE_Pf, //Punctuation, Final quote (may behave like Ps or Pe depending on usage)
UNICODE_Pi, //Punctuation, Initial quote (may behave like Ps or Pe depending on usage)
UNICODE_Po, //Punctuation, Other
UNICODE_Ps, //Punctuation, Open
UNICODE_Sc, //Symbol, Currency
UNICODE_Sk, //Symbol, Modifier
UNICODE_Sm, //Symbol, Math
UNICODE_So, //Symbol, Other
UNICODE_Zl, //Separator, Line
UNICODE_Zp, //Separator, Paragraph
UNICODE_Zs  //Separator, Space
};

bool is_UnicodeNd(code_point cp, code_point *ret_zero);

bool check_codepoint_category(code_point cp, UnicodeCategoriesEnum categ);

}
}

#endif
/* vim:set et sw=2 ts=2: */
