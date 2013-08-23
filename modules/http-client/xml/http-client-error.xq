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
 : See the License for the specific language governinzg permissions and
 : limitations under the License.
:)

(:~
 : This module defines all errors for the http-client module.
 :
 : @author Markus Pilman
 : @project EXPath/EXPath Error Codes
 :
 :)
module namespace err = "http://expath.org/ns/error";

(:~
 : Error namespace URI.
 :)
declare variable $err:errNS as xs:string := "http://expath.org/ns/error";

(:~
 : An HTTP error occurred.
 :)
declare variable $err:HC001 as xs:QName := fn:QName($err:errNS, "err:HC001");

(:~
 : Error parsing the entity content as XML or HTML.
 :)
declare variable $err:HC002 as xs:QName := fn:QName($err:errNS, "err:HC002");

(:~
 : With a multipart response, the override-media-type must be either a multipart media type or application/octet-stream.
 :)
declare variable $err:HC003 as xs:QName := fn:QName($err:errNS, "err:HC003");

(:~
 : The src attribute on the body element is mutually exclusive with all other attribute (except the media-type).
 :)
declare variable $err:HC004 as xs:QName := fn:QName($err:errNS, "err:HC004");

(:~
 : The request element is not valid.
 :)
declare variable $err:HC005 as xs:QName := fn:QName($err:errNS, "err:HC005");

(:~
 : A timeout occurred waiting for the response.
 :)
declare variable $err:HC006 as xs:QName := fn:QName($err:errNS, "err:HC006");

(:~
 : This error is not defined in the specification but used by the Zorba implementation.
 :
 : It gets thrown when the user gives wrong arguments which are statically correct,
 : but make no sense (for example: http:send-request((), ())).
 :)
declare variable $err:HCV01 as xs:QName := fn:QName($err:errNS, "err:HCV01");

(:~
 : Zorba specific error
 : This error is raised if trying to follow a redirect for a POST, PUT, or
 : DELETE request
 :)
declare variable $err:HCV02 as xs:QName := fn:QName($err:errNS, "err:HCV02");
