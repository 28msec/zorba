/*
 * Copyright 2006-2013 The FLWOR Foundation.
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
#include <map>
#include <memory>
#include "zorba/zorba.h"
#include "zorba/external_module.h"
#include "zorba/function.h"
#include "zorba/util/timer.h"

#include "structures.h"
#include "http_request_handler.h"

#ifdef WIN32
# include <Windows.h>
# define MAX_BUF_SIZE 2048
#endif

namespace zorba
{

namespace http_client
{

class HttpClientModule : public ExternalModule {
protected:
  class ltstr
  {
  public:
    bool operator()(const String& s1, const String& s2) const
    {
      return s1.compare(s2) < 0;
    }
  };

  typedef std::map<String, ExternalFunction*, ltstr> FuncMap_t;

  FuncMap_t theFunctions;

public:
  virtual ~HttpClientModule()
  {
    for (FuncMap_t::const_iterator lIter = theFunctions.begin();
        lIter != theFunctions.end(); ++lIter)
    {
      delete lIter->second;
    }
    theFunctions.clear();
  }

  HttpClientModule() : theModuleUri("http://zorba.io/modules/http-client")
  {
    for (FuncMap_t::const_iterator lIter = theFunctions.begin();
        lIter != theFunctions.end(); ++lIter)
    {
      delete lIter->second;
    }
    theFunctions.clear();
  }

  virtual String
  getURI() const { return theModuleUri; }

  virtual ExternalFunction*
  getExternalFunction(const String& aLocalname);

  virtual void
  destroy()
  {
    if (!dynamic_cast<HttpClientModule*>(this))
      return;
    delete this;
  }

private:
  String theModuleUri;
};

class ProfileWrapper
{
  bool                               theProfilingEnabled;
  Zorba_profile_format_t             theProfileFormat;
  zorba::time::cpu::timer            theCPUTimer;
  zorba::time::wall::timer           theWallTimer;
  Request&                           theRequest;
  std::auto_ptr<std::vector<Item> >& theJSONProfileData;
  zorba::Item&                       theXMLProfileData;

public:
  ProfileWrapper(Request& aRequest, std::auto_ptr<std::vector<Item> >& aProfileData, zorba::Item& aXMLProfileData):
    theProfilingEnabled(zorba::Properties::instance().getCollectProfile()),
    theProfileFormat(zorba::Properties::instance().getProfileFormat()),
    theRequest(aRequest),
    theJSONProfileData(aProfileData),
    theXMLProfileData(aXMLProfileData)
  {
    if (theProfilingEnabled)
    {
      theCPUTimer.start();
      theWallTimer.start();
    }
  }

  void jsonProfile()
  {
    double lCPUTime = theCPUTimer.elapsed();
    double lWallTime = theWallTimer.elapsed();

    zorba::ItemFactory* lFactory = Zorba::getInstance(0)->getItemFactory();

    zorba::Item lRequestField = lFactory->createString("prof-request");
    zorba::Item lRequestValue = lFactory->createString(theRequest.theMethod + " " + theRequest.theHref);
    zorba::Item lRequestBodySizeField = lFactory->createString("prof-request-body-size");
    zorba::Item lRequestBodySizeValue = lFactory->createInteger(theRequest.getBodySize());

    zorba::Item lCPUField = lFactory->createString("prof-cpu");
    zorba::Item lCPUValue = lFactory->createDouble(lCPUTime);
    zorba::Item lWallField = lFactory->createString("prof-wall");
    zorba::Item lWallValue = lFactory->createDouble(lWallTime);

    std::vector<std::pair<zorba::Item, zorba::Item> >  lPairs;
    lPairs.push_back(std::pair<zorba::Item, zorba::Item>(lRequestField, lRequestValue));
    lPairs.push_back(std::pair<zorba::Item, zorba::Item>(lRequestBodySizeField, lRequestBodySizeValue));
    lPairs.push_back(std::pair<zorba::Item, zorba::Item>(lCPUField, lCPUValue));
    lPairs.push_back(std::pair<zorba::Item, zorba::Item>(lWallField, lWallValue));

    zorba::Item lProfile = lFactory->createJSONObject(lPairs);
    if (!theJSONProfileData.get())
      theJSONProfileData.reset(new std::vector<Item>());

    theJSONProfileData->push_back(lProfile);
  }

  void xmlProfile()
  {
    double lCPUTime = theCPUTimer.elapsed();
    double lWallTime = theWallTimer.elapsed();

    zorba::ItemFactory* lFactory = Zorba::getInstance(0)->getItemFactory();
    std::vector<std::pair<zorba::String, zorba::String> > lNSBindings;
    zorba::Item lNullItem;
    zorba::Item lTypeName = lFactory->createQName("http://www.w3.org/2001/XMLSchema", "untyped");

    if (theXMLProfileData.isNull())
    {
      theXMLProfileData = lFactory->createElementNode(lNullItem,
                                                      lFactory->createQName("", "", "prof-requests"),
                                                      lTypeName,
                                                      false,
                                                      false,
                                                      lNSBindings);
    }


    zorba::Item lRequestElem = lFactory->createElementNode(theXMLProfileData,
                                                           lFactory->createQName("", "", "prof-request"),
                                                           lTypeName,
                                                           false,
                                                           false,
                                                           lNSBindings);
    lFactory->createAttributeNode(lRequestElem,
                                  lFactory->createQName("", "", "prof-uri"),
                                  lTypeName,
                                  lFactory->createString(theRequest.theMethod + " " + theRequest.theHref));

    lFactory->createAttributeNode(lRequestElem,
                                  lFactory->createQName("", "", "prof-request-body-size"),
                                  lTypeName,
                                  lFactory->createInteger(theRequest.getBodySize()));

    lFactory->createAttributeNode(lRequestElem,
                                  lFactory->createQName("", "", "prof-cpu"),
                                  lTypeName,
                                  lFactory->createDouble(lCPUTime));

    lFactory->createAttributeNode(lRequestElem,
                                  lFactory->createQName("", "", "prof-wall"),
                                  lTypeName,
                                  lFactory->createDouble(lWallTime));
  }

  ~ProfileWrapper()
  {
    if (theProfilingEnabled)
    {
      switch (theProfileFormat)
      {
        case PROFILE_FORMAT_DOT:
        case PROFILE_FORMAT_NONE:
          break;
        case PROFILE_FORMAT_JSON:
          jsonProfile();
          break;
        case PROFILE_FORMAT_XML:
          xmlProfile();
          break;
      }
    }
  }
};

class HttpSendFunction : public ContextualExternalFunction {
protected:
  const ExternalModule*                        theModule;
  ItemFactory*                                 theFactory;

  mutable std::auto_ptr<std::vector<Item> >    theJSONProfileData;
  mutable Item                                 theXMLProfileData;
  mutable std::auto_ptr<ProfileDataMap>        theProfileMap;

public:
  HttpSendFunction(const ExternalModule* aModule)
: theModule(aModule),
  theFactory(Zorba::getInstance(0)->getItemFactory()) {}

  virtual ~HttpSendFunction() {}

  virtual String
  getURI() const { return theModule->getURI(); }

  virtual String
  getLocalName() const { return "http-sequential-impl"; }

  virtual ItemSequence_t
  evaluate(const ExternalFunction::Arguments_t& args,
      const StaticContext* aStaticContext, const DynamicContext* aDynamicContext)
  const;

  int doRequest(Request& aRequest, ItemSequence_t& aResult) const;

  zorba::ProfileDataMap*
  getProfilingData() const
  {
    if (zorba::Properties::instance().getCollectProfile())
    {
      switch (zorba::Properties::instance().getProfileFormat())
      {
        case PROFILE_FORMAT_DOT:
        case PROFILE_FORMAT_NONE:
          return NULL;
        case PROFILE_FORMAT_JSON:
          return getJSONProfilingData();
        case PROFILE_FORMAT_XML:
          return getXMLProfilingData();
      }
    }
    return NULL;
  }
private:
  zorba::ProfileDataMap*
  getJSONProfilingData() const
  {
    if (!theJSONProfileData.get())
      theJSONProfileData.reset(new std::vector<Item>);

    theProfileMap.reset(new ProfileDataMap());
    (*theProfileMap)["prof-requests"] = theFactory->createJSONArray(*theJSONProfileData);
    return theProfileMap.get();
  }

  zorba::ProfileDataMap*
  getXMLProfilingData() const
  {
    if (theXMLProfileData.isNull())
    {
      zorba::Item lNullItem;
      theXMLProfileData = theFactory->createElementNode(lNullItem,
                                                        theFactory->createQName("","","prof-requests"),
                                                        theFactory->createQName("http://www.w3.org/2001/XMLSchema", "untyped"),
                                                        false,
                                                        false,
                                                        std::vector<std::pair<zorba::String, zorba::String> >());
    }

    theProfileMap.reset(new ProfileDataMap());
    (*theProfileMap)["prof-requests"] = theXMLProfileData;
    return theProfileMap.get();
  }
};

class HttpNondeterministicFunction : public HttpSendFunction {
public:
  HttpNondeterministicFunction(const ExternalModule* aModule)
: HttpSendFunction(aModule) {}

  virtual ~HttpNondeterministicFunction() {}

public:
  virtual String
  getLocalName() const { return "http-nondeterministic-impl"; }

};

class HttpDeterministicFunction : public HttpSendFunction {
public:
  HttpDeterministicFunction(const ExternalModule* aModule)
: HttpSendFunction(aModule) {}

  virtual ~HttpDeterministicFunction() {}

public:
  virtual String
  getLocalName() const { return "http-deterministic-impl"; }

};

} // namespace http_request
} // namespace zorba

#ifdef WIN32
#  define DLL_EXPORT __declspec(dllexport)
#else
#  define DLL_EXPORT __attribute__ ((visibility("default")))
#endif

extern "C" DLL_EXPORT zorba::ExternalModule* createModule() {
  return new zorba::http_client::HttpClientModule();
}
