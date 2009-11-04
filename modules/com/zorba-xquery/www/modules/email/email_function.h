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

#ifndef ZORBA_EMAIL_EMAILFUNCTION_H
#define ZORBA_EMAIL_EMAILFUNCTION_H

#include <zorba/external_function.h>

namespace zorba
{
  namespace email
  {
    class EmailModule;

    class EmailFunction : public NonePureStatelessExternalFunction
    {
      protected:
        const EmailModule*     theModule;

        static void
        throwError( const std::string aErrorMessage,
                    const XQUERY_ERROR& aErrorType);

      public:
        EmailFunction(const EmailModule* aModule);

        ~EmailFunction();

        virtual String
        getURI() const;

    }; //class EmailFunction
  } // namespace email
} // namespace zorba

#endif // ZORBA_EMAIL_EMAILFUNCTION_H