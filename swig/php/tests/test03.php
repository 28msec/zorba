<?
/*
 * Copyright 2006-2012 The FLWOR Foundation.
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

require '@phpPath@/Zorba/zorba_api_wrapper.php';

class MyDiagnosticHandler(DiagnosticHandler handler) {
  funtion error(self, *args) {
    print "Error args: ", args;
  }
}

function test(Zorba $aZorba)
{
  diagnosticHandler = MyDiagnosticHandler()
  try {
    xquery = zorba.compileQuery("1 div 0", diagnosticHandler);
    print xquery.execute()
  } catch (Exception e) {
    print "Caught error: ";
  }
  return
}

$store = InMemoryStore::getInstance();
$zorba = Zorba::getInstance($store);

print "Running: Compile query string using Diagnostic Handler"
test($zorba);
print "Success";

$zorba->shutdown();
InMemoryStore::shutdown($store);

?>