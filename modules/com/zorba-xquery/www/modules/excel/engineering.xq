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
 :  This is a library module offering the same set of functions
 : defined by Microsoft Excel, under Engineering Functions.
 :
 : @author Sorin Nasoi
 :
 : @see <a href="http://office.microsoft.com/en-us/excel/CH062528241033.aspx"
 : target="_blank">Excel Documentation: Engineering Functions</a>
 :
 :)
module namespace  excel-engineering = "http://www.zorba-xquery.com/modules/excel/engineering" ;

(:~
 : Use excel-err module functions for throwing errors.
 :)
import module namespace excel-err="http://www.zorba-xquery.com/modules/excel/errors";

(:~
 : Import excel-text module functions.
 :)
import module namespace excel-text="http://www.zorba-xquery.com/modules/excel/text";

(:~
 : Import excel-math module functions.
 :)
import module namespace excel-math="http://www.zorba-xquery.com/modules/excel/math";

(:~
 : Tests if a string is a hexadecimal representation of a number.
 :
 : @param   $arg the string.
 : @return  True if the passed $arg is a hexadecimal number, false otherwise.
 :)
declare %private function excel-engineering:is-hex
    ($arg as xs:string) as xs:boolean {

  let $tmp := fn:upper-case($arg)
  let $hexCP:=(48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 65, 66, 67, 68, 69, 70)

  return if (fn:exists(excel-text:value-except(fn:string-to-codepoints($tmp),($hexCP)))) then fn:false()
  else fn:true()
};

(:~
 : Tests if a string is a octal representation of a number. 
 :
 : @param   $arg the string
 : @return  True if the passed $arg is a octal number, false otherwise.
 :)
declare %private function excel-engineering:is-oct
    ($arg as xs:string) as xs:boolean {

  let $octCP:=(48, 49, 50, 51, 52, 53, 54, 55)

  return if (fn:exists(excel-text:value-except(fn:string-to-codepoints($arg),($octCP)))) then fn:false()
  else fn:true()
};

(:~
 : Tests if a string is a binary representation of a number.
 :
 : @param   $arg the string.
 : @return  True if the passed $arg is a binary number, false otherwise. 
 :)
declare %private function excel-engineering:is-bin
    ($arg as xs:string) as xs:boolean {

  let $binCP:=(48, 49)

  return if (fn:exists(excel-text:value-except(fn:string-to-codepoints($arg),($binCP)))) then fn:false()
  else fn:true()
};

(:~
 : Returns a binary representation of a number.
 :
 : @param   $number the number.
 : @error   XQP0021(errValue) if provided value for $number is not numeric.
 : @return  A binary representation of a number.
 :)
declare %private function excel-engineering:dec2hexUtil
    ($number as xs:anyAtomicType) as xs:string {

    if (fn:not(excel-math:is-a-number($number))) then
       fn:error($excel-err:errValue, "Provided value for 'number' is not numeric", $number)
    else
      let $tmpNumber := xs:integer($number) 

    let $hexDigits:=('0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F')
    return
    if($number < 16) then
        $hexDigits[$number + 1]
    else
        fn:concat(excel-engineering:dec2hex($number idiv 16), excel-engineering:dec2hex($number mod 16))
};

(:~
 : Returns an octal representation of a number.
 :
 : @param   $number the number.
 : @error   XQP0021(errValue) if provided value for $number is not numeric.
 : @return  An octal representation of a number.
 :)
declare %private function excel-engineering:dec2octUtil
    ($number as xs:anyAtomicType) as xs:string {

    if (fn:not(excel-math:is-a-number($number))) then
       fn:error($excel-err:errValue, "Provided value for 'number' is not numeric", $number)
    else
      let $tmpNumber := xs:integer($number) 

    let $octDigits:=('0', '1', '2', '3', '4', '5', '6', '7')
    return
    if($number < 8) then
        $octDigits[$number + 1]
    else
        fn:concat(excel-engineering:dec2oct($number idiv 8), excel-engineering:dec2oct($number mod 8))
};

(:~
 : Returns a binary representation of a number.
 :
 : @param   $arg the number.
 : @error   XQP0021(errValue) if provided value for $number is not numeric.
 : @return  A binary representation of a number.
 :)
