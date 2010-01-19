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
 : This is a library module offering the same set of functions
 : defined by Microsoft Excel.
 : 
 : @see <a href="http://office.microsoft.com/en-us/excel/CH062528291033.aspx">Excel Documentation</a>
 : @spec XQuery Specification: January 2007
 : @author Daniel Turcanu
 : @version 1.0 
 :)
module namespace  excel = "http://www.zorba-xquery.com/modules/excel/math" ;

(:~
 : Use excel-err module functions for throwing errors.
:)
import module namespace excel-err="http://www.zorba-xquery.com/modules/excel/errors";

(:~
 : Checks if the xs:anyAtomicType argument is actually a numeric type
 : or can be converted to numeric
 : 
 : @param $value  parameter to be checked
 : @return boolean true if the value can be casted to numeric
:)
declare function excel:is-a-number   ( $value as xs:anyAtomicType )  as xs:boolean 
{   
  fn:string(fn:number($value)) != 'NaN' 
} ;

(:~
 : Cast the xs:anyAtomicType to a numeric type.
 : If the value is already of a numeric type then nothing is changed.
 : Otherwise the value is casted to the numeric type that is most appropriate.
 : 
 : @param $number the parameter can be a number, string, boolean value
 : @return the casted value
 : @error XQP0021(errValue) if the value cannot be casted to numeric type
:)
declare function excel:cast-as-numeric( $number as xs:anyAtomicType) as xs:anyAtomicType
{
  typeswitch($number) 
    case xs:double return $number
    case xs:decimal return $number
    case xs:double return $number
    case xs:float return $number
    default return
      if($number castable as xs:integer) then
        xs:integer($number)
      else
      if($number castable as xs:decimal) then
         xs:decimal($number)
      else
      if($number castable as xs:double) then
         xs:double($number)
      else
         fn:error($excel-err:errValue, "Provided value is not a number", $number)

};
(: ---------------- Excel Math functions ----------------------- :)

(:~
 : Compute the abs of a numeric value.
 : The value can also be a string and it will be casted to the appropriate numeric first.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052089781033.aspx
 : @param $arg the parameter can be a number, string, boolean value
 : @return the abs value as a numeric type
 : @error XQP0021(errValue) if arg cannot be casted to numeric type
:)
declare function excel:abs ( $arg as xs:anyAtomicType ) as xs:anyAtomicType
{
  fn:abs(excel:cast-as-numeric($arg))
} ;

(:~
 : Returns number rounded up, away from zero, to the nearest multiple of significance.
 : Significance must have the same sign as number.
 : Number and significance must be of a numeric type or castable to numeric.
 : Significance must not be zero.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052090071033.aspx
 : @param $number_at the value you want to round
 : @param $significance_at is the multiple to which you want to round.
 : @return the rounded value
 : @error XQP0021(errValue) if parameters cannot be casted to numeric type
 : @error XQP0021(errNum) if significance is zero or it doesn't have the same sign as number
:)
declare function excel:ceiling( $number_at as xs:anyAtomicType, $significance_at as xs:anyAtomicType ) as xs:anyAtomicType
{
  let $number := excel:cast-as-numeric($number_at)
  let $significance := excel:cast-as-numeric($significance_at) return
    if($significance = 0) then
       fn:error($excel-err:errNum, "Ceiling function does not accept significance 0")
    else
    if($number * $significance ge 0) then
	    fn:ceiling($number div $significance) * $significance
    else
       fn:error($excel-err:errNum, "Ceiling function: both arguments must have the same sign")
};

(:~
 : Returns number rounded up to the nearest even integer.
 : Regardless of the sign of number, a value is rounded up when adjusted away from zero. 
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052090801033.aspx
 : @param $number_at the value to round
 : @return the rounded value casted as numeric type
 : @error XQP0021(errValue) if parameters cannot be casted to numeric type
:)
declare function excel:even( $number_at as xs:anyAtomicType) as xs:anyAtomicType
{
   let $number := excel:cast-as-numeric($number_at) return
   if($number = 0) then
     0
   else
   let $intnum := excel:ceiling($number, excel:sign($number)) return
     if($intnum mod 2 != 0) then
       if($intnum > 0) then
         $intnum + 1
       else
         $intnum - 1
     else
       $intnum
};

