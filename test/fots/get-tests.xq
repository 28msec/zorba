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

declare namespace c = "http://www.w3.org/2010/09/qt-fots-catalog";

declare variable $testSet as xs:string external := "";

let $catalog := fn:doc(fn:static-base-uri())/c:catalog
let $test-set := $catalog/c:test-set[@name = $testSet]
let $test-relfile := fn:trace(data($test-set/@file), "Loading")
return fn:string-join(data(fn:doc($test-relfile)/c:test-set/c:test-case/@name), ';')
