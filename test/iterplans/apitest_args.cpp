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
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <iostream>

// Zorba
#include <zorba/zorba.h>
#include <zorba/properties.h>

// local
#include "apitest_props.h"

using namespace std;
using namespace zorba;

static char const* check_args();

///////////////////////////////////////////////////////////////////////////////

#define HELP_OPT(ARG) ARG "\n"

char const* get_help_msg() {
  return

    ////////// a //////////////////////////////////////////////////////////////

#ifndef NDEBUG
    HELP_OPT( "--abort" )
      "Call abort(3) when a ZorbaException is thrown.\n\n"
#endif /* NDEBUG */

    ////////// c //////////////////////////////////////////////////////////////

    HELP_OPT( "--compile-only" )
      "Only compile (don't execute).\n\n"

    ////////// d //////////////////////////////////////////////////////////////

#ifdef ZORBA_WITH_DEBUGGER
    HELP_OPT( "--debug, -d" )
      "Launch the Zorba debugger server and connect to a DBGP-enabled debugger client.\n\n"
#endif /* ZORBA_WITH_DEBUGGER */

    HELP_OPT( "--debug-file <file>" ) 
      "Sets the file to write developer debugging information to.\n\n"

    HELP_OPT( "--debug-stream {1|cout|stdout|2|cerr|stderr}" )
      "Sets the stream to write developer debugging information to.\n\n"

#ifdef ZORBA_WITH_DEBUGGER
    HELP_OPT( "--debug-host, -h <host>" )
      "The host where the DBGP-enabled debugger client listens for connections; default: 127.0.0.1.\n\n"

    HELP_OPT( "--debug-port, -p <port>" )
      "The port on which the DBGP-enabled debugger client listens for connections; default: 28028.\n\n"
#endif /* ZORBA_WITH_DEBUGGER */

    ////////// e //////////////////////////////////////////////////////////////

    HELP_OPT( "--execute-plan" )
      "Do not compile the query; instead load the execution plan from the file specified by the -f -q options (or by any file specified without any other argument), and execute the loaded plan.\n\n"

    HELP_OPT( "--external-var, -x <name>{=<file>|:=<value>}" )
      "Sets the value of an external variable.\n\n"

    ////////// i //////////////////////////////////////////////////////////////

    HELP_OPT( "--infer-joins" )
      "Infer joins.\n\n"

    HELP_OPT( "--inline-udf" )
      "Inline user-defined functions.\n\n"

    ////////// j //////////////////////////////////////////////////////////////

    HELP_OPT( "--jsoniq, -j" )
      "Force queries to be considered JSONiq.\n\n"

    ////////// l //////////////////////////////////////////////////////////////

    HELP_OPT( "--lib-module, -l" )
      "Query compiler option to treat the query as a library module. If this is set --compile-only option is also set to true.\n\n"

    HELP_OPT( "--lib-path <path>" )
      "Library path (list of directories) where Zorba will look for dynamic libraries (e.g., module external function implementations.\n\n"

    HELP_OPT( "--loop-hosting" )
      "Hoist expressions out of loops.\n\n"

    ////////// m //////////////////////////////////////////////////////////////

    HELP_OPT( "--max-udf-call-depth <depth>" )
      "Maximum stack depth of user-defined function calls.\n\n"

    HELP_OPT( "--module-path <path>" )
      "Path (list of directories) to add to both the URI and Library paths.\n\n"

    ////////// n //////////////////////////////////////////////////////////////

    HELP_OPT( "--no-copy-optim" )
      "Apply the no-copy optimization.\n\n"

    HELP_OPT( "--no-serializer" )
      "Do not serialize (discard) result.\n\n"

    HELP_OPT( "--no-tree-ids" )
      "Suppress IDs and locations from compiler tree dumps.\n\n"

    ////////// o //////////////////////////////////////////////////////////////

    HELP_OPT( "--optimization-level, -O {0|1|2}" )
      "Optimization level for the query compiler; default: 1.\n\n"

#ifdef ZORBA_WITH_FILE_ACCESS
    HELP_OPT( "--output-file, -o <file>" )
      "Write the result to the given file.\n\n"
#endif /* ZORBA_WITH_FILE_ACCESS */

    ////////// p //////////////////////////////////////////////////////////////

    HELP_OPT( "--parse-only" )
      "Stop after parsing the query.\n\n"

    HELP_OPT( "--plan" )
      "Test plan serialization.\n\n"

    HELP_OPT( "--print-ast" )
      "Print the abstract syntax tree.\n\n"

    HELP_OPT( "--print-intermediate-opt" )
      "Print intermediate optimizations.\n\n"

    HELP_OPT( "--print-item-flow" )
      "Print items produced by all iterators.\n\n"

    HELP_OPT( "--print-iterator-tree" )
      "Print the iterator tree.\n\n"

    HELP_OPT( "--print-locations" )
      "Print parser locations for compiler expressions.\n\n"

    HELP_OPT( "--print-optimized" )
      "Print the optimized expression tree.\n\n"

    HELP_OPT( "--print-query" )
      "Print the queries.\n\n"

    HELP_OPT( "--print-static-types" )
      "Print static type inference.\n\n"

    HELP_OPT( "--print-translated" )
      "Print the normalized expression tree.\n\n"

    ////////// q //////////////////////////////////////////////////////////////

    HELP_OPT( "--query, -q <query>" )
      "Query test or file URI (file://...).\n\n"

    ////////// s //////////////////////////////////////////////////////////////

    HELP_OPT( "--serialization-parameter, -z <name>=<value>" )
      "Set serialization parameter (see http://www.w3.org/TR/xslt-xquery-serialization/#serparam, e.g.: -z method=xhtml -z doctype-system=DTD/xhtml1-strict.dtd -z indent=yes).\n\n"

    ////////// t //////////////////////////////////////////////////////////////

    HELP_OPT( "--trace-parsing" )
      "Trace parsing.\n\n"

    HELP_OPT( "--trace-scanning" )
      "Trace scanning.\n\n"

#ifndef NDEBUG
    HELP_OPT( "--trace-codegen" )
      "Trace code generatio.\n\n"

    HELP_OPT( "--trace-fulltext" )
      "Trace full-text.\n\n"

    HELP_OPT( "--trace-translator" )
      "Trace the translator.\n\n"
#endif /* NDEBUG */

    HELP_OPT( "--tz <minutes>" )
      "Set implicit time zone (in minutes).\n\n"

    ////////// u //////////////////////////////////////////////////////////////

    HELP_OPT( "--use-serializer" )
      "Use serializer.\n\n"

    ////////// v //////////////////////////////////////////////////////////////

    HELP_OPT( "--version, -v" )
      "Print the version number and exit.\n\n"

    ;
}

