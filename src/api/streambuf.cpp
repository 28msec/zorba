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

#include "stdafx.h"
#include <zorba/internal/streambuf.h>

using namespace std;

namespace zorba {
namespace internal {

///////////////////////////////////////////////////////////////////////////////

// "delete" is done here inside Zorba rather than in the header to guarantee
// that it's cross-DLL-boundary safe on Windows.

void dealloc_streambuf( streambuf *buf ) {
  delete buf;
}

void stream_callback( ios_base::event e, ios_base &ios, int index ) {
  //
  // See: "Standard C++ IOStreams and Locales: Advanced Programmer's Guide and
  // Reference," Angelika Langer and Klaus Kreft, Addison-Wesley, 2000, section
  // 3.3.1.4: "Using Stream Callbacks for Memory Management."
  //
  if ( e == ios_base::erase_event )
    delete static_cast<streambuf*>( ios.pword( index ) );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace internal
} // namespace zorba
/* vim:set et sw=2 ts=2: */
