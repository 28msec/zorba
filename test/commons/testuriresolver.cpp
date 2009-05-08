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

#include "testuriresolver.h"

#include <zorba/zorba.h>
#include <zorbautils/strutil.h>
#include <cassert>

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace zorba;



zorba::TestSchemaURIResolverResult::~TestSchemaURIResolverResult()
{}

Item zorba::TestSchemaURIResolverResult::getSchema () const
{
  return theSchema;
}

zorba::TestSchemaURIResolver::TestSchemaURIResolver( const char * file ) :
  map_file ( file )
{}

zorba::TestSchemaURIResolver::~TestSchemaURIResolver() {}

void zorba::TestSchemaURIResolver::initialize ()
{
  std::string path ( map_file );
  std::string::size_type slash = path.find_last_of ( '/' );
  path.erase ( slash );
  path += "/w3c_testsuite/";
  std::string url ( "file://" );
  url += path;
  std::ifstream urifile ( map_file.c_str() );
  if ( urifile.good () == false ) return;
  std::string uris;
  std::string::size_type start = 0;
  std::getline ( urifile, uris );
  while ( true ) {
    bool last = false;
    std::string::size_type pos = uris.find_first_of ( ' ', start );
    if ( pos == std::string::npos ) {
      pos = uris.size ();
      last = true;
    }
    std::string::size_type eq = uris.find ( '=', start );
    std::string::size_type len = eq - start;
    String uri ( uris.substr ( start, len ) );
    len = pos - eq - 1;
    String file ( url );
    const char * xsd = uris.substr ( eq+1, len ).c_str(); 
    file.append ( xsd );
    uri_map [ uri ] = file;
    start = pos + 1;
    if ( last ) break;
  }

  urifile.close();
}


std::auto_ptr<SchemaURIResolverResult>
zorba::TestSchemaURIResolver::resolve ( const Item & aURI,
				 const std::vector <Item> & aLocationHint,
				 StaticContext * aStaticContext )
  {
    if ( uri_map.empty () ) {
      initialize ();
    }
    std::auto_ptr<TestSchemaURIResolverResult>
      result ( new TestSchemaURIResolverResult () );
    String request = aURI.getStringValue ();
    std::map <String, String >::iterator it = uri_map.find ( request );
    if ( it != uri_map.end () ) {
      const String  target = uri_map [ request ];
      Zorba * zorba = Zorba::getInstance ( 0 );
      ItemFactory * factory = zorba -> getItemFactory ();
      Item item = factory -> createAnyURI ( target );
      result -> theSchema = item;
      
    } else {
      result -> theSchema = aURI;
    }

    return std::auto_ptr<SchemaURIResolverResult> ( result );
  }

std::istream *
zorba::TestModuleURIResolverResult::getModule () const
{
  return theModule;
}

zorba::TestModuleURIResolver::TestModuleURIResolver ( const char * file ) :
  map_file ( file )
{}

void zorba::TestModuleURIResolver::initialize ()
{
  std::string path ( map_file );
  std::string::size_type slash = path.find_last_of ( '/' );
  path.erase ( slash );
  slash = path.find_last_of ( '/' );
  path.erase ( slash );
  std::string url ( "file://" );
  std::ifstream urifile ( map_file.c_str() );
  if ( urifile.good () == false ) return;
  std::string uris;
  std::string::size_type start = 0;
  std::getline ( urifile, uris );
  while ( true ) {
    bool last = false;
    std::string::size_type pos = uris.find_first_of ( ' ', start );
    if ( pos == std::string::npos ) {
      pos = uris.size ();
      last = true;
    }
    std::string::size_type eq = uris.find ( '=', start );
    std::string::size_type len = eq - start;
    String uri ( uris.substr ( start, len ) );
    len = pos - eq - 1;
    String file ( path );
    const char * xsd = uris.substr ( eq+1, len ).c_str(); 
    file.append ("/");
    file.append ( xsd );
    file.append ( ".xqi" );
    uri_map [ uri ] = file;
    start = pos + 1;
    if ( last ) break;
  }

  urifile.close();
}

zorba::TestModuleURIResolver::~TestModuleURIResolver ()
{}

