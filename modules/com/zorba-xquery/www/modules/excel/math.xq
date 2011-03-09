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
 : This is a library module offering a part of the set of functions
 : defined by Microsoft Excel 2003.
 : 
 : @see <a href="http://office.microsoft.com/en-us/excel/CH062528291033.aspx"
 : target="_blank">Excel 2003 Documentation: Math Functions</a>
 :
 : @spec XQuery Specification: January 2007
 : @author Daniel Turcanu
 :
 :)
module namespace  excel = "http://www.zorba-xquery.com/modules/excel/math" ;

(:~
 : Use excel-err module functions for throwing errors.
 :)
import module namespace excel-err="http://www.zorba-xquery.com/modules/excel/errors";

(:~
 : Checks if the xs:anyAtomicType argument is actually a numeric type
 : or can be converted to numeric.
 : 
 : @param $value Parameter to be checked.
 : @return true if the value can be casted to numeric.
 :)
declare function excel:is-a-number($value as xs:anyAtomicType) as xs:boolean 
{   
  fn:string(fn:number($value)) ne 'NaN' 
};

(:~
 : Cast the xs:anyAtomicType to a numeric type.
 : If the value is already of a numeric type then nothing is changed.
 : Otherwise the value is casted to the numeric type that is most appropriate.
 : 
 : @param $number The parameter can be a number, string, boolean value.
 : @return The casted value.
 : @error XQP0021(errValue) if the value cannot be casted to numeric type.
 :)
declare function excel:cast-as-numeric($number as xs:anyAtomicType) as xs:anyAtomicType
{
  typeswitch ($number) 
    case xs:double return $number
    case xs:decimal return $number
    case xs:double return $number
    case xs:float return $number
    default return
      if ($number castable as xs:integer) then
        xs:integer($number)
      else if ($number castable as xs:decimal) then
        xs:decimal($number)
      else if ($number castable as xs:double) then
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
 : @param $arg The parameter can be a number, string, boolean value.
 : @return The abs value as a numeric type.
 : @error XQP0021(errValue) if arg cannot be casted to numeric type.
 : @example rbkt/Queries/zorba/excel/math/abs1.xq
 : @example rbkt/Queries/zorba/excel/math/abs2.xq
 : @example rbkt/Queries/zorba/excel/math/abs3.xq
 : @example rbkt/Queries/zorba/excel/math/abs4.xq
 : @example rbkt/Queries/zorba/excel/math/abs5.xq
 : @example rbkt/Queries/zorba/excel/math/abs6.xq
 :)
declare function excel:abs($arg as xs:anyAtomicType) as xs:anyAtomicType
{
  fn:abs(excel:cast-as-numeric($arg))
};

(:~
 : Returns number rounded up, away from zero, to the nearest multiple of significance.
 : Significance must have the same sign as number.
 : Number and significance must be of a numeric type or castable to numeric.
 : Significance must not be zero.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052090071033.aspx
 : @param $number The value you want to round.
 : @param $significance The multiple to which you want to round.
 : @return The rounded value.
 : @error XQP0021(errValue) if parameters cannot be casted to numeric type.
 : @error XQP0021(errNum) if significance is zero or it doesn't have the same sign as number.
 : @example rbkt/Queries/zorba/excel/math/ceiling1.xq
 : @example rbkt/Queries/zorba/excel/math/ceiling2.xq
 : @example rbkt/Queries/zorba/excel/math/ceiling3.xq
 : @example rbkt/Queries/zorba/excel/math/ceiling4.xq
 : @example rbkt/Queries/zorba/excel/math/ceiling5.xq
 : @example rbkt/Queries/zorba/excel/math/ceiling6.xq
 : @example rbkt/Queries/zorba/excel/math/ceiling7.xq
 :)
declare function excel:ceiling(
  $number        as xs:anyAtomicType,
  $significance  as xs:anyAtomicType) as xs:anyAtomicType
{
  let $num := excel:cast-as-numeric($number)
  let $sig := excel:cast-as-numeric($significance)
  return
    if ($sig eq 0) then
      fn:error($excel-err:errNum, "Ceiling function does not accept significance 0")
    else if ($num * $sig ge 0) then
	    fn:ceiling($num div $sig) * $sig
    else
      fn:error($excel-err:errNum, "Ceiling function: both arguments must have the same sign")
};

