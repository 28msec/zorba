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

#include <zorba/util/uri.h>
#include <zorba/zorbastring.h>

using namespace zorba;

int uri_file_decoding_test(int argc, char* argv[]) {
  String lTestString("file:////hello_world");
  String res = URIHelper::decodeFileURI(lTestString);
  if (res != "/hello_world")
    return 1;
  return 0;
}
