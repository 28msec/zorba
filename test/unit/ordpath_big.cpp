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
#include <string.h>
#include "../../src/store/naive/ordpath.h"

int ordpath_big (int argc, char* argv[])
{
  std::string lOrdStr1 = "5f05f84c";
  std::string lOrdStr2 = "5f05f84d";

  zorba::simplestore::OrdPath lOrdPath1((const unsigned char*) lOrdStr1.c_str(),
                                        lOrdStr1.length());

  zorba::simplestore::OrdPath lOrdPath2((const unsigned char*) lOrdStr2.c_str(),
                                        lOrdStr2.length());

  zorba::simplestore::OrdPath lOrdPath3; 

  for (int i = 0 ; i < 100000 ; ++i) 
  {
    zorba::simplestore::OrdPath::insertBefore(lOrdPath1, lOrdPath2, lOrdPath3);
    if (i % 1000 == 0)
      std::cout << "Ordpath Nr " << i << " : " << lOrdPath3.serialize() << std::endl;
    lOrdPath2 = lOrdPath3;
  }  

  return 0;
}
/* vim:set et sw=2 ts=2: */
