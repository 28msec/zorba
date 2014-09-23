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
#include <cstdlib>
#include <cctype>
#include <iostream>

// Zorba
#include <zorba/zorba.h>
#include <zorba/properties.h>

// local
#include "zorbacmd_props.h"

using namespace std;
using namespace zorba;

///////////////////////////////////////////////////////////////////////////////

static char const* check_args() {
  ZorbaCmdProperties const &zc_props = ZorbaCmdProperties::instance();

  if ( !( zc_props.boundary_space_.empty() ||
          zc_props.boundary_space_ == "preserve" ||
          zc_props.boundary_space_ == "strip" ) )
    return "Only strip and preserve are allowed as values for the option boundary-space";

  if ( !( zc_props.construction_mode_.empty() ||
          zc_props.construction_mode_ == "preserve" ||
          zc_props.construction_mode_ == "strip" ) )
    return "Only strip and preserve are allowed as values for the option construction-mode";

  if ( zc_props.optimization_level_ > 2 )
    return "only 0, 1 and 2 are allowed as values for the option --optimization-level";

  if ( !( zc_props.ordering_mode_.empty() ||
          zc_props.ordering_mode_ == "ordered" ||
          zc_props.ordering_mode_ == "unordered" ) )
    return "Only ordered and unordered are allowed as values for the option ordering-mode";

  if (zc_props.timezone_set_ &&
      (zc_props.timezone_ > 14*60 || zc_props.timezone_ < -14*60))
    return "Invalid timezone specified: valid timezones are in the range [-14*60, 14*60]";

  if ( zc_props.queries_or_files_.empty() )
    return "No queries submitted\nUsage: zorba -q '1 + 1' execute an inline query \n zorba file.xq execute a query from a file";

  return 0;
}

///////////////////////////////////////////////////////////////////////////////

#define HELP_OPT(ARG) ARG "\n"

