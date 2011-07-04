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

#ifndef ZORBA_WARNING_LIST_API_H
#define ZORBA_WARNING_LIST_API_H

#include <zorba/config.h>
#include <zorba/xquery_warning.h>

namespace zorba {
namespace zwarn {

#define ZORBA_DEC_WARNING(WARN) extern ZORBA_DLL_PUBLIC ZorbaWarningCode WARN

///////////////////////////////////////////////////////////////////////////////

/**
 * An XQuery variable was declared but never used.
 */
ZORBA_DEC_WARNING( ZWST0001_UNUSED_VARIABLE );

/**
 * An annotation is unknown or unsupported
 */
ZORBA_DEC_WARNING( ZWST0002_UNKNOWN_ANNOTATION );

///////////////////////////////////////////////////////////////////////////////

#undef ZORBA_DEC_WARNING

} // namespace zwarn
} // namespace zorba
#endif /* ZORBA_WARNING_LIST_API_H */
/* vim:set et sw=2 ts=2: */
