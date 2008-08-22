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
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>

#include "store/naive/properties.h"


#define CONFIG_FOLDER "zorba"
#define CONFIG_FILE "simplestore.cfg"

namespace zorba { namespace store {

Properties* Properties::instance()
{
  static Properties lProperties;
  return &lProperties;
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
#if defined (WIN32) || defined (UNIX)
#define DOT_FILE "."
#else
#define DOT_FILE ""
#endif

  std::string lFolder;
  std::stringstream lStream;
    
  if (getOSConfigFolder(lFolder)) 
  {
    // $HOME/.zorba/simplestore.cfg
#ifdef __win32__
    lStream << lFolder << "\\" << DOT_FILE CONFIG_FOLDER << "\\" << CONFIG_FILE;
# else
    lStream << lFolder << "/" << DOT_FILE CONFIG_FOLDER << "/" << CONFIG_FILE;
#endif
    aFileURI = lStream.str();
    return true;
  }
  return false;
}

  
bool Properties::loadProps(int argc, char *argv[])
{
    std::string cfgfile;
    getOSConfigFile (cfgfile);
    std::string result = load_all (cfgfile.c_str (), "ZORBA_STORE_CFG_", argc, (const char **) argv);
    if (result.empty ()) result = check_args ();
    if (result == "!HELP") {
      std::cout << "Allowed options:\n\n";
      std::cout << get_help_msg ();
      return false;
    } else if (result.empty ()) {
      return true;
    } else if (result [0] != '!') {
      std::cout << "Error: " << result << std::endl;
      return false;
    } else {
      return false;
    }
 }


  bool Properties::load(int argc, char *argv[]) {
    Properties* lProps = Properties::instance();
    return lProps->loadProps(argc, argv);
  }

}
} /* namespace zorba */
