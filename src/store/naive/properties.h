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
#ifndef ZORBA_PROPERTIES_H
#define ZORBA_PROPERTIES_H

#include <string>
#include <fstream>
#include <vector>

namespace zorba { namespace store {

class Properties
{
private:
  static bool theLoaded;

private:
  long theStoreTraceLevel;

  /**
   * Constructor.
   * The default values of the properties are set here! Boost Program Options
   * default values do not work because parts of the parsing might not be executed
   * because of the command line or the property file is not parsed.
   */
  Properties();

  /**
   * Gets the Operation System folger where the properties of the current 
   * user are saved.
   * Linux, Mac: /home/username
   * Windows Vista: C:\Users\username\Application Data
   * Windows XP: C:\Documents and Settings\username\Application Data
   * 
   * @param aFolderURI 
   * @return true, if found
   */
  bool 
  getOSConfigFolder(std::string& aFolderURI);
      
  /**
   * Gets the location of the zorba property in the operation system.
   * 
   * Linux, Mac: /home/username/.zorba/properties.cfg
   * Windows Vista: C:\Users\username\Application Data\zorba\properties.cfg
   * Windows XP: C:\Documents and Settings\username\Application Data\zorba\properties.cfg
   * 
   * @param aFileURI 
   * @return true, if found
   */
  bool 
  getOSConfigFile(std::string& aFileURI);
    
  /**
   * Parses the program options.
   * 
   * @param argc 
   * @param argv[] 
   * @param aNoCmdLineOptions true, if command line options should not be considered.
   * @return false, if the parsing didn't work
   */
  bool 
  loadProps(int argc, char *argv[], bool aNoCmdLineOptions = false);
    
public:
  static Properties* 
  instance(bool aCheckLoad = true);
      
  /**
   * Parses the command line arguments and the property file for properties.
   * The url of the property file is searched in the command line's arguments under the name property-file.
   * If this argument is not found, the property file is search in the current
   * directory under the name properties.cfg. If not found there, it is searched in the
   * config folder for zorba of the operation system. This folder is defined as follows:
   * - Linux, Mac: /home/username/.zorba/properties.cfg
   * - Windows Vista: C:\Users\username\Application Data\zorba\properties.cfg
   * - Windows XP: C:\Documents and Settings\username\Application Data\zorba\properties.cfg
   * 
   * 
   * @return true if parsing was successful, else false
   */
  static bool 
  load(int argc, char *argv[]);
      
  long
  storeTraceLevel() { return theStoreTraceLevel; }    
};

}
} /* namespace zorba */
#endif

/* vim:set ts=2 sw=2: */
/*
 * Local variables:
 * mode: c++
 * End:
 */
