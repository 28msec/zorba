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
#include "stdafx.h"

#include "dynamic_loader.h"
#include "static_context.h"
#include <zorbamisc/ns_consts.h>
#include <system/globalenv.h>
#include <store/api/item_factory.h>

#ifdef UNIX
#  include <dlfcn.h>
#endif

#ifdef WIN32
#  include <strsafe.h>
#endif

#include <diagnostics/xquery_diagnostics.h>
#include <zorbatypes/URI.h>
#include <zorba/external_module.h>
#include <zorba/zorba_string.h>
#include <context/get_current_lib_suffix.h>
#include <fstream>
#include <util/error_util.h>

namespace zorba {

static std::string computeVersionInfix(zstring const& aImportedVersion)
{
  if (aImportedVersion == "") {
    return "";
  }
  std::ostringstream lInfix;
  lInfix << "_" << aImportedVersion;
  return lInfix.str();
}


static zstring computeLibraryName(
    const URI& aURI,
    const zstring& aImportedVersion, 
    bool aUseDebugDir = false)
{
  zstring lPathNotation = aURI.toPathNotation();

  // get the module file name
  size_t lIndexOfLastSlash = lPathNotation.find_last_of("/");

  zstring lFileName;
  zstring lBranchPath;

  // if the URI ends in '/'
  if (lIndexOfLastSlash == lPathNotation.size())
  {
    lBranchPath = lPathNotation;
  }
  else
  {
    // if '/' is not found
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
      lFileName.erase(lIndexOfXQ);
    }
  }

  // create the name of the file
  // win32: module.dll
  // apple: libmodule.dylib
  // other unix: libmodule.so
  // If version number is not blank, insert it into the path before the extension
  std::ostringstream lLibraryName;
  lLibraryName << lBranchPath;

#ifdef WIN32
  if (aUseDebugDir) 
  {
#ifndef NDEBUG
    lLibraryName << "Debug\\";
#else
    lLibraryName << "Release\\";
#endif
  }
  lLibraryName << lFileName << get_current_lib_suffix()
               << computeVersionInfix(aImportedVersion) << ".dll";

#else // !WIN32

  if (aUseDebugDir) 
  {
    lLibraryName << "Debug/";
  }
#ifdef APPLE
  lLibraryName << "lib" << lFileName << get_current_lib_suffix()
               << computeVersionInfix(aImportedVersion) << ".dylib";
#else
  lLibraryName << "lib" << lFileName << get_current_lib_suffix()
               << computeVersionInfix(aImportedVersion) << ".so";
#endif
#endif

  return lLibraryName.str();
}


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
      zerr::ZOSE0005_DLL_LOAD_FAILED,
      ERROR_PARAMS( aFile, os_error::get_err_string() )
    );

  createModule = (ExternalModule* (*)())GetProcAddress(handle, "createModule");
  if (createModule == NULL)
    throw ZORBA_EXCEPTION(
      zerr::ZAPI0015_CREATEMODULE_NOT_FOUND,
      ERROR_PARAMS( aFile, os_error::get_err_string() )
    );

#else
  void* handle = dlopen(aFile.c_str(), RTLD_NOW);
  if (!handle)
    throw ZORBA_EXCEPTION(
      zerr::ZOSE0005_DLL_LOAD_FAILED, ERROR_PARAMS( aFile, zstring(dlerror()) )
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
{
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
DynamicLoader::getExternalModule(zstring const& aNsURI, static_context& aSctx)
{
  std::vector<zstring> lLibPath;
  aSctx.get_full_lib_path(lLibPath);

  std::auto_ptr<std::istream> modfile(0); // result file

  if (lLibPath.size() != 0)
  {
    URI lURI(aNsURI);

    // Lookup version of the module
    store::Item_t lMajorOpt;
    GENV.getItemFactory()->createQName(lMajorOpt,
                                       zstring(ZORBA_VERSIONING_NS),
                                       zstring(""),
                                       zstring(ZORBA_OPTION_MODULE_VERSION));
    
    zstring lImportedVersion;
    
    if (!aSctx.lookup_option(lMajorOpt.getp(), lImportedVersion)) 
    {
      lImportedVersion = "";
    }

    zstring lLibraryName = computeLibraryName(lURI, lImportedVersion);

    zstring lLibraryNameDebug = computeLibraryName(lURI, lImportedVersion, true);

    // Check all module path in the according order.
    for (std::vector<zstring>::const_iterator ite = lLibPath.begin();
         ite != lLibPath.end();
         ++ite)
    {
      zstring potentialModuleFile = (*ite);
      zstring potentialModuleFileDebug = potentialModuleFile;

      potentialModuleFile.append(lLibraryName);
      potentialModuleFileDebug.append(lLibraryNameDebug);

      std::auto_ptr<std::istream> modfile
        (new std::ifstream(potentialModuleFile.c_str()));

      if (!modfile->good()) 
      {
        modfile.reset(new std::ifstream(potentialModuleFileDebug.c_str()));
        potentialModuleFile = potentialModuleFileDebug;
      }

      if (modfile->good())
      {
        ExternalModule* lModule = loadModule(potentialModuleFile);
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

} // namespace zorba
/* vim:set et sw=2 ts=2: */
