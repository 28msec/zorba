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

#include "util/string_utils.h"

namespace zorba { 

std::vector<std::string> std_string_tokenize(const std::string& str,
    const std::string& delims)
{
  // Skip delims at beginning, find start of first token
  std::string::size_type lastPos = str.find_first_not_of(delims, 0);
  // Find next delimiter @ end of token
  std::string::size_type pos     = str.find_first_of(delims, lastPos);

  // output vector
  std::vector<std::string> tokens;

  while (std::string::npos != pos || std::string::npos != lastPos)
  {
    // Found a token, add it to the vector.
    tokens.push_back(str.substr(lastPos, pos - lastPos));
    // Skip delims.  Note the "not_of". this is beginning of token
    lastPos = str.find_first_not_of(delims, pos);
    // Find next delimiter at end of token.
    pos     = str.find_first_of(delims, lastPos);
  }

  return tokens;
}
                                          
}

