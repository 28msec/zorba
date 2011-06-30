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
 : @project data processing/data convertors
 :)
module namespace base64 = "http://www.zorba-xquery.com/modules/converters/base64";


(:~
 : Decode a xs:base64Binary.
 :
 : @param $base64 The xs:base64Binary item to decode
 : @return the decoded xs:base64Binary item as string
 :)
declare function base64:decode($base64 as xs:base64Binary) as xs:string external;

(:~
 : Encode a xs:string as xs:base64Binary.
 :
 : @param $string The item whose string-value should be encoded
 : @return the base64 encoded string-value of the item parameter
 :)
declare function base64:encode($string as xs:string) as xs:base64Binary external;
