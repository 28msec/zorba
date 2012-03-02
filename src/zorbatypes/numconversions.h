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
#ifndef ZORBA_NUM_CONVERSIONS_H
#define ZORBA_NUM_CONVERSIONS_H

#include "schema_types.h"

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

/**
 * Converts an \c xs:double value to an \c xs:int.
 *
 * @param d The \c xs:double value to convert.
 * @return Returns said value.
 * @throws std::range_error if the \c xs:double value can not be accurately
 * represented as an \c xs:int.
 */
xs_int to_xs_int( xs_double const &d );

/**
 * Converts an \c xs:integer value to an \c xs:int.
 *
 * @param i The \c xs:integer value to convert.
 * @return Returns said value.
 * @throws std::range_error if the \c xs:integer value can not be accurately
 * represented as an \c xs:int.
 */
xs_int to_xs_int( xs_integer const &i );

/**
 * Converts an \c xs:decimal value to an \c xs:long.
 *
 * @param d The \c xs:decimal value to convert.
 * @return Returns said value.
 * @throws std::range_error if the \c xs:decimal value can not be accurately
 * represented as an \c xs:long.
 */
xs_long to_xs_long( xs_decimal const &d );

/**
 * Converts an \c xs:integer value to an \c xs:long.
 *
 * @param i The \c xs:integer value to convert.
 * @return Returns said value.
 * @throws std::range_error if the \c xs:integer value can not be accurately
 * represented as an \c xs:long.
 */
xs_long to_xs_long( xs_integer const &i );

#ifndef ZORBA_WITH_BIG_INTEGER
xs_long to_xs_long( xs_nonNegativeInteger const &i );
#endif /* ZORBA_WITH_BIG_INTEGER */

/**
 * Converts an \c xs:integer value to an \c xs:unsignedInt.
 *
 * @param i The \c xs:integer value to convert.
 * @return Returns said value.
 * @throws std::range_error if the \c xs:integer value can not be accurately
 * represented as an \c xs:unsignedInt.
 */
xs_unsignedInt to_xs_unsignedInt( xs_integer const &i );

/**
 * Converts an \c xs:integer value to an \c xs:unsignedLong.
 *
 * @param i The \c xs:integer value to convert.
 * @return Returns said value.
 * @throws std::range_error if the \c xs:integer value can not be accurately
 * represented as an \c xs:unsignedLong.
 */
xs_unsignedLong to_xs_unsignedLong( xs_integer const &i );

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif /* ZORBA_NUM_CONVERSIONS_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
