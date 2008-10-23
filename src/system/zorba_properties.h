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
// THIS IS A GENERATED FILE. DO NOT EDIT!
#include <string>
#include <sstream>
#include <zorba/properties_base.h>
#include <cstring>

#ifndef ZORBA_ZORBAPROPERTIES
#define ZORBA_ZORBAPROPERTIES
namespace zorba { 
class ZorbaProperties : public ::zorba::PropertiesBase {
protected:
  const char **get_all_options () const {
    static const char *result [] = { "--trace-parsing", "--trace-scanning", "--use-serializer", "--optimizer", "--force-gflwor", "--result-file", "--abort", "--query", "--print-query", "--print-time", "--print-ast", "--print-translated", "--print-normalized", "--print-optimized", "--print-iterator-tree", "--print-item-flow", "--stable-iterator-ids", "--no-tree-ids", "--print-intermediate-opt", "--trace-translator", "--trace-codegen", "--debug", "--compile-only", "--tz", "--external-vars", NULL };
    return result;
  }
  bool theTraceParsing;
  bool theTraceScanning;
  bool theUseSerializer;
  bool theOptimizer;
  bool theForceGflwor;
  std::string theResultFile;
  bool theAbort;
  std::string theQuery;
  bool thePrintQuery;
  bool thePrintTime;
  bool thePrintAst;
  bool thePrintTranslated;
  bool thePrintNormalized;
  bool thePrintOptimized;
  bool thePrintIteratorTree;
  bool thePrintItemFlow;
  bool theStableIteratorIds;
  bool theNoTreeIds;
  bool thePrintIntermediateOpt;
  bool theTraceTranslator;
  bool theTraceCodegen;
  bool theDebug;
  bool theCompileOnly;
  int theTz;
  std::vector<std::string> theExternalVars;
  std::vector<std::string> theSerializerParams;

