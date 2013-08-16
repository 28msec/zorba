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
#include <zorba/util/base64_util.h>
#include <iostream>

using namespace zorba;

bool 
encode_example() 
{
  String const lString("Hello Zorba");
  String lEncoded;
  base64::encode(lString, &lEncoded);
  return lEncoded == "SGVsbG8gWm9yYmE="; 
}

bool 
decode_example()
{
  String const lEncoded("SGVsbG8gWm9yYmE=");
  String lDecoded;
  base64::decode(lEncoded, &lDecoded);
  return lDecoded == "Hello Zorba";
}

int binary(int argc, char* argv[]) {

  std::cout << "executing example 1 (Base64 encoding of String)" << std::endl;
  if (!encode_example()) return 1;

  std::cout << "executing example 2 (decoding of Base64 encoded String)" << std::endl;
  if (!decode_example()) return 1;

  return 0;
}
/* vim:set et sw=2 ts=2: */
