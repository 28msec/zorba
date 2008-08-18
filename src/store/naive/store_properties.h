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
// THIS IS A GENERATED FILE. DO NOT EDIT!
#include <string>
#include <sstream>
#include <zorba/properties_base.h>

#ifndef ZORBA_STORE_STOREPROPERTIES
#define ZORBA_STORE_STOREPROPERTIES
namespace zorba { namespace store { 
class StoreProperties : public ::zorba::PropertiesBase {
protected:
  const char **get_all_options () const {
    static const char *result [] = { "--build-dataguide", "--store-trace-level", NULL };
    return result;
  }
  bool theBuildDataguide;
  long theStoreTraceLevel;

  void initialize () {
    theBuildDataguide = false;
    theStoreTraceLevel = 0;
  }
public:
  bool buildDataguide () const { return theBuildDataguide; }
  long storeTraceLevel () const { return theStoreTraceLevel; }

  std::string load_argv (int argc, const char **argv) {
    if (argv == NULL) return "";

    std::string result;
    for (++argv; *argv != NULL; ++argv) {
      if (strcmp (*argv, "--help") == 0 || strcmp (*argv, "-h") == 0)
        return "!HELP";
      else if (strcmp (*argv, "--version") == 0)
        return "!VER";
      else if (strcmp (*argv, "--build-dataguide") == 0) {
        theBuildDataguide = true;
      }
      else if (strcmp (*argv, "--store-trace-level") == 0) {
        int d = 2;
        if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
        init_val (*argv, theStoreTraceLevel, d);
      }
      else if (strcmp (*argv, "--") == 0) {
        copy_args (++argv);
        break;
      } else if ((*argv) [0] == '-') {
        result = "unknown command line option "; result += *argv; break; 
      } else {
        copy_args (argv);
        break;
      }
    }

    return result;
  }

  const char *get_help_msg () {
    return
"--build-dataguide\n  build-dataguide (true/false)\n\n"
"--store-trace-level\n  store trace level (<= 0 : no tracing)\n\n"
;
  }

  static const StoreProperties *instance () {
    static StoreProperties result;
    return &result;
  }

  StoreProperties () { initialize (); }
  
};

} }   // namespaces

#endif // ZORBA_STORE_STOREPROPERTIES