(:~
 : Helper function for computing factorial.
  It is a recursive function multiplying number with fact(number-1).
  
  @param $intnum the positive integer
  @return the factorial of intnum
:)
declare function excel:fact-integer( $intnum as xs:integer ) as xs:integer
{
  if($intnum = 1) then
    1
  else
    $intnum * excel:fact-integer($intnum - 1)  
};

(:~
 : Returns the factorial of a number.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052090841033.aspx
 : @param $number_at number is casted to numeric and then to integer
 : @return factorial number as xs:integer
 : @error XQP0021(errNum) if the number is smaller than zero
:)
declare function excel:fact( $number_at as xs:anyAtomicType) as xs:integer
{
  let $number := excel:cast-as-numeric($number_at) return
    if($number = 0) then
      1
    else
      if($number lt 0) then
        fn:error($excel-err:errNum, "Fact function does not accept number less than zero")
      else
        excel:fact-integer(xs:integer($number))
 };

(:~
 : Rounds number down, toward zero, to the nearest multiple of significance.
 : Significance must have the same sign as number.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052090941033.aspx
 : @param $number_at the value you want to round. 
 :           If it is string or boolean it will be casted to numeric.
 : @param $significance_at the multiple to which you want to round
 : @return the rounded value as numeric type
 : @error XQP0021(errValue) if parameters cannot be casted to numeric type
 : @error XQP0021(errNum) if significance is zero or it doesn't have the same sign as number  
:)
 declare function excel:floor( $number_at as xs:anyAtomicType, $significance_at as xs:anyAtomicType  ) as xs:anyAtomicType
 {
   let $number := excel:cast-as-numeric($number_at)
   let $significance := excel:cast-as-numeric($significance_at) return
    if($significance = 0) then
       fn:error($excel-err:errNum, "Floor function does not accept significance 0")
    else
     if($number * $significance ge 0) then
       fn:floor($number div $significance) * $significance
     else
       fn:error($excel-err:errNum, "Floor function: both arguments must have the same sign")
 };
 
 (:~
  : Rounds a number down to the nearest integer.
  : Positive numbers are rounded toward zero, negative numbers are rounded away from zero.
  : 
  : @see http://office.microsoft.com/en-us/excel/HP052091421033.aspx
  : @param $number parameter will be casted to numeric
  : @return the rounded integer
  : @error XQP0021(errValue) if parameter cannot be casted to numeric type
 :)
 declare function excel:int( $number as xs:anyAtomicType ) as xs:integer
 {
   xs:integer(fn:floor(excel:cast-as-numeric($number)))
 };
 
 (:~
  : Returns the remainder after number is divided by divisor.
  : The result has the same sign as divisor.
  : 
  : @see http://office.microsoft.com/en-us/excel/HP052091821033.aspx
  : @param $number_at is the number for which you want to find the remainder.
  : @param $divisor_at is the number by which you want to divide number.
  :          This cannot be zero.
  : @return the remainder from division as numeric type
  : @error XQP0021(errValue) if parameters cannot be casted to numeric type
  : @error XQP0021(errDiv0) if divisor is zero after casting to numeric
 :)
 declare function excel:mod( $number_at as xs:anyAtomicType, $divisor_at as xs:anyAtomicType) as xs:anyAtomicType
 {
   let $number := excel:cast-as-numeric($number_at)
   let $divisor := excel:cast-as-numeric($divisor_at) return
     if($divisor = 0) then
       fn:error($excel-err:errDiv0, "Mod operator: divide by 0")
     else
       let $result := $number mod $divisor return
         if($result * $divisor lt 0) then
           -$result
         else
           $result
 };
 
 (:~
  : Returns number rounded up to the nearest odd integer, away from zero.
  : 
  : @see  http://office.microsoft.com/en-us/excel/HP052092031033.aspx
  : @param $number_at  is the value to round
  : @return the odd integer
  : @error XQP0021(errValue) if parameter cannot be casted to numeric type
 :)
 declare function excel:odd( $number_at as xs:anyAtomicType ) as xs:integer
 {
   let $number := excel:cast-as-numeric($number_at) return
   if($number = 0) then
     1
   else
   let $intnum := excel:ceiling($number, excel:sign($number)) return
     if($intnum mod 2 = 0) then
       if($intnum ge 0) then
         ($intnum + 1) cast as xs:integer
       else
         ($intnum - 1) cast as xs:integer
     else
       $intnum cast as xs:integer
 };
 
 (:~
  : Return the value of PI as decimal with 15 digits
  : 
  : @see http://office.microsoft.com/en-us/excel/HP052092141033.aspx
  : @return the value of PI with 15 digits
 :)
 declare function excel:pi() as xs:decimal
 {
   3.14159265358979
 };
 
 (:~
  : Returns the result of a number raised to a power.
  : The result is computed through successive multiplications.
  : 
  : @see http://office.microsoft.com/en-us/excel/HP052092171033.aspx
  : @param $number_at the base number
  : @param $power the exponent as integer (cannot be floating point like in Excel)
  : @return the result as numeric type
  : @error XQP0021(errValue) if parameter cannot be casted to numeric type
  : @error XQP0021(errValue) if power is smaller than zero
 :)
 declare function excel:power( $number_at as xs:anyAtomicType, $power as xs:integer) as xs:anyAtomicType
 {
   let $number := excel:cast-as-numeric($number_at) return
   if( $power lt 0) then
     fn:error($excel-err:errValue, "Power function: power must be greater or equal than zero")
   else
   if($power = 0) then
     1
   else
     if($power = 1) then
       $number
     else
       let $retval := excel:power($number, $power idiv 2) return
         $retval * $retval * excel:power($number, $power mod 2)
   
 };
 
 (:~
  : Helper function for product.
   Multiplies all numbers in the sequence.
   
   @param $numbers list of arguments to be casted to numeric and multiplied
   @return multiplication result as numeric type
   @error XQP0021(errValue) if parameters cannot be casted to numeric type
 :)
 declare function excel:product-internal( $numbers as xs:anyAtomicType*)  as xs:anyAtomicType
 {
    if(fn:empty($numbers)) then
      1
    else
     let $x := excel:cast-as-numeric($numbers[1])  return
       $x * excel:product-internal(fn:subsequence($numbers, 2))
 };
 
 (:~
  : Multiplies all the numbers given as arguments and returns the product.
  : 
  : @see http://office.microsoft.com/en-us/excel/HP052092231033.aspx
  : @param $numbers the sequence of arguments convertable to numeric types.
  :     The sequence can be of any length.
  : @return the multiplication result as numeric type
  : @error XQP0021(errValue) if parameters cannot be casted to numeric type
 :)
 declare function excel:product( $numbers as xs:anyAtomicType*)  as xs:anyAtomicType
 {
   if(fn:empty($numbers)) then
    0
   else
     excel:product-internal($numbers)
 };
 
 (:~
  : Returns the integer portion of a division.
  : 
  : @see http://office.microsoft.com/en-us/excel/HP052092271033.aspx
  : @param $numerator_at is the divident
  : @param $denominator_at is the divisor. It cannot be zero.
  : @return the result value as numeric type
  : @error XQP0021(errValue) if parameters cannot be casted to numeric type
  : @error XQP0021(div0) if denominator casted as numeric type has value zero
 :)
 declare function excel:quotient( $numerator_at as xs:anyAtomicType, $denominator_at as xs:anyAtomicType ) as xs:integer
 {
   let $numerator := excel:cast-as-numeric($numerator_at)
   let $denominator := excel:cast-as-numeric($denominator_at) return
     if($denominator = 0) then
       fn:error($excel-err:errDiv0, "Quotient function: divide by 0")
     else
       xs:integer($numerator div $denominator)
 };
 
 (:~
  : Rounds a number to a specified number of digits.
  : If precision is greater than 0 (zero), then number is rounded 
  : to the specified number of decimal places.
  : If num_digits is 0, then number is rounded to the nearest integer.
  : If num_digits is less than 0, then number is rounded to the left of the decimal point.
  : The 0.5 is rounded away from zero. 
  : 
  : @see http://office.microsoft.com/en-us/excel/HP052092391033.aspx
  : @param $number_at the number to round, castable to a numeric type
  : @param $precision the number of decimal places to keep
  : @return the rounded number as numeric type 
  : @error XQP0021(errValue) if parameters cannot be casted to numeric type
 :)
 declare function excel:round( $number_at as xs:anyAtomicType, $precision as xs:integer ) as xs:anyAtomicType
 {
   let $number := excel:cast-as-numeric($number_at) return
     if($precision ge 0) then
       let $exp_prec := excel:power(10, $precision)
       return 
         if($number ge 0) then
           fn:floor($number * $exp_prec + 0.5) div $exp_prec
         else 
           -fn:floor(-$number * $exp_prec + 0.5) div $exp_prec
     else
       let $exp_prec := excel:power(10, -$precision)
       return
         if($number ge 0) then
           fn:floor($number div $exp_prec + 0.5) * $exp_prec
         else 
           -fn:floor(-$number div $exp_prec + 0.5) * $exp_prec
   
 };
  
