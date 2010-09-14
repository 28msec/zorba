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
#include <iostream>
#include <zorba/singleton_item_sequence.h>
#include <zorba/vector_item_sequence.h>
#include <zorba/empty_sequence.h>
#include <sstream>
#include "imap_module.h"
#include "imap_client.h"
#include <string>
#include "c-client.h"


namespace zorba { namespace emailmodule {

//*****************************************************************************

StatusFunction::StatusFunction(const ImapModule* aModule)
  : ImapFunction(aModule)
{
}
  
ItemSequence_t
StatusFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  std::string lHostName;
  std::string lUserName;
  std::string lPassword;
  ImapFunction::getHostUserPassword(aArgs, 0, lHostName, lUserName, lPassword);
  String lMailbox = ImapFunction::getOneStringArg(aArgs, 1);
  ImapClient::Instance().status(lHostName, lUserName, lPassword, lMailbox.c_str());
  std::string lErrorMessage = ImapClient::Instance().getError();
  if (lErrorMessage.size() != 0) {
    ImapFunction::throwImapError(lErrorMessage);
  }  
    
  unsigned long lMessages;
  unsigned long lRecent;
  unsigned long lUnseen;
  unsigned long lUIDNext;
  unsigned long lUIDValidity;
  
  ImapClient::Instance().getStatus(&lMessages, &lRecent, &lUnseen, &lUIDNext, &lUIDValidity);
  
  std::stringstream lResult;
  lResult << lMessages << "," << lRecent << "," << lUnseen << "," << lUIDNext << "," << lUIDValidity;
     
  
  return ItemSequence_t(new SingletonItemSequence(
      theModule->getItemFactory()->createString(lResult.str())));
}

//*****************************************************************************

CreateFunction::CreateFunction(const ImapModule* aModule)
  : ImapFunction(aModule)
{
}

ItemSequence_t
CreateFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  std::string lHostName;
  std::string lUserName;
  std::string lPassword;
  ImapFunction::getHostUserPassword(aArgs, 0, lHostName, lUserName, lPassword);
  String lMailboxName = ImapFunction::getOneStringArg(aArgs, 1);
  bool lResult = ImapClient::Instance().create(lHostName, lUserName, lPassword, lMailboxName.c_str());
  std::string lErrorMessage = ImapClient::Instance().getError();
  if (lErrorMessage.size() != 0) {
    ImapFunction::throwImapError(lErrorMessage);
  }

  return ItemSequence_t(new SingletonItemSequence(
      theModule->getItemFactory()->createBoolean(lResult)));
}


//*****************************************************************************

DeleteFunction::DeleteFunction(const ImapModule* aModule)
  : ImapFunction(aModule)
{
}

ItemSequence_t
DeleteFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  std::string lHostName;
  std::string lUserName;
  std::string lPassword;
  ImapFunction::getHostUserPassword(aArgs, 0, lHostName, lUserName, lPassword);
  String lMailboxName = ImapFunction::getOneStringArg(aArgs, 1);
  bool lResult = ImapClient::Instance().delete_mailbox(lHostName, lUserName, lPassword, lMailboxName.c_str());
  std::string lErrorMessage = ImapClient::Instance().getError();
  
  if (lErrorMessage.size() != 0) {
    ImapFunction::throwImapError(lErrorMessage);
  }

  return ItemSequence_t(new SingletonItemSequence(
      theModule->getItemFactory()->createBoolean(lResult)));
}

//*****************************************************************************

RenameFunction::RenameFunction(const ImapModule* aModule)
  : ImapFunction(aModule)
{
}

ItemSequence_t
RenameFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  std::string lHostName;
  std::string lUserName;
  std::string lPassword;
  ImapFunction::getHostUserPassword(aArgs, 0, lHostName, lUserName, lPassword);
  String lMailboxFromName = ImapFunction::getOneStringArg(aArgs, 1);
  String lMailboxToName = ImapFunction::getOneStringArg(aArgs, 2);
  bool lResult = ImapClient::Instance().rename(lHostName, lUserName, lPassword, lMailboxFromName.c_str(), lMailboxToName.c_str());
  std::string lErrorMessage = ImapClient::Instance().getError();
  if (lErrorMessage.size() != 0) {
    ImapFunction::throwImapError(lErrorMessage);
  }

  return ItemSequence_t(new SingletonItemSequence(
      theModule->getItemFactory()->createBoolean(lResult)));
}


