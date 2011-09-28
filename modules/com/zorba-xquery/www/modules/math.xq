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
 : Extensive math library.
 :
 : @author Daniel Turcanu, Dan Muresan
 : @project XDM/atomic
 :)
module namespace math = "http://www.zorba-xquery.com/modules/math";

(:~
 : W3C Math namespace URI.
:)
declare namespace W3Cmath = "http://www.w3.org/2005/xpath-functions/math";

declare namespace ver = "http://www.zorba-xquery.com/options/versioning";
declare option ver:module-version "2.0";

(:~
 : Errors namespace URI.
:)
declare variable $math:errNS as xs:string := "http://www.zorba-xquery.com/modules/math";

(:~
 : xs:QName with namespace URI="http://www.zorba-xquery.com/modules/math" and local name "math:Value" 
:)
declare variable $math:errValue as xs:QName := fn:QName($math:errNS, "math:Value");

(:~
 : xs:QName with namespace URI="http://www.zorba-xquery.com/modules/math" and local name "math:Num"
:)
declare variable $math:errNum as xs:QName := fn:QName($math:errNS, "math:Num");

(:~
 : xs:QName with namespace URI="http://www.zorba-xquery.com/modules/math" and local name "math:Div0"
:)
declare variable $math:errDiv0 as xs:QName := fn:QName($math:errNS, "math:Div0");

(:~
 : xs:QName with namespace URI="http://www.zorba-xquery.com/modules/math" and local name "math:NA"
:)
declare variable $math:errNA as xs:QName := fn:QName($math:errNS, "math:NA");


(:~
 : Returns the hyperbolic cosine of x.
 : If the result it too large, INF is returned.
 : 
 : @param $arg must be smaller than 7.104760e+002
 : @return cosh(arg)
 :)
declare function math:cosh ($arg as xs:double) as xs:double external;

(:~
 : Inverse hyperbolic cosine.
 :
 : @param $arg the arg
 : @return the result of acosh(arg)
 :)
declare function math:acosh ($arg as xs:double) as xs:double external;

(:~
 : Function performing the modulo operation between the two arguments.
 : 
 : @param $x the x
 : @param $y the y
 : @return The remainder of x/y.
 :)
declare function math:fmod ($x as xs:double, $y as xs:double) as xs:double external;

(:~
 : Returns the argument split as mantissa and exponent. 
 : The recombining formula is (mantissa * 2^exponent).
 : 
 : @param $arg the double to be split.
 : @return A sequence of two doubles (mantissa, exponent)
 :)
declare function math:frexp ($arg as xs:double) as xs:double+ external;

(:~
 : Computes a real number from the mantissa and exponent.
 : The formula is (x * 2^i).
 : 
 : @param $x the mantissa
 : @param $i the exponent
 : @return the computed real number
 :)
declare function math:ldexp ($x as xs:double, $i as xs:integer) as xs:double external;

(:~
 : Splits a floating-point value into fractional and integer parts.
 : Both the fraction and integer keep the original sign of the value.
 : 
 : @param $arg the double to be split.
 : @return A sequence of two doubles (fraction, integer)
 :)
declare function math:modf ($arg as xs:double) as xs:double+ external;

(:~
 : Calculate hyperbolic sine.
 :
 : @param $arg the arg
 : @return the result of sinh(arg)
 :)
declare function math:sinh ($arg as xs:double) as xs:double external;

(:~
 : Inverse hyperbolic sine of the number.
 :
 : @param $arg the arg
 : @return the result of asinh(arg)
 :)
declare function math:asinh($arg as xs:double) as xs:double external;

(:~
 : Calculate the hyperbolic tangent.
 :
 : @param $arg the arg
 : @return the result of tanh(arg)
 :)
declare function math:tanh($arg as xs:double) as xs:double external;

(:~
 : Calculate the hyperbolic tangent.
 :
 : @param $arg must be in range -1 ... +1 (exclusive)
 : @return the result of atanh(arg)
 :)
declare function math:atanh($arg as xs:double) as xs:double external;

(:~
 : Convert angle from degrees to radians. <br/>
 : The parameter is first converted to value range of (-360, 360).
 : 
 : @param $deg angle in  degrees
 : @return value in radians (-2PI, 2PI)
 :)
declare function math:deg-to-rad($deg as xs:double) as xs:double
{
  ($deg mod 360) * 2 * W3Cmath:pi() div 360
};

(:~
 : Convert angle from radians to degrees. <br/>
 : 
 : @param $rad value in radians
 : @return value in degrees (-360, 360)
 :)
declare function math:rad-to-deg($rad as xs:double) as xs:double
{
  ($rad * 360 div 2 div W3Cmath:pi()) mod 360
};

(:~
 : Checks if the double value is positive or negative infinite.
 :
 : @param $arg the double to be checked
 : @return boolean true if argument is pos INF or neg INF
 :)
declare function math:is_inf($arg as xs:double) as xs:boolean external;

(:~
 : Checks if the double value is Not a Number (NaN).
 :
 : @param $arg the arg
 : @return boolean true if the double is NaN
 :)
declare function math:is_nan($arg as xs:double) as xs:boolean external;



(:functions borrowed from excel module :)
(:Excel math functions:)

(:~
 : Borrowed from excel module.<br/>
 : Checks if the xs:anyAtomicType argument is actually a numeric type
 : or can be converted to numeric.
 : 
 : @param $value Parameter to be checked.
 : @return true if the value can be casted to numeric.
 :)
declare function math:is-a-number($value as xs:anyAtomicType) as xs:boolean 
{   
  fn:string(fn:number($value)) ne 'NaN' 
};

(:~
 : Borrowed from excel module.<br/>
 : Cast the xs:anyAtomicType to a numeric type.
 : If the value is already of a numeric type then nothing is changed.
 : Otherwise the value is casted to the numeric type that is most appropriate.
 : 
 : @param $number The parameter can be a number, string, boolean value.
 : @return The casted value.
 : @error math:errValue if the value cannot be casted to numeric type.
 :)
declare function math:cast-as-numeric($number as xs:anyAtomicType) as xs:anyAtomicType
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
        fn:error($math:errValue, "Provided value is not a number", $number)
};

(:~
 : Borrowed from excel module.<br/>
 : Returns number rounded up, away from zero, to the nearest multiple of significance.
 : Significance must have the same sign as number.
 : Number and significance must be of a numeric type or castable to numeric.
 : Significance must not be zero.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052090071033.aspx
 : @param $number The value you want to round.
 : @param $significance The multiple to which you want to round.
 : @return The rounded value.
 : @error math:errNum if significance is zero or it doesn't have the same sign as number.
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_ceiling1.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_ceiling2.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_ceiling3.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_ceiling4.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_ceiling5.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_ceiling6.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_ceiling7.xq
 :)
declare function math:ceiling(
  $number        as xs:double,
  $significance  as xs:double) as xs:double
{
  if ($significance eq 0) then
    fn:error($math:errNum, "Ceiling function does not accept significance 0")
  else if ($number * $significance ge 0) then
	  fn:ceiling($number div $significance) * $significance
  else
    fn:error($math:errNum, "Ceiling function: both arguments must have the same sign")
};