std::auto_ptr < ModuleURIResolverResult >
zorba::TestModuleURIResolver::
resolve ( const Item & aURI, StaticContext* aStaticContext )
{
  if ( uri_map.empty () ) {
    initialize ();
  }
  std::auto_ptr < TestModuleURIResolverResult >
    lResult ( new TestModuleURIResolverResult () );

  String request = aURI.getStringValue ();
  std::map < String, String > :: iterator it = uri_map.find ( request );
  if ( it != uri_map.end () ) {
    const String target = uri_map [ request ];
    const char * file = target.c_str();
    lResult -> theModule = new std::ifstream ( file );
    lResult -> setError ( URIResolverResult::UR_NOERROR );
  } else {
    lResult -> setError ( URIResolverResult::UR_XQST0059 );
    std::stringstream lErrorStream;
    lErrorStream << "Module not found " << aURI.getStringValue();
    lResult->setErrorDescription(lErrorStream.str());
  }
  return std::auto_ptr<ModuleURIResolverResult>(lResult.release());
}

// Collection Resolver
Collection_t
zorba::TestCollectionURIResolverResult::getCollection () const
{
  return theCollection;
}

zorba::TestCollectionURIResolver::TestCollectionURIResolver ( const char * file, const std::string& rbkt_src_dir ) :
  map_file ( file ),
  rbkt_src ( rbkt_src_dir )
{}

void
std_string_tokenize(const std::string& aStr, const std::string& aDelims, std::vector<std::string>& aTokens, const std::string& rbkt_src)
{
  std::string::size_type lastPos = aStr.find_first_not_of(aDelims, 0); 
  std::string::size_type pos     = aStr.find_first_of(aDelims, lastPos);

  while (std::string::npos != pos || std::string::npos != lastPos) {   
    // Found a token, add it to the vector.
    aTokens.push_back(aStr.substr(lastPos, pos - lastPos));
    zorba::str_replace_all(aTokens.back(), "$RBKT_SRC_DIR", rbkt_src);

    lastPos = aStr.find_first_not_of(aDelims, pos);
    pos = aStr.find_first_of(aDelims, lastPos);
  }
}


void zorba::TestCollectionURIResolver::trim(std::string& str)
{
  std::string::size_type pos = str.find_last_not_of(' ');
  if(pos != std::string::npos) {
    str.erase(pos + 1);
    pos = str.find_first_not_of(' ');
    if(pos != std::string::npos) str.erase(0, pos);
  }
  else str.erase(str.begin(), str.end());
}

void zorba::TestCollectionURIResolver::initialize ()
{
  std::ifstream urifile ( map_file.c_str() );
  if ( urifile.bad() ) return;

  while ( !urifile.eof() ) {
    std::string lCollectionMapping;
    std::getline( urifile, lCollectionMapping );

    if (lCollectionMapping.size() == 0) continue;

    std::string::size_type eq = lCollectionMapping.find ( '=' );
    assert(eq != std::string::npos);

    std::string id ( lCollectionMapping.substr ( 0, eq ) );
    trim(id);

    std::vector<std::string>& lCollections = uri_map[id];

    std_string_tokenize(lCollectionMapping.substr(eq+1), ";", lCollections, rbkt_src);
  }
}

zorba::TestCollectionURIResolver::~TestCollectionURIResolver ()
{}

std::auto_ptr < CollectionURIResolverResult >
zorba::TestCollectionURIResolver::
resolve ( const Item & aURI, StaticContext* aStaticContext, XmlDataManager* aXmlDataManager )
{
  if ( uri_map.empty () ) {
    initialize ();
  }
  std::auto_ptr < TestCollectionURIResolverResult >
    lResult ( new TestCollectionURIResolverResult () );

  std::string request = aURI.getStringValue ().c_str();
  std::string search  = request.substr(request.find_last_of('/')+1);
  std::map < std::string, std::vector<std::string> > :: iterator it = uri_map.find ( search );
  if ( it != uri_map.end () ) {
    const std::vector<std::string>& target = it->second;
    Collection_t lCol = aXmlDataManager->getCollection(request);
    if (lCol.isNull())  {
      lCol = aXmlDataManager->createCollection(request);
      for (std::vector<std::string>::const_iterator lIter = target.begin();
          lIter != target.end(); ++lIter) {
        std::ifstream lIn(lIter->c_str());
        assert(lIn.good());
  
        lCol->addDocument(lIn);
      }
    }
    lResult -> theCollection = lCol;
    lResult -> setError ( URIResolverResult::UR_NOERROR );
  } else {
    lResult -> setError ( URIResolverResult::UR_FODC0004 );
    std::stringstream lErrorStream;
    lErrorStream << "Collection not found " << aURI.getStringValue();
    lResult->setErrorDescription(lErrorStream.str());
  }
  return std::auto_ptr<CollectionURIResolverResult>(lResult.release());
}

