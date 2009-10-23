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
#ifndef ZORBA_PATH_H
#define ZORBA_PATH_H

#include <string>
#include <iostream>
#include <zorba/config.h>

namespace zorba {

  class ZORBA_DLL_PUBLIC filesystem_path {

    private:
      std::string path;

      void
      canonicalize ();

    protected:
      std::string
      getPathString() const;

    public:
      typedef enum { CONVERT_SLASHES  = 1 << 0, 
                     RESOLVE = 1 << 1
      } flags_t;

    public:
      // from current dir
      filesystem_path ();

      filesystem_path (const std::string &path_, int flags = 0);

      filesystem_path (const filesystem_path &base, const filesystem_path &rel) {
        if (rel.is_complete ())
          *this = rel;
        else {
          *this = base.get_path () + get_path_separator () + rel.get_path ();
          canonicalize ();
        }
      }

      filesystem_path &operator = (const std::string &p_)
      { path = p_; canonicalize (); return *this; }

      const std::string &get_path () const { return path; }
      const char *c_str () const { return path.c_str (); }
      operator const std::string & () const { return path; }

      bool is_complete () const;
      bool is_root () const;
      void resolve_relative ();

      filesystem_path branch_path () const;

      static const char *get_path_separator ();
  };

  inline std::ostream &operator<< (std::ostream &os, const filesystem_path &p)
  { os << p.get_path (); return os; }

  }

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
