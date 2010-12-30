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
 : defined by Microsoft Excel, under Text and Data Functions.
 :
 : @author Sorin Nasoi
 :
 : @see <a href="http://office.microsoft.com/en-us/excel/CH062528321033.aspx"
 : target="_blank">Excel Documentation: Text Functions</a>
 :
 :)
module namespace  excel-text = "http://www.zorba-xquery.com/modules/excel/text" ;

(:~
 : Use excel-err module functions for throwing errors.
 :)
import module namespace excel-err="http://www.zorba-xquery.com/modules/excel/errors";

(:~
 : Import excel-math module functions.
 :)
import module namespace excel-math="http://www.zorba-xquery.com/modules/excel/math";

(:~
 : Returns the union of the values in two sequences in an implementation-defined order. It removes duplicates.
 :
 : @param   $arg1 the first sequence.
 : @param   $arg2 the second sequence.
 : @return  The union of the values in two sequences in an implementation-defined order. It removes duplicates.
 :)
declare %private function excel-text:value-union 
  ( $arg1 as xs:anyAtomicType* ,
    $arg2 as xs:anyAtomicType* )  as xs:anyAtomicType* {

  fn:distinct-values(($arg1, $arg2))
 } ;

(:~
 : Returns the intersection of the values in two sequences in an implementation-defined order. It removes duplicates.
 :
 : @param   $arg1 the first sequence.
 : @param   $arg2 the second sequence.
 : @return  The intersection of the values in two sequences in an implementation-defined order. It removes duplicates.
 :)
declare %private function excel-text:value-intersect 
  ( $arg1 as xs:anyAtomicType* ,
    $arg2 as xs:anyAtomicType* )  as xs:anyAtomicType* {

  fn:distinct-values($arg1[.=$arg2])
 } ;

(:~
 : Returns the values in one sequence that do not appear in the second sequence in an implementation-defined order.
 :
 : @param   $arg1 the first sequence.
 : @param   $arg2 the second sequence.
 : @return  The values in one sequence that do not appear in the second sequence in an implementation-defined order.
 :)
declare function excel-text:value-except 
  ( $arg1 as xs:anyAtomicType* ,
    $arg2 as xs:anyAtomicType* )  as xs:anyAtomicType* {

  fn:distinct-values($arg1[not(.=$arg2)])
 } ;

(:~
 : Reverses the order of characters in a string.
 :
 : @param   $arg the string.
 : @return  Reverses the order of characters in a string or zero-length string if the argument is the empty sequence.
 :)
declare %private function excel-text:reverse-string 
  ( $arg        as xs:string? )  as xs:string {

   fn:codepoints-to-string(fn:reverse(fn:string-to-codepoints($arg)))
 } ;

(:~
 : Returns $string appended with enough repetitions of $padChar to make its length $length.
 :
 : @param   $string the string.
 : @param   $padChar the character used for padding.
 : @param   $length the desired length.
 : @return  $string appended with enough repetitions of $padChar to make its length $length.<br/>
 : The $string is trunctated if it's length is greater than $length.
 :)
declare %private function excel-text:pad-string-to-length 
  ( $string     as xs:string? ,
    $padChar    as xs:string ,
    $length     as xs:integer )  as xs:string {

   fn:substring(fn:string-join (($string, for $i in (1 to $length) return $padChar),'')
                ,1,$length)
 } ;

(:~
 : Returns $toPad appended with enough repetitions of $padChar to make its length $length, the characters are added before the string.
 : 
 : @param   $toPad the value to be padded.
 : @param   $padChar the character used for padding.
 : @param   $length the desired length.
 : @error   XQP0021(errValue) if the length of the $toPad is greater than the desired length.
 : @return  $toPad appended with enough repetitions of $padChar to make its length $length, the characters are added before the string.
 :)
declare function excel-text:pad-integer-to-length
  ( $toPad      as xs:anyAtomicType?,
    $padChar    as xs:string ,
    $length     as xs:integer) as xs:string {

  if ($length < fn:string-length(fn:string($toPad)))
    then fn:error($excel-err:errValue, "Number can not ne padded to the desired length", $length) 
  else
    excel-text:reverse-string(excel-text:pad-string-to-length(
    excel-text:reverse-string(fn:string($toPad)),fn:substring($padChar, 1, 1),$length))  
};

