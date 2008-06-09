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

%{
#include <zorba/zorba.h>
#include <inmemorystore/inmemorystore.h>
#include <string>
#include <sstream>
#include <iostream>

#define S_ZORBA_TRY try {
#define S_ZORBA_CATCH } \
  catch (zorba::DynamicException& e) { \
    S_DynamicException newE(e); \
    throw newE; \
  } \
  catch (zorba::StaticException& e) { \
    S_StaticException newE(e); \
    throw newE; \
  } \
  catch (zorba::TypeException& e) { \
    S_TypeException newE(e); \
    throw newE; \
  } \
  catch (zorba::SerializationException& e) { \
    S_SerializationException newE(e); \
    throw newE; \
  } \
  catch (zorba::SystemException& e) { \
    S_SystemException newE(e); \
    throw newE; \
  } \

class S_QueryException {
protected:
  std::string theMsg;
public:
  S_QueryException() {}
  S_QueryException(const S_QueryException* aException) : theMsg(aException->theMsg) {}
  S_QueryException(const zorba::QueryException* aException)
  {
    std::stringstream lStream;
    lStream << *aException;
    theMsg = lStream.str();
  }
  S_QueryException(const zorba::SystemException* aException)
  {
    std::stringstream lStream;
    lStream << *aException;
    theMsg = lStream.str();
  }
  const std::string& getMsg() const { return theMsg; }
}; // class S_QueryException

class S_DynamicException : public S_QueryException {
public:
  S_DynamicException() {}
  S_DynamicException(const S_DynamicException& aException) : S_QueryException(&aException) {}
  S_DynamicException(const zorba::DynamicException& aException) : S_QueryException(&aException) {}
};
class S_StaticException : public S_QueryException {
public:
  S_StaticException() {}
  S_StaticException(const S_StaticException& aException) : S_QueryException(&aException) {}
  S_StaticException(const zorba::StaticException& aException) : S_QueryException(&aException) {}
};
class S_TypeException : public S_QueryException {
public:
  S_TypeException() {}
  S_TypeException(const S_TypeException& aException) : S_QueryException(&aException) {}
  S_TypeException(const zorba::TypeException& aException) : S_QueryException(&aException) {}
};
class S_SerializationException : public S_QueryException {
public:
  S_SerializationException() {}
  S_SerializationException(const S_SerializationException& aException) : S_QueryException(&aException) {}
  S_SerializationException(const zorba::SerializationException& aException) : S_QueryException(&aException) {}
};
class S_SystemException : public S_QueryException {
public:
  S_SystemException() {}
  S_SystemException(const S_SystemException& aException) : S_QueryException(&aException) {}
  S_SystemException(const zorba::SystemException& aException) : S_QueryException(&aException) {}
};

class S_Item {
  friend class S_ResultIterator;
private:
  zorba::Item theItem;
public:
  S_Item() {}
  S_Item(const S_Item& aItem) : theItem(aItem.theItem) {}
  static S_Item createEmptyItem() { S_Item lItem; return lItem; }
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
    S_ZORBA_TRY
      return theResultIterator->next(aItem.theItem); 
    S_ZORBA_CATCH
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
  std::string execute() {
    std::stringstream lStream;
    S_ZORBA_TRY
      lStream << theQuery;
    S_ZORBA_CATCH
    return lStream.str();
  }
  S_ResultIterator iterator() { return S_ResultIterator(theQuery->iterator()); }
}; // class S_XQuery

class S_Store {
public:
  virtual ~S_Store() {}
  virtual zorba::store::SimpleStore* getStore() const { return 0; }
  // TODO the above line must be replace by the following line!!
  // virtual zorba::store::Store* getStore() const { return 0; }
};

class S_InMemoryStore : public S_Store {
private:
  zorba::store::SimpleStore* theStore;
public:
  virtual ~S_InMemoryStore() {}
  S_InMemoryStore() : theStore(0) {}
  S_InMemoryStore(zorba::store::SimpleStore* aStore) : theStore(aStore) {}
  static S_InMemoryStore* getInstance()
  {
    static S_InMemoryStore lStore(zorba::inmemorystore::InMemoryStore::getInstance());
    return &lStore;
  }
  static void shutdown(S_InMemoryStore* aStore)
  {
    zorba::inmemorystore::InMemoryStore::shutdown(aStore->theStore);
  }
  virtual zorba::store::SimpleStore* getStore() const
  {
    return theStore;
  }
};

class S_Zorba {
private:
  zorba::Zorba* theZorba;
  S_Zorba(zorba::Zorba* aZorba):theZorba(aZorba){}
public:
  S_Zorba():theZorba(0){}
  static S_Zorba* getInstance(S_Store* aStore)
  {
    static S_Zorba lSZorba(zorba::Zorba::getInstance(aStore->getStore()));
    return & lSZorba;
  }
  S_XQuery compileQuery(const std::string& aStr) 
  {
    S_ZORBA_TRY
      return S_XQuery(theZorba->compileQuery(aStr));
    S_ZORBA_CATCH
  }
  void shutdown() { theZorba->shutdown(); }
}; // class S_Zorba

%}

class S_QueryException {
public:
  const std::string& getMsg() const;
};
class S_DynamicException : public S_QueryException {};
class S_StaticException : public S_QueryException {};
class S_TypeException : public S_QueryException {};
class S_SerializationException : public S_QueryException {};
class S_SystemException : public S_QueryException {};

class S_Item {
public: 
  static S_Item createEmptyItem();
  std::string getStringValue() const;
};

%catches(S_DynamicException, S_TypeException, S_SerializationException, S_SystemException) S_ResultIterator::next();
class S_ResultIterator {
public:
  void open();
  bool next(S_Item&);
  void close();
  void destroy();
};

%catches(S_DynamicException, S_TypeException, S_SerializationException, S_SystemException) S_XQuery::execute();
class S_XQuery {
public:
  std::string execute(); 
  S_ResultIterator iterator();
};

class S_Store {};

class S_InMemoryStore : public S_Store {
public:
  static S_InMemoryStore* getInstance();
  static void shutdown(S_InMemoryStore*);
};

%catches(S_StaticException, S_TypeException, S_SystemException) S_XQuery::compileQuery();
class S_Zorba {
public:
  static S_Zorba* getInstance(S_Store*);
  S_XQuery compileQuery(const std::string& aStr);
  void shutdown();
};

