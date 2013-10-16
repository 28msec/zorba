xquery version "3.0";

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
 : This module provides functions for processing URIs and URLs.
 :
 : @author Matthias Brantner, Luis Rodriguez Gonzalez
 : @project Zorba/XML and JSON Data Model/Atomic/URI
 :
 :)
module namespace uri = "http://zorba.io/modules/uri";

declare namespace zerr = "http://zorba.io/errors";
declare namespace ver = "http://zorba.io/options/versioning";
declare option ver:module-version "1.0";

(:~
 : Constant for the "scheme" part of a URI object.
 :)
declare variable $uri:SCHEME as xs:string := "scheme";

(:~
 : Constant for the "authority" part of a URI object.
 :)
declare variable $uri:AUTHORITY as xs:string := "authority";

(:~
 : Constant for the "user-info" part of a URI object.
 :)
declare variable $uri:USER-INFO as xs:string := "user-info";

(:~
 : Constant for the "host" part of a URI object.
 :)
declare variable $uri:HOST as xs:string := "host";

(:~
 : Constant for the "port" part of a URI object.
 :)
declare variable $uri:PORT as xs:string := "port";

(:~
 : Constant for the "path" part of a URI object.
 :)
declare variable $uri:PATH as xs:string := "path";

(:~
 : Constant for the "query" part of a URI object.
 :)
declare variable $uri:QUERY as xs:string := "query";

(:~
 : Constant for the "fragment" part of a URI object.
 :)
declare variable $uri:FRAGMENT as xs:string := "fragment";

(:~
 : Constant for the "opaque-part" part of a URI object.
 :
 : If this is set in a URI object, then none of $uri:PATH, $uri:HOST,
 : $uri:PORT, $uri:USER-INFO, or : $uri:QUERY may be specified.
 :
 : If this is set in a URI object, $uri:SCHEME must also be specified
 : (ie, it must be an absolute URI).
 :)
declare variable $uri:OPAQUE-PART as xs:string := "opaque-part";


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
 : @error uri:CHARSET_UNKNOWN if the given charset is unknown or not supported
 :
 : @error zerr:ZOSE0006 if there is an error transcoding the string
 :)
declare function uri:decode(
  $s as xs:string,
  $decode-plus as xs:boolean,
  $charset as xs:string) as xs:string external;
  
(:~
 : Parses the URI passed as string. The returned object 
 : contains only members with field names declared as constants in
 : this module.
 :
 : For example,
 : <pre class="ace-static" ace-mode="xquery">
 : let my-uri := "http://www.my.project.com/a/b/c?user=john;pass=1234#profile"
 : return uri:parse(my-uri)
 : </pre>
 :
 : returns
 : <pre class="ace-static" ace-mode="java">
 : { "squeme" : "http", "host" : "www.my.project.com", "path" : "/a/b/c",
 :   "query" : "user=john;pass=123", "fragment" : "profile" }
 : </pre>
 : 
 : @param $uri the URI to parse
 :
 : @return the JSON object
 :
 : @error err:XQST0046 if the URI is textually invalid
 :)
declare function uri:parse(
  $uri as xs:string) as object() external;
  
(:~
 : Serialize the URI passed as object into a string.
 :
 : @param $uri the object representing the URI
 :
 : @return the URI as string
 :
 : @error uri:OPAQUE_COMB_NOT_VALID if opaque part is specified in conjunction with
 : host/port/path/user-info/query.
 :
 : @error uri:OPAQUE_WITHOUT_SCHEME if opaque part is present but no scheme is present.
 :
 : @error uri:INVALID_ABSOLUTE_PATH if a path component for an absolute URI
 : doesn't start with "/".
 :)
declare function uri:serialize(
  $uri as object()) as xs:string external;
