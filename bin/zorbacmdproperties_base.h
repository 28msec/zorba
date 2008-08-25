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

#ifndef ZORBACMD_ZORBACMDPROPERTIESBASE
#define ZORBACMD_ZORBACMDPROPERTIESBASE
namespace zorbacmd { 
class ZorbaCMDPropertiesBase : public ::zorba::PropertiesBase {
protected:
  const char **get_all_options () const {
    static const char *result [] = { "--timing", "--output-file", "--serialize-html", "--serialize-text", "--indent", "--print-query", "--byte-order-mark", "--omit-xml-declaration", "--base-uri", "--boundary-space", "--default-collation", "--construction-mode", "--ordering-mode", "--multiple", "--query", "--as-files", "--external-variable", "--context-item", "--optimization-level", "--debug-ports", "--debug-client", "--debug-server", NULL };
    return result;
  }
  bool theTiming;
  std::string theOutputFile;
  bool theSerializeHtml;
  bool theSerializeText;
  bool theIndent;
  bool thePrintQuery;
  bool theByteOrderMark;
  bool theOmitXmlDeclaration;
  std::string theBaseUri;
  std::string theBoundarySpace;
  std::string theDefaultCollation;
  std::string theConstructionMode;
  std::string theOrderingMode;
  int theMultiple;
  std::vector<std::string> theQueriesOrFiles;
  bool theAsFiles;
  std::vector<std::string> theExternalVariable;
  std::string theContextItem;
  std::string theOptimizationLevel;
  std::string theDebugPorts;
  bool theDebugClient;
  bool theDebugServer;

  void initialize () {
    theTiming = false;
    theSerializeHtml = false;
    theSerializeText = false;
    theIndent = false;
    thePrintQuery = false;
    theByteOrderMark = false;
    theOmitXmlDeclaration = false;
    theMultiple = 1;
    theAsFiles = false;
    theOptimizationLevel = "O1";
    theDebugPorts = "8000:9000";
    theDebugClient = false;
    theDebugServer = false;
  }
public:
  const bool &timing () const { return theTiming; }
  const std::string &outputFile () const { return theOutputFile; }
  const bool &serializeHtml () const { return theSerializeHtml; }
  const bool &serializeText () const { return theSerializeText; }
  const bool &indent () const { return theIndent; }
  const bool &printQuery () const { return thePrintQuery; }
  const bool &byteOrderMark () const { return theByteOrderMark; }
  const bool &omitXmlDeclaration () const { return theOmitXmlDeclaration; }
  const std::string &baseUri () const { return theBaseUri; }
  const std::string &boundarySpace () const { return theBoundarySpace; }
  const std::string &defaultCollation () const { return theDefaultCollation; }
  const std::string &constructionMode () const { return theConstructionMode; }
  const std::string &orderingMode () const { return theOrderingMode; }
  const int &multiple () const { return theMultiple; }
  const std::vector<std::string> &query () const { return theQueriesOrFiles; }
  const bool &asFiles () const { return theAsFiles; }
  const std::vector<std::string> &externalVariable () const { return theExternalVariable; }
  const std::string &contextItem () const { return theContextItem; }
  const std::string &optimizationLevel () const { return theOptimizationLevel; }
  const std::string &debugPorts () const { return theDebugPorts; }
  const bool &debugClient () const { return theDebugClient; }
  const bool &debugServer () const { return theDebugServer; }

