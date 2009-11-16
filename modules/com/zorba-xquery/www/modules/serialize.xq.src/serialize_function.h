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

#ifndef ZORBA_SERIALIZEMODULE_SERIALIZEFUNCTION_H
#define ZORBA_SERIALIZEMODULE_SERIALIZEFUNCTION_H

#include <zorba/external_function.h>

namespace zorba { namespace serializemodule {

  class SerializeModule;

  class SerializeFunction : public PureStatelessExternalFunction
  {
    protected:
      const SerializeModule* theModule;

      static void
      throwError(
          const std::string aErrorMessage,
          const XQUERY_ERROR& aErrorType);

      virtual const Zorba_SerializerOptions_t
      createSerializerOptions(const Item& aItem) const;

    private:

      virtual void
      throwInvalidSerializationOptionValue() const;

    public:
      SerializeFunction(const SerializeModule* aModule);
      ~SerializeFunction();

      virtual String
      getLocalName() const { return "serialize"; }
  
      virtual ItemSequence_t 
      evaluate(const StatelessExternalFunction::Arguments_t& args) const;

      virtual String
      getURI() const;

  };

} /* namespace serializemodule */ } /* namespace zorba */

#endif /* ZORBA_SERIALIZEMODULE_SERIALIZEFUNCTION_H */

