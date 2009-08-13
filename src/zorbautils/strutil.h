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
#ifndef ZORBA_STRUTIL_H
#define ZORBA_STRUTIL_H

#include <string>
#include <sstream>

#include <zorba/config.h>

namespace zorba {

  template <class T>  std::string to_string (T x) {
    std::ostringstream o;
    o << x;
    return o.str ();
  }

   inline void str_replace_all (std::string &str, const std::string &pat, const std::string &repl) {
    std::string::size_type
      patlen = pat.size (), rlen = repl.size ();
    for (std::string::size_type pos = 0;
         (pos + patlen) < str.size () && std::string::npos != (pos = str.find (pat, pos));
         pos += rlen)
    {
      str.replace (pos, patlen, repl);
    }
  }

}

#endif