//*****************************************************************************

ListFunction::ListFunction(const ImapModule* aModule)
  : ImapFunction(aModule)
{
}

ItemSequence_t
ListFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  std::string lHostName;
  std::string lUserName;
  std::string lPassword;
  ImapFunction::getHostUserPassword(aArgs, 0, lHostName, lUserName, lPassword);
  String lReferencePath = ImapFunction::getOneStringArg(aArgs, 1);
  String lPattern = ImapFunction::getOneStringArg(aArgs, 2);
  bool lOnlySuscribed = ImapFunction::getOneBoolArg(aArgs, 3);
    
  std::vector<std::string> lListedMailboxes = ImapClient::Instance().list(lHostName, lUserName, lPassword, lReferencePath.c_str(), lPattern.c_str(), lOnlySuscribed);
  std::string lErrorMessage = ImapClient::Instance().getError();
  if (lErrorMessage.size() != 0) {
    ImapFunction::throwImapError(lErrorMessage);
  }
  // explicitly return an empty sequence if there are no elements to return
  if (lListedMailboxes.size() == 0) {
    return ItemSequence_t(new EmptySequence());
  }   

  int lVectorSize = lListedMailboxes.size();
  std::vector<Item> lItemVector;
  for (int i = 0; i < lVectorSize; i++) {
    lItemVector.push_back(theModule->getItemFactory()->createString(lListedMailboxes[i]));
  }  
  
  return ItemSequence_t(new VectorItemSequence(lItemVector));
}


//*****************************************************************************

SubscribeFunction::SubscribeFunction(const ImapModule* aModule)
  : ImapFunction(aModule)
{
}

ItemSequence_t
SubscribeFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  std::string lHostName;
  std::string lUserName;
  std::string lPassword;
  ImapFunction::getHostUserPassword(aArgs, 0, lHostName, lUserName, lPassword);
  String lMailbox = ImapFunction::getOneStringArg(aArgs, 1);
  
  bool lResult = ImapClient::Instance().subscription(lHostName, lUserName, lPassword, lMailbox.c_str(), true);
  std::string lErrorMessage = ImapClient::Instance().getError();
  if (lErrorMessage.size() != 0) {
    ImapFunction::throwImapError(lErrorMessage);
  }

  return ItemSequence_t(new SingletonItemSequence(
      theModule->getItemFactory()->createBoolean(lResult)));
}

//*****************************************************************************

UnsubscribeFunction::UnsubscribeFunction(const ImapModule* aModule)
  : ImapFunction(aModule)
{
}

ItemSequence_t
UnsubscribeFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  std::string lHostName;
  std::string lUserName;
  std::string lPassword;
  ImapFunction::getHostUserPassword(aArgs, 0, lHostName, lUserName, lPassword);
  String lMailbox = ImapFunction::getOneStringArg(aArgs, 1);
  
  bool lResult = ImapClient::Instance().subscription(lHostName, lUserName, lPassword, lMailbox.c_str(), false);
  std::string lErrorMessage = ImapClient::Instance().getError();
  if (lErrorMessage.size() != 0) {
    ImapFunction::throwImapError(lErrorMessage);
  }

  return ItemSequence_t(new SingletonItemSequence(
      theModule->getItemFactory()->createBoolean(lResult)));
}

//*****************************************************************************

ExpungeFunction::ExpungeFunction(const ImapModule* aModule)
  : ImapFunction(aModule)
{
}

ItemSequence_t
ExpungeFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  std::string lHostName;
  std::string lUserName;
  std::string lPassword;
  ImapFunction::getHostUserPassword(aArgs, 0, lHostName, lUserName, lPassword);
  String lMailbox = ImapFunction::getOneStringArg(aArgs, 1);

  bool lResult = ImapClient::Instance().expunge(lHostName, lUserName, lPassword, lMailbox.c_str());
  std::string lErrorMessage = ImapClient::Instance().getError();
  if (lErrorMessage.size() != 0) {
    ImapFunction::throwImapError(lErrorMessage);
  }

  return ItemSequence_t(new SingletonItemSequence(
      theModule->getItemFactory()->createBoolean(lResult)));
}

