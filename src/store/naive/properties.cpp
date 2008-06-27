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
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/program_options/positional_options.hpp>
#include <boost/program_options/parsers.hpp>
#include <fstream>
#include <iostream>
#include <sstream>

#include "store/naive/properties.h"


#define CONFIG_FOLDER "zorba"
#define CONFIG_FILE "simplestore.cfg"

namespace po = boost::program_options;

namespace zorba { namespace store {

bool Properties::theLoaded = false;


Properties* Properties::instance(bool aCheckLoad)
{
  static Properties lProperties;

  if (aCheckLoad && !theLoaded)
    lProperties.loadProps(0, 0, true);

  return &lProperties;
}

  
Properties::Properties() 
  :
  theStoreTraceLevel(0),
  theBuildDataGuide(false)
{
}

  
bool Properties::getOSConfigFolder(std::string& aFolderURI) 
{
  char *pValue;
    
#ifdef __unix__
  pValue = getenv("HOME"); 
#elif defined WINCE
  pValue = NULL;
#elif defined WIN32
  size_t len;
  _dupenv_s( &pValue, &len, "APPDATA" );
#else
  pValue = getenv( "APPDATA" );
#endif
  if (pValue == 0)
    return false;

  aFolderURI = pValue;
    
  return true;
}
  

bool Properties::getOSConfigFile(std::string& aFileURI) 
{
  std::string lFolder;
  std::stringstream lStream;
    
  if (getOSConfigFolder(lFolder)) 
  {
#ifdef __win32__
    lStream << lFolder << "\\" << "." CONFIG_FOLDER << "\\" << CONFIG_FILE;
# else
    lStream << lFolder << "/" << CONFIG_FOLDER << "/" << CONFIG_FILE;
#endif
    aFileURI = lStream.str();
    return true;
  }
  return false;
}

  
 /**
  * This function is programmed according to the description in
  * http://www.boost.org/doc/html/program_options/tutorial.html.
  * 
  * Important: 
  **/
bool Properties::loadProps(int argc, char *argv[], bool aNoCmdLineOptions)
{
  std::string propertiesFile;
    
  // Declaration of Generic Options
  po::options_description lGenericOptions ( "Generic Options" );
  lGenericOptions.add_options()
      ( "version,v", "print version std::string" )
      ( "help,h", "produce help message" )
      ( "property-file", po::value<std::string>(&propertiesFile), "URI to property file")
  ;

  // Declaration of Configuration Options
  po::options_description lConfigOptions ( "Configuration Options" );
  lConfigOptions.add_options()
    ("store-trace-level", po::value<long>(&theStoreTraceLevel), "store trace level (<= 0 : no tracing)")
    ("build-dataguide", po::value<bool>(&theBuildDataGuide), "build-dataguide (true/false)")
  ;  

  // Classifies everything which can be defined over the command line
  po::options_description lCmdlineOptions;
  lCmdlineOptions.add(lGenericOptions).add(lConfigOptions);

  // Classifies everthing which can be defined over the configuration file
  po::options_description lConfigFileOptions;
  lConfigFileOptions.add ( lConfigOptions ).add ( lGenericOptions );

  // Classifies everthing which can be seen when --help is executed
  po::options_description lVisibleOptions ( "Allowed options" );
  lVisibleOptions.add ( lGenericOptions ).add ( lConfigOptions );

  po::variables_map lVarMap;
    
  // Applies the command line arguments
  if (!aNoCmdLineOptions) 
  {
    po::store(po::command_line_parser(argc, argv).
          options(lCmdlineOptions).run(), lVarMap);
  }
    
  // Ignites the command line parsing
  notify ( lVarMap );
    
  // Help output when demanded
  if ( lVarMap.count ( "help" ) )
  {
    std::cout << lVisibleOptions << std::endl;;
    return false;
  }

  // Version output when demanded
  if ( lVarMap.count ( "version" ) )
  {
    std::cout << "Simple Store, version 0.1" << std::endl;
    return false;
  }
    
  // parsing of the property file
  if (lVarMap.count("property-file")) 
  {
    std::ifstream lStreamFile( lVarMap["property-file"].as<std::string>().c_str() );
    if (!lStreamFile) 
    {
      std::cerr << "Property file (" <<  lVarMap["property-file"].as<std::string>()
                << ") not found" << std::endl;
      return false;
    }
    po::store(parse_config_file(lStreamFile, lConfigFileOptions), lVarMap);
  }
  else
  {
    std::ifstream lStreamDot(CONFIG_FILE);
    if (lStreamDot)
    {
      po::store(parse_config_file(lStreamDot, lConfigFileOptions), lVarMap);
    }
    else
    {
      std::string lFile;
      if (getOSConfigFile(lFile))
      {
        std::ifstream lStreamHome(lFile.c_str());
        if (lStreamHome)
          po::store(parse_config_file(lStreamHome, lConfigFileOptions), lVarMap);
      }
    }
  }
  
  // Ignites the property file parsing
  notify ( lVarMap );

  Properties::theLoaded = true;
    
  return true;
 }


bool Properties::load(int argc, char *argv[]) 
{
  Properties* lProps = Properties::instance(false);
  return lProps->loadProps(argc, argv);
}

}
} /* namespace zorba */
