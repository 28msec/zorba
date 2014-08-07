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

// standard
#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

#ifdef WIN32
#include <windows.h>
#endif /* WIN32 */

// Zorba
#include <zorba/audit.h>
#include <zorba/audit_scoped.h>
#include <zorba/document_manager.h>
#include <zorba/internal/unique_ptr.h>
#include <zorba/item_sequence.h>
#include <zorba/properties.h>
#include <zorba/serialization_callback.h>
#include <zorba/store_manager.h>
#include <zorba/uri_resolvers.h>
#include <zorba/util/fs_util.h>
#include <zorba/xquery_exception.h>
#include <zorba/xquery_functions.h>
#include <zorba/zorba.h>
#include <zorba/zorba_exception.h>

//#define DO_AUDIT

#ifdef DO_AUDIT
#include <zorba/audit.h>
#include <zorba/audit_scoped.h>
#endif

// local
#include "apitest_props.h"
#include "util.h"

using namespace std;
using namespace zorba;

extern char const* get_help_msg();
extern int  parse_args( int argc, char const *argv[] );
static void set_paths_on_sctx( StaticContext_t& );

///////////////////////////////////////////////////////////////////////////////

static const char copyright[] =
  "Copyright 2006-2014 The FLWOR Foundation.\n"
  "License: Apache License 2.0: <http://www.apache.org/licenses/LICENSE-2.0>";

#ifndef ZORBA_NO_FULL_TEXT
static OneToOneURIMapper stop_words_mapper( EntityData::STOP_WORDS );
static OneToOneURIMapper thesaurus_mapper( EntityData::THESAURUS );
#endif /* ZORBA_NO_FULL_TEXT */

class URIMapperSerializationCallback : public SerializationCallback {
public:
  void addURIMapper( URIMapper* mapper ) {
    theURIMappers.push_back( mapper );
  }

  URIMapper* getURIMapper( size_t i ) const {
    return theURIMappers[i];
  }

private:
  vector<URIMapper*> theURIMappers;
};

URIMapperSerializationCallback serialization_callback;

static void print_exception( ZorbaException const &e ) {
  APITestProperties &at_props = APITestProperties::instance();
  if ( at_props.print_errors_as_xml_ )
    if ( at_props.indent_ )
      cerr << ZorbaException::format_xml_indented;
    else
      cerr << ZorbaException::format_xml;
  else
    cerr << ZorbaException::format_text;
  cerr << e << endl;
}

static void print_help() {
  cout << "Zorba NoSQL Query Processor\n";
  cout << "Available options:\n";
  cout << get_help_msg();
}

