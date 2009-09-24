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

%{  // Implementations

#include <zorba/zorba.h>
#include <simplestore/simplestore.h>
#include <string>
#include <sstream>
#include <iostream>
#include <zorba/exception.h>
#include <zorba/error_handler.h>
#include <zorba/options.h>

  class CompilerHints;
  class ErrorHandler;
  class Item;
  class ResultIterator;
  class StaticContext;
  class Store;
  class XQuery;
  class Zorba;

class Item {
  friend class ResultIterator;
  friend class StaticContext;
private:
  zorba::Item theItem;
public:
  Item() {}
  Item(const Item& aItem) : theItem(aItem.theItem) {}
  static Item createEmptyItem() { return Item(); }
  std::string getStringValue() const 
  { return 		std::string(theItem.getStringValue().c_str()); }

  std::string serialize() const {
    std::stringstream lStream;
    theItem.serialize(lStream);
    return lStream.str();
  }


}; // class Item

class ResultIterator {
private:
  zorba::ResultIterator_t theResultIterator;
public:
  ResultIterator() {}
  ResultIterator(const ResultIterator& aResultIterator) 
    : theResultIterator(aResultIterator.theResultIterator) {}
  ResultIterator(zorba::ResultIterator_t aResultIterator) : 
      theResultIterator(aResultIterator) {}
  void open() { theResultIterator->open(); }
  bool next(Item& aItem) { return theResultIterator->next(aItem.theItem); }
  void close() { theResultIterator->close(); }
  void destroy() { theResultIterator = 0; }

}; // class ResultIterator

class XQuery {
private:
  zorba::XQuery_t theQuery;
public:
  XQuery() {}
  XQuery(const XQuery& aXQuery) : theQuery(aXQuery.theQuery) {}
  XQuery(zorba::XQuery_t aQuery) : theQuery(aQuery) {}

  std::string execute()
  {
    std::stringstream lStream;
    lStream << theQuery;
    return lStream.str();
  }

  void setVariableAsDocument(const std::string& aVarName, 
                             const std::string& aURL, 
                             const std::string& aContent)
  {
    std::auto_ptr<std::istream> lDocStream(new std::stringstream(aContent));
  	zorba::DynamicContext* lCtx = theQuery->getDynamicContext();

  	lCtx->setVariableAsDocument(aVarName, aURL, lDocStream);
   }

  std::string printPlanAsXML()
  {
    std::ostringstream lStream;
    theQuery->printPlan(lStream);
    return lStream.str();
  }

  std::string printPlanAsDOT()
  {
    std::ostringstream lStream;
    theQuery->printPlan(lStream, true);
    return lStream.str();
  }

#ifdef SWIGPYTHON
  void executeSAX(SAX2ContentHandlerProxy* contentHandlerProxy)
  { theQuery->executeSAX(contentHandlerProxy); }
#endif

  bool isUpdateQuery() { return theQuery->isUpdateQuery(); }
  void applyUpdates() { theQuery->applyUpdates(); }
  void destroy() { theQuery = 0; }
  ResultIterator iterator() { return ResultIterator(theQuery->iterator()); }
}; // class XQuery

class Store {
public:
  Store() {}
  Store(const Store&) {}
  virtual ~Store() {}
  virtual zorba::simplestore::SimpleStore* getStore() const { return 0; }
  // TODO the above line must be replace by the following line!!
  // virtual zorba::simplestore::Store* getStore() const { return 0; }
}; // class Store

class InMemoryStore : public Store {
private:
  zorba::simplestore::SimpleStore* theStore;
public:
  InMemoryStore() : theStore(0) {}
  InMemoryStore(const InMemoryStore& aStore)
    : Store(aStore), theStore(aStore.theStore) {}
  InMemoryStore(zorba::simplestore::SimpleStore* aStore) : theStore(aStore) {}

  virtual ~InMemoryStore() {}

  static InMemoryStore getInstance() 
  { return InMemoryStore(zorba::simplestore::SimpleStoreManager::getStore()); }

  InMemoryStore& operator=(const InMemoryStore& aStore) 
  {
    theStore = aStore.theStore; 
    return *this;
  }

  static void shutdown(InMemoryStore& aStore)
  { zorba::simplestore::SimpleStoreManager::shutdownStore(aStore.theStore); }

  virtual zorba::simplestore::SimpleStore* getStore() const
  { return theStore; }
}; // class InMemoryStore

class XmlDataManager {
private:
  zorba::XmlDataManager* theManager;
public:
  XmlDataManager() : theManager(0) {}
  XmlDataManager(const XmlDataManager& aManager)
    : theManager(aManager.theManager) {} 
  XmlDataManager(zorba::XmlDataManager* aManager) : theManager(aManager) {}

  void loadDocument(const std::string& aName, const std::string& aContent)
  {
    std::stringstream lStream(aContent);
    theManager->loadDocument(aName, lStream);
  }

  bool deleteDocument(const std::string& aName) 
  { return theManager->deleteDocument(aName); }
};

class ZorbaException {
 public:
  virtual std::string getDescription() const =0;
  virtual unsigned int getFileLineNumber () const =0;
  virtual std::string getFileName () const =0;
};

class QueryException : public ZorbaException {};

class SystemException : public ZorbaException {
  friend class ErrorHandler;
 protected:
  const zorba::SystemException* theException;
  SystemException (const zorba::SystemException *se) : theException(se) {}
  SystemException() {}
 public:
  virtual std::string getDescription() const 
  {
    return std::string(theException->getDescription().c_str());
  }
  virtual unsigned int getFileLineNumber () const 
  {
    return theException->getFileLineNumber();
  }
  virtual std::string getFileName () const 
  {
    return std::string(theException->getFileName().c_str());
  }
};

class DynamicException : public QueryException {
  friend class ErrorHandler;
 protected:
  const zorba::DynamicException* theException;
  DynamicException (const zorba::DynamicException *de) : theException(de) {}
  DynamicException() {}
 public:
  virtual std::string getDescription() const 
  {
    return std::string(theException->getDescription().c_str());
  }
  virtual unsigned int getFileLineNumber () const 
  {
    return theException->getFileLineNumber();
  }
  virtual std::string getFileName () const 
  {
    return std::string(theException->getFileName().c_str());
  }
};

class SerializationException : public QueryException {
  friend class ErrorHandler;
 protected:
  const zorba::SerializationException* theException;
  SerializationException (const zorba::SerializationException *se) : 
      theException(se) {}
  SerializationException() {}
 public:
  virtual std::string getDescription() const 
  {
    return std::string(theException->getDescription().c_str());
  }
  virtual unsigned int getFileLineNumber () const 
  {
    return theException->getFileLineNumber();
  }
  virtual std::string getFileName () const 
  {
    return std::string(theException->getFileName().c_str());
  }
};

class StaticException : public QueryException {
  friend class ErrorHandler;
 protected:
  const zorba::StaticException* theException;
  StaticException (const zorba::StaticException *se) : 
      theException(se) {}
  StaticException() {}
 public:
  virtual std::string getDescription() const 
  {
    return std::string(theException->getDescription().c_str());
  }
  virtual unsigned int getFileLineNumber () const 
  {
    return theException->getFileLineNumber();
  }
  virtual std::string getFileName () const 
  {
    return std::string(theException->getFileName().c_str());
  }
};

class TypeException : public QueryException {
  friend class ErrorHandler;
 protected:
  const zorba::TypeException* theException;
  TypeException (const zorba::TypeException *se) : 
      theException(se) {}
  TypeException() {}
 public:
  virtual std::string getDescription() const 
  {
    return std::string(theException->getDescription().c_str());
  }
  virtual unsigned int getFileLineNumber () const 
  {
    return theException->getFileLineNumber();
  }
  virtual std::string getFileName () const 
  {
    return std::string(theException->getFileName().c_str());
  }
};

class UserException : public QueryException {
  friend class ErrorHandler;
 protected:
  const zorba::UserException* theException;
  UserException (const zorba::UserException *se) : 
      theException(se) {}
  UserException() {}
 public:
  virtual std::string getDescription() const 
  {
    return std::string(theException->getDescription().c_str());
  }
  virtual unsigned int getFileLineNumber () const 
  {
    return theException->getFileLineNumber();
  }
  virtual std::string getFileName () const 
  {
    return std::string(theException->getFileName().c_str());
  }
};


class ErrorHandler : public zorba::ErrorHandler {
 private:
  void dynamicError (const zorba::DynamicException &aError) 
  { 
    const DynamicException de(&aError);
    dynamicError(de); 
  }
  void serializationError (const zorba::SerializationException &aError) 
  {
    const SerializationException se(&aError);
    serializationError(se); 
  } 
  void staticError (const zorba::StaticException &aStaticError) 
  {
    const StaticException se(&aStaticError);
    staticError(se);     
  }
  void systemError (const zorba::SystemException &aSystemError) 
  {
    const SystemException se(&aSystemError);
    systemError(se);     
  }
  void typeError (const zorba::TypeException &aTypeError) 
  {
    const TypeException te(&aTypeError);
    typeError(te);     
  }
  void userError (const zorba::UserException &aUserError)
  {
    const UserException ue(&aUserError);
    userError(ue);     
  }
 public:
  virtual void dynamicError(const DynamicException &de) {}
  virtual void serializationError (const SerializationException &asError) {} 
  virtual void staticError (const StaticException &aStaticError) {}
  virtual void systemError (const SystemException &aSystemError) {}
  virtual void typeError (const TypeException &aTypeError) {}
  virtual void userError (const UserException &aUserError) {}
 }; // class ErrorHandler


class CompilerHints {
  friend class Zorba;
  friend class StaticContext;
 private:
  Zorba_CompilerHints_t theCompilerHints;
 public:
  CompilerHints() {}
  CompilerHints(const CompilerHints& aCompilerHints) : 
    theCompilerHints(aCompilerHints.theCompilerHints) {}
  CompilerHints(Zorba_CompilerHints_t aCompilerHints) : 
    theCompilerHints(aCompilerHints) {}
    
  bool getLibModule()
  { return theCompilerHints.lib_module; }

  void setLibModule(bool aLibModule)
  { theCompilerHints.lib_module = aLibModule; }

  int getOptimizationLevel()
  { return theCompilerHints.opt_level; }

  void setOptimizationLevel(int aOptLevel)
  { 
    switch( aOptLevel )
    {
    case 0:
      theCompilerHints.opt_level = ZORBA_OPT_LEVEL_O0;
      break;
    case 1:
      theCompilerHints.opt_level = ZORBA_OPT_LEVEL_O1;
      break;
    default:
      return;
    }
  }
}; // class CompilerHints


class StaticContext {
  friend class Zorba;
private:
  zorba::StaticContext_t theStaticContext;
public:
  StaticContext() {}
  StaticContext(const StaticContext& aStaticContext) : 
    theStaticContext(aStaticContext.theStaticContext) {}
  StaticContext(zorba::StaticContext_t aStaticContext) : 
    theStaticContext(aStaticContext) {}

  virtual bool addColation(const std::string& aURI)
  { return theStaticContext->addCollation(aURI); }

  virtual bool addNamespace(const std::string& aPrefix, 
                            const std::string& aURI)
  { return theStaticContext->addNamespace(aPrefix, aURI); }

  void addReference() const
  { theStaticContext->addReference(); }
  
  virtual bool containsFunction(const std::string &aFnNameUri, 
                                const std::string &aFnNameLocal, 
                                int arity) const 
  { return theStaticContext->containsFunction(aFnNameUri, aFnNameLocal,
                                              arity); }

  virtual StaticContext	createChildContext() const
  { return StaticContext(theStaticContext->createChildContext()); }
  
  virtual void 	declareOption (const Item &aQName, 
                               const std::string &aOptionVal)
  { return theStaticContext->declareOption(aQName.theItem, aOptionVal); }

  virtual void 	disableFunction (const Item &aQName, int arity)
  { theStaticContext->disableFunction( aQName.theItem, arity); }

  //virtual void 	disableFunction (const Function_t &aFunction)=0;
  //virtual void 	findFunctions (const Item &aQName, std::vector< Function_t > &aFunctions) const =0
  virtual void 	free ()
  { theStaticContext->free(); }

  virtual std::string getBaseURI () const
  { return std::string(theStaticContext->getBaseURI().c_str()); }

  //virtual boundary_space_mode_t 	getBoundarySpacePolicy () const =0;
  //virtual TypeIdentifier_t 	getCollectionType (const std::string &aCollectionUri) const =0;
  //virtual CollectionURIResolver * 	getCollectionURIResolver () const =0;
  //virtual construction_mode_t 	getConstructionMode () const =0
 	//virtual TypeIdentifier_t 	getContextItemStaticType () const =0
  //virtual void 	getCopyNamespacesMode (preserve_mode_t &aPreserve, inherit_mode_t &aInherit) const =0;
  virtual std::string getDefaultCollation () const 
  { return std::string(theStaticContext->getDefaultCollation().c_str()); }

  virtual std::string getDefaultElementAndTypeNamespace () const 
  { 
    return std::string(theStaticContext->getDefaultElementAndTypeNamespace().
                       c_str()); 
  }

  virtual std::string getDefaultFunctionNamespace () const 
  { 
    return std::string(theStaticContext->getDefaultFunctionNamespace().c_str());
  }

  //virtual order_empty_mode_t 	getDefaultOrderForEmptySequences () const =0;
  //virtual TypeIdentifier_t 	getDocumentType (const std::string &aDocUri) const =0;
  //virtual DocumentURIResolver * 	getDocumentURIResolver ()=0;
  //virtual ModuleURIResolver * 	getModuleURIResolver () const =0;
  virtual std::string getNamespaceURIByPrefix(const std::string &aPrefix) const
  {
    return std::string(theStaticContext->getNamespaceURIByPrefix(aPrefix).
                       c_str());
  }

  virtual bool getOption(const Item &aQName, std::string &aOptionValue) const
  { 
    zorba::String optVal = zorba::String(aOptionValue.c_str());
    return theStaticContext->getOption(aQName.theItem, optVal); 
  }

  //virtual ordering_mode_t 	getOrderingMode () const =0
  long 	getRefCount () const
  { return theStaticContext->getRefCount(); }

  virtual bool 	getRevalidationEnabled () const
  { return theStaticContext->getRevalidationEnabled(); }

  //virtual validation_mode_t 	getRevalidationMode ()=0;
  //virtual SchemaURIResolver * 	getSchemaURIResolver () const =0;
  //virtual xpath1_0compatib_mode_t 	getXPath1_0CompatibMode () const =0
  //virtual xquery_version_t 	getXqueryVersion () const =0;
 	virtual void 	loadProlog (const std::string & aProlog, 
                            const CompilerHints &hints)
  { theStaticContext->loadProlog( aProlog, hints.theCompilerHints); }

  //virtual bool 	registerStatelessExternalFunction (StatelessExternalFunction *aExternalFunction)=0
  void 	removeReference ()
  { theStaticContext->removeReference(); }

  virtual void 	resetTraceStream ()
  { theStaticContext->resetTraceStream(); }

  virtual bool 	setBaseURI (const std::string &aBaseURI)
  { return theStaticContext->setBaseURI(aBaseURI); }

  //virtual bool 	setBoundarySpacePolicy (boundary_space_mode_t aMode)=0
  //virtual void 	setCollectionType (const std::string &aCollectionUri, TypeIdentifier_t type)=0
 	//virtual void 	setCollectionURIResolver (CollectionURIResolver *aCollectionUriResolver)=0
  //virtual bool 	setConstructionMode (construction_mode_t aMode)=0
  //virtual void 	setContextItemStaticType (TypeIdentifier_t type)=0
  //virtual bool 	setCopyNamespacesMode (preserve_mode_t aPreserve, inherit_mode_t aInherit)=0
  virtual bool 	setDefaultCollation (const std::string &aURI)
  { return theStaticContext->setDefaultCollation(aURI); }

  virtual bool 	setDefaultElementAndTypeNamespace (const std::string &aURI)
  { return theStaticContext->setDefaultElementAndTypeNamespace(aURI); }

  virtual bool 	setDefaultFunctionNamespace (const std::string &aURI)
  { return theStaticContext->setDefaultFunctionNamespace(aURI); }

  //virtual bool 	setDefaultOrderForEmptySequences (order_empty_mode_t aMode)=0
  //virtual void 	setDocumentType (const std::string &aDocUri, TypeIdentifier_t type)=0
  //virtual void 	setDocumentURIResolver (DocumentURIResolver *aDocumentURIResolver)=0
  //virtual void 	setModuleURIResolver (ModuleURIResolver *aModuleUriResolver)=0
  //virtual bool 	setOrderingMode (ordering_mode_t aMode)=0
 	virtual bool 	setRevalidationEnabled (bool enabled)
  { return theStaticContext->setRevalidationEnabled(enabled); }

  //virtual void 	setRevalidationMode (validation_mode_t aMode)=0
 	//virtual void 	setSchemaURIResolver (SchemaURIResolver *aSchemaUriResolver)=0
  //virtual void 	setTraceStream (std::ostream &)=0
 	//virtual bool 	setXPath1_0CompatibMode (xpath1_0compatib_mode_t aMode)=0
 	//virtual bool 	setXqueryVersion (xquery_version_t aMode)=0

  void destroy() { theStaticContext = 0; }
   
}; // class StaticContext


class Zorba {
private:
  zorba::Zorba* theZorba;
  Zorba(zorba::Zorba* aZorba):theZorba(aZorba){}
public:
  Zorba():theZorba(0){}
  Zorba(const Zorba& aZorba) : theZorba(aZorba.theZorba) {}
  
  static Zorba getInstance(const Store& aStore)
  { return Zorba(zorba::Zorba::getInstance(aStore.getStore())); }
  
  XQuery compileQuery(const std::string& aStr) 
  { return XQuery(theZorba->compileQuery(aStr)); }
  
  XQuery compileQuery(const std::string& aStr, ErrorHandler* aErrorHandler)
  { return XQuery(theZorba->compileQuery(aStr, aErrorHandler)); }

  XQuery compileQuery(const std::string& aStr, StaticContext &aStaticContext, 
                      ErrorHandler* aErrorHandler)
  { 
    return XQuery(theZorba->compileQuery(aStr, aStaticContext.theStaticContext,
                                         aErrorHandler));
  }

  XQuery compileQuery(const std::string& aStr, CompilerHints &aCompilerHints, 
                      ErrorHandler* aErrorHandler)
  {
    return XQuery(theZorba->compileQuery(aStr, aCompilerHints.theCompilerHints,
                                         aErrorHandler));
  }

  XmlDataManager getXmlDataManager()
  { return XmlDataManager(theZorba->getXmlDataManager());  }

  void shutdown() 
  { theZorba->shutdown(); }
}; // class Zorba


 %}  // end Implementations

