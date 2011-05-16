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
 : This module defines a set of functions to deal with indexes in Zorba.
 : For example, it provides functions to create or delete indexes.
 :
 : @see <a href="http://www.zorba-xquery.com/doc/zorba-latest/zorba/html/XQDDF.html" target="_blank">Zorba Data Definition Facility</a>
 : @see http://www.zorba-xquery.com/modules/store/static/indexes/dml
 : @see http://www.zorba-xquery.com/modules/store/static/collections/dml
 : @see http://www.zorba-xquery.com/modules/store/static/collections/ddl
 :
 : @author Nicolae Brinza, Matthias Brantner, David Graf, Till Westmann, Markos Zaharioudakis
 :
 :)
module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/indexes/ddl";

(:~
 : The function returns true if an index with the given QName is available.
 : (i.e. has been created).
 :
 : @param $name The QName of the index that is being checked.
 : @return true if the index is available and false otherwise.
 :)
declare function ddl:is-available-index($name as xs:QName) as xs:boolean external;

(:~
 : The function returns a sequence of QNames representing the indexes that are
 : available. The sequence will be empty if there are no indexes.
 :
 : @return A sequence of QNames, one for each available index, or an empty
 : sequence if none are.
 :)
declare function ddl:available-indexes() as xs:QName* external;

(:~
 : The create-index function is an updating function that adds a
 : mapping from the expanded QName $name to a map of index entries
 : to the map of available indexes.
 :
 : @param $name The QName of the index to add to the map of available
 :        indexes.
 : @error if the expanded QName of $name is not equal
 :       (as defined by the
 :       <a href="http://www.w3.org/TR/xquery/#id-value-comparisons">eq operator</a>) 
 :       to the name of any resource in the statically known indexes.
 : @error if available indexes already provides a mapping
 :        for the expaned QName $name.
 : @return The result of the function is an empty XDM instance and a pending
 :         update list that contains the upd:createIndex($name)
 :         update primitive.
 :)
declare updating function ddl:create-index(
  $name as xs:QName)  external;

(:~
 : The delete-index function is an updating function that removes a resource
 : from the map of available indexes. The QName $name is the name
 : of the resource.
 :
 : @param $name The QName of the index to delete from the map of available
 :        indexes.
 : @error XDDY0009 If available indexes does not provide a mapping for
 :        the expaned QName $name.
 : @return The result of the function is an empty XDM instance and a pending
 :         update list that contains the upd:deleteIndex($name)
 :         update primitive.
 :)
declare updating function ddl:delete-index(
  $name as xs:QName)  external;

(:~
 : The function returns true if an index with the given QName has been declared.
 :
 : @param $name The QName of the index that is being checked.
 : @return true if the index has been declared and false otherwise.
 :)
declare function ddl:is-declared-index(
  $name as xs:QName) as xs:boolean  external;

(:~
 : The function returns a sequence of QNames representing the indexes that have
 : been previously created. The sequence will be empty if there are no indexes.
 :
 : @return A sequence of QNames, one for each created index, or an empty
 : sequence if none exist.
 :)
declare function ddl:declared-indexes() as xs:QName*  external;
