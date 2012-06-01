xquery version "1.0";

(:
 : Copyright 2006-2012 The FLWOR Foundation.
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
 : This module provides string related functions.
 :
 : @author Matthias Brantner
 : @project XDM/atomic
 :
 :)
module namespace uri = "http://www.zorba-xquery.com/modules/uri";

declare namespace zerr = "http://www.zorba-xquery.com/errors";

declare namespace ver = "http://www.zorba-xquery.com/options/versioning";
declare option ver:module-version "1.0";

(:~
 : Percent-decodes (aka URL decoding) the given string.
 :
 : All percent encoded octets will be translated into their
 : decoded UTF-8 representation.
 :
 : Please note that the percent encoding guarantees that a string
 : consists of ASCII characters only. Passing a string that contains
 : non-ASCII characters results in undefined behavior.
 :
 : @param $s the string to decode
 :
 : @return the percent decoded string
 :)
declare function uri:decode($u as xs:string) as xs:string
{
  uri:decode($u, fn:false())
};

(:~
 : Percent-decodes (aka URL decoding) the given string.
 :
 : All percent encoded octets will be translated into their
 : decoded UTF-8 representation.
 :
 : If $decode-plus is specified all occurrences of the char '+'
 : will be replaced with a space ' ' before the percent decoding
 : happens.
 :
 : Please note that the percent encoding guarantees that a string
 : consists of ASCII characters only. Passing a string that contains
 : non-ASCII characters results in undefined behavior.
 :
 : @param $s the string to decode
 : @param $decode-plus whether '+' chars will be replaced with spaces
 :
 : @return the percent decoded string
 :)
declare function uri:decode(
  $u as xs:string,
  $decode-plus as xs:boolean) as xs:string
{
  uri:decode($u, $decode-plus, "UTF-8")
};

(:~
 : Percent-decodes (aka URL decoding) the given string.
 :
 : All percent encoded octets will be translated into their
 : decoded UTF-8 representation.
 :
 : If $decode-plus is specified all occurrences of the char '+'
 : will be replaced with a space ' ' before the percent decoding
 : happens.
 :
 : The $charset parameter specifies the source charset after precent
 : decoding. It is used to convert the decoded string into UTF-8.
 :
 : Please note that the percent encoding guarantees that a string
 : consists of ASCII characters only. Passing a string that contains
 : non-ASCII characters results in undefined behavior.
 :
 : @param $s the string to decode
 : @param $decode-plus whether '+' chars will be replaced with spaces
 : @param $charset the source charset of the string after percent decoding
 :
 : @return the percent decoded string
 :
 : @error zerr:ZXQP0006 if the given charset is unknown or not supported
 :
 : @error zerr:ZOSE0006 if there is an error transcoding the string
 :)
declare function uri:decode(
  $s as xs:string,
  $decode-plus as xs:boolean,
  $charset as xs:string) as xs:string external;
