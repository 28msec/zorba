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
 : This library module provides simple sign functions.
 :
 : @author Gabriel Petrovay, Markus Pilman
 :
 :)
module namespace sign="http://www.zorba-xquery.com/modules/security/sign";

import module namespace alg = "http://www.zorba-xquery.com/modules/security/algorithms";

(:~
 : Signs the text content of a node with a user provided key. The sign
 : operation is obtained by concatenating the key with the node's text content
 : and hashing the resulting string. This operation uses MD5 as the hashing
 : algorithm.
 :
 : @param $value The node whose text content will be signed.
 : @param $key The key to sign the node's text content.
 : @return The MD5 hash value representing a the signed text content of the
 :         provided node.
 :)
declare function sign:md5($value as xs:string, $key as xs:string) as xs:string
{
  sign:sign-internal($value, $key, "md5")
};

(:~
 : Signs the text content of a node with a user provided key. The sign
 : operation is obtained by concatenating the key with the node's text content
 : and hashing the resulting string. This operation uses SHA1 as the hashing
 : algorithm.
 :
 : @param $value The node whose text content will be signed.
 : @param $key The key to sign the node's text content.
 : @return The SHA1 hash value representing a the signed text content of the
 :         provided node.
 :)
declare function sign:sha1($value as xs:string, $key as xs:string) as xs:string
{
  sign:sign-internal($value, $key, "sha1")
};

(:~
 : Signs the text content of a node with a user provided key. The sign
 : operation is obtained by concatenating the key with the node's text content
 : and hashing the resulting string.
 :
 : @param $value The node whose text content will be signed.
 : @param $key The key to sign the node's text content.
 : @param $alg The algorithm to use for this signing operation. Currently only
 :		       "MD5" and "SHA1" algorithms are available. This parameter is
 :             case insensitive.
 : @return The hash value representing a the signed text content of the
 :         provided node.
 : @error An error is thrown if the hash algorithm is not supported.
 :)
declare function sign:sign($value as xs:string, $key as xs:string, $alg as xs:string) as xs:string
{
  let $a := fn:lower-case($alg)
  return 
    if ($a = $alg:supported-algorithms) then
      sign:sign-internal($value, $key, $a)
    else
      fn:error($alg:unknown-algorithm)
};

(:~
 : This function is only for internal use - don't call it directly. 
 :
 : @param $value The node whose text content will be signed.
 : @param $key The key to sign the node's text content.
 : @param $alg The algorithm to use for this signing operation. Currently only
 :		       "MD5" and "SHA1" algorithms are available. This parameter is
 :             case insensitive.
 : @return The hash value representing a the signed text content of the
 :         provided node.
 : @error An error is thrown if the hash algorithm is not supported.
 :)
declare function sign:sign-internal($valu as xs:string, $key as xs:string, $alg as xs:string) as xs:string external;


