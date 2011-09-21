/*
 * Copyright 2006-2010 The FLWOR Foundation.
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

#include <cassert>
#include <iostream>

#include <zorba/stemmer.h>
#include <zorba/store_manager.h>
#include <zorba/zorba.h>
#include <zorba/zorba_exception.h>

#include "system/properties.h"

using namespace std;
using namespace zorba;
using namespace zorba::locale;

static bool destroy_called;

///////////////////////////////////////////////////////////////////////////////

class TestStemmer : public Stemmer {
public:
  // inherited
  void destroy() const;
  void stem( String const &word, iso639_1::type lang, String *result ) const;
};

void TestStemmer::destroy() const {
  destroy_called = true;
}

void TestStemmer::stem( String const &word, iso639_1::type lang,
                        String *result ) const {
  if ( word == "foobar" )
    *result = "foo";
  else
    *result = word;
}

///////////////////////////////////////////////////////////////////////////////

class TestStemmerProvider : public StemmerProvider {
public:
  Stemmer::ptr getStemmer( iso639_1::type lang ) const;
};

Stemmer::ptr TestStemmerProvider::getStemmer( iso639_1::type lang ) const {
  static TestStemmer stemmer;
  Stemmer::ptr result;
  switch ( lang ) {
    case iso639_1::en:
    case iso639_1::unknown:
      result.reset( &stemmer );
      break;
    default:
      break;
  }
  return std::move( result );
}

///////////////////////////////////////////////////////////////////////////////

int stemmer( int argc, char *argv[] ) {
  void *const zstore = StoreManager::getStore();
  Zorba *const zorba = Zorba::getInstance( zstore );

  int result = 0;

  try {
    Properties::load( 0, NULL );

    char const *const query_src =
      "let $x := <msg>foobar</msg>"
      "return $x contains text \"foo\" using stemming";

    TestStemmerProvider provider;
    zorba->getXmlDataManager()->registerStemmerProvider( &provider );

    StaticContext_t sctx = zorba->createStaticContext();
    XQuery_t xquery = zorba->compileQuery( query_src, sctx );

    Zorba_SerializerOptions ser_options;
    ser_options.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;
    std::ostringstream sout;
    xquery->execute( sout, &ser_options );

    if ( !destroy_called )
      result = 1;

    if ( sout.str() != "true" )
      result = 2;
  }
  catch ( ZorbaException const &e ) {
    cerr << e << endl;
    result = 3;
  }

  zorba->shutdown();
  StoreManager::shutdownStore( zstore );
  return result;
}
/* vim:set et sw=2 ts=2: */
