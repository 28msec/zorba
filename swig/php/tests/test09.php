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

function test(Zorba $aZorba) {
  $xquery = $aZorba->compileQuery("<a>text-a1<b at1='att1' at2='{1+2}'>text-b1</b>text-a2</a>");
  
  
  $saxHandler = new SAX2ContentHandlerProxy();
  $saxHandler->setStartDocumentHandler(startDocumentHandler);
  $saxHandler->setEndDocumentHandler(endDocumentHandler);
  $saxHandler->setStartElementHandler(startElementHandler);
  $saxHandler->setEndElementHandler(endElementHandler);
  $saxHandler->setCharactersHandler(charactersHandler);
  $saxHandler->setProcessingInstructionHandler(processingInstructionHandler);
  $saxHandler->setIgnorableWhitespaceHandler(ignorableWhitespaceHandler);
  $saxHandler->setStartPrefixMappingHandler(startPrefixMappingHandler);
  $saxHandler->setEndPrefixMappingHandler(endPrefixMappingHandler);
  $saxHandler->setSkippedEntityHandler(skippedEntityHandler);
  $xquery->executeSAX($saxHandler);

  return;
}

function startDocumentHandler() {
  print "Start Document";
  return;
}
function endDocumentHandler() {
  print "End Document";
  return;
}
function startElementHandler($URI, $localName, $QName, $SAXAttributes) {
  print "Start Element - " . $QName;
  return;
}
function endElementHandler($URI, $localName, $QName) {
  print "End Element - " . $QName;
  return;
}
function charactersHandler($text) {
  print "Characters - " . $text;
  return;
}
function processingInstructionHandler($target, $data) {
  print "Processing Instruction";
  return;
}
function ignorableWhitespaceHandler($text) {
  print "Ignorable Whitespace - " . $text;
  return;
}
function startPrefixMappingHandler($prefix, $URI) {
  print "Start Prefix Mapping - " . $prefix;
  return;
}
function endPrefixMappingHandler($prefix) {
  print "End Prefix Mapping - " . $prefix;
  return;
}
function skippedEntityHandler($name) {
  print "Skipped Entity - " . $name;
  return;
}


$store = InMemoryStore::getInstance();
$zorba = Zorba::getInstance($store);

print "Running: XQuery execute - executeSAX\n";
test($zorba);
print "Success";

$zorba->shutdown();
InMemoryStore::shutdown($store);

?>