  void initialize () {
    theTraceParsing = false;
    theTraceScanning = false;
    theUseSerializer = false;
    theOptimizer = true;
    theForceGflwor = false;
    theAbort = false;
    thePrintQuery = false;
    thePrintTime = false;
    thePrintAst = false;
    thePrintTranslated = false;
    thePrintNormalized = false;
    thePrintOptimized = false;
    thePrintIteratorTree = false;
    thePrintItemFlow = false;
    theStableIteratorIds = false;
    theNoTreeIds = false;
    thePrintIntermediateOpt = false;
    theTraceTranslator = false;
    theTraceCodegen = false;
    theDebug = false;
    theCompileOnly = false;
  }
public:
  const bool &traceParsing () const { return theTraceParsing; }
  const bool &traceScanning () const { return theTraceScanning; }
  const bool &useSerializer () const { return theUseSerializer; }
  const bool &optimizer () const { return theOptimizer; }
  const bool &forceGflwor () const { return theForceGflwor; }
  const std::string &resultFile () const { return theResultFile; }
  const bool &abort () const { return theAbort; }
  const std::string &query () const { return theQuery; }
  const bool &printQuery () const { return thePrintQuery; }
  const bool &printTime () const { return thePrintTime; }
  const bool &printAst () const { return thePrintAst; }
  const bool &printTranslated () const { return thePrintTranslated; }
  const bool &printNormalized () const { return thePrintNormalized; }
  const bool &printOptimized () const { return thePrintOptimized; }
  const bool &printIteratorTree () const { return thePrintIteratorTree; }
  const bool &printItemFlow () const { return thePrintItemFlow; }
  const bool &stableIteratorIds () const { return theStableIteratorIds; }
  const bool &noTreeIds () const { return theNoTreeIds; }
  const bool &printIntermediateOpt () const { return thePrintIntermediateOpt; }
  const bool &traceTranslator () const { return theTraceTranslator; }
  const bool &traceCodegen () const { return theTraceCodegen; }
  const bool &debug () const { return theDebug; }
  const bool &compileOnly () const { return theCompileOnly; }
  const int &tz () const { return theTz; }
  const std::vector<std::string> &externalVars () const { return theExternalVars; }

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
        if (*argv != NULL)
          init_val (*argv, theOptimizer, d);
      }
      else if (strcmp (*argv, "--force-gflwor") == 0) {
        theForceGflwor = true;
      }
      else if (strcmp (*argv, "--result-file") == 0 || strncmp (*argv, "-o", 2) == 0) {
        int d = 2;
        if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
        if (*argv != NULL)
          init_val (*argv, theResultFile, d);
      }
      else if (strcmp (*argv, "--abort") == 0) {
        theAbort = true;
      }
      else if (strcmp (*argv, "--query") == 0 || strncmp (*argv, "-e", 2) == 0) {
        int d = 2;
        if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
        if (*argv != NULL)
          init_val (*argv, theQuery, d);
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
      else if (strcmp (*argv, "--print-translated") == 0) {
        thePrintTranslated = true;
      }
      else if (strcmp (*argv, "--print-normalized") == 0 || strncmp (*argv, "-n", 2) == 0) {
        thePrintNormalized = true;
      }
      else if (strcmp (*argv, "--print-optimized") == 0) {
        thePrintOptimized = true;
      }
      else if (strcmp (*argv, "--print-iterator-tree") == 0 || strncmp (*argv, "-i", 2) == 0) {
        thePrintIteratorTree = true;
      }
      else if (strcmp (*argv, "--print-item-flow") == 0 || strncmp (*argv, "-f", 2) == 0) {
        thePrintItemFlow = true;
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
#ifndef NDEBUG
      else if (strcmp (*argv, "--trace-translator") == 0 || strncmp (*argv, "-l", 2) == 0) {
        theTraceTranslator = true;
      }
      else if (strcmp (*argv, "--trace-codegen") == 0 || strncmp (*argv, "-c", 2) == 0) {
        theTraceCodegen = true;
      }
#endif
#ifdef ZORBA_DEBUGGER
      else if (strcmp (*argv, "--debug") == 0) {
        theDebug = true;
      }
#endif
      else if (strcmp (*argv, "--compile-only") == 0) {
        theCompileOnly = true;
      }
      else if (strcmp (*argv, "--tz") == 0) {
        int d = 2;
        if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
        if (*argv != NULL)
          init_val (*argv, theTz, d);
      }
      else if (strcmp (*argv, "--external-vars") == 0 || strncmp (*argv, "-x", 2) == 0) {
        int d = 2;
        if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
        if (*argv != NULL)
          init_val (*argv, theExternalVars, d);
      }
      else if (strcmp (*argv, "--serializer-parameter") == 0 || strncmp (*argv, "-z", 2) == 0) {        
        int d = 2;
        if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
        if (*argv != NULL)
          init_val (*argv, theSerializerParams, d);
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

      if (*argv == NULL)
        break;
    }

    return result;
  }

  const char *get_help_msg () {
    return
"--trace-parsing, -p\ntrace parsing\n\n"
"--trace-scanning, -s\ntrace scanning\n\n"
"--use-serializer, -r\nuse serializer\n\n"
"--optimizer, -O\noptimization level (1=enabled (default), 0=off)\n\n"
"--force-gflwor\nforce compiler to generate GFLWOR iterators\n\n"
"--result-file, -o\nresult file\n\n"
"--abort\nabort when fatal error happens\n\n"
"--query, -e\nexecute inline query\n\n"
"--print-query, -q\nprint the query query\n\n"
"--print-time, -t\nprint the execution time\n\n"
"--print-ast, -a\nprint the parse tree\n\n"
"--print-translated\nprint the normalized expression tree\n\n"
"--print-normalized, -n\nprint the translated expression tree\n\n"
"--print-optimized\nprint the optimized expression tree\n\n"
"--print-iterator-tree, -i\nprint the iterator tree\n\n"
"--print-item-flow, -f\nshow items produced by all iterators\n\n"
"--stable-iterator-ids\nprint the iterator plan with stable ids\n\n"
"--no-tree-ids\nsuppress ids and locations from compiler tree dumps\n\n"
"--print-intermediate-opt\nprint intermediate optimizations\n\n"
#ifndef NDEBUG
"--trace-translator, -l\ntrace the translator\n\n"
"--trace-codegen, -c\ntrace the codegenerator\n\n"
#endif
#ifdef ZORBA_DEBUGGER
"--debug\ncompile the query in debug mode\n\n"
#endif
"--compile-only\nonly compile (don't execute)\n\n"
"--tz\nimplicit time zone (in minutes)\n\n"
"--serializer-parameter, -z\nset serialization parameters (e.g. -z indent=yes)\n\n"
"--external-vars, -x\nexternal variables (e.g. -x x=file1.xml -x y:=strValue)\n\n"
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
