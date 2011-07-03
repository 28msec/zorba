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
 : This module provides an interface for zorbas http client. Basically it
 : provides functions for simple http requests (GET, POST, DELETE etc.)
 : and a general purpose function. If the simple functions are not enough
 : powerfull for your needs, you should use the implementation of the EXPath
 : module instead. See <a href="http://www.expath.org/spec/http-client">the spec
 : of the http-client</a> for more information about EXPaths http-client.
 :
 : While the EXPath functions are all declared as sequential, some functions in
 : this module are defined as nondeterministic. But if you are making a request
 : with one of these modules to a server which does not conform to the HTTP
 : RFC (and which introduces side effects for side-effect free calls like GET),
 : use the EXPath module instead. Otherwise the behavior of your problem will
 : be undefined.
 :
 : Examples of how to use this module:
 :
 : <b>Simple GET Request (retrieving HTML)</b>
 :
 : <pre class="brush: xquery;">http:get( "www.example.com" )</pre>
 : 
 : returns
 :
 :   <pre class="brush: xml;">
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
 :
 : <b>Simple GET Request (retrieving XHTML)</b>
 :
 :   <pre class="brush: xquery;">
 :   declare namespace xhtml="http://www.w3.org/1999/xhtml";
 :
 :   http:get( "www.w3.org" )[2]//xhtml:body
 :   </pre>
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
 :   <pre class="brush: xquery;">
 :   http:post( "...", "Hello World" )
 :   </pre>
 :
 : The response of this request can look as follows:
 : 
 :   <pre class="brush: xml;">
 :   &lt;http:response status="200" message="Ok">
 :      &lt;http:header name="Content-Type" value="text/html"/>
 :      &lt;http:header name="Server" value="Apache ..."/>
 :      ...
 :      &lt;http:body content-type="text/html"/>
 :   &lt;/http:response>
 : </pre>
 :
 : @author Markus Pilman
 : @see <a href="http://www.w3.org/TR/xquery-11/#FunctionDeclns">XQuery 1.1: Function Declaration</a>
 : @library <a href="http://curl.haxx.se/">cURL Library</a>
 : @project external
 :)
module namespace http = "http://www.zorba-xquery.com/modules/http-client";

import module namespace err = "http://expath.org/ns/error";

import schema namespace https = "http://expath.org/ns/http-client";

declare namespace ver = "http://www.zorba-xquery.com/options/versioning";
declare option ver:module-version "2.0";