(:~
 : Returns an integer representing the first position of a substring that matches $pattern within $arg. 
 :
 : @param   $arg the string.
 : @param   $pattern the pattern to match.
 : @return  An integer representing the first position of a substring that matches $pattern within $arg.<br />
 : If $arg does not match $pattern, the empty sequence is returned. 
 :)
declare %private function excel-text:index-of-match-first 
  ( $arg        as xs:string? ,
    $pattern    as xs:string )  as xs:integer? {

  if (fn:matches($arg,$pattern))
  then fn:string-length(tokenize($arg, $pattern)[1]) + 1
  else ()
 } ;

(:~
 : Returns an integer representing the first position of a substring that matches $pattern using $flags within $arg.
 :
 : @param   $arg the string.
 : @param   $pattern the pattern to match.
 : @param   $flags options for the interpretation of the regular expression.
 : @return  An integer representing the first position of a substring that matches $pattern using $flags within $arg.<br />
 : If $arg does not match $pattern, the empty sequence is returned. 
 :)
declare %private function excel-text:index-of-match-first 
  ( $arg        as xs:string? ,
    $pattern    as xs:string,
    $flags      as xs:string )  as xs:integer? {

  if (matches($arg,$pattern,$flags))
  then fn:string-length(tokenize($arg, $pattern, $flags)[1]) + 1
  else ()
 } ;

(:~
 : Returns an integer representing the $instance_num position of a substring that matches $pattern within $arg starting from $pos.
 :
 : @param   $arg the string.
 : @param   $pattern the pattern to match.
 : @param   $pos the position to start the search.
 : @param   $instance_num the instance match number.
 : @return  An integer representing the $instance_num position of a substring that matches $pattern within $arg starting from $pos. <br />
 : If $arg does not match $pattern, the empty sequence is returned.
 :)
declare %private function excel-text:index-of-match
  ( $arg            as xs:string? ,
    $pattern        as xs:string,
    $pos            as xs:integer,
    $instance_num   as xs:integer)  as xs:integer? {

  if($instance_num eq 1) 
    then $pos + excel-text:index-of-match-first(fn:substring($arg,$pos),$pattern) - 1
  else 
    let $index := excel-text:index-of-match-first(fn:substring($arg,$pos),$pattern)
  return if(fn:not(fn:exists($index)))
    then ()
  else excel-text:index-of-match($arg, $pattern, $pos + $index, ($instance_num - 1))
 } ;

(:~
 : Splits $text in groups of $length characters starting from right to left. 
 :
 : @param   $text the string.
 : @param   $length the length of the group.
 : @return  Splits $text in groups of $length characters starting from right to left.
 :)
declare %private function excel-text:tokenize-length
  ($text    as xs:string,
   $length  as xs:decimal) as xs:string* {

   if(fn:string-length($text) <= $length) then
    $text
   else
    let $groupsNo := fn:string-length($text) idiv $length 
    let $tmp := fn:string-length($text) mod $length
    return 
      if ($tmp eq 0) then
        for $i in (1 to $groupsNo)
          return fn:substring($text, (1 + ($length*($i - 1))), $length)
      else
        for $i in (0 to $groupsNo)
          return 
            if ($i eq 0) then
              fn:substring($text, 1, $tmp)
            else 
              fn:substring($text, $tmp + ($length*($i - 1)) + 1, $length)
};

(:~
 : Returns the given $text unchanged.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052508361033.aspx
 : @param   $text the time
 : @return  The given $text unchanged.
 :)
declare function excel-text:asc
  ( $text as xs:string)  as xs:string {

  $text
 } ;

(:~
 : Returns the character specified by a certain codepoint.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052090091033.aspx
 : @param   $number the codepoint.
 : @error   XQP0021(errValue) provided $number must be in range [1,255].
 : @return  the character specified by a certain codepoint.
Zorba uses UTF-8 encoding so the actual codepoint range is between [1,1114111]
 :)
 declare function excel-text:char
  ( $number as xs:integer)  as xs:string {

  if( (1 <= $number) and ($number <= 255)) then
    fn:codepoints-to-string($number)
  else 
    fn:error($excel-err:errValue, "Provided number must be in range [1,255]", $number)
 } ;

(:~
 : Returns a codepoint for the first character in a text string.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052090151033.aspx
 : @param   $arg the string.
 : @error   XQP0021(errValue) Provided $arg was empty.
 : @return  A codepoint for the first character in a text string.
 :)
