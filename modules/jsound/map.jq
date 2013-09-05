jsoniq version "1.0";

(:
 : Copyright 2006-2013 The FLWOR Foundation.
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
 : Map utility
 :
 :)
 
module namespace map = "http://jsound.io/modules/validate/map";
 
declare namespace an = "http://zorba.io/annotations";

declare %an:sequential function 
map:set($map as object, $key as xs:string, $value as item) as boolean
{
  if( empty( $map($key) ) ) then
    insert json { $key : $value } into $map;
  else
    replace json value of $map($key) with $value;
    
  fn:true()
};


declare %an:sequential function 
map:set-if-empty($map as object, $key as xs:string, $value as item) as boolean
{
  if (empty($map( $key ))) then
    insert json { $key : $value } into $map;
  else
    fn:error(QName("jsdBADJSound"), 
          "Not a valid JSound doc: type '" | $key | "' already defined.");
          
  fn:true()
};



declare function 
map:get($map as object, $key as xs:string) as item
{
  $map($key)
};



(:
variable $foo := { "foo" : 5 };
local:set($foo, "foo", 6);
local:set($foo, "bar", 7);
$foo
:)
