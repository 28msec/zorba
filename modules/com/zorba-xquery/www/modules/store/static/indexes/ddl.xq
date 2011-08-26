xquery version "3.0";

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
 : This modules defines a set of functions for managing indexes which are
 : declared in the prolog of a module.
 :
 : <p>This module is part of <a href="../../html/xqddf.html">Zorba's XQuery Data
 : Definition Facility</a>. All the indexes managed by this module
 : have to be pre-declared in the prolog of a module. Please refer to the
 : <a href="../../html/data_lifecycle.html">general documentation</a>
 : for more information and examples.</p>
 :
 : @see <a href="../../html/data_lifecycle.html">Data Lifecycle</a>
 : @see <a href="../../html/xqddf.html">XQuery Data Definition Facility</a>
 : @see http://www.zorba-xquery.com/modules/store/static/indexes/dml
 : @see http://www.zorba-xquery.com/modules/store/static/collections/dml
 : @see http://www.zorba-xquery.com/modules/store/static/collections/ddl
 : @see http://www.zorba-xquery.com/modules/store/static/integrity_constraints/ddl
 : @see http://www.zorba-xquery.com/modules/store/static/integrity_constraints/dml
 : @see <a href="www.zorba-xquery.com_errors.html">http://www.zorba-xquery.com/errors</a>
 :
 : @author Nicolae Brinza, Matthias Brantner, David Graf, Till Westmann, Markos Zaharioudakis
 :
 : @project store/indexes/static
 :
 :)
module namespace iddl = "http://www.zorba-xquery.com/modules/store/static/indexes/ddl";

declare namespace zerr = "http://www.zorba-xquery.com/errors";
declare namespace ver = "http://www.zorba-xquery.com/options/versioning";
declare option ver:module-version "2.0";

(:~
 : The function returns true if an index with the given QName is available.
 : (i.e. has been created).
 :
 : @param $name The QName of the index that is being checked.
 :
 : @return true if the index is available and false otherwise.
 :)
declare function iddl:is-available-index($name as xs:QName) as xs:boolean external;

(:~
 : The function returns a sequence of QNames representing the indexes that are
 : available. The sequence will be empty if there are no indexes.
 :
 : @return A sequence of QNames, one for each available index, or an empty
 : sequence if none are.
 :)
declare function iddl:available-indexes() as xs:QName* external;

(:~
 : The create function is an updating function which creates the
 : index with the given expanded QName and populates the index with its
 : values.
 :
 : @param $name The QName of the index to create.
 :
 : @return The result of the function is an empty XDM instance and a pending
 :         update list which, once applied, creates the index with the given
 :         name.
 :
 : @error zerr:ZDDY0021 if the expanded QName of $name is not equal  
 :        to the name of any resource in the statically known indexes.
 : @error zerr:ZDDY0022 if the index with the given name is already created.
 :)
declare updating function iddl:create(
  $name as xs:QName)  external;

(:~
 : The delete function is an updating function that deletes
 : the index with the given expanded QName.
 :
 : @param $name The QName of the index to delete.
 :
 : @return The result of the function is an empty XDM instance and a pending
 :         update list which, once applied, deletes the index with the given name.
 :
 : @error zerr:ZDDY0009 If available indexes does not provide a mapping for
 :        the expanded QName $name.
 :
 :)
declare updating function iddl:delete(
  $name as xs:QName)  external;

(:~
 : The function returns true if a index with the given
 : QName is declared in the prolog of the static context.
 :
 : @param $name The QName of the index that is being checked.
 :
 : @return true if the index is declared or false otherwise.
 :)
declare function iddl:is-declared-index(
  $name as xs:QName) as xs:boolean  external;

(:~
 : The function returns a sequence of QNames representing the indexes that have
 : been declared in the prolog of the static context.
 :
 : @return A sequence of QNames, one for each created collection, or an emtpy sequence.
 :)
declare function iddl:declared-indexes() as xs:QName*  external;
