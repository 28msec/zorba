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
 : This module implements some Excel 2003 statistical functions
 : that cannot be implemented with standard XQuery functions.
 : It uses Zorba specific functions.
 : 
 : @Author Daniel Turcanu
 : @See  http://office.microsoft.com/en-us/excel/CH062528311033.aspx
:)
module namespace  excel = "http://www.zorba-xquery.com/modules/excel/statistical-zorba" ;

import module namespace
excel-math="http://www.zorba-xquery.com/modules/excel/math";

import module namespace
excel-statistical="http://www.zorba-xquery.com/modules/excel/statistical";

import module namespace
excel-err="http://www.zorba-xquery.com/modules/excel/errors";


(:~
 : Estimates standard deviation based on a sample. 
 : The standard deviation is a measure of how widely values are dispersed 
 :   from the average value (the mean).
 : It is computed with formula:
 : sqrt( sum((x-average_x)^2) / (n-1) )    = sqrt ( VAR(numbers) )
 :
 : @see http://office.microsoft.com/en-us/excel/HP052092771033.aspx
 : @param $numbers the sequence of numbers or values castable to numeric
 :    The sequence can be of any length, from 1 up.
 : @return the standard deviation, as numeric type
 : @error the errors returned by VAR function
 : @example rbkt/Queries/zorba/excel/statistical/stdev1.xq
:)
declare function excel:stdev($numbers as xs:anyAtomicType+) as xs:anyAtomicType
{
  math:sqrt(excel-statistical:var($numbers))
};

(:~
 : Estimates standard deviation based on a sample. 
 : The standard deviation is a measure of how widely values are dispersed 
 :   from the average value (the mean).
 : It is computed with formula:
 : sqrt( sum((x-average_x)^2) / (n-1) )    = sqrt ( VARA(numbers) )
 :
 : @see http://office.microsoft.com/en-us/excel/HP052092791033.aspx
 : @param $numbers the sequence of numbers or values castable to numeric
 :    The sequence can be of any length, from 1 up.
 : @return the standard deviation, as numeric type
 : @error the errors returned by VARA function
 : @example rbkt/Queries/zorba/excel/statistical/stdeva1.xq
:)
declare function excel:stdeva($numbers as xs:anyAtomicType+) as xs:anyAtomicType
{
  math:sqrt(excel-statistical:vara($numbers))
};

(:~
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
 : @error the errors returned by VARP function
 : @example rbkt/Queries/zorba/excel/statistical/stdevp1.xq
:)
declare function excel:stdevp($numbers as xs:anyAtomicType+) as xs:anyAtomicType
{
  math:sqrt(excel-statistical:varp($numbers))
};

(:~
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
 : @error the errors returned by VARPA function
 : @example rbkt/Queries/zorba/excel/statistical/stdevpa1.xq
:)
declare function excel:stdevpa($numbers as xs:anyAtomicType+) as xs:anyAtomicType
{
  math:sqrt(excel-statistical:varpa($numbers))
};

(:~ 
 : Moved from math module.
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
 : @param %numbers the sequence of numbers or values castable to numeric.
 :     The sequence can be of any length.
 : @return The function result, as numeric type
 : @error ** depends on the function called
 : @error XQP0021(errNum) if $function_num is not a value between 1 .. 11 or 101 .. 111
 : @example rbkt/Queries/zorba/excel/statistical/priority1/subtotal1.xq
 : @example rbkt/Queries/zorba/excel/statistical/priority1/subtotal2.xq
 : @example rbkt/Queries/zorba/excel/statistical/priority1/subtotal3.xq
 : @example rbkt/Queries/zorba/excel/statistical/priority1/subtotal4.xq
 : @example rbkt/Queries/zorba/excel/statistical/priority1/subtotal5.xq
 : @example rbkt/Queries/zorba/excel/statistical/priority1/subtotal6.xq
 : @example rbkt/Queries/zorba/excel/statistical/priority1/subtotal7.xq
 : @example rbkt/Queries/zorba/excel/statistical/priority1/subtotal8.xq
 : @example rbkt/Queries/zorba/excel/statistical/priority1/subtotal9.xq
 : @example rbkt/Queries/zorba/excel/statistical/priority1/subtotal10.xq
 : @example rbkt/Queries/zorba/excel/statistical/priority1/subtotal11.xq
:)
declare function excel:subtotal($function_num as xs:integer, $numbers as xs:anyAtomicType*) as xs:anyAtomicType
{
  if ($function_num = 1 or $function_num = 101) then
    excel-statistical:average($numbers)
  else 
  if ($function_num = 2 or $function_num = 102) then
    excel-statistical:count($numbers)
  else
  if ($function_num = 3 or $function_num = 103) then
    excel-statistical:counta($numbers)
  else
  if ($function_num = 4 or $function_num = 104) then
    excel-statistical:max($numbers)
  else
  if ($function_num = 5 or $function_num = 105) then
    excel-statistical:min($numbers)
  else
  if ($function_num = 6 or $function_num = 106) then
    excel-math:product($numbers)
  else
  if ($function_num = 7 or $function_num = 107) then
   excel:stdev($numbers)
  else
  if ($function_num = 8 or $function_num = 108) then
    excel:stdevp($numbers)
  else
  if ($function_num = 9 or $function_num = 109) then
    excel-math:sum($numbers)
  else
  if ($function_num = 10 or $function_num = 110) then
    excel-statistical:var($numbers)
  else
  if ($function_num = 11 or $function_num = 111) then
    excel-statistical:varp($numbers)
  else
    fn:error($excel-err:errNum, "Subtotal function: function_num should be between 1 and 11 or 101 and 111")
};