static bool populateStaticContext( Zorba *zorba, StaticContext_t &sctx ) {
  APITestProperties &at_props = APITestProperties::instance();
  try {
    // add the following module path to the static context (in this order)
    // 1. command-line properties
    // 2. environment ZORBA_MODULE_PATH
    // 3. current working directory
    set_paths_on_sctx( sctx );

    if ( !at_props.boundary_space_.empty() )
      sctx->setBoundarySpacePolicy(
        at_props.boundary_space_ == "preserve" ? preserve_space : strip_space
      );

    if ( !at_props.construction_mode_.empty() )
      sctx->setConstructionMode(
        at_props.boundary_space_ == "preserve" ? preserve_cons : strip_cons
      );

    if ( !at_props.ordering_mode_.empty() )
      sctx->setOrderingMode(
        at_props.boundary_space_ == "ordered" ? ordered : unordered
      );

    if ( !at_props.base_uri_.empty() )
      sctx->setBaseURI( at_props.base_uri_ );
  }
  catch ( ZorbaException const &ze ) {
    cerr << ze << endl;
    return false;
  }

  if ( !at_props.default_collation_.empty() ) {
    try {
      sctx->addCollation( at_props.default_collation_ );
    }
    catch ( ZorbaException const& ) {
      cerr << "the given collation {" << at_props.default_collation_
           << "} is not a valid collation." << endl;
      return false;
    }
    sctx->setDefaultCollation( at_props.default_collation_ );
  }

  sctx_opts::const_iterator i = at_props.sctx_opts_.begin();
  sctx_opts::const_iterator const end = at_props.sctx_opts_.end();
  for ( ; i != end; ++i ) {
    try {
      Item name( zorba->getItemFactory()->createQName( i->clark_qname ) );
      sctx->declareOption( name, i->value );
    }
    catch ( ZorbaException const &e) {
      cerr << "unable to set static context option with qname "
           << i->clark_qname << ": " << e.what() << endl;
      return false;
    }
  }

#ifdef DO_AUDIT
  audit::Provider* lAuditProvider = zorba->getAuditProvider();
  audit::Configuration* config = lAuditProvider->createConfiguration();
  vector<String> property_names;
  audit::Configuration::getPropertyNames(property_names);

  bool lIsStatic;

  lIsStatic = audit::Configuration::
  enableProperty(config, property_names, "xquery/compilation/parse-duration");
  assert(lIsStatic);

  lIsStatic = audit::Configuration::
  enableProperty(config, property_names, "xquery/compilation/translation-duration");
  assert(lIsStatic);

  lIsStatic = audit::Configuration::
  enableProperty(config, property_names, "xquery/compilation/optimization-duration");
  assert(lIsStatic);

  lIsStatic = audit::Configuration::
  enableProperty(config, property_names, "xquery/compilation/codegeneration-duration");
  assert(lIsStatic);

  audit::Event *event = lAuditProvider->createEvent(config);

  sctx->setAuditEvent( event );
#endif /* DO_AUDIT */

#ifndef ZORBA_NO_FULL_TEXT
  {
    ft_mappings::const_iterator i = at_props.stop_words_mapping_.begin();
    ft_mappings::const_iterator const end = at_props.stop_words_mapping_.end();
    for (; i != end; ++i)
      stop_words_mapper.addMapping( i->uri, i->value );

    if ( at_props.serialize_plan_ || at_props.load_plan_ )
      serialization_callback.addURIMapper( &stop_words_mapper );
    else
      sctx->registerURIMapper( &stop_words_mapper );
  }

  {
    ft_mappings::const_iterator i = at_props.thesaurus_mapping_.begin();
    ft_mappings::const_iterator const end = at_props.thesaurus_mapping_.end();
    for ( ; i != end; ++i )
      thesaurus_mapper.addMapping( i->uri, i->value );

    if ( at_props.serialize_plan_ || at_props.load_plan_ )
      serialization_callback.addURIMapper( &stop_words_mapper );
    else
      sctx->registerURIMapper( &thesaurus_mapper );
  }
#endif /* ZORBA_NO_FULL_TEXT */

  return true;
}

bool populateDynamicContext( Zorba *zorba, DynamicContext *dctx ) {
  APITestProperties &at_props = APITestProperties::instance();

  XmlDataManager_t xmlMgr;
  if ( !at_props.ctx_item_.empty() ) {
    ifstream is( at_props.ctx_item_.c_str() );
    xmlMgr = zorba->getXmlDataManager();
    Item doc( xmlMgr->parseXML( is ) );
    dctx->setContextItem( doc );
  }

  // sort vars: x:=1 y:=foo x:=2 --> x:=1 x:=2 y:=foo
  stable_sort( at_props.external_vars_.begin(), at_props.external_vars_.end() );

  external_vars::const_iterator i;
  external_vars::const_iterator const end( at_props.external_vars_.end() );

  //
  // Count how many of each variable there are to know whether there are
  // multiple values for the same variable.  If there are, we have to create an
  // Iterator for them later.
  //
  typedef map<String,int> var_count_type;
  var_count_type var_count;
  for ( i = at_props.external_vars_.begin(); i != end; ++i )
    ++var_count[ i->var_name ];

  for ( i = at_props.external_vars_.begin(); i != end; ++i ) {
    try {
      if ( i->inline_file ) {
        ifstream is( i->var_value.c_str() );
        if ( !xmlMgr )
          xmlMgr = zorba->getXmlDataManager();
        Item doc( xmlMgr->parseXML( is ) );
        dctx->setVariable( i->var_name, doc );
      } else {
        int count = var_count[ i->var_name ];
        if ( count == 1 ) {
          // easy case: only a single value
          Item item( zorba->getItemFactory()->createString( i->var_value ) );
          dctx->setVariable( i->var_name, item, true );
        } else {
          // hard case: multiple values -- construct an Iterator
          vector<Item> vars;
          String const var_name( i->var_name );
          while ( true ) {
            Item item( zorba->getItemFactory()->createString( i->var_value ) );
            vars.push_back( item );
            if ( !--count )
              break;
            ++i;
          } // while
          dctx->setVariable( var_name, make_iterator( vars ), true );
        }
      }
    }
    catch ( ... ) {
      // Let normal exception handling display the error message; here we
      // just want to tell the user what variable binding caused the problem
      cerr << "While binding external variable $" << i->var_name << ": ";
      throw;
    }
  }
  return true;
}

