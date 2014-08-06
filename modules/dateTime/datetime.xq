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
 : <p>This module provides functions to retrieve the current dateTime and to
 : parse dates and times.</p>
 : <p/>
 : <p>In contrast to the current-dateTime functions specified in
 : <a href="http://www.w3.org/TR/xpath-functions-30/">XQuery Functions and
 : Operators</a>, the functions in this module are nondeterministic, that is,
 : they do not return the current dateTime from the dynamic context, but return
 : the actual value.</p>
 : <p/>
 : <p>Dates and times are parsed according to the format given by
 : <a href="http://pubs.opengroup.org/onlinepubs/007904975/functions/strptime.html">strptime</a>.</p>
 : <p>However, date and time values must be "complete."</p>
 : <p>For a date, the year and either month and day or day of the year must have
 : been parsed.</p>
 : <p>For a time, the hour must have been parsed.
 : (If either the minute, second, or timezone has not been parsed, they default
 : to 0.)</p>
 : <p>For a dateTime, the parsing requirements of both date and time must be met.</p>
 : <p/>
 : <p>When a locale is given,
 : it must be of the form {lang}[{sep}{country}[{encoding}]] where
 : {lang} is an ISO 639-1 2-letter or 639-2 3-letter language code,
 : {sep} is either '-' or '_',
 : {country} is an ISO 3166-1 2-letter country code,
 : and {encoding} is any string that begins with a '.'.</p>
 : <p>The {sep}, {country}, and {encoding} are optional;
 : {encoding} is always ignored.</p>
 : <p>Examples include: de, en-US, fr_CA, ru_RU.UTF-8.</p>
 :
 : @author Matthias Brantner
 : @author Paul J. Lucas
 : @see http://www.w3.org/TR/xpath-functions/#context
 : @project Zorba/XML and JSON Data Model/Atomic/Datetime
 :
 :)
module namespace datetime = "http://zorba.io/modules/datetime";

declare namespace an = "http://zorba.io/annotations";

declare namespace ver = "http://zorba.io/options/versioning";
declare option ver:module-version "2.0";

(:~
 : <p>Gets the current date value in Universal time.</p>
 : <p>Note that this function is not stable: it returns the value of the date when
 : the function is invoked.</p>
 :
 : @return the non-stable date value
 :)
declare %an:nondeterministic function datetime:current-date()
  as xs:date external;

(:~
 : <p>Gets the current dateTime value in Universal time.</p>
 : <p>Note that this function is not stable: it returns the value of the date and
 : time when the function is invoked.</p>
 :
 : @return the non-stable datetime value
 :)
declare %an:nondeterministic function datetime:current-dateTime()
  as xs:dateTimeStamp external;

(:~
 : <p>Return the current time value in Universal time.</p>
 : <p>Note that this function is not stable: it returns the value of the time when
 : the function is invoked.</p>
 :
 : @return the non-stable time value
 :)
declare %an:nondeterministic function datetime:current-time()
  as xs:time external;

(:~
 : <p>Parses a date from a string in the current locale.</p>
 :
 : @param $input The string to parse.
 : @param $format The format string containing zero or more conversion
 : specifications and ordinary characters.  All ordinary characters are matched
 : exactly with the buffer; all whitespace characters match any amount of
 : whitespace in the buffer.
 : @return Returns an xs:date.
 : @error datetime:INVALID_SPECIFICATION if $format contains an invalid conversion specification.
 : @error datetime:INSUFFICIENT_BUFFER if $input is insufficient for $format.
 : @error datetime:INVALID_VALUE if $input contains an invalid value for a conversion
 : specification.
 : @error datetime:LITERAL_MISMATCH if there is a literal characer mismatch between $input
 : and $format.
 : @error datetime:INCOMPLETE_DATE_OR_TIME if the date is incomplete.
 : @example test/rbkt/Queries/zorba/datetime/datetime-parse-date-uD-1.xq
 : @example test/rbkt/Queries/zorba/datetime/datetime-parse-date-uF-1.xq
 :)
