(:
 : Copyright 2006-2011 The FLWOR Foundation.
 :
 : Licensed under the Apache License, Version 2.0 (the "License");
 : you may not use this file except in compliance with the License.
 : You may obtain a copy of the License at
 :
 : http://www.apache.org/licenses/LICENSE-2.0
 :
 : Unless required by applicable law or agreed to in writing, software
 : distributed under the License is distributed on an "AS IS" BASIS,
 : WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 : See the License for the specific language governing permissions and
 : limitations under the License.
 :)
 
(:~
 : list all node-names of the nodes that contain a child with a 'file' attribute.
 : At the moment this is the list: "source", "schema", "assert-xml", "module", "test"
 :
 : @author Sorin Nasoi
 :)

import module namespace util =
  "http://www.zorba-xquery.com/fots-driver/util" at "../util.xq";

declare namespace fots =
  "http://www.w3.org/2010/09/qt-fots-catalog";

let $fotsPath := "../../../build/test/fots/2011/QT3-test-suite/catalog.xml"
let $doc := doc(resolve-uri($fotsPath))
let $baseUri:= resolve-uri(util:parent-folder($fotsPath))
return
distinct-values(
  for $testSet in $doc/fots:catalog/fots:test-set
  let $testSetDoc := doc(resolve-uri($testSet/@file, $baseUri))
  let $testSetName := xs:string($testSet/@name)
  return
  distinct-values(for $case in $testSetDoc//fots:test-case
                  return distinct-values(for $node in $case/descendant-or-self::*
                                         where exists($node/@file)
                                         return local-name-from-QName(node-name($node))
                                         )
                  )
)
