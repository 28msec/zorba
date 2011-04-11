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
#include "context/dynamic_loader.h"

#ifdef UNIX
#  include <dlfcn.h>
#endif
#ifdef WIN32
#  include <strsafe.h>
#endif

#include "zorbaerrors/error_manager.h"
#include "util/error_util.h"

namespace zorba {

ExternalModule* DynamicLoader::getModule(const zstring& aFile) const
{
  // function pointer to create a module
  ExternalModule* (*createModule)() = NULL;

#ifdef WIN32
  WCHAR wpath_str[1024];
  wpath_str[0] = 0;
  if(MultiByteToWideChar(CP_UTF8,
                      0, aFile.c_str(), -1,
                      wpath_str, sizeof(wpath_str)/sizeof(WCHAR)) == 0)
  {//probably there is some invalid utf8 char, try the Windows ACP
    MultiByteToWideChar(CP_ACP,
                      0, aFile.c_str(), -1,
                      wpath_str, sizeof(wpath_str)/sizeof(WCHAR));
  }
  HMODULE handle = LoadLibraryW(wpath_str);
  if (!handle)
    throw ZORBA_EXCEPTION(
      ZOSE0001_FILE_NOT_FOUND, ERROR_PARAMS( aFile, error::get_os_err_string() )
    );

  createModule = (ExternalModule* (*)())GetProcAddress(handle, "createModule");
  if (createModule == NULL)
    throw ZORBA_EXCEPTION(
      ZAPI0015_CREATEMODULE_NOT_FOUND,
      ERROR_PARAMS( aFile, error::get_os_err_string() )
    );

#else
  void* handle = dlopen(aFile.c_str(), RTLD_NOW);
  if (!handle)
    throw ZORBA_EXCEPTION(
      ZOSE0001_FILE_NOT_FOUND, ERROR_PARAMS( aFile, dlerror() )
    );

  createModule = (ExternalModule* (*)()) dlsym(handle, "createModule");
  if (createModule == NULL)
  {
    dlclose(handle);
    throw ZORBA_EXCEPTION(
      ZAPI0015_CREATEMODULE_NOT_FOUND,
      ERROR_PARAMS( aFile, dlerror() )
    );
  }
#endif
  if (theLibraries.find(handle) == theLibraries.end())
  {
    theLibraries.insert(handle);
  }

  return createModule();
}


DynamicLoader::~DynamicLoader()
{
  for (LibrarySet_t::const_iterator lIter = theLibraries.begin();
       lIter != theLibraries.end(); ++lIter)
  {
#ifdef WIN32
    FreeLibrary(*lIter);
#else
    dlclose(*lIter);
#endif
  }
}


} // namespace zorba
/* vim:set et sw=2 ts=2: */
