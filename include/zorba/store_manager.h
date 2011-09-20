/*
 * Copyright 2006-2010 The FLWOR Foundation.
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
#ifndef ZORBA_STORE_MANAGER_H
#define ZORBA_STORE_MANAGER_H

#include <zorba/config.h>

namespace zorba {


/**
 * Class contains helper functions to create and destroy the store that is 
 * to be used by the zorba library. The functions must be implemented in the
 * code of each store module.
 */
class ZORBA_DLL_PUBLIC StoreManager 
{
public:
  static void* getStore();

  static void shutdownStore(void* store);
};

}

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