(:~
 : Returns number rounded up to the nearest even integer.
 : Regardless of the sign of number, a value is rounded up when adjusted away from zero. 
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052090801033.aspx
 : @param $number The value to round.
 : @return The rounded value casted as numeric type.
 : @error XQP0021(errValue) if parameters cannot be casted to numeric type.
 : @example rbkt/Queries/zorba/excel/math/even1.xq
 : @example rbkt/Queries/zorba/excel/math/even2.xq
 : @example rbkt/Queries/zorba/excel/math/even3.xq
 : @example rbkt/Queries/zorba/excel/math/even4.xq
 : @example rbkt/Queries/zorba/excel/math/even5.xq
 : @example rbkt/Queries/zorba/excel/math/even6.xq
 :)
declare function excel:even($number as xs:anyAtomicType) as xs:anyAtomicType
{
  let $num := excel:cast-as-numeric($number)
  return
    if ($num = 0) then
      0
    else
      let $intnum := excel:ceiling($num, excel:sign($num))
      return
        if ($intnum mod 2 ne 0) then
          if ($intnum gt 0) then
            $intnum + 1
          else
            $intnum - 1
        else
          $intnum
};

(:~
 : Function for computing factorial.
 : This function should not be used outside this module.
 : This recursive function computes: number * fact(number-1)
 : 
 : @param $intnum A positive integer.
 : @return The factorial of intnum.
:)
declare %private function excel:fact-integer($intnum as xs:integer) as xs:integer
{
  if ($intnum = 1) then
    1
  else
    $intnum * excel:fact-integer($intnum - 1)
};

(:~
 : Returns the factorial of a number.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052090841033.aspx
 : @param $number The nonnegative number you want the factorial of.
 :        If number is not an integer, it is truncated.
 : @return Returns the factorial of a number. The factorial of a number is equal to 1*2*3*...* number.
 : @error XQP0021(errNum) if the number is smaller than zero
 : @example rbkt/Queries/zorba/excel/math/fact1.xq
 : @example rbkt/Queries/zorba/excel/math/fact2.xq
 : @example rbkt/Queries/zorba/excel/math/fact3.xq
 : @example rbkt/Queries/zorba/excel/math/fact4.xq
 : @example rbkt/Queries/zorba/excel/math/fact5.xq
:)
declare function excel:fact($number as xs:anyAtomicType) as xs:integer
{
  let $num := excel:cast-as-numeric($number) return
    if ($num eq 0) then
      1
    else
      if ($num lt 0) then
        fn:error($excel-err:errNum, "Fact function does not accept numbers less than zero")
      else
        excel:fact-integer(xs:integer($num))
};

(:~
 : Rounds number down, toward zero, to the nearest multiple of significance.
 : Significance must have the same sign as number.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052090941033.aspx
 : @param $number The value you want to round. The value is casted to numeric.
 : @param $significance The multiple to which you want to round.
 : @return The rounded value as numeric type.
 : @error XQP0021(errValue) if parameters cannot be casted to numeric type.
 : @error XQP0021(errNum) if significance is zero or it doesn't have the same sign as number.
 : @example rbkt/Queries/zorba/excel/math/floor1.xq
 : @example rbkt/Queries/zorba/excel/math/floor2.xq
 : @example rbkt/Queries/zorba/excel/math/floor3.xq
 : @example rbkt/Queries/zorba/excel/math/floor4.xq
 : @example rbkt/Queries/zorba/excel/math/floor5.xq
:)
declare function excel:floor(
  $number as xs:anyAtomicType,
  $significance as xs:anyAtomicType) as xs:anyAtomicType
{
  let $num := excel:cast-as-numeric($number)
  let $sig := excel:cast-as-numeric($significance)
  return
    if ($sig eq 0) then
      fn:error($excel-err:errNum, "Floor function does not accept significance 0")
    else if ($num * $sig ge 0) then
      fn:floor($num div $sig) * $sig
    else
      fn:error($excel-err:errNum, "Floor function: both arguments must have the same sign")
};
 
