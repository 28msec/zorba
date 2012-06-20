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
 : This module provides several functions for generating (pseudo-)random
 : numbers and strings.
 :
 : @author Matthias Brantner, Sorin Nasoi
 : @project XDM/atomic
 :
 :)
module namespace r = "http://www.zorba-xquery.com/modules/random";

declare namespace an = "http://www.zorba-xquery.com/annotations";
declare namespace zerr = "http://www.zorba-xquery.com/errors";

declare namespace ver = "http://www.zorba-xquery.com/options/versioning";
declare option ver:module-version "2.0";

(:~
 : This function generates an arbitrary number of pseudo-random numbers.
 : The sequence is repeatable by calling the function with the same
 : seed.
 :
 : <p>The function is based on posix function <tt>srand()</tt> and
 : <tt>rand()</tt>. Specifically, it invokes <tt>srand($seed)</tt>
 : and then returns the values returned by invoking <tt>rand()</tt>
 : <tt>$num</tt>-times.</p>
 :
 : <p>Sequences returned by this function are not thread-safe (i.e.
 : if multiple XQuery programs invoking this function are executed
 : concurrently in several threads). This is because the function is
 : based on <tt>srand()</tt> and <tt>rand()</tt>.</p>
 :
 : @param $seed the initial seed value for the sequence
 : @param $num the length of the sequence returned
 : @return <tt>$num</tt> pseudo-random integers, or the empty
 :  sequence if <tt>$num</tt> is negative.
 :
 : @error zerr:ZQXD0004 if the given seed is negative or great
 :  than the max value of <tt>unsigned int</tt> on the given platform.
 :)
declare function r:seeded-random(
  $seed as xs:integer,
  $num as xs:integer
) as xs:integer* external;

(:~
 : This function generates an arbitrary number of random numbers.
 : The function is nondeterministic because the sequence is
 : <b>not</b> repeatable.
 :
 : <p>However, the function is based on posix function <tt>srand()</tt> and
 : <tt>rand()</tt>. Specifically, it invokes <tt>srand()</tt>
 : with some random number based on the current time
 : and then returns the values returned by invoking
 : <tt>rand()</tt> <tt>$num</tt>-times.</p>
 :
 : @param $num the length of the sequence returned
 : @return <tt>$num</tt> random integers, or the empty
 :  sequence if <tt>$num</tt> is negative.
 :)
declare %an:nondeterministic function r:random(
  $num as xs:integer
) as xs:integer* external;

(:~
 : This function generates one random number.
 : The function is nondeterministic.
 :
 : <p>The function is based on <tt>r:random#1</tt>. Specifically, it
 : returns the value of invoking <tt>r:random(1)</tt>.</p>
 :
 : @return a random integer
 :)
declare %an:nondeterministic function r:random() as xs:integer
{
  r:random(1)
};

(:~
 : This function generates an arbitrary number of pseudo-random numbers
 : within a given range. The sequence is repeatable by calling the
 : function with the same seed and boundaries.
 :
 : <p>The function is based on the function <tt>r:seeded-random#2</tt>.
 : Specifically, it's result is repeatable if called with the
 : same arguments.</p>
 :
 : @param $seed the initial seed value for the sequence
 : @param $lower the lower bound for every value within the sequence
 : @param $upper the upper bound for every value within the sequence
 : @param $num the length of the sequence returned
 : @return <tt>$num</tt> pseudo-random integers within (and including) the
 :    range specified by <tt>$lower</tt> and <tt>$upper</tt>. It returns
 :     <tt>$num</tt>-times <tt>$lower</tt> if <tt>$lower</tt> is
 :     equal to <tt>$upper</tt> and the empty sequence if <tt>$num</tt>
 :     is negative.
 :
 : @error zerr:ZQXD0004 if the given seed is negative or great
 :  than the max value of <tt>unsigned int</tt> on the given platform.
 : @error r:invalid-arg if <tt>$lower</tt> is greater than <tt>$upper</tt>
 :)
declare function r:seeded-random-between(
  $seed as xs:integer,
  $lower as xs:integer,
  $upper as xs:integer,
  $num as xs:integer
) as xs:integer*
{
  if ( $lower eq $upper ) then
    $lower
  else
    if ( $lower > $upper ) then
      fn:error(
        fn:QName("http://www.zorba-xquery.com/modules/random", "invalid-arg"),
        "$lower must be smaller or equal than $upper",
        ($lower, $upper)
      )
    else
      for $i in r:seeded-random( $seed, $num )
      return
        if ( ( $upper - $lower ) lt 10000 ) then
          xs:integer( fn:round( xs:double( $i mod 10000 ) div 10000 * ( $upper - $lower) ) + $lower )
        else
          xs:integer( fn:round( xs:double( $i ) mod ( $upper - $lower ) ) + $lower )
};

(:~
 : This function generates an arbitrary number of random numbers
 : within a given range. The function is nondeterministic because
 : the sequence is <b>not</b> repeatable.
 :
 : @param $lower the lower bound for every value within the sequence
 : @param $upper the upper bound for every value within the sequence
 : @param $num the length of the sequence returned
 : @return <tt>$num</tt> pseudo-random integers within (and including) the
 :    range specified by <tt>$lower</tt> and <tt>$upper</tt>. It returns
 :     <tt>$num</tt>-times <tt>$lower</tt> if <tt>$lower</tt> is
 :     equal to <tt>$upper</tt> and the empty sequence if <tt>$num</tt>
 :     is negative.
 :
 : @error r:invalid-arg if <tt>$lower</tt> is greater than <tt>$upper</tt>
 :)
declare %an:nondeterministic function r:random-between(
  $lower as xs:integer,
  $upper as xs:integer,
  $num as xs:integer) as xs:integer*
{
  if ( $lower eq $upper ) then
    $lower
  else
    if ( $lower > $upper ) then
      fn:error(
        fn:QName("http://www.zorba-xquery.com/modules/random", "invalid-arg"),
        "$lower must be smaller or equal than $upper",
        ($lower, $upper)
      )
    else
      for $i in r:random( $num )
      return
        if ( ( $upper - $lower ) lt 10000 ) then
          xs:integer( fn:round( xs:double( $i mod 10000 ) div 10000 * ( $upper - $lower) ) + $lower )
        else
          xs:integer( fn:round( xs:double( $i ) mod ( $upper - $lower ) ) + $lower )
};

(:~
 : This function generates one random number within a given range.
 : The function is nondeterministic.
 :
 : <p>The function is based on <tt>r:random-between#3</tt>.
 : Specifically, it returns the value of invoking
 : <tt>r:random-betwen($lower, $upper, 1)</tt>.</p>
 :
 : @param $lower the lower bound for the random number
 : @param $upper the upper bound for the random number
 : @return a random integer within the given range
 :)
declare %an:nondeterministic function r:random-between(
  $lower as xs:integer,
  $upper as xs:integer
) as xs:integer
{
  r:random-between($lower, $upper, 1)
};

(:~
 : This function returns a uuid. Note, that the function is not stable,
 : that is, it returns a different UUID everytime the function is invoked.
 :
 : @return the generated UUID as xs:string
:)
declare %an:nondeterministic function r:uuid() as xs:string external;

