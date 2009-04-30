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

#ifndef JAVA_VM_SINGELTON
#define JAVA_VM_SINGELTON

#include <jni.h>

namespace zorba {
	class JavaVMSingelton {
	public:
		static JavaVMSingelton* getInstance();
		virtual ~JavaVMSingelton();
		JavaVM* getVM();
		JNIEnv* getEnv();
	protected:
		JavaVMSingelton();
		static JavaVMSingelton* instance;
		JavaVM* m_vm;
		JNIEnv* m_env;
	};
}

#endif // JAVA_VM_SINGELTON