declare %private function excel-engineering:dec2binUtil
    ($arg as xs:anyAtomicType) as xs:string {

    if (fn:not(excel-math:is-a-number($arg))) then
       fn:error($excel-err:errValue, "Provided value for 'number' is not numeric", $arg)
    else
      let $tmpNumber := xs:integer($arg) 

    let $binDigits:=('0', '1')
      return
      if($tmpNumber < 2) then
          $binDigits[$tmpNumber + 1]
      else
          fn:concat(excel-engineering:dec2binUtil($tmpNumber idiv 2), excel-engineering:dec2binUtil($tmpNumber mod 2))
};

(:~
 : Returns a decimal representation of a number given it's hexadecimal representation.
 :
 : @param   $arg the number.
 : @error   XQP0021(errValue) if provided $arg is not a hexadecimal representation of a number.
 : @return  A decimal representation of a number given it's hexadecimal representation.
 :)
declare %private function excel-engineering:hex2decUtil
    ($arg as xs:string) as xs:integer* {

    let $number := fn:upper-case($arg)
    let $hexCP := (48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 65, 66, 67, 68, 69, 70)

    return if (fn:not(excel-engineering:is-hex($number))) then
      fn:error($excel-err:errValue, "Provided string is not a hexadecimal representation of a number", $number)
    else
      let $tmp := fn:reverse(fn:string-to-codepoints($number))
      return  fn:sum(for $val in (0 to fn:string-length($number)-1)
        return (fn:index-of($hexCP, $tmp[$val + 1]) - 1) * excel-math:power(16, $val))
};

(:~
 : Returns a decimal representation of a number given it's octal representation.
 :
 : @param   $arg the number.
 : @error   XQP0021(errValue) if provided $arg is not an octal representation of a number.
 : @return  A decimal representation of a number given it's octal representation.
 :)
declare %private function excel-engineering:oct2decUtil
    ($arg as xs:string) as xs:integer {

    if (fn:not(excel-engineering:is-oct($arg))) then
      fn:error($excel-err:errValue, "Provided string is not an octal representation of a number", $arg)
    else
      let $tmp := fn:reverse(fn:string-to-codepoints($arg))
      return fn:sum(for $val in (0 to fn:string-length($arg)-1)
        return xs:integer(fn:codepoints-to-string($tmp[$val + 1])) * excel-math:power(8, $val))
};

(:~
 : Returns a decimal representation of a number given it's binary representation.
 :
 : @param   $arg the number.
 : @error   XQP0021(errValue) if provided $arg is not an binary representation of a number.
 : @return  A decimal representation of a number given it's binary representation.
 :)
declare %private function excel-engineering:bin2decUtil
    ($arg as xs:string) as xs:integer {

    if (fn:not(excel-engineering:is-bin($arg))) then
      fn:error($excel-err:errValue, "Provided string is not a binary representation of a number", $arg)
    else
      let $tmp := fn:reverse(fn:string-to-codepoints($arg))
      return fn:sum(for $val in (0 to fn:string-length($arg)-1)
        return xs:integer(fn:codepoints-to-string($tmp[$val + 1])) * excel-math:power(2, $val))
};

(:~
 : Converts a decimal number to hexadecimal.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052090541033.aspx?pid=CH062528241033
 : @param   $arg the number.
 : @error   XQP0021(errValue) if provided value for $arg is not numeric.
 : @error   XQP0021(errNum) if provided value for $arg is smaller than -549755813888 or bigger than 549755813887
 : @return  A hexadecimal representation of a number given it's decimal representation.
 :)
declare function excel-engineering:dec2hex
    ($arg as xs:anyAtomicType) as xs:string {

    if (fn:not(excel-math:is-a-number($arg))) then
       fn:error($excel-err:errValue, "Provided value for 'number' is not numeric", $arg)
    else
      let $tmpNumber := xs:integer($arg) 

      return
      if(($tmpNumber < -549755813888) or ($tmpNumber > 549755813887)) then
        fn:error($excel-err:errNum, "Provided value for 'number' is smaller than -549755813888 or bigger than 549755813887", $tmpNumber)
      else if($tmpNumber < 0) then
          let $tmp := 1 + excel-engineering:hex2decUtil(fn:translate(
                      excel-text:pad-integer-to-length(excel-engineering:dec2hexUtil(fn:abs($tmpNumber)), "0", 10),
                     "0123456789ABCDEF",
                     "FEDCBA9876543210"))
          return excel-engineering:dec2hexUtil($tmp)
        else
          excel-engineering:dec2hexUtil($tmpNumber)
};

