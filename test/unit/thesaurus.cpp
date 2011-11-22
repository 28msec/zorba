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
#include <list>
#include <map>

#include <zorba/thesaurus.h>
#include <zorba/store_manager.h>
#include <zorba/zorba.h>
#include <zorba/zorba_exception.h>

#include "system/properties.h"

using namespace std;
using namespace zorba;
using namespace zorba::locale;

static bool destroy_called;

///////////////////////////////////////////////////////////////////////////////

class TestThesaurus : public Thesaurus {
public:
  // inherited
  void destroy() const;
  iterator::ptr lookup( String const &phrase, String const &relationship,
                        range_type at_least, range_type at_most ) const;
private:
  typedef std::list<String> synonyms_t;
  typedef std::map<String,synonyms_t const*> thesaurus_t;

  static thesaurus_t const& get_thesaurus();

  class iterator : public Thesaurus::iterator {
  public:
    iterator( synonyms_t const &s ) : synonyms_( s ), i_( s.begin() ) { }
    void destroy() const;
    bool next( String *synonym );
  private:
    synonyms_t const &synonyms_;
    synonyms_t::const_iterator i_;
  };
};

TestThesaurus::thesaurus_t const& TestThesaurus::get_thesaurus() {
  static thesaurus_t thesaurus;
  if ( thesaurus.empty() ) {
    static synonyms_t synonyms;
    synonyms.push_back( "foo" );
    synonyms.push_back( "foobar" );

    thesaurus[ "foo"    ] = &synonyms;
    thesaurus[ "foobar" ] = &synonyms;
  }
  return thesaurus;
}

void TestThesaurus::destroy() const {
  destroy_called = true;
}

Thesaurus::iterator::ptr
TestThesaurus::lookup( String const &phrase, String const &relationship,
                       range_type at_least, range_type at_most ) const {
  static thesaurus_t const &thesaurus = get_thesaurus();
  thesaurus_t::const_iterator const i = thesaurus.find( phrase );
  Thesaurus::iterator::ptr result;
  if ( i != thesaurus.end() )
    result.reset( new iterator( *i->second ) );
  return std::move( result );
}

void TestThesaurus::iterator::destroy() const {
  delete this;
}

bool TestThesaurus::iterator::next( String *synonym ) {
  if ( i_ != synonyms_.end() ) {
    *synonym = *i_;
    ++i_;
    return true;
  }
  return false;
}

///////////////////////////////////////////////////////////////////////////////

class TestThesaurusResolver : public URLResolver {
public:
  TestThesaurusResolver( String const &uri ) : uri_( uri ) { }

  // inherited
  Resource* resolveURL( String const &uri, EntityData const* );
private:
  String const uri_;
};

Resource*
TestThesaurusResolver::resolveURL( String const &uri, EntityData const *ed ) {
  static TestThesaurus thesaurus;
  return uri == uri_ ? &thesaurus : 0;
}

///////////////////////////////////////////////////////////////////////////////

int thesaurus( int argc, char *argv[] ) {
  void *const zstore = StoreManager::getStore();
  Zorba *const zorba = Zorba::getInstance( zstore );

  int result = 0;

  try {
    Properties::load( 0, NULL );

    char const *const query_src =
      "let $x := <msg>foobar</msg> \n"
      "return $x contains text \"foo\" \n"
      "  using thesaurus at \"http://test\" \n";

    StaticContext_t sctx = zorba->createStaticContext();
    TestThesaurusResolver resolver( "http://test" );
    sctx->registerURLResolver( &resolver );
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
