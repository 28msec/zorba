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
 : This module contains functions to compile and evaluate queries
 : written in either JSONiq or XQuery. Also, it contains function that
 : allow to parameterize the static or dynamic evaluation phase.
 :
 : @author Juan Zacarias
 : @project Zorba/Programming Languages/ZQ
 :)
module namespace zq = 'http://zorba.io/modules/zorba-query';

declare namespace an = "http://zorba.io/annotations";
declare namespace ver = "http://zorba.io/options/versioning";
declare namespace op = "http://zorba.io/options/features";
declare namespace f = "http://zorba.io/features";

declare option ver:module-version "1.0";

(:~
 : <p>The function prepares a given a query for execution.</p>
 : <p>If the query was successfully compiled, the function returns an
 : identifier as xs:anyURI. This URI can be passed to other functions
 : of this module (e.g. to actually evaluate the query). The URI
 : is opaque and its lifetime is bound by the lifetime of the query
 : that invoked this function. Further reference or uses
 : of the identifier lead to unexpected results.</p>
 : <p/>
 : <p>Successfully prepared queries need to be deleted by passing the resulting
 : identifier to the zq:delete-query function of this module.</p>
 :
 : @param $main-module-text the query that should be prepared.
 :   The query needs to be a XQuery or JSONiq main module.
 :
 : @return an identifier for the compiled query that can be passed
 :   as arguments to other functions of this module.
 :
 : @error any (static or type) error that may be raised during the compilation
 : of the query. For example, err:XPST0003 if the given query could
 : not be parsed.
 :)
declare %an:sequential function zq:prepare-main-module($main-module-text as xs:string) as 
  xs:anyURI external;