(:~
 : Converts a decimal number to hexadecimal.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052090541033.aspx?pid=CH062528241033
 : @param   $arg the number.
 : @param   $places is the number of characters to use. Places is useful for padding the return value with leading 0s (zeros).
 : @error   XQP0021(errValue) if provided value for $arg is not numeric.
 : @error   XQP0021(errValue) if provided value for $places is not numeric.
 : @error   XQP0021(errNum) if provided value for $places is zero or negative.
 : @error   XQP0021(errNum) if provided value for $places is too small.
 : @error   XQP0021(errNum) if provided value for $arg is smaller than -549755813888 or bigger than 549755813887.
 : @return  A hexadecimal representation of a number given it's decimal representation.
 :)
declare function excel-engineering:dec2hex
    ($arg as xs:anyAtomicType,
     $places as xs:anyAtomicType) as xs:string {

    if (fn:not(excel-math:is-a-number($arg))) then
       fn:error($excel-err:errValue, "Provided value for 'number' is not numeric", $arg)
    else if(fn:not(excel-math:is-a-number($places))) then
       fn:error($excel-err:errValue, "Provided value for 'places' is not numeric", $places) 
    else
      let $tmpNumber := xs:integer($arg) 
      let $tmpPlaces := xs:integer($places)

      return
        if(($tmpNumber < -549755813888) or ($tmpNumber > 549755813887)) then
        fn:error($excel-err:errNum, "Provided value for 'number' is smaller than -549755813888 or bigger than 549755813887", $tmpNumber) 
        else if($tmpPlaces < 1) then
          fn:error($excel-err:errNum, "Provided value for 'places' is zero or negative", $tmpPlaces)
        else
          if($tmpNumber < 0) then
            let $tmp := 1 + excel-engineering:hex2decUtil(fn:translate(
                        excel-text:pad-integer-to-length(excel-engineering:dec2hexUtil(fn:abs($tmpNumber)), "0", 10),
                       "0123456789ABCDEF",
                       "FEDCBA9876543210"))
            return excel-engineering:dec2hexUtil($tmp)
          else
            let $tmp := excel-engineering:dec2hexUtil($tmpNumber)
            return if($tmpPlaces < fn:string-length($tmp)) then
              fn:error($excel-err:errNum, "Provided value for 'places' too small", $tmpPlaces)
            else
              excel-text:pad-integer-to-length($tmp, "0", $tmpPlaces)
};

(:~
 : Converts a decimal number to octal.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052090551033.aspx?pid=CH062528241033
 : @param   $arg the number.
 : @error   XQP0021(errValue) if provided value for $arg is not numeric.
 : @error   XQP0021(errNum) if provided value for $arg is smaller than -536870912 or bigger than 536870911.
 : @return  An octal representation of a number given it's decimal representation.
 :)
declare function excel-engineering:dec2oct
    ($arg as xs:anyAtomicType) as xs:string {

    if (fn:not(excel-math:is-a-number($arg))) then
       fn:error($excel-err:errValue, "Provided value for 'number' is not numeric", $arg)
    else
      let $tmpNumber := xs:integer($arg) 

      return
      if(($tmpNumber < -536870912) or ($tmpNumber > 536870911)) then
        fn:error($excel-err:errNum, "Provided value for 'number' is smaller than -536870912 or bigger than 536870911", $tmpNumber)
      else if($tmpNumber < 0) then
          let $tmp := 1 + excel-engineering:oct2decUtil(fn:translate(
                      excel-text:pad-integer-to-length(excel-engineering:dec2octUtil(fn:abs($tmpNumber)), "0", 10), 
                     "01234567",
                     "76543210"))
          return excel-engineering:dec2octUtil($tmp)
        else
          excel-engineering:dec2octUtil($tmpNumber)
};

(:~
 : Converts a decimal number to octal.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052090551033.aspx?pid=CH062528241033
 : @param   $arg the number
 : @param   $places is the number of characters to use. Places is useful for padding the return value with leading 0s (zeros).
 : @error   XQP0021(errValue) if provided value for $arg is not numeric
 : @error   XQP0021(errValue) if provided value for $places is not numeric
 : @error   XQP0021(errNum) if provided value for $places is zero or negative
 : @error   XQP0021(errNum) if provided value for $places is too small
 : @error   XQP0021(errNum) if provided value for $arg is smaller than -536870912 or bigger than 536870911
 : @return  An octal representation of a number given it's decimal representation.
 :)
