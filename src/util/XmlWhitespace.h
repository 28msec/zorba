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
#ifndef XMLWHITESPACE_H_
#define XMLWHITESPACE_H_

#include "zorbatypes/zstring.h"

namespace zorba
{

typedef enum {
    WS_PRESERVE,
    WS_REPLACE,
    WS_COLLAPSE,
    WS_UNSPECIFIED
} XmlWhitespace_t;

/*
 * doesn't change the string, returns the same str
 */ 
zstring xmlWhitespacePreserve(zstring str);

/*
 * replace each \n, \r and \t with one space char
 */ 
zstring xmlWhitespaceReplace(zstring str);

/*
 * same as xmlWhitespaceReplace(zstring str) plus
 * it collapses multiple consecutive spaces to a single one, 
 * and leading and trailing spaces are removed
 */ 
zstring xmlWhitespaceCollapse(zstring str);

/*
 * Performs the specified action (preserve / replace / collapse)
 */ 
zstring xmlWhitespaceCollapse(zstring str, XmlWhitespace_t wsct);

/*
 * checks if is XML whitespace char
 */ 
bool xmlWhitespaceChar(char c);

} // end zorba namespace
#endif /*XMLWHITESPACE_H_*/
