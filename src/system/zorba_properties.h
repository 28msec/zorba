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
/* vim:set et sw=2 ts=2: */

// ******************************************
// *                                        *
// * THIS IS A GENERATED FILE. DO NOT EDIT! *
// * SEE .txt FILE WITH SAME NAME           *
// *                                        *
// ******************************************

#include <string>
#include <sstream>
#include <zorba/config.h>
#include <zorba/properties_base.h>
#include <cstring>

#ifndef ZORBA_ZORBAPROPERTIES
#define ZORBA_ZORBAPROPERTIES
namespace zorba { 
class ZORBA_DLL_PUBLIC ZorbaProperties : public ::zorba::PropertiesBase {
protected:
  const char **get_all_options () const {
    static const char *result [] = { "--trace-parsing", "--trace-scanning", "--use-serializer", "--optimizer", "--result-file", "--debug-file", "--abort", "--query", "--print-query", "--print-time", "--print-ast", "--print-xqdoc", "--print-translated", "--print-normalized", "--print-optimized", "--print-iterator-tree", "--print-item-flow", "--print-static-types", "--dump-lib", "--stable-iterator-ids", "--no-tree-ids", "--print-intermediate-opt", "--print-locations", "--force-gflwor", "--reorder-globals", "--specialize-num", "--specialize-cmp", "--inline-udf", "--loop-hoisting", "--infer-joins", "--trace-translator", "--trace-codegen", "--trace-fulltext", "--debug", "--compile-only", "--tz", "--external-var", "--serializer-param", "--iter-plan-test", "--dot-plan-file", "--max-udf-call-depth", NULL };
    return result;
  }
  bool theTraceParsing;
  bool theTraceScanning;
  bool theUseSerializer;
  int theOptimizer;
  std::string theResultFile;
  std::string theDebugFile;
  bool theAbort;
  std::string theQuery;
  bool thePrintQuery;
  bool thePrintTime;
  bool thePrintAst;
  bool thePrintXqdoc;
  bool thePrintTranslated;
  bool thePrintNormalized;
  bool thePrintOptimized;
  bool thePrintIteratorTree;
  bool thePrintItemFlow;
  bool thePrintStaticTypes;
  bool theDumpLib;
  bool theStableIteratorIds;
  bool theNoTreeIds;
  bool thePrintIntermediateOpt;
  bool thePrintLocations;
  bool theForceGflwor;
  bool theReorderGlobals;
  bool theSpecializeNum;
  bool theSpecializeCmp;
  bool theInlineUdf;
  bool theLoopHoisting;
  bool theInferJoins;
  bool theTraceTranslator;
  bool theTraceCodegen;
  bool theTraceFulltext;
  bool theDebug;
  bool theCompileOnly;
  int theTz;
  std::vector<std::string> theExternalVar;
  std::vector<std::string> theSerializerParam;
  bool theIterPlanTest;
  std::string theDotPlanFile;
  uint32_t theMaxUdfCallDepth;

