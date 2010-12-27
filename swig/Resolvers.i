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


%{  /////////////// Implementations

#include <zorba/uri_resolvers.h>

  
  class URIResolverResult
  {
  public:
    enum ErrorCode
      {
        UR_NOERROR,
        // documents and collections
        UR_FODC0002,
        UR_FODC0003,
        UR_FODC0004,
        UR_FODC0005,
        // modules
        UR_XQST0088,
        UR_XQST0046,
        UR_XQST0059,
        // schemas
        UR_XQST0057
      };
    
    URIResolverResult()
      : theErrorCode(UR_NOERROR) {}
    
    virtual ~URIResolverResult() {}
    
    ErrorCode getError() const { return theErrorCode; }
    
    void setError(const ErrorCode& aErrorCode) { theErrorCode = aErrorCode; }
    
    void setErrorDescription(const std::string& aDescription) 
    { theDescription = aDescription; }
    
    std::string getErrorDescription() { return theDescription; }
    
  protected:
    ErrorCode    theErrorCode;
    std::string  theDescription;
  };
  
  class DocumentURIResolverResult : public URIResolverResult
  {
    friend class DocumentURIResolver;
  protected:
    zorba::DocumentURIResolverResult *theResult;
    DocumentURIResolverResult() {}

  public:
    virtual ~DocumentURIResolverResult() {}
    
    // TODO make this function throw()
    virtual Item getDocument() const =0;
  };
  
  class MyDocumentURIResolverResult : public zorba::DocumentURIResolverResult
  {
  private:
    zorba::Item theDocument;
  public:
    MyDocumentURIResolverResult(zorba::Item aDoc) : theDocument(aDoc) {};
    virtual zorba::Item getDocument() const 
    { return theDocument; }
  };
  
  class DocumentURIResolver : protected zorba::DocumentURIResolver
  {
  public:
    virtual ~DocumentURIResolver() {}
    
  private:
    virtual std::auto_ptr<zorba::DocumentURIResolverResult>
      resolve(const zorba::Item& aURI,
            zorba::StaticContext* aStaticContext,
            zorba::XmlDataManager* aXmlDataManager,
            bool validate,
            bool tidying,
            bool replaceDoc,
            const zorba::Item& aTidyUserOpt) 
    { 
      Item newURI = Item::createEmptyItem();
      newURI.theItem = aURI;

      StaticContext newStaticContext(aStaticContext);
      XmlDataManager newXmlDataManager(aXmlDataManager);
      Item newTidyUserOpt = Item::createEmptyItem();
      newTidyUserOpt.theItem = aTidyUserOpt;

      DocumentURIResolverResult* result = 
        resolve(newURI, &newStaticContext, 
                 &newXmlDataManager, validate,
                 tidying, replaceDoc, newTidyUserOpt);
      
      std::auto_ptr<zorba::DocumentURIResolverResult> myRes ; //=
        (new MyDocumentURIResolverResult(result->getDocument().theItem)); 
      return myRes;
    }

  public:
    // swig error when using auto_ptr<>
    //virtual std::auto_ptr<DocumentURIResolverResult>
    //  resolve2(const Item& aURI,
    //        StaticContext* aStaticContext,
    //        XmlDataManager* aXmlDataManager,
    //        bool validate,
    //        bool tidying,
    //        bool replaceDoc,
    //        const Item& aTidyUserOpt) =0;
    virtual DocumentURIResolverResult* resolve(const Item& aURI,
            StaticContext* aStaticContext,
            XmlDataManager* aXmlDataManager,
            bool validate,
            bool tidying,
            bool replaceDoc,
            const Item& aTidyUserOpt) = 0;
  };




  /*
  class CollectionURIResolverResult : public URIResolverResult
  {
    friend class CollectionURIResolver;
  protected:
    zorba::CollectionURIResolverResult *theResult;
    CollectionURIResolverResult() {}

  public:
    virtual ~CollectionURIResolverResult() {}
    
    virtual Collection getCollection() const =0;
  };
  
  class MyCollectionURIResolverResult 
    : public zorba::CollectionURIResolverResult
  {
  private:
    zorba::Collection theCollection;
  public:
    MyCollectionURIResolverResult(zorba::Item aCol) : theCollection (aCol) {};
    virtual zorba::Collection getCollection() const 
    { return theCollection; }
  };
  
  class CollectionURIResolver : protected zorba::CollectionURIResolver
  {
  public:
    virtual ~CollectionURIResolver() {}
    
  private:
    virtual std::auto_ptr<zorba::CollectionURIResolverResult>
      resolve(const zorba::Item& aURI,
            zorba::StaticContext* aStaticContext,
            zorba::XmlDataManager* aXmlDataManager,
            bool validate,
            bool tidying,
            const zorba::Item& aTidyUserOpt) 
    { 
      Item newURI = Item::createEmptyItem();
      newURI.theItem = aURI;

      StaticContext newStaticContext(aStaticContext);
      XmlDataManager newXmlDataManager(aXmlDataManager);

      CollectionURIResolverResult* result = 
        resolve(newURI, &newStaticContext, 
                 &newXmlDataManager);
      
      std::auto_ptr<zorba::CollectionURIResolverResult> myRes =
        (new MyCollectionURIResolverResult(result->getCollection())); 
      return myRes;
    }

  public:
    // swig error when using auto_ptr<>
    //virtual std::auto_ptr<DocumentURIResolverResult>
    //  resolve2(const Item& aURI,
    //        StaticContext* aStaticContext,
    //        XmlDataManager* aXmlDataManager) =0;    
    virtual CollectionURIResolverResult* resolve(const Item& aURI,
            StaticContext* aStaticContext,
            XmlDataManager* aXmlDataManager) = 0;
  };
 
  
  class CollectionURIResolverResult : public URIResolverResult
  {
    public:
      virtual ~CollectionURIResolverResult() {}

      virtual Collection_t
      getCollection() const = 0;
  };

  class CollectionURIResolver
  {
    public:
      virtual ~CollectionURIResolver() {}

      virtual std::auto_ptr<CollectionURIResolverResult>
      resolve(const Item& aURI,
              StaticContext* aStaticContext,
              XmlDataManager* aXmlDataManager) = 0;
  };

  class SchemaURIResolverResult : public URIResolverResult 
  {
    public:
      virtual ~SchemaURIResolverResult() {}

      virtual Item
      getSchema() const = 0;
  };

  class SchemaURIResolver
  {
    public:
      virtual ~SchemaURIResolver() {}
      
      virtual std::auto_ptr<SchemaURIResolverResult>
      resolve(const Item& aURI,
              const std::vector<Item>& aLocationHints,
              StaticContext* aStaticContext) = 0;
  };

  class ModuleURIResolverResult : public URIResolverResult
  {
    public:
      virtual ~ModuleURIResolverResult() {}

      virtual std::istream*
      getModule() const = 0;
  };

  class ModuleURIResolver
  {
    public:
      virtual ~ModuleURIResolver() {}

      virtual std::auto_ptr<ModuleURIResolverResult>
      resolve(const Item& aURI,
              StaticContext* aStaticContext,
              String* aFileUri = 0) = 0;
  };

*/
%}  //////////////// end Implementations

    // Interface