///////////////////////////////////////////////////////////////////////////////

static bool split_key_value( char const *s, char const *split,
                             string *key, string *value ) {
  char const *const p = strstr( s, split );
  size_t const split_len = strlen( split );
  if ( !p || p == s /* =xxx */ || !p[ split_len ] /* xxx= */ )
    return false;
  key->assign( s, 0, p - s );
  value->assign( p + split_len );
  return true;
}

inline char to_lower( char c ) {
  return tolower( c );
}

template<class StringType> inline
typename enable_if<ZORBA_IS_STRING(StringType),void>::type
to_lower( StringType &s ) {
  transform(
    s.begin(), s.end(), s.begin(), static_cast<char (*)(char)>( to_lower )
  );
}

static bool bool_of( char const *s ) {
  string b( s );
  to_lower( b );
  if ( b == "t" || b == "true" || b == "y" || b == "yes" || b == "1" )
    return true;
  if ( b == "f" || b == "false" || b == "n" || b == "no" || b == "0" )
    return false;
  cerr << '"' << s << "\": invalid boolean value" << endl;
  exit( 1 );
}

///////////////////////////////////////////////////////////////////////////////

#define IS_LONG_OPT(OPT)  (strcmp( *argv, (OPT) ) == 0)
#define IS_SHORT_OPT(OPT) (strncmp( *argv, (OPT), 2 ) == 0)
#define IS_OPT(LOPT,SOPT) (IS_LONG_OPT(LOPT) || IS_SHORT_OPT(SOPT))