  void initialize () {
    theTraceParsing = false;
    theTraceScanning = false;
    theUseSerializer = false;
    theOptimizer = 1;
    theAbort = false;
    thePrintQuery = false;
    thePrintTime = false;
    thePrintAst = false;
    thePrintXqdoc = false;
    thePrintTranslated = false;
    thePrintNormalized = false;
    thePrintOptimized = false;
    thePrintIteratorTree = false;
    thePrintItemFlow = false;
    thePrintStaticTypes = true;
    theDumpLib = false;
    theStableIteratorIds = false;
    theNoTreeIds = false;
    thePrintIntermediateOpt = false;
    thePrintLocations = false;
    theForceGflwor = false;
    theReorderGlobals = true;
    theSpecializeNum = true;
    theSpecializeCmp = true;
    theInlineUdf = true;
    theLoopHoisting = true;
    theInferJoins = true;
    theTraceTranslator = false;
    theTraceCodegen = false;
    theTraceFulltext = false;
    theDebug = false;
    theCompileOnly = false;
    theIterPlanTest = false;
    theMaxUdfCallDepth = 1024;
  }
public:
  const bool &traceParsing () const { return theTraceParsing; }
  const bool &traceScanning () const { return theTraceScanning; }
  const bool &useSerializer () const { return theUseSerializer; }
  const int &optimizer () const { return theOptimizer; }
  const std::string &resultFile () const { return theResultFile; }
  const std::string &debugFile () const { return theDebugFile; }
  const bool &abort () const { return theAbort; }
  const std::string &query () const { return theQuery; }
  const bool &printQuery () const { return thePrintQuery; }
  const bool &printTime () const { return thePrintTime; }
  const bool &printAst () const { return thePrintAst; }
  const bool &printXqdoc () const { return thePrintXqdoc; }
  const bool &printTranslated () const { return thePrintTranslated; }
  const bool &printNormalized () const { return thePrintNormalized; }
  const bool &printOptimized () const { return thePrintOptimized; }
  const bool &printIteratorTree () const { return thePrintIteratorTree; }
  const bool &printItemFlow () const { return thePrintItemFlow; }
  const bool &printStaticTypes () const { return thePrintStaticTypes; }
  const bool &dumpLib () const { return theDumpLib; }
  const bool &stableIteratorIds () const { return theStableIteratorIds; }
  const bool &noTreeIds () const { return theNoTreeIds; }
  const bool &printIntermediateOpt () const { return thePrintIntermediateOpt; }
  const bool &printLocations () const { return thePrintLocations; }
  const bool &forceGflwor () const { return theForceGflwor; }
  const bool &reorderGlobals () const { return theReorderGlobals; }
  const bool &specializeNum () const { return theSpecializeNum; }
  const bool &specializeCmp () const { return theSpecializeCmp; }
  const bool &inlineUdf () const { return theInlineUdf; }
  const bool &loopHoisting () const { return theLoopHoisting; }
  const bool &inferJoins () const { return theInferJoins; }
  const bool &traceTranslator () const { return theTraceTranslator; }
  const bool &traceCodegen () const { return theTraceCodegen; }
  const bool &traceFulltext () const { return theTraceFulltext; }
  const bool &debug () const { return theDebug; }
  const bool &compileOnly () const { return theCompileOnly; }
  const int &tz () const { return theTz; }
  const std::vector<std::string> &externalVar () const { return theExternalVar; }
  const std::vector<std::string> &serializerParam () const { return theSerializerParam; }
  const bool &iterPlanTest () const { return theIterPlanTest; }
  const std::string &dotPlanFile () const { return theDotPlanFile; }
  const uint32_t &maxUdfCallDepth () const { return theMaxUdfCallDepth; }

