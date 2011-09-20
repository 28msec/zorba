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
#include <fstream>
#include <iostream>
#include <sstream>

#include <zorba/zorba.h>
#include <zorba/store_manager.h>
#include <zorba/util/path.h>
#include <zorba/xquery_exception.h>
#include "timer.h"

using namespace zorba;
using namespace std;


int
main(int argc, char* argv[])
{
  void* store = zorba::StoreManager::getStore();
  Zorba* zengine = Zorba::getInstance(store);

  if (argc != 2) {
    std::cerr << "Usage: test_plan_serializer <query_file>"  << std::endl;
    return 1;
  }

  XQuery_t lQuery = zengine->createQuery();
  try {
    std::ifstream lQueryFile(argv[1]); 

    if (!lQueryFile) {
      std::cerr << "file" << argv[1] << " does not exist" << std::endl;
      return 2;
    }

    lQuery->setFileName(argv[1]);
    lQuery = zengine->compileQuery (lQueryFile);

  } catch (XQueryException& e) {
    cerr << "Couldn't compile query: " << e << endl;
    return 3;
  } catch (ZorbaException& e) {
    // no need to close because the object is not valid
    cerr << "Couldn't compile query: " << e << endl;
    return 4;
  }


  std::ostringstream lPlanFileName;
  lPlanFileName << argv[1] << ".plan";

  try {

    Timer lTimer;
    lTimer.start();

    for (int i = 0; i < 100; ++i) {
      std::ofstream lExecPlan(lPlanFileName.str().c_str());

      if (!lExecPlan) {
        std::cerr << "cannot write to file " << lPlanFileName.str() << std::endl;
        return 5;
      }

      lQuery->saveExecutionPlan(lExecPlan, ZORBA_USE_BINARY_ARCHIVE, DONT_SAVE_UNUSED_FUNCTIONS);

    }
    lTimer.end();

    std::cout << "time needed to save the compile plan: " << std::endl;
    lTimer.print(std::cout);
  } catch (ZorbaException& e) {
    // no need to close because the object is not valid
    cerr << "Couldn't create compiled plan for query: " << e << endl;
    return 6;
  }

  try {

    Timer lTimer;
    lTimer.suspend();

    for (int i = 0; i < 100; ++i) {
      std::ifstream lExecPlan(lPlanFileName.str().c_str());

      if (!lExecPlan) {
        std::cerr << "cannot read from file " << lPlanFileName.str() << std::endl;
        return 5;
      }


      lQuery = zengine->createQuery();
      lQuery->setFileName(argv[1]);

      lTimer.resume();
      lQuery->loadExecutionPlan(lExecPlan);
      lTimer.suspend();
    }

    lTimer.end();
    
    std::cout << "time needed to load the compile plan: " << std::endl;
    lTimer.print(std::cout);
  } catch (ZorbaException& e) {
    // no need to close because the object is not valid
    cerr << "Couldn't load compiled plan for query: " << e << endl;
    return 6;
  }

  return 0;
}
