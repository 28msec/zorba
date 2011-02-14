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
#include <map>

#ifdef WIN32
# include <Windows.h>
#else
# include <sys/utsname.h>
#endif
#ifdef APPLE
# include <crt_externs.h>
#endif

#include <zorba/zorba.h>
#include <zorba/zorbastring.h>
#include <zorba/external_module.h>
#include <zorba/external_function.h>
#include <zorba/singleton_item_sequence.h>
#include <zorba/vector_item_sequence.h>
#include <zorba/empty_sequence.h>
#include <zorba/item_factory.h>

#define SYSTEM_MODULE_NAMESPACE "http://www.zorba-xquery.com/modules/system"

#ifdef LINUX
extern char** environ;
#endif

namespace zorba { namespace system {
  class SystemModule : public ExternalModule {
    private:
      StatelessExternalFunction* thePropertyFunction;
      StatelessExternalFunction* thePropertiesFunction;
    public:
      SystemModule() : thePropertyFunction(0), thePropertiesFunction(0) {}
      virtual ~SystemModule();
    public:
      virtual String getURI() const { return SYSTEM_MODULE_NAMESPACE; }

      virtual StatelessExternalFunction* getExternalFunction(const String& localName);

      virtual void destroy() {
        delete this;
      }
  };

  class SystemFunction : public PureStatelessExternalFunction {
    protected:
      ItemFactory* theFactory;
      std::map<std::string, std::string> theProperties;
    public:
      SystemFunction() : theFactory(Zorba::getInstance(0)->getItemFactory()) {
#ifdef WIN32
        theProperties.insert(std::make_pair("os.name", "Windows"));
        {
          long nodeNameLength = MAX_COMPUTERNAME_LENGTH + 1;
          char nodeName[nodeNameLength];
          GetComputerName(nodeName, nodeNameLength);
          theProperties.insert(std::make_pair("os.node.name", nodeName));
        }
        {
          DWORD dwVersion = 0; 
          DWORD dwMajorVersion = 0;
          DWORD dwMinorVersion = 0; 
          DWORD dwBuild = 0;

          dwVersion = GetVersion();

          // Get the Windows version.

          dwMajorVersion = (DWORD)(LOBYTE(LOWORD(dwVersion)));
          dwMinorVersion = (DWORD)(HIBYTE(LOWORD(dwVersion)));

          // Get the build number.

          if (dwVersion < 0x80000000)              
            dwBuild = (DWORD)(HIWORD(dwVersion));

          std::string major;
          std::string minor;
          std::string build;
          {
            std::stringstream sMajor;
            sMajor << dwMajorVersion;
            std::stringstream sMinor;
            sMajor << dwMinorVersion;
            std::stringstream sBuild;
            sMajor << dwBuild;

            major = sMajor.str();
            minor = sMinor.str();
            build = sBuild.str();
          }
          theProperties.insert(std::make_pair("os.version.major", major));
          theProperties.insert(std::make_pair("os.version.minor", minor));
          theProperties.insert(std::make_pair("os.version.build", build));
          theProperties.insert(std::make_pair("os.version", major + "." + minor + "." + build));
        }
        {
          long userNameLength = MAX_COMPUTERNAME_LENGTH + 1;
          char userName[nodeNameLength];
          GetUserName(nodeName, nodeNameLength);
          theProperties.insert(std::make_pair("user.name", userName));
        }
        {
          SYSTEM_INFO info;
          GetSystemInfo(&info);
          if (info.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64) {
            theProperties.insert(std::make_pair("os.arch", "x86_64"));
          } else if (info.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_IA64) {
            theProperties.insert(std::make_pair("os.arch", "ia64"));
          } else if (info.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_INTEL) {
            theProperties.insert(std::make_pair("os.arch", "i386"));
          }
        }
        {
          // put in the environment variables
          char *l_EnvStr;
          l_EnvStr = GetEnvironmentStrings();

          LPTSTR l_str = l_EnvStr;

          int count = 0;
          while (true)
          {
            if (*l_str == 0) break;
            while (*l_str != 0) l_str++;
            l_str++;
            count++;
          }

          for (int i = 0; i < count; i++)
          {
            std::string e(l_EnvStr);
            std::string name("env.");
            name += e.substr(0, e.find('='));
            std::string value = e.substr(e.find('=') + 1);
            theProperties.insert(std::make_pair(name, value));
            while(*l_EnvStr != '\0')
              l_EnvStr++;
            l_EnvStr++;
          }
          FreeEnvironmentStrings(l_EnvStr);
        }
#else
        struct utsname osname;
        uname(&osname);
        theProperties.insert(std::make_pair("os.name", osname.sysname));
        theProperties.insert(std::make_pair("os.node.name", osname.nodename));
        theProperties.insert(std::make_pair("os.version.release", osname.release));
        theProperties.insert(std::make_pair("os.version.version", osname.version));
        theProperties.insert(std::make_pair("os.version", osname.release));
        theProperties.insert(std::make_pair("os.arch", osname.machine));
        theProperties.insert(std::make_pair("user.name", getenv("USER")));
        {
          // put in all environment variables
#ifdef APPLE
          char** environ = *_NSGetEnviron();
#endif // APPLE
          for (int i = 0; environ[i] != NULL; ++i) {
            std::string e(environ[i]);
            std::string name("env.");
            name += e.substr(0, e.find('='));
            std::string value = e.substr(e.find('=') + 1);
            theProperties.insert(std::make_pair(name, value));
          }
        }
#endif
      }
  };

