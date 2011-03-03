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
#include <algorithm>
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
     
  std::string lResultString = lResult.str(); 
  return ItemSequence_t(new SingletonItemSequence(
      theModule->getItemFactory()->createString(lResultString.c_str())));
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

  int lVectorSize = (int)lListedMailboxes.size();
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
  Iterator_t arg3_iter = aArgs[3]->getIterator();
  arg3_iter->open();
  if (arg3_iter->next(lItem)) {
    lUid = lItem.getBooleanValue();
  }  
  arg3_iter->close();
  std::vector<long> lFoundSequenceNumbers = ImapClient::Instance().search(lHostName, lUserName, lPassword, lMailbox.c_str(), lCriteria.c_str(), lUid);
   
  // throw zorba exception if we have an error log
  std::string lErrorMessage = ImapClient::Instance().getError();
  if (lErrorMessage.size() != 0) {
    ImapFunction::throwImapError(lErrorMessage);
  }
     
  int lVectorSize =(int)lFoundSequenceNumbers.size();
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

  Iterator_t arg4_iter = aArgs[4]->getIterator();
  arg4_iter->open();
  if (arg4_iter->next(lItem)) {
    lUid = lItem.getBooleanValue();
  }
  arg4_iter->close();
  Iterator_t arg5_iter = aArgs[5]->getIterator();
  arg5_iter->open();
  bool lCopy = false;
  if (arg5_iter->next(lItem)) {
    lCopy = lItem.getBooleanValue();
  }
  arg5_iter->close();
  
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
 
  bool lUid = false;
  Item lItem;
  Iterator_t arg3_iter = aArgs[3]->getIterator();
  arg3_iter->open();
  if (arg3_iter->next(lItem)) {
    lUid = lItem.getBooleanValue();
  }
  arg3_iter->close();

  Item lParent; 
  FetchMessageFunction::getMessage(theModule, lParent, lHostName.c_str(), lUserName.c_str(), lPassword.c_str(), lMailbox.c_str(), lMessageNumber, lUid, true);  

  std::string lErrorMessage = ImapClient::Instance().getError();
  if (lErrorMessage.size() != 0) {
    ImapFunction::throwImapError(lErrorMessage);
  }



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

  std::string lErrorMessage = ImapClient::Instance().getError();
  if (lErrorMessage.size() != 0) {
    ImapFunction::throwImapError(lErrorMessage);
  }


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

  std::string lErrorMessage = ImapClient::Instance().getError();
  if (lErrorMessage.size() != 0) {
    ImapFunction::throwImapError(lErrorMessage);
  }


  return ItemSequence_t(new SingletonItemSequence(
      theModule->getItemFactory()->createString(lResult)));
}


//*****************************************************************************

FetchFlagsFunction::FetchFlagsFunction(const ImapModule* aModule)
  : ImapFunction(aModule)
{
}

ItemSequence_t
FetchFlagsFunction::evaluate(
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
  bool lUid = false;
  Item lItem;
  Iterator_t arg3_iter = aArgs[3]->getIterator();
  arg3_iter->open();
  if (arg3_iter->next(lItem)) {
    lUid = lItem.getBooleanValue();
  }
  arg3_iter->close();
  
  // null parent
  Item lParent;
  std::vector<int> lFlags(6, 0);

  ImapClient::Instance().fetchFlags(lHostName, lUserName, lPassword, lMailbox.c_str(), lMessageNumber,lFlags, lUid);
 
  std::string lErrorMessage = ImapClient::Instance().getError();
  if (lErrorMessage.size() != 0) {
    ImapFunction::throwImapError(lErrorMessage);
  }


  Item lFlagsItem;
  ImapFunction::createFlagsNode(theModule, lParent, lFlagsItem, lFlags, true);

  return ItemSequence_t(new SingletonItemSequence(lFlagsItem));
}


//*****************************************************************************

SetFlagsFunction::SetFlagsFunction(const ImapModule* aModule)
  : ImapFunction(aModule)
{
}

