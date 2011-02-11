/* -*- mode:c++ -*-
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

#ifndef ZORBA_TESTURIRESOLVER_H
#define ZORBA_TESTURIRESOLVER_H

#include <zorba/uri_resolvers.h>
#include <zorba/serialization_callback.h>

#include <map>
#include <vector>

namespace zorba 
{

/******************************************************************************

*******************************************************************************/
class TestDocumentURIResolverResult : public DocumentURIResolverResult
{
  protected:
    friend class TestDocumentURIResolver;
    Item theDocument;

  public:
    virtual ~TestDocumentURIResolverResult();
    virtual Item getDocument() const;
};


/******************************************************************************

*******************************************************************************/
class TestDocumentURIResolver : public DocumentURIResolver
{
  public:
    TestDocumentURIResolver(String aBaseFile);
    virtual ~TestDocumentURIResolver();

  virtual std::auto_ptr<DocumentURIResolverResult>
  resolve(const Item& aURI,
          StaticContext* aStaticContext,
          XmlDataManager* aXmlDataManager,
          bool validateUri,
          bool replaceDoc = false);
  private:
    String theBaseFile;
};



/******************************************************************************

*******************************************************************************/
class TestSchemaURIResolverResult : public SchemaURIResolverResult
{
protected:
  friend class TestSchemaURIResolver;

  String theSchema;

public:
  virtual ~TestSchemaURIResolverResult();

  virtual String getSchema () const;
};


/******************************************************************************

*******************************************************************************/
class TestSchemaURIResolver : public SchemaURIResolver 
{
private:
  std::string                map_file;
  std::map< String, String > uri_map;
  bool                       theVerbose;

public:
  TestSchemaURIResolver(const char* file, bool verbose = true);

  virtual ~TestSchemaURIResolver();

  virtual std::auto_ptr<SchemaURIResolverResult>
  resolve(const Item & aURI,
          StaticContext * aStaticContext,
          std::vector<Item>& aAtList,
          String* aFileUri = 0);

private:
  void initialize ();
};


/******************************************************************************

*******************************************************************************/
class TestModuleURIResolver : public ModuleURIResolver
{
  typedef std::multimap<std::string, std::string> UriMap;

private:
  std::string    theMapFile;
  std::string    theTest;
  bool           theVerbose;

  UriMap         theUriMap;

public :
  TestModuleURIResolver(
        const char* file,
        const std::string& test,
        bool verbode = true);

  TestModuleURIResolver(
        const char* file,
        bool verbode = true);

  virtual ~TestModuleURIResolver();

  void setTest(const std::string& test) { theTest = test; }

  std::auto_ptr<ModuleURIResolverResult> resolveTargetNamespace(
        const String& aTargetNamespaceURI,
        const StaticContext& aStaticContext);

  std::auto_ptr<ModuleURIResolverResult> resolve(
        const String&,
        const StaticContext& aStaticContext);

private:
  void initialize();
};


/******************************************************************************

*******************************************************************************/
class TestModuleURIResolverResult : public ModuleURIResolverResult
{
  friend class TestModuleURIResolver;

protected:
  std::istream             * theModule;
  std::vector<std::string>   theComponentURIs;

public:
  std::istream* getModuleStream() const { return theModule; }

  void getModuleURL(std::string& url) const { }

  void getComponentURIs(std::vector<std::string>& uris) const;
};


/******************************************************************************

*******************************************************************************/
class TestCollectionURIResolver : public CollectionURIResolver
{
private:
  std::string map_file;
  std::string  rbkt_src;
  std::map < std::string, std::vector<std::string> > uri_map;

public :
  TestCollectionURIResolver ( const char * file, const std::string& rbkt_src_dir );

  virtual ~TestCollectionURIResolver ();

  static void
  trim(std::string& str);

  virtual std::auto_ptr< CollectionURIResolverResult >
  resolve ( const Item &, StaticContext * aStaticContext, XmlDataManager* aXmlDataManager );
  void initialize ();
};


/******************************************************************************

*******************************************************************************/
class TestCollectionURIResolverResult : public CollectionURIResolverResult
{
protected:
  friend class TestCollectionURIResolver;

  Collection_t theCollection;

public:
  virtual Collection_t
  getCollection ( ) const;
};


class TestSerializationCallback : public zorba::SerializationCallback
{
  CollectionURIResolver *my_collection_resolver;
  ModuleURIResolver *my_module_resolver;
  public:
    TestSerializationCallback(CollectionURIResolver* my_collection_resolver,
                              ModuleURIResolver* my_module_resolver)
    {
      this->my_collection_resolver = my_collection_resolver;
      this->my_module_resolver = my_module_resolver;
    }
                              
    virtual ~TestSerializationCallback() {}

    virtual ExternalModule*
      getExternalModule(const String& aURI) const {return NULL;}

    virtual bool
      getTraceStream(std::ostream*&) const { return false; }

    virtual CollectionURIResolver*
      getCollectionURIResolver() const {return my_collection_resolver;}

    virtual DocumentURIResolver*
      getDocumentURIResolver() const {return NULL;}

    virtual ModuleURIResolver*
      getModuleURIResolver(size_t /*i*/) const { return my_module_resolver; }
};

#ifndef ZORBA_NO_FULL_TEXT
/******************************************************************************

*******************************************************************************/
class TestFullTextURIResolverResult: public FullTextURIResolverResult
{
  public:
    virtual String getResolvedFullText() const { return theFullText; }
  
  protected:
    friend class TestFullTextURIResolver;
    String theFullText;
};

class TestFullTextURIResolver: public FullTextURIResolver
{
  public:
    virtual ~TestFullTextURIResolver();
  
    virtual std::auto_ptr<FullTextURIResolverResult>
    resolve(
      const Item& aURI,
      StaticContext* aStaticContext);
  
    public:
      void
      add_mapping(const std::string& aURI, const std::string& aValue);
  
  protected:
    typedef std::map<std::string, std::string> Mapping_t;
    typedef Mapping_t::const_iterator          MappingIter_t;
    Mapping_t theMappings;
};
#endif


} // namespace zorba

#endif /* ZORBA_TESTURIRESOLVER_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