declare function excel-text:code
  ( $arg as xs:string)  as xs:integer {

  if( fn:string-length($arg) > 0 ) then 
    fn:string-to-codepoints(fn:substring($arg, 1, 1))
  else
    fn:error($excel-err:errValue, "Provided text was empty",$arg)
 } ;

(:~
 : Joins two text strings into one text string.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052090151033.aspx
 : @param   $arg1 the first string.
 : @param   $arg2 the second string.
 : @return  Joins two text strings into one text string.
 :)
declare function excel-text:concatenate
  ( $arg1 as xs:anyAtomicType?,
    $arg2 as xs:anyAtomicType?)  as xs:string {

  fn:concat($arg1,$arg2)
 };

(:~
 : Joins several text strings into one text string.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052090151033.aspx
 : @param   $args a sequence of strings.
 : @return  Joins several text strings into one text string.
 :)
declare function excel-text:concatenate
  ( $args as xs:anyAtomicType*)  as xs:string {

  fn:string-join((for $value in $args return xs:string($value)), "")
 } ;

(:~
 : Removes all nonprintable characters from text.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052090141033.aspx
 : @param   $arg the string.
 : @return  Removes all nonprintable characters from text. The CLEAN function was designed.
 : to remove the first 32 nonprinting characters in the 7-bit ASCII code (values 0 through 31) from text. <br/>
 : In the Unicode character set, there are additional nonprinting characters (values 127, 129, 141, 143, 144, and 157). <br/>
 : By itself, the CLEAN function does not remove these additional nonprinting characters.
 :)
declare function excel-text:clean
  ( $arg as xs:string? )  as xs:string? {

  fn:codepoints-to-string( for $codepoint in fn:string-to-codepoints($arg)
  return if ($codepoint < 32) then () else $codepoint)
 } ;

(:~
 : Rounds a number to the specified number of decimals, formats the number in
 : decimal format using a period and commas, and returns the result as text.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052090931033.aspx
 : @param   $number is the number you want to round and convert to text.
 : @param   $decimals is the number of digits to the right of the decimal point.
 : @return  Rounds a number to the specified number of decimals, formats the number in
 : decimal format using a period and commas, and returns the result as text.
 :)
declare function excel-text:fixed
  ( $number     as xs:decimal,
    $decimals   as xs:decimal) as xs:string {

    excel-text:fixed($number,$decimals,fn:false())
};

(:~
 : Rounds a number to the specified number of decimals, formats the number in
 :decimal format using a period and commas, and returns the result as text.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052090931033.aspx
 : @param   $number is the number you want to round and convert to text.
 : @param   $decimals is the number of digits to the right of the decimal point.
 : @param   $no_commas is a logical value that, if TRUE, prevents FIXED from
 :including commas in the returned text.
 : @return  Rounds a number to the specified number of decimals, formats the number in
 :decimal format using a period and commas, and returns the result as text.
 :)
declare function excel-text:fixed
  ( $number     as xs:decimal,
    $decimals   as xs:decimal,
    $no_commas  as xs:boolean) as xs:string {

  let $tmp := excel-math:round($number, $decimals)

  return if($no_commas) then
    fn:string($tmp)
  else
  if(fn:contains(xs:string($tmp), '.')) then
    let $x := fn:tokenize(xs:string($tmp),'[.]')[1]
    let $y := fn:tokenize(xs:string($tmp),'[.]')[2]
    let $x := fn:string-join(excel-text:tokenize-length($x,3), ',')
    return fn:string-join(($x,$y),'.')
   else
    fn:string-join(excel-text:tokenize-length(fn:string($tmp),3), ',')
 } ;

(:~
 : Converts a number to text format and applies a currency symbol. The number of
 :digits to the right of the decimal point is 2.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052090931033.aspx
 : @param   $number is the number.
 : @return  Converts a number to text format and applies a currency symbol. The number of
 :digits to the right of the decimal point is 2.
 :)
declare function excel-text:dollar
  ( $number as xs:decimal)  as xs:string {

  excel-text:dollar($number, 2)
 } ;

(:~
 : Converts a number to text format and applies a currency symbol.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052090931033.aspx
 : @param   $number is the number.
 : @param   $decimals is the number of digits to the right of the decimal point. <br/>
 :If decimals is negative, number is rounded to the left of the decimal point.
 : @return  Converts a number to text format and applies a currency symbol.
 :) 
