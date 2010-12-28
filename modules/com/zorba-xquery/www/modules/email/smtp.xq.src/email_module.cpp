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

#include "email_module.h"

#include "smtp.h"
#include "email_function.h"

namespace zorba {

  namespace emailmodule {

    ItemFactory* SMTPModule::theFactory = 0;

    SMTPModule::~SMTPModule()
    {
      for (FuncMap_t::const_iterator lIter = theFunctions.begin();
          lIter != theFunctions.end(); ++lIter)
      {
        delete lIter->second;
      }

      theFunctions.clear();
    }

    StatelessExternalFunction*
    SMTPModule::getExternalFunction(const String& aLocalname)
    {
      StatelessExternalFunction*& lFunc = theFunctions[aLocalname];
      if (!lFunc)
      {
        if (aLocalname.equals("send-impl"))
        {
          lFunc = new SendFunction(this);
        }
      }
      return lFunc;
    }

    void
    SMTPModule::destroy()
    {
      if (!dynamic_cast<SMTPModule*>(this))
      {
        return;
      }
      delete this;
    }

    bool
    SMTPModule::getOption(const StaticContext* aSctxCtx,
                          String aOptionName,
                          String& aOptionValue) const
    {
      return aSctxCtx->getOption(getItemFactory()->
          createQName(getURI(),aOptionName),aOptionValue);
    }

  } // namespace email
} // namespace zorba
