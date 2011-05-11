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
 : This is the description of the hash module
 :
 : @author Gabriel Petrovay, Markus Pilman
 :
 :)
module namespace hash = "http://www.zorba-xquery.com/modules/security/hash";

(:~
 : Computes the MD5 hash of the text content of the node provided as parameter.
 :
 : @param $value The node whose text content will be hashed.
 : @return The MD5 hash of the node's text content.
 :)
declare function hash:md5($value as xs:string) as xs:string
{
  hash:hash-unchecked(<a>{$value}</a>, "md5")
};

(:~
 : Computes the SHA1 hash of the text content of the node provided as parameter.
 :
 : @param $value The node whose text content will be hashed.
 : @return The SHA1 hash of the node's text content.
 :)
declare function hash:sha1($value as xs:string) as xs:string
{
  hash:hash-unchecked(<a>{$value}</a>, "sha1")
};

(:~
 : This function is only used internally and should not be called directly by the
 : user - it does not check, if the requested algorithm is supported.
 :
 : @param $value The node whose text content will be hashed.
 : @param $alg The algorithm to use for this hashing operation. Currently only
 :        "MD5" and "SHA1" algorithms are available. This parameter is case insensitive.
 : @return The MD5 hash of the node's text content.
 :)
declare %private function hash:hash-unchecked($value as node(), $alg as xs:string) as xs:string external;

