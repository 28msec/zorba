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
#include <zorba/api_shared_types.h>

class ZorbaCMDProperties;

namespace zorba {

  class String;

  namespace PathUtil {

    void
    setPathsOnContext(const ZorbaCMDProperties& aProperties,
                      zorba::StaticContext_t& aStaticCtx);

    static void
    tokenizePath(const std::string& aPathStr, std::vector<String>&  aResult);


    static String
    concatenatePaths( const std::vector<String>& aPathList);

  }
} /* namespace zorba */

#endif
