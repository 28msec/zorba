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
#include "context/static_context.h"

#ifdef UNIX
#  include <dlfcn.h>
#endif

#ifdef WIN32
#  include <strsafe.h>
#endif

#include "zorbaerrors/error_manager.h"
#include "zorbatypes/URI.h"
#include "zorba/external_module.h"
#include "zorba/zorbastring.h"
#include "context/get_current_lib_suffix.h"
#include <fstream>
#include "util/error_util.h"

namespace zorba {

ExternalModule*
DynamicLoader::loadModule(const zstring& aFile) const
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
      zerr::ZOSE0001_FILE_NOT_FOUND,
      ERROR_PARAMS( aFile, error::get_os_err_string() )
    );

  createModule = (ExternalModule* (*)())GetProcAddress(handle, "createModule");
  if (createModule == NULL)
    throw ZORBA_EXCEPTION(
      zerr::ZAPI0015_CREATEMODULE_NOT_FOUND,
      ERROR_PARAMS( aFile, error::get_os_err_string() )
    );

#else
  void* handle = dlopen(aFile.c_str(), RTLD_NOW);
  if (!handle)
    throw ZORBA_EXCEPTION(
      zerr::ZOSE0001_FILE_NOT_FOUND, ERROR_PARAMS( aFile, dlerror() )
    );

  createModule = (ExternalModule* (*)()) dlsym(handle, "createModule");
  if (createModule == NULL)
  {
    dlclose(handle);
    throw ZORBA_EXCEPTION(
      zerr::ZAPI0015_CREATEMODULE_NOT_FOUND,
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


DynamicLoader::DynamicLoader()
{}

DynamicLoader&
DynamicLoader::getInstance()
{
  static DynamicLoader singleton;
  return singleton;
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

ExternalModule*
DynamicLoader::getExternalModule
(zstring const& aNsURI, static_context& aSctx)
{
  std::vector<zstring> lModulePaths;
  aSctx.get_full_module_paths(lModulePaths);

  std::auto_ptr<std::istream> modfile(0); // result file

  if (lModulePaths.size() != 0)
  {
    URI lURI(aNsURI);

    zstring lLibraryName = computeLibraryName(lURI);
    zstring lLibraryNameDebug = computeLibraryName(lURI, true);

    // check all module path in the according order
    // the higher in the hirarchy the static context is
    // the higher the priority of its module paths
    for (std::vector<zstring>::const_iterator ite = lModulePaths.begin();
        ite != lModulePaths.end();
         ++ite)
    {
      zstring potentialModuleFile = (*ite);
      zstring potentialModuleFileDebug = potentialModuleFile;
      potentialModuleFile.append(lLibraryName);
      potentialModuleFileDebug.append(lLibraryNameDebug);

      std::auto_ptr<std::istream> modfile
        (new std::ifstream(potentialModuleFile.c_str()));
      
      if (!modfile->good()) {
        modfile.reset(new std::ifstream(potentialModuleFileDebug.c_str()));
        potentialModuleFile = potentialModuleFileDebug;
      }

      if (modfile->good())
      {
        ExternalModule* lModule = getInstance().loadModule(potentialModuleFile);
        if (lModule)
        {
          if (lModule->getURI().c_str() != aNsURI)
          {
            throw ZORBA_EXCEPTION(
              zerr::ZXQP0028_TARGET_NAMESPACE_NOT_PROVIDED,
              ERROR_PARAMS( lURI, potentialModuleFile )
            );
          }
        }

        return lModule;
      }
    }
  }

  return NULL;
}

zstring
DynamicLoader::computeLibraryName
(const URI& aURI, bool aUseDebugDir /* = false */)
{
  zstring lPathNotation = aURI.toPathNotation();

  // get the module file name
  size_t lIndexOfLastSlash = lPathNotation.find_last_of("/");

  zstring lFileName;
  zstring lBranchPath;

  // is the URI ends in '/'
  if (lIndexOfLastSlash == lPathNotation.size())
  {
    lBranchPath = lPathNotation;
  }
  else
  {
    // is '/' is not found
    if (lIndexOfLastSlash == std::string::npos)
    {
      lFileName = lPathNotation;
    }
    else
    {
      lFileName = lPathNotation.substr(lIndexOfLastSlash + 1);
      lBranchPath = lPathNotation.substr(0, lIndexOfLastSlash + 1);
    }

    // remove .xq from the end of the file if present
    // bugfix: find_last_of didn't do the right thing
    size_t lIndexOfXQ = lFileName.find(".xq");
    if (lIndexOfXQ != std::string::npos && lIndexOfXQ == lFileName.size() - 3)
    {
      lFileName.erase(lIndexOfXQ );
    }
  }

  // create the name of the file
  // win32: module.dll
  // apple: libmodule.dylib
  // other unix: libmodule.so
  std::ostringstream lLibraryName;
  lLibraryName << lBranchPath;
#ifdef WIN32
  if (aUseDebugDir) {
    lLibraryName << "Debug\\";
  }
  lLibraryName << lFileName << get_current_lib_suffix() << ".dll";
#else
  if (aUseDebugDir) {
    lLibraryName << "Debug/";
  }
#ifdef APPLE
  lLibraryName << "lib" << lFileName << get_current_lib_suffix() << ".dylib";
#else
  lLibraryName << "lib" << lFileName << get_current_lib_suffix() << ".so";
#endif
#endif

  return lLibraryName.str();
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