static void set_serializer_opts( Zorba_SerializerOptions_t &ser_opts ) {
  APITestProperties &at_props = APITestProperties::instance();

  if ( at_props.indent_ )
    ser_opts.indent = ZORBA_INDENT_YES;

  if ( at_props.omit_xml_declaration_ )
    ser_opts.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;

  if ( at_props.byte_order_mark_ )
    ser_opts.byte_order_mark = ZORBA_BYTE_ORDER_MARK_YES;

  if ( at_props.serialize_html_ )
    ser_opts.ser_method = ZORBA_SERIALIZATION_METHOD_HTML;
  else if ( at_props.serialize_text_ )
    ser_opts.ser_method = ZORBA_SERIALIZATION_METHOD_TEXT;
}


/******************************************************************************
  Fullfills the command-line "as-file" (-f) switch, or if not requested, infers
  -f for file:// queries. Returns an URI or the empty string.
 ******************************************************************************/

static string parse_file_uri( string const &uri ) {
#ifdef WIN32
  // file:///c:/ returns c:<backslash>
  // file://localhost returns \\localhost
  // BUG: it seems that <a>/x returns <a>\x
  static const char *file3 = "file:///";
  static const char *file2 = "file://";
  string fpath;
  if ( uri.compare( 0, strlen( file3 ), file3 ) == 0 ) {
    fpath = uri.substr( strlen( file3 ) );
  } else if ( uri.compare( 0, strlen( file2 ), file2 ) == 0 ) {
    fpath = fs::dir_separator;
    fpath += uri.substr( strlen( file2 ) );
  }
  // replace all slash with backslash
  string::size_type off=0;
  while ( (off = fpath.find( '/', off )) != string::npos )
    fpath.replace( off, 1, 1, fs::dir_separator );
  return fpath;

#else /* for UNIX */
  static const char pfx[] = "file://";
  if ( uri.compare( 0, 7, pfx ) == 0 )
    return uri.substr( 7 );
  else
    return "";
#endif /* WIN32 */
}

static void remove_output_file() {
#ifdef ZORBA_WITH_FILE_ACCESS
  APITestProperties &at_props = APITestProperties::instance();
  if ( !at_props.output_file_.empty() )
    fs::remove( at_props.output_file_, true );
#endif /* ZORBA_WITH_FILE_ACCESS */
}

