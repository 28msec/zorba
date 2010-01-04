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
#ifndef ZORBAC_EXTERNAL_MODULE_CAPI_H
#define ZORBAC_EXTERNAL_MODULE_CAPI_H

#include <map>
#include <zorba/zorba.h>
#include <zorba/external_module.h>
#include <zorba/zorbac.h>

namespace zorbac {

  class CExternalFunction;

  class ExternalModuleWrapper : public zorba::ExternalModule {
    public:
      ExternalModuleWrapper(const char* uri);

      virtual ~ExternalModuleWrapper();

      virtual zorba::String
      getURI() const;

      virtual zorba::StatelessExternalFunction*
      getExternalFunction(zorba::String aLocalname) const;

      virtual XQC_Error
      registerFunction(CExternalFunction*);

    protected:
      zorba::String                                   theURI;
      typedef std::map<std::string,
                       zorba::StatelessExternalFunction*> FunctionMap_t;
      mutable FunctionMap_t  theFunctionMap;
  };

} /* namespace zorbac */
#endif
