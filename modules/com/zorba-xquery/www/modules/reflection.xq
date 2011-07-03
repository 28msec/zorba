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
 : Reflection Module for Zorba.
 :
 : @author Nicolae Brinza
 : @project reflection
 :
 :)

module namespace reflection = "http://www.zorba-xquery.com/modules/reflection";

declare namespace ann = "http://www.zorba-xquery.com/annotations";

declare namespace ver = "http://www.zorba-xquery.com/options/versioning";
declare option ver:module-version "2.0";


(:~
 : The invoke function allows to dynamically call a function given its QName
 : and parameters. It is possible to invoke a function who's name is not known
 : at compilation time -- it can be computed, passed through an external 
 : variable, taken from a file, etc. The first parameter must always be a 
 : QName identifying a known function. The rest of the parameters will be
 : passed to the function that is called.
 :
 : invoke comes in three flavours:
 : invoke-simple() - for the invocation of functions that are non-updating and
 :                   non-side effecting 
 : invoke-updating() - for the invocation of updating functions
 : invoke-sequential() - for the invocation of sequential functions 
 :
 : <br/>
 : Example usage : <pre> reflection:invoke-simple ( xs:QName("fn:max"), 
 :                                                  (1,2,3) ) </pre>
 : <br/>
 : Returns : <pre> 3 </pre>
 :
 : @param $name the QName of the function that is to be called.
 : @return the result that is returned by the invoked function. 
 :)
declare %nondeterministic %ann:variadic function reflection:invoke-simple($name as xs:QName) as item()* external;

(:~
 : invoke-updating()
 :
 : @param $name the QName of the function that is to be called.
 : @return the result that is returned by the invoked function.
 :)
declare %nondeterministic %ann:variadic updating function reflection:invoke-updating($name as xs:QName) external;

(:~
 : invoke-sequential()
 :
 : @param $name the QName of the function that is to be called.
 : @return the result that is returned by the invoked function.
 :)
declare %nondeterministic %ann:variadic %sequential function reflection:invoke-sequential($name as xs:QName) as item()* external;


(:~
 : Eval
 :
 : @param $query the query string to be evaluated.
 : @return the result of evaluating the query (the result is not supposed to
 :         contain any PUL).
 :)
declare %nondeterministic function reflection:eval-simple(
    $query as xs:string
) as item()* external;


(:~
 : Eval
 :
 : @param $query the query string to be evaluated.
 : @return the PUL resulting from evaluating the query
 :)
declare %nondeterministic updating function reflection:eval-updating(
    $query as xs:string
) external;


(:~
 : Eval
 :
 : @param $query the query string to be evaluated.
 : @return the result of evaluating the query (the result is not supposed to
 :         contain any PUL).
 :)
declare %nondeterministic %sequential function reflection:eval-sequential(
    $query as xs:string
) as item()* external;

