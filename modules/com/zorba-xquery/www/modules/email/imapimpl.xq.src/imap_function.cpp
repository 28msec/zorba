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

#include "imap_function.h"
#include <sstream>
#include <zorba/zorba.h>
#include "imap_module.h"
#include <map>
#include <iostream>
#include <algorithm>

namespace zorba { namespace emailmodule {


ImapFunction::ImapFunction(const ImapModule* aModule)
        : theModule(aModule)
{
}
ImapFunction::~ImapFunction()
{
}

String
ImapFunction::getURI() const
{
  return theModule->getURI();
}

void
ImapFunction::throwError(
    const std::string aErrorMessage,
    const XQUERY_ERROR& aErrorType)
{
  throw zorba::ExternalFunctionData::createZorbaException(aErrorType,
      aErrorMessage.c_str(), __FILE__, __LINE__);
}

void 
ImapFunction::throwImapError(const std::string aErrorMessage) {
  throwError(aErrorMessage, XPTY0004); 
}  


void 
ImapFunction::getHostUserPassword(const StatelessExternalFunction::Arguments_t& aArgs,
                                  int aPos,
                                  std::string& aHost,
                                  std::string& aUserName,
                                  std::string& aPassword) {
  Item lNode;
  aArgs[aPos]->next(lNode);
  Iterator_t lChildren = lNode.getChildren();
  lChildren->open();
  Item lChild;
  lChildren->next(lChild);
  aHost = lChild.getStringValue().c_str();
  lChildren->next(lChild);
  aUserName = lChild.getStringValue().c_str();
  lChildren->next(lChild);
  aPassword = lChild.getStringValue().c_str();
  
}

String
ImapFunction::getOneStringArg(
    const StatelessExternalFunction::Arguments_t& aArgs,
    int aPos)
{
  Item lItem;
  if (!aArgs[aPos]->next(lItem)) {
    std::stringstream lErrorMessage;
    lErrorMessage << "An empty-sequence is not allowed as "
                  << aPos << ". parameter.";
    throwError(lErrorMessage.str(), XPTY0004);
  }
  zorba::String lTmpString = lItem.getStringValue();
  if (aArgs[aPos]->next(lItem)) {
    std::stringstream lErrorMessage;
    lErrorMessage << "A sequence of more then one item is not allowed as "
                  << aPos << ". parameter.";
    throwError(lErrorMessage.str(), XPTY0004);
  }
  return lTmpString;
}

std::string
ImapFunction::getMessageNumbers(
    const StatelessExternalFunction::Arguments_t& aArgs,
    int aPos)
{
  Item lItem;
  std::stringstream lMessageNumbers;
  aArgs[aPos]->next(lItem);
  lMessageNumbers << lItem.getStringValue().c_str();
  while(aArgs[aPos]->next(lItem)) {
    lMessageNumbers << "," << lItem.getStringValue().c_str();
  }
  return lMessageNumbers.str(); 
}


unsigned long 
ImapFunction::getOneMessageNumber(
    const StatelessExternalFunction::Arguments_t& aArgs,
    int aPos)
{
  Item lItem;
  aArgs[aPos]->next(lItem);
  return lItem.getLongValue();
}


bool
ImapFunction::getOneBoolArg(
    const StatelessExternalFunction::Arguments_t& aArgs,
    int aPos)
{
  Item lItem;
  if (!aArgs[aPos]->next(lItem)) {
    std::stringstream lErrorMessage;
    lErrorMessage << "An empty-sequence is not allowed as "
                  << aPos << ". parameter.";
    throwError(lErrorMessage.str(), XPTY0004);
  }
  bool lTmpBool = lItem.getBooleanValue();
  if (aArgs[aPos]->next(lItem)) {
    std::stringstream lErrorMessage;
    lErrorMessage << "A sequence of more then one item is not allowed as "
                  << aPos << ". parameter.";
    throwError(lErrorMessage.str(), XPTY0004);
  }
  return lTmpBool;
}


std::string
ImapFunction::getDateTime(const std::string& aCClientDateTime) {
  std::stringstream lResult;    
  std::stringstream lDateTimeStream(aCClientDateTime);
  std::string lBuffer;
  std::vector<std::string> lTokens;
  while (lDateTimeStream >> lBuffer) { 
    lTokens.push_back(lBuffer);
  }
  // YYYY-MM-DDThh:mm:ss, first push YYYY
  lResult << lTokens[3] << "-";
  // then push MM
  // build up map for Months
  
  std::string lMonths = "JanFebMarAprMayJunJulAugSepOctNovDez";
  size_t lMonthNumber = lMonths.find(lTokens[2]);
  // if the month was not found, were really in trouble!
  if (lMonthNumber == std::string::npos) {
        throwError("Error while processing month in date of message", XPTY0004);
  }  
  lMonthNumber = lMonthNumber/3 + 1;
  // make sure its MM and not just <
  if (lMonthNumber < 10) {
    lResult << 0;
  }  
  lResult << lMonthNumber << "-";
  
  if (lTokens[1].size() == 1) {
    lResult << 0;
  }
  lResult << lTokens[1] << "T";
  // now hh:mm:ss
  lResult << lTokens[4].substr(0,2) << ":" << lTokens[4].substr(3,2) << ":" << lTokens[4].substr(6,2);

  return lResult.str();
  
}

std::string
ImapFunction::getContentType(const unsigned short aType, const char* aSubtype) {
  std::stringstream lType;
  switch (aType) {
    // Text
    case 0 : 
      lType << "text";
    break;
    case 1 : 
      lType << "multipart";
    break;
    case 2 : 
      lType << "message";
    break;
    case 3 : 
      lType << "application";
    break;
    case 4 :
      lType << "audio";
    break;
    case 5 :
      lType << "image";
    break;
    case 6 :
      lType << "video";
    break;
    case 7 : 
      lType << "model";
    break;
    case 8 :
      lType << "other";
    break;
  }  
  std::string lSubType(aSubtype); 
  std::transform(lSubType.begin(), lSubType.end(), lSubType.begin(), tolower);
  lType << "/" << lSubType; 
  return lType.str();

}

std::string
ImapFunction::getEncoding(const unsigned short aEncoding) {
  std::stringstream lEncoding;
  switch (aEncoding) {
    case 0 :
      lEncoding << "ENC7BIT";
    break;
    case 1 : 
      lEncoding << "ENC8BIT";
    break;
    case 2 :
      lEncoding << "ENCBINARY";
    break;
    case 3 : 
      lEncoding << "ENCBASE64";
    break;
    case 4 :
      lEncoding << "ENCQUOTEDPRINTABLE";
    break;
    case 5 :
      lEncoding << "ENCOTHER";
    break;
    default : lEncoding << "ENCOTHER"; 


  }
  return lEncoding.str();
}



void
ImapFunction::createFlagsNode(const ImapModule* aModule,
                              Item& aParent,
                              Item& aFlags,
                              std::vector<int>& aFlagsVector) {



  std::vector<std::pair<String, String> >  ns_binding;
  ns_binding.push_back(std::pair<String, String>("email", "http://www.zorba-xquery.com/modules/email/email"));

  Item lFlagsName = aModule->getItemFactory()->createQName("http://www.zorba-xquery.com/modules/email/email", "email", "flags");
  Item lFlagsType = aModule->getItemFactory()->createQName("http://www.zorba-xquery.com/modules/email/email",  "flagsType");
  aFlags = aModule->getItemFactory()->createElementNode(aParent, lFlagsName, lFlagsType, false, false, ns_binding);


  std::vector<int>::iterator lFlagsIterator;
  std::string lFlagName;
  for (lFlagsIterator = aFlagsVector.begin(); lFlagsIterator != aFlagsVector.end(); ++lFlagsIterator) {
    int lFlagNumber = *lFlagsIterator;
    switch (lFlagNumber) {
      case 1 :
        lFlagName = "seen";
      break;
      case 2 :
        lFlagName = "deleted";
      break;
      case 3 :
        lFlagName = "flagged";
      break;
      case 4 :
        lFlagName = "answered";
      break;
      case 5 :
        lFlagName = "old";
      break;
      case 6 :
        lFlagName = "draft";
      break;
    }

    Item lOneFlagName = aModule->getItemFactory()->createQName("http://www.zorba-xquery.com/modules/email/email", "email", lFlagName);
    Item lOneFlagType = aModule->getItemFactory()->createQName("http://www.zorba-xquery.com/modules/email/email", "emptyType");
    Item lOneFlag = aModule->getItemFactory()->createElementNode(aFlags, lOneFlagName, lOneFlagType, false, false, ns_binding);
    aModule->getItemFactory()->createTextNode(lOneFlag, "1");
  }


}


void
ImapFunction::createInnerNodeWithText(const ImapModule* aModule, 
                                      Item& aParent, 
                                      const std::string& aNamespace, 
                                      const std::string& aPrefix, 
                                      const std::string& aName, 
                                      const std::string& aType, 
                                      const std::string& aContent) 
{
   std::vector<std::pair<String, String> > null_binding; 
  Item lName = aModule->getItemFactory()->createQName(aNamespace, aPrefix, aName);
  Item lType = aModule->getItemFactory()->createQName(aNamespace,  aType);
  Item lItem = aModule->getItemFactory()->createElementNode(aParent, lName, lType, false, false, null_binding);
  aModule->getItemFactory()->createTextNode(lItem, String(aContent));
}  


void
ImapFunction::createContentNode(const ImapModule* aModule,
                   Item& aParent,
                   const std::string& aContent,
                   const std::string& aContentType,
                   const std::string& aCharset,
                   const std::string& aContentTransferEncoding)

{  

  static Item lNullItem;
   
  std::vector<std::pair<String, String> > null_binding;
  static Item lName = aModule->getItemFactory()->createQName("http://www.zorba-xquery.com/modules/email/email", "email", "content");
  static Item lType = aModule->getItemFactory()->createQName("http://www.zorba-xquery.com/modules/email/email", "contentType" );
  Item lItem = aModule->getItemFactory()->createElementNode(aParent, lName, lType, false, false, null_binding);
  
  createContentTypeAttributes(aModule, lItem, aContentType, aCharset, aContentTransferEncoding);

  aModule->getItemFactory()->createTextNode(lItem, String(aContent));


}


void 
ImapFunction::createEmailAddressNode(const ImapModule* aModule, 
                                     Item& aParent, 
                                     const std::string& aName, 
                                     const char* aPersonal, 
                                     const char* aMailbox, 
                                     const char* aHost) 
{

  static Item lType = aModule->getItemFactory()->createQName("http://www.zorba-xquery.com/modules/email/email", "emailAddress");
  Item lName = aModule->getItemFactory()->createQName("http://www.zorba-xquery.com/modules/email/email", "email",  aName);

  std::vector<std::pair<String, String> >  ns_binding; 
   ns_binding.push_back(std::pair<String, String>("email", "http://www.zorba-xquery.com/modules/email/email"));
 
  Item lItem = aModule->getItemFactory()->createElementNode(aParent, lName, lType, false, false, ns_binding);
  if (aPersonal) {
    createInnerNodeWithText(aModule, lItem, "http://www.zorba-xquery.com/modules/email/email", "email", "name", "string", aPersonal);
  }
  if ((aMailbox) && (aHost)) {
    createInnerNodeWithText(aModule, lItem, "http://www.zorba-xquery.com/modules/email/email", "email", "email", "string", std::string(aMailbox) + "@" + std::string(aHost));  
  }
}



void 
ImapFunction::createRecipentNode(const ImapModule* aModule, 
                                 Item& aParent, 
                                 const std::string& aName, 
                                 const char* aPersonal, 
                                 const char* aMailbox, 
                                 const char* aHost) 
{                    
  static Item lType = aModule->getItemFactory()->createQName("http://www.zorba-xquery.com/modules/email/email", "recipientType");                                                                    
  static Item lName = aModule->getItemFactory()->createQName("http://www.zorba-xquery.com/modules/email/email", "email",  "recipient");                           
  
  std::vector<std::pair<String, String> >  ns_binding;                                        
    ns_binding.push_back(std::pair<String, String>("email", "http://www.zorba-xquery.com/modules/email/email"));
 
  Item lItem = aModule->getItemFactory()->createElementNode(aParent, lName, lType, false, false, ns_binding); 
  createEmailAddressNode(aModule, lItem, aName, aPersonal, aMailbox, aHost);
  
}
  

void 
ImapFunction::createContentTypeAttributes(const ImapModule* aModule,
                                          Item& aParent,
                                          const std::string& aContentType,
                                          const std::string& aCharset,
                                          const std::string& aContentTransferEncoding) {

  static Item lNullItem;
  /* build the value attribute */
  static Item lContentTypeName = aModule->getItemFactory()->createQName("", "", "contentType");
  static Item lContentTypeType = aModule->getItemFactory()->createQName("http://www.zorba-xquery.com/modules/email/email", "contentTypeValue");
  Item lContentTypeText = aModule->getItemFactory()->createTextNode(lNullItem, String(aContentType));
  aModule->getItemFactory()->createAttributeNode(aParent, lContentTypeName, lContentTypeType, lContentTypeText);

  /* build the charset attribute */
  static Item lCharsetName = aModule->getItemFactory()->createQName("", "", "charset");
  static Item lCharsetType = aModule->getItemFactory()->createQName("http://www.zorba-xquery.com/modules/email/email", "string");
  Item lCharsetText = aModule->getItemFactory()->createTextNode(lNullItem, String(aCharset));
  aModule->getItemFactory()->createAttributeNode(aParent, lCharsetName, lCharsetType, lCharsetText);

  /* build the contentTransferEncoding attribute */
  static Item lContentTransferName = aModule->getItemFactory()->createQName("", "", "contentTransferEncoding");
  static Item lContentTransferType = aModule->getItemFactory()->createQName("http://www.zorba-xquery.com/modules/email/email", "cteType");
  Item lContentTransferText = aModule->getItemFactory()->createTextNode(lNullItem, String(aContentTransferEncoding));
  aModule->getItemFactory()->createAttributeNode(aParent, lContentTransferName, lContentTransferType, lContentTransferText);
 

}


} /* namespace emailmodule */ } /* namespace zorba */
