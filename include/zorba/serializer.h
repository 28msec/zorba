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
#ifndef ZORBA_SERIALIZER_API_H
#define ZORBA_SERIALIZER_API_H

#include <zorba/options.h>
#include <zorba/config.h>
#include <zorba/api_shared_types.h>
#include <zorba/item.h>

namespace zorba {

  class ZORBA_DLL_PUBLIC Serializer : public SmartObject
  {
    public:

      virtual ~Serializer() {}

      virtual void
      serialize(
        ItemSequence  *object,
        std::ostream& stream) const = 0;

      virtual int
      getSerializationMethod() const = 0;

      static Serializer_t
      createSerializer(const Zorba_SerializerOptions_t& options);

      static Serializer_t
      createSerializer(ItemSequence* options);

  };

} /* namespace zorba */

#endif
/* vim:set et sw=2 ts=2: */
