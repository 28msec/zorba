#include <string>
#include <sstream>
#include <assert.h>

#include <zorba/item_factory.h>
#include <zorba/item.h>
#include <zorba/xmldatamanager.h>
#include <zorba/base64.h>

#include <tidy.h>
#include <buffio.h>

#include "http_response_parser.h"
#include "http_request_handler.h"
#include "curl_stream_buffer.h"

namespace zorba { namespace http_client {
  

  HttpResponseParser::HttpResponseParser(RequestHandler& aHandler, CURL* aCurl,
    std::string aOverridenContentType)
    : 
  theHandler(aHandler), theCurl(aCurl), theStatus(-1), theStreamBuffer(0),
    theInsideRead(false), theOverridenContentType(aOverridenContentType)
  {
    theMulti = curl_multi_init();
    curl_multi_add_handle(theMulti, theCurl);
    theStreamBuffer = new CurlStreamBuffer(theMulti, theCurl);
    registerHandler();
    fillCodeMap();
  }

  HttpResponseParser::~HttpResponseParser()
  {
    delete theStreamBuffer;
    curl_multi_remove_handle(theMulti, theCurl);
    curl_easy_cleanup(theCurl);
    curl_multi_cleanup(theMulti);
  }

  int HttpResponseParser::parse()
  {
    theStreamBuffer->setInformer(this);
    theHandler.begin();
    int lCode = theStreamBuffer->multi_perform();
    std::istream lStream(theStreamBuffer);
    Item lItem;
    if (theOverridenContentType != "") {
      theCurrentContentType = theOverridenContentType;
    }
    if (theCurrentContentType == "text/xml" ||
      theCurrentContentType == "application/xml" ||
      theCurrentContentType == "text/xml-external-parsed-entity" ||
      theCurrentContentType == "application/xml-external-parsed-entity" ||
      theCurrentContentType == "application/atom+xml") {
        lItem = createXmlItem(lStream);
    } else if (theCurrentContentType == "text/html") {
      lItem = createHtmlItem(lStream);
    } else if (theCurrentContentType.find("text/") == 0) {
      lItem = createTextItem(lStream);
    } else {
      lItem = createBase64Item(lStream);
    }
    if (!lItem.isNull()) {
      theHandler.any(lItem);
    }
    if (!theInsideRead) {
      theHandler.beginResponse(theStatus, theMessage);
    } else {
      theHandler.endBody();
    }
    theHandler.endResponse();
    theHandler.end();
    return lCode;
  }

  void HttpResponseParser::beforeRead()
  {
    if (theInsideRead) {
      return;
    }
    theInsideRead = true;
    theHandler.beginResponse(theStatus, theMessage);
    std::vector<std::pair<std::string, std::string> >::iterator lIter;
    for (lIter = theHeaders.begin(); lIter != theHeaders.end(); ++lIter) {
      theHandler.header(lIter->first, lIter->second);
    }
    theHandler.beginBody(theCurrentContentType, "", theId, theDescription, "");
  }

  void HttpResponseParser::afterRead()
  {
  }

  void HttpResponseParser::registerHandler()
  {
    curl_easy_setopt(theCurl, CURLOPT_HEADERFUNCTION,
      &HttpResponseParser::headerfunction);
    curl_easy_setopt(theCurl, CURLOPT_HEADERDATA, this);
  }