declare function excel-engineering:dec2oct
    ($arg as xs:anyAtomicType,
     $places as xs:anyAtomicType) as xs:string {

    if (fn:not(excel-math:is-a-number($arg))) then
       fn:error($excel-err:errValue, "Provided value for 'number' is not numeric", $arg)
    else if(fn:not(excel-math:is-a-number($places))) then
       fn:error($excel-err:errValue, "Provided value for 'places' is not numeric", $places)
    else
      let $tmpNumber := xs:integer($arg) 
      let $tmpPlaces := xs:integer($places)

      return
        if(($tmpNumber < -536870912) or ($tmpNumber > 536870911)) then
          fn:error($excel-err:errNum, "Provided value for 'number' is smaller than -536870912 or bigger than 536870911", $tmpNumber)
        else if($tmpPlaces < 1) then
          fn:error($excel-err:errNum, "Provided value for 'places' is zero or negative", $tmpPlaces)
        else
          if($tmpNumber < 0) then
            let $tmp := 1 + excel-engineering:oct2decUtil(fn:translate(
                        excel-text:pad-integer-to-length(excel-engineering:dec2octUtil(fn:abs($tmpNumber)), "0", 10),
                        "01234567",
                        "76543210"))
            return excel-engineering:dec2octUtil($tmp)
          else
            let $tmp := excel-engineering:dec2octUtil($tmpNumber)
            return if($tmpPlaces < fn:string-length($tmp)) then
              fn:error($excel-err:errNum, "Provided value for 'places' too small", $tmpPlaces)
            else
              excel-text:pad-integer-to-length($tmp, "0", $tmpPlaces)
};

(:~
 : Converts a decimal number to binary.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052090531033.aspx?pid=CH062528241033
 : @param   $arg the number.
 : @error   XQP0021(errValue) if provided value for $arg is not numeric.
 : @error   XQP0021(errNum) if provided value for $arg is smaller than -512 or bigger than 511.
 : @return  A binary representation of a number given it's decimal representation.
 :)
declare function excel-engineering:dec2bin
    ($arg as xs:anyAtomicType) as xs:string {

    if (fn:not(excel-math:is-a-number($arg))) then
       fn:error($excel-err:errValue, "Provided value for 'number' is not numeric", $arg)
    else
      let $tmpNumber := xs:integer($arg) 

      return
      if(($tmpNumber < -512) or ($tmpNumber > 511)) then
        fn:error($excel-err:errNum, "Provided value for 'number' is smaller than -512 or bigger than 511", $tmpNumber)
      else
        if($tmpNumber < 0) then
          let $tmp := 1 + excel-engineering:bin2decUtil(fn:translate(
                      excel-text:pad-integer-to-length(excel-engineering:dec2binUtil(fn:abs($tmpNumber)), "0", 10),
                     "01",
                     "10"))
          return excel-engineering:dec2binUtil($tmp)
        else
          excel-engineering:dec2binUtil($tmpNumber)
};

(:~
 : Converts a decimal number to binary.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052090531033.aspx?pid=CH062528241033
 : @param   $arg the number.
 : @param   $places is the number of characters to use. Places is useful for padding the return value with leading 0s (zeros).
 : @error   XQP0021(errValue) if provided value for $arg is not numeric.
 : @error   XQP0021(errValue) if provided value for $places is not numeric.
 : @error   XQP0021(errNum) if provided value for $places is zero or negative.
 : @error   XQP0021(errNum) if provided value for $places is too small.
 : @error   XQP0021(errNum) if provided value for $arg is smaller than -512 or bigger than 511.
 : @return  A binary representation of a number given it's decimal representation.
 :)
