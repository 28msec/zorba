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
 : The module implements the http-client specified by EXPath
 : @see <a href="http://www.expath.org/modules/http-client/" target="_blank">
 : http://www.expath.org/modules/http-client/</a>.
 : However, this module is an extension because it adds some convenience
 : functions and send-request functions that are declared as
 : deterministic and nondeterministic (see XQuery 1.1), respectively.
 :
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
 :
 : <p>
 : If the content type of a response is html, http-client will tidy it
 : automatically. If you want to prevent that, you can also set your
 : own by settin the override-media-type attribute in the http:request
 : element.
 : When tidying, it will use the follwong tidy options:
 : <ul>
 :   <li>TidyXmlOut=yes</li>
 :   <li>TidyDoctypeMode=TidyDoctypeOmit</li>
 :   <li>TidyQuoteNbsp=yes</li>
 :   <li>TidyCharEncoding="utf8"</li>
 :   <li>TidyNewline="LF"</li>
 : </ul>
 : </p>
 :
 : <p>
 : Please also referr to the official documentation at
 : <a href="http://expath.org/modules/http-client.html">expath.org</a>
 : For further information (especially about the http:request and
 : http:response elements) see also the xml schema and its annotations
 : (located in $zorba_install_dir/modules/org/expath/ns/).
 : </p>
 : 
 : <p>
 : Also note that the function is declared as sequential (see XQuery Scripting).
 : Sequential functions are allowed to have side effects. For example, most probably,
 : an HTTP POST request is a request that has side effects because it adds/changes
 : a remote resource.
 : </p>
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
declare sequential function http:send-request(
  $request as element(https:request)?,
  $href as xs:string?,
  $bodies as item()*) as item()+ {
  if (http:check-params($request, $href, $bodies))
  then
    let $req := if ($request) then validate { http:set-content-type($request) } else ()
    let $result := httpclientimpl:http-send-request-impl($req,
                                                         $href,
                                                         $bodies)
    return (validate {$result[1]}, fn:subsequence($result, 2))
  else ()
};

(:~
 : Function for convenience.
 : @see documentation of send-request with three parameters.
 :
 : @param $request see request parameter of 
 :  <a href="#send-request-3">send-request#3</a>
 : @return see return value of
 :  <a href="#send-request-3">send-request#3</a>
 :)
declare sequential function http:send-request (
  $request as element(https:request)) as item()+ {
  http:send-request($request,(),())
};

(:~
 : Function for convenience.
 : @see documentation of send-request with three parameters.
 :
 : @param $request see parameter $request of
 :  <a href="#send-request-3">send-request#3</a>
 : @param href see parameter $href of
 :  <a href="#send-request-3">send-request#3</a>
 : @return see return of
 :  <a href="#send-request-3">send-request#3</a>
 :)
declare sequential function http:send-request(
  $request as element(https:request)?,
  $href as xs:string?) as item()+ {
  http:send-request($request,$href,())  
};

