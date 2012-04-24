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

function println($string) {
  print $string."\n";
}

function test(Zorba $aZorba) {
  #Read and write result 
  println ("Executing: test08.xq");
  $lines = '(1, xs:int(2),"bla", <a><b att="{(3, xs:int(4),"foo", "bar")}"/>text<!--a comment--><?pi?></a>)';
  $xquery = $aZorba->compileQuery($lines);
  $result = $xquery->execute();
  println ($result);
 
  println ("Iterator:");
  $iterator = $xquery->iterator();

  printIterator($iterator, "");
 
  $handle = fopen('test8_result.xml', 'w');
  fwrite($handle, $result);
  fclose($handle);
  return;
}

function printIterator($iterator, $pre) {
  $item = Item::createEmptyItem();
  $iterator->open(); 
  while ($iterator->next($item)) {
    printItem($item, $pre);
  }
  $iterator->close();
}
 
function printItem($item, $pre) {
  if ($item->isAtomic()) {
    $typeItem = $item->getType();
    println ($pre . "Leaf Atomic: '" . $item->getStringValue() . "' \ttype:" . $typeItem->getStringValue());
    return;
  }

  if ($item->isNode()) {
    $kind = $item->getNodeKind();
  
    if ($kind ==  0) { # anyNode
      println ($pre . 'Any node');
      println ($pre . "  Children:");
      printIterator($item->getChildren() . $pre."    ");
    }
    if ($kind ==  1) { # doc
      println ($pre . 'Doc');
      println ($pre . "  Children:");
      printIterator($item->getChildren() . $pre."    ");
    }
    if ($kind == 2) { # element
      $nodeName = Item::createEmptyItem();
      $item->getNodeName($nodeName);
      $typeItem = $item->getType();
      println ($pre . "Start Element: " . $nodeName->getStringValue() . " \ttype:" . $typeItem->getStringValue());
      println ($pre . "  Attributes:");
      printIterator($item->getAttributes(), $pre."    ");
      println ($pre . "  Children:");
      printIterator($item->getChildren(), $pre."    ");
      println ($pre . "End  Element: " . $nodeName->getStringValue());
    }
    if ($kind == 3) { # attribute
      $nodeName = Item::createEmptyItem();
      $item->getNodeName($nodeName);
      $typeItem = $item->getType();
      println ($pre . "Attribute: " . $nodeName->getStringValue() . "= '" . $item->getStringValue() . " \ttype:" . $typeItem->getStringValue());
      println ($pre."  Atomization value:");
      printIterator($item->getAtomizationValue(), $pre."    ");
    }
    if ($kind == 4) { # text
      $typeItem = $item->getType();
      println ($pre . "Text: " . $item->getStringValue() . " \ttype:" . $typeItem->getStringValue());
      println ($pre."  Atomization value:");
      printIterator($item->getAtomizationValue(), $pre."    ");
    }
    if ($kind == 5) { # pi
      $nodeName = Item::createEmptyItem();
      $item->getNodeName($nodeName);
      println ($pre . "Pi: " . $nodeName->getStringValue());
    }
    if ($kind == 6) { # comment
      println ($pre . "Comment: " . $item->getStringValue());
    }
  } else {
    println ($pre."Item not Node, not Atomic");
  }
}

$store = InMemoryStore::getInstance();
$zorba = Zorba::getInstance($store);

println ("Running: XQuery execute - Get Iterator and println (info from its items\n");
test($zorba);
println ("Success");

$zorba->shutdown();
InMemoryStore::shutdown($store);

?>