(:~
 : This function sends an HTTP request and returns the corresponding response. It just
 : implements the http:send-request/3 function from the EXPath module. To provide better
 : interoperability between XQuery engines, use the EXPath module instead.
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
declare %sequential function http:send-request(
  $request as element(https:request)?,
  $href as xs:string?,
  $bodies as item()*) as item()+ 
{
  if (http:check-params($request, $href, $bodies))
  then
    {
      variable $req := if ($request) 
                      then
                        try 
                        {
                          validate { http:set-content-type($request) }
                        }
                        catch XQDY0027 
                        {
                          fn:error($err:HC005, "The request element is not valid.")
                        }
                      else
                       ();

      variable $result := http:http-sequential-impl($req, $href, $bodies);

     $result
    }
  else 
    ()
};


(:~
 : This function makes a GET request on a given URL.
 :
 : This function just makes a http GET request on $href. The function
 : is nondeterministic. But if a GET request to the given address has
 : side effects, which would not conform with the RFC but is often the
 : case, then you should use a sequential function instead.
 :
 : @param $href The URL to which the call will be made.
 : @return a sequence of items, where the first item is a element of type
 :  http:responseType. The response element is also described in the
 :  <a href="http://expath.org/modules/http-client.html#d2e483">specification</a>.
 :  If there is one (or several, in case of multipart) response body, the response bodies
 :  are the next items in the sequence.
 :)
declare function http:get($href as xs:string) as item()+
{
  http:http-nondeterministic-impl((), $href, ())
};

(:~
 : Makes a HTTP HEAD request.
 :
 : @param $href The URL to which the request will be made.
 : @return A element which describes the result of this request. A http HEAD
 :         request never returns a body.
 :)
declare function http:head($href as xs:string) as item() {
  http:http-nondeterministic-impl(
    validate {
      <https:request method="HEAD" href="{$href}">
      </https:request>
    }, (), ())
};

(:~
 : Makes a HTTP OPTIONS request.
 :
 : This request ask for OPTIONS supported of the server.
 :
 : @param $href The URL where to send the request.
 : @return A sequence of string with the allowed operations
 :)
declare function http:options($href as xs:string) as xs:string* {
  let $resp := http:http-nondeterministic-impl(
    validate {
      <https:request method="OPTIONS" href="{$href}">
      </https:request>
    }, (), ())[1]
  return
    fn:tokenize(fn:data($resp/https:header[@name = "Allow"]/@value), ",")
};


(:~
 : Makes a HTTP PUT request.
 :
 : @param $href The URL where to send the request.
 : @param $body The body which will be sent to the server
 : @return The first element of the result is the metadata (like
 :         headers, status etc), the next elements are the response
 :)
declare %sequential function http:put($href as xs:string, $body as item()) as item()+
{
  variable $media-type as xs:string+ :=
    typeswitch($body)
      case xs:string return ("text/plain","text")
      case element() return ("text/xml", "xml")
      default return ("text/plain","xml");

  variable $result := http:http-sequential-impl(validate {
    <https:request href="{$href}" method="PUT">
      <https:body media-type="{$media-type[1]}" method="{$media-type[2]}">{$body}</https:body>
    </https:request>}
    , (), ());

  $result
};

(:~
 : Makes a HTTP DELETE request.
 :
 : @param $href The URL where to send the request.
 : @return The first element of the result is the metadata (like
 :         headers, status etc), the next elements are the response
 :)
declare %sequential function http:delete($href as xs:string) as item()+
{
  http:http-nondeterministic-impl(
    validate {
      <https:request method="DELETE" href="{$href}">
      </https:request>
    }, (), ())
};

(:~
 : Makes a HTTP POST request.
 :
 : This function supports only simple http POST requests which should suite
 : most of the mostly common requests. Unlike the send-request function from
 : the EXPath http client, the user only has to give a URL, where she wants
 : the request sent to and a body as an item. The body will than be serialized
 : as follows:
 :  <ul>
 :    <li>If $body is of type xs:string, it will be serialized as plain text and
 :        the Content-Type for the request will be set to "text/plain"</li>
 :    <li>If $body is an element node, the Content-Type will be set to "text/xml"
 :        and the element will be serialized as xml.</li>
 :  </ul>
 :
 : @param $href The URL where to send the request.
 : @param $body The body which will be sent to the server
 : @return The first element of the result is the metadata (like
 :         headers, status etc), the next elements are the response
 :)
declare %sequential function http:post($href as xs:string, $body as item()) as item()+
{
  variable $media-type as xs:string+ :=
    typeswitch($body)
      case xs:string return ("text/plain","text")
      case element() return ("text/xml", "xml")
      default return ("text/plain","xml");

  variable $result := http:http-sequential-impl(validate {
    <https:request href="{$href}" method="POST">
      <https:body media-type="{$media-type[1]}" method="{$media-type[2]}">{$body}</https:body>
    </https:request>}
    , (), ());

  $result
};


declare %private %sequential function http:http-sequential-impl(
  $request as schema-element(https:request)?,
  $href as xs:string?,
  $bodies as item()*) as item()+ external;


declare %private %nondeterministic function http:http-nondeterministic-impl(
  $request as schema-element(https:request)?,
  $href as xs:string?,
  $bodies as item()*) as item()+ external;



(:~
 : This function takes an https:body element, copies it, and
 : adds a method attribute to the copy if there is none
 : in the original element.
 :
 : @param $body is the original https:body element
 : @return a https:body element with a corresponding <code>@method</code>
 :   attribute 
 :)
declare %private function http:create-body (
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
 : This function takes an https:multipart element, copies it and
 : adds a @method attribute to all body elements which don't have
 : one.
 :
 : @param $multipart the original https:multipart
 : @return a copy of $multipart with all $multipart/body/@method set 
 :)
declare %private function http:create-multipart (
  $multipart as element(https:multipart))
    as element(https:multipart) {
    <https:multipart>{$multipart/@*}
    {
    for $x in $multipart/node()
    return
      typeswitch($x)
        case element(https:body) return http:create-body($x)
        default return $x
    }
    </https:multipart>
};


(:~
 : This adds a default method attribute to all body elements which
 : don't contain a method attribute.
 :
 : @param $request The request which need to be copied.
 : @return A copy of $request with all request//body/@method set.
 :)
declare %private function http:set-content-type(
  $request as element(https:request)?)
    as element(https:request)? {
  if ($request) then
    <https:request>{$request/@*}
    {
    for $x in $request/node()
    return
      typeswitch($x)
        case element(https:body) return http:create-body($x)
        case element(https:multipart) return http:create-multipart($x)
        default return $x
    }
    </https:request>
  else ()
};

(:~
 : Private function used internally by this module.
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
declare %private function http:check-params(
  $request as element(https:request)?,
  $href as xs:string?,
  $bodies as item()*) as xs:boolean {
  let $multipart := $request/http:multipart
  let $override := $request/@override-media-type/data(.)
  let $should-be-empty :=
    for $x in $request//https:body
    return
      if ($x/@src and fn:not((fn:count($x/@*) eq 2))) then 1
      else ()
  return
    if (fn:empty($href) and fn:empty($request)) then
      fn:error($err:HC005, "The request element is not valid.")
    else if ($href eq "") then
      fn:error($err:HC005,
        "The request element is not valid.")
    else if (not(count($request//https:body[not(exists(node())) and not(exists(@src))]) eq count($bodies))) then
      fn:error($err:HC005,
        "The request element is not valid.")
    else if ($should-be-empty) then
      fn:error($err:HC004, "The src attribute on the body element is mutually exclusive with all other attribute (except the media-type).")
    else
      fn:true()
};
