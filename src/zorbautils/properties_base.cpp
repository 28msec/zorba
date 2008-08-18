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

#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cassert>

#include <zorba/properties_base.h>

using namespace std;

namespace zorba {

  template<> void PropertiesBase::init_val (const char *str, string &val, unsigned delta) { val = str + delta; }
  template<> void PropertiesBase::init_val (const char *str, vector<string> &val, unsigned delta) {
    val.push_back (str + delta);
  }

  string PropertiesBase::load_file (const char *fname) {
    ifstream is (fname);
    vector<pair <const char *, const char *> > arg_vec;
    string line;
    unsigned nargs = 1;
    while (getline (is, line)) {
      if (line.size () == 0 || line [0] == '#')
        continue;
      ++nargs;
      char *str = new char [line.size () + 3];
      str [0] = str [1] = '-';
      memcpy (str + 2, line.data (), line.size ());
      str [line.size () + 2] = '\0';
      char *p = strchr (str, '=');
      if (p != NULL) {
        ++nargs;
        *p = '\0';
      }
      arg_vec.push_back (pair<const char *, const char *> (str, p));
    }
    if (nargs == 1)
      return "";
    else {
      const char **argv = new const char * [nargs + 1];
      unsigned i, j;
      for (i = 0, j = 1; i < arg_vec.size (); ++i) {
        argv [j++] = arg_vec [i].first;
        if (arg_vec [i].second != NULL)
          argv [j++] = arg_vec [i].second;
      }
      assert (j == nargs);
      argv [nargs] = NULL;
      string res = load_argv (nargs, argv);
      delete [] argv;
      for (i = 0; i < arg_vec.size (); ++i)
        delete [] arg_vec [i].first;
      return res;
    }
  }

  string PropertiesBase::load_env (const string &env_pfx, const char **options) {
    string opt;
    vector<const char *> arg_vec;

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
    if (nargs == 1)
      return "";
    else {
      const char **argv = new const char * [nargs + 1];
      for (int i = 0; i < nargs; i++)
        argv [i] = arg_vec [i];
      argv [nargs] = NULL;
      arg_vec.clear ();
      string res = load_argv (nargs, argv);
      delete [] argv;
      return res;
    }
  }

}
