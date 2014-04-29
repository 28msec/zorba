jsoniq version "1.0";
(:
 : Copyright 2014 The FLWOR Foundation.
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
 : This module contains internal test functions.
 : @author Federico Cavalieri
 :)
module namespace tests = "http://zorba.io/modules/util-tests";

declare namespace an = "http://zorba.io/annotations";
declare namespace ver = "http://zorba.io/options/versioning";

declare option ver:module-version "1.0";

(:~
 : Equivalent to:
 : declare %an:cache function local:test-01-cache($x as xs:integer)
 : {
 :  if ($x &lt; 10)
 :  then $x * $x
 :  else if ($x &lt; 20)
 :  then ()
 :  else ($x, " == ", $x * $x)
 : };
 : 
 : @param $arg as described above
 : @return as described above
 :)
declare %an:cache function tests:test-01-cache($arg as xs:integer) as item()* external;

(:~
 : Equivalent to:
 : declare %an:strictlydeterministic function local:test-01-sd($x as xs:integer)
 : {
 :  if ($x &lt; 10)
 :  then $x * $x
 :  else if ($x &lt; 20)
 :  then ()
 :  else ($x, " == ", $x * $x)
 : };
 :
 : @param $arg as described above
 : @return as described above
 :)
declare %an:strictlydeterministic function tests:test-01-sd($arg as xs:integer) as item()* external;

(:~
 :
 : Equivalent to:
 : declare %an:cache function local:test-02-cache($arg)
 : {
 :   serialize($arg),
 :   uuid:uuid()
 : };
 :
 : @param $arg as described above
 : @return as described above
 :)
declare %an:cache function tests:test-02-cache($arg) as item()* external;

(:~
 : Equivalent to:
 : declare %an:strictlydeterministic function local:test-02-sd($arg)
 : {
 :   serialize($arg),
 :   uuid:uuid()
 : };
 :
 : @param $arg as described above
 : @return as described above
 :)
declare %an:strictlydeterministic function tests:test-02-sd($arg) as item()* external;

(:~
 : Equivalent to:
 : declare %an:cache function local:test-03-cache() 
 : {
 :   { "a" : 1 },
 :   [1],
 :   &lt;a/&gt;,
 :   1
 : };
 :
 : @return as described above
 :)
declare %an:cache function tests:test-03-cache() as item()* external;

(:~
 : Equivalent to:
 : declare %an:strictlydeterministic function local:test-03-sd() 
 : {
 :   { "a" : 1 },
 :   [1],
 :   &lt;a/&gt;,
 :   1
 : };
 :
 : @return as described above
 :)
declare %an:strictlydeterministic function tests:test-03-sd() as item()* external;

(:~
 : Equivalent to:
 : declare %an:cache function local:test-04-cache($x, $y) 
 : {
 :   tests:non-seeakable-streamable-string(),
 :   {"key" : tests:non-seeakable-streamable-string()},
 :   [tests:non-seeakable-streamable-string()],
 :   &lt;a&gt;{tests:non-seeakable-streamable-string()}&lt;/a&gt;
 :   serialize($x),
 :   serialize($y)
 : };
 :
 : @param $x as described above
 : @param $y as described above
 : @return as described above
 :)
declare %an:cache function tests:test-04-cache($x, $y) as item()* external;

(:~
 : Equivalent to:
 : declare %an:strictlydeterministic function local:test-04-sd($x, $y) 
 : {
 :   tests:non-seeakable-streamable-string(),
 :   {"key" : tests:non-seeakable-streamable-string()},
 :   [tests:non-seeakable-streamable-string()],
 :   &lt;a&gt;{tests:non-seeakable-streamable-string()}&lt;/a&gt;
 :   serialize($x),
 :   serialize($y)
 : };
 :
 : @param $x as described above
 : @param $y as described above
 : @return as described above
 :)
declare %an:strictlydeterministic function tests:test-04-sd($x, $y) as item()* external;

(:~
 : Equivalent to:
 : declare %an:cache function local:test-05-cache($x as xs:boolean, $y)
 : {
 :   if ($x)
 :   then $y
 :   else $x
 : };
 :
 : @param $x as described above
 : @param $y as described above
 : @return as described above
 :)
declare %an:cache function tests:test-05-cache($x as xs:boolean, $y) as item()* external;

(:~
 : Equivalent to:
 : declare %an:strictlydeterministic function local:test-05-sd($x as xs:boolean, $y)
 : {
 :   if ($x)
 :   then $y
 :   else $x
 : };
 :
 : @param $x as described above
 : @param $y as described above
 : @return as described above
 :)
declare %an:strictlydeterministic function tests:test-05-sd($x as xs:boolean, $y) as item()* external;

(:~
 : Equivalent to:
 : declare %an:cache %an:exclude-from-cache-key(2) function local:test-06-cache($x as xs:integer, $y as xs:integer) as xs:integer
 : {
 :   $x + $y
 : };
 :
 : @param $x as described above
 : @param $y as described above
 : @return as described above
 :)
declare %an:cache %an:exclude-from-cache-key(2) function tests:test-06-cache($x as xs:integer, $y as xs:integer) as xs:integer external;

(:~
 : Equivalent to:
 : declare %an:strictlydeterministic %an:exclude-from-cache-key(2) function local:test-06-sd($x as xs:integer, $y as xs:integer) as xs:integer
 : {
 :   $x + $y
 : };
 :
 : @param $x as described above
 : @param $y as described above
 : @return as described above
 :)
declare %an:strictlydeterministic %an:exclude-from-cache-key(2) function tests:test-06-sd($x as xs:integer, $y as xs:integer) as xs:integer external;

(:~
 : Equivalent to:
 : declare %an:strictlydeterministic %an:compare-with-deep-equal(2) function local:test-07-cache($x as item()*, $y as item()*)
 : {
 :   serialize({"x" : $x, "y" : $y}),
 :   tests:uuid()
 : };
 :
 : @param $x as described above
 : @param $y as described above
 : @return as described above
 :)
declare %an:cache %an:compare-with-deep-equal(2) function tests:test-07-cache($x as item()*, $y as item()*) as item()* external;

(:~
 : Equivalent to:
 : declare %an:strictlydeterministic %an:compare-with-deep-equal(2) function local:test-07-sd($x as item()*, $y as item()*)
 : {
 :   serialize({"x" : $x, "y" : $y}),
 :   tests:uuid()
 : };
 :
 : @param $x as described above
 : @param $y as described above
 : @return as described above
 :)
declare %an:strictlydeterministic %an:compare-with-deep-equal(2) function tests:test-07-sd($x as item()*, $y as item()*) as item()* external;

(:~
 : Returns a non seekable streamable string
 :
 : @return a non seekable streamable string
 :)
declare %an:deterministic function tests:non-seeakable-streamable-string() as string external;

(:~
 : This function is not deterministic despite the annotation
 :
 : @return a uuid
 :)
declare %an:deterministic function tests:uuid() as string external;

