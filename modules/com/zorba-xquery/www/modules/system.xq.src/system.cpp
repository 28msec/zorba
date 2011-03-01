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
#include <cstdio>
#include <sstream>

#ifdef WIN32
# include <Windows.h>
#else
# include <sys/utsname.h>
#endif

#include <zorba/zorbastring.h>
#include <zorba/singleton_item_sequence.h>
#include <zorba/vector_item_sequence.h>
#include <zorba/empty_sequence.h>
#include <zorba/item_factory.h>


#ifdef LINUX
extern char** environ;
#elif defined APPLE
# include <crt_externs.h>
#endif

#include "system.h"

namespace zorba { namespace system {

  const String SystemModule::SYSTEM_MODULE_NAMESPACE = "http://www.zorba-xquery.com/modules/system";

#ifdef LINUX

  static void trim(std::string& str, char delim)
  {
    std::string::size_type pos = str.find_last_not_of(delim);
    if(pos != std::string::npos) {
      str.erase(pos + 1);
      pos = str.find_first_not_of(delim);
      if(pos != std::string::npos) str.erase(0, pos);
    }
    else str.erase(str.begin(), str.end());
  }


  static std::pair<std::string, std::string> getDistribution() {
    std::pair<std::string, std::string> lRes;
    FILE *pipe;
    const char* command = "lsb_release -r -i";
    pipe = (FILE*) popen(command, "r");

    char line[1024];
    while (fgets(line, sizeof(line), pipe)) {
      std::stringstream s(line);
      std::string name, value;
      getline(s, name, ':');
      trim(name, ' ');
      trim(name, '\t');
      getline(s, value, ':');
      trim(value, ' ');
      trim(value, '\t');
      trim(value, '\n');
      if (name == "Distributor ID") {
        lRes.first = value;
      } else {
        lRes.second = value;
      }
    }
    return lRes;
  }
#endif

  SystemModule::SystemModule()
    : thePropertyFunction(0), thePropertiesFunction(0)
  {
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

  void SystemModule::destroy() {
    delete this;
  }

  SystemModule::~SystemModule() {
    delete thePropertyFunction;
    delete thePropertiesFunction;
  }

  SystemFunction::SystemFunction(const ExternalModule* aModule)
    : theModule(aModule), theFactory(Zorba::getInstance(0)->getItemFactory())
  {
#ifdef WIN32
    theProperties.insert(std::make_pair("os.name", "Windows"));
    {
      DWORD nodeNameLength = MAX_COMPUTERNAME_LENGTH + 1;
      TCHAR nodeName[MAX_COMPUTERNAME_LENGTH + 1];
      char nodeNameC[MAX_COMPUTERNAME_LENGTH + 1];
      GetComputerName(nodeName, &nodeNameLength);
      for (DWORD i = 0; i < nodeNameLength; ++i) {
        nodeNameC[i] = nodeName[i];
      }
      theProperties.insert(std::make_pair("os.node.name", nodeNameC));
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
      DWORD userNameLength = 1023;
      TCHAR userName[1024];
      char userNameC[1024];
      GetUserName(userName, &userNameLength);
      for (DWORD i = 0; i < userNameLength; ++i) {
        userNameC[i] = userName[i];
      }
      theProperties.insert(std::make_pair("user.name", userNameC));
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
#endif
#ifdef LINUX
    theProperties.insert(std::make_pair("linux.distributor", ""));
    theProperties.insert(std::make_pair("linux.distributor.version", ""));
#endif
    theProperties.insert(std::make_pair("zorba.version", Zorba::version().getVersion()));
    theProperties.insert(std::make_pair("zorba.version.major", intToString(Zorba::version().getMajorVersion())));
    theProperties.insert(std::make_pair("zorba.version.minor", intToString(Zorba::version().getMinorVersion())));
    theProperties.insert(std::make_pair("zorba.version.patch", intToString(Zorba::version().getPatchVersion())));
  }

  String SystemFunction::intToString(int v) {
    std::stringstream ss;
    ss << v;
    return ss.str();
  }

  bool SystemFunction::getEnv(const String& name, String& value) const
  {
    char* v = getenv(name.c_str());
    if (v == NULL) return false;
    value = v;
    return true;
  }

  void SystemFunction::getEnvNames(std::vector<Item>& names) const
  {
#ifdef WIN32
    // put in the environment variables
    TCHAR *l_EnvStr;
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
      char lStr[1024];
      memset(lStr, 0, 1024);
      for (int i =0; i<1023 && l_EnvStr[i]; ++i) {
        lStr[i] = (char) l_EnvStr[i];
      }
      std::string e(lStr);
      std::string name("env.");
      name += e.substr(0, e.find('='));
      String value = e.substr(e.find('=') + 1);
      names.push_back(theFactory->createString(value));
      while(*l_EnvStr != '\0')
        l_EnvStr++;
      l_EnvStr++;
    }
    //FreeEnvironmentStrings(l_EnvStr);
#else
# ifdef APPLE
    char** environ = *_NSGetEnviron();
# endif // APPLE
    for (int i = 0; environ[i] != NULL; ++i) {
      std::string e(environ[i]);
      String name("env.");
      name += e.substr(0, e.find('='));
      names.push_back(theFactory->createString(name));
    }
#endif
  }

  ItemSequence_t PropertiesFunction::evaluate(
      const StatelessExternalFunction::Arguments_t& args) const {
    std::vector<Item> lRes;
    getEnvNames(lRes);
    for (std::map<String, String>::const_iterator i = theProperties.begin();
        i != theProperties.end(); ++i) {
      Item lItem = theFactory->createString(i->first.c_str());
      lRes.push_back(lItem);
    }
    // insert the zorba module path
    lRes.push_back(theFactory->createString("zorba.module.path"));
    return ItemSequence_t(new VectorItemSequence(lRes));
  }

  ItemSequence_t PropertyFunction::evaluate(
      const StatelessExternalFunction::Arguments_t& args,
      const StaticContext* sctx,
      const DynamicContext* dctx) const {
    Item item;
    Iterator_t arg0_iter = args[0]->getIterator();
    arg0_iter->open();
    arg0_iter->next(item);
    arg0_iter->close();
    String envS = item.getStringValue();
    String lRes;
    if (envS == "zorba.module.path") {
      std::vector<String> lModulePaths;
      sctx->getFullModulePaths(lModulePaths);
      if (lModulePaths.size() == 0)
        return ItemSequence_t(new SingletonItemSequence(theFactory->createString("")));
      lRes = lModulePaths[0];
      for (std::vector<String>::iterator i = lModulePaths.begin() + 1; i != lModulePaths.end(); ++i) {
#ifdef WIN32
        lRes += ";";
#else
        lRes += ":";
#endif
        lRes += *i;
      }
    } else if (envS.startsWith("env.")) { 
      if (!getEnv(envS.substring(4), lRes)) {
        return ItemSequence_t(new EmptySequence());
      }
#ifdef LINUX
    } else if (envS == "linux.distributor") {
      lRes = getDistribution().first;
    } else if (envS == "linux.distributor.version") {
      lRes = getDistribution().second;
#endif
    } else {
      std::map<String, String>::const_iterator i;
      if ((i = theProperties.find(envS.c_str())) != theProperties.end()) {
        lRes = i->second;
      } else {
        return ItemSequence_t(new EmptySequence());
      }
    }
    return ItemSequence_t(new SingletonItemSequence(theFactory->createString(lRes)));
  }
}} // namespace zorba, system

