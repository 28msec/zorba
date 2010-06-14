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
 : Module provides funtions to execute a command.
 : Examples:
 :    import module namespace proc = "http://www.zorba-xquery.com/modules/process"; 
 :    proc:exec("ls"),
 :    proc:exec("md5sum", "file.txt"),
 :    
 :)
module namespace process = "http://www.zorba-xquery.com/modules/process";

(:~
 : Simple process execution
 : @param $cmd   shell commad to be executed (without arguments)
 : @return       the result of the execution
 : @error        An error is thrown if process canot be executed.
 :)
declare sequential function process:exec (
    $cmd as xs:string
    ) as node() external;

(:~
 :  Process execution with arguments
 :  @param $cmd   shell commad to be executed
 :  @param $args  arguments for cmd
 :  @return       the result of the execution
 : @error        An error is thrown if process canot be executed.
 :)
declare sequential function process:exec (
    $cmd as xs:string,
    $args as xs:string*
    ) as node() external;


