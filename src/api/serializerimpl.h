/*
 * Copyright 2006-2009 The FLWOR Foundation.
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
#ifndef ZORBA_SERIALIZER_IMPL_H
#define ZORBA_SERIALIZER_IMPL_H

#include <zorba/serializer.h>

#include "zorbaerrors/error_manager.h"

#include "api/serialization/serializer.h"

#include "store/api/shared_types.h"

namespace zorba {

  class Serializable;

  class SerializerImpl : public Serializer
  {
    private:
      error::ErrorManager theErrorManager;
      mutable serializer theInternalSerializer;

    public:

      SerializerImpl(const Zorba_SerializerOptions_t& options);

      virtual ~SerializerImpl() {}

      virtual void
      serialize(
        Serializable* object,
        std::ostream& stream) const;

      static void
      setSerializationParameters(
        serializer&                       serializer,
        const Zorba_SerializerOptions_t&  options);

  };

} /* namespace zorba */

#endif