class URIResolverResult
{
public:
  enum ErrorCode
    {
      UR_NOERROR,
      // documents and collections
      UR_FODC0002,
      UR_FODC0003,
      UR_FODC0004,
      UR_FODC0005,
      // modules
      UR_XQST0088,
      UR_XQST0046,
      UR_XQST0059,
      // schemas
      UR_XQST0057
    };
  
  URIResolverResult();
  virtual ~URIResolverResult();
  
  ErrorCode   getError() const;
  void        setError(const ErrorCode& aErrorCode);
  
  void        setErrorDescription(const std::string& aDescription);
  std::string getErrorDescription();

protected:
  ErrorCode theErrorCode;
  std::string    theDescription;
};

class DocumentURIResolverResult : public URIResolverResult
{
protected:
  DocumentURIResolverResult();
public:
  virtual ~DocumentURIResolverResult();
  
  // TODO make this function throw()
  virtual Item getDocument() const;
};


class DocumentURIResolver
{
private:
  virtual ~DocumentURIResolver();
  
public:  
  /* swig error when using auto_ptr<>
  virtual std::auto_ptr<DocumentURIResolverResult>
    resolve2(const Item& aURI,
    StaticContext* aStaticContext,
    XmlDataManager* aXmlDataManager,
    bool validate,
    bool tidying,
    const Item& aTidyUserOpt) =0;*/
  virtual DocumentURIResolverResult* resolve(const Item& aURI,
            StaticContext* aStaticContext,
            XmlDataManager* aXmlDataManager,
            bool validate,
            bool tidying,       
            bool replaceDoc,
            const Item& aTidyUserOpt) = 0;
};