declare function excel-engineering:dec2bin
    ($arg as xs:anyAtomicType,
     $places as xs:anyAtomicType) as xs:string {

    if (fn:not(excel-math:is-a-number($arg))) then
       fn:error($excel-err:errValue, "Provided value for 'number' is not numeric", $arg)
    else if(fn:not(excel-math:is-a-number($places))) then
       fn:error($excel-err:errValue, "Provided value for 'places' is not numeric", $places)
    else
      let $tmpNumber := xs:integer($arg) 
      let $tmpPlaces := xs:integer($places)

      return
      if(($tmpNumber < -512) or ($tmpNumber > 511)) then
        fn:error($excel-err:errNum, "Provided value for 'number' is smaller than -512 or bigger than 511", $tmpNumber)
      else if($tmpPlaces < 1) then
        fn:error($excel-err:errNum, "Provided value for 'places' is zero or negative", $tmpPlaces)
      else
        if($tmpNumber < 0) then
          let $tmp := 1 + excel-engineering:bin2decUtil(fn:translate(
                      excel-text:pad-integer-to-length(excel-engineering:dec2binUtil(fn:abs($tmpNumber)), "0", 10),
                     "01",
                     "10"))
          return excel-engineering:dec2binUtil($tmp)
        else
          let $tmp := excel-engineering:dec2binUtil($tmpNumber)
          return if($tmpPlaces < fn:string-length($tmp)) then
            fn:error($excel-err:errNum, "Provided value for 'places' too small", $tmpPlaces)
          else
            excel-text:pad-integer-to-length($tmp, "0", $tmpPlaces)
};

(:~
 : Converts an octal number to binary.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052092001033.aspx?pid=CH062528241033
 : @param   $arg the number.
 : @error   XQP0021(errValue) if provided value for $arg is not an octal representation of a number.
 : @error   XQP0021(errValue) if provided value for $arg contains more than 10 characters.
 : @return  A binary representation of a number given it's octal representation.
 :)
declare function excel-engineering:oct2bin
    ($arg as xs:anyAtomicType) as xs:string {

  excel-engineering:dec2bin(excel-engineering:oct2dec($arg))
};

(:~
 : Converts an octal number to binary.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052092001033.aspx?pid=CH062528241033
 : @param   $arg the number.
 : @param   $places is the number of characters to use. Places is useful for padding the return value with leading 0s (zeros).
 : @error   XQP0021(errValue) if provided value for $arg is not an octal representation of a number.
 : @error   XQP0021(errValue) if provided value for $arg contains more than 10 characters.
 : @error   XQP0021(errValue) if provided value for $places is not numeric.
 : @error   XQP0021(errNum) if provided value for $places is zero or negative.
 : @error   XQP0021(errNum) if provided value for $places is too small.
 : @return  A binary representation of a number given it's octal representation.
 :)
declare function excel-engineering:oct2bin
    ($arg as xs:anyAtomicType,
     $places as xs:anyAtomicType) as xs:string {

  excel-engineering:dec2bin(excel-engineering:oct2dec($arg),$places)
};

(:~
 : Converts an octal number to decimal.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052092011033.aspx?pid=CH062528241033
 : @param   $arg the number.
 : @error   XQP0021(errValue) if provided value for $arg is not an octal representation of a number.
 : @error   XQP0021(errValue) if provided value for $arg contains more than 10 characters.
 : @return  A decimal representation of a number given it's octal representation.
 :)
declare function excel-engineering:oct2dec
    ($arg as xs:anyAtomicType) as xs:integer {

  let $number := fn:string($arg)
  return if (fn:not(excel-engineering:is-oct($number))) then
    fn:error($excel-err:errValue, "Provided string is not an octal representation of a number", $number)
  else if(fn:string-length($number) > 10) then 
    fn:error($excel-err:errValue, "Number contains more than 10 characters", $number)
  else
    if((fn:string-length($number) eq 10) and
              fn:substring($number, 1, 1) eq "7") then
      -(1 + excel-engineering:oct2decUtil(fn:translate($number,"01234567", "76543210")))
    else
      excel-engineering:oct2decUtil($number)
};

(:~
 : Converts a binary number to decimal.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052090021033.aspx?pid=CH062528241033
 : @param   $arg the number.
 : @error   XQP0021(errValue) if provided value for $arg is not a binary representation of a number.
 : @error   XQP0021(errValue) if provided value for $arg contains more than 10 characters.
 : @return  A decimal representation of a number given it's binary representation.
 :)
declare function excel-engineering:bin2dec
    ($arg as xs:anyAtomicType) as xs:integer {

  let $number := fn:string($arg)
  return if (fn:not(excel-engineering:is-bin($number))) then
    fn:error($excel-err:errValue, "Provided string is not a binary representation of a number", $number)
  else if(fn:string-length($number) > 10) then
    fn:error($excel-err:errValue, "Number contains more than 10 characters", $number)
  else
    if((fn:string-length($number) eq 10) and
       (fn:substring($number, 1, 1) eq "1")) then
      -(1 + excel-engineering:bin2decUtil(fn:translate($number,"01", "10")))
    else
      excel-engineering:bin2decUtil ($number)
};

