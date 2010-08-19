(:
 : Copyright 2006-2009 The FLWOR Foundation.
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
 : @author Markus Pilman
 : @version 1.0
 :)
module namespace alg = "http://www.zorba-xquery.com/modules/security/algorithms";

(:~
 : thrown if a function is called with an unknown algorithm.
 :)
declare variable $alg:unknown-algorithm as xs:QName := xs:QName("alg:unknown-algorithm");

(:~
 : List of all currently supported hash-algorithms
 :)
declare variable $alg:supported-algorithms as xs:string* := ("sha1", "md5");

