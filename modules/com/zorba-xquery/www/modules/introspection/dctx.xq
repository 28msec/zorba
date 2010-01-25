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
 : Intospection Module for the Dynamic Context
 :
 : @version 1.0
 :)
module namespace dctx = "http://www.zorba-xquery.com/modules/introspection/dctx";


(:~
 : The function returns true if a collection with the given QName is available.
 :
 : @param $name The QName of the collection that is being checked.
 : @return true if the collection is available and false otherwise.
 :)
declare function dctx:is-available-collection($name as xs:QName) as xs:boolean external;

(:~
 : The function returns a sequence of QNames representing the collections that are
 : available. The sequence will be empty if there are no collections.
 :
 : @return A sequence of QNames, one for each available collection, or an emtpy sequence.
 :)
declare function dctx:available-collections() as xs:QName* external;

(:~
 : The function returns true if an index with the given QName is available.
 :
 : @param $name The QName of the index that is being checked.
 : @return true if the index is available and false otherwise.
 :)
declare function dctx:is-available-index($name as xs:QName) as xs:boolean external;

(:~
 : The function returns a sequence of QNames representing the indexes that are
 : available. The sequence will be empty if there are no indexes.
 :
 : @return A sequence of QNames, one for each available index, or an empty
 : sequence if none are.
 :)
declare function dctx:available-indexes() as xs:QName* external;

(:~
 : The function checks if an integrity constraint with the given QName is
 : activated.
 :
 : @param $name The QName of the constraint that is being checked.
 : @return true if the integrity constraint has is activated and false
 : otherwise.
 :)
declare function dctx:is-activated-integrity-constraint($name as xs:QName) as xs:boolean external;

(:~
 : The function returns a sequence of QNames representing the integrity 
 : constraints that are activated. The sequence will be empty if there are 
 : none.
 :
 : @return A sequence of QNames, one for each activated integrity constraint,
 : or an empty sequence if none are.
 :)
declare function dctx:activated-integrity-constraints() as xs:QName* external;
