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
 : This module provides function that are related to XML Schema support
 : in Zorba.
 :
 : @author Matthias Brantner
 :
 :)
module namespace schema = "http://www.zorba-xquery.com/modules/schema";

(:~
 : This function returns the name of the type of the item passed
 : as parameter.
 :
 : @param $item the item from which the name of the type should be returned.
 : @return the name of the type (as QName) of the item passed as parameter.
 :)
declare function schema:schema-type (
  $item as item()
) as xs:QName external;

(:~
 : This function returns true if the given node has need validated,
 : and false otherwise.
 :
 : @param $node the node item that should be checked for validation
 : @return true if the given node has been validated, false otherwise.
 :)
declare function schema:is-validated(
  $node as node()
) as xs:boolean external;
