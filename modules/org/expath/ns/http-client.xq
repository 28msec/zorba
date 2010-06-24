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
 : <p>
 : This module provides an implementation of the
 : <a href="http://expath.org/modules/http-client.html">EXPath Http Client</a>.
 : It provides functions for making HTTP requests and is a superset of the
 : module specified by EXPath.
 : Specifically, it implements the <code>http:send-request()</code> functions
 : as specified by EXPath. Moreover, it adds an additional function
 : <code>http:read()</code> (with several arities for the sake of ease).
 : </p>
 :
 : <p>
 : In general, both functions take a description of the HTTP request to make
 : as parameter, execute the request, and return a representation of the HTTP
 : response.
 : </p>
 : 
 : <p>
 : The <code>http:send-request()</code> functions are declared as sequential. 
 : Sequential functions are allowed to have side effects. For example, most probably,
 : an HTTP POST request is a request that has side effects because it adds/changes
 : a remote resource. Such functions are an extension of XQuery and are specified in 
 : the <a href="http://www.w3.org/TR/xquery-sx-10/">XQuery Scripting Extension</a>.
 : Sequential functions are only allowed to be invoked in certain places (e.g.
 : only from functions which are declared as sequential themselves).
 : In contrast, the <code>http:read()</code> functions are declared as
 : nondeterministic (see <a href="http://www.w3.org/TR/xquery-11/">XQuery 1.1</a>).
 : HTTP requests performed using these functions are <b>not</b> allowed to have
 : side effects.
 : </p>
 :
 : <p>
 : For almost all functions (except <code>read</code> with one parameter),
 : the request is represented by an <code>http:request</code>
 : element, specifying the URI, the HTTP method, the headers, and the body
 : content (for POST and PUT methods) of the HTTP request to make.
 : </p>
 :
 : <p>
 : The response is returned as a sequence of one or more items. The first
 : one is an <code>http:response</code> element with quite the same
 : structure as an http:request, but without the content itself.
 : The content is returned as the second item (or several items in case of
 : a multipart response) as a string, a document node, or a binary item.
 : This depends on the content-type returned.
 : Specifically, the rules are as follows:
 : 
 : <ul>
 :  <li>A document node is returned if the media type has a MIME type of
 :     text/xml, application/xml, text/xml-external-parsed-entity, or
 :     application/xml-external-parsed-entity, as defined in [RFC 3023]
 :     (except that application/xml-dtd is considered a text media type).
 :     MIME types ending by +xml are also XML media types.</li>
 :  <li>A document node is returned if the media type has a MIME type of
 :      text/html. In order to be able to make HTML parseable, tidy is automatically
 :      invoked. If you want to prevent that, you can also set your own content-type
 :      by setting the override-media-type attribute in the request element.
 :       For tidying, the following <a href="http://tidy.sourceforge.net/docs/quickref.html">options</a>
 :       will be used:
 :       <ul>
 :         <li>TidyXmlOut=yes</li>
 :         <li>TidyDoctypeMode=TidyDoctypeOmit</li>
 :         <li>TidyQuoteNbsp=yes</li>
 :         <li>TidyCharEncoding="utf8"</li>
 :         <li>TidyNewline="LF"</li>
 :       </ul>
 :  </li>
 :  <li>A xs:string item is returned if the media type has a text MIME type,
 :     i.e. beginning with text/.</li>
 :  <li>A xs:base64Binary item is returned for all the other media types.</li>
 : </ul>
 : </p>
 :
 : <b>Simple GET Request (retrieving HTML)</b>
 :
 : <code>
 :   <pre>
 :   http:read( &lt;http:request href="www.example.com" method="get"/>, () )
 :   </pre>
 : </code>
 : 
 : returns
 :
 : <code>
 :   <pre>
 :   &lt;response xmlns="http://expath.org/ns/http-client" status="200" message="OK">
 :     &lt;header name="Content-Type" value="text/html; charset=UTF-8"/>
 :     &lt;header name="Content-Length" value="574"/>
 :     ...
 :     &lt;body media-type="text/html"/>
 :   &lt;/response>
 :   &lt;!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"&gt;
 :   &lt;html&gt;
 :     &lt;head&gt;
 :       &lt;meta http-equiv="Content-Type"
 :       content="text/html; charset=utf-8" /&gt;
 :       &lt;title&gt;Example Web Page&lt;/title&gt;
 :     &lt;/head&gt;
 :     &lt;body&gt;
 :       &lt;p&gt;You have reached this web page by typing "example.com",
 :       "example.net", or "example.org" into your web browser.&lt;/p&gt;
 :       &lt;p&gt;These domain names are reserved for use in documentation and are
 :       Not available for registration. See 
 :       &lt;a href="http://www.rfc-editor.org/rfc/rfc2606.txt"&gt;RFC 2606&lt;/a&gt;,
 :       Section 3.&lt;/p&gt;
 :     &lt;/body&gt;
 :   &lt;/html&gt;
 :   </pre>
 : </code>
 :
 : <b>Simple GET Request (retrieving XHTML)</b>
 :
 : <code>
 :   <pre>
 :   declare namespace xhtml="http://www.w3.org/1999/xhtml";
 :
 :   http:read( &lt;http:request href="www.w3.org" method="get"/>, () )[2]//xhtml:body
 :   </pre>
 : </code>
 :
 : <p>
 : This example shows how to retrieve an XHTML resource. Note, that the node test
 : that is looking for the body element in the result requires the xhtml
 : namespace to be specified.
 : </p>
 :
 : <b>Simple POST Request</b>
 : 
 : <p>
 : Here is a simple example which sends a text content by making an HTTP POST
 : request.
 : </p>
 :
 : <code>
 :   <pre>
 :   http:send-request(
 :      &lt;http:request href="..." method="post">
 :         &lt;http:body content-type="text/plain">
 :            Hello, world!
 :         &lt;/http:body>
 :      &lt;/http:request>
 :   )
 :   </pre>
 : </code>
 :
 : The response of this request can look as follows:
 : 
 : <pre>
 :   <code>
 :   &lt;http:response status="200" message="Ok">
 :      &lt;http:header name="Content-Type" value="text/html"/>
 :      &lt;http:header name="Server" value="Apache ..."/>
 :      ...
 :      &lt;http:body content-type="text/html"/>
 :   &lt;/http:response>
 :   </code>
 : </pre>
 :
 : <p>
 : The structure of a request element is defined in the schema that is imported
 : by this module. The details are described in the
 : <a href="http://expath.org/modules/http-client.html#d2e183">specification</a>.
 : Analogously, the response element is also described in this
 : <a href="http://expath.org/modules/http-client.html#d2e483">specification</a>.
 : </p>
 :
 : @author Markus Pilman
 :)