declare function datetime:parse-date(
  $input as xs:string,
  $format as xs:string
) as xs:date external;

(:~
 : <p>Parses a date from a string in the given locale.</p>
 :
 : @param $input The string to parse.
 : @param $format The format string containing zero or more conversion
 : specifications and ordinary characters.  All ordinary characters are matched
 : exactly with the buffer; all whitespace characters match any amount of
 : whitespace in the buffer.
 : @param $locale The locale to use.
 : @return Returns an xs:date.
 : @error datetime:INVALID_SPECIFICATION if $format contains an invalid conversion specification.
 : @error datetime:INSUFFICIENT_BUFFER if $input is insufficient for $format.
 : @error datetime:INVALID_VALUE if $input contains an invalid value for a conversion
 : specification.
 : @error datetime:LITERAL_MISMATCH if there is a literal characer mismatch between $input
 : and $format.
 : @error datetime:INCOMPLETE_DATE_OR_TIME if the date is incomplete.
 : @error datetime:INVALID_LOCALE if $locale is in an invalid format.
 : @error datetime:UNKNOWN_LOCALE if $locale is unknown.
 : @error datetime:UNSUPPORTED_LOCALE if $locale is unsupported by the operating system.
 : @example test/rbkt/Queries/zorba/datetime/datetime-parse-date-la-uD-1.xq
 : @example test/rbkt/Queries/zorba/datetime/datetime-parse-date-uA-uD-2.xq
 :)
declare function datetime:parse-date(
  $input as xs:string,
  $format as xs:string,
  $locale as xs:string
) as xs:date external;

(:~
 : <p>Parses a dateTime from a string in the current locale.</p>
 :
 : @param $input The string to parse.
 : @param $format The format string containing zero or more conversion
 : specifications and ordinary characters.  All ordinary characters are matched
 : exactly with the buffer; all whitespace characters match any amount of
 : whitespace in the buffer.
 : @return Returns an xs:dateTime.
 : @error datetime:INVALID_SPECIFICATION if $format contains an invalid conversion specification.
 : @error datetime:INSUFFICIENT_BUFFER if $input is insufficient for $format.
 : @error datetime:INVALID_VALUE if $input contains an invalid value for a conversion
 : specification.
 : @error datetime:LITERAL_MISMATCH if there is a literal characer mismatch between $input
 : and $format.
 : @error datetime:INCOMPLETE_DATE_OR_TIME if either the date or time is incomplete.
 : @example test/rbkt/Queries/zorba/datetime/datetime-parse-dateTime-uFTZ-1.xq
 :)
declare function datetime:parse-dateTime(
  $input as xs:string,
  $format as xs:string
) as xs:dateTime external;

(:~
 : <p>Parses a dateTime from a string in the given locale.</p>
 :
 : @param $input The string to parse.
 : @param $format The format string containing zero or more conversion
 : specifications and ordinary characters.  All ordinary characters are matched
 : exactly with the buffer; all whitespace characters match any amount of
 : whitespace in the buffer.
 : @param $locale The locale to use.
 : @return Returns an xs:dateTime.
 : @error datetime:INVALID_SPECIFICATION if $format contains an invalid conversion specification.
 : @error datetime:INSUFFICIENT_BUFFER if $input is insufficient for $format.
 : @error datetime:INVALID_VALUE if $input contains an invalid value for a conversion
 : specification.
 : @error datetime:LITERAL_MISMATCH if there is a literal characer mismatch between $input
 : and $format.
 : @error datetime:INCOMPLETE_DATE_OR_TIME if either the date or time is incomplete.
 : @error datetime:INVALID_LOCALE if $locale is in an invalid format.
 : @error datetime:UNKNOWN_LOCALE if $locale is unknown.
 : @error datetime:UNSUPPORTED_LOCALE if $locale is unsupported by the operating system.
 : @example test/rbkt/Queries/zorba/datetime/datetime-parse-dateTime-uAB-ld-uYTZ-1.xq
 : @example test/rbkt/Queries/zorba/datetime/datetime-parse-dateTime-uAB-ld-uYTZ-2.xq
 :)
