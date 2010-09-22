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
#include <algorithm>
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

  unsigned long lMessageNumber = ImapFunction::getOneMessageNumber(aArgs, 2);  
  
  Item lParent; 
  FetchMessageFunction::getMessage(theModule, lParent, lHostName.c_str(), lUserName.c_str(), lPassword.c_str(), lMailbox.c_str(), lMessageNumber, false, true);  

  return ItemSequence_t(new SingletonItemSequence(lParent));
}


//*****************************************************************************

FetchSubjectFunction::FetchSubjectFunction(const ImapModule* aModule)
  : ImapFunction(aModule)
{
}

ItemSequence_t
FetchSubjectFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  std::string lHostName;
  std::string lUserName;
  std::string lPassword;
  ImapFunction::getHostUserPassword(aArgs, 0, lHostName, lUserName, lPassword);
  String lMailbox = ImapFunction::getOneStringArg(aArgs, 1);
  unsigned long lMessageNumber = ImapFunction::getOneMessageNumber(aArgs, 2);
  String lResult = ImapClient::Instance().fetchSubject(lHostName, lUserName, lPassword, lMailbox.c_str(), lMessageNumber);

  return ItemSequence_t(new SingletonItemSequence(
      theModule->getItemFactory()->createString(lResult)));
}

//*****************************************************************************

FetchFromFunction::FetchFromFunction(const ImapModule* aModule)
  : ImapFunction(aModule)
{
}

ItemSequence_t
FetchFromFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
  std::string lHostName;
  std::string lUserName;
  std::string lPassword;
  ImapFunction::getHostUserPassword(aArgs, 0, lHostName, lUserName, lPassword);
  String lMailbox = ImapFunction::getOneStringArg(aArgs, 1);
  unsigned long lMessageNumber = ImapFunction::getOneMessageNumber(aArgs, 2);
  String lResult = ImapClient::Instance().fetchFrom(lHostName, lUserName, lPassword, lMailbox.c_str(), lMessageNumber);

  return ItemSequence_t(new SingletonItemSequence(
      theModule->getItemFactory()->createString(lResult)));
}





//*****************************************************************************               
                                                                                              
FetchMessageFunction::FetchMessageFunction(const ImapModule* aModule)                       
  : ImapFunction(aModule)                                                                     
{                                                                                             
}      

ItemSequence_t
FetchMessageFunction::evaluate(
  const StatelessExternalFunction::Arguments_t& aArgs,
  const StaticContext*                          aSctxCtx,
  const DynamicContext*                         aDynCtx) const
{
std::string lHostName;  std::string lUserName;  std::string lPassword;
  ImapFunction::getHostUserPassword(aArgs, 0, lHostName, lUserName, lPassword);
  String lMailbox = ImapFunction::getOneStringArg(aArgs, 1);

  unsigned long lMessageNumber = ImapFunction::getOneMessageNumber(aArgs, 2);

  bool lUid = ImapFunction::getOneBoolArg(aArgs, 3);
  
  Item lParent;
  FetchMessageFunction::getMessage(theModule, lParent, lHostName.c_str(), lUserName.c_str(), lPassword.c_str
(), lMailbox.c_str(), lMessageNumber, lUid, false);

  return ItemSequence_t(new SingletonItemSequence(lParent));

}