  size_t HttpResponseParser::headerfunction(void *ptr,
                                            size_t size,
                                            size_t nmemb,
                                            void *stream)
  {
    size_t lSize = size*nmemb;
    size_t lResult = lSize;
    HttpResponseParser* lParser = static_cast<HttpResponseParser*>(stream);
    if (lParser->theInsideRead) {
      lParser->theHandler.endBody();
    }
    lParser->theInsideRead = false;
    const char* lDataChar = (const char*) ptr;
    while (lDataChar[lSize - 1] == 10 || lDataChar[lSize - 1] == 13) {
      lSize--;
    }
    std::string lData(lDataChar, lSize);

    if (lData.find("HTTP") == 0) {
      lParser->parseStatusAndMessage(lData);
      return lResult;
    }
    std::string::size_type lPos = lData.find(':');
    if (lPos == std::string::npos) {
      return lResult;
    }
    std::string lName = lData.substr(0, lPos);
    std::string lValue = lData.substr(lPos + 2);
    {
      std::string::size_type lPosition = lValue.size() - 1;
      while (true) {
        if (lPosition != std::string::npos) {
          break;
        }
        if (lValue[lPosition] == '\n' || lValue[lPosition] == '\r') {
          --lPosition;
        } else {
          break;
        }
      }
      lValue = lValue.substr(0, lPosition + 1);
    }
    if (lName == "Content-Type") {
      lParser->theCurrentContentType = lValue.substr(0, lValue.find(';'));
    } else if (lName == "Content-ID") {
      lParser->theId = lValue;
    } else if (lName == "Content-Description") {
      lParser->theDescription = lValue;
    }
    lParser->theHeaders.push_back(
      std::pair<std::string, std::string>(lName, lValue));
    return lResult;
  }

  void HttpResponseParser::parseStatusAndMessage(std::string aHeader)
  {
    std::string::size_type lPos = aHeader.find(' ');
    assert(lPos != std::string::npos);
    std::string lStatus = aHeader.substr(lPos, aHeader.find(' ', lPos + 1));
    theMessage = aHeader.substr(aHeader.find(' ', lPos + 1) + 1);
    {
      std::string::size_type lPosition = theMessage.size() - 1;
      while (true) {
        if (lPosition != std::string::npos) {
          break;
        }
        if (theMessage[lPosition] == '\n' || theMessage[lPosition] == '\r') {
          --lPosition;
        } else {
          break;
        }
      }
      theMessage = theMessage.substr(0, lPosition + 1);
    }
    std::stringstream lStream(lStatus);
    lStream >> theStatus;
  }

  zorba::Item HttpResponseParser::createTextItem(std::istream& aStream)
  {
    std::string lData;
    {
      std::stringstream lOut;
      bool lFirst = true;
      while (aStream.good()) {
        if (!lFirst) {
          lOut << " ";
        }
        lFirst = false;
        std::string lTmp;
        aStream >> lTmp;
        lOut << lTmp;
      }
      lData = lOut.str();
    }
    aStream >> lData;
    ItemFactory* lFactory = Zorba::getInstance(0)->getItemFactory();
    return lFactory->createString(lData);
  }

  zorba::Item HttpResponseParser::createBase64Item( std::istream& aStream )
  {
    ItemFactory* lFactory = Zorba::getInstance(0)->getItemFactory();
    // TODO: once a proper streaming implementation is in place this can be
    // changed. This required a Base64 encoding stream since the item factory
    // work only builds base64binary and assumes the data is already encoded.
    String lEncoded = encoding::Base64::encode(aStream);
    return lFactory->createBase64Binary(lEncoded.c_str(), lEncoded.bytes());
  }

  zorba::Item HttpResponseParser::createXmlItem( std::istream& aStream )
  {
    XmlDataManager* lDM = Zorba::getInstance(0)->getXmlDataManager();
    return lDM->parseDocument(aStream);
  }

  zorba::Item HttpResponseParser::createHtmlItem( std::istream& aStream )
  {
    std::vector<char> source;

    std::string lTest;
    while (aStream.good()) {
      char lTestC = (char)(aStream.get());
      if (lTestC == -1)
        continue;
      source.push_back(lTestC);
      lTest += lTestC;
    }
    char* lInput = new char[source.size() + 1];
    std::vector<char>::iterator lIter;
    long pos = 0;
    for (lIter = source.begin(); lIter != source.end(); ++lIter) {
      lInput[pos++] = *lIter;
    }
    lInput[pos] = '\0';
    if (pos == 0) {
      return NULL;
    }
    TidyBuffer output;
    tidyBufInit(&output);
    TidyBuffer errbuf;
    tidyBufInit(&errbuf);
    TidyDoc tDoc = tidyCreate();
    tidyOptSetBool(tDoc, TidyXmlOut, yes);
    tidyOptSetInt(tDoc, TidyDoctypeMode, TidyDoctypeOmit);
    tidyOptSetBool(tDoc, TidyQuoteNbsp, yes);
    tidyOptSetValue(tDoc, TidyCharEncoding, "utf8");
    tidyOptSetValue(tDoc, TidyNewline, "LF");
    tidySetErrorBuffer(tDoc, &errbuf);
    tidyParseString(tDoc, lInput);
    tidySaveBuffer(tDoc, &output);
    std::string lResult((char*) output.bp, output.size);
    lResult = replaceCodes(lResult);
    std::istringstream lStream(lResult);
    XmlDataManager* lDM = Zorba::getInstance(0)->getXmlDataManager();
    try {
      return lDM->parseDocument(lStream);
    } catch (ZorbaException&) {
      return Zorba::getInstance(0)->getItemFactory()->createString(lResult);
    }
  }