(:~
 : Rounds a number down to the nearest integer.
 : Positive numbers are rounded toward zero, negative numbers are rounded away from zero.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052091421033.aspx
 : @param $number The value to be rounded.
 : @return The rounded integer.
 : @error XQP0021(errValue) if parameter cannot be casted to numeric type
 : @example rbkt/Queries/zorba/excel/math/int1.xq
 : @example rbkt/Queries/zorba/excel/math/int2.xq
 : @example rbkt/Queries/zorba/excel/math/int3.xq
 : @example rbkt/Queries/zorba/excel/math/int4.xq
:)
declare function excel:int($number as xs:anyAtomicType) as xs:integer
{
  xs:integer(fn:floor(excel:cast-as-numeric($number)))
};

(:~
 : Returns the remainder after number is divided by divisor.
 : The result has the same sign as divisor.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052091821033.aspx
 : @param $number The number for which you want to find the remainder.
 : @param $divisor The number by which you want to divide number.
 :        This cannot be zero.
 : @return The remainder from division as numeric type.
 : @error XQP0021(errValue) if parameters cannot be casted to numeric type.
 : @error XQP0021(errDiv0) if divisor is zero after casting to numeric.
 : @example rbkt/Queries/zorba/excel/math/mod1.xq
 : @example rbkt/Queries/zorba/excel/math/mod2.xq
 : @example rbkt/Queries/zorba/excel/math/mod3.xq
 : @example rbkt/Queries/zorba/excel/math/mod4.xq
 :)
declare function excel:mod(
  $number as xs:anyAtomicType,
  $divisor as xs:anyAtomicType) as xs:anyAtomicType
{
  let $num := excel:cast-as-numeric($number)
  let $div := excel:cast-as-numeric($divisor) return
    if ($div eq 0) then
      fn:error($excel-err:errDiv0, "Mod operator: divide by 0")
    else
      let $result := $num mod $div
      return
        if ($result * $div lt 0) then
          -$result
        else
          $result
};
 
(:~
 : Returns number rounded up to the nearest odd integer, away from zero.
 : 
 : @see  http://office.microsoft.com/en-us/excel/HP052092031033.aspx
 : @param $number The value to round.
 : @return The odd integer.
 : @error XQP0021(errValue) if parameter cannot be casted to numeric type.
 : @example rbkt/Queries/zorba/excel/math/odd1.xq
 : @example rbkt/Queries/zorba/excel/math/odd2.xq
 : @example rbkt/Queries/zorba/excel/math/odd3.xq
 : @example rbkt/Queries/zorba/excel/math/odd4.xq
 : @example rbkt/Queries/zorba/excel/math/odd5.xq
 : @example rbkt/Queries/zorba/excel/math/odd6.xq
 :)
declare function excel:odd($number as xs:anyAtomicType) as xs:integer
{
  let $num := excel:cast-as-numeric($number) return
  if ($num eq 0) then
    1
  else
    let $intnum := excel:ceiling($num, excel:sign($num))
    return
      if ($intnum mod 2 eq 0) then
        if ($intnum ge 0) then
          ($intnum + 1) cast as xs:integer
        else
          ($intnum - 1) cast as xs:integer
      else
        $intnum cast as xs:integer
};
 
(:~
 : Return the value of PI as decimal with 15 digits.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052092141033.aspx
 : @return The value of PI with 15 digits.
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
 : @param $number The base number.
 : @param $power The exponent as integer (cannot be floating point like in Excel).
 : @return The result as numeric type.
 : @error XQP0021(errValue) if parameter cannot be casted to numeric type.
 : @error XQP0021(errValue) if power is smaller than zero.
 : @example rbkt/Queries/zorba/excel/math/power1.xq
 : @example rbkt/Queries/zorba/excel/math/power3.xq
 : @example rbkt/Queries/zorba/excel/math/power4.xq
 : @example rbkt/Queries/zorba/excel/math/power5.xq
 :)
declare function excel:power(
  $number as xs:anyAtomicType,
  $power as xs:integer) as xs:anyAtomicType
{
  let $num := excel:cast-as-numeric($number)
  return
    if ($power lt 0) then
      fn:error($excel-err:errValue, "Power function: power must be greater or equal than zero")
    else if ($power eq 0) then
      1
    else if ($power = 1) then
      $num
    else
      let $retval := excel:power($num, $power idiv 2)
      return
        $retval * $retval * excel:power($num, $power mod 2)   
 };
 
(:~
 : Function for product.
 : This function should not be used outside this module.
 : Multiplies all numbers in the sequence.
 :
 : @param $numbers The list of arguments to be casted to numeric and multiplied.
 : @return The multiplication result as numeric type.
 : @error XQP0021(errValue) if parameters cannot be casted to numeric type.
 :)
