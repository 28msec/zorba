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
#ifndef UNICODE_UTIL_H
#define UNICODE_UTIL_H

#include "common/common.h"

namespace zorba {

#define TABLE_SIZE(arr)   (sizeof (arr) / sizeof ((arr)[0]))
bool isUpper(uint32_t c);

bool isLower(uint32_t c);

/*
This is a simple case folding(where string lengths don't change) so only the mappings
with status C and S from the ftp://ftp.unicode.org/Public/5.1.0/ucd/CaseFolding-5.1.0d10.txt
are taken into account. The mappings with status T are ignored.
*/
uint32_t toUpper(uint32_t c);

/*
This is a simple case folding(where string lengths don't change) so only the mappings
with status C and S from the ftp://ftp.unicode.org/Public/5.1.0/ucd/CaseFolding-5.1.0d10.txt
are taken into account. The mappings with status T are ignored.
*/
uint32_t toLower(uint32_t c);

}/* namespace zorba */
#endif /* UNICODE_UTIL_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
