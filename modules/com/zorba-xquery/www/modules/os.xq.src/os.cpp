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
#include <cstdlib>

#include <zorba/zorba.h>
#include <zorba/zorbastring.h>
#include <zorba/external_module.h>
#include <zorba/external_function.h>
#include <zorba/singleton_item_sequence.h>
#include <zorba/empty_sequence.h>
#include <zorba/item_factory.h>

#define OS_MODULE_NAMESPACE "http://www.zorba-xquery.com/modules/os"

namespace zorba { namespace os {
  class OSModule : public ExternalModule {
    private:
      StatelessExternalFunction* theGetEnvFunction;
      StatelessExternalFunction* theOperatingSystemFunction;
    public:
      OSModule() : theGetEnvFunction(0), theOperatingSystemFunction(0) {}
      virtual ~OSModule();
    public:
      virtual String getURI() const { return OS_MODULE_NAMESPACE; }

      virtual StatelessExternalFunction* getExternalFunction(const String& localName);

      virtual void destroy() {
        delete this;
      }
  };

  class OSFunction : public PureStatelessExternalFunction {
    protected:
      ItemFactory* theFactory;
    public:
      OSFunction() : theFactory(Zorba::getInstance(0)->getItemFactory()) {}
  };

  class GetEnvFunction : public OSFunction {
    private:
      const ExternalModule* theModule;
    public:
      GetEnvFunction(const ExternalModule* mod) : theModule(mod) {}
      virtual String getURI() const { return theModule->getURI(); }

      virtual String getLocalName() const { return "get-env"; }

      virtual ItemSequence_t 
      evaluate(const StatelessExternalFunction::Arguments_t& args) const;
  };

  class OperatingSystemFunction : public OSFunction {
    private:
      const ExternalModule* theModule;
    public:
      OperatingSystemFunction(const ExternalModule* mod) : theModule(mod) {}
      virtual String getURI() const { return theModule->getURI(); }

      virtual String getLocalName() const { return "operating-system"; }

      virtual ItemSequence_t 
      evaluate(const StatelessExternalFunction::Arguments_t& args) const;
  };

  OSModule::~OSModule() {
    delete theGetEnvFunction;
    delete theOperatingSystemFunction;
  }

  StatelessExternalFunction* OSModule::getExternalFunction(const String& localName) {
    if (localName == "get-env") {
      if (!theGetEnvFunction)
        theGetEnvFunction = new GetEnvFunction(this);
      return theGetEnvFunction;
    } else if (localName == "operating-system") {
      if (!theOperatingSystemFunction)
        theOperatingSystemFunction = new OperatingSystemFunction(this);
      return theOperatingSystemFunction;
    }
    return 0;
  }

  ItemSequence_t OperatingSystemFunction::evaluate(const StatelessExternalFunction::Arguments_t& args) const {
#ifdef WIN32
    String lRes = "Windows";
#endif
#ifdef LINUX
    String lRes = "Linux";
#endif
#ifdef APPLE
    String lRes = "Mac OS X";
#endif
    return ItemSequence_t(new SingletonItemSequence(theFactory->createString(lRes)));
  }

  ItemSequence_t GetEnvFunction::evaluate(const StatelessExternalFunction::Arguments_t& args) const {
    Item item;
    args[0]->next(item);
    String envS = item.getStringValue();
    char* envC = getenv(envS.c_str());
    if (envC == 0) {
      return ItemSequence_t(new EmptySequence());
    }
    String lRes = envC;
    return ItemSequence_t(new SingletonItemSequence(theFactory->createString(lRes)));
  }
}} // namespace zorba, os

#ifdef WIN32
#  define DLL_EXPORT __declspec(dllexport)
#else
#  define DLL_EXPORT __attribute__ ((visibility("default")))
#endif

extern "C" DLL_EXPORT zorba::ExternalModule* createModule() {
  return new zorba::os::OSModule();
}