module namespace http = "http://expath.org/ns/http-client";

import module namespace httpclientimpl = "http://expath.org/ns/httpclientimpl";
import module namespace err = "http://expath.org/ns/error";

import schema namespace https = "http://expath.org/ns/http-client";

(:~
 : This function sends an HTTP request and returns the corresponding response. 
 :
 : <p>
 : This function is declared as sequential (see XQuery Scripting).
 : Sequential functions are allowed to have side effects. For example, most probably,
 : an HTTP POST request is a request that has side effects because it adds/changes
 : a remote resource.
 : </p>
 :
 : @param $request Contains the various parameters of the request. 
 :   See the 
 :   <a href="http://expath.org/modules/http-client.html#d2e183">specification</a>.
 :   for a full description of the structure of this element.
 : @param $href is the HTTP or HTTPS URI to send the request to. It must be a valid
 :  xs:anyURI, but is declared as a string to be able to pass literal strings
 :  (without requiring to explicitly cast it to an xs:anyURI.)
 : @param $content is the request body content, for HTTP methods that can
 :  contain a body in the request (i.e. POST and PUT). It is an error, if this
 :  param is not the empty sequence for methods other then DELETE, GET, HEAD
 :  and OPTIONS.
 : @return a sequence of items, where the first item is a element of type
 :  http:responseType. The response element is also described in the
 :  <a href="http://expath.org/modules/http-client.html#d2e483">specification</a>.
 :  If there is one (or several, in case of multipart) response body, the response bodies
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
 :
 : The result of this function is equal to calling the send-request function
 : as follows:
 :
 : <code>
 : http:send-request($request, (), ())
 : </code>
 :
 : @see documentation of <a href="#send-request-3">send-request</a> with three parameters.
 :
 : @param $request see request parameter of the sequential
 :  <a href="#send-request-3">send-request</a> function with three parameters.
 : @return see return value of the sequential 
 :  <a href="#send-request-3">send-request</a> function with three parameters.
 :)
