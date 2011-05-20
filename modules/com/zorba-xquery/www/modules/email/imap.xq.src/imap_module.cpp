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

#include "imap.h"
#include "imap_module.h"
#include "imap_function.h"

namespace zorba { namespace emailmodule {

  ItemFactory* ImapModule::theFactory = 0;


ImapModule::~ImapModule()
{
  for (FuncMap_t::const_iterator lIter = theFunctions.begin();
       lIter != theFunctions.end(); ++lIter) {
    delete lIter->second;
  }
  theFunctions.clear();
}
  
StatelessExternalFunction*
ImapModule::getExternalFunction(const String& aLocalname)
{
  StatelessExternalFunction*& lFunc = theFunctions[aLocalname];
  if (!lFunc) {
    if (1 == 0) {
    } else if (aLocalname == "status-impl") {
      lFunc = new StatusFunction(this);
    } else if (aLocalname == "create-impl") {
      lFunc = new CreateFunction(this);
    } else if (aLocalname == "delete-impl") {
      lFunc = new DeleteFunction(this);
    } else if (aLocalname == "rename-impl") {
      lFunc = new RenameFunction(this);
    } else if (aLocalname == "list-impl") {
      lFunc = new ListFunction(this);
    } else if (aLocalname == "subscribe-impl") {
      lFunc = new SubscribeFunction(this);
    } else if (aLocalname == "unsubscribe-impl") {
      lFunc = new UnsubscribeFunction(this);
    } else if (aLocalname == "expunge-impl") {
      lFunc = new ExpungeFunction(this);
    } else if (aLocalname == "search-impl") {
      lFunc = new SearchFunction(this);
    } else if (aLocalname == "copy-impl") {
      lFunc = new CopyFunction(this);
    } else if (aLocalname == "fetch-envelope-impl") {
      lFunc = new FetchEnvelopeFunction(this);
    } else if (aLocalname == "fetch-message-impl") {
      lFunc = new FetchMessageFunction(this);
    } else if (aLocalname == "fetch-subject-impl") {
      lFunc = new FetchSubjectFunction(this);
    } else if (aLocalname == "fetch-from-impl") {
      lFunc = new FetchFromFunction(this);
    } else if (aLocalname == "fetch-uid-impl") {
      lFunc = new FetchUidFunction(this);
    } else if (aLocalname == "fetch-message-sequence-number-impl") {
      lFunc = new FetchMessageSequenceNumberFunction(this);
    } else if (aLocalname == "fetch-flags-impl") {
      lFunc = new FetchFlagsFunction(this);
    } else if (aLocalname == "set-flags-impl") {
      lFunc = new SetFlagsFunction(this);
    }  
  }
  return lFunc;
}

void
ImapModule::destroy()
{
  if (!dynamic_cast<ImapModule*>(this)) {
    return;
  }
  delete this;
}

} /* namespace emailmodule */ } /* namespace zorba */
