/*
 * Copyright 2006-2014 The FLWOR Foundation.
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

// standard
#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>

// Zorba
#include <zorba/internal/unique_ptr.h>
#include <zorba/iterator.h>
#include <zorba/properties.h>
#include <zorba/store_manager.h>
#include <zorba/util/fs_util.h>
#include <zorba/zorba_exception.h>
#include <zorba/zorba.h>

// local
#include "apitest_props.h"

using namespace std;
using namespace zorba;

extern int parse_args( int argc, char const *argv[] );

///////////////////////////////////////////////////////////////////////////////

#ifndef _WIN32_WCE
int main( int argc, char const *argv[] ) {
#else
int _tmain( int argc, _TCHAR const *argv[] ) {
#endif
  int const optind = parse_args( argc, argv );
  argc -= optind;
  argv += optind;

  Properties const &z_props = Properties::instance();
  APITestProperties const &at_props = APITestProperties::instance();
#if 0
  if (! z_props.hasSingleQuery ()) {
    cout << "Error: either a single inline query or a single query file must be supplied" << endl;
    return 4;
  }
#endif
  Zorba_CompilerHints chints;
  switch ( z_props.getOptimizationLevel() ) {
    case 0 : chints.opt_level = ZORBA_OPT_LEVEL_O0; break;
    case 2 : chints.opt_level = ZORBA_OPT_LEVEL_O1; break;
    default: chints.opt_level = ZORBA_OPT_LEVEL_O1;
  }

  chints.for_serialization_only = at_props.serialize_only_query_;
  chints.lib_module = at_props.lib_module_;

  // output file (either a file or the standard out if no file is specified)
  unique_ptr<ostream> output_file_ptr(
    at_props.output_file_.empty() ?
      NULL : new ofstream( at_props.output_file_.c_str() )
  );
  ostream *output_file = output_file_ptr.get();
  if ( !output_file )
    output_file = &cout;

  // input file (either from a file or given as parameter)
  unique_ptr<istream> qstream;
  string path;

  if ( at_props.as_files_ ) {
    path = at_props.query_;
    fs::make_absolute( &path );
    qstream.reset( new ifstream( path.c_str() ) );
    if ( !qstream->good() || qstream->eof() ) {
      cerr << "no query given or not readable " << path << endl;
      return 3;
    }
  } else
    qstream.reset( new istringstream( at_props.query_ ) );

  // print the query if requested
  if ( at_props.print_query_ ) {
    z_props.getDebugStream() << "Query text:\n";
    copy(
      istreambuf_iterator<char>( *qstream ),
      istreambuf_iterator<char>(),
      ostreambuf_iterator<char>( z_props.getDebugStream() )
    );
    z_props.getDebugStream() << '\n' << endl;
    qstream->seekg( 0 );
  }

  // Instantiate the simple store
  void *const store = StoreManager::getStore();

  // start processing
  Zorba *const zorba = Zorba::getInstance( store );
  StaticContext_t sctx( zorba->createStaticContext() );
  XQuery_t query( zorba->createQuery() );

#ifdef ZORBA_WITH_DEBUGGER
  if ( at_props.debug_ )
    query->setDebugMode( true );
#endif /* ZORBA_WITH_DEBUGGER */

  if ( !path.empty() )
    query->setFileName( path );

  if ( at_props.jsoniq_ )
    sctx->setJSONiqVersion( jsoniq_version_1_0 );

  try {
    query->compile( *qstream, sctx, chints );
  }
  catch ( ZorbaException const &e ) {
    // no need to close because the object is not valid
    cerr << "Compilation error: " << e << endl;
    return 1;
  }

  if ( at_props.test_plan_serialization_ ) {
    try {
      string binary_path;
      if ( path.empty() )
        binary_path = "./temp.plan";
      else
        binary_path = path + ".plan";

      ofstream fbinary( binary_path.c_str(), ios_base::binary );
      if ( !query->saveExecutionPlan( fbinary ) ) {
        printf( "save execution plan FAILED\n" );
        return 0x0badc0de;
      }
      printf( "saved execution plan at: %s\n", binary_path.c_str() );
    }
    catch( ZorbaException const &e ) {
      cout << e << endl;
      return -1;
    }

    // Now load back the plan
    try {
      string binary_path;
      if ( path.empty() )
        binary_path = "./temp.plan";
      else
        binary_path = path + ".plan";
      query = zorba->createQuery();
      ifstream ifbinary( binary_path.c_str(), ios_base::binary );
      if ( !ifbinary.is_open() ) {
        cout << "cannot open plan " << binary_path << endl;
        return 15;
      }

      bool load_ret = query->loadExecutionPlan( ifbinary );
      if ( !load_ret ) {
        cout << "cannot load plan " << binary_path << endl;
        return 16;
      }
      printf( "load execution plan: %s\n", binary_path.c_str() );
    }
    catch ( ZorbaException const &e ) {
      cout << e << endl;
      return -1;
    }
  }

  // set external variables
  external_vars const &ext_vars = at_props.external_vars_;
  DynamicContext *const dctx = query->getDynamicContext();
  dctx->setImplicitTimezone( at_props.tz_ );
  for ( external_vars::const_iterator
        i = ext_vars.begin(); i != ext_vars.end(); ++i ) {
    Item item;
    if ( i->inline_file ) {
      ifstream is( i->var_value.c_str() );
      assert( is );
      try {
        XmlDataManager_t xml_dm( zorba->getXmlDataManager() );
        item = xml_dm->parseXML( is );
        assert( item.getNodeKind() == store::StoreConsts::documentNode );
      }
      catch ( ZorbaException const &e ) {
        cerr << "could not set external variable " << e << endl;
        exit( 1 );
      }
    } else {
      item = zorba->getItemFactory()->createString( i->var_value );
    }
    if ( i->var_name == "." )
      dctx->setContextItem( item );
    else
      dctx->setVariable( i->var_name, item );
  }

  // if you want to print the plan into a file
  if ( !at_props.dot_plan_file_.empty() ) {
    ofstream plan_file( at_props.dot_plan_file_.c_str() );
    query->printPlan( plan_file, true );
  }

  int return_code = 0;
  if ( !at_props.compile_only_ && !at_props.lib_module_ ) {

    // output the result (either using xml serialization or using show)

    try {
      if ( at_props.use_serializer_ ) {
        Zorba_SerializerOptions const opts( at_props.serialization_params_ );
        query->execute( *output_file, &opts );
      } else {
        Iterator_t i( query->iterator() );
        i->open();
        Item item;
        while ( i->next( item ) )
          ;
        i->close();
      }
    }
    catch ( ZorbaException const &e ) {
      cerr << "Execution error: " << e << endl;
      return_code = 2;
    }
  }

  sctx.release()->removeReference();  // force destruction
  query->close();
  zorba->shutdown();
  StoreManager::shutdownStore( store );
  return return_code;
}

///////////////////////////////////////////////////////////////////////////////

/* vim:set et sw=2 ts=2: */
