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
#include <zorba/module_import_checker.h>

using namespace zorba;

class ModuleFileChecker : public zorba::ModuleImportChecker
{
public:

  virtual bool checkModuleUri(const zorba::String& aModuleUri) const
  {
    if (aModuleUri == "http://www.zorba-xquery.com/modules/file")
      return false;
    return true;
  }

  virtual bool operator==(const ModuleImportChecker& aOther) const
  {
    const ModuleFileChecker* checker = dynamic_cast<const ModuleFileChecker*>(&aOther);
    return checker != 0;
  }
};

bool example1(Zorba* aZorba)
{
  StaticContext_t lStcxt = aZorba->createStaticContext();
  lStcxt->addModuleImportChecker(new ModuleFileChecker());

  std::stringstream lStream;
  lStream << "import module namespace file = 'http://www.zorba-xquery.com/modules/file';";
  lStream << std::endl << std::endl;
  lStream << "file:files('.')" << std::endl;

  try {
    XQuery_t lQuery = aZorba->compileQuery(lStream, lStcxt);
    std::cout << lQuery << std::endl;
  } catch (ZorbaException&) {
    return true;
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