#define PARSE_ARG(ARG)                                                    \
  int offset = 2;                                                         \
  if ( (*argv)[1] == '-' || !(*argv)[2] ) { offset = 0; ++argv; }         \
  if ( !*argv ) { error = "No value given for " #ARG " option"; break; }

#define ARG_VAL (*argv + offset)

template<typename T> inline
void atoi( char const *s,  T *result, int offset = 0 ) {
  istringstream iss( s + offset );
  iss >> *result;
}

#define SET_ATPROP(PROP) \
  atoi( *argv, &at_props.PROP, offset )

template<class C,typename T> inline
void atoi( char const *s, C &c, void (C::*f)( T ), int offset = 0 ) {
  T temp;
  atoi( s, &temp, offset );
  (c.*f)( temp );
}

#define SET_ZPROP(PROP) \
  atoi( *argv, z_props, &Properties::set##PROP, offset )

int parse_args( int argc, char const *argv[] ) {
  char const *error = 0;
  Properties &z_props = Properties::instance();
  APITestProperties &at_props = APITestProperties::instance();

  char const **const argv_orig = argv;
  for ( ++argv; *argv; ++argv ) {

    ////////// a //////////////////////////////////////////////////////////////

#ifndef NDEBUG
    if ( IS_LONG_OPT( "--abort" ) )
      z_props.setAbort( true );
    else
#endif /* NDEBUG */

    ////////// c //////////////////////////////////////////////////////////////

    if ( IS_LONG_OPT( "--compile-only" ) )
      at_props.compile_only_ = true;

    ////////// d //////////////////////////////////////////////////////////////

#ifdef ZORBA_WITH_DEBUGGER
    else if ( IS_OPT( "--debug", "-d" ) )
      at_props.debug_ = true;
    else if ( IS_OPT( "--debug-host", "-h" ) ) {
      PARSE_ARG( "--debug-host" );
      at_props.debug_host_ = ARG_VAL;
    }
#endif /* ZORBA_WITH_DEBUGGER */
    else if ( IS_LONG_OPT( "--debug-file" ) ) {
      PARSE_ARG( "--debug-file" );
      z_props.setDebugFile( ARG_VAL );
    }
    else if ( IS_LONG_OPT( "--debug-stream" ) ) {
      PARSE_ARG( "--debug-stream" );
      string val( ARG_VAL );
      to_lower( val );
      if ( val == "1" || val == "stdout" || val == "cout" )
        z_props.setDebugStream( cout );
      else if ( val == "2" || val == "stderr" || val == "cerr" )
        z_props.setDebugStream( cerr );
      else {
        error = "--debug-stream argument must be one of: 1, stdout, cout, 2, stderr, or cerr.\n";
        break;
      }
    }
#ifdef ZORBA_WITH_DEBUGGER
    else if ( IS_OPT( "--debug-port", "-p" ) ) {
      PARSE_ARG( "--debug-port" );
      SET_ATPROP( debug_port_ );
    }
#endif /* ZORBA_WITH_DEBUGGER */
    else if ( IS_LONG_OPT( "--dot-plan-file" ) )
      at_props.dot_plan_file_ = true;
    else if ( IS_LONG_OPT( "--dump-lib" ) )
      z_props.setDumpLib( true );

    ////////// e //////////////////////////////////////////////////////////////

    else if ( IS_LONG_OPT( "--execute-plan" ) )
      at_props.load_plan_ = true;
    else if ( IS_OPT( "--external-var", "-x" ) ) {
      PARSE_ARG( "--external-var" );
      string key, value;
      if ( !split_key_value( ARG_VAL, "=", &key, &value ) ) {
        error = "--external-var argument must be of the form name=file or name:=value";
        break;
      }
      external_var ev;
      ev.var_value = value;

      if ( key[0] == ':' ) {
        error = "--external-var argument must be of the form name=file or name:=value";
        break;
      }
      if ( key[ key.size() - 1 ] == ':' )
        key.erase( key.size() - 1 );
      else
        ev.inline_file = true;
      ev.var_name = key;

      at_props.external_vars_.push_back( ev );
    }

    ////////// f //////////////////////////////////////////////////////////////

    else if ( IS_LONG_OPT( "--force-gflwor" ) )
      z_props.setForceGFLWOR( true );

    ////////// h //////////////////////////////////////////////////////////////

    else if ( IS_LONG_OPT( "--help" ) ) {
      cout << "Zorba NoSQL Query Processor, Version: "
           << Zorba::version() << '\n'
           << "Available options:\n\n"
           << get_help_msg();
      exit( 0 );
    }

    ////////// i //////////////////////////////////////////////////////////////

    else if ( IS_LONG_OPT( "--infer-joins" ) ) {
      PARSE_ARG( "--infer-joins" );
      z_props.setInferJoins( bool_of( ARG_VAL ) );
    }
    else if ( IS_LONG_OPT( "--inline-udf" ) ) {
      PARSE_ARG( "--inline-udf" );
      z_props.setInlineUDF( bool_of( ARG_VAL ) );
    }
    else if ( IS_LONG_OPT( "--iter-plan-test" ) )
      at_props.iter_plan_test_ = true;

    ////////// j //////////////////////////////////////////////////////////////

    else if ( IS_OPT( "--jsoniq", "-j" ) )
      at_props.jsoniq_ = true;

    ////////// l //////////////////////////////////////////////////////////////

    else if ( IS_OPT( "--lib-module", "-l" ) )
      at_props.lib_module_ = true;
    else if ( IS_LONG_OPT( "--lib-path" ) ) {
      PARSE_ARG( "--lib-path" );
      at_props.lib_path_ = ARG_VAL;
    }
    else if ( IS_LONG_OPT( "--loop-hoisting" ) ) {
      PARSE_ARG( "--loop-hoisting" );
      z_props.setLoopHoisting( bool_of( ARG_VAL ) );
    }

    ////////// n //////////////////////////////////////////////////////////////

    else if ( IS_LONG_OPT( "--no-copy-optim" ) ) {
      PARSE_ARG( "--no-copy-optim" );
      z_props.setNoCopyOptim( bool_of( ARG_VAL ) );
    }
    else if ( IS_LONG_OPT( "--no-tree-ids" ) )
      z_props.setNoTreeIDs( true );

    ////////// o //////////////////////////////////////////////////////////////

    else if ( IS_OPT( "--optimization-level", "-O" ) ||
              IS_LONG_OPT( "--optimizer" ) ) {
      PARSE_ARG( "--optimization-level" );
      unsigned opt_level;
      atoi( ARG_VAL, &opt_level );
      if ( opt_level > 2 ) {
        error = "Only 0, 1 and 2 are allowed as values for --optimization-level";
        break;
      }
      z_props.setOptimizationLevel( opt_level );
    }
#ifdef ZORBA_WITH_FILE_ACCESS
    else if ( IS_OPT( "--output-file", "-o" ) ) {
      PARSE_ARG( "--output-file" );
      at_props.output_file_ = ARG_VAL;
    }
#endif /* ZORBA_WITH_FILE_ACCESS */

    ////////// p //////////////////////////////////////////////////////////////

    else if ( IS_LONG_OPT( "--parse-only" ) )
      at_props.parse_only_ = true;
    else if ( IS_LONG_OPT( "--plan" ) )
      at_props.test_plan_serialization_ = true;
    else if ( IS_OPT( "--print-ast", "-a" ) )
      z_props.setPrintAST( true );
    else if ( IS_LONG_OPT( "--print-intermediate-opt" ) )
      z_props.setPrintIntermediateOpt( true );
    else if ( IS_LONG_OPT( "--print-item-flow" ) )
      z_props.setPrintItemFlow( true );
    else if ( IS_LONG_OPT( "--print-iterator-tree" ) )
      z_props.setPlanFormat( PLAN_FORMAT_XML );
    else if ( IS_LONG_OPT( "--print-locations" ) )
      z_props.setPrintLocations( true );
    else if ( IS_OPT( "--print-optimized", "-P" ) )
      z_props.setPrintOptimized( true );
    else if ( IS_LONG_OPT( "--print-query" ) )
      at_props.print_query_ = true;
    else if ( IS_LONG_OPT( "--print-static-types" ) )
      z_props.setPrintStaticTypes( true );
    else if ( IS_LONG_OPT( "--print-translated" ) )
      z_props.setPrintTranslated( true );

    ////////// q //////////////////////////////////////////////////////////////

    else if ( IS_OPT( "--query", "-e" ) ) {
      PARSE_ARG( "--query" );
      at_props.query_ = ARG_VAL;
    }

    ////////// s //////////////////////////////////////////////////////////////

    else if ( IS_LONG_OPT( "--serialize-only-query" ) ) {
      PARSE_ARG( "--serialize-only-query" );
      at_props.serialize_only_query_ = bool_of( ARG_VAL );
    }
    else if ( IS_OPT( "--serialization-parameter", "-z" ) ) {
      PARSE_ARG( "--serialization-parameter" );
      string key, value;
      serialization_param sp;
      if ( split_key_value( ARG_VAL, "=", &key, &value ) ) {
        sp.first = key;
        sp.second = value;
      } else
        sp.first = ARG_VAL;
      at_props.serialization_params_.push_back( sp );
    }
    else if ( IS_LONG_OPT( "--stable-iterator-ids" ) )
      z_props.setStableIteratorIDs( true );

    ////////// t //////////////////////////////////////////////////////////////

    else if ( IS_LONG_OPT( "--trace-parsing" ) )
      z_props.setTraceParsing( true );
    else if ( IS_LONG_OPT( "--trace-scanning" ) )
      z_props.setTraceScanning( true );
#ifndef NDEBUG
    else if ( IS_LONG_OPT( "--trace-codegen" ) )
      z_props.setTraceCodegen( true );
    else if ( IS_LONG_OPT( "--trace-fulltext" ) )
      z_props.setTraceFulltext( true );
    else if ( IS_LONG_OPT( "--trace-translator" ) )
      z_props.setTraceTranslator( true );
#endif /* NDEBUG */
    else if ( IS_LONG_OPT( "--tz" ) ) {
      PARSE_ARG( "--tz" );
      SET_ATPROP( tz_ );
    }

    ////////// u //////////////////////////////////////////////////////////////

    else if ( IS_LONG_OPT( "--use-indexes" ) )
      z_props.setUseIndexes( true );
    else if ( IS_LONG_OPT( "--use-serializer" ) )
      at_props.use_serializer_ = true;

    ////////// v //////////////////////////////////////////////////////////////

    else if ( IS_OPT( "--version", "-v" ) ) {
      cout << "Zorba NoSQL Query Processor, Version: "
           << zorba::Zorba::version() << endl;
      exit( 1 ); // should be 0, but the old code returned 1
    }

    ////////// END ////////////////////////////////////////////////////////////

    else if ( IS_LONG_OPT( "--" ) )
      break;
    else if ( (*argv)[0] == '-' ) {
      cerr << "unknown command line option " << *argv << endl;
      exit( 1 );
    } else {
      if ( !at_props.query_.empty() ) {
        error = "exactly one inline query or query file must be specified";
        break;
      }
      at_props.as_file_ = true;
      at_props.query_ = *argv;
    }
  } // for

  if ( !error )
    error = check_args();
  if ( error ) {
    cout << "Error: " << error << "\nUse --help for help." << endl;
    exit( 1 );
  }
  return argv - argv_orig;
}

///////////////////////////////////////////////////////////////////////////////

static char const* check_args() {
  APITestProperties const &at_props = APITestProperties::instance();

  if ( at_props.optimization_level_ > 2 )
    return "only 0, 1 and 2 are allowed as values for the option --optimization-level";

  return 0;
}

///////////////////////////////////////////////////////////////////////////////

/* vim:set et sw=2 ts=2: */
