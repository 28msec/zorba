#ifndef ZORBA_STRUTIL_H
#define ZORBA_STRUTIL_H

#include <string>
#include <sstream>

namespace zorba {

  template <class T> std::string to_string (T x) {
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
