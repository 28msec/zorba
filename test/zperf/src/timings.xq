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

module namespace tims = 'http://www.example.com/timings';

import module namespace functx = "http://www.functx.com/"; 

declare namespace pdash = "http://www.28msec.com/pdash";


declare function tims:getFirstNumber ($string as xs:string, $firstDelimiter as xs:string, $secondDelimiter as xs:string) as xs:float
{
  let $tempString := tims:substring-after-last($string, $firstDelimiter)
  let $tempString := fn:substring-after($tempString, ':')
  let $tempString := fn:substring-before($tempString, $secondDelimiter)
  let $tempString := fn:substring-before($tempString, '(')
  return xs:float($tempString)
};

declare function tims:getSecondNumber ($string as xs:string?, $firstDelimiter as xs:string?, $secondDelimiter as xs:string?) as xs:float? {
  let $tempString := tims:substring-after-last($string, $firstDelimiter)
  let $tempString := fn:substring-before($tempString, $secondDelimiter)
  let $tempString := fn:substring-after($tempString, '(user:')
  let $tempString := fn:substring-before($tempString, ')')
  return xs:float($tempString)
};

declare function tims:getFirstNumberEx ($string as xs:string, $firstDelimiter as xs:string, $secondDelimiter as xs:string) as xs:float
{
  let $t1 := tims:substring-after-last($string, $firstDelimiter)
  let $t2 := fn:substring-after($t1, '=')
  let $t3 := fn:substring-before($t2, $secondDelimiter)
  return xs:float($t3)
};

declare function tims:substring-after-last($arg as xs:string?, $delim as xs:string )  
    as xs:string 
{     
   if (fn:contains($arg, $delim))
   then
     tims:substring-after-last(fn:substring-after($arg, $delim), $delim)
   else
     $arg
};


declare function tims:parseTimings ($string as xs:string) 
{
    (: let $numberOfExecutions     := tims:getFirstNumberEx (fn:trace($string,"input"), 'Number of executions', 'Engine') :)

    let $engineStartupTime      := tims:getFirstNumber ($string, 'Engine Startup Time',     'Average Compilation Time')
    (: let $engineStartupTimeUser  := tims:getSecondNumber($string, 'Engine Startup Time',     'Average Compilation Time') :)
    let $avgCompilationTime     := tims:getFirstNumber ($string, 'Average Compilation Time','Average Execution Time')
    (: let $avgCompilationTimeUser := tims:getSecondNumber($string, 'Average Compilation Time','Average Execution Time') :)
    let $avgExecutionTime       := tims:getFirstNumber ($string, 'Average Execution Time',  'Average Loading Time')
    (: let $avgExecutionTimeUser   := tims:getSecondNumber($string, 'Average Execution Time',  'Average Loading Time') :)
    let $avgLoadingTime         := tims:getFirstNumber ($string, 'Average Loading Time',    'Average Unloading Time')
    (: let $avgLoadingTimeUser     := tims:getSecondNumber($string, 'Average Loading Time',    'Average Unloading Time') :)
    let $avgUnloadingTime       := tims:getFirstNumber ($string, 'Average Unloading Time',  'Average Total Time')
    (: let $avgUnloadingTimeUser   := tims:getSecondNumber($string, 'Average Unloading Time',  'Average Total Time') :)
    let $avgTotalTime           := tims:getFirstNumber ($string, 'Average Total Time',      'Engine Shutdown Time')
    (: let $avgTotalTimeUser       := tims:getSecondNumber($string, 'Average Total Time',      'Engine Shutdown Time') :)
    let $engineShutdownTime     := tims:getFirstNumber ($string, 'Engine Shutdown Time',    'milliseconds')
    (: let $engineShutdownTimeUser := tims:getSecondNumber($string, 'Engine Shutdown Time',    'milliseconds') 
    
    return ($numberOfExecutions, 
            $engineStartupTime, $engineStartupTimeUser, $avgCompilationTime, $avgCompilationTimeUser,
            $avgExecutionTime, $avgExecutionTimeUser, $avgLoadingTime, $avgLoadingTimeUser, 
            $avgUnloadingTime, $avgUnloadingTimeUser, $avgTotalTime, $avgTotalTimeUser, 
            $engineShutdownTime, $engineShutdownTimeUser)
    :)
    
    return 
      ( <pdash:measurements>
            <pdash:avgCompilationTime>{$avgCompilationTime}</pdash:avgCompilationTime>
            <pdash:avgExecutionTime>{$avgExecutionTime}</pdash:avgExecutionTime>
            <pdash:avgLoadingTime>{$avgLoadingTime}</pdash:avgLoadingTime>
            <pdash:avgUnloadingTime>{$avgUnloadingTime}</pdash:avgUnloadingTime>
            <pdash:avgDiffToTotalTime>
                {$avgTotalTime - $avgCompilationTime - $avgExecutionTime - $avgLoadingTime - $avgUnloadingTime}
            </pdash:avgDiffToTotalTime>
        </pdash:measurements>,
        <extra>
            <pdash:engineStartupTime>{$engineStartupTime}</pdash:engineStartupTime> 
            <pdash:engineShutdownTime>{$engineShutdownTime}</pdash:engineShutdownTime>
        </extra>
      )
};


(: 
 :   Example
 
declare variable $string as xs:string := "
<xml ...>
<xml ...>
<xml ...>
Number of executions = 3
Engine Startup Time     : 30.584 (user: 30.512) milliseconds
Average Compilation Time: 0.564 (user: 0.564) milliseconds
Average Execution Time  : 0.036 (user: 0.037) milliseconds
Average Loading Time    : 0.000 (user: 0.000) milliseconds
Average Unloading Time  : 2.896 (user: 2.892) milliseconds
Average Total Time      : 3.502 (user: 3.496) milliseconds

Engine Shutdown Time     : 0.003 (user: 0.003) milliseconds
";


declare variable $result := tims:parseTimings($string);
$result:)