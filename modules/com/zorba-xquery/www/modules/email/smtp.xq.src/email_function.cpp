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

#include <zorba/zorba.h>

#include "email_function.h"

#include "email_module.h"

namespace zorba
{
  namespace email
  {
    SMTPFunction::SMTPFunction(const SMTPModule* aModule)
    : theModule(aModule)
    {
    }

    SMTPFunction::~SMTPFunction()
    {
    }

    String
    SMTPFunction::getURI() const
    {
      return theModule->getURI();
    }

    void
    SMTPFunction::throwError( const std::string aErrorMessage,
                              const XQUERY_ERROR& aErrorType)
    {
      throw zorba::ExternalFunctionData::createZorbaException(aErrorType,
          aErrorMessage.c_str(), __FILE__, __LINE__);
    }

  } // namespace email
} // namespace zorba
