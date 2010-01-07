#include <zorba/zorba.h>
#include <zorba/singleton_item_sequence.h>
#include <zorba/serializer.h>
#include <zorba/api_shared_types.h>
#include <zorba/base64.h>

#include "http_request_handler.h"

namespace zorba { namespace http_client {

  HttpRequestHandler::HttpRequestHandler(CURL* aCurl,
                                         ItemSequence* aContent,
                                         String aSerial)
    : theCurl(aCurl),
      theStatusOnly(false),
      theInsideMultipart(false),
      theLastBodyHadContent(false),
      theContent(aContent),
      theSerial(aSerial),
      theSerStream(NULL),
      thePost(NULL),
      theLast(NULL)
  {
    theHeaderLists.push_back(NULL);
  }

  HttpRequestHandler::~HttpRequestHandler()
  {
    std::vector<struct curl_slist*>::iterator lIter;
    for (lIter = theHeaderLists.begin(); lIter != theHeaderLists.end(); ++lIter)
    {
      if (*lIter) {
        curl_slist_free_all(*lIter);
      }
    }

    if (thePost != NULL) {
      curl_formfree(thePost);
    }
  }

  void HttpRequestHandler::begin()
  {
  }

  void HttpRequestHandler::beginResponse(int aStatus, String aMessage)
  {
  }

  void HttpRequestHandler::endResponse()
  {
  }

  void HttpRequestHandler::beginRequest(String aMethod,
                                        String href,
                                        bool aStatusOnly,
                                        String aUsername,
                                        String aPassword,
                                        String aAuthMethod,
                                        bool aSendAuthorization,
                                        String aOverrideContentType,
                                        bool aFollowRedirect,
                                        int aTimeout /*= -1*/ )
  {
    if (aMethod == "POST") {
      curl_easy_setopt(theCurl, CURLOPT_POST, 1);
    } else if (aMethod == "PUT") {
      curl_easy_setopt(theCurl, CURLOPT_UPLOAD, 1);
    } else if (aMethod == "GET") {
      //is default
    } else if (aMethod == "DELETE") {
      curl_easy_setopt(theCurl, CURLOPT_CUSTOMREQUEST, "DELETE");
    } else if (aMethod == "TRACE") {
      curl_easy_setopt(theCurl, CURLOPT_CUSTOMREQUEST, "TRACE");
    } else if (aMethod == "OPTIONS") {
      curl_easy_setopt(theCurl, CURLOPT_CUSTOMREQUEST, "OPTIONS");
    } else if (aMethod == "HEAD") {
      curl_easy_setopt(theCurl, CURLOPT_CUSTOMREQUEST, "HEAD");
    } else {
      aMethod.uppercase();
      curl_easy_setopt(theCurl, CURLOPT_CUSTOMREQUEST, aMethod.c_str());
    }
    if (href != "") {
      curl_easy_setopt(theCurl, CURLOPT_URL, href.c_str());
    }
    if (aFollowRedirect) {
      curl_easy_setopt(theCurl, CURLOPT_FOLLOWLOCATION, 1);
    }
    theStatusOnly = aStatusOnly;
    theOverrideContentType = aOverrideContentType;
    if (aTimeout != -1) {
      curl_easy_setopt(theCurl, CURLOPT_TIMEOUT, aTimeout);
    }
    if (aUsername != "" && !aSendAuthorization) {
      String lUserPw = aUsername + ":" + aPassword;
      curl_easy_setopt(theCurl, CURLOPT_USERPWD, lUserPw.c_str());
      if (aAuthMethod == "Basic") {
        curl_easy_setopt(theCurl, CURLOPT_HTTPAUTH, CURLAUTH_BASIC);
      } else if (aAuthMethod == "Digest") {
        curl_easy_setopt(theCurl, CURLOPT_HTTPAUTH, CURLAUTH_DIGEST);
      }
    }
    if (aUsername != "" && aSendAuthorization) {
      if (aAuthMethod == "Basic") {
        String lAuthString = aUsername + ":" + aPassword;
        String lAuth = "Authorization: Basic ";
        lAuth += encoding::Base64::encode(lAuthString);
        theHeaderLists[0] = curl_slist_append(theHeaderLists[0], lAuth.c_str());
      } else if (aAuthMethod == "Digest") {
        String lUserPw = aUsername + ":" + aPassword;
        curl_easy_setopt(theCurl, CURLOPT_USERPWD, lUserPw.c_str());
        curl_easy_setopt(theCurl, CURLOPT_HTTPAUTH, CURLAUTH_DIGEST);
      }
    }
  }

  void HttpRequestHandler::endRequest()
  {
  }

  void HttpRequestHandler::header(String aName, String aValue)
  {
    std::string lValue = aName.c_str();
    lValue += ":";
    lValue += aValue.c_str();
    if (!theInsideMultipart) {
      theHeaderLists[0] = curl_slist_append(theHeaderLists[0], lValue.c_str());
    } else {
      theHeaderLists.back() = curl_slist_append(theHeaderLists.back(), (lValue).c_str());
    }
  }