declare function excel-text:dollar
  ( $number as xs:decimal,
    $decimals as xs:decimal)  as xs:string {

  let $int := fn:tokenize(fn:concat("$", excel-text:fixed(excel-math:abs($number), $decimals)),'\.')[1]
  let $decimal := fn:tokenize(fn:concat("$", excel-text:fixed(excel-math:abs($number), $decimals)),'\.')[2]

  return if( fn:empty($decimal) ) then $int
  else fn:concat($int,'.',excel-text:pad-string-to-length($decimal,"0",$decimals))
 } ;

(:~
 : Compares two text strings and returns TRUE if they are exactly the same,
 :FALSE otherwise. EXACT is case-sensitive but ignores formatting differences.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052090811033.aspx
 : @param   $arg1 the first string.
 : @param   $arg2 the second string.
 : @return  Compares two text strings and returns TRUE if they are exactly the same,
 :FALSE otherwise. EXACT is case-sensitive but ignores formatting differences.
 :)
declare function excel-text:exact
  ($arg1 as xs:string,
   $arg2 as xs:string) as xs:boolean {

   $arg1 eq $arg2
};

(:~
 : Returns the first character in a text string.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052091531033.aspx
 : @param   $arg is the text string that contains the characters you want to extract.
 : @return  The first character in a text string.
 :)
declare function excel-text:left
  ( $arg as xs:string)  as xs:string {
  excel-text:left($arg, 1)
 };

(:~
 : Returns the first character or characters in $text, based on the number of $num_chars you specify.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052091531033.aspx
 : @param   $text is the text string that contains the characters you want to extract.
 : @param   $num_chars specifies the number of characters you want to extract.
 : @return  The first character or characters in $text, based on the number of $num_chars you specify.
 :)
declare function excel-text:left
  ( $text       as xs:string,
    $num_chars  as xs:integer)  as xs:string {

  let $chars := if (fn:string-length($text) < $num_chars) then
                    fn:string-length($text)
                else
                    $num_chars

  return fn:substring($text, 1, $chars)
 } ;

(:~
 : Returns the number of characters in a text string.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052091541033.aspx
 : @param   $arg the string.
 : @return  The number of characters in a text string.
 :)
declare function excel-text:len
  ( $arg as xs:string?)  as xs:integer {

  fn:string-length($arg)
 } ;

(:~
 : Converts all uppercase letters in a text string to lowercase.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052091671033.aspx
 : @param   $arg the string.
 : @return  Converts all uppercase letters in a text string to lowercase.
 :)
declare function excel-text:lower
  ( $arg as xs:string?)  as xs:string? {

  fn:lower-case($arg)
 } ;

(:~
 : Returns a specific number of characters from a text string, starting at
 :the position you specify, based on the number of characters you specify.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052091751033.aspx
 : @param   $text the text string containing the characters you want to extract.
 : @param   $start_num the position of the first character you want to extract
 : in text. The first character in text has start_num 1, and so on.
 : @param   $num_chars the number of characters you want to return from text.
 : @return  A specific number of characters from a text string, starting at
 : the position you specify, based on the number of characters you specify.
 :)
declare function excel-text:mid
  ( $text as xs:string?,
    $start_num as xs:integer,
    $num_chars as xs:integer)  as xs:string? {
  let $len := fn:string-length($text)
  return
  if ($start_num > $len) then
    xs:string('')
  else if ($start_num  < 1) then
    fn:error($excel-err:errValue, "Provided value is less than 1", $start_num)
  else if ($num_chars < 0) then
    fn:error($excel-err:errValue, "Provided value is less than zero", $num_chars)
  else
    fn:substring($text, $start_num, $num_chars)
 };

(:~
 : Replaces part of a text string, based on the number of characters you specify, with a different text string.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052092351033.aspx
 : @param   $old_text is text in which you want to replace some characters.
 : @param   $start_num the position of the character in old_text that you want to replace with new_text.
 : @param   $num_chars the number of characters in old_text that you want REPLACE to replace with new_text.
 : @param   $new_text the text that will replace characters in old_text.
 : @return  Replaces part of a text string, based on the number of characters you specify, with a different text string.
 :)