char const* get_help_msg() {
  return

    ////////// a //////////////////////////////////////////////////////////////

#ifndef NDEBUG
    HELP_OPT( "--abort" )
      "Call abort(3) when a ZorbaException is thrown.\n\n"
#endif /* NDEBUG */

    HELP_OPT( "--as-files, -f" )
      "Treat all -q arguments as file paths instead of URIs or inline queries. This option is deprecated and will be defaulted to true in the future, so any entry in the command line is going to be treated as files.\n\n"

    ////////// b //////////////////////////////////////////////////////////////

    HELP_OPT( "--base-uri <uri>" )
      "Set the base URI property of the static context.\n\n"

    HELP_OPT( "--boundary-space {strip|preserve}" )
      "Set the boundary-space policy in the static context.\n\n"

    HELP_OPT( "--byte-order-mark" )
      "Set the byte-order-mark for the serializer.\n\n"

    ////////// c //////////////////////////////////////////////////////////////

    HELP_OPT( "--classpath <path>" )
      "Set the JVM classpath to be used by modules using Java implementations.\n\n"

    HELP_OPT( "--compile-only" )
      "Only compile (don't execute).\n\n"

    HELP_OPT( "--compile-plan" )
      "Do not execute the query; just compile it and save the execution plan in the file specified with the -o option.\n\n"

    HELP_OPT( "--construction-mode {strip|preserve}" )
      "Set the construction mode in the static context.\n\n"

    HELP_OPT( "--context-item <item>" )
      "Set the context item to the XML document in a given file.\n\n"

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
      "The port on which the DBGP-enabled debugger client listens for connections; defaults: 28028.\n\n"
#endif /* ZORBA_WITH_DEBUGGER */

    HELP_OPT( "--default-collation <collation>" )
      "Add the given collation and set the value of the default collation in the static context to the given collation.\n\n"

    HELP_OPT( "--disable-http-resolution" )
      "Do not use HTTP to resolve URIs.\n\n"

    HELP_OPT( "--dump-lib" )
      "Dump function library.\n\n"

    ////////// e //////////////////////////////////////////////////////////////

    HELP_OPT( "--execute-plan" )
      "Do not compile the query; instead load the execution plan from the file specified by the -f -q options (or by any file specified without any other argument), and execute the loaded plan.\n\n"

    HELP_OPT( "--external-variable, -e <name>{=<file>|:=<value>}" )
      "Set the value for an external variable.\n\n"

    ////////// f //////////////////////////////////////////////////////////////

    HELP_OPT( "--force-gflwor" )
      "Force the compiler to generate GFLWOR iterators.\n\n"

    ////////// h //////////////////////////////////////////////////////////////

    HELP_OPT( "--help" )
      "Print this help message.\n\n"

    ////////// i //////////////////////////////////////////////////////////////

    HELP_OPT( "--indent, -i" )
      "Indent output.\n\n"

    HELP_OPT( "--infer-joins" )
      "Infer joins.\n\n"

    HELP_OPT( "--inline-udf" )
      "Inline user-defined functions.\n\n"

    HELP_OPT( "--iterator-tree {dot|json|xml}" )
      "Print the iterator tree in the given format.\n\n"

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

    HELP_OPT( "--multiple, -m" )
      "Execute the given queries multiple times.\n\n"

    ////////// n //////////////////////////////////////////////////////////////

    HELP_OPT( "--no-copy-optim" )
      "Apply the no-copy optimization.\n\n"

    HELP_OPT( "--no-logo" )
      "Print no logo when starting.\n\n"

    HELP_OPT( "--no-serializer" )
      "Do not serialize (discard) result.\n\n"

    HELP_OPT( "--no-tree-ids" )
      "Suppress IDs and locations in printed iterator trees and profiles.\n\n"

    HELP_OPT( "--no-uncalled-iterators" )
      "Suppress uncalled iterators in printed profiles.\n\n"

    ////////// o //////////////////////////////////////////////////////////////

    HELP_OPT( "--omit-xml-declaration, -r" )
      "Omit the XML declaration from the result.\n\n"

    HELP_OPT( "--optimization-level, -O {0|1|2}>" )
      "Optimization level for the query compiler, default: 1.\n\n"

    HELP_OPT( "--option <option>=<value>" )
      "Set an XQuery option in the static context. The QName of the option is passed as a string in the notation by James Clark (i.e. {namespace}localname). For example, --option {http://zorba.io/}option=value\n\n"

    HELP_OPT( "--ordering-mode {ordered|unordered}" )
      "Set the ordering mode in the static context.\n\n"

#ifdef ZORBA_WITH_FILE_ACCESS
    HELP_OPT( "--output-file, -o <file>" )
      "Write the result to the given file.\n\n"
#endif /* ZORBA_WITH_FILE_ACCESS */

    ////////// p //////////////////////////////////////////////////////////////

    HELP_OPT( "--parse-only" )
      "Stop after parsing the query.\n\n"

    HELP_OPT( "--print-ast" )
      "Print the abstract syntax tree.\n\n"

    HELP_OPT( "--print-errors-as-xml, -x" )
      "Print the errors as XML.\n\n"

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

    HELP_OPT( "--profile {dot|json|xml}" )
      "Print profiling information in the given format.\n\n"

    ////////// q //////////////////////////////////////////////////////////////

    HELP_OPT( "--query, -q" )
      "Query test or file URI (file://...)\n\n"

    ////////// s //////////////////////////////////////////////////////////////

    HELP_OPT( "--serialization-parameter, -z <name>=<value>" )
      "Set serialization parameter (see http://www.w3.org/TR/xslt-xquery-serialization/#serparam, e.g.: -z method=xhtml -z doctype-system=DTD/xhtml1-strict.dtd -z indent=yes).\n\n"

    HELP_OPT( "--serialize-html" )
      "Serialize the result as HTML.\n\n"

    HELP_OPT( "--serialize-plan, -s" )
      "Serialize and then load the query execution plan.\n\n"

    HELP_OPT( "--serialize-only-query" )
      "Serialize only query.\n\n"

    HELP_OPT( "--serialize-plan, s" )
      "Serialize and then load the query execution plan.\n\n"

    HELP_OPT( "--serialize-text" )
      "Serialize the result as text.\n\n"

#ifndef NDEBUG
    HELP_OPT( "--stable-iterator-ids" )
      "Print the iterator plan with stable IDs.\n\n"
#endif

#ifndef ZORBA_NO_FULL_TEXT
    HELP_OPT( "--stop-words <uri>:=<value>" )
      "Mapping specifying a stop-words URI to another.\n\n"

    ////////// t //////////////////////////////////////////////////////////////

    HELP_OPT( "--thesaurus <uri>:=<value>" )
      "Mapping specifying a thesaurus URI to another.\n\n"
#endif /* ZORBA_NO_FULL_TEXT */

    HELP_OPT( "--timing, -t" )
      "Print timing information. In case of multiple queries, the timing information is provided per query. Both wallclock time and user time (which excludes I/O, network delays and other kernel waits) are shown.\n\n"

    HELP_OPT( "--timeout <seconds>" )
      "Specify a timeout in seconds. After the specified time, the execution of the query will be aborted.\n\n"

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

    HELP_OPT( "--trailing-nl, -n" )
      "Print a trailing newline after the result of the query.\n\n"

    HELP_OPT( "--timezone <minutes>" )
      "Set implicit time zone (in minutes).\n\n"

    ////////// u //////////////////////////////////////////////////////////////

    HELP_OPT( "--uri-path <path>" )
      "URI path (list of directories) added to the built-in URI resolver, i.e. where to find modules/schemas to import.\n\n"

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
  int offset = 2; (void)offset;                                           \
  if ( (*argv)[1] == '-' || !(*argv)[2] ) { offset = 0; ++argv; }         \
  if ( !*argv ) { error = "No value given for " #ARG " option"; break; }

#define ARG_VAL (*argv + offset)

template<typename T> inline
void atoi( char const *s,  T *result, int offset = 0 ) {
  istringstream iss( s + offset );
  iss >> *result;
}

#define SET_ZCPROP(PROP) \
  atoi( *argv, &zc_props.PROP, offset )

template<class C,typename T> inline
void atoi( char const *s, C &c, void (C::*f)( T ), int offset = 0 ) {
  T temp;
  atoi( s, &temp, offset );
  (c.*f)( temp );
}

#define SET_ZPROP(PROP) \
  atoi( *argv, z_props, &Properties::set##PROP, offset )

int parse_args( int argc, char const *argv[] ) {
  bool got_as_files = false;
  char const *error = 0;
  Properties &z_props = Properties::instance();
  ZorbaCmdProperties &zc_props = ZorbaCmdProperties::instance();

  char const **const argv_orig = argv;
  for ( ++argv; *argv; ++argv ) {

    ////////// a //////////////////////////////////////////////////////////////

#ifndef NDEBUG
    if ( IS_LONG_OPT( "--abort" ) )
      z_props.setAbort( true );
    else
#endif /* NDEBUG */
    if ( IS_OPT( "--as-files", "-f" ) ) {
      zc_props.as_files_ = true;
      got_as_files = true;
    }

    ////////// b //////////////////////////////////////////////////////////////

    else if ( IS_LONG_OPT( "--base-uri" ) ) {
      PARSE_ARG( "--base-uri" );
      zc_props.base_uri_ = ARG_VAL;
    }
    else if ( IS_LONG_OPT( "--boundary-space" ) ) {
      PARSE_ARG( "--boundary-space" );
      zc_props.boundary_space_ = ARG_VAL;
    }
    else if ( IS_LONG_OPT( "--byte-order-mark" ) )
      zc_props.byte_order_mark_ = true;

    ////////// c //////////////////////////////////////////////////////////////

    else if ( IS_LONG_OPT( "--classpath" ) ) {
      PARSE_ARG( "--classpath" );
      z_props.setJVMClassPath( ARG_VAL );
    }
    else if ( IS_LONG_OPT( "--compile-only" ) )
      zc_props.compile_only_ = true;
    else if ( IS_LONG_OPT( "--compile-plan" ) )
      zc_props.save_plan_ = true;
    else if ( IS_LONG_OPT( "--construction-mode" ) ) {
      PARSE_ARG( "--construction-mode" );
      zc_props.construction_mode_ = ARG_VAL;
    }
    else if ( IS_LONG_OPT( "--context-item" ) ) {
      PARSE_ARG( "--context-item" );
      zc_props.ctx_item_ = ARG_VAL;
    }

    ////////// d //////////////////////////////////////////////////////////////

#ifdef ZORBA_WITH_DEBUGGER
    else if ( IS_OPT( "--debug", "-d" ) )
      zc_props.debug_ = true;
#endif /* ZORBA_WITH_DEBUGGER */
    else if ( IS_LONG_OPT( "--debug-file" ) ) {
      PARSE_ARG( "--debug-file" );
      z_props.setDebugFile( ARG_VAL );
    }
    else if ( IS_LONG_OPT( "--debug-stream" ) ) {
      PARSE_ARG( "--debug-stream" );
      string val( ARG_VAL );
      to_lower( val );
      if ( val == "1" || val == "cout" || val == "stdout" )
        z_props.setDebugStream( cout );
      else if ( val == "2" || val == "cerr" || val == "stderr" )
        z_props.setDebugStream( cerr );
      else {
        error = "--debug-stream argument must be one of: 1, cout, stdout, 2, cerr, or stderr.\n";
        break;
      }
    }
#ifdef ZORBA_WITH_DEBUGGER
    else if ( IS_OPT( "--debug-host", "-h" ) ) {
      PARSE_ARG( "--debug-host" );
      zc_props.debug_host_ = ARG_VAL;
    }
    else if ( IS_OPT( "--debug-port", "-p" ) ) {
      PARSE_ARG( "--debug-port" );
      SET_ZCPROP( debug_port_ );
    }
#endif /* ZORBA_WITH_DEBUGGER */
    else if ( IS_LONG_OPT( "--default-collation" ) ) {
      PARSE_ARG( "--default-collation" );
      zc_props.default_collation_ = ARG_VAL;
    }
    else if ( IS_LONG_OPT( "--disable-http-resolution" ) ) {
      sctx_opt opt;
      opt.clark_qname = "{http://zorba.io/options/features}disable";
      opt.value = "http-uri-resolution";
      zc_props.sctx_opts_.push_back( opt );
    }
    else if ( IS_LONG_OPT( "--dump-lib" ) )
      z_props.setDumpLib( true );

    ////////// e //////////////////////////////////////////////////////////////

    else if ( IS_LONG_OPT( "--execute-plan" ) )
      zc_props.load_plan_ = true;
    else if ( IS_OPT( "--external-variable", "-e" ) ) {
      PARSE_ARG( "--external-variable" );
      string key, value;
      if ( !split_key_value( ARG_VAL, "=", &key, &value ) ) {
        error = "--external-variable argument must be of the form name=file or name:=value\n";
        break;
      }
      external_var ev;
      ev.var_value = value;

      if ( key[0] == ':' ) {
        error = "--external-variable argument must be of the form name=file or name:=value\n";
        break;
      }
      if ( key[ key.size() - 1 ] == ':' )
        key.erase( key.size() - 1 );
      else
        ev.inline_file = true;
      ev.var_name = key;

      zc_props.external_vars_.push_back( ev );
    }

    ////////// f //////////////////////////////////////////////////////////////

    else if ( IS_LONG_OPT( "--force-gflwor" ) )
      z_props.setForceGFLWOR( true );

    ////////// h //////////////////////////////////////////////////////////////

    else if ( IS_OPT( "--help", "-h" ) ) {
      cout << "Zorba NoSQL Query Processor, Version: "
           << Zorba::version() << '\n'
           << "Available options:\n\n"
           << get_help_msg();
      exit( 0 );
    }

    ////////// i //////////////////////////////////////////////////////////////

    else if ( IS_OPT( "--indent", "-i" ) )
      zc_props.indent_ = true;
    else if ( IS_LONG_OPT( "--infer-joins" ) ) {
      PARSE_ARG( "--infer-joins" );
      z_props.setInferJoins( bool_of( ARG_VAL ) );
    }
    else if ( IS_LONG_OPT( "--inline-udf" ) ) {
      PARSE_ARG( "--inline-udf" );
      z_props.setInlineUDF( bool_of( ARG_VAL ) );
    }
    else if ( IS_LONG_OPT( "--iterator-tree" ) ) {
      PARSE_ARG( "--iterator-tree" );
      string val( ARG_VAL );
      to_lower( val );
      if ( val == "none" )
        z_props.setPlanFormat( PLAN_FORMAT_NONE );
      else if ( val == "dot" )
        z_props.setPlanFormat( PLAN_FORMAT_DOT );
      else if ( val == "json" )
        z_props.setPlanFormat( PLAN_FORMAT_JSON );
      else if ( val == "xml" )
        z_props.setPlanFormat( PLAN_FORMAT_XML );
      else {
        error = "--iterator-tree argument must be one of: none, dot, json, or xml.\n";
        break;
      }
    }

    ////////// j //////////////////////////////////////////////////////////////

    else if ( IS_OPT( "--jsoniq", "-j" ) )
      zc_props.jsoniq_ = true;

    ////////// l //////////////////////////////////////////////////////////////

    else if ( IS_OPT( "--lib-module", "-l" ) )
      zc_props.lib_module_ = true;
    else if ( IS_LONG_OPT( "--lib-path" ) ) {
      PARSE_ARG( "--lib-path" );
      zc_props.lib_path_ = ARG_VAL;
    }
    else if ( IS_LONG_OPT( "--loop-hoisting" ) ) {
      PARSE_ARG( "--loop-hoisting" );
      z_props.setLoopHoisting( bool_of( ARG_VAL ) );
    }

    ////////// m //////////////////////////////////////////////////////////////

    else if ( IS_LONG_OPT( "--max-udf-call-depth" ) ) {
      PARSE_ARG( "--max-udf-call-depth" );
      SET_ZPROP( MaxUDFCallDepth );
    }
    else if ( IS_LONG_OPT( "--module-path" ) ) {
      PARSE_ARG( "--module-path" );
      zc_props.module_path_ = ARG_VAL;
    }
    else if ( IS_OPT( "--multiple", "-m" ) ) {
      PARSE_ARG( "--multiple" );
      SET_ZCPROP( multiple_ );
    }

    ////////// n //////////////////////////////////////////////////////////////

    else if ( IS_LONG_OPT( "--no-copy-optim" ) ) {
      PARSE_ARG( "--no-copy-optim" );
      z_props.setNoCopyOptim( bool_of( ARG_VAL ) );
    }
    else if ( IS_LONG_OPT( "--no-logo" ) )
      zc_props.no_logo_ = true;
    else if ( IS_LONG_OPT( "--no-serializer" ) )
      zc_props.no_serializer_ = true;
    else if ( IS_LONG_OPT( "--no-tree-ids" ) )
      z_props.setNoTreeIDs( true );
    else if ( IS_LONG_OPT( "--no-uncalled-iterators" ) )
      z_props.setNoUncalledIterators( true );

    ////////// o //////////////////////////////////////////////////////////////

    else if ( IS_OPT( "--omit-xml-declaration", "-r" ) )
      zc_props.omit_xml_declaration_ = true;
    else if ( IS_OPT( "--optimization-level", "-O" ) ) {
      PARSE_ARG( "--optimization-level" );
      unsigned opt_level;
      atoi( ARG_VAL, &opt_level );
      if ( opt_level > 2 ) {
        error = "Only 0, 1 and 2 are allowed as values for --optimization-level";
        break;
      }
      z_props.setOptimizationLevel( opt_level );
    }
    else if ( IS_LONG_OPT( "--option" ) ) {
      PARSE_ARG( "--option" );
      string key, value;
      if ( !split_key_value( ARG_VAL, "=", &key, &value ) ) {
        error = "--option argument must be of the form {namespace}localname=value\n";
        break;
      }
      // TODO: check key is of the form {ns}local
      sctx_opt opt;
      opt.clark_qname = key;
      opt.value = value;
      zc_props.sctx_opts_.push_back( opt );
    }
    else if ( IS_LONG_OPT( "--ordering-mode" ) ) {
      PARSE_ARG( "--ordering-mode" );
      zc_props.ordering_mode_ = ARG_VAL;
    }
#ifdef ZORBA_WITH_FILE_ACCESS
    else if ( IS_OPT( "--output-file", "-o" ) ) {
      PARSE_ARG( "--output-file" );
      zc_props.output_file_ = ARG_VAL;
    }
#endif /* ZORBA_WITH_FILE_ACCESS */

    ////////// p //////////////////////////////////////////////////////////////

    else if ( IS_LONG_OPT( "--parse-only" ) )
      zc_props.parse_only_ = true;
    else if ( IS_OPT( "--print-ast", "-a" ) )
      z_props.setPrintAST( true );
    else if ( IS_OPT( "--print-errors-as-xml", "-x" ) )
      zc_props.print_errors_as_xml_ = true;
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
      zc_props.print_query_ = true;
    else if ( IS_LONG_OPT( "--print-static-types" ) )
      z_props.setPrintStaticTypes( true );
    else if ( IS_LONG_OPT( "--print-translated" ) )
      z_props.setPrintTranslated( true );
    else if ( IS_LONG_OPT( "--profile" ) )
    {
      PARSE_ARG( "--profile" );
      string val( ARG_VAL );
      to_lower( val );
      if ( val == "none" )
        z_props.setProfileFormat( PROFILE_FORMAT_NONE );
      else
      {
        if ( val == "dot" )
          z_props.setProfileFormat( PROFILE_FORMAT_DOT );
        else if ( val == "json" )
          z_props.setProfileFormat( PROFILE_FORMAT_JSON );
        else if ( val == "xml" )
          z_props.setProfileFormat( PROFILE_FORMAT_XML );
        else
        {
          error = "--profile argument must be one of: none, dot, json, or xml.\n";
          break;
        }
        z_props.setCollectProfile(true);
      }
    }

    ////////// q //////////////////////////////////////////////////////////////

    else if ( IS_OPT( "--query", "-q" ) ) {
      if ( !got_as_files )
        zc_props.as_files_ = false;
      if ( *(argv+1) && !strncmp( *(argv+1), "-f", 2 ) )
        break; // is it "-q -f <filename>" perhaps?
      PARSE_ARG( "--query" );
      zc_props.queries_or_files_.push_back( ARG_VAL );
    }

    ////////// s //////////////////////////////////////////////////////////////

    else if ( IS_OPT( "--serialization-parameter", "-z" ) ) {
      PARSE_ARG( "--serialization-parameter" );
      string key, value;
      serialization_param sp;
      if ( split_key_value( ARG_VAL, "=", &key, &value ) ) {
        sp.first = key;
        sp.second = value;
      } else
        sp.first = ARG_VAL;
      zc_props.serialization_params_.push_back( sp );
    }
    else if ( IS_LONG_OPT( "--serialize-html" ) )
      zc_props.serialize_html_ = true;
    else if ( IS_LONG_OPT( "--serialize-only-query" ) ) {
      PARSE_ARG( "--serialize-only-query" );
      zc_props.serialize_only_query_ = bool_of( ARG_VAL );
    }
    else if ( IS_OPT( "--serialize-plan", "-s" ) )
      zc_props.serialize_plan_ = true;
    else if ( IS_LONG_OPT( "--serialize-text" ) )
      zc_props.serialize_text_ = true;
#ifndef NDEBUG
    else if ( IS_LONG_OPT( "--stable-iterator-ids" ) )
      z_props.setStableIteratorIDs( true );
#endif
#ifndef ZORBA_NO_FULL_TEXT
    else if ( IS_LONG_OPT( "--stop-words" ) ) {
      PARSE_ARG( "--stop-words" );
      string uri, value;
      if ( !split_key_value( ARG_VAL, ":=", &uri, &value ) ) {
        error = "--stop-words argument must be of the form URI:=value\n";
        break;
      }
      ft_mapping ft;
      ft.uri = uri;
      ft.value = value;
      zc_props.stop_words_mapping_.push_back( ft );
    }

    ////////// t //////////////////////////////////////////////////////////////

    else if ( IS_LONG_OPT( "--thesaurus" ) ) {
      PARSE_ARG( "--thesaurus" );
      string uri, value;
      if ( !split_key_value( ARG_VAL, ":=", &uri, &value ) ) {
        error = "--thesaurus argument must be of the form URI:=value\n";
        break;
      }
      if ( uri == "default" )
        uri = "##default";
      ft_mapping ft;
      ft.uri = uri;
      ft.value = value;
      zc_props.thesaurus_mapping_.push_back( ft );
    }
#endif /* ZORBA_NO_FULL_TEXT */
    else if ( IS_OPT( "--timing", "-t" ) )
      zc_props.timing_ = true;
    else if ( IS_LONG_OPT( "--timeout" ) ) {
      PARSE_ARG( "--timeout" );
      SET_ZCPROP( timeout_ );
    }
    else if ( IS_LONG_OPT( "--trace-parsing" ) )
      z_props.setTraceParsing( true );
    else if ( IS_LONG_OPT( "--trace-scanning" ) )
      z_props.setTraceScanning( true );
#ifndef NDEBUG
    else if ( IS_LONG_OPT( "--trace-codegen" ) )
      z_props.setTraceCodegen( true );
#ifndef ZORBA_NO_FULL_TEXT
    else if ( IS_LONG_OPT( "--trace-fulltext" ) )
      z_props.setTraceFulltext( true );
#endif
    else if ( IS_LONG_OPT( "--trace-translator" ) )
      z_props.setTraceTranslator( true );
#endif /* NDEBUG */
    else if ( IS_OPT( "--trailing-nl", "-n" ) )
      zc_props.trailing_nl_ = true;
    else if ( IS_LONG_OPT( "--timezone" ) ) {
      PARSE_ARG( "--timezone" );
      SET_ZCPROP( timezone_ );
      zc_props.timezone_set_ = true;
    }

    ////////// u //////////////////////////////////////////////////////////////

    else if ( IS_LONG_OPT( "--uri-path" ) ) {
      PARSE_ARG( "--uri-path" );
      zc_props.uri_path_ = ARG_VAL;
    }
    else if ( IS_LONG_OPT( "--use-indexes" ) ) {
      PARSE_ARG( "--use-indexes" );
      z_props.setUseIndexes( true );
    }

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
      zc_props.queries_or_files_.push_back( *argv );
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

/* vim:set et sw=2 ts=2: */