  class PropertiesFunction : public SystemFunction {
    private:
      const ExternalModule* theModule;
    public:
      PropertiesFunction(const ExternalModule* mod) : theModule(mod) {}
      virtual String getURI() const { return theModule->getURI(); }

      virtual String getLocalName() const { return "properties"; }

      virtual ItemSequence_t 
      evaluate(const StatelessExternalFunction::Arguments_t& args) const;
  };

  class PropertyFunction : public SystemFunction {
    private:
      const ExternalModule* theModule;
    public:
      PropertyFunction(const ExternalModule* mod) : theModule(mod) {}
      virtual String getURI() const { return theModule->getURI(); }

      virtual String getLocalName() const { return "property"; }

      virtual ItemSequence_t 
      evaluate(const StatelessExternalFunction::Arguments_t& args) const;
  };

  SystemModule::~SystemModule() {
    delete thePropertyFunction;
    delete thePropertiesFunction;
  }

  StatelessExternalFunction* SystemModule::getExternalFunction(const String& localName) {
    if (localName == "properties") {
      if (!thePropertiesFunction)
        thePropertiesFunction = new PropertiesFunction(this);
      return thePropertiesFunction;
    } else if (localName == "property") {
      if (!thePropertyFunction)
        thePropertyFunction = new PropertyFunction(this);
      return thePropertyFunction;
    }
    return 0;
  }

  ItemSequence_t PropertiesFunction::evaluate(const StatelessExternalFunction::Arguments_t& args) const {
    std::vector<Item> lRes;
    for (std::map<std::string, std::string>::const_iterator i = theProperties.begin(); i != theProperties.end(); ++i) {
      Item lItem = theFactory->createString(i->first.c_str());
      lRes.push_back(lItem);
    }
    return ItemSequence_t(new VectorItemSequence(lRes));
  }

  ItemSequence_t PropertyFunction::evaluate(const StatelessExternalFunction::Arguments_t& args) const {
    Item item;
    Iterator_t arg0_iter = args[0]->getIterator();
    arg0_iter->open();
    arg0_iter->next(item);
    arg0_iter->close();
    String envS = item.getStringValue();
    String lRes;
    std::map<std::string, std::string>::const_iterator i;
    if (envS.startsWith("env.")) {
      String lStr = envS.substring(4);
      lRes = getenv(lStr.c_str());
    } else if ((i = theProperties.find(envS.c_str())) != theProperties.end()) {
      lRes = i->second;
    }
    return ItemSequence_t(new SingletonItemSequence(theFactory->createString(lRes)));
  }
}} // namespace zorba, system

#ifdef WIN32
#  define DLL_EXPORT __declspec(dllexport)
#else
#  define DLL_EXPORT __attribute__ ((visibility("default")))
#endif

extern "C" DLL_EXPORT zorba::ExternalModule* createModule() {
  return new zorba::system::SystemModule();
}