declare %private function excel:product-internal($numbers as xs:anyAtomicType*) as xs:anyAtomicType
{
  if (fn:empty($numbers)) then
    1
  else
    let $x := excel:cast-as-numeric($numbers[1])
    return
      $x * excel:product-internal(fn:subsequence($numbers, 2))
};
 
(:~
 : Multiplies all the numbers given as arguments and returns the product.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052092231033.aspx
 : @param $numbers The sequence of arguments convertable to numeric types.
 :        The sequence can be of any length.
 : @return The multiplication result as numeric type.
 : @error XQP0021(errValue) if parameters cannot be casted to numeric type.
 : @example rbkt/Queries/zorba/excel/math/product1.xq
 : @example rbkt/Queries/zorba/excel/math/product2.xq
 : @example rbkt/Queries/zorba/excel/math/product3.xq
 : @example rbkt/Queries/zorba/excel/math/product4.xq
 : @example rbkt/Queries/zorba/excel/math/product5.xq
 :)
declare function excel:product($numbers as xs:anyAtomicType*) as xs:anyAtomicType
{
  if (fn:empty($numbers)) then
    0
  else
    excel:product-internal($numbers)
};
 
(:~
 : Returns the integer portion of a division.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052092271033.aspx
 : @param $numerator The divident.
 : @param $denominator The divisor. It cannot be zero.
 : @return The result value as numeric type.
 : @error XQP0021(errValue) if parameters cannot be casted to numeric type.
 : @error XQP0021(div0) if denominator casted as numeric type has value zero.
 : @example rbkt/Queries/zorba/excel/math/quotient1.xq
 : @example rbkt/Queries/zorba/excel/math/quotient2.xq
 : @example rbkt/Queries/zorba/excel/math/quotient3.xq
 : @example rbkt/Queries/zorba/excel/math/quotient4.xq
 :)
declare function excel:quotient(
  $numerator   as xs:anyAtomicType,
  $denominator as xs:anyAtomicType) as xs:integer
{
  let $numer := excel:cast-as-numeric($numerator)
  let $denom := excel:cast-as-numeric($denominator)
  return
    if ($denom eq 0) then
      fn:error($excel-err:errDiv0, "Quotient function: divide by 0")
    else
      xs:integer($numer div $denom)
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
 : @param $number The number to round, castable to a numeric type.
 : @param $precision The number of decimal places to keep.
 : @return The rounded number as numeric type.
 : @error XQP0021(errValue) if parameters cannot be casted to numeric type.
 : @example rbkt/Queries/zorba/excel/math/round1.xq
 : @example rbkt/Queries/zorba/excel/math/round2.xq
 : @example rbkt/Queries/zorba/excel/math/round3.xq
 : @example rbkt/Queries/zorba/excel/math/round4.xq
 :)
declare function excel:round(
  $number as xs:anyAtomicType,
  $precision as xs:integer) as xs:anyAtomicType
{
  let $num := excel:cast-as-numeric($number)
  return
    if ($precision ge 0) then
      let $exp_prec := excel:power(10, $precision)
      return 
        if ($num ge 0) then
          fn:floor($num * $exp_prec + 0.5) div $exp_prec
        else 
          -fn:floor(-$num * $exp_prec + 0.5) div $exp_prec
    else
      let $exp_prec := excel:power(10, -$precision)
      return
        if ($num ge 0) then
          fn:floor($num div $exp_prec + 0.5) * $exp_prec
        else 
          -fn:floor(-$num div $exp_prec + 0.5) * $exp_prec
};
  
(:~
 : Rounds a number down, toward zero.
 : If num_digits is greater than 0 (zero), then number is rounded down 
 : to the specified number of decimal places. 
 : If num_digits is 0, then number is rounded down to the nearest integer. 
 : If num_digits is less than 0, then number is rounded down to the left of the decimal point. 
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052092411033.aspx
 : @param $number The number to round, castable to numeric type.
 : @param $precision The number of decimal places to keep.
 : @return the truncated number toward zero, as numeric type.
 : @error XQP0021(errValue) if parameters cannot be casted to numeric type.
 : @example rbkt/Queries/zorba/excel/math/rounddown1.xq
 : @example rbkt/Queries/zorba/excel/math/rounddown2.xq
 : @example rbkt/Queries/zorba/excel/math/rounddown3.xq
 : @example rbkt/Queries/zorba/excel/math/rounddown4.xq
 : @example rbkt/Queries/zorba/excel/math/rounddown5.xq
 :)
