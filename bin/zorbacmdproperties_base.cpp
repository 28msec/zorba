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

#include "zorbacmdproperties_base.h"

namespace zorbacmd {

///////////////////////////////////////////////////////////////////////////////

ZorbaCMDPropertiesBase::ZorbaCMDPropertiesBase() {
  theAsFiles = true;
  theByteOrderMark = false;
  theCompileOnly = false;
  theDebug = false;
  theDebugHost = "127.0.0.1";
  theDebugPort = 28028;
  theFparm = false;
  theIndent = false;
  theLibModule = false;
  theLoadPlan = false;
  theMultiple = 1;
  theNoLogo = false;
  theNoSerializer = false;
  theOmitXmlDeclaration = false;
  theOptimizationLevel = "O1";
  theParseOnly = false;
  thePrintErrorsAsXml = false;
  thePrintQuery = false;
  theQBeforeF = false;
  theSavePlan = false;
  theSerializeHtml = false;
  theSerializePlan = false;
  theSerializeText = false;
  theTimeout = -1;
  theTiming = false;
  theTrailingNl = false;
  theUnknownOption = false;
}

char const** ZorbaCMDPropertiesBase::get_all_options() const {
  static const char* result [] = {
    "--as-files",
    "--base-uri",
    "--boundary-space",
    "--byte-order-mark",
    "--classpath",
    "--compile-only",
    "--compile-plan",
    "--construction-mode",
    "--context-item",
    "--debug",
    "--debug-host",
    "--debug-port",
    "--default-collation",
    "--disable-http-resolution",
    "--execute-plan",
    "--external-variable",
    "--indent",
    "--lib-module",
    "--lib-path",
    "--module-path",
    "--multiple",
    "--no-logo",
    "--no-serializer",
    "--omit-xml-declaration",
    "--optimization-level",
    "--option",
    "--ordering-mode",
#ifdef ZORBA_WITH_FILE_ACCESS
    "--output-file",
#endif /* ZORBA_WITH_FILE_ACCESS */
    "--parse-only",
    "--print-errors-as-xml",
    "--print-query",
    "--query",
    "--serialization-parameter",
    "--serialize-html",
    "--serialize-plan",
    "--serialize-text",
    "--stop-words",
    "--thesaurus",
    "--timeout",
    "--timing",
    "--trailing-nl",
    "--uri-path",
    NULL
  };
  return result;
}

#define IS_LONG_OPT(OPT)  (strcmp( *argv, (OPT) ) == 0)
#define IS_SHORT_OPT(OPT) (strncmp( *argv, (OPT), 2 ) == 0)
#define IS_OPT(LOPT,SOPT) (IS_LONG_OPT(LOPT) || IS_SHORT_OPT(SOPT))

std::string ZorbaCMDPropertiesBase::load_argv(int argc, const char **argv) {
  if ( !argv )
    return "";

  std::string result;
  for ( ++argv; *argv; ++argv ) {
    if ( IS_OPT( "--help", "-h" ) )
      return "!HELP";
    if ( IS_OPT( "--version", "-v" ) )
      return "!VER";

    if ( IS_OPT( "--as-files", "-f" ) ) {
      theFparm = true;
      theAsFiles = true;
    }
    else if ( IS_LONG_OPT( "--base-uri" ) ) {
      int d = 2;
      if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
      if (!*argv) { result = "No value given for --base-uri option"; break; }
      init_val(*argv, theBaseUri, d);
    }
    else if ( IS_LONG_OPT( "--boundary-space" ) ) {
      int d = 2;
      if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
      if (!*argv) { result = "No value given for --boundary-space option"; break; }
      init_val(*argv, theBoundarySpace, d);
    }
    else if ( IS_LONG_OPT( "--byte-order-mark" ) ) 
      theByteOrderMark = true;
    else if ( IS_LONG_OPT( "--classpath" ) ) {
      int d = 2;
      if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
      if (!*argv) { result = "No value given for --classpath option"; break; }
      init_val(*argv, theClasspath, d);
    }
    else if ( IS_LONG_OPT( "--compile-only" ) ) 
      theCompileOnly = true;
    else if ( IS_LONG_OPT( "--compile-plan" ) )
      theSavePlan = true;
    else if ( IS_LONG_OPT( "--construction-mode" ) ) {
      int d = 2;
      if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
      if (!*argv) { result = "No value given for --construction-mode option"; break; }
      init_val(*argv, theConstructionMode, d);
    }
    else if ( IS_LONG_OPT( "--context-item" ) ) {
      int d = 2;
      if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
      if (!*argv) { result = "No value given for --context-item option"; break; }
      init_val(*argv, theContextItem, d);
    }
    else if ( IS_OPT( "--debug", "-d" ) ) 
      theDebug = true;
    else if ( IS_OPT( "--debug-host", "-h" ) ) {
      int d = 2;
      if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
      if (!*argv) { result = "No value given for --debug-host option"; break; }
      init_val(*argv, theDebugHost, d);
    }
    else if ( IS_OPT( "--debug-port", "-p" ) ) {
      int d = 2;
      if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
      if (!*argv) { result = "No value given for --debug-port option"; break; }
      init_val(*argv, theDebugPort, d);
    }
    else if ( IS_LONG_OPT( "--default-collation" ) ) {
      int d = 2;
      if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
      if (!*argv) { result = "No value given for --default-collation option"; break; }
      init_val(*argv, theDefaultCollation, d);
    }
    else if ( IS_LONG_OPT( "--execute-plan" ) )
      theLoadPlan = true;
    else if ( IS_OPT( "--external-variable", "-e" ) ) {
      int d = 2;
      if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
      if (!*argv) { result = "No value given for --external-variable option"; break; }
      init_val(*argv, theExternalVariable, d);
    }
    else if ( IS_OPT( "--indent", "-i" ) ) 
      theIndent = true;
    else if ( IS_OPT( "--lib-module", "-l" ) )
      theLibModule = true;
    else if ( IS_LONG_OPT( "--lib-path" ) ) {
      int d = 2;
      if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
      if (!*argv) { result = "No value given for --lib-path option"; break; }
      init_val(*argv, theLibPath, d);
    }
    else if ( IS_LONG_OPT( "--module-path" ) ) {
      int d = 2;
      if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
      if (!*argv) { result = "No value given for --module-path option"; break; }
      init_val(*argv, theModulePath, d);
    }
    else if ( IS_LONG_OPT( "--no-logo" ) ) 
      theNoLogo = true;
    else if ( IS_LONG_OPT( "--no-serializer" ) ) 
      theNoSerializer = true;
    else if ( IS_OPT( "--multiple", "-m" ) ) {
      int d = 2;
      if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
      if (!*argv) { result = "No value given for --multiple option"; break; }
      init_val(*argv, theMultiple, d);
    }
    else if ( IS_OPT( "--omit-xml-declaration", "-r" ) ) 
      theOmitXmlDeclaration = true;
    else if ( IS_LONG_OPT( "--optimization-level" ) ) {
      int d = 2;
      if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
      if (!*argv) { result = "No value given for --optimization-level option"; break; }
      init_val(*argv, theOptimizationLevel, d);
    }
    else if ( IS_LONG_OPT( "--option" ) ) {
      int d = 2;
      if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
      if (!*argv) { result = "No value given for --option option"; break; }
      init_val(*argv, theOption, d);
    }
    else if ( IS_LONG_OPT( "--ordering-mode" ) ) {
      int d = 2;
      if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
      if (!*argv) { result = "No value given for --ordering-mode option"; break; }
      init_val(*argv, theOrderingMode, d);
    }
#ifdef ZORBA_WITH_FILE_ACCESS
    else if ( IS_OPT( "--output-file", "-o" ) ) {
      int d = 2;
      if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
      if (!*argv) { result = "No value given for --output-file option"; break; }
      init_val(*argv, theOutputFile, d);
    }
#endif /* ZORBA_WITH_FILE_ACCESS */
    else if ( IS_LONG_OPT( "--parse-only" ) ) 
      theParseOnly = true;
    else if ( IS_OPT( "--print-errors-as-xml", "-x" ) )
      thePrintErrorsAsXml = true;
    else if ( IS_LONG_OPT( "--print-query" ) ) 
      thePrintQuery = true;
    else if ( IS_OPT( "--query", "-q" ) ) {
      int d = 2;
      if(theFparm == false)
        theAsFiles = false;
      if(*(argv+1) && !strncmp(*(argv+1), "-f", 2))
      {
        theQBeforeF = true; // is it "-q -f <filename>" perhaps?
        break;           // stop functionality here
      }
      if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
      if (!*argv) { result = "No value given for --query option"; break; }
      init_val(*argv, theQueriesOrFiles, d);
    }
    else if ( IS_LONG_OPT( "--serialize-html" ) ) 
      theSerializeHtml = true;
    else if ( IS_LONG_OPT( "--serialize-text" ) ) 
      theSerializeText = true;
    else if ( IS_OPT( "--serialization-parameter", "-z" ) ) {
      int d = 2;
      if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
      if (!*argv) { result = "No value given for --serialization-parameter option"; break; }
      init_val(*argv, theSerializationParameter, d);
    }
    else if ( IS_LONG_OPT( "--stop-words" ) ) {
      int d = 2;
      if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
      if (!*argv) { result = "No value given for --stop-words option"; break; }
      init_val(*argv, theStopWords, d);
    }
    else if ( IS_OPT( "--timing", "-t" ) ) 
      theTiming = true;
    else if ( IS_LONG_OPT( "--timeout" ) ) {
      int d = 2;
      if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
      if (!*argv) { result = "No value given for --timeout option"; break; }
      init_val(*argv, theTimeout, d);
    }
    else if ( IS_LONG_OPT( "--trailing-nl" ) ) 
      theTrailingNl = true;
    else if ( IS_LONG_OPT( "--uri-path" ) ) {
      int d = 2;
      if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
      if (!*argv) { result = "No value given for --uri-path option"; break; }
      init_val(*argv, theUriPath, d);
    }
    else if ( IS_OPT( "--serialize-plan", "-s" ) )
      theSerializePlan = true;
    else if ( IS_LONG_OPT( "--disable-http-resolution" ) ) {
      init_val("{http://zorba.io/options/features}disable=http-uri-resolution",
                theOption, 0);
    }
    else if ( IS_LONG_OPT( "--thesaurus" ) ) {
      int d = 2;
      if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
      if (!*argv) { result = "No value given for --thesaurus option"; break; }
      init_val(*argv, theThesaurus, d);
    }

    else if ( IS_LONG_OPT( "--" ) ) {
      copy_args (++argv);
      break;
    } else if ( (*argv)[0] == '-' ) {
      result = "unknown command line option "; result += *argv; 
      theUnknownOption = true; break; 
    } else {
      init_val(*argv, theQueriesOrFiles, 0);
      copy_args( argv );
    }
  } // for
  return result;
}

char const* ZorbaCMDPropertiesBase::get_help_msg() const {
  return
    "--as-files, -f\nTreat all -q arguments as file paths instead of URIs or inline queries. This option is deprecated and will be defaulted to true in the future, so any entry in the command line is going to be treated as files.\n\n"
    "--base-uri\nSet the base URI property of the static context.\n\n"
    "--boundary-space\nSet the boundary-space policy ('strip' or 'preserve') in the static context.\n\n"
    "--byte-order-mark\nSet the byte-order-mark for the serializer.\n\n"
    "--classpath\nJVM classpath to be used by modules using Java implementations\n\n"
    "--compile-only\nOnly compile (don't execute)\n\n"
    "--compile-plan,\nDo not execute the query; just compile it and save the execution plan in the file specified with the -o option.\n\n"
    "--construction-mode\nSet the construction mode ('strip' or 'preserve') in the static context.\n\n"
    "--context-item\nSet the context item to the XML document in a given file.\n\n"
    "--debug, -d\nLaunch the Zorba debugger server and connect to a DBGP-enabled debugger client.\n\n"
    "--debug-host, -h\nThe host where the DBGP-enabled debugger client listens for connections. Defaults to: 127.0.0.1\n\n"
    "--debug-port, -p\nThe port on which the DBGP-enabled debugger client listens for connections. Defaults to: 28028\n\n"
    "--default-collation\nAdd the given collation and set the value of the default collation in the static context to the given collation.\n\n"
    "--disable-http-resolution\nDo not use HTTP to resolve URIs\n\n"
    "--execute-plan\nDo not compile the query; instead load the execution plan from the file specified by the -f -q options (or by any file specified without any other argument), and execute the loaded plan.\n\n"
    "--external-variable, -e\nProvide the value for a variable given a file (name=file) or a value (name:=value)\n\n"
    "--indent, -i\nIndent output.\n\n"
    "--lib-module, -l\nQuery compiler option to treat the query as a library module. If this is set --compile-only option is also set to true.\n\n"
    "--lib-path\nLibrary path (list of directories) where Zorba will look for dynamic libraries (e.g., module external function implementations.\n\n"
    "--module-path\nPath (list of directories) to add to both the URI and Library paths.\n\n"
    "--multiple, -m\nExecute the given queries multiple times.\n\n"
    "--no-logo\nPrint no logo when starting.\n\n"
    "--no-serializer\nDo not serialize (discard) result.\n\n"
    "--omit-xml-declaration, -r\nOmit the XML declaration from the result.\n\n"
    "--optimization-level\nOptimization level for the query compiler (O0, O1 or O2 - default: O1)\n\n"
    "--option\nSet an XQuery option in the static context. The QName of the option is passed as a string in the notation by James Clark (i.e. {namespace}localname). For example, --option {http://zorba.io/}option=value\n\n"
    "--ordering-mode\nSet the ordering mode ('ordered' or 'unordered') in the static context.\n\n"
    "--output-file, -o\nWrite the result to the given file.\n\n"
    "--parse-only\nStop after parsing the query.\n\n"
    "--print-errors-as-xml, -x\nPrint the errors as XML.\n\n"
    "--print-query\nPrint the queries.\n\n"
    "--query, -q\nQuery test or file URI (file://...)\n\n"
    "--serialization-parameter, -z\nSet serialization parameter in the form of a parameter=value pair (see http://www.w3.org/TR/xslt-xquery-serialization/#serparam, e.g.: -z method=xhtml -z doctype-system=DTD/xhtml1-strict.dtd -z indent=yes).\n\n"
    "--serialize-html\nSerialize the result as HTML.\n\n"
    "--serialize-plan, -s\nSerialize and then load the query execution plan.\n\n"
    "--serialize-text\nSerialize the result as Text.\n\n"
    "--stop-words\nMapping specifying a stop-words URI to another.\n\n"
    "--thesaurus\nMapping specifying a thesaurus URI to another.\n\n"
    "--timeout\nSpecify a timeout in seconds. After the specified time, the execution of the query will be aborted.\n\n"
    "--timing, -t\nPrint timing information. In case of multiple queries the timing information is provided per each query. Both wallclock time and user time (which excludes I/O, network delays and other kernel waits) are shown.\n\n"
    "--trailing-nl\nOutput a trailing newline after the result of the query.\n\n"
    "--uri-path\nURI path (list of directories) added to the built-in URI resolver, i.e. where to find modules/schemas to import.\n\n"
    ;
}

ZorbaCMDPropertiesBase const* ZorbaCMDPropertiesBase::instance() {
  static ZorbaCMDPropertiesBase result;
  return &result;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorbacmd
/* vim:set et sw=2 ts=2: */