(:~
 : Converts an octal number to hexadecimal.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052092021033.aspx?pid=CH062528241033
 : @param   $arg the number.
 : @error   XQP0021(errValue) if provided value for $arg is not an octal representation of a number.
 : @error   XQP0021(errValue) if provided value for $arg contains more than 10 characters.
 : @return  A hexadecimal representation of a number given it's octal representation.
 :)
declare function excel-engineering:oct2hex
    ($arg as xs:anyAtomicType) as xs:string {

  excel-engineering:dec2hex(excel-engineering:oct2dec($arg))
};

(:~
 : Converts an octal number to hexadecimal.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052092021033.aspx?pid=CH062528241033
 : @param   $arg the number.
 : @param   $places is the number of characters to use. Places is useful for padding the return value with leading 0s (zeros).
 : @error   XQP0021(errValue) if provided value for $arg is not an octal representation of a number.
 : @error   XQP0021(errValue) if provided value for $arg contains more than 10 characters.
 : @error   XQP0021(errValue) if provided value for $places is not numeric.
 : @error   XQP0021(errNum) if provided value for $places is zero or negative.
 : @error   XQP0021(errNum) if provided value for $places is too small.
 : @return  A hexadecimal representation of a number given it's octal representation.
 :)
declare function excel-engineering:oct2hex
    ($arg as xs:anyAtomicType,
     $places as xs:anyAtomicType) as xs:string {

  excel-engineering:dec2hex(excel-engineering:oct2dec($arg),$places)
};

(:~
 : Converts a hexadecimal number to binary.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052091101033.aspx?pid=CH062528241033
 : @param   $arg the number.
 : @error   XQP0021(errValue) if provided value for $arg is not a hexadecimal representation of a number.
 : @error   XQP0021(errValue) if provided value for $arg contains more than 10 characters.
 : @return  A binary representation of a number given it's hexadecimal representation.
 :)
declare function excel-engineering:hex2bin
    ($arg as xs:anyAtomicType) as xs:string {

  excel-engineering:dec2bin(excel-engineering:hex2dec($arg))
};

(:~
 : Converts a hexadecimal number to binary.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052091101033.aspx?pid=CH062528241033
 : @param   $arg the number.
 : @param   $places is the number of characters to use. Places is useful for padding the return value with leading 0s (zeros).
 : @error   XQP0021(errValue) if provided value for $arg is not a hexadecimal representation of a number.
 : @error   XQP0021(errValue) if provided value for $arg contains more than 10 characters.
 : @error   XQP0021(errValue) if provided value for $places is not numeric.
 : @error   XQP0021(errNum) if provided value for $places is zero or negative.
 : @error   XQP0021(errNum) if provided value for $places is too small.
 : @return  A binary representation of a number given it's hexadecimal representation.
 :)
declare function excel-engineering:hex2bin
    ($arg as xs:anyAtomicType,
     $places as xs:anyAtomicType) as xs:string {

  excel-engineering:dec2bin(excel-engineering:hex2dec($arg),$places)
};

(:~
 : Converts a hexadecimal number to octal.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052091121033.aspx?pid=CH062528241033
 : @param   $arg the number.
 : @error   XQP0021(errValue) if provided value for $arg is not a hexadecimal representation of a number.
 : @error   XQP0021(errValue) if provided value for $arg contains more than 10 characters.
 : @return  A octal representation of a number given it's hexadecimal representation.
 :)
declare function excel-engineering:hex2oct
    ($arg as xs:anyAtomicType) as xs:string {

  excel-engineering:dec2oct(excel-engineering:hex2dec($arg))
};

(:~
 : Converts a hexadecimal number to octal.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052091121033.aspx?pid=CH062528241033
 : @param   $arg the number.
 : @param   $places is the number of characters to use. Places is useful for padding the return value with leading 0s (zeros).
 : @error   XQP0021(errValue) if provided value for $arg is not a hexadecimal representation of a number.
 : @error   XQP0021(errValue) if provided value for $arg contains more than 10 characters.
 : @error   XQP0021(errValue) if provided value for $places is not numeric.
 : @error   XQP0021(errNum) if provided value for $places is zero or negative.
 : @error   XQP0021(errNum) if provided value for $places is too small.
 : @return  A octal representation of a number given it's hexadecimal representation.
 :)
