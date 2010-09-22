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
ImapModule::getExternalFunction(String aLocalname) const
{
  StatelessExternalFunction*& lFunc = theFunctions[aLocalname];
  if (!lFunc) {
    if (1 == 0) {
    } else if (aLocalname.equals("status")) {
      lFunc = new StatusFunction(this);
    } else if (aLocalname.equals("create")) {
      lFunc = new CreateFunction(this);
    } else if (aLocalname.equals("delete")) {
      lFunc = new DeleteFunction(this);
    } else if (aLocalname.equals("rename")) {
      lFunc = new RenameFunction(this);
    } else if (aLocalname.equals("list")) {
      lFunc = new ListFunction(this);
    } else if (aLocalname.equals("subscribe")) {
      lFunc = new SubscribeFunction(this);
    } else if (aLocalname.equals("unsubscribe")) {
      lFunc = new UnsubscribeFunction(this);
    } else if (aLocalname.equals("expunge")) {
      lFunc = new ExpungeFunction(this);
    } else if (aLocalname.equals("search")) {
      lFunc = new SearchFunction(this);
    } else if (aLocalname.equals("copy")) {
      lFunc = new CopyFunction(this);
    } else if (aLocalname.equals("fetch-envelope")) {
      lFunc = new FetchEnvelopeFunction(this);
    } else if (aLocalname.equals("fetch-message")) {
      lFunc = new FetchMessageFunction(this);
    } else if (aLocalname.equals("fetch-subject")) {
      lFunc = new FetchSubjectFunction(this);
    } else if (aLocalname.equals("fetch-from")) {
      lFunc = new FetchFromFunction(this);
    } else if (aLocalname.equals("fetch-uid")) {
      lFunc = new FetchUidFunction(this);
    } else if (aLocalname.equals("fetch-message-sequence-number")) {
      lFunc = new FetchMessageSequenceNumberFunction(this);
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