  std::string load_argv (int argc, const char **argv) {
    if (argv == NULL) return "";

    std::string result;
    for (++argv; *argv != NULL; ++argv) {
      if (strcmp (*argv, "--help") == 0 || strcmp (*argv, "-h") == 0)
        return "!HELP";
      else if (strcmp (*argv, "--version") == 0)
        return "!VER";
      else if (strcmp (*argv, "--trace-parsing") == 0 || strncmp (*argv, "-p", 2) == 0) {
        theTraceParsing = true;
      }
      else if (strcmp (*argv, "--trace-scanning") == 0 || strncmp (*argv, "-s", 2) == 0) {
        theTraceScanning = true;
      }
      else if (strcmp (*argv, "--use-serializer") == 0 || strncmp (*argv, "-r", 2) == 0) {
        theUseSerializer = true;
      }
      else if (strcmp (*argv, "--optimizer") == 0 || strncmp (*argv, "-O", 2) == 0) {
        int d = 2;
        if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
        if (*argv == NULL) { result = "No value given for --optimizer option"; break; }        init_val (*argv, theOptimizer, d);
      }
      else if (strcmp (*argv, "--result-file") == 0 || strncmp (*argv, "-o", 2) == 0) {
        int d = 2;
        if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
        if (*argv == NULL) { result = "No value given for --result-file option"; break; }        init_val (*argv, theResultFile, d);
      }
      else if (strcmp (*argv, "--debug-file") == 0) {
        int d = 2;
        if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
        if (*argv == NULL) { result = "No value given for --debug-file option"; break; }        init_val (*argv, theDebugFile, d);
      }
      else if (strcmp (*argv, "--abort") == 0) {
        theAbort = true;
      }
      else if (strcmp (*argv, "--query") == 0 || strncmp (*argv, "-e", 2) == 0) {
        int d = 2;
        if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
        if (*argv == NULL) { result = "No value given for --query option"; break; }        init_val (*argv, theQuery, d);
      }
      else if (strcmp (*argv, "--print-query") == 0 || strncmp (*argv, "-q", 2) == 0) {
        thePrintQuery = true;
      }
      else if (strcmp (*argv, "--print-time") == 0 || strncmp (*argv, "-t", 2) == 0) {
        thePrintTime = true;
      }
      else if (strcmp (*argv, "--print-ast") == 0 || strncmp (*argv, "-a", 2) == 0) {
        thePrintAst = true;
      }
      else if (strcmp (*argv, "--print-xqdoc") == 0) {
        thePrintXqdoc = true;
      }
      else if (strcmp (*argv, "--print-translated") == 0) {
        thePrintTranslated = true;
      }
      else if (strcmp (*argv, "--print-normalized") == 0 || strncmp (*argv, "-n", 2) == 0) {
        thePrintNormalized = true;
      }
      else if (strcmp (*argv, "--print-optimized") == 0 || strncmp (*argv, "-P", 2) == 0) {
        thePrintOptimized = true;
      }
      else if (strcmp (*argv, "--print-iterator-tree") == 0 || strncmp (*argv, "-i", 2) == 0) {
        thePrintIteratorTree = true;
      }
      else if (strcmp (*argv, "--print-item-flow") == 0 || strncmp (*argv, "-f", 2) == 0) {
        thePrintItemFlow = true;
      }
      else if (strcmp (*argv, "--print-static-types") == 0) {
        int d = 2;
        if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
        if (*argv == NULL) { result = "No value given for --print-static-types option"; break; }        init_val (*argv, thePrintStaticTypes, d);
      }
      else if (strcmp (*argv, "--dump-lib") == 0) {
        theDumpLib = true;
      }
      else if (strcmp (*argv, "--stable-iterator-ids") == 0) {
        theStableIteratorIds = true;
      }
      else if (strcmp (*argv, "--no-tree-ids") == 0) {
        theNoTreeIds = true;
      }
      else if (strcmp (*argv, "--print-intermediate-opt") == 0) {
        thePrintIntermediateOpt = true;
      }
      else if (strcmp (*argv, "--print-locations") == 0) {
        thePrintLocations = true;
      }
      else if (strcmp (*argv, "--force-gflwor") == 0) {
        theForceGflwor = true;
      }
      else if (strcmp (*argv, "--reorder-globals") == 0) {
        int d = 2;
        if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
        if (*argv == NULL) { result = "No value given for --reorder-globals option"; break; }        init_val (*argv, theReorderGlobals, d);
      }
      else if (strcmp (*argv, "--specialize-num") == 0) {
        int d = 2;
        if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
        if (*argv == NULL) { result = "No value given for --specialize-num option"; break; }        init_val (*argv, theSpecializeNum, d);
      }
      else if (strcmp (*argv, "--specialize-cmp") == 0) {
        int d = 2;
        if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
        if (*argv == NULL) { result = "No value given for --specialize-cmp option"; break; }        init_val (*argv, theSpecializeCmp, d);
      }
      else if (strcmp (*argv, "--inline-udf") == 0) {
        int d = 2;
        if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
        if (*argv == NULL) { result = "No value given for --inline-udf option"; break; }        init_val (*argv, theInlineUdf, d);
      }
      else if (strcmp (*argv, "--loop-hoisting") == 0) {
        int d = 2;
        if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
        if (*argv == NULL) { result = "No value given for --loop-hoisting option"; break; }        init_val (*argv, theLoopHoisting, d);
      }
      else if (strcmp (*argv, "--infer-joins") == 0) {
        int d = 2;
        if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
        if (*argv == NULL) { result = "No value given for --infer-joins option"; break; }        init_val (*argv, theInferJoins, d);
      }
#ifndef NDEBUG
      else if (strcmp (*argv, "--trace-translator") == 0 || strncmp (*argv, "-l", 2) == 0) {
        theTraceTranslator = true;
      }
      else if (strcmp (*argv, "--trace-codegen") == 0 || strncmp (*argv, "-c", 2) == 0) {
        theTraceCodegen = true;
      }
      else if (strcmp (*argv, "--trace-fulltext") == 0) {
        theTraceFulltext = true;
      }
#endif
      else if (strcmp (*argv, "--debug") == 0) {
        theDebug = true;
      }
      else if (strcmp (*argv, "--compile-only") == 0) {
        theCompileOnly = true;
      }
      else if (strcmp (*argv, "--tz") == 0) {
        int d = 2;
        if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
        if (*argv == NULL) { result = "No value given for --tz option"; break; }        init_val (*argv, theTz, d);
      }
      else if (strcmp (*argv, "--external-var") == 0 || strncmp (*argv, "-x", 2) == 0) {
        int d = 2;
        if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
        if (*argv == NULL) { result = "No value given for --external-var option"; break; }        init_val (*argv, theExternalVar, d);
      }
      else if (strcmp (*argv, "--serializer-param") == 0 || strncmp (*argv, "-z", 2) == 0) {
        int d = 2;
        if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
        if (*argv == NULL) { result = "No value given for --serializer-param option"; break; }        init_val (*argv, theSerializerParam, d);
      }
      else if (strcmp (*argv, "--iter-plan-test") == 0) {
        theIterPlanTest = true;
      }
      else if (strcmp (*argv, "--dot-plan-file") == 0) {
        int d = 2;
        if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
        if (*argv == NULL) { result = "No value given for --dot-plan-file option"; break; }        init_val (*argv, theDotPlanFile, d);
      }
      else if (strcmp (*argv, "--max-udf-call-depth") == 0) {
        int d = 2;
        if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
        if (*argv == NULL) { result = "No value given for --max-udf-call-depth option"; break; }        init_val (*argv, theMaxUdfCallDepth, d);
      }
      else if (strcmp (*argv, "--") == 0) {
        copy_args (++argv);
        break;
      } else if ((*argv) [0] == '-') {
        result = "unknown command line option "; result += *argv; break; 
      } else {
        copy_args (argv);
        break;
      }
    }

    return result;
  }