(:~
 : Borrowed from excel module.<br/>
 : Returns number rounded up to the nearest even integer.
 : Regardless of the sign of number, a value is rounded up when adjusted away from zero. 
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052090801033.aspx
 : @param $number The value to round.
 : @return The rounded value casted as numeric type.
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_even1.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_even2.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_even3.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_even4.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_even5.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_even6.xq
 :)
declare function math:even($number as xs:double) as xs:integer
{
  let $num := $number
  return
    if ($num = 0) then
      0
    else
      let $intnum := xs:integer(math:ceiling($num, math:sign($num)))
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
 : Borrowed from excel module.<br/>
 : Function for computing factorial.
 : This function should not be used outside this module.
 : This recursive function computes: number * fact(number-1)
 : 
 : @param $intnum A positive integer.
 : @return The factorial of intnum.
:)
declare %private function math:fact-integer($intnum as xs:integer) as xs:integer
{
  if ($intnum = 1) then
    1
  else
    $intnum * math:fact-integer($intnum - 1)
};

(:~
 : Borrowed from excel module.<br/>
 : Returns the factorial of a number.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052090841033.aspx
 : @param $number The non-negative number you want the factorial of.
 : @return Returns the factorial of a number. The factorial of a number is equal to 1*2*3*...* number.
 : @error math:errNum if the number is smaller than zero
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_fact1.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_fact2.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_fact3.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_fact4.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_fact5.xq
:)
declare function math:fact($number as xs:integer) as xs:integer
{
  let $num := $number return
    if ($num eq 0) then
      1
    else
      if ($num lt 0) then
        fn:error($math:errNum, "Fact function does not accept numbers smaller than zero")
      else
        math:fact-integer(xs:integer($num))
};

(:~
 : Borrowed from excel module.<br/>
 : Rounds number down, toward zero, to the nearest multiple of significance.
 : Significance must have the same sign as number.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052090941033.aspx
 : @param $number The value you want to round. 
 : @param $significance The multiple to which you want to round.
 : @return The rounded value as numeric type.
 : @error math:errNum if significance is zero or it doesn't have the same sign as number.
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_floor1.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_floor2.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_floor3.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_floor4.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_floor5.xq
:)
declare function math:floor(
  $number as xs:double,
  $significance as xs:double) as xs:double
{
  let $num := $number
  let $sig := $significance
  return
    if ($sig eq 0) then
      fn:error($math:errNum, "Floor function does not accept significance 0")
    else if ($num * $sig ge 0) then
      fn:floor($num div $sig) * $sig
    else
      fn:error($math:errNum, "Floor function: both arguments must have the same sign")
};
 
(:~
 : Borrowed from excel module.<br/>
 : Rounds a number down to the nearest integer.
 : Positive numbers are rounded toward zero, negative numbers are rounded away from zero.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052091421033.aspx
 : @param $number The value to be rounded.
 : @return The rounded integer.
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_int1.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_int2.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_int3.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_int4.xq
:)
declare function math:int($number as xs:double) as xs:integer
{
  xs:integer(fn:floor($number))
};

(:~
 : Borrowed from excel module.<br/>
 : Returns the remainder after number is divided by divisor.
 : The result has the same sign as divisor.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052091821033.aspx
 : @param $number The number for which you want to find the remainder.
 : @param $divisor The number by which you want to divide number.
 :        This cannot be zero.
 : @return The remainder from division as numeric type.
 : @error math:errDiv0 if divisor is zero after casting to numeric.
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_mod1.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_mod2.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_mod3.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_mod4.xq
 :)
declare function math:mod(
  $number as xs:double,
  $divisor as xs:double) as xs:double
{
  let $num := $number
  let $div := $divisor return
    if ($div eq 0) then
      fn:error($math:errDiv0, "Mod operator: divide by 0")
    else
      let $result := $num mod $div
      return
        if ($result * $div lt 0) then
          -$result
        else
          $result
};
 
(:~
 : Borrowed from excel module.<br/>
 : Returns number rounded up to the nearest odd integer, away from zero.
 : 
 : @see  http://office.microsoft.com/en-us/excel/HP052092031033.aspx
 : @param $number The value to round.
 : @return The odd integer.
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_odd1.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_odd2.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_odd3.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_odd4.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_odd5.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_odd6.xq
 :)
declare function math:odd($number as xs:double) as xs:integer
{
  let $num := $number return
  if ($num eq 0) then
    1
  else
    let $intnum := xs:integer(math:ceiling($num, math:sign($num)))
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
 : Borrowed from excel module.<br/>
 : Function for product.
 : This function should not be used outside this module.
 : Multiplies all numbers in the sequence.
 :
 : @param $numbers The list of arguments to be casted to numeric and multiplied.
 : @return The multiplication result as numeric type.
 :)
declare %private function math:product-internal($numbers as xs:double*) as xs:double
{
  if (fn:empty($numbers)) then
    1
  else
    let $x := $numbers[1]
    return
      $x * math:product-internal(fn:subsequence($numbers, 2))
};
 
(:~
 : Borrowed from excel module.<br/>
 : Multiplies all the numbers given as arguments and returns the product.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052092231033.aspx
 : @param $numbers The sequence of arguments convertible to numeric types.
 :        The sequence can be of any length.
 : @return The multiplication result as numeric type.
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_product1.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_product2.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_product3.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_product4.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_product5.xq
 :)
declare function math:product($numbers as xs:double*) as xs:double
{
  if (fn:empty($numbers)) then
    0
  else
    math:product-internal($numbers)
};
 
(:~
 : Borrowed from excel module.<br/>
 : Returns the integer portion of a division.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052092271033.aspx
 : @param $numerator The divider.
 : @param $denominator The divisor. It cannot be zero.
 : @return The result value as numeric type.
 : @error math:errDiv0 if denominator casted as numeric type has value zero.
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_quotient1.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_quotient2.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_quotient3.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_quotient4.xq
 :)
declare function math:quotient(
  $numerator   as xs:double,
  $denominator as xs:double) as xs:integer
{
  let $numer := $numerator
  let $denom := $denominator
  return
    if ($denom eq 0) then
      fn:error($math:errDiv0, "Quotient function: divide by 0")
    else
      xs:integer($numer div $denom)
};
 
(:~
 : Borrowed from excel module.<br/>
 : Rounds a number to a specified number of digits.
 : If precision is greater than 0 (zero), then number is rounded 
 : to the specified number of decimal places.
 : If num_digits is 0, then number is rounded to the nearest integer.
 : If num_digits is less than 0, then number is rounded to the left of the decimal point.
 : The 0.5 is rounded away from zero. 
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052092391033.aspx
 : @param $number The number to round.
 : @param $precision The number of decimal places to keep.
 : @return The rounded number as numeric type.
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_round1.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_round2.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_round3.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_round4.xq
 :)
declare function math:round(
  $number as xs:double,
  $precision as xs:integer) as xs:double
{
  let $num := $number
  return
    if ($precision ge 0) then
      let $exp_prec := W3Cmath:pow(10, $precision)
      return 
        if ($num ge 0) then
          fn:floor($num * $exp_prec + 0.5) div $exp_prec
        else 
          -fn:floor(-$num * $exp_prec + 0.5) div $exp_prec
    else
      let $exp_prec := W3Cmath:pow(10, -$precision)
      return
        if ($num ge 0) then
          fn:floor($num div $exp_prec + 0.5) * $exp_prec
        else 
          -fn:floor(-$num div $exp_prec + 0.5) * $exp_prec
};
  
