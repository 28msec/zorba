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
 : This module defines a set of functions to deal with integrity constraints.
 : For example, it provides functions to activate or deactivate integrity constraints.
 :
 : @see http://www.zorba-xquery.com/modules/store/static/collections/ddl
 : @see http://www.zorba-xquery.com/modules/store/static/collections/dml
 :
 : @author Nicolae Brinza, Matthias Brantner, David Graf, Till Westmann, Markos Zaharioudakis
 : @project store/integrity constraints/static
 :
 :
 :)
module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/integrity_constraints/ddl";

declare namespace ver = "http://www.zorba-xquery.com/options/versioning";
declare option ver:module-version "2.0";

(:~
 : The function returns true if an integrity constraints with the given
 : QName is activated.
 :
 : @param $name The QName of the constraint that is being checked.
 :
 : @return true if the integrity constraint has is activated and false otherwise.
 :)
declare function ddl:is-activated-integrity-constraint(
  $name as xs:QName) as xs:boolean external;

(:~
 : The function returns a sequence of QNames representing the integrity 
 : constraints that are activated. The sequence will be empty if there are 
 : none.
 :
 : @return A sequence of QNames, one for each activated integrity constraint,
 :         or an empty sequence.
 :)
declare function ddl:activated-integrity-constraints() as xs:QName*  external;


(:~
 : The activate-integrity-constraint function is an updating function
 : that activates the integrity constraint identified by the expanded QName
 : $name in the dynamic context.
 :
 : @param $name The QName of the integrity constraint to activate.
 : @return The result of the function is an empty XDM instance and a
 :         pending update list that consists of a
 :         upd:activateIntegrityConstraint($name) update primitive.
 :
 : @error ZDDY0031 if available integrity constraints in the static context
 :        does not provide a mapping for the expanded QName $name.
 :)
declare updating function ddl:activate-integrity-constraint(
  $name as xs:QName)  external;

(:~
 : The deactivate-integrity-constraint function is an updating function that
 : deactivates the integrity constraint with the given QName.
 :
 : @param $name The QName of the integrity constraint to deactivate.
 :
 : @return The result of the function is an empty XDM instance and a
 :         pending update list which, once applied, deactivates the
 :         integrity constraint.
 :
 : @error ZDDY0032 if the integrity constraints is not declared in the
 :        the static context.
 : @error ZDDY0032 if the given integrity constraints is not activated.
 :)
declare updating function ddl:deactivate-integrity-constraint(
  $name as xs:QName)  external;

(:~
 : The function returns a sequence of QNames representing the integrity
 : constraints that have been declared in the prolog of the static context.
 :
 : @return A sequence of QNames, one for each created integrity constraints, or an emtpy sequence.
 :)
declare function ddl:declared-integrity-constraints() as xs:QName*  external;

(:~
 : The function returns true if a integrity constraints with the given
 : QName is declared in the prolog of the static context.
 :
 : @param $name The QName of the constraint that is being checked.
 :
 : @return true if the constraint is declared and false otherwise.
 :)
declare function ddl:is-declared-integrity-constraint(
  $name as xs:QName) as xs:boolean  external;
