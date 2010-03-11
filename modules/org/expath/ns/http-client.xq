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
 : This module defines a set of functions to send HTTP and HTTPS requests
 : and handle responses. This is quite a low-level functionality, allowing
 : one to deal with most aspects of the HTTP protocol.
 :
 : @see <a href="http://www.expath.org/modules/http-client/" target="_blank">
 : http://www.expath.org/modules/http-client/</a>
 : @version Candidate 9 January 2010
 : @author Markus Pilman
 :)
module namespace http = "http://expath.org/ns/http-client";

import module namespace httpclientimpl = "http://expath.org/ns/httpclientimpl";
import module namespace err = "http://expath.org/ns/error";

import schema namespace https = "http://expath.org/ns/http-client";

(:~
 : This function sends an HTTP request and returns the corresponding 
 : response. It supports HTTP multi-part messages.
 : If the content type of a request is html, http-client will tidy it
 : automatically. If you want to prevent that, you can also set your
 : own by settin the override-media-type attribute in the http:request
 : element.
 : When tidying, it will use the follwong tidy options:
 : - TidyXmlOut=yes
 : - TidyDoctypeMode=TidyDoctypeOmit
 : - TidyQuoteNbsp=yes
 : - TidyCharEncoding="utf8"
 : - TidyNewline="LF"
 : Please also referr to the official documentation at
 : <a href="http://expath.org/modules/http-client.html">expath.org</a>
 : For further information (especially about the http:request and
 : http:response elements) see also the xml schema and its annotations
 : (located in $zorba_install_dir/modules/org/expath/ns/).
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
 : @return a sequence of items, where the first item is a element of type
 :  http:responseType and describes the response of the http request. If there
 :  is one (or several, in case of multipart) response body, the response bodies
 :  are the next items in the sequence.
 :)
declare function http:send-request(
  $request as element(https:request, https:requestType)?,
  $href as xs:string?,
  $bodies as item()*) as item()+ {
  if (fn:empty($href) and fn:empty($request)) then
    fn:error($err:HCV01,
      "Not all required arguments are set.")
  else if ($href eq "") then
    fn:error($err:HCV01,
      "The href value is set to the empty string")
  else if (not(count($request//body[not(exists(node()))]) eq count($bodies))) then
    fn:error($err:HCV01,
      "The number of bodies without children is not equal the size of the bodies sequence")
  else
    let $result := httpclientimpl:http-send-request-impl(http:set-content-type($request),
                                                         $href,
                                                         $bodies)
    return (validate {$result[1]}, fn:subsequence($result, 2))
};

(:~
 : Function for convenience.
 : @see documentation of send-request with four parameters.
 :
 : @param $request see request parameter of 
 :  <a href="#send-request-3">send-request#3</a>
 : @return see return value of
 :  <a href="#send-request-3">send-request#3</a>
 :)
declare function http:send-request (
  $request as element(https:request, https:requestType)) as item()+ {
  http:send-request($request,(),())
};

(:~
 : Function for convenience.
 : @see documentation of send-request with four parameters.
 :
 : @param $request see parameter $request of
 :  <a href="#send-request-3">send-request#3</a>
 : @param href see parameter $href of
 :  <a href="#send-request-3">send-request#3</a>
 : @return see return of
 :  <a href="#send-request-3">send-request#3</a>
 :)
declare function http:send-request(
  $request as element(https:request, https:requestType)?,
  $href as xs:string?) as item()+ {
  http:send-request($request,$href,())  
};

(:~
 : Helper function.
 :
 : This function takes a https:body element, copies it and
 : adds a method attribute to the copy if there is none
 : in the original element.
 :
 : @param $body is the original https:body element
 : @return a https:body element with a @method attribute 
 :)
declare function http:create-body (
  $body as element(https:body, https:bodyType))
    as element(https:body, https:bodyType) {
  validate {
    <https:body>{$body/@*}
    {
      if ($body/@method) then
        ()
      else
        attribute method {
          if ($body/@media-type eq "text/xml" or
              $body/@media-type eq "application/xml" or
              $body/@media-type eq "text/xml-external-parsed-entity" or
              $body/@media-type eq "application/xml-external-parsed-entity") then
                "xml"
           else if ($body/@media-type eq "text/html") then "html"
           else if (fn:starts-with($body/@media-type/data(.), "text/")) then "text"
           else "binary"
        }
    }
    {$body/node()}
    </https:body>
  }
};

(:~
 : Helper function.
 :
 : This function takes a https:multipart element, copies it and
 : adds a @method attribute to all body elements which don't have
 : one.
 :
 : @param $multipart the original https:multipart
 : @return a copy of $multipart with all $multipart/body/@method set 
 :)
declare function http:create-multipart (
  $multipart as element(https:multipart, https:multipartType))
    as element(https:multipart, https:multipartType) {
  validate {
    <https:multipart>{$multipart/@*}
    {
    for $x in $multipart/node()
    return
      typeswitch($x)
        case element(https:body, https:bodyType) return http:create-body($x)
        default return $x
    }
    </https:multipart>
  }
};


(:~
 : Helper function.
 :
 : This adds a default method attribute to all body elements which
 : don't contain a method attribute.
 :
 : @param $request The request which need to be copied.
 : @return A copy of $request with all request//body/@method set.
 :)
declare function http:set-content-type(
  $request as element(https:request, https:requestType)?)
    as element(https:request, https:requestType)? {
  if ($request) then
    validate
    {
      <http:request>{$request/@*}
      {
      for $x in $request/node()
      return
        typeswitch($x)
          case element(https:body, https:bodyType) return http:create-body($x)
          case element(https:multipart, https:multipartType) return http:create-multipart($x)
          default return $x
      }
      </http:request>
    }
  else ()
};
