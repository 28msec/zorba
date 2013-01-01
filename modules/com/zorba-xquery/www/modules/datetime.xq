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
 : This module provides functions to retrieve the current dateTime and to
 : parse dates and times.
 :
 : In contrast to the current-dateTime functions specified in
 : <a href="http://www.w3.org/TR/xpath-functions-30/">XQuery Functions and
 : Operators</a>, the functions in this module are nondeterministic, that is,
 : they do not return the current dateTime from the dynamic context, but return
 : the actual value.
 :
 : Dates and times are parsed according to the format given by
 : <a href="http://pubs.opengroup.org/onlinepubs/007904975/functions/strptime.html">strptime</a>.
 : However, date and time values must be "complete."
 : For a date, the year and either month and day or day of the year must have
 : been parsed.
 : For a time, the hour must have been parsed.
 : (If either the minute, second, or timezone has not been parsed, they default
 : to 0.)
 : For a dateTime, the parsing requirements of both date and time must be met.
 :
 : @author Matthias Brantner
 : @author Paul J. Lucas
 : @see http://www.w3.org/TR/xpath-functions/#context
 : @project XDM/atomic
 :
 :)
module namespace datetime = "http://www.zorba-xquery.com/modules/datetime";

declare namespace an = "http://www.zorba-xquery.com/annotations";
declare namespace zerr = "http://www.zorba-xquery.com/errors";

declare namespace ver = "http://www.zorba-xquery.com/options/versioning";
declare option ver:module-version "2.0";

(:~
 : Gets the current date value in Universal time.
 : Note that this function is not stable: it returns the value of the date when
 : the function is invoked.
 :
 : @return the non-stable date value
 :)
declare %an:nondeterministic function datetime:current-date()
  as xs:date external;

(:~
 : Gets the current dateTime value in Universal time.
 : Note that this function is not stable: it returns the value of the date and
 : time when the function is invoked.
 :
 : @return the non-stable datetime value
 :)
declare %an:nondeterministic function datetime:current-dateTime()
  as xs:dateTime external;

(:~
 : Return the current time value in Universal time.
 : Note that this function is not stable: it returns the value of the time when
 : the function is invoked.
 :
 : @return the non-stable time value
 :)
declare %an:nondeterministic function datetime:current-time()
  as xs:time external;

(:~
 : Parses a date from a string.
 :
 : @param $input The string to parse.
 : @param $format The format string containing zero or more conversion
 : specifications and ordinary characters.  All ordinary characters are matched
 : exactly with the buffer; all whitespace characters match any amount of
 : whitespace in the buffer.
 : @return Returns an xs:date.
 : @error zerr:ZDTP0001 if $format contains an invalid conversion specification.
 : @error zerr:ZDTP0002 if $input is insufficient for $format.
 : @error zerr:ZDTP0003 if $input contains an invalid value for a conversion
 : specification.
 : @error zerr:ZDTP0004 if there is a literal characer mismatch between $input
 : and $format.
 : @error zerr:ZDTP0005 if the date is incomplete.
 : @example test/rbkt/Queries/zorba/datetime/datetime-parse-date-uD-1.xq
 : @example test/rbkt/Queries/zorba/datetime/datetime-parse-date-uF-1.xq
 :)
declare function datetime:parse-date(
  $input as xs:string,
  $format as xs:string
) as xs:date external;

(:~
 : Parses a dateTime from a string.
 :
 : @param $input The string to parse.
 : @param $format The format string containing zero or more conversion
 : specifications and ordinary characters.  All ordinary characters are matched
 : exactly with the buffer; all whitespace characters match any amount of
 : whitespace in the buffer.
 : @return Returns an xs:dateTime.
 : @error zerr:ZDTP0001 if $format contains an invalid conversion specification.
 : @error zerr:ZDTP0002 if $input is insufficient for $format.
 : @error zerr:ZDTP0003 if $input contains an invalid value for a conversion
 : specification.
 : @error zerr:ZDTP0004 if there is a literal characer mismatch between $input
 : and $format.
 : @error zerr:ZDTP0005 if either the date or time is incomplete.
 : @example test/rbkt/Queries/zorba/datetime/datetime-parse-dateTime-uFTZ-1.xq
 :)
declare function datetime:parse-dateTime(
  $input as xs:string,
  $format as xs:string
) as xs:dateTime external;

(:~
 : Parses a time from a string.
 :
 : @param $input The string to parse.
 : @param $format The format string containing zero or more conversion
 : specifications and ordinary characters.  All ordinary characters are matched
 : exactly with the buffer; all whitespace characters match any amount of
 : whitespace in the buffer.
 : @return Returns an xs:time.
 : @error zerr:ZDTP0001 if $format contains an invalid conversion specification.
 : @error zerr:ZDTP0002 if $input is insufficient for $format.
 : @error zerr:ZDTP0003 if $input contains an invalid value for a conversion
 : specification.
 : @error zerr:ZDTP0004 if there is a literal characer mismatch between $input
 : and $format.
 : @error zerr:ZDTP0005 if the hour has not been parsed.
 : @example test/rbkt/Queries/zorba/datetime/datetime-parse-time-uH-1.xq
 : @example test/rbkt/Queries/zorba/datetime/datetime-parse-time-uIMS-1.xq
 :)
declare function datetime:parse-time(
  $input as xs:string,
  $format as xs:string
) as xs:time external;

(:~
 : Gets the the number of milliseconds since epoch.
 :
 : @return the said number of milliseconds.
 :)
declare %an:nondeterministic function datetime:timestamp()
  as xs:long external;

(:~
 : Gets the offset of the current timezone from Universal time.
 :
 : @return the offset in seconds with positive values being east of the prime
 : meridian.
 :)
declare %an:nondeterministic function datetime:utc-offset()
  as xs:long external;

(: vim:set et sw=2 ts=2: :)
