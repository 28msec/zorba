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

#ifndef API_STORE_H
#define API_STORE_H

class Store 
{
public:
  Store() {}

  Store(const Store&) {}

  virtual ~Store() {}

  virtual void* getStore() const { return 0; }

}; // class Store


/**
 * Class contains helper functions to create and destroy the store that is 
 * to be used by the zorba library. The functions must be implemented in the
 * code of each store module.
 */
class InMemoryStore : public Store 
{
private:
  void* theStore;
public:
  InMemoryStore() : theStore(0) {}

  InMemoryStore(const InMemoryStore& aStore) : Store(aStore), theStore(aStore.theStore) {}

  InMemoryStore(void* aStore) : theStore(aStore) {}

  virtual ~InMemoryStore() {}

  InMemoryStore& operator=(const InMemoryStore& aStore);
  static InMemoryStore getInstance();
  static void shutdown(InMemoryStore&);
  virtual void* getStore() const;
};

#endif
