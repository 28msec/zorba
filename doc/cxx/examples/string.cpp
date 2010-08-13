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
#include <zorba/zorba.h>
#include <zorba/zorbastring.h>
#include <iostream>
#include <sstream>


using namespace zorba;

bool 
nr_of_chars_example() 
{
  std::string lStdStr("Hello\u00E7Zorba");
  String lString(lStdStr);
  // zorba::String::length return the length of the string after considering UTF-* encoding.
  // Therefore, the length needs to be different to zorba::String::nr_of_chars and std::string::length
  return lStdStr.length() == lString.nr_of_chars()
      && lString.length() != lString.nr_of_chars();
}

int 
string(int argc, char* argv[])
{

  bool res = false;
  
  std::cout << "executing example 1 (nr_of_chars of String)" << std::endl;
  res = nr_of_chars_example();
  if (!res) return 1;
  std::cout << std::endl;
  
  return 0;

}