  std::string HttpResponseParser::replaceCodes( std::string aStr )
  {
    std::ostringstream o;

    std::string::size_type lPrev = 0;
    std::string::size_type lPos = aStr.find('&');
    std::string::size_type lNext = aStr.find(';', lPos);
    while (lPos != std::string::npos && lNext != std::string::npos) {
      o << aStr.substr(lPrev, lPos - lPrev);
      std::string code = aStr.substr(lPos + 1, lNext - lPos - 1);
      o << "&" << lookUpCode(code) << ";";
      lPrev = lNext + 1;
      lPos = aStr.find('&', lPos + 1);
      lNext = aStr.find(';', lPos);
    }
    o << aStr.substr(lPrev == 0 ? 0 : lPrev);
    return o.str();
  }

  std::string HttpResponseParser::lookUpCode( std::string aCode )
  {
    std::map<std::string, std::string>::iterator lIter = theCodeMap.find(aCode);
    if (lIter != theCodeMap.end()) {
      return lIter->second;
    }
    return aCode;
  }

  void HttpResponseParser::fillCodeMap()
  {
    theCodeMap.insert(std::pair<std::string, std::string>("AElig", "#198"));
    theCodeMap.insert(std::pair<std::string, std::string>("Aacute", "#193"));
    theCodeMap.insert(std::pair<std::string, std::string>("Acirc", "#194"));
    theCodeMap.insert(std::pair<std::string, std::string>("Agrave", "#192"));
    theCodeMap.insert(std::pair<std::string, std::string>("Alpha", "#913"));
    theCodeMap.insert(std::pair<std::string, std::string>("Aring", "#197"));
    theCodeMap.insert(std::pair<std::string, std::string>("Atilde", "#195"));
    theCodeMap.insert(std::pair<std::string, std::string>("Auml", "#196"));
    theCodeMap.insert(std::pair<std::string, std::string>("Beta", "#914"));
    theCodeMap.insert(std::pair<std::string, std::string>("Ccedil", "#199"));
    theCodeMap.insert(std::pair<std::string, std::string>("Chi", "#935"));
    theCodeMap.insert(std::pair<std::string, std::string>("Dagger", "#8225"));
    theCodeMap.insert(std::pair<std::string, std::string>("Delta", "#916"));
    theCodeMap.insert(std::pair<std::string, std::string>("ETH", "#208"));
    theCodeMap.insert(std::pair<std::string, std::string>("Eacute", "#201"));
    theCodeMap.insert(std::pair<std::string, std::string>("Ecirc", "#202"));
    theCodeMap.insert(std::pair<std::string, std::string>("Egrave", "#200"));
    theCodeMap.insert(std::pair<std::string, std::string>("Epsilon", "#917"));
    theCodeMap.insert(std::pair<std::string, std::string>("Eta", "#919"));
    theCodeMap.insert(std::pair<std::string, std::string>("Euml", "#203"));
    theCodeMap.insert(std::pair<std::string, std::string>("Gamma", "#915"));
    theCodeMap.insert(std::pair<std::string, std::string>("Iacute", "#205"));
    theCodeMap.insert(std::pair<std::string, std::string>("Icirc", "#206"));
    theCodeMap.insert(std::pair<std::string, std::string>("Igrave", "#204"));
    theCodeMap.insert(std::pair<std::string, std::string>("Iota", "#921"));
    theCodeMap.insert(std::pair<std::string, std::string>("Iuml", "#207"));
    theCodeMap.insert(std::pair<std::string, std::string>("Kappa", "#922"));
    theCodeMap.insert(std::pair<std::string, std::string>("Lambda", "#923"));
    theCodeMap.insert(std::pair<std::string, std::string>("Mu", "#924"));
    theCodeMap.insert(std::pair<std::string, std::string>("Ntilde", "#209"));
    theCodeMap.insert(std::pair<std::string, std::string>("Nu", "#925"));
    theCodeMap.insert(std::pair<std::string, std::string>("OElig", "#338"));
    theCodeMap.insert(std::pair<std::string, std::string>("Oacute", "#211"));
    theCodeMap.insert(std::pair<std::string, std::string>("Ocirc", "#212"));
    theCodeMap.insert(std::pair<std::string, std::string>("Ograve", "#210"));
    theCodeMap.insert(std::pair<std::string, std::string>("Omega", "#937"));
    theCodeMap.insert(std::pair<std::string, std::string>("Omicron", "#927"));
    theCodeMap.insert(std::pair<std::string, std::string>("Oslash", "#216"));
    theCodeMap.insert(std::pair<std::string, std::string>("Otilde", "#213"));
    theCodeMap.insert(std::pair<std::string, std::string>("Ouml", "#214"));
    theCodeMap.insert(std::pair<std::string, std::string>("Phi", "#934"));
    theCodeMap.insert(std::pair<std::string, std::string>("Pi", "#928"));
    theCodeMap.insert(std::pair<std::string, std::string>("Prime", "#8243"));
    theCodeMap.insert(std::pair<std::string, std::string>("Psi", "#936"));
    theCodeMap.insert(std::pair<std::string, std::string>("Rho", "#929"));
    theCodeMap.insert(std::pair<std::string, std::string>("Scaron", "#352"));
    theCodeMap.insert(std::pair<std::string, std::string>("Sigma", "#931"));
    theCodeMap.insert(std::pair<std::string, std::string>("THORN", "#222"));
    theCodeMap.insert(std::pair<std::string, std::string>("Tau", "#932"));
    theCodeMap.insert(std::pair<std::string, std::string>("Theta", "#920"));
    theCodeMap.insert(std::pair<std::string, std::string>("Uacute", "#218"));
    theCodeMap.insert(std::pair<std::string, std::string>("Ucirc", "#219"));
    theCodeMap.insert(std::pair<std::string, std::string>("Ugrave", "#217"));
    theCodeMap.insert(std::pair<std::string, std::string>("Upsilon", "#933"));
    theCodeMap.insert(std::pair<std::string, std::string>("Uuml", "#220"));
    theCodeMap.insert(std::pair<std::string, std::string>("Xi", "#926"));
    theCodeMap.insert(std::pair<std::string, std::string>("Yacute", "#221"));
    theCodeMap.insert(std::pair<std::string, std::string>("Yuml", "#376"));
    theCodeMap.insert(std::pair<std::string, std::string>("Zeta", "#918"));
    theCodeMap.insert(std::pair<std::string, std::string>("aacute", "#225"));
    theCodeMap.insert(std::pair<std::string, std::string>("acirc", "#226"));
    theCodeMap.insert(std::pair<std::string, std::string>("acute", "#180"));
    theCodeMap.insert(std::pair<std::string, std::string>("aelig", "#230"));
    theCodeMap.insert(std::pair<std::string, std::string>("agrave", "#224"));
    theCodeMap.insert(std::pair<std::string, std::string>("alefsym", "#8501"));
    theCodeMap.insert(std::pair<std::string, std::string>("alpha", "#945"));
    theCodeMap.insert(std::pair<std::string, std::string>("amp", "#38;#38"));
    theCodeMap.insert(std::pair<std::string, std::string>("and", "#8743"));
    theCodeMap.insert(std::pair<std::string, std::string>("ang", "#8736"));
    theCodeMap.insert(std::pair<std::string, std::string>("apos", "#39"));
    theCodeMap.insert(std::pair<std::string, std::string>("aring", "#229"));
    theCodeMap.insert(std::pair<std::string, std::string>("asymp", "#8776"));
    theCodeMap.insert(std::pair<std::string, std::string>("atilde", "#227"));
    theCodeMap.insert(std::pair<std::string, std::string>("auml", "#228"));
    theCodeMap.insert(std::pair<std::string, std::string>("bdquo", "#8222"));
    theCodeMap.insert(std::pair<std::string, std::string>("beta", "#946"));
    theCodeMap.insert(std::pair<std::string, std::string>("brvbar", "#166"));
    theCodeMap.insert(std::pair<std::string, std::string>("bull", "#8226"));
    theCodeMap.insert(std::pair<std::string, std::string>("cap", "#8745"));
    theCodeMap.insert(std::pair<std::string, std::string>("ccedil", "#231"));
    theCodeMap.insert(std::pair<std::string, std::string>("cedil", "#184"));
    theCodeMap.insert(std::pair<std::string, std::string>("cent", "#162"));
    theCodeMap.insert(std::pair<std::string, std::string>("chi", "#967"));
    theCodeMap.insert(std::pair<std::string, std::string>("circ", "#710"));
    theCodeMap.insert(std::pair<std::string, std::string>("clubs", "#9827"));
    theCodeMap.insert(std::pair<std::string, std::string>("cong", "#8773"));
    theCodeMap.insert(std::pair<std::string, std::string>("copy", "#169"));
    theCodeMap.insert(std::pair<std::string, std::string>("crarr", "#8629"));
    theCodeMap.insert(std::pair<std::string, std::string>("cup", "#8746"));
    theCodeMap.insert(std::pair<std::string, std::string>("curren", "#164"));
    theCodeMap.insert(std::pair<std::string, std::string>("dArr", "#8659"));
    theCodeMap.insert(std::pair<std::string, std::string>("dagger", "#8224"));
    theCodeMap.insert(std::pair<std::string, std::string>("darr", "#8595"));
    theCodeMap.insert(std::pair<std::string, std::string>("deg", "#176"));
    theCodeMap.insert(std::pair<std::string, std::string>("delta", "#948"));
    theCodeMap.insert(std::pair<std::string, std::string>("diams", "#9830"));
    theCodeMap.insert(std::pair<std::string, std::string>("divide", "#247"));
    theCodeMap.insert(std::pair<std::string, std::string>("eacute", "#233"));
    theCodeMap.insert(std::pair<std::string, std::string>("ecirc", "#234"));
    theCodeMap.insert(std::pair<std::string, std::string>("egrave", "#232"));
    theCodeMap.insert(std::pair<std::string, std::string>("empty", "#8709"));
    theCodeMap.insert(std::pair<std::string, std::string>("emsp", "#8195"));
    theCodeMap.insert(std::pair<std::string, std::string>("ensp", "#8194"));
    theCodeMap.insert(std::pair<std::string, std::string>("epsilon", "#949"));
    theCodeMap.insert(std::pair<std::string, std::string>("equiv", "#8801"));
    theCodeMap.insert(std::pair<std::string, std::string>("eta", "#951"));
    theCodeMap.insert(std::pair<std::string, std::string>("eth", "#240"));
    theCodeMap.insert(std::pair<std::string, std::string>("euml", "#235"));
    theCodeMap.insert(std::pair<std::string, std::string>("euro", "#8364"));
    theCodeMap.insert(std::pair<std::string, std::string>("exist", "#8707"));
    theCodeMap.insert(std::pair<std::string, std::string>("fnof", "#402"));
    theCodeMap.insert(std::pair<std::string, std::string>("forall", "#8704"));
    theCodeMap.insert(std::pair<std::string, std::string>("frac12", "#189"));
    theCodeMap.insert(std::pair<std::string, std::string>("frac14", "#188"));
    theCodeMap.insert(std::pair<std::string, std::string>("frac34", "#190"));
    theCodeMap.insert(std::pair<std::string, std::string>("frasl", "#8260"));
    theCodeMap.insert(std::pair<std::string, std::string>("gamma", "#947"));
    theCodeMap.insert(std::pair<std::string, std::string>("ge", "#8805"));
    theCodeMap.insert(std::pair<std::string, std::string>("gt", "#62"));
    theCodeMap.insert(std::pair<std::string, std::string>("hArr", "#8660"));
    theCodeMap.insert(std::pair<std::string, std::string>("harr", "#8596"));
    theCodeMap.insert(std::pair<std::string, std::string>("hearts", "#9829"));
    theCodeMap.insert(std::pair<std::string, std::string>("hellip", "#8230"));
    theCodeMap.insert(std::pair<std::string, std::string>("iacute", "#237"));
    theCodeMap.insert(std::pair<std::string, std::string>("icirc", "#238"));
    theCodeMap.insert(std::pair<std::string, std::string>("iexcl", "#161"));
    theCodeMap.insert(std::pair<std::string, std::string>("igrave", "#236"));
    theCodeMap.insert(std::pair<std::string, std::string>("image", "#8465"));
    theCodeMap.insert(std::pair<std::string, std::string>("infin", "#8734"));
    theCodeMap.insert(std::pair<std::string, std::string>("int", "#8747"));
    theCodeMap.insert(std::pair<std::string, std::string>("iota", "#953"));
    theCodeMap.insert(std::pair<std::string, std::string>("iquest", "#191"));
    theCodeMap.insert(std::pair<std::string, std::string>("isin", "#8712"));
    theCodeMap.insert(std::pair<std::string, std::string>("iuml", "#239"));
    theCodeMap.insert(std::pair<std::string, std::string>("kappa", "#954"));
    theCodeMap.insert(std::pair<std::string, std::string>("lArr", "#8656"));
    theCodeMap.insert(std::pair<std::string, std::string>("lambda", "#955"));
    theCodeMap.insert(std::pair<std::string, std::string>("lang", "#9001"));
    theCodeMap.insert(std::pair<std::string, std::string>("laquo", "#171"));
    theCodeMap.insert(std::pair<std::string, std::string>("larr", "#8592"));
    theCodeMap.insert(std::pair<std::string, std::string>("lceil", "#8968"));
    theCodeMap.insert(std::pair<std::string, std::string>("ldquo", "#8220"));
    theCodeMap.insert(std::pair<std::string, std::string>("le", "#8804"));
    theCodeMap.insert(std::pair<std::string, std::string>("lfloor", "#8970"));
    theCodeMap.insert(std::pair<std::string, std::string>("lowast", "#8727"));
    theCodeMap.insert(std::pair<std::string, std::string>("loz", "#9674"));
    theCodeMap.insert(std::pair<std::string, std::string>("lrm", "#8206"));
    theCodeMap.insert(std::pair<std::string, std::string>("lsaquo", "#8249"));
    theCodeMap.insert(std::pair<std::string, std::string>("lsquo", "#8216"));
    theCodeMap.insert(std::pair<std::string, std::string>("lt", "#38;#60"));
    theCodeMap.insert(std::pair<std::string, std::string>("macr", "#175"));
    theCodeMap.insert(std::pair<std::string, std::string>("mdash", "#8212"));
    theCodeMap.insert(std::pair<std::string, std::string>("micro", "#181"));
    theCodeMap.insert(std::pair<std::string, std::string>("middot", "#183"));
    theCodeMap.insert(std::pair<std::string, std::string>("minus", "#8722"));
    theCodeMap.insert(std::pair<std::string, std::string>("mu", "#956"));
    theCodeMap.insert(std::pair<std::string, std::string>("nabla", "#8711"));
    theCodeMap.insert(std::pair<std::string, std::string>("nbsp", "#160"));
    theCodeMap.insert(std::pair<std::string, std::string>("ndash", "#8211"));
    theCodeMap.insert(std::pair<std::string, std::string>("ne", "#8800"));
    theCodeMap.insert(std::pair<std::string, std::string>("ni", "#8715"));
    theCodeMap.insert(std::pair<std::string, std::string>("not", "#172"));
    theCodeMap.insert(std::pair<std::string, std::string>("notin", "#8713"));
    theCodeMap.insert(std::pair<std::string, std::string>("nsub", "#8836"));
    theCodeMap.insert(std::pair<std::string, std::string>("ntilde", "#241"));
    theCodeMap.insert(std::pair<std::string, std::string>("nu", "#957"));
    theCodeMap.insert(std::pair<std::string, std::string>("oacute", "#243"));
    theCodeMap.insert(std::pair<std::string, std::string>("ocirc", "#244"));
    theCodeMap.insert(std::pair<std::string, std::string>("oelig", "#339"));
    theCodeMap.insert(std::pair<std::string, std::string>("ograve", "#242"));
    theCodeMap.insert(std::pair<std::string, std::string>("oline", "#8254"));
    theCodeMap.insert(std::pair<std::string, std::string>("omega", "#969"));
    theCodeMap.insert(std::pair<std::string, std::string>("omicron", "#959"));
    theCodeMap.insert(std::pair<std::string, std::string>("oplus", "#8853"));
    theCodeMap.insert(std::pair<std::string, std::string>("or", "#8744"));
    theCodeMap.insert(std::pair<std::string, std::string>("ordf", "#170"));
    theCodeMap.insert(std::pair<std::string, std::string>("ordm", "#186"));
    theCodeMap.insert(std::pair<std::string, std::string>("oslash", "#248"));
    theCodeMap.insert(std::pair<std::string, std::string>("otilde", "#245"));
    theCodeMap.insert(std::pair<std::string, std::string>("otimes", "#8855"));
    theCodeMap.insert(std::pair<std::string, std::string>("ouml", "#246"));
    theCodeMap.insert(std::pair<std::string, std::string>("para", "#182"));
    theCodeMap.insert(std::pair<std::string, std::string>("part", "#8706"));
    theCodeMap.insert(std::pair<std::string, std::string>("permil", "#8240"));
    theCodeMap.insert(std::pair<std::string, std::string>("perp", "#8869"));
    theCodeMap.insert(std::pair<std::string, std::string>("phi", "#966"));
    theCodeMap.insert(std::pair<std::string, std::string>("pi", "#960"));
    theCodeMap.insert(std::pair<std::string, std::string>("piv", "#982"));
    theCodeMap.insert(std::pair<std::string, std::string>("plusmn", "#177"));
    theCodeMap.insert(std::pair<std::string, std::string>("pound", "#163"));
    theCodeMap.insert(std::pair<std::string, std::string>("prime", "#8242"));
    theCodeMap.insert(std::pair<std::string, std::string>("prod", "#8719"));
    theCodeMap.insert(std::pair<std::string, std::string>("prop", "#8733"));
    theCodeMap.insert(std::pair<std::string, std::string>("psi", "#968"));
    theCodeMap.insert(std::pair<std::string, std::string>("quot", "#34"));
    theCodeMap.insert(std::pair<std::string, std::string>("rArr", "#8658"));
    theCodeMap.insert(std::pair<std::string, std::string>("radic", "#8730"));
    theCodeMap.insert(std::pair<std::string, std::string>("rang", "#9002"));
    theCodeMap.insert(std::pair<std::string, std::string>("raquo", "#187"));
    theCodeMap.insert(std::pair<std::string, std::string>("rarr", "#8594"));
    theCodeMap.insert(std::pair<std::string, std::string>("rceil", "#8969"));
    theCodeMap.insert(std::pair<std::string, std::string>("rdquo", "#8221"));
    theCodeMap.insert(std::pair<std::string, std::string>("real", "#8476"));
    theCodeMap.insert(std::pair<std::string, std::string>("reg", "#174"));
    theCodeMap.insert(std::pair<std::string, std::string>("rfloor", "#8971"));
    theCodeMap.insert(std::pair<std::string, std::string>("rho", "#961"));
    theCodeMap.insert(std::pair<std::string, std::string>("rlm", "#8207"));
    theCodeMap.insert(std::pair<std::string, std::string>("rsaquo", "#8250"));
    theCodeMap.insert(std::pair<std::string, std::string>("rsquo", "#8217"));
    theCodeMap.insert(std::pair<std::string, std::string>("sbquo", "#8218"));
    theCodeMap.insert(std::pair<std::string, std::string>("scaron", "#353,"));
    theCodeMap.insert(std::pair<std::string, std::string>("sdot", "#8901"));
    theCodeMap.insert(std::pair<std::string, std::string>("sect", "#167"));
    theCodeMap.insert(std::pair<std::string, std::string>("shy", "#173"));
    theCodeMap.insert(std::pair<std::string, std::string>("sigma", "#963"));
    theCodeMap.insert(std::pair<std::string, std::string>("sigmaf", "#962"));
    theCodeMap.insert(std::pair<std::string, std::string>("sim", "#8764"));
    theCodeMap.insert(std::pair<std::string, std::string>("spades", "#9824"));
    theCodeMap.insert(std::pair<std::string, std::string>("sub", "#8834"));
    theCodeMap.insert(std::pair<std::string, std::string>("sube", "#8838"));
    theCodeMap.insert(std::pair<std::string, std::string>("sum", "#8721"));
    theCodeMap.insert(std::pair<std::string, std::string>("sup", "#8835"));
    theCodeMap.insert(std::pair<std::string, std::string>("sup1", "#185"));
    theCodeMap.insert(std::pair<std::string, std::string>("sup2", "#178"));
    theCodeMap.insert(std::pair<std::string, std::string>("sup3", "#179"));
    theCodeMap.insert(std::pair<std::string, std::string>("supe", "#8839"));
    theCodeMap.insert(std::pair<std::string, std::string>("szlig", "#223"));
    theCodeMap.insert(std::pair<std::string, std::string>("tau", "#964"));
    theCodeMap.insert(std::pair<std::string, std::string>("there4", "#8756"));
    theCodeMap.insert(std::pair<std::string, std::string>("theta", "#952"));
    theCodeMap.insert(std::pair<std::string, std::string>("thetasym", "#977"));
    theCodeMap.insert(std::pair<std::string, std::string>("thinsp", "#8201"));
    theCodeMap.insert(std::pair<std::string, std::string>("thorn", "#254"));
    theCodeMap.insert(std::pair<std::string, std::string>("tilde", "#732"));
    theCodeMap.insert(std::pair<std::string, std::string>("times", "#215"));
    theCodeMap.insert(std::pair<std::string, std::string>("trade", "#8482"));
    theCodeMap.insert(std::pair<std::string, std::string>("uArr", "#8657"));
    theCodeMap.insert(std::pair<std::string, std::string>("uacute", "#250"));
    theCodeMap.insert(std::pair<std::string, std::string>("uarr", "#8593"));
    theCodeMap.insert(std::pair<std::string, std::string>("ucirc", "#251"));
    theCodeMap.insert(std::pair<std::string, std::string>("ugrave", "#249"));
    theCodeMap.insert(std::pair<std::string, std::string>("uml", "#168"));
    theCodeMap.insert(std::pair<std::string, std::string>("upsih", "#978"));
    theCodeMap.insert(std::pair<std::string, std::string>("upsilon", "#965"));
    theCodeMap.insert(std::pair<std::string, std::string>("uuml", "#252"));
    theCodeMap.insert(std::pair<std::string, std::string>("weierp", "#8472"));
    theCodeMap.insert(std::pair<std::string, std::string>("xi", "#958"));
    theCodeMap.insert(std::pair<std::string, std::string>("yacute", "#253"));
    theCodeMap.insert(std::pair<std::string, std::string>("yen", "#165"));
    theCodeMap.insert(std::pair<std::string, std::string>("yuml", "#255"));
    theCodeMap.insert(std::pair<std::string, std::string>("zeta", "#950"));
    theCodeMap.insert(std::pair<std::string, std::string>("zwj", "#8205"));
    theCodeMap.insert(std::pair<std::string, std::string>("zwnj", "#8204"));
  }
}}
