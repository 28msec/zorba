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
#ifndef ZORBA_STORE_PROPERTIES_H
#define ZORBA_STORE_PROPERTIES_H

#include <string>
#include <fstream>
#include <vector>

#include "store/naive/store_properties.h"

namespace zorba { namespace store {

class Properties : public StoreProperties
{
private:
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
   * Linux, Mac: /home/username/.zorba/simplestore.cfg
   * Windows Vista: C:\Users\username\Application Data\zorba\simplestore.cfg
   * Windows XP: C:\Documents and Settings\username\Application Data\zorba\simplestore.cfg
   * 
   * @param aFileURI 
   * @return true, if found
   */
  bool 
  getOSConfigFile(std::string& aFileURI);
    
  bool loadProps(int argc, char *argv[]);
    
public:
  static Properties* instance();
      
  static bool load(int argc, char *argv[]);
      
};

}
} /* namespace zorba */
#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
