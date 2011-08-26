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
 : This module defines a function to check if an integrity constraint is satisfied.
 : The integrity constraint needs to be declared in the prolog of a module.
 :
 : <p>This module is part of <a href="../../html/xqddf.html">Zorba's XQuery Data
 : Definition Facility</a>. All the integrity constraints managed by this module
 : have to be pre-declared in the prolog of a module. Please refer to the
 : <a href="../../html/data_lifecycle.html">general documentation</a>
 : for more information and examples.</p>
 :
 : @see <a href="../../html/data_lifecycle.html">Data Lifecycle</a>
 : @see <a href="../../html/xqddf.html">XQuery Data Definition Facility</a>
 : @see http://www.zorba-xquery.com/modules/store/static/integrity_constraints/dml
 : @see http://www.zorba-xquery.com/modules/store/static/collections/dml
 : @see http://www.zorba-xquery.com/modules/store/static/collections/ddl
 : @see http://www.zorba-xquery.com/modules/store/static/indexes/ddl
 : @see http://www.zorba-xquery.com/modules/store/static/indexes/dml
 : @see <a href="www.zorba-xquery.com_errors.html">http://www.zorba-xquery.com/errors</a>
 :
 : @author Nicolae Brinza, Matthias Brantner, David Graf, Till Westmann, Markos Zaharioudakis
 : @project store/integrity constraints/static
 :
 :)
module namespace icdml = "http://www.zorba-xquery.com/modules/store/static/integrity_constraints/dml";

declare namespace zerr = "http://www.zorba-xquery.com/errors";
declare namespace ver = "http://www.zorba-xquery.com/options/versioning";
declare option ver:module-version "2.0";

(:~
 : The check-integrity-constraint function checks if the constraints
 : specified by the expanded QName $name is valid in the database.
 :
 : @param $name The QName of the integrity constraint to check.
 :
 : @return true if the constraints are valid in the database, false otherwise.
 :
 : @error zerr:ZDDY0031 if the integrity constraint identified by $name is not declared.
 : @error zerr:ZDDY0032 if the integrity constraint identified by $name is not available.
 :)
declare function icdml:check-integrity-constraint(
  $name as xs:QName) as xs:boolean external;
