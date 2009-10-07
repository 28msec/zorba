(:~
 : Module Name: eXcel-logical
 : Module Version: 0.1
 : Date: August 1, 2009
 : Copyright: 2006-2008 The FLWOR Foundation. Licensed under the Apache License, Version 2.0.
 : Proprietary XQuery Extensions Used: None
 : XQuery Specification: January 2007
 : Module Overview: This is a library module offering the same set of functions
 : defined by Microsoft Excel into 
 : @see http://office.microsoft.com/en-us/excel/CH062528271033.aspx
 : @author  Sorin Nasoi
 :)

(:  for False,Not and True use fn:false(), fn:not(), fn:true() :)

module namespace  excel-logical = "http://www.zorba-xquery.com/modules/excel/logical" ;

import module namespace excel-err="http://www.zorba-xquery.com/modules/excel/errors";

(:~
 : Returns TRUE if all its arguments are TRUE; returns FALSE if one or more argument is FALSE.
 : 
 : @see     http://office.microsoft.com/en-us/excel/HP052089861033.aspx
 : @param   $arg1 the first argument
 : @param   $arg2 the second argument
 :) 
declare function excel-logical:and
  ( $arg1 as xs:anyAtomicType,
    $arg2 as xs:anyAtomicType)  as xs:boolean {
    fn:boolean(($arg1 and $arg2))
 } ;

(:~
 : Returns TRUE if all its arguments are TRUE; returns FALSE if one or more argument is FALSE.
 : 
 : @see     http://office.microsoft.com/en-us/excel/HP052089861033.aspx
 : @param   $values the sequence of arguments
 : @error   XQP0021(errValue) provided sequence is empty
 :) 
declare function excel-logical:and
  ( $values as xs:anyAtomicType* )  as xs:boolean {
  let $distValues := distinct-values($values)
  return
  if(fn:empty($distValues)) then
    fn:error($excel-err:errValue, "Provided sequence is empty", $values)
  else
    every $value in $distValues satisfies $value eq fn:true()
 } ;

(:~
 : Returns one value if a condition you specify evaluates to TRUE and another value if it evaluates to FALSE.
 : 
 : @see     http://office.microsoft.com/en-us/excel/HP052091181033.aspx
 : @param   $logical_test is any value or expression that can be evaluated to TRUE or FALSE
 : @param   $value_if_true the value that is returned if logical_test is TRUE
 : @param   $value_if_false the value that is returned if logical_test is FALSE
 :) 
declare function excel-logical:if
  ( $logical_test as xs:boolean,
    $value_if_true as item()*,
    $value_if_false as item()*)  as item()* {
  if($logical_test) then
    $value_if_true
  else
    $value_if_false
 } ;

(:~
 : Returns TRUE if any argument is TRUE; returns FALSE if all arguments are FALSE.
 : 
 : @see     http://office.microsoft.com/en-us/excel/HP052092091033.aspx
 : @param   $arg1 the first argument
 : @param   $arg2 the second argument
 :) 
declare function excel-logical:or
  ( $arg1 as xs:anyAtomicType,
    $arg2 as xs:anyAtomicType)  as xs:boolean {
    fn:boolean(($arg1 or $arg2))
 } ;

(:~
 : Returns TRUE if any argument is TRUE; returns FALSE if all arguments are FALSE.
 : 
 : @see     http://office.microsoft.com/en-us/excel/HP052092091033.aspx
 : @param   $values the sequence of arguments
 : @error   XQP0021(errValue) provided sequence is empty
 :)  
declare function excel-logical:or
  ( $values as xs:anyAtomicType* )  as xs:boolean {
  let $distValues := distinct-values($values)
  return
  if(fn:empty($distValues)) then
    fn:error($excel-err:errValue, "Provided sequence is empty", $values)
  else
    some $value in $distValues satisfies $value eq fn:true()
 } ;
