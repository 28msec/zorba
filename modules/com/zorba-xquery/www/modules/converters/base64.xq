xquery version "1.0";

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
 : Base64 encoding and decoding
 :
 : @author Matthias Brantner
 :
 : @project data processing/data converters
 :)
module namespace base64 = "http://www.zorba-xquery.com/modules/converters/base64";

declare namespace zerr = "http://www.zorba-xquery.com/errors";

declare namespace ver = "http://www.zorba-xquery.com/options/versioning";
declare option ver:module-version "2.0";

(:~
 : Decode a xs:base64Binary.
 :
 : The function assumes that the content after decoding is valid
 : UTF-8.
 :
 : @param $base64 The xs:base64Binary item to decode
 : @return the base64 decoded value as string
 :)
declare function base64:decode($base64 as xs:base64Binary)
as xs:string external;

(:~
 : Decode a xs:base64Binary.
 :
 : The function assumes that the content after decoding has
 : the given encoding.
 :
 : @param $base64 The xs:base64Binary item to decode
 : @param $encoding The encoding of the string after base64 decoding it.
 :
 : @return the base64 decoded value as string
 :
 : @error zerr:ZXQP0006 if the given encoding is invalid or not supported.
 :)
declare function base64:decode(
  $base64 as xs:base64Binary,
  $encoding as xs:string)
as xs:string external;

(:~
 : Encode a xs:string as xs:base64Binary.
 :
 : @param $string The item whose string-value should be encoded
 : @return the base64 encoded string-value of the item parameter
 :)
declare function base64:encode($string as xs:string) as xs:base64Binary external;
