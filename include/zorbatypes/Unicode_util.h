/**
 * @copyright
 * ========================================================================
 *  Copyright FLWOR Foundation
 * ========================================================================
 *
 * @author Sorin Nasoi (sorin.nasoi@ipdevel.ro)
 * @file utf8/Unicode_util.h
 */
 
#ifndef UNICODE_UTIL_H
#define UNICODE_UTIL_H

#include <iostream>
#include <sstream>

#include <zorba/common/common.h>

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

 template <class T> std::string to_string (T x) {
   std::ostringstream o;
   o << x;
   return o.str ();
 }

}/* namespace zorba */
#endif /* UNICODE_UTIL_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
