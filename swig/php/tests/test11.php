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
    $itemFactory = $aZorba->getItemFactory();
    print "Creating JSON Item null:  ". $itemFactory->createJSONNull()->serialize() . "\n";
    print "Creating JSON Item number:  ". $itemFactory->createInteger(5)->serialize() . "\n";
    $sv = new StringVector(4);
    $sv->set(0, "Hello");
    $sv->set(1, "Zorba");
    $sv->set(2, "Hello");
    $sv->set(3, "Zorba");
    print "Creating JSON Item array:  ". $itemFactory->createJSONArray($sv)->serialize() . "\n";
    print "Success";
  } catch (ZorbaException $e) {
    print "Caught unexpected Zorba error: " . $e->getDescription() . "\n" ;
    exit();
  } catch (Exception $e) {
    print "Caught error: " . $e . "\n";
    exit();
  }
  return;
}

$store = InMemoryStore::getInstance();
$zorba = Zorba::getInstance($store);

print "Running: Compile query string using Diagnostic Handler\n";
test($zorba);

$zorba->shutdown();
InMemoryStore::shutdown($store);

?>
