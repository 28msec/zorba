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
#include "command.h"

#include <iostream>


namespace std {
  
  set<string>& operator<< (set<string>& vec, const string& str)
  {
    string::size_type before = 0;
    string::size_type pos = str.find(" ", 0);
    while (pos != str.npos) {
      vec.insert(str.substr(before, pos));
      before = pos + 1;
      pos = str.find(" ", before);
    }
    vec.insert(str.substr(before));
    return vec;
  }

}
