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
 :
 :)

module namespace reflection = "http://www.zorba-xquery.com/modules/reflection";



(:~
 : The invoke() function allows to dynamically call a function given its QName
 : and parameters. It is possible to invoke a function who's name is not known
 : at compilation time -- it can be computed, passed through an external 
 : variable, taken from a file, etc. The first parameter must always be a 
 : QName identifying a known function. The rest of the parameters will be
 : passed to the function that is called.
 :
 : <br/>
 : Example usage : <pre> reflection:invoke ( xs:QName("fn:max"), (1,2,3) ) </pre>
 : <br/>
 : Returns : <pre> 3 </pre>
 :
 : @param $name the QName of function that is to be called.
 : @return the result that is returned by the invoked function. 
 :)
declare %variadic function reflection:invoke($name as xs:QName) as item()* external;

