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
#ifndef ZORBAC_EXTERNAL_FUNCTION_CAPI_H
#define ZORBAC_EXTERNAL_FUNCTION_CAPI_H

#include <zorba/zorba.h>
#include <zorba/external_function.h>
#include <zorba/zorbac.h>

namespace zorbac {

  class ExternalFunctionWrapper : public zorba::StatelessExternalFunction {
    public:
      ExternalFunctionWrapper(const char* uri, 
                              const char* localname,
                              external_function_init init,
                              external_function_next next,
                              external_function_release release,
                              void* global_user_data);

      virtual zorba::String
      getURI() const;

      virtual zorba::String
      getLocalName() const;

      zorba::ItemSequence_t
      evaluate(const zorba::StatelessExternalFunction::Arguments_t& args) const;

    protected:
      zorba::String theURI;
      zorba::String theLocalName;
      external_function_init    theInitFunction;
      external_function_next    theNextFunction;
      external_function_release theReleaseFunction;
      void* theGlobalUserData;
      void* theUserData;
                              
  }; /* class ExternalFunctionWrapper */


} /* namespace zorbac */

#endif