declare function datetime:parse-dateTime(
  $input as xs:string,
  $format as xs:string,
  $locale as xs:string
) as xs:dateTime external;

(:~
 : <p>Parses a time from a string in the current locale.</p>
 :
 : @param $input The string to parse.
 : @param $format The format string containing zero or more conversion
 : specifications and ordinary characters.  All ordinary characters are matched
 : exactly with the buffer; all whitespace characters match any amount of
 : whitespace in the buffer.
 : @return Returns an xs:time.
 : @error datetime:INVALID_SPECIFICATION if $format contains an invalid conversion specification.
 : @error datetime:INSUFFICIENT_BUFFER if $input is insufficient for $format.
 : @error datetime:INVALID_VALUE if $input contains an invalid value for a conversion
 : specification.
 : @error datetime:LITERAL_MISMATCH if there is a literal characer mismatch between $input
 : and $format.
 : @error datetime:INCOMPLETE_DATE_OR_TIME if the hour has not been parsed.
 : @example test/rbkt/Queries/zorba/datetime/datetime-parse-time-uH-1.xq
 : @example test/rbkt/Queries/zorba/datetime/datetime-parse-time-uIMS-1.xq
 :)
declare function datetime:parse-time(
  $input as xs:string,
  $format as xs:string
) as xs:time external;

(:~
 : <p>Parses a time from a string in the given locale.</p>
 :
 : @param $input The string to parse.
 : @param $format The format string containing zero or more conversion
 : specifications and ordinary characters.  All ordinary characters are matched
 : exactly with the buffer; all whitespace characters match any amount of
 : whitespace in the buffer.
 : @param $locale The locale to use.
 : @return Returns an xs:time.
 : @error datetime:INVALID_SPECIFICATION if $format contains an invalid conversion specification.
 : @error datetime:INSUFFICIENT_BUFFER if $input is insufficient for $format.
 : @error datetime:INVALID_VALUE if $input contains an invalid value for a conversion
 : specification.
 : @error datetime:LITERAL_MISMATCH if there is a literal characer mismatch between $input
 : and $format.
 : @error datetime:INCOMPLETE_DATE_OR_TIME if the hour has not been parsed.
 : @error datetime:INVALID_LOCALE if $locale is in an invalid format.
 : @error datetime:UNKNOWN_LOCALE if $locale is unknown.
 : @error datetime:UNSUPPORTED_LOCALE if $locale is unsupported by the operating system.
 : @example test/rbkt/Queries/zorba/datetime/datetime-parse-time-lr-1.xq
 : @example test/rbkt/Queries/zorba/datetime/datetime-parse-time-lr-2.xq
 :)
declare function datetime:parse-time(
  $input as xs:string,
  $format as xs:string,
  $locale as xs:string
) as xs:time external;

(:~
 : <p>Converts the given number of milliseconds since epoch into its corresponding
 : xs:dateTime.</p>
 :
 : @param $millis The number of milliseconds since epoch.
 : @return Returns an xs:dateTime.
 : @example test/rbkt/Queries/zorba/datetime/datetime-millis-to-dateTime-1.xq
 :)
declare function datetime:millis-to-dateTime( $millis as xs:long )
  as xs:dateTime external;

(:~
 : <p>Gets the the number of milliseconds since epoch.</p>
 :
 : @return the said number of milliseconds.
 :)
declare %an:nondeterministic function datetime:timestamp()
  as xs:long external;

(:~
 : <p>Gets the offset of the current timezone from Universal time.</p>
 :
 : @return the offset in seconds with positive values being east of the prime
 : meridian.
 :)
declare %an:nondeterministic function datetime:utc-offset()
  as xs:long external;

(: vim:set et sw=2 ts=2: :)