ItemSequence_t
SetFlagsFunction::evaluate(
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
    
  std::vector<int> lFlags(6, 0);
  SetFlagsFunction::getFlagsVector(aArgs, lFlags); 

  bool lUid = false;
  Item lItem;
  Iterator_t arg4_iter = aArgs[4]->getIterator();
  arg4_iter->open();
  if (arg4_iter->next(lItem)) {
    lUid = lItem.getBooleanValue();
  }
  arg4_iter->close();

  ImapClient::Instance().setFlags(lHostName, lUserName, lPassword, lMailbox.c_str(), lMessageNumber, lFlags, lUid);

  std::string lErrorMessage = ImapClient::Instance().getError();
  if (lErrorMessage.size() != 0) {
    ImapFunction::throwImapError(lErrorMessage);
  }
  
  return ItemSequence_t(new SingletonItemSequence(
      theModule->getItemFactory()->createBoolean(true)));
}

void
SetFlagsFunction::getFlagsVector(const StatelessExternalFunction::Arguments_t& aArgs, std::vector<int>& aFlags) {
  
  Item lFlagsNode;
  Iterator_t arg3_iter = aArgs[3]->getIterator();
  arg3_iter->open();
  arg3_iter->next(lFlagsNode);
  arg3_iter->close();
  Iterator_t lChildren = lFlagsNode.getChildren();
  lChildren->open();
  Item lChild;
  while(lChildren->next(lChild)) {
    Item lNameNode; 
    lChild.getNodeName(lNameNode);
    String lName = lNameNode.getStringValue();
    /* checking for ending of name as it is not sure how the prefix looks like */
    if (lName.endsWith("n")) {
      // seen
      aFlags[0] = 1; 
    } else if (lName.endsWith("ted")) {
      // deleted
      aFlags[1] = 1;
    } else if (lName.endsWith("ged")) {
      // flagged
      aFlags[2] = 1;
    } else if (lName.endsWith("red")) {
      // answered
      aFlags[3] = 1;
    } else if (lName.endsWith("ft")) {
      // draft
      aFlags[4] = 1;
    }
  }
}


//*****************************************************************************

FetchUidFunction::FetchUidFunction(const ImapModule* aModule)
  : ImapFunction(aModule)
{
}

ItemSequence_t
FetchUidFunction::evaluate(
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
  unsigned long lResult = ImapClient::Instance().convertNumber(lHostName, lUserName, lPassword, lMailbox.c_str(), lMessageNumber, true);

  return ItemSequence_t(new SingletonItemSequence(
      theModule->getItemFactory()->createLong(lResult)));
}

//*****************************************************************************

FetchMessageSequenceNumberFunction::FetchMessageSequenceNumberFunction(const ImapModule* aModule)
  : ImapFunction(aModule)
{
}

