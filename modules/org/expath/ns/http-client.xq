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
 : a remote resource. Sequential functions are specified in the
 : <a href="http://www.w3.org/TR/xquery-sx-10/">XQuery Scripting Extension</a>,
 : which is an extension of XQuery.
 : Sequential functions are only allowed to be invoked in certain places (e.g.
 : only from functions which are declared as sequential themselves).
 : In contrast, the http:read() functions are not declared as sequential -
 : they are declared as nondeterministic though, which
 : means that several calls may return different results.
 : HTTP requests performed using these functions are <b>not</b> allowed to have
 : side effects.
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
 :  <li>An xs:string item is returned if the media type has a text MIME type,
 :     i.e. beginning with text/.</li>
 :  <li>An xs:base64Binary item is returned for all the other media types.</li>
 : </ul>
 : </p>
 :
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
 : @see <a href="http://www.w3.org/TR/xquery-11/#FunctionDeclns">XQuery 1.1: Function Declaration</a>
 : @library <a href="http://curl.haxx.se/">cURL Library</a>
 :
 :)
module namespace http = "http://expath.org/ns/http-client";

import module namespace zorba-http = "http://www.zorba-xquery.com/modules/http-client";
import module namespace err = "http://expath.org/ns/error";

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
  $request as element()?,
  $href as xs:string?,
  $bodies as item()*) as item()+ {
  try {
    zorba-http:send-request($request, $href, $bodies)
  } catch XPTY0004 {
    fn:error($err:HC005, "The request element is not valid.")
  }
};

(:~
 : Function for convenience.
 :
 : Calling this function is equivalent to calling
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
  $request as element()) as item()+ {
  try {
    http:send-request($request, (), ())
  } catch XPTY0004 {
    fn:error($err:HC005, "The request element is not valid.")
  }
};

(:~
 : Function for convenience.
 :
 : Calling this function is equivalent to calling
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
  $request as element()?,
  $href as xs:string?) as item()+ {
  try {
    http:send-request($request, $href, ())
  } catch XPTY0004 {
    fn:error($err:HC005, "The request element is not valid.")
  }
};