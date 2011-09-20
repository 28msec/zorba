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
#include <zorba/base64.h>
#include <iostream>


using namespace zorba;

bool 
encode_example() 
{
  String lString("Hello Zorba");
  String lEncoded = zorba::encoding::Base64::encode(lString);
  String lExpectedResult("SGVsbG8gWm9yYmE=");
  return lEncoded == lExpectedResult; 
}

bool 
decode_example()
{
 String lEncoded("SGVsbG8gWm9yYmE=");
 String lDecoded = zorba::encoding::Base64::decode(lEncoded);
 return lDecoded == "Hello Zorba";

}

int 
binary(int argc, char* argv[])
{

bool res = false;

std::cout << "executing example 1 (Base64 encoding of String)" << std::endl;
res = encode_example();
if (!res) return 1;
std::cout << std::endl;

std::cout << "executing example 2 (decoding of Base64 encoded String)" << std::endl;
res = decode_example();
if (!res) return 1;
std::cout << std::endl;

return 0;

}
