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

#include "store/naive/simple_storec.h"
#include "store/naive/simple_store.h"


void* create_simple_store()
{
  zorba::store::SimpleStore* store = zorba::store::SimpleStore::getInstance();

  return store;
}


void free_simple_store(void* store)
{
  zorba::store::SimpleStore* lstore = reinterpret_cast<zorba::store::SimpleStore*>(store);

  lstore->shutdown();
}
