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
#include <zorba/zorba_string.h>
#include <zorba/zorba_exception.h>
#include <zorba/singleton_item_sequence.h>
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
 URIMapper for "test:" URI scheme.
*******************************************************************************/
TestSchemeURIMapper::TestSchemeURIMapper(String aBaseFile)
  : theBaseFile(aBaseFile)
{
}

TestSchemeURIMapper::~TestSchemeURIMapper()
{
}

void
TestSchemeURIMapper::mapURI(const String aURI, EntityData const* aEntityData,
                            std::vector<String>& oUris) throw()
{
  if (ascii::begins_with(aURI, "test://")) {
    String lFileURI = URIHelper::encodeFileURI(theBaseFile + aURI.substr(7));
    oUris.push_back((lFileURI));
  }
}


/******************************************************************************
  Mostly pointless URLResolver; really only here to check plan serialization
  of URLResolvers.
 ******************************************************************************/
static void
releaseStream(std::istream* aStream)
{
  delete aStream;
}

Resource*
TestURLResolver::resolveURL(const zorba::String &aUrl,
                            EntityData const* aEntityData)
{
  if (aEntityData->getKind() != EntityData::DOCUMENT) {
    return NULL;
  }
  if (aUrl != "http://www.zorba-xquery.com/testuriresolver.cpp/hello.xml") {
    return NULL;
  }
  std::stringstream* ss = new std::stringstream();
  *ss << "<a>Hello, world</a>";
  return StreamResource::create(ss, &releaseStream);
}


/******************************************************************************

*******************************************************************************/
TestSchemaURIMapper::TestSchemaURIMapper(const char* file, bool verbose) 
  :
  map_file ( file ),
  theVerbose(verbose)  
{
}


TestSchemaURIMapper::~TestSchemaURIMapper() 
{
}


void TestSchemaURIMapper::initialize()
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

void
TestSchemaURIMapper::mapURI
(const String aURI, EntityData const* aEntityData,
  std::vector<String>& oUris) throw ()
{
  if (aEntityData->getKind() != EntityData::SCHEMA) {
    return;
  }

  if ( uri_map.empty () ) {
    initialize ();
  }
  std::map<String, String>::iterator it = uri_map.find (aURI );
  if ( it != uri_map.end () ) {
    const String target = it->second;

    if (theVerbose)
      std::cout << "Resolved schema " << aURI << " -> " << target << std::endl;

    oUris.push_back(target);
  }
}


/******************************************************************************

*******************************************************************************/

TestModuleURIMapper::TestModuleURIMapper(
    const char* file,
    const std::string& test,
    bool verbose) 
  :
  theMapFile(file),
  theTest(test),
  theVerbose(verbose)
{
}

TestModuleURIMapper::~TestModuleURIMapper()
{
}

TestModuleURIMapper::TestModuleURIMapper(
    const char* file,
    bool verbose) 
  :
  theMapFile(file),
  theVerbose(verbose)
{
  initialize();
}

void TestModuleURIMapper::initialize()
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

void TestModuleURIMapper::mapURI
(const String aURI, EntityData const* aEntityData,
  std::vector<String>& oUris) throw ()
{
  if (aEntityData->getKind() != EntityData::MODULE)
  {
    return;
  }
  if (theUriMap.empty()) 
  {
    initialize();
  }

  std::pair<UriMap::const_iterator, UriMap::const_iterator> range;
  std::string lURIString = aURI.c_str();

  range = theUriMap.equal_range(lURIString);

  if (range.first == range.second)
  {
    // Didn't find anything to map this URI to, so do nothing
    std::cerr << "Asked to import URI " << lURIString <<
      " which is not mentioned in " << theMapFile << std::endl;
    return;
  }

  UriMap::const_iterator ite;
  for (ite = range.first; ite != range.second; ++ite)
  {
    oUris.push_back(ite->second);
    if (theVerbose)
      std::cout << "Resolved module " << aURI << " -> " << ite->second << std::endl;
  }
}


/******************************************************************************
  Collection Resolver
*******************************************************************************/
TestCollectionURIMapper::TestCollectionURIMapper (
  const char * file,
  const std::string& rbkt_src_dir )
  : theMapFileName(file),
    theRbktSrcFile(rbkt_src_dir)
{
}

TestCollectionURIMapper::~TestCollectionURIMapper ()
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

void TestCollectionURIMapper::trim(std::string& str)
{
  std::string::size_type pos = str.find_last_not_of(' ');
  if(pos != std::string::npos) {
    str.erase(pos + 1);
    pos = str.find_first_not_of(' ');
    if(pos != std::string::npos) str.erase(0, pos);
  }
  else str.erase(str.begin(), str.end());
}


void TestCollectionURIMapper::initialize()
{
  std::ifstream urifile ( theMapFileName.c_str() );
  if ( !urifile.good() ) return;

  while ( !urifile.eof() ) {
    std::string lCollectionMapping;
    std::getline( urifile, lCollectionMapping );

    if (lCollectionMapping.size() == 0) continue;

    std::string::size_type eq = lCollectionMapping.find ( '=' );
    assert(eq != std::string::npos);

    std::string id ( lCollectionMapping.substr ( 0, eq ) );
    trim(id);

    std::vector<std::string>& lCollections = theMap[id];

    std_string_tokenize(lCollectionMapping.substr(eq+1), ";", lCollections, theRbktSrcFile);
  }
}

void
TestCollectionURIMapper::mapURI(
    const String aURI,
    EntityData const* aEntityData,
    std::vector<String>& oUris) throw ()
{
  if (aEntityData->getKind() != EntityData::COLLECTION)
  {
    return;
  }
  if ( theMap.empty () ) 
  {
    initialize ();
  }

  std::string request = aURI.c_str();
  std::string search  = request.substr(request.find_last_of('/')+1);
  UriMap::iterator it = theMap.find(search);

  if ( it != theMap.end() )
  {
    const std::vector<std::string>& target = it->second;
    XmlDataManager* lDataManager = Zorba::getInstance(0)->getXmlDataManager();
    ItemFactory* lFactory = Zorba::getInstance(0)->getItemFactory();
    CollectionManager* lMgr = lDataManager->getW3CCollectionManager();

    Item lColName = lFactory->createAnyURI(request);

    if ( !lMgr->isAvailableCollection(lColName) ) {

      lMgr->createCollection(lColName);
      Collection_t lColl = lMgr->getCollection(lColName);

      for (std::vector<std::string>::const_iterator lIter = target.begin();
           lIter != target.end(); ++lIter)
      {
        std::ifstream lIn(lIter->c_str());
        assert(lIn.good());

        Item lDoc = lDataManager->parseXML(lIn);

        lColl->insertNodesLast(new SingletonItemSequence(lDoc));
      }
    }
  }
  oUris.push_back(request);
}

} /* namespace zorba */