void
FetchMessageFunction::getMessage(const ImapModule* aModule, 
                                 Item& aParent,
                                 const std::string& aHostName, 
                                 const std::string& aUserName, 
                                 const std::string& aPassword, 
                                 const std::string& aMailbox, 
                                 const unsigned long aMessageNumber, 
                                 const bool aUid, 
                                 const bool aOnlyEnvelope)
{
 
  ENVELOPE* lEnvelope;
  BODY* lBody;
  if (aOnlyEnvelope) {
    // only fetch envelope
    lEnvelope =  ImapClient::Instance().fetchEnvelope(aHostName, aUserName, aPassword, aMailbox, aMessageNumber);
  } else {
    lEnvelope = ImapClient::Instance().fetchStructure(aHostName, aUserName, aPassword, aMailbox, &lBody, aMessageNumber, aUid);
  }

  std::vector<std::pair<String, String> >   ns_binding;
  ns_binding.push_back(std::pair<String, String>("email", "http://www.zorba-xquery.com/modules/email/email"));
 
  /* First construct the envelope (depending on aOnlyEnvelope we may be finished then) */
  Item lEnvelopeItem;
  std::string lErrorMessage = ImapClient::Instance().getError();
  if (lErrorMessage.size() != 0) {
    ImapFunction::throwImapError(lErrorMessage);
  }
  // begin construction of envelope 
  Item lEnvelopeName = aModule->getItemFactory()->createQName("http://www.zorba-xquery.com/modules/email/email", "email", "envelope");
  Item lEnvelopeType = aModule->getItemFactory()->createQName("http://www.zorba-xquery.com/modules/email/email", "email", "envelopeType");
 
  Item lNullItem;
  /* if we only want the envelope, then create it with a null parent, else create the message and use it as parent */
  if (aOnlyEnvelope) {
    lEnvelopeItem =  aModule->getItemFactory()->createElementNode(lNullItem, lEnvelopeName, lEnvelopeType, false, false, ns_binding);
  } else {
    Item lMessageName = aModule->getItemFactory()->createQName("http://www.zorba-xquery.com/modules/email/email", "email", "Message");
    Item lMessageType = aModule->getItemFactory()->createQName("http://www.zorba-xquery.com/modules/email/email", "email", "messageType");
    aParent =  aModule->getItemFactory()->createElementNode(lNullItem, lMessageName, lMessageType, false, false, ns_binding);
    lEnvelopeItem =  aModule->getItemFactory()->createElementNode(aParent, lEnvelopeName, lEnvelopeType, false, false, ns_binding);
  }

  // create the remail node if needed 
  if (lEnvelope->remail) {
    ImapFunction::createInnerNodeWithText(aModule, lEnvelopeItem, "http://www.zorba-xquery.com/modules/email/email", "email",  "remail", "string", lEnvelope->remail);
  }
  /* create the date node if needed */
  if (lEnvelope->date) {
    ImapFunction::createInnerNodeWithText(aModule, lEnvelopeItem, "http://www.zorba-xquery.com/modules/email/email", "",  "date", "string", ImapFunction::getDateTime(reinterpret_cast<const char*>(lEnvelope->date)));
  }
  // create from node if needed
  if (lEnvelope->from) {
    ImapFunction::createEmailAddressNode(aModule, lEnvelopeItem, "from", lEnvelope->from->personal, lEnvelope->from->mailbox, lEnvelope->from->host);
  }
  // create sender node if needed  
  if (lEnvelope->sender) {    ImapFunction::createEmailAddressNode(aModule, lEnvelopeItem, "sender", lEnvelope->sender->personal, lEnvelope->sender->mailbox, lEnvelope->sender->host);  }
  // create replyTo node if needed
  if (lEnvelope->reply_to) {
    ImapFunction::createEmailAddressNode(aModule, lEnvelopeItem, "replyTo", lEnvelope->reply_to->personal, lEnvelope->reply_to->mailbox, lEnvelope->reply_to->host);
  }
  // create subject node
  if (lEnvelope->subject) {
    ImapFunction::createInnerNodeWithText(aModule, lEnvelopeItem, "http://www.zorba-xquery.com/modules/email/email", "email",  "subject", "string", lEnvelope->subject);
  }
   
  ADDRESS* lRecipents;
  if (lEnvelope->to) {
    ImapFunction::createRecipentNode(aModule, lEnvelopeItem, "to", lEnvelope->to->personal, lEnvelope->to->mailbox, lEnvelope->to->host);
    lRecipents = lEnvelope->to;
    while ((lRecipents = lRecipents->next)) {
       ImapFunction::createRecipentNode(aModule, lEnvelopeItem, "to", lEnvelope->to->personal, lEnvelope->to->mailbox, lEnvelope->to->host);
    }
  }

  if (lEnvelope->cc) {
    ImapFunction::createRecipentNode(aModule, lEnvelopeItem, "cc", lEnvelope->cc->personal, lEnvelope->cc->mailbox, lEnvelope->cc->host);
    lRecipents = lEnvelope->cc;
    while ((lRecipents = lRecipents->next)) {
       ImapFunction::createRecipentNode(aModule, lEnvelopeItem, "cc", lEnvelope->cc->personal, lEnvelope->cc->mailbox, lEnvelope->cc->host);
    }
  }

  if ((lRecipents = lEnvelope->bcc)) {
    ImapFunction::createRecipentNode(aModule, lEnvelopeItem, "bcc", lEnvelope->bcc->personal, lEnvelope->bcc->mailbox, lEnvelope->bcc->host);
    while ((lRecipents = lRecipents->next)) {
       ImapFunction::createRecipentNode(aModule, lEnvelopeItem, "bcc", lEnvelope->bcc->personal, lEnvelope->bcc->mailbox, lEnvelope->bcc->host);
    }
  }

  // create messageId node
  if (lEnvelope->message_id) {
    ImapFunction::createInnerNodeWithText(aModule, lEnvelopeItem,  "http://www.zorba-xquery.com/modules/email/email", "email",  "messageId", "string", lEnvelope->message_id);
  }
  // if we only want the envelope, then here is a good place to stop
  if (aOnlyEnvelope) {
    aParent = lEnvelopeItem;
    return;
  } 

  /* if we want the whole message, then build it together */
  
  /* <email:mimeVersion>1.0</email:mimeVersion> */
  ImapFunction::createInnerNodeWithText(aModule, aParent,  "http://www.zorba-xquery.com/modules/email/email", "email", "mimeVersion", "string", "1.0");
  

  ImapFunction::createContentTypeNode(aModule, aParent, ImapFunction::getContentType(lBody->type, lBody->subtype), "us-ascii", ImapFunction::getEncoding(lBody->encoding));

 
  // make a tolower version of the subtype
  
  std::string lSubType(lBody->subtype);
  std::transform(lSubType.begin(), lSubType.end(), lSubType.begin(), tolower);
  
   
  /* creating the <body> node */ 
  Item lBodyName = aModule->getItemFactory()->createQName("http://www.zorba-xquery.com/modules/email/email", "email", "body");
  Item lBodyType = aModule->getItemFactory()->createQName("http://www.zorba-xquery.com/modules/email/email", "email", "bodyTypeChoice");
  Item lBodyItem = aModule->getItemFactory()->createElementNode(aParent, lBodyName, lBodyType, false, false, ns_binding); 
  /* in case of non-multipart, just add the body to the message */
  if (lBody->type != TYPEMULTIPART) {
      // in this case just get the whole text body
      std::string lBodyContent = ImapClient::Instance().fetchText(aHostName, aUserName, aPassword, aMailbox, aMessageNumber, aUid);  
      ImapFunction::createBodyNode(aModule, lBodyItem, lBodyContent, lSubType);  
  } else if (lBody->type == TYPEMULTIPART) {
      // needed for creating multipart items
      Item lMultipartParentName = aModule->getItemFactory()->createQName("http://www.zorba-xquery.com/modules/email/email", "email", "multipart");
      Item lMultipartParentType = aModule->getItemFactory()->createQName("http://www.zorba-xquery.com/modules/email/email", "email", "innerMessageType");
      Item lMultipartParent; 
      // using a vector instead of a stack, because including stack will clash with the c-client include ... 
      std::vector<BODY*> lBodies;
      std::vector<Item> lParents;
      std::vector<std::string> lSections;
      lSections.push_back("");  
      lBodies.push_back(lBody);
      lParents.push_back(lBodyItem);
      
      BODY* lCurrentBody;
      Item lCurrentParent;
      std::string lCurrentSection; 
      // iterate and create all nodes (doing this recursive would have been nicer, but seems impossible without making a function containing a c-client structure in its signature, which seems impossible)
      while (lBodies.size() > 0) {
        lCurrentBody = lBodies.front();
        lCurrentParent = lParents.front();
        lCurrentSection = lSections.front(); 
        lSections.erase(lSections.begin());
        lParents.erase(lParents.begin()); 
        lBodies.erase(lBodies.begin());
        if (lCurrentBody->type != TYPEMULTIPART) {
           std::string lSubType(lCurrentBody->subtype);                                                                  
           std::transform(lSubType.begin(), lSubType.end(), lSubType.begin(), tolower);
           lCurrentSection.erase(lCurrentSection.end() - 1);
           std::string lBodyContent = ImapClient::Instance().fetchBodyFull(aHostName, aUserName, aPassword, aMailbox, aMessageNumber, lCurrentSection, aUid);  
           ImapFunction::createBodyNode(aModule, lCurrentParent, lBodyContent, lSubType); 
        } else {
          lMultipartParent = aModule->getItemFactory()->createElementNode(lCurrentParent, lMultipartParentName, lMultipartParentType, false, false, ns_binding);

          PART* lPart = lCurrentBody->nested.part;
          lBodies.insert(lBodies.begin(), &lPart->body);
          lParents.insert(lParents.begin(), lMultipartParent);      
          lSections.insert(lSections.begin(), lCurrentSection + "1.");
          for (int j = 1; lPart->next; j++) {
            lPart = lPart->next; 
            std::stringstream lConverter;
            lConverter << j+1 << "."; 
            lSections.insert(lSections.begin() + j, lCurrentSection + lConverter.str());
            lConverter.clear(); 
            lBodies.insert(lBodies.begin() +j, &lPart->body);
            lParents.insert(lParents.begin(), lMultipartParent);
          }
        }
      } 
    }
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
