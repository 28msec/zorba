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
#include <iostream>

#include <zorba/zorba.h>
#include <zorba/store_manager.h>
#include <zorba/unit_tests.h>

/**
 * This is the main entry point for unit tests which require a running
 * Zorba instance, and which execute inside of libzorba.
 */

using namespace zorba;

int main(int argc, char* argv[])
{
  void* lStore = zorba::StoreManager::getStore();
  Zorba* lZorba = Zorba::getInstance(lStore);

  int res = UnitTests::runUnitTest(argc, argv + 1);

  lZorba->shutdown();
  zorba::StoreManager::shutdownStore(lStore);
  return res;
}
/* vim:set et sw=2 ts=2: */