(:~
 : Rounds a number down, toward zero.
 : If num_digits is greater than 0 (zero), then number is rounded down 
 : to the specified number of decimal places. 
 : If num_digits is 0, then number is rounded down to the nearest integer. 
 : If num_digits is less than 0, then number is rounded down to the left of the decimal point. 
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052092411033.aspx
 : @param $number_at number to round, castable to numeric type
 : @param $precision the number of decimal places to keep
 : @return the truncated number toward zero, as numeric type
 : @error XQP0021(errValue) if parameters cannot be casted to numeric type
:)
 declare function excel:rounddown( $number_at as xs:anyAtomicType, $precision as xs:integer) as xs:anyAtomicType
 {
   let $number := excel:cast-as-numeric($number_at) return
     if($precision ge 0) then
       let $exp_prec := excel:power(10, $precision)
       return 
         if($number ge 0) then
           fn:floor($number * $exp_prec) div $exp_prec
         else 
           -fn:floor(-$number * $exp_prec) div $exp_prec
     else
       let $exp_prec := excel:power(10, -$precision)
       return
         if($number ge 0) then
           fn:floor($number div $exp_prec) * $exp_prec
         else 
           -fn:floor(-$number div $exp_prec) * $exp_prec
     
 };
 
 (:~
  : Rounds a number up, away from 0 (zero).
  : If num_digits is greater than 0 (zero), then number is rounded down 
  : to the specified number of decimal places. 
  : If num_digits is 0, then number is rounded down to the nearest integer. 
  : If num_digits is less than 0, then number is rounded down to the left of the decimal point. 
  : 
  : @see http://office.microsoft.com/en-us/excel/HP052092421033.aspx
  : @param $number_at number to round, castable to numeric type
  : @param $precision the number of decimal places to keep
  : @return the truncated number away from zero, as numeric type
  : @error XQP0021(errValue) if parameters cannot be casted to numeric type
:)
declare function excel:roundup( $number_at as xs:anyAtomicType, $precision as xs:integer) as xs:anyAtomicType
 {
   let $number := excel:cast-as-numeric($number_at) return
     if($precision ge 0) then
       let $exp_prec := excel:power(10, $precision)
       return 
         if($number ge 0) then
           fn:ceiling($number * $exp_prec) div $exp_prec
         else 
           -fn:ceiling(-$number * $exp_prec) div $exp_prec
     else
       let $exp_prec := excel:power(10, -$precision)
       return
         if($number ge 0) then
           fn:ceiling($number div $exp_prec) * $exp_prec
         else 
           -fn:ceiling(-$number div $exp_prec) * $exp_prec
     
 };
 
 (:~
  : Determines the sign of a number. 
  : Returns 1 if the number is positive, zero (0) if the number is 0, 
  : and -1 if the number is negative.
  : 
  : @see http://office.microsoft.com/en-us/excel/HP052092551033.aspx
  : @param $number_at the argument castable to numeric type
  : @return the sign as (-1, 0, 1)
  : @error XQP0021(errValue) if parameters cannot be casted to numeric type
 :)
 declare function excel:sign( $number_at as xs:anyAtomicType) as xs:integer
 {
   let $number := excel:cast-as-numeric($number_at) return
     if($number = 0) then
       0
     else
      if($number gt 0) then
        1
      else
        -1   
 };
 
 (:~
  : Adds all the numbers in the sequence.
  : 
  : @see http://office.microsoft.com/en-us/excel/HP052092901033.aspx
  : @param $numbers is the sequence of arguments castable to numeric types.
  :     The sequence can be of any length
  : @return the sum as numeric type
  : @error XQP0021(errValue) if parameters cannot be casted to numeric type
 :)
 declare function excel:sum( $numbers as xs:anyAtomicType*)  as xs:anyAtomicType
 {
    if(fn:empty($numbers)) then
      0
    else
     let $x := excel:cast-as-numeric($numbers[1])  return
       $x + excel:sum(fn:subsequence($numbers,2))
 };
 
 (:~
  : Truncates a number to an integer by removing the fractional part of the number.
  : 
  : @see http://office.microsoft.com/en-us/excel/HP052093241033.aspx
  : @param $number the argument castable to numeric type
  : @return the integer value
  : @error XQP0021(errValue) if parameter cannot be casted to numeric type
 :)
 declare function excel:trunc( $number as xs:anyAtomicType ) as xs:integer
 {
   xs:integer(excel:cast-as-numeric($number))
 };
 
 (:~
  : Truncates a number down to precision.
  : This behaves exactly like rounddown.
  : 
  : @see http://office.microsoft.com/en-us/excel/HP052093241033.aspx
  : @param $number the argument castable to numeric type
  : @param $precision the number of decimal places to keep 
  : @return the integer value
  : @error XQP0021(errValue) if parameter cannot be casted to numeric type
 :)
 declare function excel:trunc( $number as xs:anyAtomicType, $precision as xs:integer ) as xs:anyAtomicType
 {
    excel:rounddown(excel:cast-as-numeric($number),$precision)
 };
 