declare function excel-text:replace
  ( $old_text as xs:string?,
    $start_num as xs:integer,
    $num_chars as xs:integer,
    $new_text as xs:string)  as xs:string {

  fn:concat(fn:substring($old_text,0,$start_num),
            $new_text,
            fn:substring($old_text,$start_num + $num_chars))
 };

(:~
 : Returns the last character in a text string.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052092371033.aspx
 : @param   $arg the text string containing the characters you want to extract.
 : @return  The last character in a text string.
 :)
declare function excel-text:right
  ( $arg as xs:string)  as xs:string {

  excel-text:right($arg, 1)
 } ;

(:~
 : Returns the last character or characters in a text string, based on the number of characters you specify.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052092371033.aspx
 : @param   $text the text string containing the characters you want to extract.
 : @param   $num_chars specifies the number of characters you want RIGHT to extract.
 : @return  The last character or characters in a text string, based on the number of characters you specify.
 :)
declare function excel-text:right
  ( $text as xs:string,
    $num_chars as xs:integer)  as xs:string {

  let $chars := if (fn:string-length($text) < $num_chars) then fn:string-length($text) else $num_chars
  return fn:substring($text, (fn:string-length($text) - $chars + 1), $chars)
 };

(:~
 : Locate one text string within a second text string, and return the number of
 : the starting position of the first text string from the first character of the
 : second text string. <br/> The search starts at position 1, and it is not case sensitive.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052092491033.aspx
 : @param   $find_text text you want to find.
 : @param   $within_text text in which you want to search for $find_text.
 : @error   XQP0021(errValue) the value is not greater than zero or is greater than the length of within_text.
 : @error   XQP0021(errValue) value was not found.
 : @return  Locate one text string within a second text string, and return the number of
 : the starting position of the first text string from the first character of the
 : second text string. <br/> The search starts at position 1, and it is not case sensitive.
 :)
declare function excel-text:search
  ( $find_text      as xs:string,
    $within_text    as xs:string)  as xs:integer? {

    excel-text:search($find_text, $within_text, 1)
};

(:~
 : Locate one text string within a second text string, and return the number of
 : the starting position of the first text string from the first character of the
 : second text string.<br/> The search starts at $start_num, and it is not case sensitive.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052092491033.aspx
 : @param   $find_text text you want to find.
 : @param   $within_text text in which you want to search for $find_text.
 : @param   $start_num the character number in within_text at which you want to start searching.
 : @error   XQP0021(errValue) the value is not greater than zero or is greater than the length of within_text.
 : @error   XQP0021(errValue) value was not found.
 : @return  Locate one text string within a second text string, and return the number of
 : the starting position of the first text string from the first character of the
 : second text string.<br/> The search starts at $start_num, and it is not case sensitive.
 :)
declare function excel-text:search
  ( $find_text      as xs:string,
    $within_text    as xs:string,
    $start_num      as xs:integer)  as xs:integer? {

    if(($start_num < 1) or ($start_num > fn:string-length($within_text))) then
     fn:error($excel-err:errValue, "The value is not greater than zero or is greater than the length of within_text", $start_num)
    else
     let $source := fn:substring($within_text, $start_num)

     return if(fn:exists(excel-text:index-of-match-first($source, $find_text, "i"))) then
         $start_num + excel-text:index-of-match-first($source, $find_text, "i") -1
        else
         fn:error($excel-err:errValue, "Value was not found", $find_text)
};

(:~
 : Locate one text string within a second text string, and return the number of the
 : starting position of the first text string from the first character of the second text string. <br/>
 : The search is case sensitive.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052090891033.aspx
 : @param   $find_text text you want to find.
 : @param   $within_text text in which you want to search for $find_text.
 : @error   XQP0021(errValue) the value is not greater than zero or is greater than the length of within_text.
 : @error   XQP0021(errValue) value was not found.
 : @return  Locate one text string within a second text string, and return the number of the
 : starting position of the first text string from the first character of the second text string. <br/>
 : The search is case sensitive.
 :)
declare function excel-text:find
  ( $find_text      as xs:string,
    $within_text    as xs:string)  as xs:integer? {

    excel-text:find($find_text, $within_text, 1)
};

(:~
 : Locate one text string within a second text string, and return the number of the
 : starting position of the first text string from the first character of the second text string.<br/>
 : The search is case sensitive.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052090891033.aspx
 : @param   $find_text text you want to find.
 : @param   $within_text text in which you want to search for $find_text.
 : @param   $start_num specifies the character at which to start the search.
 : @error   XQP0021(errValue) the value is not greater than zero or is greater than the length of within_text.
 : @error   XQP0021(errValue) value was not found.
 : @return  Locate one text string within a second text string, and return the number of the
 : starting position of the first text string from the first character of the second text string.<br/>
 : The search is case sensitive.
 :)
