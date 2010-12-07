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
 : The OS module brings operating system depended functions to zorba.
 :
 : @author Markus Pilman
 :)
module namespace os = "http://www.zorba-xquery.com/modules/os";

(:~
 : Returns the name of the operating system Zorba was built on.
 : Possible values of the returned string are:
 :
 : <ul>
 :  <li>Linux</li>
 :  <li>Mac OS X</li>
 :  <li>Windows</li>
 : </ul>
 :
 : @return The name of the operating system zorba was built on.
 :)
declare function os:operating-system() as xs:string external;

(:~
 : The get-env function obtains the current value of an environment variable.
 :
 : @param $variable The name of the envroinment variable to query for.
 : @return The value of the envroinment variable with the name $variable. If the
 :         variable does not exist, the empty-seuqnce is returned.
 :)
declare function os:get-env($variable as xs:string) as xs:string? external;
