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
#pragma once
#ifndef ZORBA_DYNAMIC_LOADER_H
#define ZORBA_DYNAMIC_LOADER_H

#include "common/common.h"
#include <map>
#include "common/shared_types.h"

namespace zorba {

class ExternalModule;
class URI;

class DynamicLoader
{
public:
  ExternalModule* getExternalModule(
      zstring const& aNsURI,
      static_context& aSctx);

private:

  friend class GlobalEnvironment;
  DynamicLoader();

  ~DynamicLoader();


#ifdef WIN32
  typedef HMODULE handle_t;
#else
  typedef void *  handle_t;
#endif

  ExternalModule* loadModule(const zstring& aFile) const;
  ExternalModule* createModule(handle_t handle, const zstring& aFile) const;


  typedef std::map<const zstring, handle_t> LibraryMap_t;

  mutable LibraryMap_t theLibraries;
};

} /* namespace zorba */

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