(:~
 : Helper function.
 : Sorts a sequence of numbers or arguments castable to numeric.
  It first casts all arguments to numeric and then sorts ascending.
  
  @param $numbers the sequence of arguments castable to numeric
  @return the sorted sequence as numeric types
  @error XQP0021(errValue) if parameters cannot be casted to numeric type
:)
declare function excel:sort-numbers ( $numbers as xs:anyAtomicType* ) as xs:anyAtomicType*
{
  let $sorted-numbers := (
    for $number_at in $numbers 
    let $number := excel:cast-as-numeric($number_at)
    order by $number
    return $number
    ) 
    return  $sorted-numbers
};



(: priority 1 :)

(:~
 : Converts radians into degrees.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052090561033.aspx
 : @param $radian the value in radians
 : @return the value in degrees 0 .. 360 or 0 .. -360
:)
declare function excel:degrees( $radian as xs:double ) as xs:integer
{
  xs:integer(($radian div excel:pi() * 180 ) mod 360)
};

(:~
 : Returns the double factorial of a number.
 : Computes the double factorial of n as n(n-2)(n-4)...
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052090851033.aspx
 : @param $number the positive integer value
 : @return the result as integer
 : @error XQP0021(errNum) if the number is negative 
:)
declare function excel:factdouble( $number as xs:integer ) as xs:integer
{
  if($number < 0) then
    fn:error($excel-err:errNum, "Factdouble function: number should be greater than zero or equal")
  else  if($number = 1) then
    1
  else if($number = 2) then
    2
  else
    $number * excel:factdouble($number - 2) 
};

