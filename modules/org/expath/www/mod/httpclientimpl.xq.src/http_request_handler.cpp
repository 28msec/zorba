#include <zorba/zorba.h>
#include <zorba/singleton_item_sequence.h>
#include <zorba/serializer.h>
#include <zorba/api_shared_types.h>

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
    }
    if (href != "") {
      curl_easy_setopt(theCurl, CURLOPT_URL, href.c_str());
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
      // Todo: implement adding header here.
    }
  }

  void HttpRequestHandler::endRequest()
  {
  }

  void HttpRequestHandler::header(String aName, String aValue)
  {
    String lValue = aName.append(":");
    lValue += aValue;
    if (!theInsideMultipart) {
      curl_slist_append(theHeaderLists[0], (lValue).c_str());
    } else {
      curl_slist_append(theHeaderLists.back(), (lValue).c_str());
    }
  }

  void HttpRequestHandler::beginBody(String aContentType,
                                     String aEncoding,
                                     String aId,
                                     String aDescription,
                                     String aSrc)
  {
    theSerStream = new std::ostringstream();
    String lValueId = "Content-ID: ";
    lValueId += aId;
    String lValueDescr = "Content-Description : ";
    lValueDescr += aDescription;
    if (!theInsideMultipart) {
      curl_slist_append(theHeaderLists[0], lValueId.c_str());
      curl_slist_append(theHeaderLists[0], lValueDescr.c_str());
    } else {
      theHeaderLists.push_back(NULL);
      curl_slist_append(theHeaderLists.back(), lValueId.c_str());
      curl_slist_append(theHeaderLists.back(), lValueDescr.c_str());
    }
  }

  void HttpRequestHandler::any(Item aItem)
  {
    theLastBodyHadContent = true;
    if (theSerial == "text") {
      (*theSerStream) << aItem.getStringValue();
    } else {
      Zorba_SerializerOptions_t lOptions;
      Serializer_t lSerializer = Serializer::createSerializer(lOptions);
      SingletonItemSequence lSequence(aItem);
      lSerializer->serialize(&lSequence, *theSerStream);
    }
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
        if (theSerial == "text") {
          (*theSerStream) << lItem.getStringValue();
        } else {
          Zorba_SerializerOptions_t lOptions;
          Serializer_t lSerializer = Serializer::createSerializer(lOptions);
          SingletonItemSequence lSequence(lItem);
          lSerializer->serialize(&lSequence, *theSerStream);
        }
      }
    }
    std::string lData = theSerStream->str();
    if (!theInsideMultipart) {
      curl_easy_setopt(theCurl, CURLOPT_POSTFIELDSIZE, lData.length());
      curl_easy_setopt(theCurl, CURLOPT_POSTFIELDS, lData.c_str());
    } else {
      curl_formadd(&thePost, &theLast, CURLFORM_COPYCONTENTS, lData.c_str(),
        CURLFORM_CONTENTSLENGTH, lData.length(),
        CURLFORM_CONTENTHEADER, theHeaderLists.back());
    }
  }

  void HttpRequestHandler::beginMultipart(String aContentType, String aBoundary)
  {
    theInsideMultipart = true;
    String lValue = "Content-type: ";
    lValue += aContentType;
    lValue += "; boundary=\"";
    lValue += aBoundary;
    lValue += "\"";
    curl_slist_append(theHeaderLists[0], lValue.c_str());
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
}}
