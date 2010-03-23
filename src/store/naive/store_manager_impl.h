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
#ifndef ZORBA_SIMPLE_STORE_STORE_MANAGER_H
#define ZORBA_SIMPLE_STORE_STORE_MANAGER_H

#include <zorba/store_manager.h>


namespace zorba 
{

namespace simplestore
{

class SimpleStore;


/*******************************************************************************

********************************************************************************/
class StoreManagerImpl : public StoreManager
{
  friend class SimpleStore;

 private:
  static SimpleStore  * theStore;

 public:
  static SimpleStore* getStoreInternal() { return theStore; }
};



}
}
#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