(:~
 : Helper function for computing GCD.
 : It calculates the minimum value from a sequence of positive integers, 
 : not taking into account the zero value.
  
  @param $numbers the sequence of positive integers
  @return the minimum value. If the sequence contains only zero values, then zero is returned.
:)
declare function excel:min-without-zero($numbers as xs:integer+) as xs:integer
{
  if(fn:count($numbers) = 1) then
    $numbers[1]
  else
    let $min-other := excel:min-without-zero(fn:subsequence($numbers, 2)) return
    if($numbers[1] = 0) then
      $min-other
    else if($min-other = 0) then
      $numbers[1]
    else if($numbers[1] < $min-other) then
      $numbers[1]
    else
      $min-other
};

(:~
 : Helper function for computing GCD.
 : Checks if all integer numbers from a sequence divide exactly to a divident.
  
  @param $numbers the positive integers
  @param $divident the divident to be tried
  @return boolean true if the numbers divide exactly
:)
declare function excel:try-exact-divide($numbers as xs:integer*, $divident as xs:integer) as xs:boolean
{
  if(fn:empty($numbers)) then
    fn:true()
  else
    if($numbers[1] mod $divident != 0) then
      fn:false()
    else
      excel:try-exact-divide(fn:subsequence($numbers, 2), $divident)
};