ItemSequence_t
FetchMessageSequenceNumberFunction::evaluate(
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
  unsigned long lResult = ImapClient::Instance().convertNumber(lHostName, lUserName, lPassword, lMailbox.c_str(), lMessageNumber, false);

  return ItemSequence_t(new SingletonItemSequence(
      theModule->getItemFactory()->createLong(lResult)));
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
 
 
  std::vector<int> lFlags(6,0);
  ENVELOPE* lEnvelope;
  BODY* lBody;
  if (aOnlyEnvelope) {
    // only fetch envelope
    lEnvelope =  ImapClient::Instance().fetchEnvelope(aHostName, aUserName, aPassword, aMailbox, aMessageNumber, lFlags, aUid);
  } else {
    // the flags vector in the imap client will be filled by this call, so clear it
    lEnvelope = ImapClient::Instance().fetchStructure(aHostName, aUserName, aPassword, aMailbox, &lBody, aMessageNumber, aUid, lFlags);
  }
 
  std::vector<std::pair<String, String> >   ns_binding;
  ns_binding.push_back(std::pair<String, String>("email", "http://www.zorba-xquery.com/modules/email/email"));
 
  /* First construct the envelope (depending on aOnlyEnvelope we may be finished then) */
  Item lEnvelopeItem;
  std::string lErrorMessage = ImapClient::Instance().getError();
  if (lErrorMessage.size() != 0) {
    ImapFunction::throwImapError(lErrorMessage);
  }
  /* begin construction of envelope
   * Important: if we only want the envelope, then the envelope MUST be qualified (being the root of the DOM)
   */
  Item lEnvelopeName;
  if (aOnlyEnvelope) {
    lEnvelopeName = aModule->getItemFactory()->createQName("http://www.zorba-xquery.com/modules/email/email", "email", "envelope");
  } else {
     lEnvelopeName = aModule->getItemFactory()->createQName("", "", "envelope");
  }  
  Item lEnvelopeType = aModule->getItemFactory()->createQName("http://www.zorba-xquery.com/modules/email/email", "email", "envelopeType");
 
  Item lNullItem;
  /* if we only want the envelope, then create it with a null parent, else create the message and use it as parent */
  if (aOnlyEnvelope) {
    lEnvelopeItem =  aModule->getItemFactory()->createElementNode(lNullItem, lEnvelopeName, lEnvelopeType, false, false, ns_binding);
  } else {
    Item lMessageName = aModule->getItemFactory()->createQName("http://www.zorba-xquery.com/modules/email/email", "email", "message");
    Item lMessageType = aModule->getItemFactory()->createQName("http://www.zorba-xquery.com/modules/email/email", "email", "messageType");
    aParent =  aModule->getItemFactory()->createElementNode(lNullItem, lMessageName, lMessageType, false, false, ns_binding);
    lEnvelopeItem =  aModule->getItemFactory()->createElementNode(aParent, lEnvelopeName, lEnvelopeType, false, false, ns_binding);
  }

  // create the remail node if needed 
  if (lEnvelope->remail) {
    ImapFunction::createInnerNodeWithText(aModule, lEnvelopeItem, "", "email",  "remail", "string", lEnvelope->remail);
  }
  /* create the date node if needed */
  if (lEnvelope->date) {
    ImapFunction::createInnerNodeWithText(aModule, lEnvelopeItem, "", "",  "date", "string", ImapFunction::getDateTime(reinterpret_cast<const char*>(lEnvelope->date)));
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
    ImapFunction::createInnerNodeWithText(aModule, lEnvelopeItem, "", "",  "subject", "string", lEnvelope->subject);
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
    ImapFunction::createInnerNodeWithText(aModule, lEnvelopeItem,  "", "",  "messageId", "string", lEnvelope->message_id);
  }
  Item lFlagsItem;
  // create flags node
  ImapFunction::createFlagsNode(aModule, lEnvelopeItem, lFlagsItem, lFlags, false);

  // if we only want the envelope, then here is a good place to stop
  if (aOnlyEnvelope) {
    aParent = lEnvelopeItem;
    return;
  } 

  /* if we want the whole message, then build it together */
  
  /* <email:mimeVersion>1.0</email:mimeVersion> */
  ImapFunction::createInnerNodeWithText(aModule, aParent,  "", "", "mimeVersion", "string", "1.0");
  
 
  // make a tolower version of the subtype
  
  std::string lSubType(lBody->subtype);
  std::transform(lSubType.begin(), lSubType.end(), lSubType.begin(), tolower);
   
  /* creating the <body> node */ 
  static Item lBodyName = aModule->getItemFactory()->createQName("", "", "body");
  static Item lBodyType = aModule->getItemFactory()->createQName("http://www.zorba-xquery.com/modules/email/email", "email", "bodyTypeChoice");
  static Item lBodyItem = aModule->getItemFactory()->createElementNode(aParent, lBodyName, lBodyType, false, false, ns_binding); 
  /* in case of non-multipart, just add the body to the message */
      
  static Item lMultipartParentName = aModule->getItemFactory()->createQName("", "", "multipart");
  static Item lMultipartParentType = aModule->getItemFactory()->createQName("http://www.zorba-xquery.com/modules/email/email", "email", "multipartType");
  Item lMultipartParent; 
      // using a vector instead of a stack, because including stack will clash with the c-client include ... 
  std::vector<BODY*> lBodies;
  lBodies.push_back(lBody);
  std::vector<Item> lParents;
  lParents.push_back(lBodyItem);
  std::vector<std::string> lSections;
  lSections.push_back("");  
  
  /* make sure that the special case of a completely non-multipart message is handled correctly */
  bool lNoMultipart = false;
  if (lBody->type != TYPEMULTIPART) {
    lNoMultipart = true;
  }

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
    /* get different attributes that we will need in any case, regardless if this is a content or multipart item */
    std::string lContentType = ImapFunction::getContentType(lCurrentBody->type, lCurrentBody->subtype);
    std::string lEncoding = ImapFunction::getEncoding(lCurrentBody->encoding);
    std::string lContentDisposition = "";
    if (lCurrentBody->disposition.type != NIL) {
      lContentDisposition = cpystr(lCurrentBody->disposition.type);
    }  
    std::string lContentDispositionFilename = "";
    std::string lContentDispositionModificationDate = "";
    
    PARAMETER* lCurrentParameter = lCurrentBody->disposition.parameter;
    while (lCurrentParameter != NIL) {
      
      if (!std::string("filename").compare(lCurrentParameter->attribute)) {
        lContentDispositionFilename = cpystr(lCurrentParameter->value);
      }  else if (!std::string("modification-date").compare(lCurrentParameter->attribute)) {
        lContentDispositionModificationDate = cpystr(lCurrentParameter->value);
      }  
      
      lCurrentParameter = lCurrentParameter->next;
    }  

    if (lCurrentBody->type != TYPEMULTIPART) {
      std::string lContentId = "";
      char * lId = lCurrentBody->id;
     
      if (lId != NIL) {
        lContentId = cpystr(lId);
      }
      
      std::string lSubType(lCurrentBody->subtype);                                                                  
      std::transform(lSubType.begin(), lSubType.end(), lSubType.begin(), tolower);
      // make sure that we haven't got a empty string (happens if there is no multipart in this message)
      if (lCurrentSection.size() != 0) {
        lCurrentSection.erase(lCurrentSection.end() - 1);
      }
  
      std::string lBodyContent = ImapClient::Instance().fetchBodyFull(aHostName, aUserName, aPassword, aMailbox, aMessageNumber, lNoMultipart ? "1" : lCurrentSection, aUid);  
      ImapFunction::createContentNode(aModule, lCurrentParent, lBodyContent, lContentType, "us-ascii", lEncoding, lContentDisposition, lContentDispositionFilename, lContentDispositionModificationDate, lContentId); 
 
    } else {
      lMultipartParent = aModule->getItemFactory()->createElementNode(lCurrentParent, lMultipartParentName, lMultipartParentType, false, false, ns_binding);
      ImapFunction::createContentTypeAttributes(aModule, lMultipartParent, lContentType, "us-ascii", lEncoding, lContentDisposition, lContentDispositionFilename, lContentDispositionModificationDate); 
      PART* lPart = lCurrentBody->nested.part;
      lBodies.insert(lBodies.begin(), &lPart->body);
      lParents.insert(lParents.begin(), lMultipartParent);      
      lSections.insert(lSections.begin(), lCurrentSection + "1.");
      for (int j = 1; lPart->next; ++j) {
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


} /* namespace emailmodule */ } /* namespace zorba */



#ifdef WIN32
#  define DLL_EXPORT __declspec(dllexport)
#else
#  define DLL_EXPORT __attribute__ ((visibility("default")))
#endif

extern "C" DLL_EXPORT zorba::ExternalModule* createModule() {
  return new zorba::emailmodule::ImapModule();
}
