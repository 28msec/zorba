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

#include "path_util.h"

#include <stdlib.h>
//#include "zorba/zorba_string.h"
#include "zorba/util/path.h"

#include "util.h"
#include "zorbacmdproperties.h"
#include <zorba/static_context.h>

namespace zorba {

namespace PathUtil {

static std::string
getPathFromEnvironment(std::string const& aEnvVar)
{
#ifdef WIN32
  char* lBuffer;
  size_t lLen=0;
  errno_t lErr = getenv_s(&lLen, NULL, 0, aEnvVar.c_str());
  if (lErr || !lLen) return "";
  lBuffer = (char*)malloc(lLen * sizeof(char));
  if (!lBuffer) return "";
  getenv_s(&lLen, lBuffer, lLen, aEnvVar.c_str());
  std::string lRes(lBuffer);
  free(lBuffer);
  return lRes;
#else
  const char* lEnvValue = getenv(aEnvVar.c_str());
  return lEnvValue != 0 ? lEnvValue : "";
#endif
}


static void
tokenizePath(
  const std::string&    aPathStr,
  std::vector<String>&  aResult)
{
  std::vector<std::string> lPath;
#ifdef WIN32
  Util::tokenize(aPathStr, ";", lPath);
#else
  Util::tokenize(aPathStr, ":", lPath);
#endif
  for (std::vector<std::string>::iterator lIter = lPath.begin();
       lIter != lPath.end(); ++lIter) {
    aResult.push_back(*lIter);
  }
}


static String
concatenatePaths( const std::vector<String>& aPathList)
{
  String delimiter(filesystem_path::get_path_separator());

  String lResult;
  for (std::vector<String>::const_iterator lIter = aPathList.begin();
       lIter != aPathList.end(); ++lIter)
  {
    lResult += delimiter + *lIter;
  }

  return lResult;
}


void
setPathsOnContext(
  const ZorbaCMDProperties& aProperties,
  StaticContext_t& aStaticCtx)
{
  std::vector<String> lPath;
  std::string lPathStr, lEnvStr;

  // Compute the current working directory to append to all paths.
  filesystem_path lCWD;

  // setModulePaths() *overwrites* the URI path and lib path, so there's no
  // sense in calling both. So if either --module-path or ZORBA_MODULE_PATH
  // exists, just use those.
  aProperties.getModulePath(lPathStr);
  lEnvStr = getPathFromEnvironment("ZORBA_MODULE_PATH");
  if (lPathStr.length() > 0 || lEnvStr.length() > 0) {
    tokenizePath(lPathStr, lPath);
    tokenizePath(lEnvStr, lPath);
    lPath.push_back(lCWD.get_path());
    aStaticCtx->setModulePaths(lPath);
  }
  else {
    // Compute and set URI path
    aProperties.getURIPath(lPathStr);
    tokenizePath(lPathStr, lPath);
    lEnvStr = getPathFromEnvironment("ZORBA_URI_PATH");
    tokenizePath(lEnvStr, lPath);
    lPath.push_back(lCWD.get_path());
    aStaticCtx->setURIPath(lPath);
    lPath.clear();

    // Compute and set lib path
    aProperties.getLibPath(lPathStr);
    tokenizePath(lPathStr, lPath);
    lEnvStr = getPathFromEnvironment("ZORBA_LIB_PATH");
    lPath.push_back(lCWD.get_path());
    tokenizePath(lEnvStr, lPath);
    aStaticCtx->setLibPath(lPath);
  }

  // Compute and set JVM class path
  aProperties.getJVMClassPath(lPathStr);
  tokenizePath(lPathStr, lPath);
  lEnvStr = getPathFromEnvironment("CLASSPATH");
  lPath.push_back(lCWD.get_path());
  tokenizePath(lEnvStr, lPath);
  aStaticCtx->setJVMClassPath(lPath);
}

} /* namespace ModulePath */

} /* namespace zorba */
