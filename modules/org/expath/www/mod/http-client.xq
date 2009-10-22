(:
 : Copyright 2006-2008 The FLWOR Foundation.
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
 : This module defines a set of functions to send HTTP and HTTPS requests
 : and handle responses. This is quite a low-level functionality, allowing
 : one to deal with most aspects of the HTTP protocol.
 :
 : @see http://www.expath.org/modules/http-client/
 : @version Candidate 13 April 2009
:)
module namespace http = "http://www.expath.org/mod/http-client";

import module namespace httpclientimpl = "http://www.expath.org/mod/httpclientimpl";

import schema namespace https = "http://www.expath.org/mod/http-client" at "file:///C:/Projects/zorba_current/modules/org/expath/www/mod/http-client.xsd";

(:~
 : This function sends an HTTP request and returns the corresponding 
 : response. It supports HTTP multi-part messages.
 :
 : @param $request Contains the various parameters of the request. See the
 :  documentation of the type requestType in the schema definition.
 : @param $href is the HTTP or HTTPS URI to send the request to. It is an
 :  xs:anyURI, but is declared as a string to be able to pass literal strings
 :  (without requiring to explicitly cast it to an xs:anyURI.)
 : @param $content is the request body content, for HTTP methods that can
 :  contain a body in the request (POST and PUT.) It is an error, if this
 :  param is not the empty sequence for methods other then DELETE, GET, HEAD
 :  and OPTIONS. 
:)
declare function http:send-request(
    $request as element(https:request, https:requestType)?,
    $href as xs:string?,
    $content as item()?,
    $serial as item()?) as item()+ {
    if (fn:empty($href) and fn:empty($request)) then
        fn:error(fn:QName("http://www.expath.org/mod/http-client", "WrongArgs"),
            "Not all required arguments are set.")
    else
        if ($href eq "") then
            fn:error(fn:QName("http://www.expath.org/mod/http-client", "HrefEmpty"),
                "The href value is set to the empty string")
        else
            httpclientimpl:http-send-request-impl($request,
                $href,
                $content,
                $serial)
};

(:~
 : Function for convenience.
 : @see documentation of send-request with four parameters.
 :
 : @see http://www.expath.org/mod/http-client;send-request
:)
declare function http:send-request (
    $request as element(https:request, https:requestType)) as item()+ {
    http:send-request($request,(),(),())
};

(:~
 : Function for convenience.
 : @see documentation of send-request with four parameters.
 :
 : @see http://www.expath.org/mod/http-client;send-request
:)
declare function http:send-request(
    $request as element(https:request, https:requestType)?,
    $href as xs:string?) as item()+ {
    http:send-request($request,$href,(),())  
};

(:~
 : Function for convenience.
 : @see documentation of send-request with four parameters.
 :
 : @see http://www.expath.org/mod/http-client;send-request
:)
declare function http:send-request(
    $request as element(https:request, https:requestType)?,
    $href as xs:string?,
    $content as item()?) as item()+ {
    http:send-request($request,$href,$content,())
};
