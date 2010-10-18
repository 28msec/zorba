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
 : defined by Microsoft Excel, under Information Functions.
 :
 : @author Sorin Nasoi
 :
 : @see <a href="http://office.microsoft.com/en-us/excel/CH062528261033.aspx"
 : target="_blank">Excel Documentation: Information Functions</a>
 :
 :)
module namespace  excel-information = "http://www.zorba-xquery.com/modules/excel/information" ;

(:~
 : Use excel-err module functions for throwing errors.
 :)
import module namespace excel-err="http://www.zorba-xquery.com/modules/excel/errors";

(:~
 : Import excel-math module functions.
 :)
import module namespace excel-math = "http://www.zorba-xquery.com/modules/excel/math";

(:~
 : Test if the passed argument is empty of not.
 :
 : @see     http://www.w3.org/TR/xquery-operators/#func-empty
 : @param   $value the value.
 : @return  If the value of $arg is the empty sequence, the function returns true, otherwise the function returns false.   
 :)
declare function excel-information:is-blank
  ( $value as xs:anyAtomicType? )  as xs:boolean {
  fn:empty($value)
 };

(:~
 : Test is a number is even.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052091481033.aspx
 : @param   $value the value.
 : @error   XQP0021(errValue) if provided value is not a number.
 : @return  TRUE if number is even, FALSE if number is odd.
 :)
declare function excel-information:is-even
  ( $value as xs:anyAtomicType? )  as xs:boolean {

 if(excel-math:is-a-number($value)) then
  fn:not(fn:boolean(fn:floor(fn:abs(fn:number($value))) mod 2))
 else
  fn:error($excel-err:errValue, "Provided value is not a number", $value)
 };

(:~
 : Test is a number is odd.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052091491033.aspx
 : @param   $value the value.
 : @error   XQP0021(errValue) if provided value is not a number.
 : @return  TRUE if number is odd, FALSE if number is even.
 :)
declare function excel-information:is-odd
  ( $value as xs:anyAtomicType? )  as xs:boolean {

 if(excel-math:is-a-number($value)) then
  fn:boolean(fn:floor(fn:abs(fn:number($value))) mod 2)
 else
  fn:error($excel-err:errValue, "Provided value is not a number", $value)
 };

(:~
 : Tests if the passed $value is a logical value.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052091471033.aspx
 : @param   $value the value.
 : @return  TRUE if $value refers to a logical value.
 :)
declare function excel-information:islogical
  ( $value as xs:anyAtomicType? )  as xs:boolean {

  if ($value instance of xs:boolean) then fn:true()
  else fn:false()
 };

(:~
 : Tests if the passed $value is a number.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052091471033.aspx
 : @param   $value the value.
 : @return  TRUE if $value refers to a number.
 :)
declare function excel-information:isnumber
  ( $value as xs:anyAtomicType? )  as xs:boolean {

  if (($value instance of xs:integer) or
      ($value instance of xs:decimal) or
      ($value instance of xs:float) or
      ($value instance of xs:double)) then fn:true()
  else fn:false()
 };

(:~
 : Tests if the passed $value is a string. 
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052091471033.aspx
 : @param   $value the value.
 : @return  TRUE if $value refers to text.
 :)
declare function excel-information:istext
  ( $value as xs:anyAtomicType? )  as xs:boolean {

  if ($value instance of xs:string) then fn:true()
  else fn:false()
 };

(:~
 : Converts a $value to a number.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052091871033.aspx
 : @param   $value the value.
 : @return  A $value converted to a number.
 :)
declare function excel-information:n
  ( $value as xs:anyAtomicType? )  as xs:anyAtomicType {

  if( excel-information:isnumber($value)) then $value
  else if( excel-information:islogical($value)) then $value cast as xs:integer
  else 0
 };

(:~
 : Returns the error value #N/A.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052091881033.aspx
 : @return  The error value #N/A. #N/A is the error value that means "no value is available."
 :)
declare function excel-information:na
  ()  as xs:anyAtomicType {

  fn:error($excel-err:errNA, "No value is available")
 };