(:~
 : This function sends an HTTP request and returns the corresponding 
 : response. It supports HTTP multi-part messages.
 :
 : <p>
 : If the content type of a request is html, http-client will tidy it
 : automatically. If you want to prevent that, you can also set your
 : own by settin the override-media-type attribute in the http:request
 : element.
 : When tidying, it will use the follwong tidy options:
 : <ul>
 :   <li>TidyXmlOut=yes</li>
 :   <li>TidyDoctypeMode=TidyDoctypeOmit</li>
 :   <li>TidyQuoteNbsp=yes</li>
 :   <li>TidyCharEncoding="utf8"</li>
 :   <li>TidyNewline="LF"</li>
 : </ul>
 : </p>
 :
 : <p>
 : If the content type of a request is html, http-client will tidy it
 : Please also referr to the official documentation at
 : <a href="http://expath.org/modules/http-client.html">expath.org</a>
 : For further information (especially about the http:request and
 : http:response elements) see also the xml schema and its annotations
 : (located in $zorba_install_dir/modules/org/expath/ns/).
 : </p>
 : 
 : <p>
 : If the content type of a request is html, http-client will tidy it
 : Also note that the function is <b>not</b> declared as sequential.
 : That is, the query processor is free to optimize invocations of this
 : function. For example, a call to this function within a for expression
 : could be hoisted outside of the for because it assumes that every
 : invocation of the function with the same parameters has the same result
 : (in particular it doesn't have any side effects). Usually, this
 : function will be used for retrieving resources using HTTP GET or HEAD
 : which are known to not change during the execution of the query.
 : </p>
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
declare function http:send-request-deterministic(
  $request as element(https:request)?,
  $href as xs:string?,
  $bodies as item()*) as item()+ {
  if (http:check-params($request, $href, $bodies))
  then
    let $req := if ($request) then validate { http:set-content-type($request) } else ()
    let $result := httpclientimpl:http-send-request-impl-deterministic($req, $href, $bodies)
    return (validate {$result[1]}, fn:subsequence($result, 2))
  else ()
};

(:~
 : Function for convenience.
 : @see documentation of send-request-deterministic with three parameters.
 :
 : @param $request see parameter $request of
 :  <a href="#send-request-3">send-request-deterministic#3</a>
 : @param href see parameter $href of
 :  <a href="#send-request-3">send-request-deterministic#3</a>
 : @return see return of
 :  <a href="#send-request-3">send-request-deterministic#3</a>
 :)
declare function http:send-request-deterministic(
  $request as element(https:request)?,
  $href as xs:string?) as item()+ {
  http:send-request-deterministic($request, $href, ())
};

(:~
 : Function for convenience.
 : @see documentation of send-request-deterministic with three parameters.
 :
 : @param $request see parameter $request of
 :  <a href="#send-request-3">send-request-deterministic#3</a>
 : @return see return of
 :  <a href="#send-request-3">send-request-deterministic#3</a>
 :)
declare function http:send-request-deterministic(
  $request as element(https:request)?) as item()+ {
  http:send-request-deterministic($request, (), ())
};

(:~
 : This function sends an HTTP request and returns the corresponding 
 : response. It supports HTTP multi-part messages.
 :
 : <p>
 : If the content type of a request is html, http-client will tidy it
 : If the content type of a request is html, http-client will tidy it
 : automatically. If you want to prevent that, you can also set your
 : own by settin the override-media-type attribute in the http:request
 : element.
 : When tidying, it will use the follwong tidy options:
 : <ul>
 :   <li>TidyXmlOut=yes</li>
 :   <li>TidyDoctypeMode=TidyDoctypeOmit</li>
 :   <li>TidyQuoteNbsp=yes</li>
 :   <li>TidyCharEncoding="utf8"</li>
 :   <li>TidyNewline="LF"</li>
 : </ul>
 : </p>
 :
 : <p>
 : Please also referr to the official documentation at
 : <a href="http://expath.org/modules/http-client.html">expath.org</a>
 : For further information (especially about the http:request and
 : http:response elements) see also the xml schema and its annotations
 : (located in $zorba_install_dir/modules/org/expath/ns/).
 : </p>
 : 
 : <p>
 : Also note that the function is  declared as nondeterministic but not
 : sequential. Usually, this function will be used for retrieving resources
 : using HTTP GET or HEAD which are known to change during the execution of
 : the query, i.e. return a different result with each invocation of the
 : function.
 : </p>
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
declare function http:send-request-nondeterministic(
  $request as element(https:request)?,
  $href as xs:string?,
  $bodies as item()*) as item()+ {
  if (http:check-params($request, $href, $bodies))
  then
    let $req := if ($request) then validate { http:set-content-type($request) } else ()
    let $result := httpclientimpl:http-send-request-impl-nondeterministic($req, $href, $bodies)
    return (validate {$result[1]}, fn:subsequence($result, 2))
  else ()
};

(:~
 : Function for convenience.
 : @see documentation of send-request-nondeterministic with three parameters.
 :
 : @param $request see parameter $request of
 :  <a href="#send-request-3">send-request-nondeterministic#3</a>
 : @param href see parameter $href of
 :  <a href="#send-request-3">send-request-nondeterministic#3</a>
 : @return see return of
 :  <a href="#send-request-3">send-request-nondeterministic#3</a>
 :)
declare function http:send-request-nondeterministic(
  $request as element(https:request)?,
  $href as xs:string?) as item()+ {
  http:send-request-nondeterministic($request, $href, ())
};

(:~
 : Function for convenience.
 : @see documentation of send-request-nondeterministic with three parameters.
 :
 : @param $request see parameter $request of
 :  <a href="#send-request-3">send-request-nondeterministic#3</a>
 : @return see return of
 :  <a href="#send-request-3">send-request-nondeterministic#3</a>
 :)
declare function http:send-request-nondeterministic(
  $request as element(https:request)?) as item()+ {
  http:send-request-nondeterministic($request, (), ())
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
  $body as element(https:body))
    as element(https:body) {
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
  $multipart as element(https:multipart))
    as element(https:multipart) {
  validate {
    <https:multipart>{$multipart/@*}
    {
    for $x in $multipart/node()
    return
      typeswitch($x)
        case element(https:body) return http:create-body($x)
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
  $request as element(https:request)?)
    as element(https:request)? {
  if ($request) then
    validate
    {
      <http:request>{$request/@*}
      {
      for $x in $request/node()
      return
        typeswitch($x)
          case element(https:body) return http:create-body($x)
          case element(https:multipart) return http:create-multipart($x)
          default return $x
      }
      </http:request>
    }
  else ()
};

(:~
 : Helper function.
 :
 : This function checks if the request, href, and bodies parameters
 : are consistent.
 :
 : @param $request The request which needs to be checked.
 : @param $href The href which needs to be checked.
 : @param $href The bodies element which needs to be checked.
 : @return true if the parameters are consistent. Otherwise,
 :         this function raises an error.
 :)
declare function http:check-params(
  $request as element(https:request)?,
  $href as xs:string?,
  $bodies as item()*) as xs:boolean {
  if (fn:empty($href) and fn:empty($request)) then
    fn:error($err:HCV01, "Not all required arguments are set.")
  else if ($href eq "") then
    fn:error($err:HCV01,
      "The href value is set to the empty string")
  else if (not(count($request//body[not(exists(node()))]) eq count($bodies))) then
    fn:error($err:HCV01,
      "The number of bodies without children is not equal the size of the bodies sequence")
  else
    fn:true()
};

