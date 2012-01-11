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
#include "zorbacmdproperties.h"

#include <fstream>
#include <iostream>
#include <cstdlib>

#include <zorba/zorba.h>

std::string ZorbaCMDProperties::check_args () {

  if(queriesOrFilesBegin() == queriesOrFilesEnd()) {
    return "No queries submitted \nUsage: zorba -q '1 + 1' execute an inline query \n zorba -f -q file.xq execute a query from a file \n Use -h for help.";
  }

  if (getPositionalArgs ().size () != 0) {
    QueriesOrFiles_t::const_iterator lIter;
    for (lIter = queriesOrFilesBegin(); lIter != queriesOrFilesEnd();
         ++lIter)
    {
      if (*lIter == "-f")
        return "Extra arguments found on command line. Possible reason: misplaced -f option (try '-f -q filename' instead of '-q -f filename'). Use -h for help.";
    }
    
    return "Extra arguments found on command line. Use -h for help.";
  }

  if ( theBoundarySpace.size() != 0 )
  {
    if ( ! (theBoundarySpace.compare("strip") == 0 || theBoundarySpace.compare("preserve") == 0 ))
      return "Only strip and preserve are allowed as values for the option boundary-space";
  }

  if ( theConstructionMode.size() != 0 )
  {
    if ( ! (theConstructionMode.compare("strip") == 0 || theConstructionMode.compare("preserve") == 0 ))
      return "Only strip and preserve are allowed as values for the option construction-mode";
  }

  if ( theOrderingMode.size() != 0 ) {
    if ( ! (theOrderingMode.compare("ordered") == 0 || theOrderingMode.compare("unordered") == 0 ))
      return "Only ordered and unordered are allowed as values for the option ordering-mode";
  }

  if ( ! (theOptimizationLevel.compare("O0") == 0 || theOptimizationLevel.compare("O1") == 0
    || theOptimizationLevel.compare("O2") == 0 ) )
    return "only O0, O1 and O2 are allowed as values for the option opt-level";

  for (std::vector<std::string>::const_iterator lIter = theExternalVariable.begin();
       lIter != theExternalVariable.end(); ++lIter) 
  {
    std::string lStr = *lIter;
    std::string::size_type lPos = lStr.find_first_of("=");
    std::string lVarName = lStr.substr(0, lPos);
    std::string lValue = lStr.substr(lPos + 1);
    bool lInlineFile = true;
    if (lVarName.at(lVarName.size()-1) == ':') {
      lInlineFile = false;
      lVarName.resize(lVarName.size()-1); // remove the :
    }
    ExternalVariable lExternalVariable;
    lExternalVariable.var_name = lVarName;
    lExternalVariable.var_value = lValue;
    lExternalVariable.inline_file = lInlineFile;
    theExternalVars.push_back(lExternalVariable);
  }

  for (std::vector<std::string>::const_iterator lIter = theOption.begin();
       lIter != theOption.end(); ++lIter) {
    size_t lEQual = lIter->find_last_of("=");
    if (lEQual == std::string::npos)
      return "option must be of the form {namespace}localname=value";

    std::string lClarkQName = lIter->substr(0, lEQual);
    std::string lValue      = lIter->substr(lEQual + 1);

    StaticContextOption lOption;
    lOption.clark_qname = lClarkQName;
    lOption.value = lValue;
    theStaticContextOptions.push_back(lOption);
  }
  for (std::vector<std::string>::const_iterator lIter = theStopWords.begin();
       lIter != theStopWords.end(); ++lIter) {
    size_t lEQual = lIter->find(":=");
    if (lEQual == std::string::npos)
      return "Stop-words mapping must be of the form URI:=value";

    std::string lURI   = lIter->substr(0, lEQual);
    std::string lValue = lIter->substr(lEQual + 2);

    FullTextMapping lMapping;
    lMapping.uri   = lURI;
    lMapping.value = lValue;
    theStopWordsMapping.push_back(lMapping);
  }
  for (std::vector<std::string>::const_iterator lIter = theThesaurus.begin();
       lIter != theThesaurus.end(); ++lIter) {
    size_t lEQual = lIter->find(":=");
    if (lEQual == std::string::npos)
      return "Thesaurus mapping must be of the form URI:=value";

    std::string lURI   = lIter->substr(0, lEQual);
    std::string lValue = lIter->substr(lEQual + 2);

    if ( lURI == "default" )
      lURI = "##default";

    FullTextMapping lMapping;
    lMapping.uri   = lURI;
    lMapping.value = lValue;
    theThesaurusMapping.push_back(lMapping);
  }
       
  return "";
}


bool ZorbaCMDProperties::loadProperties(int argc, char* argv[]) 
{
  std::string result = load_argv(argc, (const char **) argv);

  if (result.empty())
    result = check_args();

  if (result == "!HELP") 
  {
    std::cout << "Zorba XQuery Engine, Version: " 
              << zorba::Zorba::version() << std::endl;
    std::cout << "Available options:\n\n";
    std::cout << get_help_msg ();
    return false;
  }
  else if (result == "!VER") 
  {
    std::cout << "Zorba XQuery Engine, Version: " 
              << zorba::Zorba::version() << std::endl;
    return false;
  }
  else if (result.empty ())
  {
    return true;
  }
  else if (result [0] != '!')
  {
    std::cout << "Error: " << result << std::endl;
    return false;
  }
  else
  {
    return false;
  }  
}


void ZorbaCMDProperties::getModulePath(std::string& aPath) const
{
  aPath = theModulePath;
}

void ZorbaCMDProperties::getURIPath(std::string& aPath) const
{
  aPath = theUriPath;
}

void ZorbaCMDProperties::getLibPath(std::string& aPath) const
{
  aPath = theLibPath;
}

std::vector<std::pair<std::string,std::string> > ZorbaCMDProperties::getSerializerParameters() const
{
  std::vector<std::pair<std::string,std::string> > lResult;
  std::vector<std::string>::const_iterator lEnd = theSerializationParameter.end();
  for (
       std::vector<std::string>::const_iterator lIter = theSerializationParameter.begin();
       lIter != lEnd;
       ++lIter
      ) 
  {
    std::string lStr = *lIter;
    std::string::size_type lPos = lStr.find_first_of("=");
    std::string lVarName = lStr.substr(0, lPos);
    std::string lValue;
    if (lPos != std::string::npos)
        lValue = lStr.substr(lPos + 1);

    lResult.push_back(std::pair<std::string,std::string>(lVarName, lValue));
  }
  return lResult;
}