  std::string load_argv (int argc, const char **argv) {
    if (argv == NULL) return "";

    std::string result;
    for (++argv; *argv != NULL; ++argv) {
      if (strcmp (*argv, "--help") == 0 || strcmp (*argv, "-h") == 0)
        return "!HELP";
      else if (strcmp (*argv, "--version") == 0)
        return "!VER";
      else if (strcmp (*argv, "--timing") == 0 || strncmp (*argv, "-t", 2) == 0) {
        theTiming = true;
      }
      else if (strcmp (*argv, "--output-file") == 0 || strncmp (*argv, "-o", 2) == 0) {
        int d = 2;
        if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
        init_val (*argv, theOutputFile, d);
      }
      else if (strcmp (*argv, "--serialize-html") == 0) {
        theSerializeHtml = true;
      }
      else if (strcmp (*argv, "--serialize-text") == 0) {
        theSerializeText = true;
      }
      else if (strcmp (*argv, "--indent") == 0) {
        theIndent = true;
      }
      else if (strcmp (*argv, "--print-query") == 0) {
        thePrintQuery = true;
      }
      else if (strcmp (*argv, "--byte-order-mark") == 0) {
        theByteOrderMark = true;
      }
      else if (strcmp (*argv, "--omit-xml-declaration") == 0) {
        theOmitXmlDeclaration = true;
      }
      else if (strcmp (*argv, "--base-uri") == 0) {
        int d = 2;
        if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
        init_val (*argv, theBaseUri, d);
      }
      else if (strcmp (*argv, "--boundary-space") == 0) {
        int d = 2;
        if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
        init_val (*argv, theBoundarySpace, d);
      }
      else if (strcmp (*argv, "--default-collation") == 0) {
        int d = 2;
        if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
        init_val (*argv, theDefaultCollation, d);
      }
      else if (strcmp (*argv, "--construction-mode") == 0) {
        int d = 2;
        if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
        init_val (*argv, theConstructionMode, d);
      }
      else if (strcmp (*argv, "--ordering-mode") == 0) {
        int d = 2;
        if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
        init_val (*argv, theOrderingMode, d);
      }
      else if (strcmp (*argv, "--multiple") == 0 || strncmp (*argv, "-m", 2) == 0) {
        int d = 2;
        if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
        init_val (*argv, theMultiple, d);
      }
      else if (strcmp (*argv, "--query") == 0 || strncmp (*argv, "-q", 2) == 0) {
        int d = 2;
        if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
        init_val (*argv, theQueriesOrFiles, d);
      }
      else if (strcmp (*argv, "--as-files") == 0 || strncmp (*argv, "-f", 2) == 0) {
        theAsFiles = true;
      }
      else if (strcmp (*argv, "--external-variable") == 0 || strncmp (*argv, "-e", 2) == 0) {
        int d = 2;
        if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
        init_val (*argv, theExternalVariable, d);
      }
      else if (strcmp (*argv, "--context-item") == 0) {
        int d = 2;
        if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
        init_val (*argv, theContextItem, d);
      }
      else if (strcmp (*argv, "--optimization-level") == 0) {
        int d = 2;
        if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
        init_val (*argv, theOptimizationLevel, d);
      }
#ifdef ZORBA_DEBUGGER
      else if (strcmp (*argv, "--debug-ports") == 0 || strncmp (*argv, "-p", 2) == 0) {
        int d = 2;
        if ((*argv) [1] == '-' || (*argv) [2] == '\0') { d = 0; ++argv; }
        init_val (*argv, theDebugPorts, d);
      }
      else if (strcmp (*argv, "--debug-client") == 0 || strncmp (*argv, "-c", 2) == 0) {
        theDebugClient = true;
      }
      else if (strcmp (*argv, "--debug-server") == 0 || strncmp (*argv, "-s", 2) == 0) {
        theDebugServer = true;
      }
#endif
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
"--timing, -t\nPrint timing information. In case of multiple queries the timing information is provided per each query\n\n"
"--output-file, -o\nWrite the result to the given file.\n\n"
"--serialize-html\nSerialize the result as HTML.\n\n"
"--serialize-text\nSerialize the result as Text.\n\n"
"--indent\nIndent output.\n\n"
"--print-query\nPrint the queries.\n\n"
"--byte-order-mark\nSet the byte-order-mark for the serializer.\n\n"
"--omit-xml-declaration\nOmit the XML declaration from the result.\n\n"
"--base-uri\nSet the base URI property of the static context\n\n"
"--boundary-space\nSet the boundary-space policy ('strip' or 'preserve') in the static context.\n\n"
"--default-collation\nAdd the given collation and set the value of the default collation in the static context to the given collation.\n\n"
"--construction-mode\nSet the construction mode ('strip' or 'preserve') in the static context.\n\n"
"--ordering-mode\nSet the ordering mode ('ordered' or 'unordered') in the static context\n\n"
"--multiple, -m\nExecute the given queries multiple times.\n\n"
"--query, -q\nQuery test or file URI (file://...)\n\n"
"--as-files, -f\nTreat all -q arguments as file paths instead of URIs or inline queries\n\n"
"--external-variable, -e\nProvide the value for a variable given a file (name=file) or a value (name:=value)\n\n"
"--context-item\nSet the context item to the XML document in a given file.\n\n"
"--optimization-level\nOptimization level for the query compiler (O0 or O1)\n\n"
#ifdef ZORBA_DEBUGGER
"--debug-ports, -p\nSpecify the ports for zorba debugger. The format is requestPort:eventPort.\n\n"
"--debug-client, -c\nLaunch the debugger command line client.\n\n"
"--debug-server, -s\nLaunch queries on the debugger server.\n\n"
#endif
;
  }

  static const ZorbaCMDPropertiesBase *instance () {
    static ZorbaCMDPropertiesBase result;
    return &result;
  }

  ZorbaCMDPropertiesBase () { initialize (); }
  
};

}   // namespaces

#endif // ZORBACMD_ZORBACMDPROPERTIESBASE
