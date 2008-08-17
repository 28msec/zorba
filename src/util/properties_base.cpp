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
#include "util/properties_base.h"

namespace zorba {

  template<> void PropertiesBase::init_val (const char *str, std::string &val, unsigned delta) { val = str + delta; }
  template<> void PropertiesBase::init_val (const char *str, std::vector<std::string> &val, unsigned delta) {
    val.push_back (str + delta);
  }

  std::string PropertiesBase::load_env (const std::string &env_pfx, const char **options) {
    std::string opt;
    std::vector<const char *> arg_vec;

    arg_vec.push_back ("cmd");
    for (; *options != NULL; ++options) {
      opt.clear (); opt += env_pfx; opt += *options + 2;
      for (unsigned i = 0; i < opt.size (); i++) {
        if (opt [i] == '-')
          opt [i] = '_';
        else if (islower (opt [i]))
          opt [i] += 'A' - 'a';
      }
      const char *val = getenv (opt.c_str ());
      if (val != NULL) {
        arg_vec.push_back (*options);
        arg_vec.push_back (val);
      }
    }

    int nargs = arg_vec.size ();
    if (nargs == 0)
      return "";
    else {
      const char **argv = new const char * [nargs + 1];
      for (int i = 0; i < nargs; i++)
        argv [i] = arg_vec [i];
      argv [nargs] = NULL;
      arg_vec.clear ();
      std::string res = load_argv (nargs, argv);
      delete [] argv;
      return res;
    }
  }

}
