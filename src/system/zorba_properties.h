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

#ifndef ZORBA_ZORBAPROPERTIES
#define ZORBA_ZORBAPROPERTIES

// standard
#include <string>

// Zorba
#include <zorba/config.h>
#include <zorba/properties_base.h>

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

class ZORBA_DLL_PUBLIC ZorbaProperties : public ::zorba::PropertiesGlobal {
public:
  bool abort() const { return theAbort; }
  const std::string& CLASSPATH() const { return theCLASSPATH; }
  bool compileOnly() const { return theCompileOnly; }
  bool debug() const { return theDebug; }
  const std::string& debugFile() const { return theDebugFile; }
  const std::string& dotPlanFile() const { return theDotPlanFile; }
  bool dumpLib() const { return theDumpLib; }
  const std::vector<std::string>& externalVar() const { return theExternalVar; }
  bool forceGflwor() const { return theForceGflwor; }
  bool inferJoins() const { return theInferJoins; }
  bool inlineUdf() const { return theInlineUdf; }
  bool iterPlanTest() const { return theIterPlanTest; }
  bool jsoniqParser() const { return theJsoniqParser; }
  bool libModule() const { return theLibModule; }
  bool loopHoisting() const { return theLoopHoisting; }
  uint32_t maxUdfCallDepth() const { return theMaxUdfCallDepth; }
  bool noCopyOptim() const { return theNoCopyOptim; }
  bool noTreeIds() const { return theNoTreeIds; }
  int optimizer() const { return theOptimizer; }
  bool printAst() const { return thePrintAst; }
  bool printIntermediateOpt() const { return thePrintIntermediateOpt; }
  bool printItemFlow() const { return thePrintItemFlow; }
  bool printIteratorTree() const { return thePrintIteratorTree; }
  bool printLocations() const { return thePrintLocations; }
  bool printNormalized() const { return thePrintNormalized; }
  bool printOptimized() const { return thePrintOptimized; }
  bool printQuery() const { return thePrintQuery; }
  bool printStaticTypes() const { return thePrintStaticTypes; }
  bool printTime() const { return thePrintTime; }
  bool printTranslated() const { return thePrintTranslated; }
  bool printXqdoc() const { return thePrintXqdoc; }
  const std::string& query() const { return theQuery; }
  bool reorderGlobals() const { return theReorderGlobals; }
  const std::string& resultFile() const { return theResultFile; }
  int serializeOnlyQuery() const { return theSerializeOnlyQuery; }
  const std::vector<std::string>& serializerParam() const { return theSerializerParam; }
  bool specializeCmp() const { return theSpecializeCmp; }
  bool specializeNum() const { return theSpecializeNum; }
  bool stableIteratorIds() const { return theStableIteratorIds; }
  bool testPlanSerialization() const { return theTestPlanSerialization; }
  bool traceCodegen() const { return theTraceCodegen; }
  bool traceFulltext() const { return theTraceFulltext; }
  bool traceParsing() const { return theTraceParsing; }
  bool traceScanning() const { return theTraceScanning; }
  bool traceTranslator() const { return theTraceTranslator; }
  int tz() const { return theTz; }
  bool useIndexes() const { return theUseIndexes; }
  bool useSerializer() const { return theUseSerializer; }

  char const* get_help_msg() const;
  static const ZorbaProperties* instance();
  std::string load_argv( int argc, char const **argv );

protected:
  ZorbaProperties();

  const char** get_all_options() const;

  bool theAbort;
  std::string theCLASSPATH;
  bool theCompileOnly;
  bool theDebug;
  std::string theDebugFile;
  std::string theDotPlanFile;
  bool theDumpLib;
  std::vector<std::string> theExternalVar;
  bool theForceGflwor;
  bool theInferJoins;
  bool theInlineUdf;
  bool theIterPlanTest;
  bool theJsoniqParser;
  bool theLibModule;
  bool theLoopHoisting;
  uint32_t theMaxUdfCallDepth;
  bool theNoCopyOptim;
  bool theNoTreeIds;
  int theOptimizer;
  bool thePrintAst;
  bool thePrintIntermediateOpt;
  bool thePrintItemFlow;
  bool thePrintIteratorTree;
  bool thePrintLocations;
  bool thePrintNormalized;
  bool thePrintOptimized;
  bool thePrintQuery;
  bool thePrintStaticTypes;
  bool thePrintTime;
  bool thePrintTranslated;
  bool thePrintXqdoc;
  std::string theQuery;
  std::string theResultFile;
  bool theReorderGlobals;
  int theSerializeOnlyQuery;
  std::vector<std::string> theSerializerParam;
  bool theSpecializeCmp;
  bool theSpecializeNum;
  bool theStableIteratorIds;
  bool theTestPlanSerialization;
  bool theTraceCodegen;
  bool theTraceFulltext;
  bool theTraceParsing;
  bool theTraceScanning;
  bool theTraceTranslator;
  int theTz;
  bool theUseIndexes;
  bool theUseSerializer;
};

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif /* ZORBA_ZORBAPROPERTIES */
/* vim:set et sw=2 ts=2: */