  void HttpRequestHandler::beginBody(String aContentType,
                                     String aEncoding,
                                     String aId,
                                     String aDescription,
                                     String aSrc)
  {
    theSerStream = new std::ostringstream();
    std::string lValueId = "Content-ID: ";
    lValueId += aId.c_str();
    std::string lValueDescr = "Content-Description : ";
    lValueDescr += aDescription.c_str();
    theCurrentContentType = aContentType;
    std::string lContentType = "Content-Type: ";
    lContentType += aContentType.c_str();
    if (!theInsideMultipart) {
      theHeaderLists[0] = curl_slist_append(theHeaderLists[0], lValueId.c_str());
      theHeaderLists[0] = curl_slist_append(theHeaderLists[0], lValueDescr.c_str());
      theHeaderLists[0] = curl_slist_append(theHeaderLists[0], lContentType.c_str());
    } else {
      theHeaderLists.push_back(NULL);
      theHeaderLists.back() = curl_slist_append(theHeaderLists.back(), lValueId.c_str());
      theHeaderLists.back() = curl_slist_append(theHeaderLists.back(), lValueDescr.c_str());
      theHeaderLists.back() = curl_slist_append(theHeaderLists.back(), lContentType.c_str());
    }
  }

  void HttpRequestHandler::any(Item aItem)
  {
    serializeItem(aItem);
  }

  void HttpRequestHandler::endBody()
  {
    if (!theLastBodyHadContent) {
      if (theContent == NULL) {
        cleanUpBody();
        return;
      }
      Item lItem;
      while (theContent->next(lItem)) {
        serializeItem(lItem);
      }
    }
    std::string lData = theSerStream->str();
    if (!theInsideMultipart) {
      curl_easy_setopt(theCurl, CURLOPT_POSTFIELDSIZE, lData.length());
      curl_easy_setopt(theCurl, CURLOPT_COPYPOSTFIELDS, lData.c_str());
    } else {
      curl_formadd(&thePost, &theLast,
        CURLFORM_COPYNAME, "blub",
        CURLFORM_COPYCONTENTS, lData.c_str(),
        CURLFORM_CONTENTSLENGTH, lData.length(),
        CURLFORM_CONTENTHEADER, theHeaderLists.back(),
        CURLFORM_END);
    }
  }

  void HttpRequestHandler::beginMultipart(String aContentType, String aBoundary)
  {
    theInsideMultipart = true;
    std::string lValue = "Content-Type: ";
    lValue += aContentType.c_str();
    theHeaderLists[0] = curl_slist_append(theHeaderLists[0], lValue.c_str());
  }

  void HttpRequestHandler::endMultipart()
  {
    theInsideMultipart = false;
    curl_easy_setopt(theCurl, CURLOPT_HTTPPOST, thePost);
  }

  void HttpRequestHandler::end()
  {
    if (theHeaderLists[0]) {
      curl_easy_setopt(theCurl, CURLOPT_HTTPHEADER, theHeaderLists[0]);
    }
  }

  bool HttpRequestHandler::getOverrideContentType( String& aResult )
  {
    if (theOverrideContentType == "") {
      return false;
    }
    aResult = theOverrideContentType;
    return true;
  }

  void HttpRequestHandler::cleanUpBody()
  {
    delete theSerStream;
    theLastBodyHadContent = false;
  }

  void HttpRequestHandler::serializeItem( Item aItem )
  {
    theLastBodyHadContent = true;
    Zorba_SerializerOptions_t lOptions;
    lOptions.version = "1.1";
    lOptions.undeclare_prefixes = ZORBA_UNDECLARE_PREFIXES_YES;
    if (theSerial == "") {
      if (theCurrentContentType == "text/xml" ||
        theCurrentContentType == "application/xml" ||
        theCurrentContentType == "text/xml-external-parsed-entity" ||
        theCurrentContentType == "application/xml-external-parsed-entity" ||
        theCurrentContentType.endsWith("+xml"))
      {
        lOptions.ser_method = ZORBA_SERIALIZATION_METHOD_XML;
        lOptions.version = "1.1";
        lOptions.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;
      } else if (theCurrentContentType == "text/html") {
        lOptions.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;
        lOptions.ser_method = ZORBA_SERIALIZATION_METHOD_HTML;
      } else if (theCurrentContentType.startsWith("text/")) {
        lOptions.ser_method = ZORBA_SERIALIZATION_METHOD_TEXT;
      }
    } else {
      if (theSerial == "text")
        lOptions.ser_method = ZORBA_SERIALIZATION_METHOD_TEXT;
      else if (theSerial == "xml")
        lOptions.ser_method = ZORBA_SERIALIZATION_METHOD_XML;
      else if (theSerial == "html")
        lOptions.ser_method = ZORBA_SERIALIZATION_METHOD_HTML;
      else
        lOptions.ser_method = ZORBA_SERIALIZATION_METHOD_TEXT;
    }
    Serializer_t lSerializer = Serializer::createSerializer(lOptions);
    SingletonItemSequence lSequence(aItem);
    lSerializer->serialize(&lSequence, *theSerStream);
  }
}}
