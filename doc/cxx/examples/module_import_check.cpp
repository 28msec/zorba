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

#include <memory>
#include <sstream>
#include <iostream>

#include <zorba/zorba.h>
#include <zorba/store_manager.h>
#include <zorba/diagnostic_list.h>
#include <zorba/uri_resolvers.h>
#include <zorba/zorba_exception.h>

using namespace zorba;

class FileModuleDisallow : public URIMapper
{
public:
  virtual void mapURI(const zorba::String aUri,
                      EntityData const* aEntityData,
                      std::vector<zorba::String>& oUris) throw ()
  {
    if (aEntityData->getKind() != EntityData::MODULE) {
      return;
    }
    if (aUri == "http://www.zorba-xquery.com/modules/file") {
      oUris.push_back(URIMapper::DENY_ACCESS);
    }
  }
};

bool example1(Zorba* aZorba)
{
  StaticContext_t lStcxt = aZorba->createStaticContext();
  FileModuleDisallow lChecker;
  lStcxt->registerURIMapper(&lChecker);

  std::stringstream lStream;
  lStream << "import module namespace file = 'http://www.zorba-xquery.com/modules/file';";
  lStream << std::endl << std::endl;
  lStream << "file:files('.')" << std::endl;

  try {
    XQuery_t lQuery = aZorba->compileQuery(lStream, lStcxt);
    std::cout << lQuery << std::endl;
  } catch (ZorbaException &e) {
    if (e.diagnostic() == zerr::ZXQP0029_URI_ACCESS_DENIED) {
      return true;
    }
    return false;
  } catch (...) {
    return false;
  }
  return false;
}

int module_import_check(int argc, char* argv[])
{
  void* lStore = zorba::StoreManager::getStore();
  Zorba *lZorba = Zorba::getInstance(lStore);

  bool res = false;

  res = example1(lZorba);
  if (!res)
    return 1;

  lZorba->shutdown();
  zorba::StoreManager::shutdownStore(lStore);
  return 0;
}