//*****************************************************************************

SearchFunction::SearchFunction(const ImapModule* aModule)
  : ImapFunction(aModule)
{
}

ItemSequence_t
SearchFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  std::string lHostName;
  std::string lUserName;
  std::string lPassword;
  ImapFunction::getHostUserPassword(aArgs, 0, lHostName, lUserName, lPassword);
  String lMailbox = ImapFunction::getOneStringArg(aArgs, 1);
  String lCriteria = ImapFunction::getOneStringArg(aArgs, 2);
  // get none or one boolean arg
  bool lUid = false;
  Item lItem;
  if (aArgs[3]->next(lItem)) {
    lUid = lItem.getBooleanValue();
  }  
  std::vector<long> lFoundSequenceNumbers = ImapClient::Instance().search(lHostName, lUserName, lPassword, lMailbox.c_str(), lCriteria.c_str(), lUid);
   
  // throw zorba exception if we have an error log
  std::string lErrorMessage = ImapClient::Instance().getError();
  if (lErrorMessage.size() != 0) {
    ImapFunction::throwImapError(lErrorMessage);
  }
     
  int lVectorSize =lFoundSequenceNumbers.size();
  std::vector<Item> lItemVector;
  for (int i = 0; i < lVectorSize; i++) {
    lItemVector.push_back(theModule->getItemFactory()->createLong(lFoundSequenceNumbers[i]));
  } 

  return ItemSequence_t(new VectorItemSequence(lItemVector));

}

//*****************************************************************************

CopyFunction::CopyFunction(const ImapModule* aModule)
  : ImapFunction(aModule)
{
}

ItemSequence_t
CopyFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  std::string lHostName;
  std::string lUserName;
  std::string lPassword;
  ImapFunction::getHostUserPassword(aArgs, 0, lHostName, lUserName, lPassword);
  String lMailboxFrom = ImapFunction::getOneStringArg(aArgs, 1);
  String lMailboxTo = ImapFunction::getOneStringArg(aArgs, 2);
  // find out if we are working with uid's instead of sequence numbers.
  bool lUid = false;
  Item lItem;
  if (aArgs[4]->next(lItem)) {
    lUid = lItem.getBooleanValue();
  }
  bool lCopy = false;
  if (aArgs[5]->next(lItem)) {
    lCopy = lItem.getBooleanValue();
  }
  
  std::string lMessageNumbers = ImapFunction::getMessageNumbers(aArgs, 3); 
   
  bool lResult = ImapClient::Instance().copy(lHostName, lUserName, lPassword, lMailboxFrom.c_str(), lMailboxTo.c_str(), lMessageNumbers, lUid, lCopy);
  std::string lErrorMessage = ImapClient::Instance().getError();
  if (lErrorMessage.size() != 0) {
    ImapFunction::throwImapError(lErrorMessage);
  }

  return ItemSequence_t(new SingletonItemSequence(
      theModule->getItemFactory()->createBoolean(lResult)));
}

//*****************************************************************************

FetchEnvelopeFunction::FetchEnvelopeFunction(const ImapModule* aModule)
  : ImapFunction(aModule)
{
}

