#ifndef ZORBA_STRUTIL_H
#define ZORBA_STRUTIL_H

#include <string>
#include <sstream>

#include <zorba/config.h>

namespace zorba {

  template <class T> ZORBAUTILS_EXTERNAL_DECL std::string to_string (T x) {
    std::ostringstream o;
    o << x;
    return o.str ();
  }

  ZORBAUTILS_EXTERNAL_DECL inline void str_replace_all (std::string &str, const std::string &pat, const std::string &repl) {
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
