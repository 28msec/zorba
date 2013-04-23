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
#ifndef ZORBA_MODULE_INFO_H
#define ZORBA_MODULE_INFO_H

#include <zorba/config.h>
#include <zorba/api_shared_types.h>

namespace zorba {

  /** \brief Information about a main or library module.
   *
   */
  class ZORBA_DLL_PUBLIC ModuleInfo : public SmartObject
  {
    public:
      virtual ~ModuleInfo() {}

      /**
       * Return the target namespace of the module.
       *
       * @return the target namespace or the empty
       *   string if the module is a main module.
       */
      virtual zorba::String
      getTargetNamespace() const = 0;

      /**
       * @return true if the module is a library module,
       *   false otherwise.
       */
      virtual bool
      isLibraryModule() const = 0;

  }; /* class ModuleInfo */

} // namespace zorba
#endif /* ZORBA_MODULE_INFO_H */
/* vim:set et sw=2 ts=2: */
