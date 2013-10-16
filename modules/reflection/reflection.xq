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
 : This module provides functions to dynamically invoke functions or main modules,
 : respectively. Each of the functions (invoke or eval) come in four variants depending
 : whether the expression being invoked is simple, nondeterministic, updating,
 : or sequential.

 : @author Nicolae Brinza
 : @project Zorba/Reflection/Reflection
 :
 :)

module namespace reflection = "http://zorba.io/modules/reflection";

declare namespace an = "http://zorba.io/annotations";

declare namespace err = "http://www.w3.org/2005/xqt-errors";

declare namespace ver = "http://zorba.io/options/versioning";
declare option ver:module-version "1.0";

(:~
 : The invoke function allows to dynamically call a function given its QName
 : and parameters.<p/>
 : It is possible to invoke a function whose name is not known
 : at compilation time -- it can be computed, passed through an external 
 : variable, taken from a file, etc. The first parameter must always be a 
 : QName identifying a known function.<p/>
 :
 : The function is declared with the %an:variadic annotation. Hence, it allows
 : for an arbitrary number of parameters. All of these parameters (except the
 : first one) will be passed to the function that is called.
 :
 : <br/>
 : Example usage : <pre> reflection:invoke ( xs:QName("fn:max"), (1,2,3) ) </pre>
 : <br/>
 : Returns <pre> 3 </pre>.
 :
 : @param $name the QName of the function that is to be invoked
 :
 : @error whatever error the invoked function may return
 :
 : @return the result that is returned by the invoked function
 :
 : @example test/rbkt/Queries/zorba/reflection/reflection-invoke-01.xq
 : @example test/rbkt/Queries/zorba/reflection/reflection-invoke-92.xq
 :)
declare %an:variadic function reflection:invoke(
  $name as xs:QName
) as item()* external;

(:~
 : See documentation for reflection:invoke except the function that
 : is to be invoked may be nondeterministic.
 :
 : @param $name the QName of the function that is to be invoked
 :
 : @error whatever error the invoked function may return

 : @return the result that is returned by the invoked function
 :
 : @see reflection:invoke()
 :)
declare %an:nondeterministic %an:variadic updating function reflection:invoke-n(
  $name as xs:QName
) as item()* external;

(:~
 : See documentation for reflection:invoke-n except the function that
 : is to be invoked may be updating, i.e. return a pending update list.
 :
 : @param $name the QName of the function that is to be invoked
 :
 : @error whatever error the invoked function may return
 :
 : @return the result that is returned by the invoked function
 :
 : @see reflection:invoke-n()
 :)
declare %an:nondeterministic %an:variadic updating function reflection:invoke-u(
  $name as xs:QName
) external;

(:~
 : See documentation for reflection:invoke except the function that
 : is to be invoked may be sequential, i.e. may have side-effects.
 :
 : @param $name the QName of the function that is to be invoked
 :
 : @error whatever error the invoked function may return
 :
 : @return the result that is returned by the invoked function
 :
 : @see reflection:invoke()
 :)
declare %an:variadic %an:sequential function reflection:invoke-s(
  $name as xs:QName
) as item()* external;


(:~
 : The purpose of this function is to (dynamically) execute an XQuery program
 : from inside another XQuery program.<p/>
 : The XQuery program that invokes the
 : eval function will be referred to as the "outer" program and the XQuery
 : program that is executed by the eval invocation will be referred to as
 : the "inner" program. The function is given as a string argument.
 : Typically, the outer program constructs this string dynamically,
 : e.g., based on data extracted from documents and/or the values of
 : external variables. The eval function treats this string as 
 : an XQuery main module. That is, it parses the string, compiles the 
 : resulting parse tree, executes the resulting execution plan, and finally 
 : returns the result or error (if any) to the outer program.<p/>
 : The given XQuery program needs to be a valid according to XQuery's 
 : MainModule production (see <a href="http://www.w3.org/TR/xquery/#doc-xquery-MainModule">
 : http://www.w3.org/TR/xquery/#doc-xquery-MainModule</a>. Please note
 : that the inner pogram must at least have the XQuery version of the
 : outer program [err:XQST0031].<p/>
 :
 : The inner program "inherits" the static and dynamic context of the outer
 : program. Specifically, evaluation of the inner program is done in static and 
 : dynamic contextes that are initialized as copies of the static and dynamic 
 : contextes of the outer program at the place where the eval invocation appears 
 : at. This means that, for example, all variables that are in-scope at the place 
 : where the eval function is invoked from, are also in-scope inside the inner
 : program and can be referenced there without having to be re-declared. On the other
 : hand, declarations that appear in the prolog of the inner main module or are
 : imported by the inner main module from library modules, hide their corresponding
 : inherited declarations. For example, if the inner main module declares 
 : a variable or function with the same name as an inherited variable or function, 
 : the inner variable/function hides the inherited one.<p/> 
 :
 : If the inner program declares an external variable with the same name as an 
 : inherited variable, the value of the inherited variable is used to initialize 
 : the inner external variable. If, however, an inner external variable has no 
 : default initializer and no corresponding inherited variable, it will remain 
 : uninitialized, causing the inner program to raise an error when executed.
 : 
 : @param $query the query string to be evaluated
 :
 : @error whatever error the evaluated XQuery may return.
 : @error err:XQST0031 If the XQuery version of the inner program is greater
 :   than the version of the outer program.
 :
 : @return the result of evaluating the query
 :
 : @example test/rbkt/Queries/zorba/eval/eval1.xq
 : @example test/rbkt/Queries/zorba/eval/eval2.xq
 :)
declare function reflection:eval(
    $query as xs:string
) as item()* external;

(:~
 : See documentation of reflection:eval() except the main module that is to
 : be executed may be nondeterministc.
 :
 : @param $query the query string to be evaluated
 :
 : @error whatever error the evaluated XQuery may return
 : @error err:XQST0031 If the XQuery version of the inner program is greater
 :   than the version of the outer program.
 :
 : @return the result of evaluating the query
 :)
declare %an:nondeterministic function reflection:eval-n(
    $query as xs:string
) as item()* external;


(:~
 : See documentation of reflection:eval() except the main module that is to
 : be executed may be updating, i.e. return a pending update list.
 :
 : @param $query the query string to be evaluated
 :
 : @error whatever error the evaluated XQuery may return
 : @error err:XQST0031 If the XQuery version of the inner program is greater
 :   than the version of the outer program.
 :
 : @return the PUL resulting from evaluating the query
 :
 : @see reflection:eval()
 :)
declare %an:nondeterministic updating function reflection:eval-u(
    $query as xs:string
) external;


(:~
 : See documentation of reflection:eval() except the main module that is to
 : be executed may be sequential, i.e. may have side-effects.
 :
 : @param $query the query string to be evaluated
 :
 : @error whatever error the evaluated XQuery may return
 : @error err:XQST0031 If the XQuery version of the inner program is greater
 :   than the version of the outer program.
 :
 : @return the result of evaluating the query (the result is not supposed to
 :         contain any PUL).
 :
 : @see reflection:eval()
 :)
declare %an:sequential function reflection:eval-s(
    $query as xs:string
) as item()* external;
