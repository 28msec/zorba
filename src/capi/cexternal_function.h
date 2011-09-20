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
#ifndef ZORBAC_CEXTERNAL_FUNCTION_H
#define ZORBAC_CEXTERNAL_FUNCTION_H

#include <zorba/zorba.h>
#include <zorba/function.h>
#include <zorba/zorbac.h>

using namespace zorba;

namespace zorbac {

  class CExternalFunction : public NonContextualExternalFunction {
    public:
      CExternalFunction(const char* uri, const char* localname,
        external_function_init init_fn, external_function_next next_fn,
        external_function_free free_fn, void* function_user_data,
        ItemFactory* factory, XQC_ErrorHandler* handler);

      virtual ~CExternalFunction();

      virtual zorba::String
      getURI() const;

      virtual zorba::String
      getLocalName() const;

      ItemSequence_t
      evaluate(const ExternalFunction::Arguments_t& args) const;

    private:

      friend class UserItemSequence;

      zorba::String theURI;
      zorba::String theLocalName;
      external_function_init    theInitFunction;
      external_function_next    theNextFunction;
      external_function_free    theFreeFunction;
      void* theFunctionUserData;
      ItemFactory*  theFactory;
      XQC_ErrorHandler* theErrorHandler;
                              
  }; /* class CExternalFunction */

} /* namespace zorbac */

#endif
/* vim:set et sw=2 ts=2: */
