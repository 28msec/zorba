xquery version "3.0";
(:
 : Copyright 2011 The FLWOR Foundation.
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
 : This module contains functions to compile and evaluate XQuery
 : programs. Also, it contains function that allow to parameterize
 : the static or dynamic evaluation phase.
 :
 : @author Juan Zacarias
 : @project Zorba/Programming Languages/XQuery
 :)
module namespace xqxq = 'http://www.zorba-xquery.com/modules/xqxq';

declare namespace an = "http://www.zorba-xquery.com/annotations";
declare namespace ver = "http://www.zorba-xquery.com/options/versioning";
declare namespace op = "http://www.zorba-xquery.com/options/features";
declare namespace f = "http://www.zorba-xquery.com/features";

declare option ver:module-version "1.0";
declare option op:enable "f:hof";

(:~
 : The function prepares a given XQuery program for execution.
 : If the program was successfully compiled, the function returns an
 : identifier as xs:anyURI. This URI can be passed to other functions
 : of this module (e.g. to actually evaluate the program). The URI
 : is opaque and its lilfetime is bound by the lifetime of the XQuery
 : program that invoked this function. Further reference or uses
 : of the identifier lead to unexpected results.
 :
 : Successfully prepared queries need to be deleted by passing the resulting
 : identifier to the xqxq:delete-query function of this module.
 :
 : @param $main-module-text the XQuery program that should be prepared.
 :   The program needs to be a XQuery main module.
 :
 : @return an identifier for the compiled program that can be passed
 :   as arguments to other functions of this module.
 :
 : @error any (static or type) error that may be raised during the compilation
 : of the query. For example, err:XPST0003 if the given XQuery program could
 : not be parsed.
 :)
declare %an:sequential function xqxq:prepare-main-module($main-module-text as xs:string) as 
  xs:anyURI external;

