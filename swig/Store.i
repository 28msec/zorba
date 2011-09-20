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

%{  // start Implementation
 
class Store 
{
public:
  Store() {}

  Store(const Store&) {}

  virtual ~Store() {}

  virtual void* getStore() const { return 0; }

}; // class Store


class InMemoryStore : public Store 
{
private:
  void* theStore;

public:
  InMemoryStore() : theStore(0) {}

  InMemoryStore(const InMemoryStore& aStore) : Store(aStore), theStore(aStore.theStore) {}

  InMemoryStore(void* aStore) : theStore(aStore) {}

  virtual ~InMemoryStore() {}

  static InMemoryStore getInstance() 
  { return InMemoryStore(zorba::StoreManager::getStore()); }

  InMemoryStore& operator=(const InMemoryStore& aStore) 
  {
    theStore = aStore.theStore; 
    return *this;
  }

  static void shutdown(InMemoryStore& aStore)
  { 
    zorba::StoreManager::shutdownStore(aStore.theStore); 
  }

  virtual void* getStore() const
  {
     return theStore; 
  }
}; // class InMemoryStore




%}  // end   Implementation

    // Interface

class Store {};

class InMemoryStore : public Store 
{
public:
  static InMemoryStore getInstance();
  static void shutdown(InMemoryStore&);
}; // class InMemoryStore


