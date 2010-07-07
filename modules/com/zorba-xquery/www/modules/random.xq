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
 : A module that provides several functions for generating (pseudo-)random
 : numbers and strings.
 :)
module namespace random = "http://www.zorba-xquery.com/modules/random";

(:~
 : This function returns a pseudo-random integer
 :
 : @return a pseudo-random integer
 :)
declare nondeterministic function random:random() as xs:integer external;

(:~
 : This function returns a pseudo-random integer
 : The function sets its argument as the seed for a new sequence
 : of pseudo-random integers to be returned.
 : These sequences are repeatable by calling this function with the
 : same seed value.
 :
 : @param $seed the seed value for this pseudo-random integer sequence
 : @return a pseudo-random integer
 :)
declare nondeterministic function random:random($seed as xs:integer) as xs:integer external;

(:~
 :  This function returns a uuid. Note, that the function is not stable,
 :  that is, it returns a different UUID everytime the function is invoked.
 :
 : @return the generated UUID
 :)
declare nondeterministic function random:uuid() as xs:string external;
