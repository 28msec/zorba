jsoniq version "1.0";

(:
 : Copyright 2006-2013 The FLWOR Foundation.
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
 : @project Zorba/XML and JSON Data Model/Atomic/Random
 :
 :)
module namespace r = "http://zorba.io/modules/random";

declare namespace an = "http://zorba.io/annotations";
declare namespace zerr = "http://zorba.io/errors";

declare namespace ver = "http://zorba.io/options/versioning";
declare option ver:module-version "1.0";

declare %private variable $r:errNS as string := "http://zorba.io/modules/random";
declare %private variable $r:INVALID_ARGUMENT as QName := fn:QName($r:errNS, "r:INVALID_ARGUMENT");

(:~
 : <p>This function generates an arbitrary number of pseudo-random numbers.
 : The sequence is repeatable by calling the function with the same
 : seed.</p>
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
  $seed as integer,
  $num as integer
) as integer* external;

(:~
 : <p>This function generates an arbitrary number of random numbers.
 : The function is nondeterministic because the sequence is
 : <b>not</b> repeatable.</p>
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
  $num as integer
) as integer* external;

(:~
 : <p>This function generates one random number.
 : The function is nondeterministic.</p>
 :
 : <p>The function is based on <tt>r:random#1</tt>. Specifically, it
 : returns the value of invoking <tt>r:random(1)</tt>.</p>
 :
 : @return a random integer
 :)
declare %an:nondeterministic function r:random() as integer
{
  r:random(1)
};

(:~
 : <p>This function generates an arbitrary number of pseudo-random numbers
 : within a given range. The sequence is repeatable by calling the
 : function with the same seed and boundaries.</p>
 :
 : <p>The function is based on the function <tt>r:seeded-random#2</tt>.
 : Specifically, its result is repeatable if called with the
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
 : @error r:INVALID_ARGUMENT if <tt>$lower</tt> is greater than <tt>$upper</tt>
 :)
declare function r:seeded-random-between(
  $seed as integer,
  $lower as integer,
  $upper as integer,
  $num as integer
) as integer*
{
  if ( $lower eq $upper ) then
    $lower
  else
    if ( $lower gt $upper ) then
      fn:error(
        $r:INVALID_ARGUMENT,
        "$lower must be less than or equal to $upper",
        ($lower, $upper)
      )
    else
      for $i in r:seeded-random( $seed, $num )
      return
        if ( ( $upper - $lower ) lt 10000 ) then
          integer( fn:round( double( $i mod 10000 ) div 10000 * ( $upper - $lower) ) + $lower )
        else
          integer( fn:round( double( $i ) mod ( $upper - $lower ) ) + $lower )
};

(:~
 : <p>This function generates an arbitrary number of random numbers
 : within a given range. The function is nondeterministic because
 : the sequence is <b>not</b> repeatable.</p>
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
 : @error r:INVALID_ARGUMENT if <tt>$lower</tt> is greater than <tt>$upper</tt>
 :)
declare %an:nondeterministic function r:random-between(
  $lower as integer,
  $upper as integer,
  $num as integer) as integer*
{
  if ( $lower eq $upper ) then
    $lower
  else
    if ( $lower gt $upper ) then
      fn:error(
        $r:INVALID_ARGUMENT,
        "$lower must be less than or equal to $upper",
        ($lower, $upper)
      )
    else
      for $i in r:random( $num )
      return
        if ( ( $upper - $lower ) lt 10000 ) then
          integer( fn:round( double( $i mod 10000 ) div 10000 * ( $upper - $lower) ) + $lower )
        else
          integer( fn:round( double( $i ) mod ( $upper - $lower ) ) + $lower )
};

(:~
 : <p>This function generates one random number within a given range.
 : The function is nondeterministic.</p>
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
  $lower as integer,
  $upper as integer
) as integer
{
  r:random-between($lower, $upper, 1)
};

(:~
 : <p>This function returns a uuid.</p>
 : <p> Note, that the function is not stable,
 : that is, it returns a different UUID everytime the function is invoked.</p>
 :
 : @return the generated UUID as string
:)
declare %an:nondeterministic function r:uuid() as string external;

