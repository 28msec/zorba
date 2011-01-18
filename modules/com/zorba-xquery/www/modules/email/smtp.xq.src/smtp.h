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

#ifndef ZORBA_EMAIL_SMTP_H
#define ZORBA_EMAIL_SMTP_H

#include "email_function.h"

namespace zorba
{
  namespace emailmodule
  {
    class SendFunction : public SMTPFunction
    {
    public:
      SendFunction(const SMTPModule* aModule);

      virtual String
      getLocalName() const { return "send-impl"; }

      virtual ItemSequence_t
      evaluate( const StatelessExternalFunction::Arguments_t& args,
                const StaticContext* aSctxCtx,
                const DynamicContext* aDynCtx) const;
    };
  } // namespace email
} // namespace zorba

#endif // ZORBA_EMAIL_SMTP_H
