xquery version "3.0";

(:
 : Copyright 2006-2013 The FLWOR Foundation.
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
 : This module provides a function to put the currently running query
 : to sleep.
 :
 :)
module namespace sleep = "http://zorba.io/modules/sleep";

declare namespace an = "http://zorba.io/annotations";

declare namespace ver = "http://zorba.io/options/versioning";
declare option ver:module-version "1.0";

(:~ 
 : Puts the currently running query to sleep.
 : This function is mainly useful in development e.g. to simulate the
 : effects of long-running tasks wrt. the concurrent execution of
 : requests.
 :
 : @param $millis the number of milliseconds to sleep
 : @return the function is sequential and returns the empty sequence
 :)
declare %an:sequential function sleep:millis($millis as xs:integer)
  as empty-sequence() external;