ItemSequence_t
FetchEnvelopeFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  std::string lHostName;
  std::string lUserName;
  std::string lPassword;
  ImapFunction::getHostUserPassword(aArgs, 0, lHostName, lUserName, lPassword);
  String lMailbox = ImapFunction::getOneStringArg(aArgs, 1);
  // find out if we are working with uid's instead of sequence numbers.

  unsigned long lMessageNumber = ImapFunction::getOneMessageNumber(aArgs, 2);  

  ENVELOPE* lEnvelope =  ImapClient::Instance().fetchEnvelope(lHostName.c_str(), lUserName.c_str(), lPassword.c_str(), lMailbox.c_str(), lMessageNumber);
  
  std::string lErrorMessage = ImapClient::Instance().getError();
  if (lErrorMessage.size() != 0) {
    ImapFunction::throwImapError(lErrorMessage);
  }
  // begin construction of envelope 
  std::vector<std::pair<String, String> >   ns_binding;
  ns_binding.push_back(std::pair<String, String>("email", "http://www.zorba-xquery.com/modules/email/email"));
  Item lItemName = theModule->getItemFactory()->createQName("http://www.zorba-xquery.com/modules/email/email", "email", "envelope");
  Item lItemType = theModule->getItemFactory()->createQName("http://www.zorba-xquery.com/modules/email/email", "email", "envelopeType");
  Item lParent = NULL;
  lParent =  theModule->getItemFactory()->createElementNode(lParent, lItemName, lItemType, false, false, ns_binding);

  // create the remail node if needed 
  if (lEnvelope->remail) {
    ImapFunction::createInnerNodeWithText(theModule, lParent, "http://www.zorba-xquery.com/modules/email/email", "email",  "remail", "string", lEnvelope->remail);
  }
  /* create the date node if needed */
  if (lEnvelope->date) {
    ImapFunction::createInnerNodeWithText(theModule, lParent, "http://www.zorba-xquery.com/modules/email/email", "",  "date", "string", ImapFunction::getDateTime(reinterpret_cast<const char*>(lEnvelope->date)));
  }
  // create from node if needed
  if (lEnvelope->from) {
    ImapFunction::createEmailAddressNode(theModule, lParent, "from", lEnvelope->from->personal, lEnvelope->from->mailbox, lEnvelope->from->host);
  }
  // create sender node if needed
  if (lEnvelope->sender) {
    ImapFunction::createEmailAddressNode(theModule, lParent, "sender", lEnvelope->sender->personal, lEnvelope->sender->mailbox, lEnvelope->sender->host);
  }
  // create replyTo node if needed
  if (lEnvelope->reply_to) {
    ImapFunction::createEmailAddressNode(theModule, lParent, "replyTo", lEnvelope->reply_to->personal, lEnvelope->reply_to->mailbox, lEnvelope->reply_to->host);
  }
  // create subject node
  if (lEnvelope->subject) {
    ImapFunction::createInnerNodeWithText(theModule, lParent, "http://www.zorba-xquery.com/modules/email/email", "email",  "subject", "string", lEnvelope->subject);
  }

  ADDRESS* lRecipents;
  if (lEnvelope->to) {
    ImapFunction::createRecipentNode(theModule, lParent, "to", lEnvelope->to->personal, lEnvelope->to->mailbox, lEnvelope->to->host);
    lRecipents = lEnvelope->to;
    while ((lRecipents = lRecipents->next)) {
       ImapFunction::createRecipentNode(theModule, lParent, "to", lEnvelope->to->personal, lEnvelope->to->mailbox, lEnvelope->to->host);
    } 
  }
 
  if (lEnvelope->cc) {
    ImapFunction::createRecipentNode(theModule, lParent, "cc", lEnvelope->cc->personal, lEnvelope->cc->mailbox, lEnvelope->cc->host);
    lRecipents = lEnvelope->cc;
    while ((lRecipents = lRecipents->next)) {
       ImapFunction::createRecipentNode(theModule, lParent, "cc", lEnvelope->cc->personal, lEnvelope->cc->mailbox, lEnvelope->cc->host);
    }
  }  
 
  if ((lRecipents = lEnvelope->bcc)) {
    ImapFunction::createRecipentNode(theModule, lParent, "bcc", lEnvelope->bcc->personal, lEnvelope->bcc->mailbox, lEnvelope->bcc->host);
    while ((lRecipents = lRecipents->next)) {
       ImapFunction::createRecipentNode(theModule, lParent, "bcc", lEnvelope->bcc->personal, lEnvelope->bcc->mailbox, lEnvelope->bcc->host);
    }
  }  

  // create messageId node
  if (lEnvelope->message_id) {
    ImapFunction::createInnerNodeWithText(theModule, lParent,  "http://www.zorba-xquery.com/modules/email/email", "email",  "messageId", "string", lEnvelope->message_id);
  }
 

  return ItemSequence_t(new SingletonItemSequence(lParent));
}




} /* namespace emailmodule */ } /* namespace zorba */

#ifdef WIN32
#  define DLL_EXPORT __declspec(dllexport)
#else
#  define DLL_EXPORT __attribute__ ((visibility("default")))
#endif

extern "C" DLL_EXPORT zorba::ExternalModule* createModule() {
  return new zorba::emailmodule::ImapModule();
}
