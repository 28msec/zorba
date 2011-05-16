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

#ifndef ZORBA_EMAILMODULE_EMAILFUNCTION_H
#define ZORBA_EMAILMODULE_EMAILFUNCTION_H

#include <zorba/external_function.h>

namespace zorba
{
  namespace emailmodule
  {
    class SMTPModule;

    class SMTPFunction : public NonePureStatelessExternalFunction
    {
      protected:
        const SMTPModule*     theModule;

      public:
        SMTPFunction(const SMTPModule* aModule);

        ~SMTPFunction();

        virtual String
        getURI() const;

        
        virtual void 
        getHostUserPassword(const StatelessExternalFunction::Arguments_t& aArgs,
                            int aPos,
                            std::string& aHost,
                            std::string& aUserName,
                            std::string& aPassword) const; 

       static void
       getNameAndEmailAddress(Item& aEmailItem,
                               std::string& aName,
                               std::string& aMailbox,
                               std::string& aHost);


    }; //class SMTPFunction
  } // namespace email
} // namespace zorba

#endif // ZORBA_EMAILMODULE_EMAILFUNCTION_H
