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

#ifndef __MODULE_IMPORT_CHECKER_H__
#define __MODULE_IMPORT_CHECKER_H__
#include <zorba/api_shared_types.h>

namespace zorba {

/**
  * @brief Checks if a module should be imported.
  *
  * This class can be implemented by a user and registered in the static
  * context. if done so, zorbas module uri resolver will ask all instances
  * of this abstract class for every module import, if it should allow the
  * import. This feature can be used in special cases, where the user wants
  * to disallow the user to import several modules (i.e. for security
  * reasons).
  */
class ZORBA_DLL_PUBLIC ModuleImportChecker {
public:
  /**
    * @brief Checks, if a module should be imported by zorba.
    *
    * For all instances of this class which are registered in the static
    * context, zorba will ask if it should import a module for every module
    * it finds during the compilation process. If this function returns
    * false, zorba will throw an exception instead of importing this module.
    * Otherwise zorba will try to import the module.
    *
    * @return true, if zorba should try to import the module, false
    *         otherwise.
    */
  virtual bool checkModuleUri(const String& aModuleUri) const = 0;

  /**
    * @brief Checks if a ModuleImportChecker should be treated by zorba
    *        like being "equal" in a user defined way.
    *
    * Zorba allows the user to register as many ModuleImportChecker as he
    * wants. If a user wants to be able to also remove ModuleImportCheckers
    * from the static context, he has to implement this method in a way,
    * that zorba can check the modules for equality.
    *
    * @return true if this instance is the same checker than aOther in a
    *         user defined way.
    */
  virtual bool operator==(const ModuleImportChecker& aOther) const = 0;

  /**
    * @brief virtual destrucor
    */
  virtual ~ModuleImportChecker();
};
}
#endif //__MODULE_IMPORT_CHECKER_H__
/* vim:set et sw=2 ts=2: */