(:~
 : Borrowed from excel module.<br/>
 : Rounds a number down, toward zero.
 : If num_digits is greater than 0 (zero), then number is rounded down 
 : to the specified number of decimal places. 
 : If num_digits is 0, then number is rounded down to the nearest integer. 
 : If num_digits is less than 0, then number is rounded down to the left of the decimal point. 
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052092411033.aspx
 : @param $number The number to round
 : @param $precision The number of decimal places to keep.
 : @return the truncated number toward zero, as numeric type.
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_rounddown1.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_rounddown2.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_rounddown3.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_rounddown4.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_rounddown5.xq
 :)
declare function math:rounddown(
  $number     as xs:double,
  $precision  as xs:integer) as xs:double
{
  let $num := $number
  return
    if ($precision ge 0) then
      let $exp_prec := W3Cmath:pow(10, $precision)
      return 
        if ($num ge 0) then
          fn:floor($num * $exp_prec) div $exp_prec
        else
          -fn:floor(-$num * $exp_prec) div $exp_prec
    else
      let $exp_prec := W3Cmath:pow(10, -$precision)
      return
        if ($num ge 0) then
          fn:floor($num div $exp_prec) * $exp_prec
        else
          -fn:floor(-$num div $exp_prec) * $exp_prec
};
 
(:~
 : Borrowed from excel module.<br/>
 : Rounds a number up, away from 0 (zero).
 : If num_digits is greater than 0 (zero), then number is rounded down 
 : to the specified number of decimal places. 
 : If num_digits is 0, then number is rounded down to the nearest integer. 
 : If num_digits is less than 0, then number is rounded down to the left of the decimal point. 
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052092421033.aspx
 : @param $number The number to round
 : @param $precision The number of decimal places to keep.
 : @return The truncated number away from zero, as numeric type.
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_roundup1.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_roundup2.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_roundup3.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_roundup4.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_roundup5.xq
 :)
declare function math:roundup(
  $number     as xs:double,
  $precision  as xs:integer) as xs:double
{
  let $num := $number
  return
    if ($precision ge 0) then
      let $exp_prec := W3Cmath:pow(10, $precision)
      return
        if ($num ge 0) then
           fn:ceiling($num * $exp_prec) div $exp_prec
        else 
          -fn:ceiling(-$num * $exp_prec) div $exp_prec
    else
      let $exp_prec := W3Cmath:pow(10, -$precision)
      return
        if ($num ge 0) then
          fn:ceiling($num div $exp_prec) * $exp_prec
        else
          -fn:ceiling(-$num div $exp_prec) * $exp_prec
};
 
(:~
 : Borrowed from excel module.<br/>
 : Determines the sign of a number. 
 : Returns 1 if the number is positive, zero (0) if the number is 0, 
 : and -1 if the number is negative.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052092551033.aspx
 : @param $number The argument
 : @return The sign as (-1, 0, 1).
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_sign1.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_sign2.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_sign3.xq
 :)
declare function math:sign($number as xs:double) as xs:integer
{
  let $num := $number
  return
    if ($num eq 0) then
      0
    else if ($num gt 0) then
      1
    else
      -1   
 };

(:~
 : Borrowed from excel module.<br/>
 : Truncates a number to an integer by removing the fractional part of the number.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052093241033.aspx
 : @param $number The argument .
 : @return The integer value.
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_trunc1.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_trunc2.xq
 :)
declare function math:trunc($number as xs:double ) as xs:integer
{
  xs:integer($number)
};
 
(:~
 : Borrowed from excel module.<br/>
 : Truncates a number down to precision.
 : This behaves exactly like rounddown.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052093241033.aspx
 : @param $number The argument castable to numeric type.
 : @param $precision The number of decimal places to keep .
 : @return The integer value.
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_trunc3.xq
 :)
declare function math:trunc(
  $number as xs:double,
  $precision as xs:integer) as xs:double
{
  math:rounddown($number, $precision)
};
 
(:~
 : Borrowed from excel module.<br/>
 : Helper function.<br/>
 : Sorts a sequence of numbers or arguments castable to numeric.
 : It first casts all arguments to numeric and then sorts ascending.
 :  
 : @param $numbers The sequence of arguments castable to numeric.
 : @return The sorted sequence as numeric types.
 :)
declare function math:sort-numbers($numbers as xs:double*) as xs:double*
{
  let $sorted-numbers :=
    (
      for $number in $numbers 
      let $num := $number
      order by $num
      return $num
    )
  return $sorted-numbers
};

(:~
 : Borrowed from excel module.<br/>
 : Returns the double factorial of a number.
 : Computes the double factorial of n as n(n-2)(n-4)...
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052090851033.aspx
 : @param $number The positive integer value.
 : @return The result as integer.
 : @error math:errNum if the number is negative.
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_factdouble1.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_factdouble2.xq
 :)
declare function math:factdouble($number as xs:integer) as xs:integer
{
  if ($number lt 0) then
    fn:error($math:errNum, "Factdouble function: number should be greater than zero or equal")
  else if ($number eq 1) then
    1
  else if ($number eq 2) then
    2
  else
    $number * math:factdouble($number - 2) 
};

(:~
 : Borrowed from excel module.<br/>
 : Function for computing GCD.
 : This function should not be used outside this module.
 : It calculates the minimum value from a sequence of positive integers, 
 : not taking into account the zero value.
 : 
 : @param $numbers The sequence of positive integers.
 : @return The minimum value. If the sequence contains only zero values, then zero is returned.
 :)
declare %private function math:min-without-zero($numbers as xs:integer+) as xs:integer
{
  if (fn:count($numbers) eq 1) then
    $numbers[1]
  else
    let $min-other := math:min-without-zero(fn:subsequence($numbers, 2))
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
 : Borrowed from excel module.<br/>
 : Function for computing GCD.
 : This function should not be used outside this module.
 : Checks if all integer numbers from a sequence divide exactly to a divider.
 :
 : @param $numbers The positive integers.
 : @param $divider The divider to be tried.
 : @return true if the numbers divide exactly.
:)
declare %private function math:try-exact-divide(
  $numbers as xs:integer*,
  $divider as xs:integer) as xs:boolean
{
  if (fn:empty($numbers)) then
    fn:true()
  else
    if ($numbers[1] mod $divider ne 0) then
      fn:false()
    else
      math:try-exact-divide(fn:subsequence($numbers, 2), $divider)
};

