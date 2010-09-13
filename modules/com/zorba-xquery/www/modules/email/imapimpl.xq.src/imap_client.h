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


#ifndef ZORBA_EMAIL_IMAP_CLIENT_H
#define ZORBA_EMAIL_IMAP_CLIENT_H 


#ifdef WIN32
#include <windows.h>
#endif

#include "c-client.h"
#include <string>
#include <vector>

namespace zorba
{
  namespace emailmodule
  {
    class ImapClient
    {
    public:
      static ImapClient& Instance()
      {
        static ImapClient lInstance;
        return lInstance;
      }

      void status(const std::string& aHost, const std::string& aUsername, const std::string& aPassword, const std::string& aMailbox);

      bool create(const std::string& aHost, const std::string& aUsername, const std::string& aPassword, const std::string& aMailboxName);

      bool delete_mailbox(const std::string& aHost, const std::string& aUsername, const std::string& aPassword, const std::string& aMailboxName);

      bool rename(const std::string& aHost, const std::string& aUserName, const std::string& aPassword, const std::string& aMailboxFromName, const std::string& aMailboxToName);

      bool subscription(const std::string& aHost, const std::string& aUserName, const std::string& aPassword, const std::string& aMailbox, bool subscribe);

      bool expunge(const std::string& aHost, const std::string& aUserName, const std::string& aPassword, const std::string& aMailbox);

      bool copy(const std::string& aHost, const std::string& aUserName, const std::string& aPassword, const std::string& aMailboxFrom, const std::string& aMailboxTo, const std::string& aMessageNumbers, bool aUid, bool aCopy);

      std::vector<std::string> list(const std::string& aHost, const std::string& aUserName, const std::string& aPassword, const std::string& aReferencePath, const std::string& aPattern, bool aOnlySuscribed);
      
      std::vector<long> search(const std::string& aHost, const std::string& aUserName, const std::string& aPassword, const std::string& aMailbox, const std::string& aCriteria, bool aUid);
     
      ENVELOPE* fetchEnvelope(const std::string& aHost, const std::string& aUserName, const std::string& aPassword, const std::string& aMailbox, unsigned long aMessageNumber );

      /*
       * Generates a search_program out of an IMAP_rv4 complient vector of strings.
       * The search program is then used by the mail_search_full function which hasn't got a built in parser.
       */
      SEARCHPGM *search_criteria(std::vector<std::string> aCriteria);

      /*
       * Returns the next string of this iterator as char *.
       */
      char * getNextStringAsChar(std::vector<std::string>::iterator aIterator);

      /*
       * Returns true if the passed keyword does not need an argument (according to the IMAP_rv4 search syntax.
       */
      bool isSingleKeyword(const std::string& aKeyword);
  

      void setUserName(const std::string& aUserName);
      void setPassword(const std::string& aPassword);

      std::string getUserName();
      std::string getPassword();
      std::string getError();
      void addError(const std::string& aError);

      void setStatus(unsigned long aMessages, unsigned long aRecent, unsigned long aUnseen, unsigned long aUIDNext, unsigned long aUIDValidity);
  
      void getStatus(unsigned long* aMessages, unsigned long* aRecent, unsigned long* aUnseen, unsigned long* aUIDNextm, unsigned long* aUIDValidity);  
    
      void addFoundSequenceNumber(long aSequenceNumber);
      
      
      void addListedMailbox(const std::string& aListedMail);
      

    private:
      //ctor, dtor, copy ctor are all hidden
      ImapClient() {
        theErrorMessage.clear();
      };
      ~ImapClient() {};
      ImapClient(ImapClient const&) {};
      std::string theUserName;
      std::string thePassword;
      
      // string containing error message
      std::string theErrorMessage;
  
      // vars for status  
      unsigned long theMessages;
      unsigned long theRecent;
      unsigned long theUnseen;
      unsigned long theUIDNext;
      unsigned long theUIDValidity;
      std::vector<std::string> theListedMailboxes;
      std::vector<long> theFoundSequenceNumbers;

    };

  }//namespace email
}//namespace zorba

#endif // ZORBA_MODULES_EMAIL_UW_IMAP_H



