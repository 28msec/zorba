<?
/*
 * Copyright 2006-2013 The FLWOR Foundation.
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

require 'zorba_api_wrapper.php';

class MyDiagnosticHandler extends DiagnosticHandler {
  public function error($args) {
    print "Error caught in DiagnosticHandler: " . $args->getDescription() . "\n";
  }
}

function test(Zorba $aZorba)
{
  $diagnosticHandler = new MyDiagnosticHandler();
  try {
    $xquery = $aZorba->compileQuery("1 div 0", $diagnosticHandler);
    $xquery->execute();
  } catch (ZorbaException $e) {
    print "Caught unexpected Zorba error: " . $e->getDescription();
    exit();
  } catch (Exception $e) {
    print "Caught error: " . $e;
    exit();
  }
  return;
}

$store = InMemoryStore::getInstance();
$zorba = Zorba::getInstance($store);

print "Running: Compile query string using Diagnostic Handler\n";
test($zorba);
print "Success\n";

$zorba->shutdown();
InMemoryStore::shutdown($store);

?>