// Interfaces

class Item {
public: 
  static Item createEmptyItem();
  std::string getStringValue() const;
  std::string serialize() const;
}; // class Item

class ResultIterator {
public:
  void open();
  bool next(Item&);
  void close();
  void destroy();
}; // class ResultIterator

class XQuery {
public:
  std::string execute();
  std::string printPlanAsXML();
  std::string printPlanAsDOT();

#ifdef SWIGPYTHON
  void executeSAX(SAX2ContentHandlerProxy* contentHandlerProxy);
#endif

  bool isUpdateQuery();
  void applyUpdates();
  void destroy();
  ResultIterator iterator();
  void setVariableAsDocument(const std::string& aVarName, 
                             const std::string& aURL, 
                             const std::string& aContent);
}; // class XQuery

class Store {};

class InMemoryStore : public Store {
public:
  static InMemoryStore getInstance();
  static void shutdown(InMemoryStore&);
}; // class InMemoryStore

class XmlDataManager {
 public:
  void loadDocument(const std::string& aName, const std::string& aContent);
  bool deleteDocument(const std::string& aName);
}; // class XmlDataManager

class ZorbaException {
 private:
  ZorbaException();
 public:
  virtual std::string getDescription() const;
  virtual unsigned int getFileLineNumber () const;
  virtual std::string getFileName () const;
};

