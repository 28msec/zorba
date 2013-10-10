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
 : This modules defines a set of functions for managing indexes that are
 : declared in the prolog of a module.
 : <p/>
 : This module is part of
 : <a href="../zorba/xqddf.html">Zorba's XQuery Data Definition Facility</a>.
 : All the indexes managed by this module have to be pre-declared in the prolog
 : of a module.
 : Please refer to the
 : <a href="../zorba/data_lifecycle.html">general documentation</a>
 : for more information and examples.
 :
 : @see <a href="../zorba/data_lifecycle.html">Data Lifecycle</a>
 : @see <a href="../zorba/xqddf.html">XQuery Data Definition Facility</a>
 : @see http://zorba.io/modules/store/static/indexes/dml
 : @see http://zorba.io/modules/store/static/collections/dml
 : @see http://zorba.io/modules/store/static/collections/ddl
 : @see http://zorba.io/modules/store/static/integrity-constraints/ddl
 : @see http://zorba.io/modules/store/static/integrity-constraints/dml
 : @see http://zorba.io/errors
 :
 : @author Nicolae Brinza, Matthias Brantner, David Graf, Till Westmann, Markos Zaharioudakis
 : @project Zorba/Data Store/Indexes/Static Data Definition
 :)
module namespace iddl = "http://zorba.io/modules/store/static/indexes/ddl";

declare namespace zerr = "http://zorba.io/errors";
declare namespace ver = "http://zorba.io/options/versioning";
declare option ver:module-version "2.0";

(:===========================================================================:)

(:~
 : Gets the available indexes.
 :
 : @return A sequence of QNames, one for each available index, or an empty
 : sequence if none are.
 :)
declare function iddl:available-indexes()
  as xs:QName* external;

(:~
 : Creates an index.
 :
 : @param $name The name of the index to create.
 : @return An empty XDM instance and a pending update list that, once applied,
 : creates the index with the given name.
 :
 : @error zerr:ZDDY0021 if <code>$name</code> is not equal to the name of any
 : resource in the statically known indexes.
 : @error zerr:ZDDY0022 if an index with <code>$name</code> already exists.
 :)
declare updating function iddl:create( $name as xs:QName )
  external;

(:~
 : Gets a sequence of QNames representing the indexes that have been declared
 : in the prolog of the static context.
 :
 : @return A sequence of QNames, one for each created collection, or an emtpy
 : sequence.
 :)
declare function iddl:declared-indexes()
  as xs:QName* external;

(:~
 : Deletes an index.
 :
 : @param $name The name of the index to delete.
 : @return An empty XDM instance and a pending update list that, once applied,
 : deletes the index with the given name.
 : @error zerr:ZDDY0009 if the index does not exist.
 :)
declare updating function iddl:delete( $name as xs:QName )
  external;

(:~
 : Gets whether an index exists.
 :
 : @param $name The name of the index that is being checked.
 : @return true if the index is available; false otherwise.
 :)
declare function iddl:is-available-index( $name as xs:QName )
  as xs:boolean external;

(:~
 : Gets whether an index has been declared in the prolog of the static context.
 :
 : @param $name The name of the index that is being checked.
 : @return true if the index was declared; false otherwise.
 :)
declare function iddl:is-declared-index( $name as xs:QName )
  as xs:boolean external;

(:===========================================================================:)

(: vim:set et sw=2 ts=2: :)