static int compileAndExecute( Zorba *zorba,
                              StaticContext_t &sctx,
                              string const &qfilepath,
                              istream &qstream,
                              ostream &outputStream) {
  Properties const &z_props = Properties::instance();
  APITestProperties const &at_props = APITestProperties::instance();

  unsigned long lNumExecutions = at_props.multiple_;
  ostringstream lOut;
  Zorba_CompilerHints hints;

  unique_ptr<fstream> planFile;
  fstream *planFilep = NULL;

  if ( at_props.jsoniq_ || fs::extension( qfilepath ) == "jq" )
    sctx->setJSONiqVersion( jsoniq_version_1_0 );

  if ( at_props.serialize_plan_ ) {
    if ( at_props.load_plan_ || at_props.save_plan_ ) {
      cerr << "The --serialize-plan option cannot be used together with the --compile-plan or --execute-plan options" << endl;
      exit( 1 );
    }

    string planFilePath = qfilepath;
    planFilePath += ".plan";
    planFile.reset(
      new fstream(
        planFilePath.c_str(), ios::in | ios::out | ios::trunc | ios::binary
      )
    );
    planFilep = planFile.get();
    assert(planFilep->good());
  }

  if ( at_props.save_plan_ && at_props.load_plan_ ) {
    cerr << "The --compile-plan and --execute-plan options cannot be used together" << endl;
    exit( 1 );
  }

  // default is O1 in the Zorba_CompilerHints constructor
  switch ( z_props.getOptimizationLevel() ) {
    case 0: hints.opt_level = ZORBA_OPT_LEVEL_O0; break;
    case 2: hints.opt_level = ZORBA_OPT_LEVEL_O2; break;
  }

  hints.for_serialization_only = at_props.serialize_only_query_;
  hints.lib_module = at_props.lib_module_;

  Zorba_SerializerOptions ser_opts;
  try {
    ser_opts.set( at_props.serialization_params_ );
  }
  catch ( ZorbaException const &e ) {
    cerr << e << endl;
    return 11;
  }
  set_serializer_opts( ser_opts );

  XQuery_t query;
  DiagnosticHandler diagnosticHandler;
  XmlDataManager_t xmlDataMgr;

  for ( unsigned long exec = 0; exec < lNumExecutions; ++exec ) {

    //
    // Compile the query
    // Compilation is done only once, unless timing is needed
    //
    if ( at_props.timing_ || exec == 0 ) {
      // go back to the beginning of the stream
      qstream.clear();
      qstream.seekg( 0 );
      assert( qstream.tellg() >= 0 );

      try {

        // Create and compile the query
        query = zorba->createQuery();
        query->registerDiagnosticHandler( &diagnosticHandler );
        query->setFileName( qfilepath );

        if ( at_props.load_plan_ ) {
          query->loadExecutionPlan( qstream, &serialization_callback );

        } else {
          query->compile( qstream, sctx, hints );

          // Serialize the execution plan, if requested
          if ( at_props.serialize_plan_ ) {
            planFilep->clear();
            planFilep->seekp( 0 );

            query->saveExecutionPlan( *planFilep );
            planFilep->flush();
          }
        }
      }
      catch ( XQueryException const &qe ) {
        print_exception( qe );
        return 11;
      }
      catch ( ZorbaException const &ze ) {
        cerr << ze << endl;
        return 12;
      }
    } // if (at_props.timing_ || exec == 0)

    //
    // Run the query, unless compile-only has been requested.
    //
    if ( !at_props.compile_only_ && !at_props.lib_module_ ) {
      try {
        // load the execution plan, if requested
        if ( at_props.serialize_plan_ ) {
          planFilep->seekg( 0 );
          assert( planFilep->good() );


          query = zorba->createQuery();
          query->loadExecutionPlan( *planFilep, &serialization_callback );

        }

        // Populate the dynamic context
        try {
          DynamicContext *const dctx = query->getDynamicContext();
          if ( !populateDynamicContext( zorba, dctx ) ) {
            print_help();
            return 21;
          }
        }
        catch ( XQueryException const &qe ) {
          print_exception( qe );
          return 22;
        }
        catch ( ZorbaException const &ze ) {
          cerr << ze << endl;
          return 23;
        }

        // run the query
        if ( at_props.no_serializer_ )
          query->executeSAX();
        else if ( at_props.save_plan_ )
          query->saveExecutionPlan( outputStream );
        else
          query->execute( outputStream, &ser_opts );

        if ( at_props.trailing_nl_ )
          outputStream << endl;

        query->close();
      }
      catch ( XQueryException const &qe ) {
        print_exception( qe );
        return 31;
      }
      catch ( ZorbaException const &ze ) {
        cerr << ze << endl;
        return 32;
      }
    }

#ifdef DO_AUDIT
    cerr << *sctx->getAuditEvent() << endl;
#endif /* DO_AUDIT */
  } // for each execution

  return 0;
}

