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
 :
 : @author Matthias Brantner
 : @project XDM/atomic
 :
 :)
module namespace random = "http://www.zorba-xquery.com/modules/random";

declare namespace ann = "http://www.zorba-xquery.com/annotations";

declare namespace ver = "http://www.zorba-xquery.com/options/versioning";
declare option ver:module-version "2.0";

(:~
 : Errors namespace URI.
:)
declare variable $random:randomNS as xs:string := "http://www.zorba-xquery.com/modules/random";

(:~
 : Error code for wrong parameter situations.<br/>
 : Possible error messages:<br/>
 : * Randbetween function: $bottom must be smaller or equal than $up<br/>
:)
declare variable $random:errValue as xs:QName := fn:QName($random:randomNS, "random:errValue");

(:~
 : This function returns a pseudo-random integer.
 :
 : @return a pseudo-random integer
 :)
declare %ann:nondeterministic function random:random() as xs:integer external;

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
declare %ann:nondeterministic function random:random($seed as xs:integer) as xs:integer external;

(:~
 :  This function returns a uuid. Note, that the function is not stable,
 :  that is, it returns a different UUID everytime the function is invoked.
 :
 : @return the generated UUID
 :)
declare %ann:nondeterministic function random:uuid() as xs:string external;

(:~
 : Returns a random integer number between the numbers you specify.
 : The seed is based on time in seconds so calling too fast will return the same result.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052092301033.aspx
 : @param $bottom the lower limit
 : @param $up the upper limit
 : @return the random between bottom and up, as xs:integer
 : @error XQP0021(errValue) if bottom is bigger than up
:)
declare %ann:nondeterministic function random:randbetween( $bottom as xs:integer, $up as xs:integer) as xs:integer
{
  if($bottom = $up) then
    $bottom
  else
    if($bottom > $up) then
      fn:error($random:errValue, "Randbetween function: $bottom must be smaller or equal than $up")
    else
      xs:integer(random:random() mod ($up - $bottom) + $bottom)
};

