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

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <sstream>

#include "JavaVMSingelton.h"

namespace zorba { namespace xslfo {
JavaVMSingelton* JavaVMSingelton::instance = NULL;

JavaVMSingelton::JavaVMSingelton(const char* classPath)
{
  memset(&args, 0, sizeof(args));
  jint r;
  jint nOptions = 2;

  std::string classpathOption;
  std::ostringstream os;
  os << "-Djava.class.path=" << classPath;
  classpathOption = os.str();
  classPathOption = new char[classpathOption.size() + 1];
  memset(classPathOption, 0, sizeof(char) * (classpathOption.size() + 1));
  memcpy(classPathOption, classpathOption.c_str(), classpathOption.size() * sizeof(char));
  classpathOption[classpathOption.size()] = 0;
  std::string lAwtArgStr = "-Djava.awt.headless=true";
  awtOption = new char[lAwtArgStr.size() + 1];
  memset(awtOption, 0, sizeof(char) * (lAwtArgStr.size() + 1));
  memcpy(awtOption, lAwtArgStr.c_str(), sizeof(char) * lAwtArgStr.size());
  awtOption[lAwtArgStr.size()] = 0;
  options[0].optionString = classPathOption;
  options[0].extraInfo = NULL;
  options[1].optionString = awtOption;
  options[1].extraInfo = NULL;
  memset(&args, 0, sizeof(args));
  args.version  = JNI_VERSION_1_2;
  args.nOptions = nOptions;
  args.options  = options;
  args.ignoreUnrecognized = JNI_FALSE;

  r = JNI_CreateJavaVM(&m_vm, (void **)&m_env, &args);
  if (r != JNI_OK) {
    throw VMOpenException();
  }
}

JavaVMSingelton::~JavaVMSingelton()
{
  if (instance) {
    instance = NULL;
  }
  m_vm->DestroyJavaVM();
  delete[] awtOption;
  delete[] classPathOption;
}

JavaVMSingelton* JavaVMSingelton::getInstance(const char* classPath)
{
  if (instance == NULL) {
    instance = new JavaVMSingelton(classPath);
  }
  return instance;
}

JavaVM* JavaVMSingelton::getVM()
{
  return m_vm;
}

JNIEnv* JavaVMSingelton::getEnv()
{
  return m_env;
}

}} // namespace zorba, xslfo
