jsoniq version "1.0";

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
 : <p>Base64 encoding and decoding.</p>
 :
 : @author Matthias Brantner
 :
 : @project Zorba/Data Converters/Base 64
 :)
module namespace base64 = "http://zorba.io/modules/base64";

declare namespace zerr = "http://zorba.io/errors";

declare namespace ver = "http://zorba.io/options/versioning";
declare option ver:module-version "1.0";

(:~
 : <p>Decode a base64Binary.</p>
 :
 : <p>The function assumes that the content after decoding is valid
 : UTF-8.</p>
 :
 : @param $base64 The base64Binary item to decode
 : @return the base64-decoded value as string
 : @error zerr:ZOSE0006 if $base64 contains invalid base-64 data.
 :)
declare function base64:decode($base64 as base64Binary)
as string external;

(:~
 : <p>Decode a base64Binary.</p>
 :
 : <p>The function assumes that the content after decoding has
 : the given encoding.</p>
 :
 : @param $base64 The base64Binary item to decode
 : @param $encoding The encoding of the string after base64-decoding it.
 : The encoding parameter is case insensitive.
 :
 : @return the base64-decoded value as a string
 :
 : @error zerr:ZXQP0006 if the given encoding is invalid or not supported.
 : "ASCII" and "UTF-8" are guaranteed to be supported; other encodings
 : may be supported depending on the installation.
 : @error zerr:ZOSE0006 if $base64 contains invalid base-64 data.
 :)
declare function base64:decode(
  $base64 as base64Binary,
  $encoding as string)
as string external;

(:~
 : <p>Encode a string as base64Binary.</p>
 :
 : @param $string The item whose string-value should be encoded
 : @return the base64-encoded string-value of the item parameter
 :)
declare function base64:encode($string as string) as base64Binary external;
