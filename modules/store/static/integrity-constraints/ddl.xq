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
 : This module defines a set of functions to manage integrity constraints
 : that are declared in the prolog of a module.
 : For example, it provides functions to activate or deactivate integrity
 : constraints.
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
 : @see http://zorba.io/modules/store/static/collections/dml
 : @see http://zorba.io/modules/store/static/collections/ddl
 : @see http://zorba.io/modules/store/static/indexes/ddl
 : @see http://zorba.io/modules/store/static/indexes/dml
 : @see http://zorba.io/modules/store/static/integrity-constraints/dml
 : @see http://zorba.io/errors
 :
 : @author Nicolae Brinza, Matthias Brantner, David Graf, Till Westmann, Markos Zaharioudakis
 : @project Zorba/Data Store/Integrity Constraints/Static Data Definition
 :)
module namespace icddl = "http://zorba.io/modules/store/static/integrity-constraints/ddl";

declare namespace zerr = "http://zorba.io/errors";
declare namespace ver = "http://zorba.io/options/versioning";
declare option ver:module-version "2.0";

(:===========================================================================:)

(:~
 : Activates an integrity constraint in the dynamic context.
 :
 : @param $name The name of the integrity constraint to activate.
 : @return An empty XDM instance and a pending update list that consists of a
 : <code>upd:activateIntegrityConstraint($name)</code> update primitive.
 : @error zerr:ZDDY0031 if the integrity constraint does not exist in the
 : static context.
 :)
declare updating function icddl:activate( $name as xs:QName )
  external;

(:~
 : Gets the integrity constraints that are activated, if any.
 : @return A sequence of QNames, one for each activated integrity constraint,
 : or an empty sequence if none.
 :)
declare function icddl:activated-integrity-constraints()
  as xs:QName* external;

(:~
 : Deactivates the integrity constraint.
 :
 : @param $name The name of the integrity constraint to deactivate.
 : @return An empty XDM instance and a pending update list that, once applied,
 : deactivates the integrity constraint.
 : @error zerr:ZDDY0032 if the integrity constraint was not declared in the the
 : static context.
 : @error zerr:ZDDY0032 if the integrity constraints is not activated.
 :)
declare updating function icddl:deactivate( $name as xs:QName )
  external;

(:~
 : Gets whether an integrity constraints is activated.
 :
 : @param $name The name of the constraint to check.
 : @return true if the integrity constraint is activated; false otherwise.
 :)
declare function icddl:is-activated-integrity-constraint( $name as xs:QName )
  as xs:boolean external;

(:~
 : Gets whether an integrity constraint is declared in the prolog of the static
 : context.
 :
 : @param $name The name of the constraint to check.
 : @return true if the constraint is declared; false otherwise.
 :)
declare function icddl:is-declared-integrity-constraint( $name as xs:QName )
  as xs:boolean external;

(:~
 : Gets the sequence of QNames representing the integrity constraints that have
 : been declared in the prolog of the static context.
 :
 : @return A sequence of QNames, one for each created integrity constraints, or
 : an emtpy sequence if none.
 :)
declare function icddl:declared-integrity-constraints()
  as xs:QName* external;

(:===========================================================================:)

(: vim:set et sw=2 ts=2: :)
