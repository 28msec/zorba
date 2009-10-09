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
#ifndef ZORBA_EXTERNAL_MODULE_H
#define ZORBA_EXTERNAL_MODULE_H

#include <zorba/config.h>
#include <zorba/external_function_data.h>

namespace zorba {

  class ZORBA_DLL_PUBLIC ExternalModule : public ExternalFunctionData
  {
    public:
      virtual ~ExternalModule() {}

      virtual String
      getURI() const = 0;

      virtual StatelessExternalFunction*
      getExternalFunction(String aLocalname) const = 0;

      /**
       * \brief Function used for destroying the ExternalModule object
       *        passed as parameter.
       *
       * The user needs to override this function if the module
       * passed as parameter was created using the createModule function
       * which is used for dynamically loading modules from a shared
       * library.
       */
      virtual void
      destroy() {}

  };

} /* namespace zorba */

#endif
