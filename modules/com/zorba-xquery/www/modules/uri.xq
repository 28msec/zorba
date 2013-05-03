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
 : @project XDM/atomic
 :
 :)
module namespace uri = "http://www.zorba-xquery.com/modules/uri";

declare namespace zerr = "http://www.zorba-xquery.com/errors";
declare namespace ver = "http://www.zorba-xquery.com/options/versioning";
declare option ver:module-version "1.0";

(:~
 : Constant for the "scheme" part of a URI object.
 :)
declare variable $uri:scheme := "scheme";

(:~
 : Constant for the "authority" part of a URI object.
 :)
declare variable $uri:authority := "authority";

(:~
 : Constant for the "user-info" part of a URI object.
 :)
declare variable $uri:user-info := "user-info";

(:~
 : Constant for the "host" part of a URI object.
 :)
declare variable $uri:host := "host";

(:~
 : Constant for the "port" part of a URI object.
 :)
declare variable $uri:port := "port";

(:~
 : Constant for the "path" part of a URI object.
 :)
declare variable $uri:path := "path";

(:~
 : Constant for the "query" part of a URI object.
 :)
declare variable $uri:query := "query";

(:~
 : Constant for the "fragment" part of a URI object.
 :)
declare variable $uri:fragment := "fragment";

(:~
 : Constant for the "opaque-part" part of a URI object.
 :
 : If this is set in a URI object, then none of $uri:PATH, $uri:HOST,
 : $uri:PORT, $uri:USER-INFO, or : $uri:QUERY may be specified.
 :
 : If this is set in a URI object, $uri:SCHEME must also be specified
 : (ie, it must be an absolute URI).
 :)
declare variable $uri:opaque-part := "opaque-part";


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
  
(:~
 : Parses the URI passed as xs:string into a URI JSON object. The object 
 : will contain only members with field names declared as constants in
 : this module.
 :
 : @param $uri the URI as string to parse
 :
 : @return the URI JSONiq object
 :
 : Example: Assume that you have this xquery code: 
 : import module namespace uri = "http://www.zorba-xquery.com/modules/uri";
 : 
 : let my-uri := "http://www.my.project.com/a/b/c?user=john;pass=1234#profile"
 : return uri:parse(my-uri)
 :
 : The output of this code would be this JSON object:
 : <code>
 : { "squeme" : "http", "host" : "www.my.project.com", "path" : "/a/b/c",
 :   "query" : "user=john;pass=123", "fragment" : "profile" }
 : </code>
 : 
 : @error err:XQST0046 if the URI is textually invalid
 :)
declare function uri:parse(
  $uri as xs:string) as object() external;
  
(:~
 : Serialize the URI passed as JSON object into a URI represented as xs:string.
 : The object should only contain members with field names declared as
 : constants in this module.
 :
 : @param $uri the URI JSONiq object
 :
 : @return the URI as xs:string
 :
 : @error zerr:ZURI0001 if opaque part is specified in conjunction with
 : host/port/path/user-info/query.
 :
 : @error zerr:ZURI0002 if opaque part is present but no scheme is present at the
 : same time.
 :
 : @error zerr:ZURI0003 if a path component for an absolute URI doesn't start with
 : "/".
 :
 :)
declare function uri:serialize(
  $uri as object()) as xs:string external;

