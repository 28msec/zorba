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
#ifndef ZORBA_PROPERTIES_BASE_H
#define ZORBA_PROPERTIES_BASE_H

#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <cctype>
#include <zorba/config.h>

namespace zorba {

/***************************************************************************//**

********************************************************************************/
class ZORBA_DLL_PUBLIC PropertiesBase 
{
protected:
  std::vector<std::string> thePositionalArgs;

public:
  virtual ~PropertiesBase() {}

  std::string load_all(
        const char* cfgFilename,
        const std::string& env_pfx,
        int argc,
        const char **argv) 
  {
    std::string result;

    if (! (result = load_env(env_pfx)).empty())
      return result;

    if (! (result = load_file(cfgFilename)).empty())
      return result;

    return load_argv(argc, argv);
  }

  std::string load_env(const std::string& env_pfx) 
  {
    return load_env(env_pfx, get_all_options()); 
  }

  std::string load_env(const std::string& env_pfx, const char** options);

  std::string load_file(const char* fname);

  virtual std::string load_argv(int argc, const char **argv) = 0;

  virtual const char** get_all_options() const = 0;

  virtual std::string check_args() { return ""; }

  const std::vector<std::string>& getPositionalArgs() const
  {
    return thePositionalArgs;
  }

  void copy_args (const char** argv) 
  {
    for (; *argv != NULL; ++argv) 
    {
      thePositionalArgs.push_back(*argv);
    }
  }

  template<class T> void init_val(const char* str, T& val, unsigned delta = 0) 
  {
    std::istringstream is(str + delta);
    is >> val;
  }

};


template<> ZORBA_DLL_PUBLIC void PropertiesBase::init_val(
    const char* str,
    std::string& val,
    unsigned delta);


template<> ZORBA_DLL_PUBLIC void PropertiesBase::init_val(
    const char* str,
    std::vector<std::string>& val,
    unsigned delta);

/**
 * This class provides access to global properties set for Zorba in environment
 * and configuration file.
 * It is available using Zorba.getProperties() method.
 * \see { Zorba::getProperties() }
 */
class ZORBA_DLL_PUBLIC PropertiesGlobal : public PropertiesBase
{
public:
  virtual ~PropertiesGlobal() {}

  /**
   * Before the JVM is started this will return the classpath set by
   * command line option, the CLASSPATH environment variable and in Zorba
   * config file.
   *
   * After the JVM is started this will contain in addition the paths to jars
   * used by modules that make use of the JVM.
   */
  virtual void getJVMClassPath(std::string & jvmClasspath) {}

  /**
   * This method should be used to set additional JVM classpath for modules
   * that make use of JVM. This will overide the classpath set by CLASSPATH
   * environment variable or Zorba config file.
   *
   * Once the JVM is started this method doesn't have any effect.
   */
  virtual void setJVMClassPath(const std::string & jvmClasspath) {}
};

}
#endif  // ZORBA_PROPERTIES_BASE_H
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