declare function excel:rounddown(
  $number     as xs:anyAtomicType,
  $precision  as xs:integer) as xs:anyAtomicType
{
  let $num := excel:cast-as-numeric($number)
  return
    if ($precision ge 0) then
      let $exp_prec := excel:power(10, $precision)
      return 
        if ($num ge 0) then
          fn:floor($num * $exp_prec) div $exp_prec
        else
          -fn:floor(-$num * $exp_prec) div $exp_prec
    else
      let $exp_prec := excel:power(10, -$precision)
      return
        if ($num ge 0) then
          fn:floor($num div $exp_prec) * $exp_prec
        else
          -fn:floor(-$num div $exp_prec) * $exp_prec
};
 
(:~
 : Rounds a number up, away from 0 (zero).
 : If num_digits is greater than 0 (zero), then number is rounded down 
 : to the specified number of decimal places. 
 : If num_digits is 0, then number is rounded down to the nearest integer. 
 : If num_digits is less than 0, then number is rounded down to the left of the decimal point. 
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052092421033.aspx
 : @param $number The number to round, castable to numeric type.
 : @param $precision The number of decimal places to keep.
 : @return The truncated number away from zero, as numeric type.
 : @error XQP0021(errValue) if parameters cannot be casted to numeric type.
 : @example rbkt/Queries/zorba/excel/math/roundup1.xq
 : @example rbkt/Queries/zorba/excel/math/roundup2.xq
 : @example rbkt/Queries/zorba/excel/math/roundup3.xq
 : @example rbkt/Queries/zorba/excel/math/roundup4.xq
 : @example rbkt/Queries/zorba/excel/math/roundup5.xq
 :)
declare function excel:roundup(
  $number     as xs:anyAtomicType,
  $precision  as xs:integer) as xs:anyAtomicType
{
  let $num := excel:cast-as-numeric($number)
  return
    if ($precision ge 0) then
      let $exp_prec := excel:power(10, $precision)
      return
        if ($num ge 0) then
           fn:ceiling($num * $exp_prec) div $exp_prec
        else 
          -fn:ceiling(-$num * $exp_prec) div $exp_prec
    else
      let $exp_prec := excel:power(10, -$precision)
      return
        if ($num ge 0) then
          fn:ceiling($num div $exp_prec) * $exp_prec
        else
          -fn:ceiling(-$num div $exp_prec) * $exp_prec
};
 
(:~
 : Determines the sign of a number. 
 : Returns 1 if the number is positive, zero (0) if the number is 0, 
 : and -1 if the number is negative.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052092551033.aspx
 : @param $number The argument castable to numeric type.
 : @return The sign as (-1, 0, 1).
 : @error XQP0021(errValue) if parameters cannot be casted to numeric type.
 : @example rbkt/Queries/zorba/excel/math/sign1.xq
 : @example rbkt/Queries/zorba/excel/math/sign2.xq
 : @example rbkt/Queries/zorba/excel/math/sign3.xq
 :)
declare function excel:sign($number as xs:anyAtomicType) as xs:integer
{
  let $num := excel:cast-as-numeric($number)
  return
    if ($num eq 0) then
      0
    else if ($num gt 0) then
      1
    else
      -1   
 };

(:~
 : Adds all the numbers in the sequence.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052092901033.aspx
 : @param $numbers The sequence of arguments castable to numeric types.
 :        The sequence can be of any length.
 : @return The sum as numeric type.
 : @error XQP0021(errValue) if parameters cannot be casted to numeric type.
 : @example rbkt/Queries/zorba/excel/math/sum1.xq
 : @example rbkt/Queries/zorba/excel/math/sum2.xq
 : @example rbkt/Queries/zorba/excel/math/sum3.xq
 :)
declare function excel:sum($numbers as xs:anyAtomicType*) as xs:anyAtomicType
{
  if (fn:empty($numbers)) then
    0
  else
    let $x := excel:cast-as-numeric($numbers[1])
    return
      $x + excel:sum(fn:subsequence($numbers,2))
 };

