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
 : @author Chris Hillery, Cezar Andrei
 :)
 
module namespace map = "http://jsound.io/modules/validate/map";
 
declare namespace an = "http://zorba.io/annotations";
declare namespace ver = "http://zorba.io/options/versioning";
declare option ver:module-version "1.0";

(:~ 
 : Inserts new key and value into the map or replaces value under the exiting key.
 : Returns true all the time.
 : 
 : @param $map the map JSON object
 : @param $key the key
 : @param $value the value
 : @return true
 :
 : Example: 
<code>
 variable $foo := { "foo" : 5 };
 map:set($foo, "foo", 6);
 map:set($foo, "bar", 7);
 $foo
</code>
 :)
declare %an:sequential function 
map:set($map as object, $key as xs:string, $value as item) as boolean
{
  if( keys($map) = $key ) then
    insert json { $key : $value } into $map;
  else
    replace value of json $map.$key with $value;
    
  true
};


(:~ 
 : Only if key doesn't exist, inserts new key and value into the map and 
 : returns true. Otherwise returns false.
 : 
 : @param $map the map JSON object
 : @param $key the key
 : @param $value the value
 : @return true if $key is empty, false otherwise
 :
 : Example: 
<code>
 variable $foo := { "foo" : 5 };
 map:set($foo, "foo", 6);
 map:set-if-empty($foo, "foo", 7);
 $foo
</code>
 :)
declare %an:sequential function 
map:set-if-empty($map as object, $key as xs:string, $value as item) as boolean
{
  if( keys($map) = $key ) 
  then
    false
  else
  {
    insert json { $key : $value } into $map;
    true
  }
};


(:~ 
 : Returns the value under the key.
 : 
 : @param $map the map JSON object
 : @param $key the key
 : @return the value under the $key, () if empty
 :
 : Example: 
<code>
 variable $foo := { "foo" : 5 };
 map:set($foo, "foo", 6);
 map:set($foo, "bar", 7);
 map:get($foo, "foo")
</code>
 :)
declare function 
map:get($map as object, $key as string) as item
{
  $map.$key
};

(:~ 
 : Returns true if $key exists in the map.
 : 
 : @param $map the map JSON object
 : @param $key the key
 : @return true if $key exists, false otherwise
 :
 : Example: 
<code>
 variable $foo := { "foo" : 5 };
 map:set($foo, "foo", 6);
 map:has-key($foo, "foo")
</code>
 :)
declare function
map:has-key($map as object, $key as string) as boolean
{
  keys($map) = $key
};



(:
variable $foo := { "foo" : 5 };
map:set($foo, "foo", 6);
map:set($foo, "bar", 7);
$foo
:)
