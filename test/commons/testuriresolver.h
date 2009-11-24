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
#include <zorba/uri_resolvers.h>
#include <zorba/serialization_callback.h>

#include <map>
#include <vector>

namespace zorba 
{

class TestSchemaURIResolverResult : public SchemaURIResolverResult
{
protected:
  friend class TestSchemaURIResolver;

  String theSchema;

public:
  virtual ~TestSchemaURIResolverResult();

  virtual String getSchema () const;
};


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


class TestModuleURIResolver : public ModuleURIResolver
{
private:
  std::string                  map_file;
    std::string                theTest;
  std::map < String, String >  uri_map;
  bool                         theVerbose;

public :
  TestModuleURIResolver (
        const char* file,
        const std::string& test,
        bool verbode = true);

  TestModuleURIResolver (
        const char* file,
        bool verbode = true);

  virtual ~TestModuleURIResolver ();

  void setTest(const std::string& test) { theTest = test; }

  virtual std::auto_ptr< ModuleURIResolverResult >
  resolve ( const Item &, StaticContext * aStaticContext, String* aFileUri = 0 );

private:
  void initialize ();
};


class TestModuleURIResolverResult : public ModuleURIResolverResult
{
protected:
  friend class TestModuleURIResolver;

  std::istream * theModule;

public:
  virtual std::istream * getModule ( ) const;
};


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
  public:
    TestSerializationCallback(CollectionURIResolver* my_collection_resolver)
    {
      this->my_collection_resolver = my_collection_resolver;
    }
                              
    virtual ~TestSerializationCallback() {}

    virtual ExternalModule*
      getExternalModule(const String& aURI) const {return NULL;}

    virtual bool
      getTraceStream(std::ostream&) const {return NULL;}

    virtual CollectionURIResolver*
      getCollectionURIResolver() const {return my_collection_resolver;}

    virtual DocumentURIResolver*
      getDocumentURIResolver() const {return NULL;}
};


} // namespace zorba
