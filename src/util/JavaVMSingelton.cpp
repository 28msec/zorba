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

#include "util/JavaVMSingelton.h"
#include "zorbaerrors/error_manager.h"
#include "util/tracer.h"

#include <iostream>
#include <string>
#include <cstdlib>

using namespace zorba;

namespace zorba {
  extern std::ostringstream __oss;
}

static bool InitializeJVM(JavaVM **pvm, JNIEnv **penv)
{
  JavaVMInitArgs args;
  jint r;
  jint nOptions = 1;
  JavaVMOption options[1];

  const char *cls = getenv("CLASSPATH");
  std::string classpathOption;
  if (cls) {
    std::ostringstream os;
    os << "-Djava.class.path=\"" << cls << "\"";
    classpathOption = os.str();
  }
  options[0].optionString = const_cast<char*>(classpathOption.c_str());
  options[0].extraInfo = NULL;
  args.version  = JNI_VERSION_1_2;
  args.nOptions = nOptions;
  args.options  = options;
  args.ignoreUnrecognized = JNI_FALSE;

  r = JNI_CreateJavaVM(pvm, (void **)penv, &args);
  return r == JNI_OK;
}


zorba::JavaVMSingelton* zorba::JavaVMSingelton::instance = NULL;

zorba::JavaVMSingelton::JavaVMSingelton()
{
  /*long result;
  JavaVMInitArgs vm_args;*/

  /*vm_args.version = JNI_VERSION_1_6;
  vm_args.options = options;
  vm_args.nOptions = 2;
  vm_args.ignoreUnrecognized = JNI_FALSE;

  result = JNI_CreateJavaVM(&m_vm, (void**) &m_env, &vm_args);*/
  bool result = InitializeJVM(&m_vm, &m_env);
  if (!result) {
    ZORBA_ERROR(FODC0002);
  }
}

zorba::JavaVMSingelton::~JavaVMSingelton()
{
  if (instance) {
    instance = NULL;
  }
  m_vm->DestroyJavaVM();
}

zorba::JavaVMSingelton* zorba::JavaVMSingelton::getInstance()
{
  if (instance == NULL) {
    instance = new JavaVMSingelton();
  }
  return instance;
}

JavaVM* zorba::JavaVMSingelton::getVM()
{
  return m_vm;
}

JNIEnv* zorba::JavaVMSingelton::getEnv()
{
  return m_env;
}
