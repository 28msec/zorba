/*
 * Copyright 2013 The FLWOR Foundation.
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
#ifndef ZORBA_MODULE_INFO_IMPL_H
#define ZORBA_MODULE_INFO_IMPL_H

#include <zorba/module_info.h>
#include <zorba/zorba_string.h>
#include "common/shared_types.h"

namespace zorba {

  /** 
   */
  class ZORBA_DLL_PUBLIC ModuleInfoImpl : public ModuleInfo
  {
    protected:
      String theTargetNamespace;

    public:
      ModuleInfoImpl(const zstring& aTargetNamespace);

      virtual zorba::String
      getTargetNamespace() const
      {
        return theTargetNamespace;
      }

      virtual bool
      isLibraryModule() const
      {
        return theTargetNamespace.length() > 0;
      }
  }; /* class ModuleInfoImpl */

} // namespace zorba
#endif /* ZORBA_MODULE_INFO_IMPL_H */
/* vim:set et sw=2 ts=2: */