(:~
 : Truncates a number to an integer by removing the fractional part of the number.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052093241033.aspx
 : @param $number The argument castable to numeric type.
 : @return The integer value.
 : @error XQP0021(errValue) if parameter cannot be casted to numeric type.
 : @example rbkt/Queries/zorba/excel/math/trunc1.xq
 : @example rbkt/Queries/zorba/excel/math/trunc2.xq
 :)
declare function excel:trunc($number as xs:anyAtomicType ) as xs:integer
{
  xs:integer(excel:cast-as-numeric($number))
};
 
(:~
 : Truncates a number down to precision.
 : This behaves exactly like rounddown.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052093241033.aspx
 : @param $number The argument castable to numeric type.
 : @param $precision The number of decimal places to keep .
 : @return The integer value.
 : @error XQP0021(errValue) if parameter cannot be casted to numeric type.
 : @example rbkt/Queries/zorba/excel/math/trunc3.xq
 :)
declare function excel:trunc(
  $number as xs:anyAtomicType,
  $precision as xs:integer) as xs:anyAtomicType
{
  excel:rounddown(excel:cast-as-numeric($number), $precision)
};
 
(:~
 : Helper function.<br/>
 : Sorts a sequence of numbers or arguments castable to numeric.
 : It first casts all arguments to numeric and then sorts ascending.
 :  
 : @param $numbers The sequence of arguments castable to numeric.
 : @return The sorted sequence as numeric types.
 : @error XQP0021(errValue) if parameters cannot be casted to numeric type.
 :)
declare function excel:sort-numbers($numbers as xs:anyAtomicType*) as xs:anyAtomicType*
{
  let $sorted-numbers :=
    (
      for $number in $numbers 
      let $num := excel:cast-as-numeric($number)
      order by $num
      return $num
    )
  return $sorted-numbers
};

(:~
 : Converts radians into degrees.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052090561033.aspx
 : @param $radian The value in radians.
 : @return The value in degrees 0 .. 360 or 0 .. -360.
 :)
declare function excel:degrees($radian as xs:double) as xs:integer
{
  xs:integer(($radian * 180 div excel:pi()) mod 360)
};

(:~
 : Returns the double factorial of a number.
 : Computes the double factorial of n as n(n-2)(n-4)...
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052090851033.aspx
 : @param $number The positive integer value.
 : @return The result as integer.
 : @error XQP0021(errNum) if the number is negative.
 : @example rbkt/Queries/zorba/excel/math/priority1/factdouble1.xq
 : @example rbkt/Queries/zorba/excel/math/priority1/factdouble2.xq
 :)
declare function excel:factdouble($number as xs:integer) as xs:integer
{
  if ($number lt 0) then
    fn:error($excel-err:errNum, "Factdouble function: number should be greater than zero or equal")
  else if ($number eq 1) then
    1
  else if ($number eq 2) then
    2
  else
    $number * excel:factdouble($number - 2) 
};

(:~
 : Function for computing GCD.
 : This function should not be used outside this module.
 : It calculates the minimum value from a sequence of positive integers, 
 : not taking into account the zero value.
 : 
 : @param $numbers The sequence of positive integers.
 : @return The minimum value. If the sequence contains only zero values, then zero is returned.
 :)
declare %private function excel:min-without-zero($numbers as xs:integer+) as xs:integer
{
  if (fn:count($numbers) eq 1) then
    $numbers[1]
  else
    let $min-other := excel:min-without-zero(fn:subsequence($numbers, 2))
    return
      if ($numbers[1] eq 0) then
        $min-other
      else if ($min-other eq 0) then
        $numbers[1]
      else if ($numbers[1] lt $min-other) then
        $numbers[1]
      else
        $min-other
};

(:~
 : Function for computing GCD.
 : This function should not be used outside this module.
 : Checks if all integer numbers from a sequence divide exactly to a divident.
 :
 : @param $numbers The positive integers.
 : @param $divident The divident to be tried.
 : @return true if the numbers divide exactly.
:)
declare %private function excel:try-exact-divide(
  $numbers as xs:integer*,
  $divident as xs:integer) as xs:boolean
{
  if (fn:empty($numbers)) then
    fn:true()
  else
    if ($numbers[1] mod $divident ne 0) then
      fn:false()
    else
      excel:try-exact-divide(fn:subsequence($numbers, 2), $divident)
};