static void set_paths_on_sctx( StaticContext_t &sctx ) {
  APITestProperties &at_props = APITestProperties::instance();
  vector<String> paths;

  // Compute the current working directory to append to all paths.
  string const cwd( fs::curdir() );

  // setModulePaths() *overwrites* the URI path and lib path, so there's no
  // sense in calling both. So if --module-path exists, just use it.

  if ( !at_props.module_path_.empty() ) {
    tokenize( at_props.module_path_, fs::path_separator, &paths );
    paths.push_back( cwd );
    sctx->setModulePaths( paths );
  } else {
    // Compute and set URI path
    tokenize( at_props.uri_path_, fs::path_separator, &paths );
    paths.push_back( cwd );
    sctx->setURIPath( paths );
    paths.clear();

    // Compute and set lib path
    tokenize( at_props.lib_path_, fs::path_separator, &paths );
    paths.push_back( cwd );
    sctx->setLibPath( paths );
  }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  Main                                                                     //
//                                                                           //
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

#ifdef ZORBA_WITH_DEBUGGER
  bool const debug = at_props.debug_;
#else
  bool const debug = false;
#endif

  // libModule assumes compile-only even if compile-only is false
  bool const compile_only = at_props.compile_only_ || at_props.lib_module_;

  // write to file or standard out
  unique_ptr<ostream> out_stream_ptr(
#ifdef ZORBA_WITH_FILE_ACCESS
    !at_props.output_file_.empty() ?
      new ofstream( at_props.output_file_.c_str() ) : 0
#else /* ZORBA_WITH_FILE_ACCESS */
    0
#endif /* ZORBA_WITH_FILE_ACCESS */
  );

  ostream *out_stream = out_stream_ptr.get();
  if ( !out_stream )
    out_stream = &cout;
#ifdef ZORBA_WITH_FILE_ACCESS
  else if ( !out_stream->good() ) {
    cerr << "could not write to output file {" << at_props.output_file_
         << '}' << endl;
    return 2;
  }
#endif /* ZORBA_WITH_FILE_ACCESS */

  if ( at_props.queries_or_files_.empty() ) {
    cerr << "no queries submitted." << endl;
    print_help();
    return 3;
  }

  // Start the engine
  void *const store = StoreManager::getStore();
  Zorba *const zorba = Zorba::getInstance( store );

#ifdef DO_AUDIT
  audit::Provider* lAuditProvider = zorba->getAuditProvider();

  audit::Configuration* config = lAuditProvider->createConfiguration();

  vector<String> property_names;
  audit::Configuration::getPropertyNames(property_names);

  audit::Configuration::
  enableProperty(config, property_names, "xquery/compilation/parse-duration");

  audit::Configuration::
  enableProperty(config, property_names, "xquery/compilation/translation-duration");

  audit::Configuration::
  enableProperty(config, property_names, "xquery/compilation/optimization-duration");

  audit::Configuration::
  enableProperty(config, property_names, "xquery/compilation/codegeneration-duration");
#endif

  {
  // For each query ...

  int query_no;
  vector<string>::const_iterator i;
  for ( query_no = 1, i = at_props.queries_or_files_.begin();
        i != at_props.queries_or_files_.end(); ++query_no, ++i ) {
    //
    // Read the query (either from a file or given as parameter)
    //
    string const uri( *i );
    string const fname( at_props.as_files_ ? uri : parse_file_uri( uri ) );
    string path( fname );
    bool const as_file = !fname.empty();
    unique_ptr<istream> qstream;

    if ( as_file ) {
      fs::make_absolute( &path );
      qstream.reset( new ifstream( path.c_str() ) );
    } else {
      qstream.reset( new istringstream( uri ) );
    }

    if ( as_file && (!qstream->good() || qstream->eof()) ) {
      cerr << "file {" << fname << "} not found or not readable." << endl;
      print_help();
      return 3;
    } else if ( uri.empty() ) {
      cerr << "empty query." << endl;
      print_help();
      return 3;
    }

    //
    // Print the query if requested
    //
    if ( at_props.print_query_ ) {
      *out_stream << "\nQuery number " << query_no << " :\n";
      copy(
        istreambuf_iterator<char>( *qstream ),
        istreambuf_iterator<char>(),
        ostreambuf_iterator<char>( *out_stream )
      );
      *out_stream << endl;
      qstream->seekg( 0 );
    }

    //
    // Create the static context and populate it with info taken from the
    // properties
    //
    StaticContext_t sctx = zorba->createStaticContext();

    if ( !populateStaticContext( zorba, sctx ) ) {
      print_help();
      return 3;
    }

#ifdef DO_AUDIT
    audit::Event *event = lAuditProvider->createEvent( config );
    sctx->setAuditEvent( event );
#endif // DO_AUDIT

    if ( !as_file && at_props.base_uri_.empty() ) {
      // No user set base URI. Set the cwd to be used as base-uri in order
      // to make the doc function doc("mydoc.xml") work
      string p( fs::curdir() );
      stringstream lTmp;
      vector<string> lTokens;
      tokenize( p, fs::dir_separator, &lTokens );

      lTmp << "file://";
      for ( vector<string>::const_iterator i = lTokens.begin();
            i != lTokens.end(); ++i ) {
        String s( *i );
        lTmp << '/' << fn::encode_for_uri( s );
      }

      lTmp << '/';
      sctx->setBaseURI( lTmp.str() );
    }

    // Parse the query
    if ( at_props.parse_only_ ) {
      try {
        XQuery_t lQuery = zorba->createQuery();
        if ( as_file )
          lQuery->setFileName( path );

        lQuery->parse (*qstream);
      }
      catch ( ZorbaException const &ze ) {
        cerr << ze << endl;
        return 6;
      }
    }

    // Compile and run it if necessary.
    // Print timing information if requested.
    else if ( !debug ) {
      if ( compile_only ) {
        try {
          XQuery_t aQuery = zorba->createQuery();
          if ( as_file )
            aQuery->setFileName( path );

          aQuery->parse( *qstream );
          qstream->clear();
          qstream->seekg( 0 );
        }
        catch ( XQueryException const &qe ) {
          print_exception( qe );
          return 6;
        }
      }

      int status = compileAndExecute(zorba,
                                     sctx,
                                     path,
                                     *qstream,
                                     *out_stream);
      if ( status != 0 ) {
        // reset the file handler (in case output option was provided)
        // in order to delete the created output file
        out_stream_ptr.reset();
        remove_output_file();
        return status;
      }
    }

#ifdef ZORBA_WITH_DEBUGGER
    // Debug the query. Do not allow "compile_only" flags and inline queries
    else if ( debug ) {
      if ( compile_only ) {
        cerr << "cannot debug a query if the --compile-only option is specified"
             << endl;
        return 7;
      }

      if ( !as_file ) {
        cerr << "Cannot debug inline queries." << endl;
        return 8;
      }

      unique_ptr<istream> lXQ( new ifstream( path.c_str() ) );

      XQuery_t query;

      try {
        query = zorba->createQuery();
        query->setFileName( path );
        query->setDebugMode( true );

        Zorba_CompilerHints hints;
        hints.opt_level = ZORBA_OPT_LEVEL_O0;

        query->compile( *lXQ.get(), hints );
        if (!populateDynamicContext(zorba, query->getDynamicContext()))
          return 9;

        Zorba_SerializerOptions ser_opts( at_props.serialization_params_ );
        set_serializer_opts( ser_opts );

        if ( !at_props.no_logo_ )
          cout << "Zorba XQuery Debugger Server\n" << copyright << endl;

        query->debug( *out_stream, ser_opts, at_props.debug_host_, at_props.debug_port_ );
      }
      catch ( XQueryException const &qe ) {
        print_exception( qe );
        return 5;
      }
      catch ( ZorbaException const &ze ) {
        cerr << ze << endl;
        return 6;
      }
    } // else if (debug)
#endif /* ZORBA_WITH_DEBUGGER */

#ifdef DO_AUDIT
    lAuditProvider->submitEvent( event );
#endif

  } // for each query

  }

#ifdef DO_AUDIT
  lAuditProvider->destroyConfiguration(config);
#endif /* DO_AUDIT */

  zorba->shutdown();
  StoreManager::shutdownStore( store );

  return 0;
}

///////////////////////////////////////////////////////////////////////////////

/* vim:set et sw=2 ts=2: */
