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
 : defined by Microsoft Excel, under Logical Functions.
 :
 : @author Sorin Nasoi
 :
 : @see <a href="http://office.microsoft.com/en-us/excel/CH062528271033.aspx"
 : target="_blank">Excel Documentation: Logical Functions</a>
 :
 :)
(:  for False,Not and True use fn:false(), fn:not(), fn:true() :)

module namespace  excel-logical = "http://www.zorba-xquery.com/modules/excel/logical" ;

(:~
 : Use excel-err module functions for throwing errors.
 :)
import module namespace excel-err="http://www.zorba-xquery.com/modules/excel/errors";

(:~
 : Returns TRUE if all its arguments are TRUE; FALSE if one or more arguments are FALSE.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052089861033.aspx
 : @param   $arg1 the first argument.
 : @param   $arg2 the second argument.
 : @return  TRUE if all its arguments are TRUE; FALSE if one or more arguments are FALSE.
 :)
declare function excel-logical:and
  ( $arg1 as xs:anyAtomicType,
    $arg2 as xs:anyAtomicType)  as xs:boolean {
    fn:boolean(($arg1 and $arg2))
 };

(:~
 : Returns TRUE if all its arguments are TRUE; FALSE if one or more arguments are FALSE.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052089861033.aspx
 : @param   $values the sequence of arguments.
 : @error   XQP0021(errValue) provided sequence is empty.
 : @return  TRUE if all its arguments are TRUE; FALSE if one or more arguments are FALSE.
 :)
declare function excel-logical:and
  ( $values as xs:anyAtomicType* )  as xs:boolean {
  let $distValues := distinct-values($values)
  return
  if(fn:empty($distValues)) then
    fn:error($excel-err:errValue, "Provided sequence is empty", $values)
  else
    every $value in $distValues satisfies $value eq fn:true()
 };

(:~
 : Returns one value if a condition you specify evaluates to TRUE and another value if it evaluates to FALSE.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052091181033.aspx
 : @param   $logical_test is any value or expression that can be evaluated to TRUE or FALSE.
 : @param   $value_if_true the value that is returned if logical_test is TRUE.
 : @param   $value_if_false the value that is returned if logical_test is FALSE.
 : @return  One value if a condition you specify evaluates to TRUE and another value if it evaluates to FALSE.
 :)
declare function excel-logical:if
  ( $logical_test as xs:boolean,
    $value_if_true as item()*,
    $value_if_false as item()*)  as item()* {
  if($logical_test) then
    $value_if_true
  else
    $value_if_false
 };

(:~
 : Returns TRUE if any argument is TRUE; FALSE if all arguments are FALSE.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052092091033.aspx
 : @param   $arg1 the first argument.
 : @param   $arg2 the second argument.
 : @return  TRUE if any argument is TRUE; FALSE if all arguments are FALSE.
 :)
declare function excel-logical:or
  ( $arg1 as xs:anyAtomicType,
    $arg2 as xs:anyAtomicType)  as xs:boolean {
    fn:boolean(($arg1 or $arg2))
 };

(:~
 : Returns TRUE if any argument is TRUE; FALSE if all arguments are FALSE.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052092091033.aspx
 : @param   $values the sequence of arguments.
 : @error   XQP0021(errValue) provided sequence is empty.
 : @return  TRUE if any argument is TRUE; FALSE if all arguments are FALSE.
 :)
declare function excel-logical:or
  ( $values as xs:anyAtomicType* )  as xs:boolean {
  let $distValues := distinct-values($values)
  return
  if(fn:empty($distValues)) then
    fn:error($excel-err:errValue, "Provided sequence is empty", $values)
  else
    some $value in $distValues satisfies $value eq fn:true()
 };