declare sequential function http:send-request (
  $request as element(https:request)) as item()+ {
  http:send-request($request, (), ())
};

(:~
 : Function for convenience.
 :
 : The result of this function is equal to calling the send-request function
 : as follows:
 :
 : <code>
 : http:send-request($request, $href, ())
 : </code>
 :
 : @see documentation of <a href="#send-request-3">send-request</a> with three parameters.
 :
 : @param $request see request parameter of the sequential
 :  <a href="#send-request-3">send-request</a> function with three parameters.
 : @param $href see href parameter of the sequential
 :  <a href="#send-request-3">send-request</a> function with three parameters.
 : @return see return of
 :  <a href="#send-request-3">send-request</a>
 :)
declare sequential function http:send-request(
  $request as element(https:request)?,
  $href as xs:string?) as item()+ {
  http:send-request($request, $href, ())  
};

(:~
 : This function sends an HTTP request and returns the corresponding response. 
 :
 : <p>
 : This function is not sequential. Usually, this function should be used
 : for retrieving resources using HTTP GET or HEAD (i.e. HTTP requests which
 : are known to <b>not</b> have any side effects.
 : </p>
 :
 : @param $request Contains the various parameters of the request. 
 :   See the 
 :   <a href="http://expath.org/modules/http-client.html#d2e183">specification</a>.
 :   for a full description of the structure of this element.
 : @param $href is the HTTP or HTTPS URI to send the request to. It must be a valid
 :  xs:anyURI, but is declared as a string to be able to pass literal strings
 :  (without requiring to explicitly cast it to an xs:anyURI.)
 : @param $bodies is the request body content, for HTTP methods that can
 :  contain a body in the request (i.e. POST and PUT). It is an error, if this
 :  param is not the empty sequence for methods other then DELETE, GET, HEAD
 :  and OPTIONS.
 : @return a sequence of items, where the first item is a element of type
 :  http:responseType. The response element is also described in the
 :  <a href="http://expath.org/modules/http-client.html#d2e483">specification</a>.
 :  If there is one (or several, in case of multipart) response body, the response bodies
 :  are the next items in the sequence.
 :)
declare function http:read(
  $request as element(https:request)?,
  $href as xs:string?,
  $bodies as item()*) as item()+ {
  if (http:check-params($request, $href, $bodies))
  then
    let $req := if ($request) then validate { http:set-content-type($request) } else ()
    let $result := httpclientimpl:http-read-impl($req, $href, $bodies)
    return (validate {$result[1]}, fn:subsequence($result, 2))
  else ()
};

(:~
 : Function for convenience.
 :
 : The result of this function is equal to calling the read function as follows:
 :
 : <code>
 : http:read($request, $href, ())
 : </code>
 :
 : @see documentation of <a href="#read-3">read</a>
 :      with three parameters.
 :
 : @param $request see parameter $request of <a href="#read-3">read</a> with three parameters
 : @param $href see parameter $href of <a href="#read-3">read</a> with three parameters
 : @return see return of <a href="#read-3">read</a> with three parameters
 :)
declare function http:read(
  $request as element(https:request)?,
  $href as xs:string?) as item()+ {
  http:read($request, $href, ())
};

(:~
 : Function for convenience.
 :
 : The result of this function is equal to calling the read function
 : as follows:
 :
 : <code>
 : http:read((), $href, ())
 : </code>
 :
 : @see documentation of <a href="#read-3">read</a> with three parameters.
 :
 : @param $href see parameter $href of <a href="#read-3">read</a> with three parameters
 : @return see return of <a href="#read-3">read</a> with three parameters
 :)
declare function http:read(
  $href as xs:string) as item()+ {
  http:read((), $href, ())
};

(:~
 : Helper function.
 :
 : This function takes an https:body element, copies it, and
 : adds a method attribute to the copy if there is none
 : in the original element.
 :
 : @param $body is the original https:body element
 : @return a https:body element with a corresponding <code>@method</code>
 :   attribute 
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
 : This function takes an https:multipart element, copies it and
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
 : Private helper function used internally by this module.
 :
 : This function checks if the request, href, and bodies parameters
 : are consistent.
 :
 : @param $request The request which needs to be checked.
 : @param $href The href which needs to be checked.
 : @param $bodies The bodies element which needs to be checked.
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
