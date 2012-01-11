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

#include <vector>
#include <iostream>
#include <cassert>

#include <zorba/zorba.h>
#include <zorba/store_manager.h>
#include <zorba/audit.h>
#include <zorba/audit_scoped.h>

bool
test_audit_1(zorba::Zorba* aZorba)
{
  zorba::audit::Provider* lAuditProvider = aZorba->getAuditProvider();
  zorba::audit::Configuration* config = lAuditProvider->createConfiguration();
  std::vector<zorba::String> property_names;
  zorba::audit::Configuration::getPropertyNames(property_names);

  bool lIsStatic;
  lIsStatic = zorba::audit::Configuration::enableProperty(config, property_names,
                                                          "xquery/compilation/filename");
  assert(lIsStatic);
  lIsStatic = zorba::audit::Configuration::enableProperty(config, property_names,
                                                          "xquery/compilation/parse-duration");
  assert(lIsStatic);
  lIsStatic = zorba::audit::Configuration::enableProperty(config, property_names,
                                                          "xquery/compilation/translation-duration");
  assert(lIsStatic);
  lIsStatic = zorba::audit::Configuration::enableProperty(config, property_names,
                                                          "xquery/compilation/optimization-duration");
  assert(lIsStatic);
  lIsStatic = zorba::audit::Configuration::enableProperty(config, property_names,
                                                          "xquery/compilation/codegeneration-duration");
  assert(lIsStatic);

  zorba::audit::Event* event = lAuditProvider->createEvent(config);

  zorba::XQuery_t query = aZorba->createQuery();
  zorba::StaticContext_t lStaticContext = aZorba->createStaticContext();

  lStaticContext->setAuditEvent(event);

  Zorba_CompilerHints lHints;
  query->setFileName("test_audit");
  query->compile("import module namespace e = 'http://www.zorba-xquery.com/modules/reflection'; e:eval('1+1')",  lStaticContext, lHints);
  Zorba_SerializerOptions lSerOptions;
  query->execute(std::cout, &lSerOptions);

  if (event->size() != 2) {
    return false;
  } else {
    // one record for the eval query and one for the main query
    const zorba::audit::Record* lRecord = event->at(0);
    assert(lRecord->size() == 5);
    lRecord = event->at(1);
    assert(lRecord->size() == 5);
    std::cerr << *event << std::endl;
  }

  aZorba->getAuditProvider()->submitEvent(event);
  aZorba->getAuditProvider()->destroyConfiguration(config);

  return true;
}

bool
test_audit_2(zorba::Zorba* aZorba)
{
  zorba::audit::Provider* lAuditProvider = aZorba->getAuditProvider();
  zorba::audit::Configuration* config = lAuditProvider->createConfiguration();

  {
    // test to make sure that auditing doesn't crash if the record is initialized
    // with a 0 event pointer
    zorba::audit::ScopedRecord sar(0);
    zorba::time::Timer lTimer;
    zorba::audit::MicroDurationAuditor auditor(sar, "blub", lTimer);
  }


  aZorba->getAuditProvider()->destroyConfiguration(config);

  return true;
}

int
test_audit(int argc, char* argv[])
{
  void* store = zorba::StoreManager::getStore();
  zorba::Zorba* lZorbaInstance = zorba::Zorba::getInstance(store);

  if (!test_audit_1(lZorbaInstance))
  {
    return 1;
  }

  if (!test_audit_2(lZorbaInstance))
  {
    return 2;
  }

  return 0;
}
/* vim:set et sw=2 ts=2: */