(:~
 : Helper function for computing GCD.
  This function iterates through possible divisors and checks
  if the sequence divides exactly to any of those.
  It starts from the minimum value from the sequence
  and searches downwards.
  
  @param $numbers the sequence of positive integers
  @param $min-nonzero the minimum value of numbers sequence, excluding the zero value
  @param $iteration which iteration is it. It starts from 1 and continues to min-nonzero/2
  @return the greatest common divisor if found, or 1 if not found
:)
declare function excel:iterate-all-gcd($numbers as xs:integer*, 
                                       $min-nonzero as xs:integer,
                                       $iteration as xs:integer) as xs:integer
{
  if($min-nonzero mod $iteration = 0) then
    if(excel:try-exact-divide($numbers, $min-nonzero idiv $iteration)) then
      $min-nonzero idiv $iteration
    else
      excel:iterate-all-gcd($numbers, $min-nonzero, $iteration + 1)
  else
    if($iteration > $min-nonzero idiv 2) then
      1
    else
      excel:iterate-all-gcd($numbers, $min-nonzero, $iteration + 1)
};

(:~
 : Returns the greatest common divisor GCD of a sequence of integers.
 : The sequence can have one or more positive integers.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052091041033.aspx
 : @param $numbers the sequence of positive integers
 : @return the GCD as integer
 : @error XQP0021(errNum) if any number is smaller than zero
:)
declare function excel:gcd($numbers as xs:integer+) as xs:integer
{
  if(fn:count($numbers) = 1) then
    $numbers[1]
  else
  let $minval := excel:min-without-zero($numbers) return
  if($minval < 0) then
    fn:error($excel-err:errNum, "gcd function: numbers should be greater than zero or equal")
  else if($minval = 0) then
    0
  else 
    excel:iterate-all-gcd($numbers, $minval, 1)
};

(:~
 : Returns the least common multiple of integers.
 : LCM is computed by multiplying all the numbers and dividing with GCD.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052091521033.aspx
 : @param $numbers the sequence of one or more positive integers
 : @return the LCM as integer
 : @error XQP0021(errNum) if any number is smaller than zero
:)
declare function excel:lcm($numbers as xs:integer+) as xs:integer
{
  let $product := excel:product(fn:distinct-values($numbers)) return
    if($product = 0) then
      0
    else
      $product idiv excel:gcd($numbers)
};

