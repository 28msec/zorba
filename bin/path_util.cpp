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

void
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

void
setPathsOnContext(
  const ZorbaCMDProperties& aProperties,
  StaticContext_t& aStaticCtx)
{
  std::vector<String> lPath;
  std::string lPathStr;

  // Compute the current working directory to append to all paths.
  filesystem_path lCWD;

  // setModulePaths() *overwrites* the URI path and lib path, so there's no
  // sense in calling both. So if --module-path exists, just use it.
  aProperties.getModulePath(lPathStr);
  if (lPathStr.length() > 0) {
    tokenizePath(lPathStr, lPath);
    lPath.push_back(lCWD.get_path());
    aStaticCtx->setModulePaths(lPath);
  }
  else {
    // Compute and set URI path
    aProperties.getURIPath(lPathStr);
    tokenizePath(lPathStr, lPath);
    lPath.push_back(lCWD.get_path());
    aStaticCtx->setURIPath(lPath);
    lPath.clear();

    // Compute and set lib path
    aProperties.getLibPath(lPathStr);
    tokenizePath(lPathStr, lPath);
    lPath.push_back(lCWD.get_path());
    aStaticCtx->setLibPath(lPath);
  }
}

} /* namespace ModulePath */

} /* namespace zorba */
