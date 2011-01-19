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
#include <zorba/zorbastring.h>
#include "util/ascii_util.h"
#include "zorba/util/uri.h"
#include <cassert>

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

namespace zorba
{



/******************************************************************************
 "Document resolver"
*******************************************************************************/
TestDocumentURIResolver::TestDocumentURIResolver(zorba::String aBaseFile)
{
  theBaseFile = URIHelper::encodeFileURI(aBaseFile);
}

TestDocumentURIResolver::~TestDocumentURIResolver()
{
}

TestDocumentURIResolverResult::~TestDocumentURIResolverResult()
{
}

Item
TestDocumentURIResolverResult::getDocument() const
{
  return theDocument;
}

std::auto_ptr<DocumentURIResolverResult>
TestDocumentURIResolver::resolve(const Item& aURI,
  StaticContext* aStaticContext,
  XmlDataManager* aXmlDataManager,
  bool validateUri,
  bool tidying,
  bool replaceDoc,
  const Item& aTidyUserOpt)
{
  zorba::String lUri = aURI.getStringValue();
  if (lUri.startsWith("test://")) {
    lUri = theBaseFile + lUri.substring(7);
  }
  std::auto_ptr<TestDocumentURIResolverResult> lResult
    (new TestDocumentURIResolverResult());
  try {
    lResult->theDocument =
      aXmlDataManager->loadDocumentFromUri(lUri, replaceDoc);
  }
  catch (ZorbaException &e) {
    lResult->setError(URIResolverResult::UR_FODC0002);
    lResult->setErrorDescription(e.getDescription());
  }
  return std::auto_ptr<DocumentURIResolverResult>(lResult.release());
}


/******************************************************************************

*******************************************************************************/
TestSchemaURIResolverResult::~TestSchemaURIResolverResult()
{
}


String TestSchemaURIResolverResult::getSchema() const
{
  return theSchema;
}


TestSchemaURIResolver::TestSchemaURIResolver(const char* file, bool verbose) 
  :
  map_file ( file ),
  theVerbose(verbose)  
{
}


TestSchemaURIResolver::~TestSchemaURIResolver() 
{
}


void TestSchemaURIResolver::initialize()
{
  std::string path ( map_file );
  for (int i = 0; i < 2; i++) {
    std::string::size_type slash = path.find_last_of ( '/' );
    assert (slash != std::string::npos);
    path.erase ( slash );
  }
  path += "/";
#ifndef WIN32
  std::string url ( "file://" );
#else
  std::string url ( "file:///" );
#endif
  url += path;
  std::ifstream urifile ( map_file.c_str() );
  if ( urifile.good () == false ) return;
  std::string uris;
  while (std::getline (urifile, uris)) {
    std::string::size_type eq = uris.find ('=');
    String uri (uris.substr (0, eq));
    String file (url + uris.substr (eq+1).c_str());
    uri_map [uri] = file;
  }

  urifile.close();
}


std::auto_ptr<SchemaURIResolverResult>
TestSchemaURIResolver::resolve (
    const Item & aURI,
    StaticContext * aStaticContext,
    std::vector<Item>& aAtList,
    String* aFileURI)
{
  if ( uri_map.empty () ) {
    initialize ();
  }
  std::auto_ptr<TestSchemaURIResolverResult>result(new TestSchemaURIResolverResult());
  String request = aURI.getStringValue ();
  std::map <String, String >::iterator it = uri_map.find ( request );
  if ( it != uri_map.end () ) {
    const String  target = uri_map [ request ];
    result -> theSchema = target;

    if (theVerbose)
      std::cout << "Resolved schema " << aURI.getStringValue () << " -> " 
                << result->theSchema << std::endl;
  } else {
    // todo Location hint is not used at all
    result -> setError ( URIResolverResult::UR_XQST0059 );
    std::stringstream lErrorStream;
    lErrorStream << "Schema not found " << aURI.getStringValue();
    //std::cerr << "Schema not found " << aURI.getStringValue() << std::endl;
    result->setErrorDescription(lErrorStream.str());
  }
  
  return std::auto_ptr<SchemaURIResolverResult> ( result );
}


/******************************************************************************

*******************************************************************************/
void TestModuleURIResolverResult::getComponentURIs(std::vector<std::string>& uris) const
{
  uris = theComponentURIs;
}


TestModuleURIResolver::TestModuleURIResolver(
    const char* file,
    const std::string& test,
    bool verbose) 
  :
  theMapFile(file),
  theTest(test),
  theVerbose(verbose)
{
}


TestModuleURIResolver::TestModuleURIResolver(
    const char* file,
    bool verbose) 
  :
  theMapFile(file),
  theVerbose(verbose)
{
  initialize();
}


TestModuleURIResolver::~TestModuleURIResolver ()
{
}


void TestModuleURIResolver::initialize()
{
  std::string::size_type pos;
  std::string pfx;

  if (theTest.empty())
  {
    pfx = "w3c_testsuite/XQuery/";
  }
  else
  {
    pos = theTest.find_first_of ('/');
    if (pos != std::string::npos && theTest.substr(0, pos) == "w3c_testsuite")
    {
      pos = theTest.find_first_of('/', pos + 1);
    }
    else
    {
#ifndef MY_D_WIN32
      return;
#endif
    }

    pfx = theTest.substr(0, pos) + "/";
  }

  // set "path" to <zorba-root-dir>/test/rbkt/Queries/w3c_testsuite 
  std::string path(theMapFile);
  std::string::size_type slash = path.find_last_of ( '/' );
  path.erase(slash);
  slash = path.find_last_of('/');
  path.erase(slash);

  // Process theMapFile
  std::ifstream urifile(theMapFile.c_str());
  std::string uris;

  while (std::getline(urifile, uris)) 
  {
    uris = pfx + uris;
    pos = uris.find_first_of (':');
    assert(pos != std::string::npos);

    if (uris.substr(0, pos) != theTest)
      continue;

    uris = uris.substr(pos + 1);

    std::string::size_type eq = uris.find('=');
    std::string uri(uris.substr(0, eq));
#ifdef WIN32
    std::string file("file:///");
#else
    std::string file("file://");
#endif
    file.append(path);
    file = file.append("/");
    file = file.append(uris.substr(eq+1).c_str());
    file = file.append(".xqi");

    theUriMap.insert(std::pair<std::string, std::string>(uri, file));
  }

  urifile.close();
}


std::auto_ptr<ModuleURIResolverResult> TestModuleURIResolver::resolveTargetNamespace(
    const String& nsURI,
    const StaticContext& sctx)
{
  if (theUriMap.empty()) 
  {
    initialize();
  }

  std::auto_ptr<TestModuleURIResolverResult> result(new TestModuleURIResolverResult());

  std::pair<UriMap::const_iterator, UriMap::const_iterator> range;

  std::string localNsURI = nsURI.c_str();

  range = theUriMap.equal_range(localNsURI);

  if (range.first == range.second)
  {
    result->setError(URIResolverResult::UR_XQST0059);
    std::stringstream lErrorStream;
    lErrorStream << "Module not found " << nsURI;
    //std::cerr << "Module not found " << nsURI << std::endl;
    result->setErrorDescription(lErrorStream.str());
  }

  UriMap::const_iterator ite;
  for (ite = range.first; ite != range.second; ++ite)
  {
    result->theComponentURIs.push_back(ite->second);
    if (theVerbose)
      std::cout << "Resolved module " << nsURI << " -> " << ite->second << std::endl;
  }

  return std::auto_ptr<ModuleURIResolverResult>(result.release());
}


std::auto_ptr<ModuleURIResolverResult> TestModuleURIResolver::resolve(
    const String& uri,
    const StaticContext& sctx)
{
  if (theUriMap.empty()) 
  {
    initialize();
  }

  std::auto_ptr<TestModuleURIResolverResult> result(new TestModuleURIResolverResult());

  std::string filename = uri.c_str();
#ifdef WIN32
  filename = filename.substr(8); // strip the "file:///" prefix
#else
  filename = filename.substr(7); // strip the "file://" prefix
#endif

  result->theModule = new std::ifstream(filename.c_str());

  if (result->theModule->good())
  {
    result->setError(URIResolverResult::UR_NOERROR);
  }
  else
  {
    result->setError(URIResolverResult::UR_XQST0059);
    std::stringstream lErrorStream;
    lErrorStream << "Module file not found " << filename;
    //std::cerr << "Module file not found " << filename << std::endl;
    result->setErrorDescription(lErrorStream.str());
    delete result->theModule;
    result->theModule = 0;
  }

  return std::auto_ptr<ModuleURIResolverResult>(result.release());
}


/******************************************************************************
  Collection Resolver
*******************************************************************************/
Collection_t
TestCollectionURIResolverResult::getCollection () const
{
  return theCollection;
}


TestCollectionURIResolver::TestCollectionURIResolver ( const char * file, const std::string& rbkt_src_dir ) 
  :
  map_file ( file ),
  rbkt_src ( rbkt_src_dir )
{
}


TestCollectionURIResolver::~TestCollectionURIResolver ()
{
}


void
std_string_tokenize(
    const std::string& aStr,
    const std::string& aDelims,
    std::vector<std::string>& aTokens,
    const std::string& rbkt_src)
{
  std::string::size_type lastPos = aStr.find_first_not_of(aDelims, 0); 
  std::string::size_type pos     = aStr.find_first_of(aDelims, lastPos);

  while (std::string::npos != pos || std::string::npos != lastPos) {   
    // Found a token, add it to the vector.
    aTokens.push_back(aStr.substr(lastPos, pos - lastPos));
    zorba::ascii::replace_all(aTokens.back(), "$RBKT_SRC_DIR", rbkt_src);

    lastPos = aStr.find_first_not_of(aDelims, pos);
    pos = aStr.find_first_of(aDelims, lastPos);
  }
}


void TestCollectionURIResolver::trim(std::string& str)
{
  std::string::size_type pos = str.find_last_not_of(' ');
  if(pos != std::string::npos) {
    str.erase(pos + 1);
    pos = str.find_first_not_of(' ');
    if(pos != std::string::npos) str.erase(0, pos);
  }
  else str.erase(str.begin(), str.end());
}


void TestCollectionURIResolver::initialize()
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


std::auto_ptr<CollectionURIResolverResult>
TestCollectionURIResolver::resolve(
    const Item & aURI,
    StaticContext* aStaticContext,
    XmlDataManager* aXmlDataManager)
{
  if ( uri_map.empty () ) 
  {
    initialize ();
  }

  std::auto_ptr<TestCollectionURIResolverResult>
    lResult ( new TestCollectionURIResolverResult() );

  std::string request = aURI.getStringValue().c_str();
  std::string search  = request.substr(request.find_last_of('/')+1);
  std::map<std::string, std::vector<std::string> >::iterator it = uri_map.find(search);
  if ( it != uri_map.end() ) 
  {
    const std::vector<std::string>& target = it->second;
    Collection_t lCol = aXmlDataManager->getCollection(request);
    if (lCol.isNull())
    {
      lCol = aXmlDataManager->createCollection(request);
      for (std::vector<std::string>::const_iterator lIter = target.begin();
          lIter != target.end(); ++lIter)
      {
        std::ifstream lIn(lIter->c_str());
        assert(lIn.good());
  
        lCol->addDocument(lIn);
      }
    }
    lResult -> theCollection = lCol;
    lResult -> setError ( URIResolverResult::UR_NOERROR );
  }
  else
  {
    lResult -> setError ( URIResolverResult::UR_FODC0004 );
    std::stringstream lErrorStream;
    lErrorStream << "Collection not found " << aURI.getStringValue();
    lResult->setErrorDescription(lErrorStream.str());
  }
  return std::auto_ptr<CollectionURIResolverResult>(lResult.release());
}


}