(:~
 : Returns a number rounded to the desired multiple.
 : MROUND rounds up, away from zero, if the remainder of dividing number by multiple
 :  is greater than or equal to half the value of multiple.
 : MROUND is computed through floor function.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052091851033.aspx
 : @param $number_at the value to round, castable to numeric type
 : @param $multiple_at is the multiple to which you want to round number.
 : @return rounded number up to the desired multiple
 : @error XQP0021(errValue) if parameters cannot be casted to numeric type
:)
declare function excel:mround($number_at as xs:anyAtomicType, $multiple_at as xs:anyAtomicType) as xs:anyAtomicType
{
  let $number := excel:cast-as-numeric($number_at)
  let $multiple := excel:cast-as-numeric($multiple_at)
  let $floor := excel:floor($number, $multiple) return
  if($number ge 0) then
    if(($number - $floor) ge ($multiple div 2)) then
      $floor + $multiple
    else
      $floor
  else
    if((- $number + $floor) ge (-$multiple div 2)) then
      $floor + $multiple
    else
      $floor
};

(:~
 : Converts degrees to radians.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052092281033.aspx
 : @degree the value in degrees
 : @return the value in radians
:)
declare function excel:radians($degree as xs:integer) as xs:decimal
{
  ($degree mod 360) div 180.0 * excel:pi()
};

(:~
 : Converts an arabic numeral to roman, as text.
 : Only the clasic format is supported (out of all formats Excel requires).
 : M is the largest digit, it represents 1000.
 : Numbers bigger than 2000 will be represented by a sequence of "M".
 : D = 500, C = 100, L = 50, X = 10, V = 5, I = 1.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052092381033.aspx
 : @param $number the positive integer
 : @return the roman string representation
 : @error XQP0021(errNum) if the input integer is negative 
:)
declare function excel:roman($number as xs:integer) as xs:string
{
  if($number < 0) then
    fn:error($excel-err:errNum, "Roman function: number should be greater than zero or equal")
  else
  if($number ge 1000) then
    fn:concat("M", excel:roman($number - 1000))
  else
  if($number ge 900) then
    fn:concat("CM", excel:roman($number - 900))
  else
  if($number ge 800) then
    fn:concat("DCCC", excel:roman($number - 800))
  else
  if($number ge 700) then
    fn:concat("DCC", excel:roman($number - 700))
  else
  if($number ge 600) then
    fn:concat("DC", excel:roman($number - 600))
  else
  if($number ge 500) then
    fn:concat("D", excel:roman($number - 500))
  else
  if($number ge 400) then
    fn:concat("CD", excel:roman($number - 400))
  else
  if($number ge 300) then
    fn:concat("CCC", excel:roman($number - 300))
  else
  if($number ge 200) then
    fn:concat("CC", excel:roman($number - 200))
  else
  if($number ge 100) then
    fn:concat("C", excel:roman($number - 100))
  else
  if($number ge 90) then
    fn:concat("XC", excel:roman($number - 90))
  else
  if($number ge 80) then
    fn:concat("LXXX", excel:roman($number - 80))
  else
  if($number ge 70) then
    fn:concat("LXX", excel:roman($number - 70))
  else
  if($number ge 60) then
    fn:concat("LX", excel:roman($number - 60))
  else
  if($number ge 50) then
    fn:concat("L", excel:roman($number - 50))
  else
  if($number ge 40) then
    fn:concat("XL", excel:roman($number - 40))
  else
  if($number ge 30) then
    fn:concat("XXX", excel:roman($number - 30))
  else
  if($number ge 20) then
    fn:concat("XX", excel:roman($number - 20))
  else
  if($number ge 10) then
    fn:concat("X", excel:roman($number - 10))
  else
  if($number = 9) then
    "IX"
  else
  if($number = 8) then
    "VIII"
  else
  if($number = 7) then
    "VII"
  else
  if($number = 6) then
    "VI"
  else
  if($number = 5) then
    "V"
  else
  if($number = 4) then
    "IV"
  else
  if($number = 3) then
    "III"
  else
  if($number = 2) then
    "II"
  else
  if($number = 1) then
    "I"
  else
    ""
};

