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

#include <cstring>

#include "zorba_properties.h"

namespace zorba { 

///////////////////////////////////////////////////////////////////////////////

ZorbaProperties::ZorbaProperties() {
  theAbort = false;
  theCompileOnly = false;
  theDebug = false;
  theDumpLib = false;
  theForceGflwor = false;
  theInferJoins = true;
  theInlineUdf = true;
  theIterPlanTest = false;
  theJsoniqParser = false;
  theLibModule = false;
  theLoopHoisting = true;
  theMaxUdfCallDepth = 1024;
  theNoCopyOptim = true;
  theNoTreeIds = false;
  theOptimizer = 1;
  thePrintAst = false;
  thePrintIntermediateOpt = false;
  thePrintItemFlow = false;
  thePrintIteratorTree = false;
  thePrintLocations = false;
  thePrintNormalized = false;
  thePrintOptimized = false;
  thePrintQuery = false;
  thePrintStaticTypes = true;
  thePrintTime = false;
  thePrintTranslated = false;
  thePrintXqdoc = false;
  theReorderGlobals = true;
  theSerializeOnlyQuery = -1;
  theSpecializeCmp = true;
  theSpecializeNum = true;
  theStableIteratorIds = false;
  theTestPlanSerialization = false;
  theTraceCodegen = false;
  theTraceFulltext = false;
  theTraceParsing = false;
  theTraceScanning = false;
  theTraceTranslator = false;
  theUseIndexes = true;
  theUseSerializer = false;
}

char const** ZorbaProperties::get_all_options() const {
  static char const *result[] = {
    "--abort",
    "--CLASSPATH",
    "--compile-only",
    "--debug",
    "--debug-file",
    "--dot-plan-file",
    "--dump-lib",
    "--external-var",
    "--force-gflwor",
    "--infer-joins",
    "--inline-udf",
    "--iter-plan-test",
    "--jsoniq",
    "--lib-module",
    "--loop-hoisting",
    "--max-udf-call-depth",
    "--no-copy-optim",
    "--no-tree-ids",
    "--optimizer",
    "--plan",
    "--print-ast",
    "--print-intermediate-opt",
    "--print-item-flow",
    "--print-iterator-tree",
    "--print-locations",
    "--print-normalized",
    "--print-optimized",
    "--print-query",
    "--print-static-types",
    "--print-time",
    "--print-translated",
    "--print-xqdoc",
    "--query",
    "--reorder-globals",
    "--result-file",
    "--serialize-only-query",
    "--serializer-param",
    "--specialize-cmp",
    "--specialize-num",
    "--stable-iterator-ids",
    "--trace-codegen",
    "--trace-fulltext",
    "--trace-parsing",
    "--trace-scanning",
    "--trace-translator",
    "--tz",
    "--use-serializer",
    0
  };
  return result;
}

char const* ZorbaProperties::get_help_msg() const {
  return
    "--abort\nabort when fatal error happens\n\n"
    "--CLASSPATH\nJVM classpath to be used by modules using Java implementations\n\n"
    "--compile-only\nonly compile (don't execute)\n\n"
    "--debug-file\nlog file for debugging information\n\n"
    "--debug\ncompile the query in debug mode\n\n"
    "--dot-plan-file\ngenerate the dot iterator plan\n\n"
    "--dump-lib\ndump function library\n\n"
    "--external-var, -x\nexternal variables (e.g. -x x=file1.xml -x y:=strValue)\n\n"
    "--force-gflwor\nforce compiler to generate GFLWOR iterators\n\n"
    "--infer-joins\ninfer joins (1=enabled (default), 0=off)\n\n"
    "--inline-udf\ninline functions (1=enabled (default), 0=off)\n\n"
    "--iter-plan-test\nrun as iterator plan test\n\n"
    "--loop-hoisting\nhoist expressions out of loops (1=enabled (default), 0=off)\n\n"
    "--max-udf-call-depth\nmaximum stack depth of udf function calls\n\n"
    "--no-copy-optim\napply the no-copy optimization (1=enabled (default), 0=off)\n\n"
    "--no-tree-ids\nsuppress ids and locations from compiler tree dumps\n\n"
    "--optimizer, -O\noptimization level (0, 1 or 2 - 1 is default)\n\n"
    "--plan\ntest plan serialization, i.e. save the plan, load it back and then execute it\n\n"
    "--print-ast, -a\nprint the parse tree\n\n"
    "--print-intermediate-opt\nprint intermediate optimizations\n\n"
    "--print-item-flow, -f\nshow items produced by all iterators\n\n"
    "--print-iterator-tree, -i\nprint the iterator tree\n\n"
    "--print-locations\nprint parser locations for compiler expressions\n\n"
    "--print-normalized, -n\nprint the translated expression tree\n\n"
    "--print-optimized, -P\nprint the optimized expression tree\n\n"
    "--print-query, -q\nprint the query\n\n"
    "--print-static-types\nprint static type inference\n\n"
    "--print-time, -t\nprint the execution time\n\n"
    "--print-translated\nprint the normalized expression tree\n\n"
    "--print-xqdoc\ncreate output for XQDoc\n\n"
    "--query, -e\nexecute inline query\n\n"
    "--reorder-globals\nreorder global variables (1=enabled (default), 0=off)\n\n"
    "--result-file, -o\nresult file\n\n"
    "--serialize-only-query\nserialize-only-query (<0=unknown (default), 1=enabled, 0=off)\n\n"
    "--serializer-param, -z\nserializer parameters (see http://www.w3.org/TR/xslt-xquery-serialization/#serparam, e.g. -z method=xhtml, -z doctype-system='DTD/xhtml1-strict.dtd', -z indent=yes)\n\n"
    "--specialize-cmp\nspecialize generic comparisons (1=enabled (default), 0=off)\n\n"
    "--specialize-num\nspecialize numerics (1=enabled (default), 0=off)\n\n"
    "--stable-iterator-ids\nprint the iterator plan with stable ids\n\n"
#ifndef NDEBUG
    "--trace-codegen, -c\ntrace the codegenerator\n\n"
    "--trace-fulltext\ntrace full-text evaluation\n\n"
    "--trace-translator, -l\ntrace the translator\n\n"
#endif
    "--trace-parsing, -p\ntrace parsing\n\n"
    "--trace-scanning, -s\ntrace scanning\n\n"
    "--tz\nimplicit time zone (in minutes)\n\n"
    "--use-serializer, -r\nuse serializer\n\n"
  ;
}

ZorbaProperties const* ZorbaProperties::instance() {
  static ZorbaProperties instance;
  return &instance;
}

#define IS_LONG_OPT(OPT)  (strcmp( *argv, (OPT) ) == 0)
#define IS_SHORT_OPT(OPT) (strncmp( *argv, (OPT), 2 ) == 0)
#define IS_OPT(LOPT,SOPT) (IS_LONG_OPT(LOPT) || IS_SHORT_OPT(SOPT))

std::string ZorbaProperties::load_argv( int argc, char const *argv[] ) {
  if ( !argv )
    return "";

  std::string result;
  for ( ++argv; *argv; ++argv ) {
    if ( IS_OPT( "--help", "-h" ) )
      return "!HELP";
    if ( IS_OPT( "--version", "-v" ) )
      return "!VER";

    if ( IS_LONG_OPT( "--abort" ) )
      theAbort = true;
    else if ( IS_LONG_OPT( "--compile-only" ) )
      theCompileOnly = true;
    else if ( IS_LONG_OPT( "--CLASSPATH" ) ) {
      int d = 2;
      if ((*argv)[1] == '-' || (*argv)[2] == '\0') { d = 0; ++argv; }
      if (!*argv) { result = "No value given for --CLASSPATH option"; break; }
      init_val(*argv, theCLASSPATH, d);
    }
    else if ( IS_LONG_OPT( "--debug" ) )
      theDebug = true;
    else if ( IS_LONG_OPT( "--debug-file" ) ) {
      int d = 2;
      if ((*argv)[1] == '-' || (*argv)[2] == '\0') { d = 0; ++argv; }
      if (!*argv) { result = "No value given for --debug-file option"; break; }
      init_val(*argv, theDebugFile, d);
    }
    else if ( IS_LONG_OPT( "--dot-plan-file" ) ) {
      int d = 2;
      if ((*argv)[1] == '-' || (*argv)[2] == '\0') { d = 0; ++argv; }
      if (!*argv) { result = "No value given for --dot-plan-file option"; break; }
      init_val(*argv, theDotPlanFile, d);
    }
    else if ( IS_LONG_OPT( "--dump-lib" ) )
      theDumpLib = true;
    else if ( IS_OPT( "--external-var", "-x" ) ) {
      int d = 2;
      if ((*argv)[1] == '-' || (*argv)[2] == '\0') { d = 0; ++argv; }
      if (!*argv) { result = "No value given for --external-var option"; break; }
      init_val( *argv, theExternalVar, d );
    }
    else if ( IS_LONG_OPT( "--force-gflwor" ) )
      theForceGflwor = true;
    else if ( IS_LONG_OPT( "--infer-joins" ) ) {
      int d = 2;
      if ((*argv)[1] == '-' || (*argv)[2] == '\0') { d = 0; ++argv; }
      if (!*argv) { result = "No value given for --infer-joins option"; break; }
      init_val(*argv, theInferJoins, d);
    }
    else if ( IS_LONG_OPT( "--inline-udf" ) ) {
      int d = 2;
      if ((*argv)[1] == '-' || (*argv)[2] == '\0') { d = 0; ++argv; }
      if (!*argv) { result = "No value given for --inline-udf option"; break; }
      init_val(*argv, theInlineUdf, d);
    }
    else if ( IS_LONG_OPT( "--iter-plan-test" ) )
      theIterPlanTest = true;
    else if ( IS_OPT( "--jsoniq", "-j" ) )
      theJsoniqParser = true;
    else if ( IS_LONG_OPT( "--lib-module" ) )
      theLibModule = true;
    else if ( IS_LONG_OPT( "--loop-hoisting" ) ) {
      int d = 2;
      if ((*argv)[1] == '-' || (*argv)[2] == '\0') { d = 0; ++argv; }
      if (!*argv) { result = "No value given for --loop-hoisting option"; break; }
      init_val(*argv, theLoopHoisting, d);
    }
    else if ( IS_LONG_OPT( "--max-udf-call-depth" ) ) {
      int d = 2;
      if ((*argv)[1] == '-' || (*argv)[2] == '\0') { d = 0; ++argv; }
      if (!*argv) { result = "No value given for --max-udf-call-depth option"; break; }
      init_val(*argv, theMaxUdfCallDepth, d);
    }
    else if ( IS_LONG_OPT( "--no-copy-optim" ) ) {
      int d = 2;
      if ((*argv)[1] == '-' || (*argv)[2] == '\0') { d = 0; ++argv; }
      if (!*argv) {
        result = "No value given for --no-copy-optim option"; break; 
      }
      init_val(*argv, theNoCopyOptim, d);
    }
    else if ( IS_LONG_OPT( "--no-tree-ids" ) )
      theNoTreeIds = true;
    else if ( IS_OPT( "--optimizer", "-O" ) ) {
      int d = 2;
      if ((*argv)[1] == '-' || (*argv)[2] == '\0') { d = 0; ++argv; }
      if (!*argv) { result = "No value given for --optimizer option"; break; }
      init_val(*argv, theOptimizer, d);
    }
    else if ( IS_LONG_OPT( "--plan" ) )
      theTestPlanSerialization = true;
    else if ( IS_OPT( "--print-ast", "-a" ) )
      thePrintAst = true;
    else if ( IS_LONG_OPT( "--print-intermediate-opt" ) )
      thePrintIntermediateOpt = true;
    else if ( IS_OPT( "--print-item-flow", "-f" ) )
      thePrintItemFlow = true;
    else if ( IS_OPT( "--print-iterator-tree", "-i" ) )
      thePrintIteratorTree = true;
    else if ( IS_LONG_OPT( "--print-locations" ) )
      thePrintLocations = true;
    else if ( IS_OPT( "--print-normalized", "-n" ) )
      thePrintNormalized = true;
    else if ( IS_OPT( "--print-optimized", "-P" ) )
      thePrintOptimized = true;
    else if ( IS_OPT( "--print-query", "-q" ) )
      thePrintQuery = true;
    else if ( IS_LONG_OPT( "--print-static-types" ) ) {
      int d = 2;
      if ((*argv)[1] == '-' || (*argv)[2] == '\0') { d = 0; ++argv; }
      if (!*argv) { result = "No value given for --print-static-types option"; break; }
      init_val(*argv, thePrintStaticTypes, d);
    }
    else if ( IS_OPT( "--print-time", "-t" ) )
      thePrintTime = true;
    else if ( IS_LONG_OPT( "--print-translated" ) )
      thePrintTranslated = true;
    else if ( IS_LONG_OPT( "--print-xqdoc" ) )
      thePrintXqdoc = true;
    else if ( IS_OPT( "--query", "-e" ) ) {
      int d = 2;
      if ((*argv)[1] == '-' || (*argv)[2] == '\0') { d = 0; ++argv; }
      if (!*argv) { result = "No value given for --query option"; break; }
      init_val(*argv, theQuery, d);
    }
    else if ( IS_LONG_OPT( "--reorder-globals" ) ) {
      int d = 2;
      if ((*argv)[1] == '-' || (*argv)[2] == '\0') { d = 0; ++argv; }
      if (!*argv) { result = "No value given for --reorder-globals option"; break; }
      init_val(*argv, theReorderGlobals, d);
    }
    else if ( IS_OPT( "--result-file", "-o" ) ) {
      int d = 2;
      if ((*argv)[1] == '-' || (*argv)[2] == '\0') { d = 0; ++argv; }
      if (!*argv) { result = "No value given for --result-file option"; break; }
      init_val(*argv, theResultFile, d);
    }
    else if ( IS_LONG_OPT( "--serialize-only-query" ) ) {
      int d = 2;
      if ((*argv)[1] == '-' || (*argv)[2] == '\0') { d = 0; ++argv; }
      if (!*argv)
      { result = "No value given for --serialize-only-query option"; break; }
      init_val(*argv, theSerializeOnlyQuery, d);
    }
    else if ( IS_OPT( "--serializer-param", "-z" ) ) {
      int d = 2;
      if ((*argv)[1] == '-' || (*argv)[2] == '\0') { d = 0; ++argv; }
      if (!*argv) { result = "No value given for --serializer-param option"; break; }
      init_val(*argv, theSerializerParam, d);
    }
    else if ( IS_LONG_OPT( "--specialize-cmp" ) ) {
      int d = 2;
      if ((*argv)[1] == '-' || (*argv)[2] == '\0') { d = 0; ++argv; }
      if (!*argv) { result = "No value given for --specialize-cmp option"; break; }
      init_val(*argv, theSpecializeCmp, d);
    }
    else if ( IS_LONG_OPT( "--specialize-num" ) ) {
      int d = 2;
      if ((*argv)[1] == '-' || (*argv)[2] == '\0') { d = 0; ++argv; }
      if (!*argv) { result = "No value given for --specialize-num option"; break; }
      init_val(*argv, theSpecializeNum, d);
    }
    else if ( IS_LONG_OPT( "--stable-iterator-ids" ) )
      theStableIteratorIds = true;
    else if ( IS_OPT( "--trace-parsing", "-p" ) )
      theTraceParsing = true;
    else if ( IS_OPT( "--trace-scanning", "-s" ) )
      theTraceScanning = true;
#ifndef NDEBUG
    else if ( IS_OPT( "--trace-codegen", "-c" ) )
      theTraceCodegen = true;
    else if ( IS_LONG_OPT( "--trace-fulltext" ) )
      theTraceFulltext = true;
    else if ( IS_OPT( "--trace-translator", "-l" ) )
      theTraceTranslator = true;
#endif
    else if ( IS_LONG_OPT( "--tz" ) ) {
      int d = 2;
      if ((*argv)[1] == '-' || (*argv)[2] == '\0') { d = 0; ++argv; }
      if (!*argv) { result = "No value given for --tz option"; break; }
      init_val(*argv, theTz, d);
    }
    else if ( IS_LONG_OPT( "--use-indexes" ) ) {
      int d = 2;
      if ((*argv)[1] == '-' || (*argv)[2] == '\0') { d = 0; ++argv; }
      if (!*argv) { result = "No value given for --use-indexes option"; break; }
      init_val(*argv, theUseIndexes, d);
    }
    else if ( IS_OPT( "--use-serializer", "-r" ) )
      theUseSerializer = true;

    else if ( IS_LONG_OPT( "--" ) ) {
      copy_args( ++argv );
      break;
    } else if ( (*argv)[0] == '-' ) {
      result = "unknown command line option "; result += *argv;
      break; 
    } else {
      copy_args( argv );
      break;
    }
  } // for
  return result;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