(:~
 : Borrowed from excel module.<br/>
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
declare %private function math:iterate-all-gcd(
  $numbers as xs:integer*, 
  $min-nonzero as xs:integer,
  $iteration as xs:integer) as xs:integer
{
  if ($min-nonzero mod $iteration eq 0) then
    if (math:try-exact-divide($numbers, $min-nonzero idiv $iteration)) then
      $min-nonzero idiv $iteration
    else
      math:iterate-all-gcd($numbers, $min-nonzero, $iteration + 1)
  else
    if ($iteration > $min-nonzero idiv 2) then
      1
    else
      math:iterate-all-gcd($numbers, $min-nonzero, $iteration + 1)
};

(:~
 : Borrowed from excel module.<br/>
 : Returns the greatest common divisor GCD of a sequence of integers.
 : The sequence can have one or more positive integers.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052091041033.aspx
 : @param $numbers The sequence of positive integers.
 : @return The GCD as integer.
 : @error math:errNum if any number is smaller than zero.
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_gcd1.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_gcd2.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_gcd3.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_gcd4.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_gcd5.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_gcd6.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_gcd7.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_gcd8.xq
 :)
declare function math:gcd($numbers as xs:integer+) as xs:integer
{
  if (fn:count($numbers) = 1) then
    $numbers[1]
  else
    let $minval := math:min-without-zero($numbers)
    return
      if ($minval lt 0) then
        fn:error($math:errNum, "gcd function: numbers should be greater than zero or equal")
      else if ($minval eq 0) then
        0
      else 
        math:iterate-all-gcd($numbers, $minval, 1)
};

(:~
 : Borrowed from excel module.<br/>
 : Returns the least common multiple of integers.<br/>
 : LCM for two numbers is computed by multiplying them and dividing with GCD. <br/>
 : The function is applied recursively replacing the first two numbers in the sequence with their LCM.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052091521033.aspx
 : @param $numbers The sequence of one or more positive integers.
 : @return The LCM as integer.
 : @error math:errNum if any number is smaller than zero.
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_lcm1.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_lcm2.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_lcm3.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_lcm4.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_lcm5.xq
 :)
declare function math:lcm($numbers as xs:integer+) as xs:integer
{
  if(count($numbers) eq 1) then
    $numbers[1]
  else
  if(count($numbers) eq 2) then
    let $product := math:product(fn:distinct-values($numbers))
    return
      if ($product eq 0) then
        0
      else
        $product idiv math:gcd($numbers)
  else
    math:lcm((math:lcm(($numbers[1], $numbers[2])), subsequence($numbers, 3)))

};

(:~
 : Borrowed from excel module.<br/>
 : Returns a number rounded to the desired multiple.
 : MROUND rounds up, away from zero, if the remainder of dividing number by multiple
 : is greater than or equal to half the value of multiple.
 : MROUND is computed through math:floor function.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052091851033.aspx
 : @param $number The value to round, 
 : @param $multiple The multiple to which you want to round number.
 : @return The rounded number up to the desired multiple.
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_mround1.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_mround2.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_mround3.xq
 :)
declare function math:mround(
  $number   as xs:decimal,
  $multiple as xs:double) as xs:double
{
  let $num := $number
  let $mul := $multiple
  let $floor := math:floor($num, $mul) return
  if ($num ge 0) then
    if (($num - $floor) ge (($mul div (2 + 1e-12)))) then
      $floor + $mul
    else
      $floor
  else
    if ((-$num + $floor) ge (-$mul div (2 + 1e-12))) then
      $floor + $mul
    else
      $floor
};

(:~
 : Borrowed from excel module.<br/>
 : Converts an Arabic numeral to roman, as text.
 : Only the classic format is supported (out of all formats Excel requires).<br/>
 : M is the largest digit, it represents 1000.
 : Numbers bigger than 2000 will be represented by a sequence of "M".<br/>
 : D = 500, C = 100, L = 50, X = 10, V = 5, I = 1.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052092381033.aspx
 : @param $number A positive integer.
 : @return The roman string representation.
 : @error math:errNum if the input integer is negative 
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_roman1.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_roman2.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_roman3.xq
 :)
declare function math:roman($number as xs:integer) as xs:string
{
  if ($number lt 0) then
    fn:error($math:errNum, "Roman function: number should be greater than zero or equal")
  else if ($number ge 1000) then
    fn:concat("M", math:roman($number - 1000))
  else if ($number ge 900) then
    fn:concat("CM", math:roman($number - 900))
  else if ($number ge 800) then
    fn:concat("DCCC", math:roman($number - 800))
  else if ($number ge 700) then
    fn:concat("DCC", math:roman($number - 700))
  else if ($number ge 600) then
    fn:concat("DC", math:roman($number - 600))
  else if ($number ge 500) then
    fn:concat("D", math:roman($number - 500))
  else if ($number ge 400) then
    fn:concat("CD", math:roman($number - 400))
  else if ($number ge 300) then
    fn:concat("CCC", math:roman($number - 300))
  else if ($number ge 200) then
    fn:concat("CC", math:roman($number - 200))
  else if ($number ge 100) then
    fn:concat("C", math:roman($number - 100))
  else if ($number ge 90) then
    fn:concat("XC", math:roman($number - 90))
  else if ($number ge 80) then
    fn:concat("LXXX", math:roman($number - 80))
  else if ($number ge 70) then
    fn:concat("LXX", math:roman($number - 70))
  else if ($number ge 60) then
    fn:concat("LX", math:roman($number - 60))
  else if ($number ge 50) then
    fn:concat("L", math:roman($number - 50))
  else if ($number ge 40) then
    fn:concat("XL", math:roman($number - 40))
  else if ($number ge 30) then
    fn:concat("XXX", math:roman($number - 30))
  else if ($number ge 20) then
    fn:concat("XX", math:roman($number - 20))
  else if ($number ge 10) then
    fn:concat("X", math:roman($number - 10))
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

(:~
 : Borrowed from excel module.<br/>
 : Multiplies the elements on the same position in each sequence
 : and sums up the results.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052092931033.aspx
 : @param $array1 the sequences of numbers
 : @param $array2 the sequences of numbers
 : @return the sum of products
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_sumproduct2.xq
:)
 declare function math:sumproduct( $array1 as xs:double*,
                                    $array2 as xs:double*  ) as xs:double
 {
    if( fn:empty($array1) or 
        fn:empty($array2)) 
        then
      0
    else
      $array1[1] * $array2[1] + math:sumproduct( fn:subsequence($array1,2),
                                                  fn:subsequence($array2,2))
 };

(:~
 : Borrowed from excel module.<br/>
 : Returns the sum of the squares of the arguments.
 : It uses the sumproduct function.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052092951033.aspx
 : @param $numbers the sequence of one or more numbers
 : @return the sum of squared values, as numeric type
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_sumsq1.xq
:)
 declare function math:sumsq( $numbers as xs:double+) as xs:double
 {
   math:sumproduct($numbers, $numbers)
 };
 


(:Excel statistical functions :)

(:~
 : Borrowed from excel module.<br/>
 : Returns the median of the given numbers. 
 : The median is the number in the middle of a set of numbers.
 : Half the numbers have values that are greater than the median, 
 : and half the numbers have values that are less than the median. 
 : 
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052091741033.aspx
 : @param $numbers the sequence of numbers, of any length
 : @return for odd count of numbers return the number in the middle of the sorted sequence.
 :       For even count of numbers return the average of the two numbers in the middle.
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_median1.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_median2.xq
:)
declare function math:median( $numbers as xs:double* ) as xs:double
{
  let $number_count := fn:count( $numbers )
  let $sorted_numbers := math:sort-numbers( $numbers ) return
  if ($number_count mod 2 != 0) then
    $sorted_numbers[$number_count idiv 2 + 1]
  else
    if ($number_count = 0) then
      0
    else
      ($sorted_numbers[$number_count idiv 2] + $sorted_numbers[$number_count idiv 2 + 1] ) div 2
};

(:~
 : Borrowed from excel module.<br/>
 : Returns the most frequently occurring, or repetitive, value in a sequence.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052091831033.aspx
 : @param $numbers the sequence of numbers, of any length
 : @return The most occuring number
 : @error math:errNA if there are no duplicate numbers
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_mode1.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_mode2.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_mode3.xq
:)
declare function math:mode( $numbers as xs:double* ) as xs:double
{
  if ( fn:empty($numbers)) then
    fn:error($math:errNA, "Mode function: empty sequence")
  else
  let $result := 
  ( for $n_at in fn:distinct-values($numbers) 
    let $n := $n_at
    let $count := fn:count( (for $d in $numbers where $d eq $n return $d) )
    where $count > 1 
    order by $count descending
    return $n
  ) return 
  if (fn:empty($result)) then
    fn:error($math:errNA, "Mode function: no duplicate elements")
  else
    $result[1]
};

(:~
 : Borrowed from excel module.<br/>
 : Returns the k-th percentile of values in a sequence.
 : If k is not a multiple of 1/(n - 1), 
 :   PERCENTILE interpolates to determine the value at the k-th percentile.  
 : The function is computed by (max-min)*k + min
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052092111033.aspx
 : @param $numbers the sequence of numbers, of any length
 : @param $k_at the percentile, with value between 0 .. 1 inclusive
 : @return The computed percentile
 : @error math:errNum if percentile is not between 0 .. 1
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_percentile1.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_percentile2.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_percentile3.xq
:)
declare function math:percentile( $numbers as xs:double*, $k_at as xs:double) as xs:double
{
  let $k := $k_at return
  if ($k < 0 or $k > 1) then
    fn:error($math:errNum, "Percentile function: k must be a value between 0 and 1 inclusive")
  else
    let $max := fn:max($numbers)
    let $min := fn:min($numbers) return
    ($max - $min) * $k + $min
};



(:~
 : Borrowed from excel module.<br/>
 : Function for AVEDEV.
 : This function should not be used outside this module.
 : Computes formula sum(abs(x - average)) for every x in $numbers
 :
 : @param $numbers The sequence of numbers.
 :        Sequence can be of any length.
 : @param $average The average of all numbers, computed with function AVERAGE.
 : @return The result of the formula.
 :)
declare %private function math:sum-deviations(
  $numbers as xs:double*,
  $average as xs:double) as xs:double
{
  if (fn:empty($numbers)) then
    0
  else
    fn:abs($numbers[1] - $average) + math:sum-deviations(fn:subsequence($numbers, 2), $average)
};

(:~
 : Borrowed from excel module.<br/>
 : Returns the average of the absolute deviations of data points from their mean.
 : The formula is sum(abs(x - average_x))/n, where n is the count of x in the sequence.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052089931033.aspx
 : @param $numbers the sequence of numbers.
 :     Sequence can be of any length from 1 up.
 : @return The formula result
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_avedev1.xq
:)
declare function math:avedev($numbers as xs:double+) as xs:double
{
  let $average := fn:avg($numbers) return
  math:sum-deviations($numbers, $average) div fn:count($numbers)
};

(:~
 : Borrowed from excel module.<br/>
 : Returns the k-th largest value in a data set. 
 : If n is the number of data points in a range, 
 :   then LARGE(array,1) returns the largest value, 
 :   and LARGE(array,n) returns the smallest value.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052091511033.aspx
 : @param $numbers the sequence of numbers
 :           The sequence can be of any length, from 1 up.
 : @param $k the position of largest value, with value from 1 to count of values
 : @return The k-th largest value as numeric type
 : @error math:errNum if the sequence is empty or k is not a value between 1
 :  and the size of the sequence
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_large1.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_large2.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_large3.xq
:)
declare function math:large($numbers as xs:double+, $k as xs:integer) as xs:double
{
  if (fn:empty($numbers)) then
    fn:error($math:errNum, "Large function: value list must not be empty")  
  else if ($k > fn:count($numbers) or $k le 0) then
    fn:error($math:errNum, "Large function: k must be between 1 and the count of numbers ", $k)
  else
    let $ordered_numbers :=
      (for $n in $numbers 
       let $nn := $n
       order by $nn descending
       return $nn
      ) return
     $ordered_numbers[$k]
};

(:~
 : Borrowed from excel module.<br/>
 : Returns the rank of a number in a list of numbers. 
 : The rank of a number is its size relative to other values in a list. 
 : (If you were to sort the list, the rank of the number would be its position.)
 : RANK gives duplicate numbers the same rank.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052092311033.aspx
 : @param $x The number whose rank you want to find.
 : @param $numbers The sequence of numbers.
 :        The sequence can be of any length.
 : @param $order_ascending <dl>A boolean having the meaning:
 :        <dt>false</dt><dd>then rank the number as if the sequence was sorted in descending order.</dd>
 :        <dt>true</dt> <dd>then rank the number as if the sequence was sorted in ascending order.</dd></dl>
 : @return The rank of $x.
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_rank1.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_rank2.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_rank4.xq
 :)
declare function math:rank(
  $x                as xs:double, 
  $numbers          as xs:double*, 
  $order_ascending  as xs:boolean) as xs:double
{
  let $ordered_numbers :=
    if ($order_ascending) then (
      for $n in $numbers 
      let $nn := $n
      order by $nn ascending
      return $nn
    ) else (
      for $n in $numbers 
      let $nn := $n
      order by $nn descending
      return $nn
    )
  let $xnum := $x
  let $rank :=
    (
      for $i at $pos in $ordered_numbers
      where $xnum = $i or $order_ascending and $xnum < $i
                     or fn:not($order_ascending) and $xnum > $i
      return 
        if ($xnum = $i) then
          $pos
        else if ($pos = 1) then
          0
        else
          ($pos - 1) + ($xnum - $ordered_numbers[$pos - 1]) div ($ordered_numbers[$pos] - $ordered_numbers[$pos - 1])
    )
  return 
    if (fn:empty($rank)) then
      fn:count($numbers)
    else
      $rank[1]
};

(:~
 : Borrowed from excel module.<br/>
 : This RANK function is same as the above, only that $order_ascending is set by default to false.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052092311033.aspx
 : @param $x The number whose rank you want to find.
 : @param $numbers the sequence of numbers.
 :        The sequence can be of any length.
 : @return The rank of $x.
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_rank3.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_rank5.xq
:)
declare function math:rank(
  $x        as xs:double, 
  $numbers  as xs:double*) as xs:double
{
  math:rank($x, $numbers, fn:false())
};

(:~
 : Borrowed from excel module.<br/>
 : Returns the rank of a value in a data set as a percentage of the data set.
 : If x does not match one of the values in array, 
 :   PERCENTRANK interpolates to return the correct percentage rank. <br/>
 : The formula is uses: (RANK - 1) / (size - 1) .
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052092121033.aspx
 : @param $numbers the sequence of numbers.
 :    The sequence can be of any length, from 1 up.
 : @param $x is the value for which you want to know the rank
 : @return The percentage of rank. 
 : @error math:errNum if the sequence is zero length
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_percentrank1.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_percentrank2.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_percentrank3.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_percentrank4.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_percentrank5.xq
:)
declare function math:percentrank($numbers as xs:double*, $x as xs:double) as xs:double
{
  if (fn:empty($numbers)) then
    fn:error($math:errNum, "Percentrank function: value list must not be empty")
  else  
    let $rank := math:rank($x, $numbers, fn:true()) return
    if ($rank = 0) then
      0
    else
      ($rank - 1) div (fn:count($numbers) - 1)
};

(:~
 : Borrowed from excel module.<br/>
 : Returns the quartile of a data set. 
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052092261033.aspx
 : @param $numbers sequence of numbers.
 :      The sequence can be of any length, from 1 up.
 : @param $quart <dl>one of the values 0, 1, 2, 3, 4 with meaning:
 :     <dt>0</dt> <dd> compute minimum value</dd>
 :     <dt>1</dt> <dd> compute first quartile (25th percentile)</dd>
 :     <dt>2</dt> <dd> compute median value (50th percentile)</dd>
 :     <dt>3</dt> <dd> compute third quartile (75th percentile)</dd>
 :     <dt>4</dt> <dd> compute maximum value</dd></dl>
 :  @return the computed quartile, as numeric type
 : @error math:errNum if the sequence is zero length or $quart is not one of the values 0,1,3,4
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_quartile1.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_quartile2.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_quartile3.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_quartile4.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_quartile5.xq
:)
declare function math:quartile($numbers as xs:double*, $quart as xs:integer) as xs:double
{
  if (fn:empty($numbers)) then
    fn:error($math:errNum, "Quartile function: value list must not be empty")
  else  
  if ($quart = 0) then
    fn:min($numbers)
  else
  if ($quart = 1) then
    let $r := (fn:count($numbers) + 3) div 4
    let $rint := xs:integer($r)
    let $rrem := $r - $rint 
    let $sorted_numbers := math:sort-numbers( $numbers ) return
      ($numbers[$rint + 1] - $numbers[$rint]) * $rrem + $numbers[$rint] 
  else
  if ($quart = 2) then
    math:median($numbers)
  else
  if ($quart = 3) then
    let $r := (3 * fn:count($numbers) + 1) div 4
    let $rint := xs:integer($r)
    let $rrem := $r - $rint 
    let $sorted_numbers := math:sort-numbers( $numbers ) return
      ($numbers[$rint + 1] - $numbers[$rint]) * $rrem + $numbers[$rint] 
  else
  if ($quart = 4) then
    fn:max($numbers)
  else
    fn:error($math:errNum, "Quartile function: quart should be between 0 and 4 :", $quart)
};

(:~
 : Borrowed from excel module.<br/>
 : This function computes the k-th smallest value in a data set. 
 : Use this function to return values with a particular relative standing in a data set.
 : If n is the number of data points in array, SMALL(array,1) equals the smallest value, 
 :   and SMALL(array,n) equals the largest value. 
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052092661033.aspx
 : @param $numbers A sequence of numbers.
 :        The sequence can be of any length, from 1 up.
 : @param $k The position (from the smallest) in the sequence of data to return.
 :        Must have value between 1 and size of sequence.
 : @return The k-th smallest value of $numbers.
 : @error math:errNum if the sequence is zero length or $k is not a value
 :   between 1 and the size of sequence.
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_small1.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_small2.xq
:)
declare function math:small($numbers as xs:double*, $k as xs:integer) as xs:double
{
  if (fn:empty($numbers)) then
    fn:error($math:errNum, "Small function: value list must not be empty")
  else if ($k gt fn:count($numbers) or $k le 0) then
    fn:error($math:errNum, "Small function: k must be between 1 and the count of numbers ", $k)
  else
    let $ordered_numbers := (
        for $n in $numbers 
        let $nn := $n
        order by $nn ascending
        return $nn
      )
    return
      $ordered_numbers[$k]
};


(:~
 : Borrowed from excel module.<br/>
 : Function for VAR, VARA, VARP, VARPA and SLOPE.
 : This function should not be used outside this module.
 : It computes formula sum((x - average_x)^2) for all x in $numbers.
 :
 : @param $numbers the sequence of numbers.
 :        The sequence can be of any length.
 : @param $average The precomputed average over the sequence.
 : @return The result as numeric type.
 :)
declare %private function math:sumsq-deviations($numbers as xs:double*, $average as xs:double) as xs:double
{
  if (fn:empty($numbers)) then
    0
  else
    let $val := $numbers[1] - $average
    return
      $val * $val + math:sumsq-deviations(fn:subsequence($numbers, 2), $average)
};

(:~
 : Borrowed from excel module.<br/>
 : Estimates variance based on a sample.<br/>
 : The formula is sum(x - average_x)^2 / (n - 1).<br/>
 : average_x is computed with AVERAGE function.<br/>
 : n is the count of numbers from the sequence, excluding empty values.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052093301033.aspx
 : @param $numbers the sequence of numbers.
 :       The sequence can be of any length, from 1 up.
 : @return The variance, as numeric type
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_var1.xq
 :)
declare function math:var($numbers as xs:double+) as xs:double
{
  let $average := fn:avg($numbers)
  return
    math:sumsq-deviations($numbers, $average) div (fn:count($numbers) - 1)
};

(:~
 : Borrowed from excel module.<br/>
 : Estimates variance based on a sample.<br/>
 : The formula is sum(x - average_x)^2 / (n - 1).<br/>
 : average_x is computed with AVERAGE function.<br/>
 : n is the size of sequence, including empty values.<br/>
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052093311033.aspx
 : @param $numbers the sequence of numbers.
 :       The sequence can be of any length, from 1 up.
 : @return The variance, as numeric type
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_vara1.xq
:)
declare function math:vara($numbers as xs:double+) as xs:double
{
  let $average := fn:avg($numbers) return
  math:sumsq-deviations($numbers, $average) div (fn:count($numbers) - 1)
};

(:~
 : Borrowed from excel module.<br/>
 : Calculates variance based on the entire population.<br/>
 : The formula is sum(x - average_x)^2 / n.<br/>
 : average_x is computed with AVERAGE function.<br/>
 : n is the count of numbers from the sequence, excluding empty values.<br/>
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052093321033.aspx
 : @param $numbers the sequence of numbers.
 :       The sequence can be of any length, from 1 up.
 : @return The variance, as numeric type
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_varp1.xq
:)
declare function math:varp($numbers as xs:double+) as xs:double
{
  let $average := fn:avg($numbers) return
  math:sumsq-deviations($numbers, $average) div fn:count($numbers)
};

(:~
 : Borrowed from excel module.<br/>
 : Calculates variance based on the entire population.<br/>
 : The formula is sum(x - average_x)^2 / n.<br/>
 : average_x is computed with AVERAGE function.<br/>
 : n is the size of sequence, including empty values.<br/>
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052093321033.aspx
 : @param $numbers the sequence of numbers.
 :       The sequence can be of any length, from 1 up.
 : @return The variance, as numeric type
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_varpa1.xq
:)
declare function math:varpa($numbers as xs:double+) as xs:double
{
  let $average := fn:avg($numbers) return
  math:sumsq-deviations($numbers, $average) div fn:count($numbers)
};

(:~
 : Borrowed from excel module.<br/>
 : Function for PROB function.
 : This function should not be used outside this module.
 : Computes the sum over a sequence of numbers.
 : Checks if the values are between 0 and 1.
 :
 : @param $prob_range The sequence of probabilities.
 : @return The sum of probabilities. This should be 1.
 : @error math:errNum if any probability is not between 0 and 1.
 : @error math:errValue if any parameter is not castable to numeric.
:)
declare %private function math:sum-prob($prob_range as xs:double*) as xs:double
{
  if (fn:empty($prob_range)) then
    0
  else
    let $prob_num := $prob_range[1]
  return
    if ($prob_num < 0 or $prob_num > 1) then
      fn:error($math:errNum, "Prob function: prob values should be between 0 and 1 ", $prob_num)
    else
      $prob_num + math:sum-prob(fn:subsequence($prob_range, 2))
};

(:~
 : Borrowed from excel module.<br/>
 : Function for PROB function.
 : This function should not be used outside this module.
 : Checks the prob range and x range if they have the same number of values.
 : Adds all probabilities corresponding to values between range_lower_limit and upper_limit.
 :
 : @param $x_range The sequence of x values.
 : @param $prob_range The sequence of probabilities associated to x values.
 : @param $range_lower_limit The lower limit of the range to compute the probability.
 : @param $upper_limit The upper limit of the range to compute the probability.
 : @return The sum of probabilities.
 : @error $math:errNum if x_range and prob_range do not have the same number of values.
 :)
declare %private function math:sum-prob-x(
  $x_range            as xs:double*,
  $prob_range         as xs:double*,
  $range_lower_limit  as xs:double,
  $upper_limit        as xs:double) as xs:double
{
  if (fn:empty($x_range) and fn:not(fn:empty($prob_range))) then
    fn:error($math:errNum, "Prob function: x range and prob range should have the same number of elements")
  else if (fn:empty($prob_range) and fn:not(fn:empty($x_range))) then
    fn:error($math:errNum, "Prob function: x range and prob range should have the same number of elements")
  else if (fn:empty($prob_range) and fn:empty($x_range)) then
    0
  else
    let $x := $x_range[1]
    let $this_prob :=
      if ($x ge $range_lower_limit and $x le $upper_limit) then
        $prob_range[1]
      else
        0 
    return
      $this_prob + math:sum-prob-x(
        fn:subsequence($x_range, 2),
        fn:subsequence($prob_range, 2),
        $range_lower_limit,
        $upper_limit)
};

(:~
 : Borrowed from excel module.<br/>
 : Returns the probability that values in a range are between two limits.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052092221033.aspx
 : @param $x_range is the range of numeric values of x with which there are associated probabilities.
 :       This does not need to be ordered.
 : @param $prob_range is a set of probabilities associated with values in x_range.
 : @param $range_lower_limit is the lower bound on the value for which you want a probability.
 : @param $upper_limit  is the upper bound on the value for which you want a probability.
 : @return The probability of the entire range
 : @error math:errNum if any probability is not between 0 and 1
 : @error math:errNum if the sum of probabilities is not equal to 1
 : @error math:errNum if x_range and prob_range do not have the same number of values
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_prob2.xq
:)
declare function math:prob($x_range as xs:double+,
                            $prob_range as xs:double+,
                            $range_lower_limit as xs:double,
                            $upper_limit as xs:double) as xs:double
{
  let $prob_sum := math:sum-prob($prob_range) return
  if ($prob_sum != 1) then
    fn:error($math:errNum, "Prob function: prob sum should equal 1")
  else
    math:sum-prob-x($x_range, $prob_range, 
                    $range_lower_limit, 
                    $upper_limit)
};

(:~
 : Borrowed from excel module.<br/>
 : This is the same as above, only that upper_limit is not specified.
 : The probability is computed only for range_lower_limit.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052092221033.aspx
 : @param $x_range is the range of numeric values of x with which there are associated probabilities.
 :       This does not need to be ordered.
 : @param $prob_range is a set of probabilities associated with values in x_range.
 : @param $range_lower_limit is the value for which you want a probability.
 : @return The probability of the range_lower_limit value
 : @error math:errNum if any probability is not between 0 and 1
 : @error math:errNum if the sum of probabilities is not equal to 1
 : @error math:errNum if x_range and prob_range do not have the same number of values
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_prob1.xq
 :)
declare function math:prob($x_range as xs:double+,
                            $prob_range as xs:double+,
                            $range_lower_limit as xs:double) as xs:double
{
  math:prob($x_range, $prob_range, $range_lower_limit, $range_lower_limit)
};

(:~
 : Borrowed from excel module.<br/>
 : Function for SLOPE function.
 : This function should not be used outside this module.
 : It computes the formula:<br/>
 : sum((x - average_x)(y - average_y)) <br/>
 : where average_x and average_y are computed with AVERAGE function.
 :
 : @param $x_numbers The sequence of x numbers.
 : @param $x_average The precomputed AVERAGE over the x_numbers.
 : @param $y_numbers The sequence of y numbers.
 : @param $y_average The precomputed AVERAGE over the y_numbers.
 : @return The formula result, as numeric type.
 : @error math:errNA if there are different numbers of x's and y's.
 :)
declare %private function math:sum-x-y-deviations(
  $x_numbers as xs:double*, 
  $x_average as xs:double,
  $y_numbers as xs:double*, 
  $y_average as xs:double) as xs:double
{
  if (fn:empty($x_numbers) and fn:not(fn:empty($y_numbers))) then
    fn:error($math:errNA, "Slope function: different number of x's and y's")
  else if (fn:empty($y_numbers) and fn:not(fn:empty($x_numbers))) then
    fn:error($math:errNA, "Slope function: different number of x's and y's")
  else if (fn:empty($x_numbers) and fn:empty($y_numbers)) then
    0
  else
    ($x_numbers[1] - $x_average) * 
    ($y_numbers[1] - $y_average) + 
    math:sum-x-y-deviations(
      fn:subsequence($x_numbers, 2),$x_average,
      fn:subsequence($y_numbers, 2),$y_average)
};

(:~
 : Borrowed from excel module.<br/>
 : Returns the slope of the linear regression line through data points in known_y's and known_x's.
 : The slope is the vertical distance divided by the horizontal distance between 
 :   any two points on the line, which is the rate of change along the regression line.
 : It computes the formula:<br/>
 : sum((x - average_x)(y - average_y)) / sum((x - average_x)^2)  <br/>
 : where average_x and average_y are computed with AVERAGE function.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052092641033.aspx
 : @param $known_y the sequence of y numbers.
 :    The sequence can be of any length, from 1 up.  
 : @param $known_x the sequence of x numbers.
 :    The sequence can be of any length, from 1 up.  
 : @return The slope value, as numeric type
 : @error math:errNA if there are different numbers of x's and y's or if the sequence is empty
 : @error math:errDiv0 if all x's are equal
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_slope1.xq
:)
declare function math:slope($known_y as xs:double+,
                       $known_x as xs:double+) as xs:double
{
  if (fn:empty($known_y) or fn:empty($known_x)) then
    fn:error($math:errNA, "Slope function: known_x and known_y cannot be empty sequences")
  else
  let $x_average := fn:avg($known_x) 
  let $y_average := fn:avg($known_y) 
  let $xsq_dev := math:sumsq-deviations($known_x, $x_average) return
  if ($xsq_dev = 0) then
    fn:error($math:errDiv0, "Slope function: all x's are equal")
  else
  let $x_y_dev := math:sum-x-y-deviations($known_x, $x_average, $known_y, $y_average) return
  $x_y_dev div $xsq_dev
};

(:~
 : Borrowed from excel module.<br/>
 : Returns a normalized value from a distribution characterized by mean and standard_dev.<br/>
 : The formula is (x - mean) / standard_dev .
 :
 : @see http://office.microsoft.com/en-us/excel/HP052092731033.aspx
 : @param $x is the value you want to normalize
 : @param $mean  is the arithmetic mean of the distribution.
 : @param $standard_dev is the standard deviation of the distribution.
 : @return The normalized x, as numeric type
 : @error math:errNum if standard_dev is a value smaller than zero or equal
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_standardize1.xq
:)
declare function math:standardize($x as xs:double,
                                   $mean as xs:double,
                                   $standard_dev as xs:double) as xs:double
{
  if ($standard_dev le 0) then
    fn:error($math:errNum, "Standardize function: standard_dev must be positive ", $standard_dev)
  else
    ($x - $mean) div $standard_dev
};


(:~
 : Borrowed from excel module.<br/>
 : Estimates standard deviation based on a sample. 
 : The standard deviation is a measure of how widely values are dispersed 
 :   from the average value (the mean).
 : It is computed with formula:
 : sqrt( sum((x-average_x)^2) / (n-1) )    = sqrt ( VAR(numbers) )
 :
 : @see http://office.microsoft.com/en-us/excel/HP052092771033.aspx
 : @param $numbers the sequence of numbers
 :    The sequence can be of any length, from 1 up.
 : @return the standard deviation, as numeric type
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_stdev1.xq
:)
declare function math:stdev($numbers as xs:double+) as xs:double
{
  W3Cmath:sqrt(math:var($numbers))
};

(:~
 : Borrowed from excel module.<br/>
 : Estimates standard deviation based on a sample. 
 : The standard deviation is a measure of how widely values are dispersed 
 :   from the average value (the mean).
 : It is computed with formula:
 : sqrt( sum((x-average_x)^2) / (n-1) )    = sqrt ( VARA(numbers) )
 :
 : @see http://office.microsoft.com/en-us/excel/HP052092791033.aspx
 : @param $numbers the sequence of numbers.
 :    The sequence can be of any length, from 1 up.
 : @return the standard deviation, as numeric type
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_stdeva1.xq
:)
declare function math:stdeva($numbers as xs:double+) as xs:double
{
  W3Cmath:sqrt(math:vara($numbers))
};

(:~
 : Borrowed from excel module.<br/>
 : Calculates standard deviation based on the entire population given as arguments. 
 : The standard deviation is a measure of how widely values are dispersed from 
 :   the average value (the mean).
 : It is computed with formula:
 : sqrt( sum((x-average_x)^2) / n )    = sqrt ( VARP(numbers) )
 :
 : @see http://office.microsoft.com/en-us/excel/HP052092811033.aspx
 : @param $numbers the sequence of numbers or values castable to numeric
 :    The sequence can be of any length, from 1 up.
 : @return the standard deviation, as numeric type
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_stdevp1.xq
:)
declare function math:stdevp($numbers as xs:double+) as xs:double
{
  W3Cmath:sqrt(math:varp($numbers))
};

(:~
 : Borrowed from excel module.<br/>
 : Calculates standard deviation based on the entire population given as arguments. 
 : The standard deviation is a measure of how widely values are dispersed from 
 :   the average value (the mean).
 : It is computed with formula:
 : sqrt( sum((x-average_x)^2) / n )    = sqrt ( VARPA(numbers) )
 :
 : @see http://office.microsoft.com/en-us/excel/HP052092831033.aspx
 : @param $numbers the sequence of numbers or values castable to numeric
 :    The sequence can be of any length, from 1 up.
 : @return the standard deviation, as numeric type
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_stdevpa1.xq
:)
declare function math:stdevpa($numbers as xs:double+) as xs:double
{
  W3Cmath:sqrt(math:varpa($numbers))
};

(:~ 
 : Borrowed from excel module.<br/>
 : Returns a subtotal in a sequence of numbers.
 : The function applied is given by $function_num.
 :   
 : @see http://office.microsoft.com/en-us/excel/HP052092881033.aspx
 : @param $function_num <dl>defines the function to be applied on sequence values.
 :       The possible values are:
 :       <dt>1 or 101</dt> <dd> AVERAGE</dd>
 :       <dt>2 or 102</dt> <dd> COUNT</dd>
 :       <dt>3 or 103</dt> <dd> COUNTA</dd>
 :       <dt>4 or 104</dt> <dd> MAX</dd>
 :       <dt>5 or 105</dt> <dd> MIN</dd>
 :       <dt>6 or 106</dt> <dd> PRODUCT</dd>
 :       <dt>7 or 107</dt> <dd> STDEV</dd>
 :       <dt>8 or 108</dt> <dd> STDEVP</dd>
 :       <dt>9 or 109</dt> <dd> SUM</dd>
 :       <dt>10 or 110</dt> <dd> VAR</dd>
 :       <dt>11 or 111</dt> <dd> VARP</dd></dl>
 :       
 :       In this implementation there is no difference between x and 10x.<br/>
 : @param $numbers the sequence of numbers.
 :     The sequence can be of any length.
 : @return The function result, as numeric type
 : @error * depends on the function called
 : @error math:errNum if $function_num is not a value between 1 .. 11 or 101 .. 111
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_subtotal1.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_subtotal2.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_subtotal3.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_subtotal4.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_subtotal5.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_subtotal6.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_subtotal7.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_subtotal8.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_subtotal9.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_subtotal10.xq
 : @example test/rbkt/Queries/zorba/math/from_excel/excel_subtotal11.xq
:)
declare function math:subtotal($function_num as xs:integer, $numbers as xs:double*) as xs:double
{
  if ($function_num = 1 or $function_num = 101) then
    fn:avg($numbers)
  else 
  if ($function_num = 2 or $function_num = 102) then
    fn:count($numbers)
  else
  if ($function_num = 3 or $function_num = 103) then
    fn:count($numbers)
  else
  if ($function_num = 4 or $function_num = 104) then
    fn:max($numbers)
  else
  if ($function_num = 5 or $function_num = 105) then
    fn:min($numbers)
  else
  if ($function_num = 6 or $function_num = 106) then
    math:product($numbers)
  else
  if ($function_num = 7 or $function_num = 107) then
   math:stdev($numbers)
  else
  if ($function_num = 8 or $function_num = 108) then
    math:stdevp($numbers)
  else
  if ($function_num = 9 or $function_num = 109) then
    fn:sum($numbers)
  else
  if ($function_num = 10 or $function_num = 110) then
    math:var($numbers)
  else
  if ($function_num = 11 or $function_num = 111) then
    math:varp($numbers)
  else
    fn:error($math:errNum, "Subtotal function: function_num should be between 1 and 11 or 101 and 111")
};
