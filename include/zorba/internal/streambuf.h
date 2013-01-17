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

#ifndef ZORBA_INTERNAL_STREAMBUF_H
#define ZORBA_INTERNAL_STREAMBUF_H

#include <streambuf>

#include <zorba/config.h>
#include <zorba/internal/proxy.h>

namespace zorba {
namespace internal {

///////////////////////////////////////////////////////////////////////////////

typedef ztd::proxy<std::streambuf> proxy_streambuf;

ZORBA_DLL_PUBLIC
void dealloc_streambuf( std::streambuf* );

ZORBA_DLL_PUBLIC
void stream_callback( std::ios_base::event, std::ios_base&, int index );

///////////////////////////////////////////////////////////////////////////////

} // namespace internal
} // namespace zorba
#endif  /* ZORBA_INTERNAL_STREAMBUF_H */
/* vim:set et sw=2 ts=2: */