(:~
 : Function for computing GCD.
 : This function should not be used outside this module.
 : This function iterates through possible divisors and checks if the sequence
 : divides exactly to any of those. It starts from the minimum value from the
 : sequence and searches downwards.
 :
 : @param $numbers The sequence of positive integers.
 : @param $min-nonzero The minimum value of numbers sequence, excluding the zero value.
 : @param $iteration Which iteration is it. It starts from 1 and continues
 :        to min-nonzero/2.
 : @return The greatest common divisor if found, or 1 if not found.
 :)
declare %private function excel:iterate-all-gcd(
  $numbers as xs:integer*, 
  $min-nonzero as xs:integer,
  $iteration as xs:integer) as xs:integer
{
  if ($min-nonzero mod $iteration eq 0) then
    if (excel:try-exact-divide($numbers, $min-nonzero idiv $iteration)) then
      $min-nonzero idiv $iteration
    else
      excel:iterate-all-gcd($numbers, $min-nonzero, $iteration + 1)
  else
    if ($iteration > $min-nonzero idiv 2) then
      1
    else
      excel:iterate-all-gcd($numbers, $min-nonzero, $iteration + 1)
};

(:~
 : Returns the greatest common divisor GCD of a sequence of integers.
 : The sequence can have one or more positive integers.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052091041033.aspx
 : @param $numbers The sequence of positive integers.
 : @return The GCD as integer.
 : @error XQP0021(errNum) if any number is smaller than zero.
 : @example rbkt/Queries/zorba/excel/math/priority1/gcd1.xq
 : @example rbkt/Queries/zorba/excel/math/priority1/gcd2.xq
 : @example rbkt/Queries/zorba/excel/math/priority1/gcd3.xq
 : @example rbkt/Queries/zorba/excel/math/priority1/gcd4.xq
 : @example rbkt/Queries/zorba/excel/math/priority1/gcd5.xq
 : @example rbkt/Queries/zorba/excel/math/priority1/gcd6.xq
 : @example rbkt/Queries/zorba/excel/math/priority1/gcd7.xq
 : @example rbkt/Queries/zorba/excel/math/priority1/gcd8.xq
 :)
declare function excel:gcd($numbers as xs:integer+) as xs:integer
{
  if (fn:count($numbers) = 1) then
    $numbers[1]
  else
    let $minval := excel:min-without-zero($numbers)
    return
      if ($minval lt 0) then
        fn:error($excel-err:errNum, "gcd function: numbers should be greater than zero or equal")
      else if ($minval eq 0) then
        0
      else 
        excel:iterate-all-gcd($numbers, $minval, 1)
};

(:~
 : Returns the least common multiple of integers.<br/>
 : LCM for two numbers is computed by multiplying them and dividing with GCD. <br/>
 : The function is applied recursively replacing the first two numbers in the sequence with their LCM.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052091521033.aspx
 : @param $numbers The sequence of one or more positive integers.
 : @return The LCM as integer.
 : @error XQP0021(errNum) if any number is smaller than zero.
 : @example rbkt/Queries/zorba/excel/math/priority1/lcm1.xq
 : @example rbkt/Queries/zorba/excel/math/priority1/lcm2.xq
 : @example rbkt/Queries/zorba/excel/math/priority1/lcm3.xq
 : @example rbkt/Queries/zorba/excel/math/priority1/lcm4.xq
 : @example rbkt/Queries/zorba/excel/math/priority1/lcm5.xq
 :)
declare function excel:lcm($numbers as xs:integer+) as xs:integer
{
  if(count($numbers) eq 1) then
    $numbers[1]
  else
  if(count($numbers) eq 2) then
    let $product := excel:product(fn:distinct-values($numbers))
    return
      if ($product eq 0) then
        0
      else
        $product idiv excel:gcd($numbers)
  else
    excel:lcm((excel:lcm(($numbers[1], $numbers[2])), subsequence($numbers, 3)))

};

(:~
 : Returns a number rounded to the desired multiple.
 : MROUND rounds up, away from zero, if the remainder of dividing number by multiple
 : is greater than or equal to half the value of multiple.
 : MROUND is computed through floor function.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052091851033.aspx
 : @param $number The value to round, castable to numeric type.
 : @param $multiple The multiple to which you want to round number.
 : @return The rounded number up to the desired multiple.
 : @error XQP0021(errValue) if parameters cannot be casted to numeric type.
 : @example rbkt/Queries/zorba/excel/math/priority1/mround1.xq
 : @example rbkt/Queries/zorba/excel/math/priority1/mround2.xq
 : @example rbkt/Queries/zorba/excel/math/priority1/mround3.xq
 :)
