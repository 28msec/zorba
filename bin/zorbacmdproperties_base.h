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

#include <string>
#include <sstream>
#include <zorba/config.h>
#include <zorba/properties_base.h>
#include <cstring>

#ifndef ZORBACMD_ZORBACMDPROPERTIESBASE
#define ZORBACMD_ZORBACMDPROPERTIESBASE
namespace zorbacmd {

///////////////////////////////////////////////////////////////////////////////

class ZorbaCMDPropertiesBase : public ::zorba::PropertiesBase {
protected:
  bool theTiming;
#ifdef ZORBA_WITH_FILE_ACCESS
  std::string theOutputFile;
#endif /* ZORBA_WITH_FILE_ACCESS */
  std::vector<std::string> theSerializationParameter;
  bool theSerializeHtml;
  bool theSerializeText;
  bool theIndent;
  bool thePrintQuery;
  bool thePrintErrorsAsXml;
  bool theByteOrderMark;
  bool theOmitXmlDeclaration;
  std::string theBaseUri;
  std::string theBoundarySpace;
  std::string theDefaultCollation;
  std::string theConstructionMode;
  std::string theOrderingMode;
  unsigned long theMultiple;
  std::vector<std::string> theQueriesOrFiles;
  bool theAsFiles;
  std::vector<std::string> theExternalVariable;
  std::string theContextItem;
  std::string theOptimizationLevel;
  bool theLibModule;
  bool theParseOnly;
  bool theCompileOnly;
  bool theNoSerializer;
  bool theDebug;
  std::string theDebugHost;
  unsigned int theDebugPort;
  bool theNoLogo;
  long theTimeout;
  std::string theUriPath;
  std::string theLibPath;
  std::string theModulePath;
  std::string theClasspath;
  std::vector<std::string> theOption;
  bool theTrailingNl;
  std::vector<std::string> theStopWords;
  std::vector<std::string> theThesaurus;
  bool theSerializePlan;
  bool theSavePlan;
  bool theLoadPlan;
  bool theFparm;
  bool theQBeforeF;
  bool theUnknownOption;

  // inherited
  const char** get_all_options() const;

public:
  ZorbaCMDPropertiesBase();

  bool timing () const { return theTiming; }
#ifdef ZORBA_WITH_FILE_ACCESS
  const std::string &outputFile () const { return theOutputFile; }
#endif /* ZORBA_WITH_FILE_ACCESS */
  const std::vector<std::string> &serializationParameter () const { return theSerializationParameter; }
  bool serializeHtml () const { return theSerializeHtml; }
  bool serializeText () const { return theSerializeText; }
  bool indent () const { return theIndent; }
  bool printQuery () const { return thePrintQuery; }
  bool printErrorsAsXml () const { return thePrintErrorsAsXml; }
  bool byteOrderMark () const { return theByteOrderMark; }
  bool omitXmlDeclaration () const { return theOmitXmlDeclaration; }
  const std::string &baseUri () const { return theBaseUri; }
  const std::string &boundarySpace () const { return theBoundarySpace; }
  const std::string &defaultCollation () const { return theDefaultCollation; }
  const std::string &constructionMode () const { return theConstructionMode; }
  const std::string &orderingMode () const { return theOrderingMode; }
  unsigned long multiple () const { return theMultiple; }
  const std::vector<std::string> &query () const { return theQueriesOrFiles; }
  bool asFiles () const { return theAsFiles; }
  const std::vector<std::string> &externalVariable () const { return theExternalVariable; }
  const std::string &contextItem () const { return theContextItem; }
  const std::string &optimizationLevel () const { return theOptimizationLevel; }
  bool libModule () const { return theLibModule; }
  bool parseOnly () const { return theParseOnly; }
  bool compileOnly () const { return theCompileOnly; }
  bool noSerializer () const { return theNoSerializer; }
  bool debug () const { return theDebug; }
  const std::string &debugHost () const { return theDebugHost; }
  unsigned debugPort () const { return theDebugPort; }
  bool noLogo () const { return theNoLogo; }
  const long &timeout () const { return theTimeout; }
  const std::string &uriPath () const { return theUriPath; }
  const std::string &libPath () const { return theLibPath; }
  const std::string &modulePath () const { return theModulePath; }
  const std::string &classpath () const { return theClasspath; }
  const std::vector<std::string> &option () const { return theOption; }
  bool trailingNl () const { return theTrailingNl; }
  const std::vector<std::string> &stopWords () const { return theStopWords; }
  const std::vector<std::string> &thesaurus () const { return theThesaurus; }
  bool serializePlan () const { return theSerializePlan; }
  bool loadPlan () const { return theLoadPlan; }
  bool savePlan () const { return theSavePlan; }
  bool qBeforeF () const { return theQBeforeF; }
  bool unknownOption() const { return theUnknownOption; }

  std::string load_argv(int argc, const char **argv);

  const char* get_help_msg() const;

  static const ZorbaCMDPropertiesBase* instance();
};

///////////////////////////////////////////////////////////////////////////////

} // namespace zorbacmd

#endif /* ZORBACMD_ZORBACMDPROPERTIESBASE */
/* vim:set et sw=2 ts=2: */
