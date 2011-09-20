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

#include <zorba/zorba.h>
#include <zorba/zorbac.h>
#include "capi/external_module.h"
#include "capi/cexternal_function.h"

using namespace zorba;

namespace zorbac {

  ExternalModuleWrapper::ExternalModuleWrapper(const char* aURI)
    : theURI(aURI) {}

  ExternalModuleWrapper::~ExternalModuleWrapper()
  {
    for (FunctionMap_t::iterator lIter = theFunctionMap.begin();
         lIter != theFunctionMap.end();
         ++lIter) {
      delete lIter->second;
    }
  }

  String
  ExternalModuleWrapper::getURI() const { return theURI; }

  ExternalFunction*
  ExternalModuleWrapper::getExternalFunction(const String& aLocalname)
  {
    FunctionMap_t::const_iterator lIter = theFunctionMap.find(aLocalname.c_str());

    if (lIter == theFunctionMap.end()) {
      return NULL;
    } else {
      return lIter->second;
    }
  }

  XQC_Error
  ExternalModuleWrapper::registerFunction(CExternalFunction* aFunc)
  {
    String lLocalName = aFunc->getLocalName();
    FunctionMap_t::iterator lIter = theFunctionMap.find(lLocalName.c_str());
    if (lIter != theFunctionMap.end()) {
      return XQC_INVALID_ARGUMENT; // was: ZAPI0019_MODULE_ALREADY_REGISTERED;
    }

    theFunctionMap[lLocalName.c_str()] = aFunc;
    return XQC_NO_ERROR;
  }

} /* namespace zorbac */

/* vim:set et sw=2 ts=2: */
