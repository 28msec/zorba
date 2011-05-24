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
#include <zorba/iterator.h>
#include <zorba/user_exception.h>
#include <zorba/xquery_functions.h>

#include "email_function.h"

#include "email_module.h"

namespace zorba
{
  namespace emailmodule
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
    SMTPFunction::getHostUserPassword(const StatelessExternalFunction::Arguments_t& aArgs,
                                      int aPos,
                                      std::string& aHost,
                                      std::string& aUserName,
                                      std::string& aPassword) const {
      Item lNode;
      Iterator_t args_iter = aArgs[aPos]->getIterator();
      args_iter->open();
      args_iter->next(lNode);
      args_iter->close();
      Iterator_t lChildren = lNode.getChildren();
      lChildren->open();
      Item lChild;
      lChildren->next(lChild);
      aHost = lChild.getStringValue().c_str();
      lChildren->next(lChild);
      aUserName = lChild.getStringValue().c_str();
      lChildren->next(lChild);
      aPassword = lChild.getStringValue().c_str();
      lChildren->close();  
    }

    void
    SMTPFunction::getNameAndEmailAddress(Item& aEmailItem,
                                         std::string& aName,
                                         std::string& aMailbox,
                                         std::string& aHost) {

        Iterator_t lChildren = aEmailItem.getChildren();
        lChildren->open();
        Item lChild;
        lChildren->next(lChild);
  
        // as a name is not mandatory, we first check if this is a name node
        Item lNodeName;
        lChild.getNodeName(lNodeName);
        if (fn::ends_with(lNodeName.getStringValue(),"e")) {
          aName = lChild.getStringValue().c_str();
          lChildren->next(lChild);
        } else {
          aName = "";
        }  
        String lEmail = lChild.getStringValue();
        int lIndexOfAt = lEmail.find('@'); 
        aMailbox = lEmail.substr(0, lIndexOfAt).c_str(); 
        aHost = lEmail.substr(lIndexOfAt+1, lEmail.length()-lIndexOfAt-1).c_str();
    }
  } // namespace email
} // namespace zorba
