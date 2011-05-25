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

#include "module_path.h"

#include <stdlib.h>
#include "zorba/zorba_string.h"
#include "zorba/util/path.h"

#include "util.h"
#include "zorbacmdproperties.h"

namespace zorba {

std::string
ModulePath::getEnvironmentModulePath()
{
  std::string lEnvName("ZORBA_MODULE_PATH");
#ifdef WIN32
  char* lBuffer;
  size_t lLen=0;
  errno_t lErr = getenv_s(&lLen, NULL, 0, lEnvName.c_str());
  if (lErr || !lLen) return "";
  lBuffer = (char*)malloc(lLen * sizeof(char));
  if (!lBuffer) return "";
  getenv_s(&lLen, lBuffer, lLen, lEnvName.c_str());
  std::string lRes(lBuffer);
  free(lBuffer);
  return lRes;
#else
  const char* lEnvValue = getenv(lEnvName.c_str());
  return lEnvValue!=0?lEnvValue:"";
#endif
}

void
ModulePath::convertVector(
  const std::vector<std::string>& aSource,
  std::vector<String>&            aDest)
{
  for (std::vector<std::string>::const_iterator lIter = aSource.begin();
       lIter != aSource.end(); ++lIter) {
    aDest.push_back(*lIter);
  } 
}

void
ModulePath::tokenizeModulePath(
  const std::string&        aModulePath,
  std::vector<std::string>& aResult)
{
#ifdef WIN32
  Util::tokenize(aModulePath, ";", aResult);
#else
  Util::tokenize(aModulePath, ":", aResult);
#endif
}

void
ModulePath::getModulePaths(
  const ZorbaCMDProperties& aProperties,
  std::vector<String>&      aModulePaths)
{
  std::vector<std::string> lModulePaths; // result vector
  std::string lModulePath; // temporary variable for collections paths

  // 1. add the module paths from the command line properties
  aProperties.getModulePaths(lModulePath);

  tokenizeModulePath(lModulePath, lModulePaths);

  // 2. add the module paths from the environment
  lModulePath = ModulePath::getEnvironmentModulePath();

  tokenizeModulePath(lModulePath, lModulePaths);

  // 3. add the current working directory as module path
  filesystem_path lCWD;
  lModulePaths.push_back(lCWD.get_path());

  // convert std::string to zorba::String
  convertVector(lModulePaths, aModulePaths);
}

} /* namespace zorba */
