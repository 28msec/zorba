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
 : This module provides functions to retrieve the current dateTime.
 : In contrast to the current-dateTime functions specified in
 : "XQuery Functions and Operators" (see http://www.w3.org/TR/xpath-functions/#context)
 : the functions in this module are nondeterministic. That is, they do not
 : return the current-dateTime from the dynamic context but return the actual
 : value.
 :)
module namespace datetime = "http://www.zorba-xquery.com/modules/datetime";

(:~
 : Return the current dateTime value.
 : Please note, that this function is not stable. It returns the
 : dateTime value of the date and time the function has actually been invoked.
 :
 : @return the non-stable datetime value
 :)
declare %nondeterministic function datetime:current-dateTime ( ) as xs:dateTime external;

(:~
 : Return the current time value.
 : Please note, that this function is not stable. It returns the
 : time value of the date and time the function has actually been invoked.
 :
 : @return the non-stable time value
 :)
declare %nondeterministic function datetime:current-time ( ) as xs:time external;

(:~
 : Return the current date value.
 : Please note, that this function is not stable. It returns the
 : dat value of the date the function has been actually invoked.
 :
 : @return the non-stable date value
 :)
declare %nondeterministic function datetime:current-date ( ) as xs:date external;
