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
 : @see <a href="http://office.microsoft.com/en-us/excel/CH062528231033.aspx"
 : target="_blank">Excel Documentation: Datetime Functions</a>
 :
 : @spec XQuery Specification: January 2007
 : @author Sorin Nasoi
 :
 :)
module namespace  excel-datetime = "http://www.zorba-xquery.com/modules/excel/datetime" ;

(:~
 : Use excel-err module functions for throwing errors.
 :)
import module namespace excel-err="http://www.zorba-xquery.com/modules/excel/errors";

(:~
 : Import excel-text module functions.
 :)
import module namespace excel-text = "http://www.zorba-xquery.com/modules/excel/text";

(:~
 : The day of the week, from a date.
 : 
 : @param $date the date.
 : @return the day of the week as a number, where from 0 (Sunday) to 6 (Saturday).
 :) 
declare %private function excel-datetime:day-of-week 
  ( $date as xs:anyAtomicType? )  as xs:integer? {
       
  if (fn:empty($date))
   then ()
  else xs:integer((xs:date($date) - xs:date('1899-01-01'))
   div xs:dayTimeDuration('P1D')) mod 7
 } ;

(:~
 : Tests if a year is leap or not.
 :
 : @param $date the date.
 : @return true if the year part of the supplied $date is a leap year, false otherwise.
 :)  
declare %private function excel-datetime:is-leap-year 
  ( $date as xs:date )  as xs:boolean {
       
    let $year := fn:year-from-date($date)
    return (($year mod 4 = 0 and $year mod 100 != 0) or
            ($year mod 400 = 0))            
 } ;

(: actual requirements :)
(:~
 : Returns the number of days between two dates based on a 360-day year.
 : 
 : @see http://office.microsoft.com/en-us/excel/HP052090471033.aspx 
 : @param $start_date the start date.
 : @param $end_date the end date.
 : @return The number of days between two dates based on a 360-day year (twelve 30-day months), which is used in some accounting calculations.<br/> 
 : Use this function to help compute payments if your accounting system is based on twelve 30-day months.<br/> 
 : The metod used is U.S. (NASD). If the starting date is the last day of a month, it becomes equal to the 30th of the same month. <br/> 
 : If the ending date is the last day of a month and the starting date is earlier than the 30th of a month, the ending date becomes equal to the 1st of the next month; otherwise the ending date becomes equal to the 30th of the same month.
 :) 
declare function excel-datetime:days360
  ( $start_date as xs:date,
    $end_date   as xs:date)  as xs:integer {
  
  excel-datetime:days360($start_date, $end_date, fn:false())
 } ;

(:~
 : Returns the number of days between two dates based on a 360-day year.
 :
 : @see http://office.microsoft.com/en-us/excel/HP052090471033.aspx
 : @param $start_date the start date.
 : @param $end_date the end date.
 : @param $method if false then US/NASD Method is used, otherwise the European Method is used.
 : @return The number of days between two dates based on a 360-day year (twelve 30-day months), which is used in some accounting calculations. 
 : Use this function to help compute payments if your accounting system is based on twelve 30-day months. <br />
 :The European Method (30E/360)<br />
 : - If either date A or B falls on the 31st of the month, that date will be changed to the 30th;<br />
 : - Where date B falls on the last day of February, the actual date B will be used.<br /><br />
 :
 :The US/NASD Method (30US/360)<br />
 : - If both date A and B fall on the last day of February, then date B will be changed to the 30th.<br />
 : - If date A falls on the 31st of a month or last day of February, then date A will be changed to the 30th.<br />
 : - If date A falls on the 30th of a month after applying (2) above and date B falls on the 31st of a month, then date B will be changed to the 30th.
 :)  
