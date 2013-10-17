xquery version "3.0";

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
 : This module defines a function to check if an integrity constraint is
 : satisfied.
 : The integrity constraint needs to be declared in the prolog of a module.
 : <p/>
 : This module is part of
 : <a href="../zorba/xqddf.html">Zorba's XQuery Data Definition Facility</a>.
 : All the integrity constraints managed by this module have to be pre-declared
 : in the prolog of a module.
 : Please refer to the
 : <a href="../zorba/data_lifecycle.html">general documentation</a>
 : for more information and examples.
 :
 : @see <a href="../zorba/data_lifecycle.html">Data Lifecycle</a>
 : @see <a href="../zorba/xqddf.html">XQuery Data Definition Facility</a>
 : @see http://zorba.io/modules/store/static/integrity-constraints/dml
 : @see http://zorba.io/modules/store/static/collections/dml
 : @see http://zorba.io/modules/store/static/collections/ddl
 : @see http://zorba.io/modules/store/static/indexes/ddl
 : @see http://zorba.io/modules/store/static/indexes/dml
 : @see http://zorba.io/errors
 :
 : @author Nicolae Brinza, Matthias Brantner, David Graf, Till Westmann, Markos Zaharioudakis
 : @project Zorba/Data Store/Integrity Constraints/Static Data Manipulation
 :)
module namespace icdml = "http://zorba.io/modules/store/static/integrity-constraints/dml";

declare namespace zerr = "http://zorba.io/errors";
declare namespace ver = "http://zorba.io/options/versioning";
declare option ver:module-version "2.0";

(:===========================================================================:)

(:~
 : Checks if the specified constraints are valid in the database.
 :
 : @param $name The name of the integrity constraint to check.
 : @return true if the constraints are valid; false otherwise.
 : @error zerr:ZDDY0031 if the integrity constraint is not declared.
 : @error zerr:ZDDY0032 if the integrity constraint is not available.
 :)
declare function icdml:check-integrity-constraint( $name as xs:QName )
  as xs:boolean external;

(:===========================================================================:)

(: vim:set et sw=2 ts=2: :)
