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

#include <zorba/external_module.h>

namespace zorba {
namespace util_curl {

///////////////////////////////////////////////////////////////////////////////

class module : public ExternalModule {
public:
  // inherited
  virtual void destroy();
  virtual ExternalFunction* getExternalFunction( String const& );
  virtual String getURI() const;
};

void module::destroy() {
  delete this;
}

ExternalFunction* module::getExternalFunction( String const& ) {
  return 0;
}

String module::getURI() const {
  return "http://zorba.io/modules/util-curl";
}

///////////////////////////////////////////////////////////////////////////////

} // namespace util_curl
} // namespace zorba

#ifdef WIN32
# define DLL_EXPORT __declspec(dllexport)
#else
# define DLL_EXPORT __attribute__ ((visibility("default")))
#endif

extern "C" DLL_EXPORT zorba::ExternalModule* createModule() {
  return new zorba::util_curl::module();
}

/* vim:set et sw=2 ts=2: */
