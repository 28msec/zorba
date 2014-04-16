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
#include <zorba/zorba.h>
#include <zorba/external_module.h>
#include <zorba/function.h>

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

class HttpSendFunction : public ContextualExternalFunction {
protected:
  const ExternalModule*     theModule;
  ItemFactory*              theFactory;

public:
  HttpSendFunction(const ExternalModule* aModule)
: theModule(aModule),
  theFactory(Zorba::getInstance(0)->getItemFactory()) {}

  virtual ~HttpSendFunction() {}

public:
  virtual String
  getURI() const { return theModule->getURI(); }

  virtual String
  getLocalName() const { return "http-sequential-impl"; }

  virtual ItemSequence_t
  evaluate(const ExternalFunction::Arguments_t& args,
      const StaticContext* aStaticContext, const DynamicContext* aDynamicContext)
  const;

  int do_request(Request& aRequest, ItemSequence_t& aResult) const;
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
