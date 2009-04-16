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

//#include <map>
#include <fstream>
#include <string>
//#include <vector>

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
  std::ifstream urifile ( map_file );
  if ( urifile.good () == false ) return;
  std::string uris;
  std::string::size_type start = 0;
  std::getline ( urifile, uris );
  while ( true ) {
    std::string::size_type pos = uris.find ( ' ', start );
    if ( pos == std::string::npos ) break;
    std::string::size_type eq = uris.find ( '=', start );
    std::string::size_type len = eq - start;
    String uri ( uris.substr ( start, len ) );
    len = pos - eq - 1;
    String file ( url );
    const char * xsd = uris.substr ( eq+1, len ).c_str(); 
    file.append ( xsd );
    uri_map [ uri ] = file;
    start = pos + 1;
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

