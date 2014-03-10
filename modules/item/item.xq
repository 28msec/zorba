xquery version "1.0";

(:
 : Copyright 2012 The FLWOR Foundation.
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
 : This module provides utility functions on items. For example,
 : it provides a function that allows estimating the size in bytes
 : that a given item allocates in memory.
 : 
 : @author Matthias Brantner
 : @project Zorba/XML and JSON Data Model/Item/Item
 :)
module namespace item = "http://zorba.io/modules/item";

declare namespace ver = "http://zorba.io/options/versioning";
declare option ver:module-version "1.0";

(:~
 : Computes the size in bytes of the given item in main memory.<p/>
 :
 : @param $item the item whose size to compute.
 :
 : @return the size allocated by the item in bytes.
 :)
declare function item:size($item as item()) as xs:integer external;
