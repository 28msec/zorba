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

%module zorba_api
%include "std_string.i"
%include "exception.i"

%exception {
  try {
    $action
  }
  catch (zorba::QueryException& e) {
    std::stringstream lStream;
    lStream << e;
    SWIG_exception(SWIG_RuntimeError, lStream.str().c_str());
  }
  catch (zorba::ZorbaException& e) {
    std::stringstream lStream;
    lStream << e;
    SWIG_exception(SWIG_RuntimeError, lStream.str().c_str());
  }
}

%{
#include <zorba/zorba.h>
#include <inmemorystore/inmemorystore.h>
#include <string>
#include <sstream>
#include <iostream>

class S_Item {
  friend class S_ResultIterator;
private:
  zorba::Item theItem;
public:
  S_Item() {}
  S_Item(const S_Item& aItem) : theItem(aItem.theItem) {}
  static S_Item createEmptyItem() { return S_Item(); }
  std::string getStringValue() const { return std::string(theItem.getStringValue().c_str()); }
}; // class S_Item

class S_ResultIterator {
private:
  zorba::ResultIterator_t theResultIterator;
public:
  S_ResultIterator() {}
  S_ResultIterator(const S_ResultIterator& aResultIterator) 
  : theResultIterator(aResultIterator.theResultIterator) 
  {}
  S_ResultIterator(zorba::ResultIterator_t aResultIterator) : theResultIterator(aResultIterator) {}
  void open() { theResultIterator->open(); }
  bool next(S_Item& aItem) 
  { 
      return theResultIterator->next(aItem.theItem); 
  }
  void close() { theResultIterator->close(); }
  void destroy() { theResultIterator = 0; }

}; // class S_ResultIterator

class S_XQuery {
private:
  zorba::XQuery_t theQuery;
public:
  S_XQuery() {}
  S_XQuery(const S_XQuery& aXQuery) : theQuery(aXQuery.theQuery) {}
  S_XQuery(zorba::XQuery_t aQuery) : theQuery(aQuery) {}
  std::string execute()
  {
    std::stringstream lStream;
      lStream << theQuery;
    return lStream.str();
  }
  void destroy() { theQuery = 0; }
  S_ResultIterator iterator() { return S_ResultIterator(theQuery->iterator()); }
}; // class S_XQuery

class S_Store {
public:
  S_Store() {}
  S_Store(const S_Store&) {}
  virtual ~S_Store() {}
  virtual zorba::store::SimpleStore* getStore() const { return 0; }
  // TODO the above line must be replace by the following line!!
  // virtual zorba::store::Store* getStore() const { return 0; }
};

class S_InMemoryStore : public S_Store {
private:
  zorba::store::SimpleStore* theStore;
public:
  S_InMemoryStore() : theStore(0) {}
  S_InMemoryStore(const S_InMemoryStore& aStore) : S_Store(aStore), theStore(aStore.theStore) {}
  virtual ~S_InMemoryStore() {}
  S_InMemoryStore(zorba::store::SimpleStore* aStore) : theStore(aStore) {}
  static S_InMemoryStore getInstance() { return S_InMemoryStore(zorba::inmemorystore::InMemoryStore::getInstance());
  }
  S_InMemoryStore& operator=(const S_InMemoryStore& aStore) 
  {
    theStore = aStore.theStore; 
    return *this;
  }
  static void shutdown(S_InMemoryStore& aStore)
  {
    zorba::inmemorystore::InMemoryStore::shutdown(aStore.theStore);
  }
  virtual zorba::store::SimpleStore* getStore() const
  {
    return theStore;
  }
};

class S_XmlDataManager {
private:
  zorba::XmlDataManager* theManager;
public:
  S_XmlDataManager() : theManager(0) {}
  S_XmlDataManager(const S_XmlDataManager& aManager) : theManager(aManager.theManager) {} 
  S_XmlDataManager(zorba::XmlDataManager* aManager) : theManager(aManager) {}
  void loadDocument(const std::string& aName, const std::string& aContent)
  {
    std::stringstream lStream(aContent);
    theManager->loadDocument(aName, lStream);
  }
  bool deleteDocument(const std::string& aName) { return theManager->deleteDocument(aName); }
};

class S_Zorba {
private:
  zorba::Zorba* theZorba;
  S_Zorba(zorba::Zorba* aZorba):theZorba(aZorba){}
public:
  S_Zorba():theZorba(0){}
  S_Zorba(const S_Zorba& aZorba) : theZorba(aZorba.theZorba) {}
  static S_Zorba getInstance(const S_Store& aStore)
  {
    return S_Zorba(zorba::Zorba::getInstance(aStore.getStore()));
  }
  S_XQuery compileQuery(const std::string& aStr) 
  {
      return S_XQuery(theZorba->compileQuery(aStr));
  }
  S_XmlDataManager getXmlDataManager()
  {
    return S_XmlDataManager(theZorba->getXmlDataManager());
  }
  void shutdown() { theZorba->shutdown(); }
}; // class S_Zorba


%}

class S_Item {
public: 
  static S_Item createEmptyItem();
  std::string getStringValue() const;
};

class S_ResultIterator {
public:
  void open();
  bool next(S_Item&);
  void close();
  void destroy();
};

class S_XQuery {
public:
  std::string execute(); 
  void destroy();
  S_ResultIterator iterator();
};

class S_Store {};

class S_InMemoryStore : public S_Store {
public:
  static S_InMemoryStore getInstance();
  static void shutdown(S_InMemoryStore&);
};

class S_XmlDataManager {
public:
  void loadDocument(const std::string& aName, const std::string& aContent);
  bool deleteDocument(const std::string& aName);
};

class S_Zorba {
public:
  static S_Zorba getInstance(const S_Store&);
  S_XQuery compileQuery(const std::string& aStr);
  S_XmlDataManager getXmlDataManager();
  void shutdown();
};