declare function excel-datetime:days360
  ( $start_date as xs:date,
    $end_date   as xs:date,
    $method     as xs:boolean)  as xs:integer   {
  
  if($method eq fn:true()) then (: European Method :)
    let $sd :=  if (fn:day-from-date($start_date) eq 31) then 
      excel-datetime:date(fn:year-from-date($start_date), fn:month-from-date($start_date), 30)
      else $start_date
    
    let $ed :=  if (fn:day-from-date($end_date) eq 31) then 
      excel-datetime:date(fn:year-from-date($end_date), fn:month-from-date($end_date), 30)
      else $end_date
      
    let $ed1 := excel-datetime:date(fn:year-from-date($ed), fn:month-from-date($ed), 01)
    
    let $ret := fn:days-from-duration($ed1 - $sd)+ fn:day-from-date($ed)
    return if($ret < 0) then $ret else $ret - 1
  else (: US/NASD Method :)
    let $ed :=  if(($start_date = $end_date) and 
       ((excel-datetime:is-leap-year($end_date) and (fn:day-from-date($end_date) eq 29)) or
       (fn:day-from-date($end_date) eq 28))) then 
       excel-datetime:date(fn:year-from-date($end_date), fn:month-from-date($end_date), 30)
       else $end_date
    
    return if((fn:day-from-date($start_date) eq 31) or 
      ((excel-datetime:is-leap-year($start_date) and (fn:day-from-date($start_date) eq 29)) or
      (fn:day-from-date($start_date) eq 28))) then 
      let $sd :=  excel-datetime:date(fn:year-from-date($start_date), fn:month-from-date($start_date), 30)
      let $ed := if (fn:day-from-date($ed) eq 31) then 
      excel-datetime:date(fn:year-from-date($ed), fn:month-from-date($ed), 30) else 
      $ed
      let $ed1 := excel-datetime:date(fn:year-from-date($ed), fn:month-from-date($ed), 01)
      let $ret := fn:days-from-duration($ed1 - $sd)+ fn:day-from-date($ed) - 1
      return if($ret < 0) then $ret else $ret - 1
    else   
      let $ed1 := excel-datetime:date(fn:year-from-date($ed), fn:month-from-date($ed), 01) 
      let $ret := fn:days-from-duration($ed1 - $start_date)+ fn:day-from-date($ed)
      return if($ret < 0) then $ret else $ret - 1
 } ;

(:~
 : Returns the hour of a time value.
 :
 : @see http://office.microsoft.com/en-us/excel/HP052091151033.aspx
 : @param $time the time.
 : @return The hour of a time value. The hour is as an integer, ranging from 0 (12:00 A.M.) to 23 (11:00 P.M.).
 :)  
declare function excel-datetime:hour
    ($time      as xs:time)     as xs:integer?  {
    
  fn:hours-from-time($time)  
 };

(:~
 : Returns the minutes of a time value. 
 :
 : @see http://office.microsoft.com/en-us/excel/HP052091781033.aspx
 : @param $time the time. 
 : @return The minutes of a time value. The minute is given as an integer, ranging from 0 to 59.
 :)  
declare function excel-datetime:minute
    ($time      as xs:time)     as xs:integer?  {
    
  fn:minutes-from-time($time)  
 };

(:~
 : Returns the month of a $date.
 :
 : @see http://office.microsoft.com/en-us/excel/HP052091841033.aspx
 : @param $date the date.
 : @return  the month of a $date. The month is given as an integer, ranging from 1 (January) to 12 (December).
 :)  
declare function excel-datetime:month
    ($date      as xs:date)     as xs:integer?  {
    
  fn:month-from-date($date)  
 };

(:~
 : Returns the seconds of a $time value. 
 :
 : @see http://office.microsoft.com/en-us/excel/HP052092511033.aspx
 : @param $time the time.
 : @return The seconds of a $time value. The second is given as an integer in the range 0 (zero) to 59.
 :)  
declare function excel-datetime:second
    ($time      as xs:time)     as xs:decimal   ?  {
    
  fn:seconds-from-time($time)  
 };

(:~
 : Returns the day of a $date, represented by a serial number.  
 :
 : @see http://office.microsoft.com/en-us/excel/HP052090461033.aspx
 : @param $date the date.
 : @return The day of a $date, represented by a serial number. The day is given as an integer ranging from 1 to 31. 
 :) 
declare function excel-datetime:day
    ($date      as xs:date)     as xs:integer?  {
    
  fn:day-from-date($date)  
 };

(:~
 : Returns the year corresponding to a date. 
 :
 : @see http://office.microsoft.com/en-us/excel/HP052093431033.aspx
 : @param $date the date.
 : @return The year corresponding to a date.
 :)  
declare function excel-datetime:year
    ($date      as xs:date)     as xs:integer?  {
    
  fn:year-from-date($date)  
 };

(:~
 : Returns the current date.
 :
 : @see http://www.w3.org/TR/xquery-operators/#func-current-date
 : @return The current date.
 :)  
declare function excel-datetime:today
    ()     as xs:date?  {
    
  fn:current-date()  
 };

(:~
 : Returns the current date and time. 
 :
 : @see http://www.w3.org/TR/xquery-operators/#func-current-dateTime
 : @return The current date and time.
 :)  
declare function excel-datetime:now
    ()     as xs:dateTime?  {
    
  fn:current-dateTime() 
 };

(:~
 : Constructs a date given the hours, months and days.
 TODO what happens when the params are not in range
 :
 : @see http://office.microsoft.com/en-us/excel/HP052090421033.aspxs
 : @param $year the year
 : @param $month the month 
 : @param $day the day 
 : @return A date given the hours, months and days
 :) 
declare function excel-datetime:date
    ($year      as xs:integer,
     $month     as xs:integer,
     $day       as xs:integer)     as xs:date?  {
    
  let $vyear := excel-text:pad-integer-to-length($year, "0", 4)
  let $vmonth := excel-text:pad-integer-to-length($month, "0", 2)
  let $vday := excel-text:pad-integer-to-length($day, "0", 2)
   
  return xs:date(fn:string-join(($vyear, $vmonth, $vday),"-"))
 }; 