class QueryException : public ZorbaException {
 private:
  QueryException();
};

class SystemException : public ZorbaException {
 private:
  SystemException();
};

class DynamicException : public ZorbaException {
 private:
  DynamicException();
};

class SerializationException : public QueryException {
 private:
  SerializationException();
};

class StaticException : public QueryException {
 private:
  StaticException();
};

class TypeException : public QueryException {
 private:
  TypeException();
};

class UserException : public QueryException {
 private:
  UserException();
};

class ErrorHandler {
 public:
  virtual void dynamicError(const DynamicException &de); 
  /* virtual void serializationError();
  virtual void staticError();
  virtual void systemError();
  virtual void typeError();
  virtual void userError();*/
}; // class ErrorHandler

class CompilerHints {
 private:
  Zorba_CompilerHints_t theCompilerHints;
 public:
  bool getLibModule();
  void setLibModule(bool aLibModule);

  int getOptimizationLevel();
  void setOptimizationLevel(int aOptLevel);
}; // class CompilerHints


class StaticContext {
 public:
  virtual bool addColation(const std::string& aURI);  
  virtual bool addNamespace(const std::string& aPrefix, 
                            const std::string& aURI);
  void addReference() const;
  virtual bool containsFunction(const std::string &aFnNameUri, 
                                const std::string &aFnNameLocal, 
                                int arity) const =0;