  const char *get_help_msg () const {
    return
"--trace-parsing, -p\ntrace parsing\n\n"
"--trace-scanning, -s\ntrace scanning\n\n"
"--use-serializer, -r\nuse serializer\n\n"
"--optimizer, -O\noptimization level (0, 1 or 2 - 1 is default)\n\n"
"--result-file, -o\nresult file\n\n"
"--debug-file\nlog file for debugging information\n\n"
"--abort\nabort when fatal error happens\n\n"
"--query, -e\nexecute inline query\n\n"
"--print-query, -q\nprint the query\n\n"
"--print-time, -t\nprint the execution time\n\n"
"--print-ast, -a\nprint the parse tree\n\n"
"--print-xqdoc\ncreate output for XQDoc\n\n"
"--print-translated\nprint the normalized expression tree\n\n"
"--print-normalized, -n\nprint the translated expression tree\n\n"
"--print-optimized, -P\nprint the optimized expression tree\n\n"
"--print-iterator-tree, -i\nprint the iterator tree\n\n"
"--print-item-flow, -f\nshow items produced by all iterators\n\n"
"--print-static-types\nprint static type inference\n\n"
"--dump-lib\ndump function library\n\n"
"--stable-iterator-ids\nprint the iterator plan with stable ids\n\n"
"--no-tree-ids\nsuppress ids and locations from compiler tree dumps\n\n"
"--print-intermediate-opt\nprint intermediate optimizations\n\n"
"--print-locations\nprint parser locations for compiler expressions\n\n"
"--force-gflwor\nforce compiler to generate GFLWOR iterators\n\n"
"--reorder-globals\nreorder global variables (1=enabled (default), 0=off)\n\n"
"--specialize-num\nspecialize numerics (1=enabled (default), 0=off)\n\n"
"--specialize-cmp\nspecialize generic comparisons (1=enabled (default), 0=off)\n\n"
"--inline-udf\ninline functions (1=enabled (default), 0=off)\n\n"
"--loop-hoisting\nhoist expressions out of loops (1=enabled (default), 0=off)\n\n"
"--infer-joins\ninfer joins (1=enabled (default), 0=off)\n\n"
#ifndef NDEBUG
"--trace-translator, -l\ntrace the translator\n\n"
"--trace-codegen, -c\ntrace the codegenerator\n\n"
"--trace-fulltext\ntrace full-text evaluation\n\n"
#endif
"--debug\ncompile the query in debug mode\n\n"
"--compile-only\nonly compile (don't execute)\n\n"
"--tz\nimplicit time zone (in minutes)\n\n"
"--external-var, -x\nexternal variables (e.g. -x x=file1.xml -x y:=strValue)\n\n"
"--serializer-param, -z\nserializer parameters (see http://www.w3.org/TR/xslt-xquery-serialization/#serparam, e.g. -z method=xhtml, -z doctype-system='DTD/xhtml1-strict.dtd', -z indent=yes)\n\n"
"--iter-plan-test\nrun as iterator plan test\n\n"
"--dot-plan-file\ngenerate the dot iterator plan\n\n"
"--max-udf-call-depth\nmaximum stack depth of udf function calls\n\n"
;
  }

  static const ZorbaProperties *instance () {
    static ZorbaProperties result;
    return &result;
  }

  ZorbaProperties () { initialize (); }
  
};

}   // namespaces

#endif // ZORBA_ZORBAPROPERTIES