declare function excel-engineering:hex2oct
    ($arg as xs:anyAtomicType,
     $places as xs:anyAtomicType) as xs:string {

  excel-engineering:dec2oct(excel-engineering:hex2dec($arg),$places)
};

(:~
 : Converts a hexadecimal number to decimal.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052091111033.aspx?pid=CH062528241033
 : @param   $arg the number.
 : @error   XQP0021(errValue) if provided value for $arg is not a hexadecimal representation of a number.
 : @error   XQP0021(errValue) if provided value for $arg contains more than 10 characters.
 : @return  A decimal representation of a number given it's hexadecimal representation.
 :)
declare function excel-engineering:hex2dec
    ($arg as xs:string) as xs:integer {

  let $number := fn:upper-case($arg)
  return if (fn:not(excel-engineering:is-hex($number))) then
    fn:error($excel-err:errValue, "Provided string is not a hexadecimal representation of a number", $arg)
  else if(fn:string-length($number) > 10) then 
    fn:error($excel-err:errValue, "Number contains more than 10 characters", $arg)
  else   
    if((fn:string-length($number) eq 10) and
        fn:substring($number, 1, 1) eq "F") then
      -(1 + excel-engineering:hex2decUtil(fn:translate($number,"0123456789ABCDEF", "FEDCBA9876543210")))
    else
      excel-engineering:hex2decUtil($number)
};

(:~
 : Converts a binary number to octal.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052090041033.aspx?pid=CH062528241033
 : @param   $arg the number.
 : @error   XQP0021(errValue) if provided value for $arg is not a binary representation of a number.
 : @error   XQP0021(errValue) if provided value for $arg contains more than 10 characters.
 : @return  A octal representation of a number given it's binary representation.
 :)
declare function excel-engineering:bin2oct
    ($arg as xs:anyAtomicType) as xs:string {

  excel-engineering:dec2oct(excel-engineering:bin2dec($arg))
};

(:~
 : Converts a binary number to octal.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052090041033.aspx?pid=CH062528241033
 : @param   $arg the number.
 : @param   $places is the number of characters to use. Places is useful for padding the return value with leading 0s (zeros).
 : @error   XQP0021(errValue) if provided value for $arg is not a binary representation of a number.
 : @error   XQP0021(errValue) if provided value for $arg contains more than 10 characters.
 : @error   XQP0021(errValue) if provided value for $places is not numeric.
 : @error   XQP0021(errNum) if provided value for $places is zero or negative.
 : @error   XQP0021(errNum) if provided value for $places is too small.
 : @return  A octal representation of a number given it's binary representation.
 :)
declare function excel-engineering:bin2oct
    ($arg as xs:anyAtomicType,
     $places as xs:anyAtomicType) as xs:string {

  excel-engineering:dec2oct(excel-engineering:bin2dec($arg),$places)
};

(:~
 : Converts a binary number to hexadecimal.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052090031033.aspx?pid=CH062528241033
 : @param   $arg the number.
 : @error   XQP0021(errValue) if provided value for $arg is not a binary representation of a number.
 : @error   XQP0021(errValue) if provided value for $arg contains more than 10 characters.
 : @return  A hexadecimal representation of a number given it's binary representation.
 :)
declare function excel-engineering:bin2hex
    ($arg as xs:anyAtomicType) as xs:string {

  excel-engineering:dec2hex(excel-engineering:bin2dec($arg))
};

(:~
 : Converts a binary number to hexadecimal.
 :
 : @see     http://office.microsoft.com/en-us/excel/HP052090031033.aspx?pid=CH062528241033
 : @param   $arg the number.
 : @param   $places is the number of characters to use. Places is useful for padding the return value with leading 0s (zeros).
 : @error   XQP0021(errValue) if provided value for $arg is not a binary representation of a number.
 : @error   XQP0021(errValue) if provided value for $arg contains more than 10 characters.
 : @error   XQP0021(errValue) if provided value for $places is not numeric.
 : @error   XQP0021(errNum) if provided value for $places is zero or negative.
 : @error   XQP0021(errNum) if provided value for $places is too small.
 : @return  A hexadecimal representation of a number given it's binary representation.
 :)
declare function excel-engineering:bin2hex
    ($arg as xs:anyAtomicType,
     $places as xs:anyAtomicType) as xs:string {

  excel-engineering:dec2hex(excel-engineering:bin2dec($arg),$places)
};
