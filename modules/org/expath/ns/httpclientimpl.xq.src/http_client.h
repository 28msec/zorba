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
#include <map>
#include <zorba/zorba.h>
#include <zorba/serializer.h>
#include <zorba/external_module.h>
#include <zorba/external_function.h>

namespace zorba {
  namespace http_client {

    class HttpSendFunction : public NonePureStatelessExternalFunction {
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
      getLocalName() const { return "http-send-request-impl"; }

      virtual ItemSequence_t 
        evaluate(const StatelessExternalFunction::Arguments_t& args,
        const StaticContext* aStaticContext, const DynamicContext* aDynamicContext)
        const;
    };

    class HttpReadFunction : public HttpSendFunction {
    public:
      HttpReadFunction(const ExternalModule* aModule) 
        : HttpSendFunction(aModule) {}
      
      virtual ~HttpReadFunction() {}

    public:
      virtual String
      getLocalName() const { return "http-read-impl"; }

    }; 

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
      
      typedef std::map<String, StatelessExternalFunction*, ltstr> FuncMap_t;
    
      mutable FuncMap_t theFunctions;

    public:
      virtual ~HttpClientModule();

      HttpClientModule() 
      {
        for (FuncMap_t::const_iterator lIter = theFunctions.begin();
             lIter != theFunctions.end(); ++lIter) {
          delete lIter->second;
        }
        theFunctions.clear();
      }

      virtual String
      getURI() const { return "http://expath.org/ns/httpclientimpl"; }

      virtual StatelessExternalFunction*
      getExternalFunction(String aLocalname) const
      {
        StatelessExternalFunction*& lFunc = theFunctions[aLocalname];
        if (!lFunc) {
          if (aLocalname.equals("http-send-request-impl")) {
            lFunc = new HttpSendFunction(this);
          } else if (aLocalname.equals("http-read-impl")) {
            lFunc = new HttpReadFunction(this);
          } 
        }
        return lFunc;
      }

      virtual void
      destroy()
      {
        if (!dynamic_cast<HttpClientModule*>(this)) {
          return;
        }
        delete this;
      }
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