declare function excel:mround(
  $number   as xs:anyAtomicType,
  $multiple as xs:anyAtomicType) as xs:anyAtomicType
{
  let $num := excel:cast-as-numeric($number)
  let $mul := excel:cast-as-numeric($multiple)
  let $floor := excel:floor($num, $mul) return
  if ($num ge 0) then
    if (($num - $floor) ge ($mul div 2)) then
      $floor + $mul
    else
      $floor
  else
    if ((-$num + $floor) ge (-$mul div 2)) then
      $floor + $mul
    else
      $floor
};

(:~
 : Converts degrees to radians.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052092281033.aspx
 : @param $degree An angle in degrees that you want to convert.
 : @return The value in radians.
 : @example rbkt/Queries/zorba/excel/math/priority1/radians1.xq
 : @example rbkt/Queries/zorba/excel/math/priority1/radians2.xq
 : @example rbkt/Queries/zorba/excel/math/priority1/radians3.xq
 :)
declare function excel:radians($degree as xs:integer) as xs:decimal
{
  ($degree mod 360) div 180.0 * excel:pi()
};

(:~
 : Converts an arabic numeral to roman, as text.
 : Only the clasic format is supported (out of all formats Excel requires).<br/>
 : M is the largest digit, it represents 1000.
 : Numbers bigger than 2000 will be represented by a sequence of "M".<br/>
 : D = 500, C = 100, L = 50, X = 10, V = 5, I = 1.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052092381033.aspx
 : @param $number A positive integer.
 : @return The roman string representation.
 : @error XQP0021(errNum) if the input integer is negative 
 : @example rbkt/Queries/zorba/excel/math/priority1/roman1.xq
 : @example rbkt/Queries/zorba/excel/math/priority1/roman2.xq
 : @example rbkt/Queries/zorba/excel/math/priority1/roman3.xq
 :)
declare function excel:roman($number as xs:integer) as xs:string
{
  if ($number lt 0) then
    fn:error($excel-err:errNum, "Roman function: number should be greater than zero or equal")
  else if ($number ge 1000) then
    fn:concat("M", excel:roman($number - 1000))
  else if ($number ge 900) then
    fn:concat("CM", excel:roman($number - 900))
  else if ($number ge 800) then
    fn:concat("DCCC", excel:roman($number - 800))
  else if ($number ge 700) then
    fn:concat("DCC", excel:roman($number - 700))
  else if ($number ge 600) then
    fn:concat("DC", excel:roman($number - 600))
  else if ($number ge 500) then
    fn:concat("D", excel:roman($number - 500))
  else if ($number ge 400) then
    fn:concat("CD", excel:roman($number - 400))
  else if ($number ge 300) then
    fn:concat("CCC", excel:roman($number - 300))
  else if ($number ge 200) then
    fn:concat("CC", excel:roman($number - 200))
  else if ($number ge 100) then
    fn:concat("C", excel:roman($number - 100))
  else if ($number ge 90) then
    fn:concat("XC", excel:roman($number - 90))
  else if ($number ge 80) then
    fn:concat("LXXX", excel:roman($number - 80))
  else if ($number ge 70) then
    fn:concat("LXX", excel:roman($number - 70))
  else if ($number ge 60) then
    fn:concat("LX", excel:roman($number - 60))
  else if ($number ge 50) then
    fn:concat("L", excel:roman($number - 50))
  else if ($number ge 40) then
    fn:concat("XL", excel:roman($number - 40))
  else if ($number ge 30) then
    fn:concat("XXX", excel:roman($number - 30))
  else if ($number ge 20) then
    fn:concat("XX", excel:roman($number - 20))
  else if ($number ge 10) then
    fn:concat("X", excel:roman($number - 10))
  else if ($number eq 9) then
    "IX"
  else if ($number eq 8) then
    "VIII"
  else if ($number eq 7) then
    "VII"
  else if ($number eq 6) then
    "VI"
  else if ($number eq 5) then
    "V"
  else if ($number eq 4) then
    "IV"
  else if ($number eq 3) then
    "III"
  else if ($number eq 2) then
    "II"
  else if ($number eq 1) then
    "I"
  else
    ""
};