declare function excel-text:find
  ( $find_text      as xs:string,
    $within_text    as xs:string,
    $start_num      as xs:integer)  as xs:integer? {

    if(($start_num < 1) or ($start_num > fn:string-length($within_text))) then
     fn:error($excel-err:errValue, "The value is not greater than zero or is greater than the length of within_text", $start_num)
    else
     let $source := fn:substring($within_text, $start_num)

     return if(fn:exists(excel-text:index-of-match-first($source, $find_text))) then
         $start_num + excel-text:index-of-match-first($source, $find_text) -1
        else
         fn:error($excel-err:errValue, "Value was not found", $find_text)
};

(:~
 : Substitutes new_text for old_text in a text string.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052092861033.aspx
 : @param   $text the text or the reference to a cell containing text for which you want to substitute characters.
 : @param   $old_text text you want to replace.
 : @param   $new_text text you want to replace old_text with.
 : @param   $instance_num specifies which occurrence of old_text you want to replace with new_text. <br/>
 : Only that instance of old_text is replaced.
 : @return  Substitutes new_text for old_text in a text string. <br/> Use SUBSTITUTE when you
 : want to replace specific text in a text string; use REPLACE when you want
 : to replace any text that occurs in a specific location in a text string.
 :)
declare function excel-text:substitute
  ( $text as xs:string,
    $old_text as xs:string,
    $new_text as xs:string,
    $instance_num as xs:integer?)  as xs:string {

  let $startPos := excel-text:index-of-match($text,$old_text,1,$instance_num)
  return
    if(fn:empty($startPos)) then $text
    else excel-text:replace($text, $startPos, fn:string-length($old_text), $new_text)
 } ;

(:~
 : Substitutes new_text for old_text in a text string. Every occurrence of old_text in text is changed to new_text.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052092861033.aspx
 : @param   $text the text or the reference to a cell containing text for which you want to substitute characters.
 : @param   $old_text text you want to replace.
 : @param   $new_text text you want to replace old_text with.
 : @return  Substitutes new_text for old_text in a text string. Every occurrence of old_text in text is changed to new_text.
 :)
declare function excel-text:substitute
  ( $text as xs:string,
    $old_text as xs:string,
    $new_text as xs:string)  as xs:string? {

  fn:replace($text, $old_text, $new_text)
 } ;

(:~
 : Removes all spaces from text except for single spaces between words.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052093211033.aspx?pid=CH062528321033
 : @param   $text from which you want spaces removed.
 : @return  Removes all spaces from text except for single spaces between words.
 :)
declare function excel-text:trim
  ( $text as xs:string?)  as xs:string? {

  fn:normalize-space($text)
 } ;

(:~
 : Converts text to uppercase.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052093271033.aspx
 : @param   $text text you want converted to uppercase.
 : @return  Converts text to uppercase.
 :)
declare function excel-text:upper
  ( $text as xs:string?)  as xs:string? {

  fn:upper-case($text)
 };

(:~
 : Converts the $value to string.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052093041033.aspx
 : @param   $value the value
 : @return  Converts the $value to string.
 :)
declare function excel-text:t
( $value as xs:anyAtomicType?)  as xs:string {

  if( $value instance of xs:string ) then fn:string($value)
  else fn:string("")
 } ;

(:~
 : Converts a text string that represents a number to a number.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052093291033.aspx
 : @param   $arg the value.
 : @error   XQP0021(errValue) provided value is not a number.
 : @return  Converts a text string that represents a number to a number.
 :)
declare function excel-text:value
( $arg as xs:anyAtomicType?)  as xs:anyAtomicType? {

   typeswitch($arg) 
    case xs:double return $arg
    case xs:decimal return $arg
    case xs:double return $arg
    case xs:float return $arg
    default return
      if($arg castable as xs:integer) then
        xs:integer($arg)
      else
      if($arg castable as xs:decimal) then
         xs:decimal($arg)
      else
      if($arg castable as xs:double) then
         xs:double($arg)
      else
         fn:error($excel-err:errValue, "Provided value is not a number", $arg)
};