(: TODO what happens when the params are not in range :)
(:~
 : Constructs a time given the hours, minutes and seconds.
 :
 : @see http://office.microsoft.com/en-us/excel/HP052093151033.aspx
 : @param $hour the hour.
 : @param $minute the minute.
 : @param $second the second.
 : @return A time given the hours, minutes and seconds.
 :)  
declare function excel-datetime:time
    ($hour      as xs:integer,
     $minute    as xs:integer,
     $second    as xs:integer)     as xs:time?  {
   
  let $vhour := excel-text:pad-integer-to-length($hour, "0",2)
  let $vminute := excel-text:pad-integer-to-length($minute, "0",2)
  let $vsecond := excel-text:pad-integer-to-length($second, "0",2)
   
  return xs:time(fn:string-join(($vhour, $vminute,$vsecond),":"))
 }; 

(:~
 : Returns the day of the week corresponding to a $date.
 :
 : @see http://office.microsoft.com/en-us/excel/HP052093151033.aspx
 : @param $date the date.
 : @return The day of the week corresponding to a $date. The day is given as an integer, ranging from 1 (Sunday) to 7 (Saturday).
 :)  
declare function excel-datetime:weekday
    ($date      as xs:date)      as xs:integer? {
    
  excel-datetime:weekday($date, 1)    
};

(:~
 : Returns the day of the week corresponding to a $date depending on $return_type.
 :
 : @see http://office.microsoft.com/en-us/excel/HP052093361033.aspx
 : @param $date the date.
 : @param $return_type 1 for Numbers 1 (Sunday) through 7 (Saturday). 2 for Numbers 1 (Monday) through 7 (Sunday). 3 for Numbers 0 (Monday) through 6 (Sunday).
 : @error   XQP0021(errValue) if $return_type is outside the range [1,3].
 : @return The day of the week corresponding to a $date depending on $return_type.
 :) 
declare function excel-datetime:weekday
    ($date          as xs:date,
     $return_type   as xs:integer)      as xs:integer? {
    
  if ($return_type eq 1) then
    excel-datetime:day-of-week($date) + 1
  else if ($return_type eq 2) then
    if (excel-datetime:day-of-week($date) eq 0) then 7
    else excel-datetime:day-of-week($date)
  else if ($return_type eq 3) then
    if(excel-datetime:day-of-week($date) eq 0) then 6
    else excel-datetime:day-of-week($date) - 1
  else
    fn:error($excel-err:errValue, "Provided number must be in range [1,3]", $return_type)
};

(:~
 : Returns the number of whole working days between $start_date and $end_date. 
 :
 : @see http://office.microsoft.com/en-us/excel/HP052091901033.aspx
 : @param $start_date the start date.
 : @param $end_date the end date.
 : @return The number of whole working days between start_date and end_date.<br/>
 : Working days exclude weekends and any dates identified in holidays.<br/>
 : Use NETWORKDAYS to calculate employee benefits that accrue based on the number of days worked during a specific term. 
 :)  
declare function excel-datetime:networkdays
    ($start_date        as xs:date,
     $end_date          as xs:date) as xs:integer* {
     
  excel-datetime:networkdays( $start_date, $end_date, ())  
}; 

(:~
 : Returns the number of whole working days between $start_date and $end_date.
 :
 : @see http://office.microsoft.com/en-us/excel/HP052091901033.aspx
 : @param $start_date the start date.
 : @param $end_date the end date.
 : @param $holidays one or more dates to exclude from the working calendar, such as state and federal holidays and floating holidays.
 : @return The number of whole working days between start_date and end_date.<br/> 
 : Working days exclude weekends and any dates identified in holidays.<br/>
 : Use NETWORKDAYS to calculate employee benefits that accrue based on the number of days worked during a specific term.
 :)  
declare function excel-datetime:networkdays
    ($start_date        as xs:date,
     $end_date          as xs:date,
     $holidays          as xs:date*) as xs:integer* {

     let $days := fn:days-from-duration($end_date - $start_date) + 1 
     
     let $before := 8 - excel-datetime:day-of-week($start_date)    
     let $after := excel-datetime:day-of-week($end_date)     
     
     let $working_days := (($days - $before - $after)  idiv 7 )*5 
     + (if(excel-datetime:day-of-week($start_date) < 7) then 6 - excel-datetime:day-of-week($start_date) else 0) 
     + (if($after < 6) then $after else if($after eq 6) then 5 else 0)
     
     let $hol := fn:count( for $date in $holidays
                            return if(($start_date lt $date) and 
                                ($date lt $end_date) and 
                                (excel-datetime:day-of-week($date) ne 6) and
                                (excel-datetime:day-of-week($date) ne 0)) then 1
                             else ())
   
     return $working_days - $hol  
};
