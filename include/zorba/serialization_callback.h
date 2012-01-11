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
#ifndef ZORBA_SERIALIZATION_CALLBACK_H
#define ZORBA_SERIALIZATION_CALLBACK_H

#include <zorba/config.h>
#include <zorba/api_shared_types.h>
#include <ostream>

namespace zorba {

  class ZORBA_DLL_PUBLIC SerializationCallback {

    public:
      virtual ~SerializationCallback() {}

      virtual ExternalModule*
      getExternalModule(const String& aURI) const;

      virtual bool
      getTraceStream(std::ostream*&) const;

      /**
       * Get the i-th URIMapper that was registered before
       * serialization.
       */
      virtual URIMapper*
      getURIMapper(size_t i) const;

      /**
       * Get the i-th URLResolver that was registered before
       * serialization.
       */
      virtual URLResolver*
      getURLResolver(size_t i) const;
  };

} /* namespace zorba */

#endif
/* vim:set et sw=2 ts=2: */
