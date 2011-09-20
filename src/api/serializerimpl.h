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
#pragma once
#ifndef ZORBA_SERIALIZER_IMPL_H
#define ZORBA_SERIALIZER_IMPL_H

#include <zorba/serializer.h>

#include "diagnostics/xquery_diagnostics.h"

#include "api/serialization/serializer.h"

#include "store/api/shared_types.h"

namespace zorba {

  class Serializable;
  class DiagnosticHandler;

  class SerializerImpl : public Serializer
  {
    private:
      XQueryDiagnostics theXQueryDiagnostics;
      DiagnosticHandler* theDiagnosticHandler;
      bool                own_error_handler;
      mutable serializer theInternalSerializer;

    public:

      SerializerImpl(const Zorba_SerializerOptions_t& aOptions, DiagnosticHandler* aDiagnosticHandler = 0);

      SerializerImpl(ItemSequence* options, DiagnosticHandler* aDiagnosticHandler = 0);

      virtual ~SerializerImpl();

      virtual void
      serialize(
        ItemSequence* object,
        std::ostream& stream) const;

      virtual int
      getSerializationMethod() const;

      static void
      setSerializationParameters(
        serializer&                       serializer,
        const Zorba_SerializerOptions_t&  options);

      static void
      setSerializationParameters(
        serializer&   serializer,
        ItemSequence* options);

  };

} /* namespace zorba */

#endif
/* vim:set et sw=2 ts=2: */
