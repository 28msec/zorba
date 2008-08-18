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

#ifndef ZORBA_ZORBAPROPERTIES
#define ZORBA_ZORBAPROPERTIES
namespace zorba { 
class ZorbaProperties : public ::zorba::PropertiesBase {
protected:
  const char **get_all_options () const {
    static const char *result [] = { "--trace-parsing", "--trace-scanning", "--use-serializer", "--optimizer", "--result-file", "--abort", "--query", "--print-query", "--print-time", "--print-ast", "--print-translated", "--print-normalized", "--print-optimized", "--print-iterator-tree", "--print-item-flow", "--stable-iterator-ids", "--no-tree-ids", "--print-intermediate-opt", "--trace-translator", "--trace-codegen", "--compile-only", "--tz", "--external-vars", NULL };
    return result;
  }
  bool theTraceParsing;
  bool theTraceScanning;
  bool theUseSerializer;
  bool theOptimizer;
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
  bool theCompileOnly;
  int theTz;
  std::vector<std::string>  theExternalVars;

  void initialize () {
    theTraceParsing = false;
    theTraceScanning = false;
    theUseSerializer = false;
    theOptimizer = true;
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
    theCompileOnly = false;
  }
public:
  bool traceParsing () const { return theTraceParsing; }
  bool traceScanning () const { return theTraceScanning; }
  bool useSerializer () const { return theUseSerializer; }
  bool optimizer () const { return theOptimizer; }
  std::string resultFile () const { return theResultFile; }
  bool abort () const { return theAbort; }
  std::string query () const { return theQuery; }
  bool printQuery () const { return thePrintQuery; }
  bool printTime () const { return thePrintTime; }
  bool printAst () const { return thePrintAst; }
  bool printTranslated () const { return thePrintTranslated; }
  bool printNormalized () const { return thePrintNormalized; }
  bool printOptimized () const { return thePrintOptimized; }
  bool printIteratorTree () const { return thePrintIteratorTree; }
  bool printItemFlow () const { return thePrintItemFlow; }
  bool stableIteratorIds () const { return theStableIteratorIds; }
  bool noTreeIds () const { return theNoTreeIds; }
  bool printIntermediateOpt () const { return thePrintIntermediateOpt; }
  bool traceTranslator () const { return theTraceTranslator; }
  bool traceCodegen () const { return theTraceCodegen; }
  bool compileOnly () const { return theCompileOnly; }
  int tz () const { return theTz; }
  std::vector<std::string>  externalVars () const { return theExternalVars; }

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
        init_val (*argv, theOptimizer, d);
      }
      else if (strcmp (*argv, "--result-file") == 0 || strncmp (*argv, "-o", 2) == 0) {
        int d = 2;
        if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
        init_val (*argv, theResultFile, d);
      }
      else if (strcmp (*argv, "--abort") == 0) {
        theAbort = true;
      }
      else if (strcmp (*argv, "--query") == 0 || strncmp (*argv, "-e", 2) == 0) {
        int d = 2;
        if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
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
      else if (strcmp (*argv, "--trace-translator") == 0 || strncmp (*argv, "-l", 2) == 0) {
        theTraceTranslator = true;
      }
      else if (strcmp (*argv, "--trace-codegen") == 0 || strncmp (*argv, "-c", 2) == 0) {
        theTraceCodegen = true;
      }
      else if (strcmp (*argv, "--compile-only") == 0) {
        theCompileOnly = true;
      }
      else if (strcmp (*argv, "--tz") == 0) {
        int d = 2;
        if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
        init_val (*argv, theTz, d);
      }
      else if (strcmp (*argv, "--external-vars") == 0 || strncmp (*argv, "-x", 2) == 0) {
        int d = 2;
        if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
        init_val (*argv, theExternalVars, d);
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

  const char *get_help_msg () {
    return
"--trace-parsing, -p\n  trace parsing\n\n"
"--trace-scanning, -s\n  trace scanning\n\n"
"--use-serializer, -r\n  use serializer\n\n"
"--optimizer, -O\n  optimization level (1=enabled (default), 0=off)\n\n"
"--result-file, -o\n  result file\n\n"
"--abort\n  abort when fatal error happens\n\n"
"--query, -e\n  execute inline query\n\n"
"--print-query, -q\n  print the query query\n\n"
"--print-time, -t\n  print the execution time\n\n"
"--print-ast, -a\n  print the parse tree\n\n"
"--print-translated\n  print the normalized expression tree\n\n"
"--print-normalized, -n\n  print the translated expression tree\n\n"
"--print-optimized\n  print the optimized expression tree\n\n"
"--print-iterator-tree, -i\n  print the iterator tree\n\n"
"--print-item-flow, -f\n  show items produced by all iterators\n\n"
"--stable-iterator-ids\n  print the iterator plan with stable ids\n\n"
"--no-tree-ids\n  suppress ids and locations from compiler tree dumps\n\n"
"--print-intermediate-opt\n  print intermediate optimizations\n\n"
"--trace-translator, -l\n  trace the translator\n\n"
"--trace-codegen, -c\n  trace the codegenerator\n\n"
"--compile-only\n  only compile (don't execute)\n\n"
"--tz\n  implicit time zone (in minutes)\n\n"
"--external-vars, -x\n  external variables (e.g. -x x=file1.xml -x y:=strValue)\n\n"
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
