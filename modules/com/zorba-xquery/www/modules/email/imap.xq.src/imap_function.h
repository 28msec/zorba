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

#ifndef ZORBA_EMAILMODULE_IMAPFUNCTION_H
#define ZORBA_EMAILMODULE_IMAPFUNCTION_H

#include <zorba/external_function.h>



namespace zorba { namespace emailmodule {

  class ImapModule;

  class ImapFunction : public NonePureStatelessExternalFunction
  {
  protected:
      const ImapModule* theModule;

      static void
      throwError(
          const std::string errorMessage,
          const Error& errorType);

      static void throwImapError(const std::string aErrorMessage);

      static void
      getHostUserPassword(const StatelessExternalFunction::Arguments_t& aArgs,
                          int aPos,
                          std::string& aHost,
                          std::string& aUserName,
                          std::string& aPassword);

      static String
      getOneStringArg(const StatelessExternalFunction::Arguments_t& args,
                      int pos);
      static std::string
      getMessageNumbers(const StatelessExternalFunction::Arguments_t& args,
                        int pos);

      static unsigned long
      getOneMessageNumber(const StatelessExternalFunction::Arguments_t& args,
                          int pos);

     static bool
     getOneBoolArg(const StatelessExternalFunction::Arguments_t& args,
                   int pos);

    /*
     * Converts a dateTime string as returned by the c-client (e.g. Tue, 24
     * Aug 2010 16:26:10 +0200'DD) into a xs:dateTime format.
     */
    static std::string
    getDateTime(const std::string& aCClientDateTime);

    static std::string
    getContentType(const unsigned short aType, const char* aSubtype);

    static std::string
    getEncoding(const unsigned short aEncoding);



    static void
    createFlagsNode(const ImapModule* aModule,
                    Item& aParent,
                    Item& aFlags,
                    std::vector<int>& aFlagsVector,
                    const bool aQualified);

    /*
     * Creates a simple named  node containing a text node.
     */
    static void
    createInnerNodeWithText(const ImapModule* aModule,
                            Item& aParent,
                            const std::string& aNamespace,
                            const std::string& aPrefix,
                            const std::string& aName,
                            const std::string& aTypeNamespace,
                            const std::string& aType,
                            const std::string& aContent);

    static void
    createContentNode(const ImapModule* aModule,
                   Item& aParent,
                   const std::string& aContent,
                   const std::string& contentType,
                   const std::string& charset,
                   const std::string& contentTransferEncoding,
                   const std::string& aContentDisposition,
                   const std::string& aContentDispositionFilename,
                   const std::string& aContentDispositionModificationDate,
                   const std::string& aContentId);





     /*
      * Creates a simple email address node as defined in email.xsd
      */
    static void
    createEmailAddressNode(const ImapModule* aModule,
                           Item& aParent,
                           const std::string& aName,
                           const char * aPersonal,
                           const char* aMailbox,
                           const char* aHost);

    static void
    createRecipentNode(const ImapModule* aModule,
                       Item& aParent,
                       const std::string& aName,
                       const char * aPersonal,
                       const char* aMailbox,
                       const char* aHost);

    static void
    createContentTypeAttributes(const ImapModule* aModule,
                                Item& aParent,
                                const std::string& aValue,
                                const std::string& aCharset,
                                const std::string& aTransferEncoding,
                                const std::string& aContentDisposition,
                                const std::string& aContentDispositionFilename,
                                const std::string& aContentDispositionModificationDate);


    public:
      ImapFunction(const ImapModule* module);
      ~ImapFunction();

      virtual String
      getURI() const;

  };
} /* namespace emailmodule */
} /* namespace zorba */

#endif /* ZORBA_EMAILMODULE_EMAILFUNCTION_H */
                                                 