  virtual StaticContext	createChildContext() const =0;
  virtual void declareOption(const Item &aQName, 
                             const std::string &aOptionVal)=0;
  virtual void disableFunction(const Item &aQName, int arity)=0;

  //virtual void 	disableFunction (const Function_t &aFunction)=0;
  //virtual void 	findFunctions (const Item &aQName, std::vector< Function_t > &aFunctions) const =0
  virtual void 	free ();
  virtual std::string 	getBaseURI () const =0;
  //virtual boundary_space_mode_t 	getBoundarySpacePolicy () const =0;
  //virtual TypeIdentifier_t 	getCollectionType (const std::string &aCollectionUri) const =0;
  //virtual CollectionURIResolver * 	getCollectionURIResolver () const =0;
  //virtual construction_mode_t 	getConstructionMode () const =0
 	//virtual TypeIdentifier_t 	getContextItemStaticType () const =0
  //virtual void 	getCopyNamespacesMode (preserve_mode_t &aPreserve, inherit_mode_t &aInherit) const =0;
  virtual std::string 	getDefaultCollation () const =0;
  virtual std::string 	getDefaultElementAndTypeNamespace () const =0;
  virtual std::string 	getDefaultFunctionNamespace () const =0;
  //virtual order_empty_mode_t 	getDefaultOrderForEmptySequences () const =0;
  //virtual TypeIdentifier_t 	getDocumentType (const std::string &aDocUri) const =0;
  //virtual DocumentURIResolver * 	getDocumentURIResolver ()=0;
  //virtual ModuleURIResolver * 	getModuleURIResolver () const =0;
  virtual std::string 	getNamespaceURIByPrefix (const std::string &aPrefix) const =0;
  virtual bool 	getOption (const Item &aQName, std::string &aOptionValue) const =0;
  //virtual ordering_mode_t 	getOrderingMode () const =0
  long 	getRefCount () const;
  virtual bool 	getRevalidationEnabled () const =0;
  //virtual validation_mode_t 	getRevalidationMode ()=0;
  //virtual SchemaURIResolver * 	getSchemaURIResolver () const =0;
  //virtual xpath1_0compatib_mode_t 	getXPath1_0CompatibMode () const =0
  //virtual xquery_version_t 	getXqueryVersion () const =0;
 	virtual void 	loadProlog (const std::string &, const Zorba_CompilerHints_t &hints)=0;
  //virtual bool 	registerStatelessExternalFunction (StatelessExternalFunction *aExternalFunction)=0
  void 	removeReference ();
  virtual void 	resetTraceStream ()=0;
  virtual bool 	setBaseURI (const std::string &aBaseURI)=0;
  //virtual bool 	setBoundarySpacePolicy (boundary_space_mode_t aMode)=0
  //virtual void 	setCollectionType (const std::string &aCollectionUri, TypeIdentifier_t type)=0
 	//virtual void 	setCollectionURIResolver (CollectionURIResolver *aCollectionUriResolver)=0
  //virtual bool 	setConstructionMode (construction_mode_t aMode)=0
  //virtual void 	setContextItemStaticType (TypeIdentifier_t type)=0
  //virtual bool 	setCopyNamespacesMode (preserve_mode_t aPreserve, inherit_mode_t aInherit)=0
  virtual bool 	setDefaultCollation (const std::string &aURI)=0;
  virtual bool 	setDefaultElementAndTypeNamespace (const std::string &aURI)=0;
  virtual bool 	setDefaultFunctionNamespace (const std::string &aURI)=0;
  //virtual bool 	setDefaultOrderForEmptySequences (order_empty_mode_t aMode)=0
  //virtual void 	setDocumentType (const std::string &aDocUri, TypeIdentifier_t type)=0
  //virtual void 	setDocumentURIResolver (DocumentURIResolver *aDocumentURIResolver)=0
  //virtual void 	setModuleURIResolver (ModuleURIResolver *aModuleUriResolver)=0
  //virtual bool 	setOrderingMode (ordering_mode_t aMode)=0
 	virtual bool 	setRevalidationEnabled (bool enabled)=0;
  //virtual void 	setRevalidationMode (validation_mode_t aMode)=0
 	//virtual void 	setSchemaURIResolver (SchemaURIResolver *aSchemaUriResolver)=0
  //virtual void 	setTraceStream (std::ostream &)=0
 	//virtual bool 	setXPath1_0CompatibMode (xpath1_0compatib_mode_t aMode)=0
 	//virtual bool 	setXqueryVersion (xquery_version_t aMode)=0
 	
  void destroy();
}; // class StaticContext


class Zorba {
 public:
  static Zorba getInstance(const Store&);
  XQuery compileQuery(const std::string& aStr);
  XQuery compileQuery(const std::string& aStr, ErrorHandler* aErrorHandler);
  XQuery compileQuery(const std::string& aStr, StaticContext &aStaticContext, 
                      ErrorHandler* aErrorHandler);
  XQuery compileQuery(const std::string& aStr, CompilerHints &aCompilerHints, 
                      ErrorHandler* aErrorHandler);
  XmlDataManager getXmlDataManager();
  void shutdown();
}; // class Zorba