(:~
 : The function prepares a given XQuery program for execution.
 : If the program was successfully compiled, the function returns an
 : identifier as xs:anyURI. This URI can be passed to other functions
 : of this module (e.g. to actually evaluate the program). The URI
 : is opaque and its lilfetime is bound by the lifetime of the XQuery
 : program that invoked this function. Further reference or uses
 : of the identifier lead to unexpected results.
 : 
 : Important notes regarding the second and third parameters of the function:
 : --------------------------------------------------------------------------
 :
 : These parameters allow you to specify a URL resolver and a URI mapper
 : for Zorba to use when executing this query. See
 : http://www.zorba-xquery.com/html/documentation/2.7.0/zorba/uriresolvers
 :
 : The second parameter is a function item for a URL
 : resolver. The URL resolver function must recive 2 parameters:
 :   A $namespace as xs:string that will contain the url to be resolved.
 :   A $entity as xs:string that will contain the type of resolving needed;
 :   this can be 2 values "module" and "schema".
 : The function must return an empty sequence when the specified $namespace
 : or $entity are not the ones to be resolved.
 :
 : Example:
 :   
 : declare function mymod:url-resolver($namespace as xs:string, $entity as xs:string)
 : {
 :  if($namespace = 'http://test.xq')
 :  then "module namespace test = 'http://test'; declare function test:foo(){'foo'};"
 :  else ()
 : };
 :
 : The URL resolver function's namespace, name, and parameter naming are
 : not restricted by XQXQ.
 :
 : The URL resolver function's return type is not restricted, it could be a string, a sequence,
 : a node, etc. All the outputs types are to be serialized as a string.
 :
 : The third parameter is a function item for a URI mapper.
 : The URI mapper function, just like the URL resolver, receives 2 parameters:
 :   A $namespace as xs:string that will contain the URI to be mapped.
 :   A $entity as xs:string that will contain the type of resolving needed;
 :   this can be 2 values "module" and "schema".
 : The URI mapper must return an empty sequence when the specified $namesapce or $entity
 : are not to be mapped. Unlike the URL resolver this function must return a sequence of strings.
 :
 : Example:
 :
 : declare function mymod:uri-mapper($namespace as xs:string, $entity as xs:string)
 : {
 :  if($namespace = 'http://test')
 :  then ("http://www.zorba-xquery.com/test", "http://foo.com/schema/test")
 :  else ()
 : };
 :
 : The URI mapper function's namespace, name, and parameter naming are
 : not restricted by XQXQ.
 :
 : In order to pass the above URL resolver and URI mapper to this function,
 : use the following syntax:
 :
 :   variable $queryID := xqxq:prepare-main-module("..query text..",
 :      mymod:url-resolver#2, mymod:uri-mapper#2);
 :
 : That is, the QName of the function followed by "#2". This is XQuery
 : "higher-order function" syntax, meaning the function with the specified
 : QName which takes two arguments. Since URL resolvers and URI mappers
 : must take two arguments, both will always be specified with "#2".
 :
 : Note that parameters 2 and 3 should be declared as follows:
 :    as function($url as xs:string, $entity as xs:string) as item()
 :    as function($uri as xs:string, $entity as xs:string) as xs:string*
 : However Zorba's implementation of higher-order functions (HOF) is not
 : yet complete enough to allow for this. When Zorba's HOF implementation
 : is complete this function signature will be changed.
 :
 : Both the URL resolver and URI mapper functions are optional, meaning you
 : may pass the empty-sequence () for either.
 :
 : Successfully prepared queries need to be deleted by passing the resulting
 : identifier to the xqxq:delete-query function of this module.
 :
 : @param $main-module-text the XQuery program that should be prepared.
 :   The program needs to be a XQuery main module.
 :
 : @param $resolver the URL resolver function.
 : 
 : @param $mapper the URI mapper function.
 :
 : @return an identifier for the compiled program that can be passed
 :   as arguments to other functions of this module.
 :
 : @error any (static or type) error that may be raised during the compilation
 : of the query. For example, err:XPST0003 if the given XQuery program could
 : not be parsed.
 :)
declare %an:sequential function xqxq:prepare-main-module($main-module-text as xs:string, $resolver as item()?, $mapper as item()?) as 
  xs:anyURI external;

(:~
 : This function compiles a given XQuery library module. It can be used
 : to compile-check a module. 
 :
 : @param $library-module-text the XQuery library module that should
 :  be prepared. 
 :
 : @return the function is declared as sequential.It returns the
 :  empty-sequence.
 :
 : @error any (static or type) error that may be raised during the compilation
 : of the library module. For example, err:XPST0003 if the given XQuery library
 : module could not be parsed.
 :)
declare %an:sequential function xqxq:prepare-library-module($library-module-text as xs:string) as 
  empty-sequence() external ;

(:~
 : The function tests if the context-item is bound for the
 : execution of the query referred to by the given query identifier.
 :
 : @param $query-key the identifier for a compiled query
 :
 : @return true if the context-item is bound, false otherwise.
 :
 : @error xqxq:NoQueryMatch if no query with the given identifier
 :   was prepared.
 :)
declare function xqxq:is-bound-context-item($query-key as xs:anyURI) 
  as xs:boolean  external;
  

(:~
 : The function tests if the given variable is bound for the
 : execution of the query referred to by the given query identifier.
 :
 : @param $query-key the identifier for a compiled query
 : @param $var-name the name of the variable
 :
 : @return true if the variable is bound, false otherwise.
 :
 : @error xqxq:NoQueryMatch if no query with the given identifier
 :   was prepared.
 : @error xqxq:UndeclaredVariable if the given variable is not declared
 :   in the query.
 :)
declare function xqxq:is-bound-variable($query-key as xs:anyURI, $var-name as 
  xs:QName) as xs:boolean  external;

(:~
 : The function returns the names of the external variables that
 : are declared in the given query (either in the main module or
 : in any of the imported library modules).
 :
 : @param $query-key the identifier for a compiled query
 :
 : @return the sequence of names of the said external variables.
 :
 : @error xqxq:NoQueryMatch if no query with the given identifier
 :   was prepared.
 :)
declare function xqxq:external-variables($query-key as xs:anyURI) as
  xs:QName* external ;
  
(:~
 : The function tests if the query identified by the given key
 : is an updating query.
 :
 : @param $query-key the identifier for a compiled query
 :
 : @return true if the query is an updating query, false otherwise.
 :
 : @error xqxq:NoQueryMatch if no query with the given identifier
 :   was prepared.
 :)
declare function xqxq:is-updating($query-key as xs:anyURI) as
  xs:boolean external;  

(:~
 : The function tests if the query identified by the given key
 : is sequential query.
 :
 : @param $query-key the identifier for a compiled query
 :
 : @return true if the query is a sequential, false otherwise.
 :
 : @error xqxq:NoQueryMatch if no query with the given identifier
 :   was prepared.
 :)
declare function xqxq:is-sequential($query-key as xs:anyURI) as
  xs:boolean external;
  
(:~
 : This function binds the context-item of the prepared query
 : identified by the given key to the $dot argument.
 :
 : @param $query-key the identifier for a compiled query
 : @param $dot the context item to bind
 :
 : @return the function has side effects and returns the empty
 :   sequence.
 :
 : @error xqxq:NoQueryMatch if no query with the given identifier
 :   was prepared.
 :)
declare %an:sequential function xqxq:bind-context-item($query-key as xs:anyURI,
  $dot as item()) as empty-sequence() external ;

(:~
 : This function binds the variable with name $name of
 : the prepared query identified by $query-key to the given sequence.
 :
 : @param $query-key the identifier for a compiled query
 : @param $name the name of the external variable to bind
 : @param $value the sequence to which the external variable $name
 :  should be bound
 :
 : @return the function has side effects and returns the empty
 :   sequence.
 :
 : @error xqxq:NoQueryMatch if no query with the given identifier
 :   was prepared.
 : @error xqxq:UndeclaredVariable if the given variable is not declared
 :   in the query.
 :)
declare %an:sequential function xqxq:bind-variable($query-key as xs:anyURI,
  $var as xs:QName, $value as item()*) as empty-sequence() external ;


(:~
 : Evaluates the given prepared query and returns the result
 : of the evaluation. The query must not be sequential or
 : updating.
 :
 : @param $query-key the identifier for a compiled query
 :
 : @return the result of evaluating the given query
 :
 : @error xqxq:NoQueryMatch if no query with the given identifier
 :   was prepared.
 :
 : @error xqxq:QueryIsUpdating if the query is an updating query.
 :
 : @error xqxq:QueryIsSequential if the query is sequential.
 :
 : @error any dynamic error that is raised by evaluating the
 :   given query.
 :
 :)
declare function xqxq:evaluate($query-key as xs:anyURI) as item()* external;

(:~
 : Evaluates the given prepared query and applies the updates
 : computed by this query. The query must be an updating query.
 :
 : @param $query-key the identifier for a compiled query
 :
 : @return the function has side effects because it applies
 :  the updates of the query. It returns the empty sequence.
 :
 : @error xqxq:NoQueryMatch if no query with the given identifier
 :   was prepared.
 :
 : @error xqxq:QueryNotUpdating if the query is not an updating query.
 :
 : @error xqxq:QueryIsSequential if the query is sequential.
 :
 : @error any dynamic error that is raised by evaluating the
 :   given query or applying its updates.
 :
 :)
declare updating function xqxq:evaluate-updating($query-key as xs:anyURI) external;

(:~ 
 : Evaluates the given prepared query and returns the result
 : of the evaluation. The query must be sequential.
 :
 : @param $query-key the identifier for a compiled query
 :
 : @return the result of evaluating the query.
 :
 : @error xqxq:NoQueryMatch if no query with the given identifier
 :   was prepared.
 :
 : @error xqxq:QueryNotSequential if the query is not sequential.
 :
 : @error xqxq:QueryIsUpdating if the query is an updating query.
 :
 : @error any dynamic error that is raised by evaluating the
 :   given query.
 :
 :)
declare %an:sequential function xqxq:evaluate-sequential($query-key as
  xs:string) as item()* external;
  
(:~ 
 : Deletes the prepared query associated with the given identifier.
 : After the query is deleted, the corresponding identifier should
 : not be used as argument to any of the functions of this module.
 :
 : @param $query-key the identifier for a compiled query
 :
 : @return the function has side effects and returns the empty sequence.
 :
 : @error xqxq:NoQueryMatch if no query with the given identifier
 :   was prepared.
 :
 :)
declare %an:sequential function xqxq:delete-query($query-key as xs:anyURI) as
  empty-sequence() external;


(:~
 : Internal helper function. Only necessary because of incomplete HOF
 : support in Zorba.
 :)
declare %private function xqxq:hof-invoker($hof as item(),
  $ns as xs:string, $entity as xs:string) as item()*
{
   $hof($ns, $entity)
};