(:~
 : <p>The function prepares a given query for execution.</p>
 : <p>If the query was successfully compiled, the function returns an
 : identifier as xs:anyURI. This URI can be passed to other functions
 : of this module (e.g. to actually evaluate the query). The URI
 : is opaque and its lifetime is bound by the lifetime of the query
 : that invoked this function. Further reference or uses
 : of the identifier lead to unexpected results.</p>
 : <p/>
 : <p>Important notes regarding the second and third parameters of the function:</p>
 : <p>--------------------------------------------------------------------------</p>
 : <p/>
 : <p>These parameters allow you to specify a URL resolver and a URI mapper
 : for Zorba to use when executing this query. See
 : <a href="http://www.zorba-xquery.com/html/documentation/2.7.0/zorba/uriresolvers">here</a></p>
 : <p/>
 : <ul>The second parameter is a function item for a URL
 : resolver. The URL resolver function must recive 2 parameters:
 : <li>A $namespace as xs:string that will contain the url to be resolved.</li>
 : <li>A $entity as xs:string that will contain the type of resolving needed.
 :   This can be one of two values: "module" or "schema".</li>
 : </ul>
 : <p>The function must return the empty sequence when the specified $namespace
 : or $entity are not the ones to be resolved.</p>
 : <p/>
 : <p>Example:</p>
 : <p/>  
 : <pre class="ace-static" ace-mode="xquery">declare function mymod:url-resolver($namespace as xs:string, $entity as xs:string) as item()?
 : {
 :  if($namespace = 'http://test.xq')
 :  then "module namespace test = 'http://test'; declare function test:foo(){'foo'};"
 :  else ()
 : };</pre>
 : <p/>
 : <p>The URL resolver function's namespace, name, and parameter naming are
 : not restricted by ZQ.</p>
 : <p/>
 : <p>The URL resolver function's return type is not restricted, it could be a string, a sequence,
 : a node, etc. All the outputs types are to be serialized as a string.</p>
 : <p/>
 : <p>The third parameter is a function item for a URI mapper.</p>
 : <ul>The URI mapper function, just like the URL resolver, receives 2 parameters:
 : <li>A $namespace as xs:string that will contain the URI to be mapped.</li>
 : <li>A $entity as xs:string that will contain the type of resolving needed.
 :   This can be one of two values: "module" or "schema".</li>
 : </ul>
 : <p>The URI mapper must return an empty sequence when the specified $namesapce or $entity
 : are not to be mapped. Unlike the URL resolver this function must return a sequence of strings.</p>
 : <p/>
 : <p>Example:</p>
 : <p/>
 : <pre class="ace-static" ace-mode="xquery">declare function mymod:uri-mapper($namespace as xs:string, $entity as xs:string)
 : {
 :  if($namespace = 'http://test')
 :  then ("http://zorba.io/test", "http://foo.com/schema/test")
 :  else ()
 : };</pre>
 : <p/>
 : <p>The URI mapper function's namespace, name, and parameter naming are
 : not restricted by ZQ.</p>
 : <p/>
 : <p>In order to pass the above URL resolver and URI mapper to this function,
 : use the following syntax:</p>
 : <p/>
 :   <pre class="ace-static" ace-mode="xquery">variable $queryID := zq:prepare-main-module("..query text..",
 :      mymod:url-resolver#2, mymod:uri-mapper#2);</pre>
 : <p/>
 : <p>That is, the QName of the function followed by "#2". This is XQuery
 : "higher-order function" syntax, meaning the function with the specified
 : QName which takes two arguments. Since URL resolvers and URI mappers
 : must take two arguments, both will always be specified with "#2".</p>
 : <p/>
 : <p>Both the URL resolver and URI mapper functions are optional, meaning you
 : may pass the empty-sequence () for either.</p>
 : <p/>
 : <p>Successfully prepared queries need to be deleted by passing the resulting
 : identifier to the zq:delete-query function of this module.</p>
 :
 : @param $main-module-text the query that should be prepared.
 :   The query needs to be a XQuery or JSONiq main module.
 :
 : @param $resolver the URL resolver function.
 : 
 : @param $mapper the URI mapper function.
 :
 : @return an identifier for the compiled query that can be passed
 :   as arguments to other functions of this module.
 :
 : @error any (static or type) error that may be raised during the compilation
 : of the query. For example, err:XPST0003 if the given query could
 : not be parsed.
 :)
declare %an:sequential function zq:prepare-main-module(
  $main-module-text as xs:string,
  $resolver as ( function(xs:string, xs:string) as item()? )?,
  $mapper as ( function(xs:string, xs:string) as xs:string* )? ) as 
    xs:anyURI external;

(:~
 : <p>This function compiles a given XQuery or JSONiq library module.
 : It can be used to compile-check a module.</p> 
 :
 : @param $library-module-text the library module that should
 :  be prepared. 
 :
 : @return the empty-sequence.
 :
 : @error any (static or type) error that may be raised during the compilation
 : of the library module. For example, err:XPST0003 if the given library
 : module could not be parsed.
 :)
declare %an:sequential function zq:prepare-library-module($library-module-text as xs:string) as 
  empty-sequence() external ;

(:~
 : <p>The function tests if the context-item is bound for the
 : execution of the query referred to by the given query identifier.</p>
 :
 : @param $query-key the identifier for a compiled query
 :
 : @return true if the context-item is bound, false otherwise.
 :
 : @error zq:NO_QUERY_MATCH if no query with the given identifier
 :   was prepared.
 :)
declare function zq:is-bound-context-item($query-key as xs:anyURI) 
  as xs:boolean  external;
  

(:~
 : <p>The function tests if the given variable is bound for the
 : execution of the query referred to by the given query identifier.</p>
 :
 : @param $query-key the identifier for a compiled query
 : @param $var-name the name of the variable
 :
 : @return true if the variable is bound, false otherwise.
 :
 : @error zq:NO_QUERY_MATCH if no query with the given identifier
 :   was prepared.
 : @error zq:UNDECLARED_VARIABLE if the given variable is not declared
 :   in the query.
 :)
declare function zq:is-bound-variable($query-key as xs:anyURI, $var-name as 
  xs:QName) as xs:boolean  external;

(:~
 : <p>The function returns the names of the external variables that
 : are declared in the given query (either in the main module or
 : in any of the imported library modules).</p>
 :
 : @param $query-key the identifier for a compiled query
 :
 : @return the sequence of names of the said external variables.
 :
 : @error zq:NO_QUERY_MATCH if no query with the given identifier
 :   was prepared.
 :)
declare function zq:external-variables($query-key as xs:anyURI) as
  xs:QName* external ;
  
(:~
 : <p>The function tests if the query identified by the given key
 : is an updating query.</p>
 :
 : @param $query-key the identifier for a compiled query
 :
 : @return true if the query is an updating query, false otherwise.
 :
 : @error zq:NO_QUERY_MATCH if no query with the given identifier
 :   was prepared.
 :)
declare function zq:is-updating($query-key as xs:anyURI) as
  xs:boolean external;  

(:~
 : <p>The function tests if the query identified by the given key
 : is sequential query.</p>
 :
 : @param $query-key the identifier for a compiled query
 :
 : @return true if the query is a sequential, false otherwise.
 :
 : @error zq:NO_QUERY_MATCH if no query with the given identifier
 :   was prepared.
 :)
declare function zq:is-sequential($query-key as xs:anyURI) as
  xs:boolean external;
  
(:~
 : <p>This function binds the context-item of the prepared query
 : identified by the given key to the $dot argument.</p>
 :
 : @param $query-key the identifier for a compiled query
 : @param $dot the context item to bind
 :
 : @return the function has side effects and returns the empty
 :   sequence.
 :
 : @error zq:NO_QUERY_MATCH if no query with the given identifier
 :   was prepared.
 :)
declare %an:sequential function zq:bind-context-item($query-key as xs:anyURI,
  $dot as item()) as empty-sequence() external ;

(:~
 : <p>This function binds the variable with name $name of
 : the prepared query identified by $query-key to the given sequence.</p>
 :
 : @param $query-key the identifier for a compiled query
 : @param $name the name of the external variable to bind
 : @param $value the sequence to which the external variable $name
 :  should be bound
 :
 : @return the function has side effects and returns the empty
 :   sequence.
 :
 : @error zq:NO_QUERY_MATCH if no query with the given identifier
 :   was prepared.
 : @error zq:UNDECLARED_VARIABLE if the given variable is not declared
 :   in the query.
 :)
declare %an:sequential function zq:bind-variable($query-key as xs:anyURI,
  $var as xs:QName, $value as item()*) as empty-sequence() external ;


(:~
 : <p>Evaluates the given prepared query and returns the result
 : of the evaluation. The query must not be sequential or
 : updating.</p>
 :
 : @param $query-key the identifier for a compiled query
 :
 : @return the result of evaluating the given query
 :
 : @error zq:NO_QUERY_MATCH if no query with the given identifier
 :   was prepared.
 :
 : @error zq:QUERY_IS_UPDATING if the query is an updating query.
 :
 : @error zq:QUERY_IS_SEQUENTIAL if the query is sequential.
 :
 : @error any dynamic error that is raised by evaluating the
 :   given query.
 :
 :)
declare function zq:evaluate($query-key as xs:anyURI) as item()* external;

(:~
 : <p>Evaluates the given prepared query and applies the updates
 : computed by this query. The query must be an updating query.</p>
 :
 : @param $query-key the identifier for a compiled query
 :
 : @return the function has side effects because it applies
 :  the updates of the query. It returns the empty sequence.
 :
 : @error zq:NO_QUERY_MATCH if no query with the given identifier
 :   was prepared.
 :
 : @error zq:QUERY_NOT_UPDATING if the query is not an updating query.
 :
 : @error zq:QUERY_IS_SEQUENTIAL if the query is sequential.
 :
 : @error any dynamic error that is raised by evaluating the
 :   given query or applying its updates.
 :
 :)
declare updating function zq:evaluate-updating($query-key as xs:anyURI) external;

(:~ 
 : <p>Evaluates the given prepared query and returns the result
 : of the evaluation. The query must be sequential.</p>
 :
 : @param $query-key the identifier for a compiled query
 :
 : @return the result of evaluating the query.
 :
 : @error zq:NO_QUERY_MATCH if no query with the given identifier
 :   was prepared.
 :
 : @error zq:QUERY_NOT_SEQUENTIAL if the query is not sequential.
 :
 : @error zq:QUERY_IS_UPDATING if the query is an updating query.
 :
 : @error any dynamic error that is raised by evaluating the
 :   given query.
 :
 :)
declare %an:sequential function zq:evaluate-sequential($query-key as
  xs:string) as item()* external;
  
(:~ 
 : <p>Deletes the prepared query associated with the given identifier.</p>
 : <p>After the query is deleted, the corresponding identifier should
 : not be used as argument to any of the functions of this module.</p>
 :
 : @param $query-key the identifier for a compiled query
 :
 : @return the function has side effects and returns the empty sequence.
 :
 : @error zq:NO_QUERY_MATCH if no query with the given identifier
 :   was prepared.
 :
 :)
declare %an:sequential function zq:delete-query($query-key as xs:anyURI) as
  empty-sequence() external;

(:~
 : <p>This function returns the value of a variable that is bound in the
 : given query.</p>
 :
 : @param $query-key the identifier of a compiled query.
 : @param $var-name the name of the variable whose value should be returned.
 :
 : @return the value bound to the given variable.
 :
 : @error zq:NO_QUERY_MATCH if no query with the given identifier
 :   was prepared.
 : @error zq:UNDECLARED_VARIABLE if the given variable is not declared
 :   in the query.
 : @error zq:UNBOUND_VARIABLE if the given variable doesn't have a value.
 :)
declare function zq:variable-value($query-key as xs:anyURI, $var-name as 
  xs:QName) as item()* external;

(:~
 : <p>Returns the compiled query identified by the given query-key 
 : as binary data.</p>
 :
 : @param $query-key the identifier of a compiled query.
 :
 : @return the query as xs:base64Binary.
 :
 : @error zq:NO_QUERY_MATCH if no query with the given identifier
 :   was prepared.
 : @error zq:NO_QUERY_PLAN if there is an error serializing the query.
 :)
declare function zq:query-plan($query-key as xs:anyURI) 
  as xs:base64Binary external;
  
  
(:~
 : <p>The function loads a given query for execution from a 
 : xs:base64Binary query plan, obtained through the zq:query-plan function.</p>
 : <p>If the query was successfully loaded, the function returns an
 : identifier as xs:anyURI. This URI can be passed to other functions
 : of this module (e.g. to actually evaluate the query). The URI
 : is opaque and its lifetime is bound by the lifetime of the query
 : that invoked this function. Further reference or uses
 : of the identifier lead to unexpected results.</p>
 : <p/>
 : <p>Successfully prepared queries need to be deleted by passing the resulting
 : identifier to the zq:delete-query function of this module.</p>
 :
 : @param $plan the binary query plan.
 :
 : @return an identifier for the compiled query that can be passed
 :   as arguments to other functions of this module.
 :
 : @error any (static or type) error that may be raised during the compilation
 : of the query. For example, err:XPST0003 if the given query could
 : not be parsed.
 :)    
declare function zq:load-from-query-plan($plan as xs:base64Binary)
  as xs:anyURI external;

(:~
 : <p>The function loads a given query for execution from a 
 : xs:base64Binary query plan, obtained through the zq:query-plan function.</p>
 : <p>If the query was successfully loaded, the function returns an
 : identifier as xs:anyURI. This URI can be passed to other functions
 : of this module (e.g. to actually evaluate the query). The URI
 : is opaque and its lilfetime is bound by the lifetime of the query
 : that invoked this function. Further reference or uses
 : of the identifier lead to unexpected results.</p>                 
 : <p/>
 : <p>For important notes regarding the second and third parameters of the 
 : function, review the comments in zq:prepare-main-module#3.</p>
 : <p/>
 : <p>Successfully prepared queries need to be deleted by passing the resulting
 : identifier to the zq:delete-query function of this module.</p>
 :
 : @param $plan the binary query plan.
 :
 : @param $resolver the URL resolver function.
 : 
 : @param $mapper the URI mapper function.
 :
 : @return an identifier for the compiled query that can be passed
 :   as arguments to other functions of this module.
 :
 : @error any (static or type) error that may be raised during the compilation
 : of the query. For example, err:XPST0003 if the given query could
 : not be parsed.
 :)  
declare function zq:load-from-query-plan($plan as xs:base64Binary,
  $resolver as item()?, $mapper as item()?) as xs:anyURI external;

