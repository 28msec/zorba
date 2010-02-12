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
#ifndef ZORBA_MODULE_PATH_H
#define ZORBA_MODULE_PATH_H

#include <vector>
#include <string>

class ZorbaCMDProperties;

namespace zorba {

  class String;

  class ModulePath {
  protected:
    static std::string
    getEnvironmentModulePath();

    static void
    convertVector(const std::vector<std::string>& aSource,
                  std::vector<String>& aDest); 

    static void
    tokenizeModulePath(const std::string& aModulePath,
                       std::vector<std::string>& aResult);

    static void
    getInstalledModulePath(const std::string& aModulePath,
                       std::vector<std::string>& aResult);

  public:
    static void
    getModulePaths(const ZorbaCMDProperties& aProperties,
                   std::vector<String>& aModulePaths);


  };
} /* namespace zorba */

#endif
