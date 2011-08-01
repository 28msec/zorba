xquery version "3.0";

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
 : with one of these functions to a server which does not conform to the HTTP
 : RFC (i.e. which introduces side effects for side-effect free calls like GET),
 : use the EXPath module instead. Otherwise the behavior of your code will
 : be undefined. Zorba has no way to figure out, if a HTTP call is side-effect
 : free or not.
 : 
 : Examples of how to use this module:
 : 
 : <b>Simple GET Request (retrieving text)</b>
 : 
 : <pre class="brush: xquery;">http:get-text( "www.example.com" )</pre>
 : 
 : returns
 : 
 :   <pre class="brush: xml;">
 :   &lt;response xmlns="http://expath.org/ns/http-client" status="200" message="OK"&gt;
 :     &lt;header name="Content-Type" value="text/html; charset=UTF-8"/&gt;
 :     &lt;header name="Content-Length" value="574"/&gt;
 :     ...
 :     &lt;body media-type="text/html"/&gt;
 :   &lt;/response&gt;
 :   &amp;lt;!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"&amp;gt;
 :   &amp;lt;html&amp;gt;
 :     &amp;lt;head&amp;gt;
 :       &amp;lt;meta http-equiv="Content-Type"
 :       content="text/html; charset=utf-8" /&amp;gt;
 :       &amp;lt;title&amp;gt;Example Web Page&lt;/title&amp;gt;
 :     &amp;lt;/head&amp;gt;
 :     &amp;lt;body&amp;gt;
 :       &amp;lt;p&amp;gt;You have reached this web page by typing "example.com",
 :       "example.net", or "example.org" into your web browser.&amp;lt;/p&amp;gt;
 :       &amp;lt;p&amp;gt;These domain names are reserved for use in documentation and are
 :       Not available for registration. See 
 :       &amp;lt;a href="http://www.rfc-editor.org/rfc/rfc2606.txt"&amp;gt;RFC 2606&amp;lt;/a&amp;gt;,
 :       Section 3.&amp;lt;/p&amp;gt;
 :     &amp;lt;/body&amp;gt;
 :   &amp;lt;/html&amp;gt;
 :   </pre>
 : 
 : <b>Simple GET Request (retrieving XHTML)</b>
 : 
 :   <pre class="brush: xquery;">
 :   declare namespace xhtml="http://www.w3.org/1999/xhtml";
 : 
 :   http:get-node( "www.w3.org" )[2]//xhtml:body
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

import module namespace error = "http://expath.org/ns/error";

import schema namespace http-schema = "http://expath.org/ns/http-client";

declare namespace ann = "http://www.zorba-xquery.com/annotations";
declare namespace ver = "http://www.zorba-xquery.com/options/versioning";
declare namespace err = "http://www.w3.org/2005/xqt-errors";

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
 : @error err:XPST0081 Schema validation error - this happens whenever a wrong request element is given.
 : @error error:HC001 An HTTP error occurred.
 : @error error:HC002 Error parsing the entity content as XML or HTML.
 : @error error:HC003 With a multipart response, the override-media-type must be either a multipart media type or application/octet-stream.
 : @error error:HC004 The src attribute on the body element is mutually exclusive with all other attribute (except the media-type).
 : @error error:HC005 The request element is not valid.
 : @error error:HC006 A timeout occurred waiting for the response.
 :)
declare %ann:sequential function http:send-request(
  $request as element(http-schema:request)?,
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
                          fn:error($error:HC005, "The request element is not valid.")
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
 : This functions uses the ContentType of the response to parse the result.
 : It will return a sequence of items, where the first item describes the
 : result according to the <a href="http://www.expath.org/spec/http-client">
 : expath specification</a>. The next items are the date of each body
 : element. Each body will be:
 :
 : <ul>
 :  <li>
 :    an element node, if the returned content type is one of:
 :    <ul>
 :      <li>text/xml</li>
 :      <li>application/xml</li>
 :      <li>text/xml-external-parsed-entity</li>
 :      <li>application/xml-external-parsed-entity</li>
 :      <li>or if the Content-Type ends with "+xml"</li>
 :    </ul>
 :  </li>
 :  <li>
 :    A text node, if the content type starts with "text/" and does not match the
 :    strings for xml.
 :  </li>
 :  <li>for all other content types the type will be xs:base64Binary</li>
 : </ul>
 :
 : Unlike the expath http-client, this function will never tidy html to xml.
 :
 : @param $href The URL to which the call will be made.
 : @return a sequence of items, where the first item is a element of type
 :  http:responseType. The response element is also described in the
 :  <a href="http://expath.org/modules/http-client.html#d2e483">specification</a>.
 :  If there is one (or several, in case of multipart) response body, the response bodies
 :  are the next items in the sequence.
 : @error error:HC001 An HTTP error occurred.
 : @error error:HC002 Error parsing the entity content as XML or HTML.
 : @error error:HC003 With a multipart response, the override-media-type must be either a multipart media type or application/octet-stream.
 : @error error:HC004 The src attribute on the body element is mutually exclusive with all other attribute (except the media-type).
 : @error error:HC005 The request element is not valid.
 : @error error:HC006 A timeout occurred waiting for the response.
 :)
declare %ann:nondeterministic function http:get($href as xs:string) as item()+
{
  http:http-nondeterministic-impl(validate {<http-schema:request method="GET" href="{$href}" follow-redirect="true"/>}, (), ())
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
 : @error error:HC001 An HTTP error occurred.
 : @error error:HC002 Error parsing the entity content as XML or HTML.
 : @error error:HC003 With a multipart response, the override-media-type must be either a multipart media type or application/octet-stream.
 : @error error:HC004 The src attribute on the body element is mutually exclusive with all other attribute (except the media-type).
 : @error error:HC005 The request element is not valid.
 : @error error:HC006 A timeout occurred waiting for the response.
 :)
declare %ann:nondeterministic function http:get-node($href as xs:string) as item()+
{
  http:http-nondeterministic-impl(validate {<http-schema:request method="GET" href="{$href}" follow-redirect="true" override-media-type="text/xml"/>}, (), ())
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
 : @error error:HC001 An HTTP error occurred.
 : @error error:HC002 Error parsing the entity content as XML or HTML.
 : @error error:HC003 With a multipart response, the override-media-type must be either a multipart media type or application/octet-stream.
 : @error error:HC004 The src attribute on the body element is mutually exclusive with all other attribute (except the media-type).
 : @error error:HC005 The request element is not valid.
 : @error error:HC006 A timeout occurred waiting for the response.
 :)
declare %ann:nondeterministic function http:get-text($href as xs:string) as item()+
{
  http:http-nondeterministic-impl(validate {<http-schema:request method="GET" href="{$href}" follow-redirect="true" override-media-type="text/plain"/>}, (), ())
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
 : @error error:HC001 An HTTP error occurred.
 : @error error:HC002 Error parsing the entity content as XML or HTML.
 : @error error:HC003 With a multipart response, the override-media-type must be either a multipart media type or application/octet-stream.
 : @error error:HC004 The src attribute on the body element is mutually exclusive with all other attribute (except the media-type).
 : @error error:HC005 The request element is not valid.
 : @error error:HC006 A timeout occurred waiting for the response.
 :)
declare %ann:nondeterministic function http:get-binary($href as xs:string) as item()+
{
  http:http-nondeterministic-impl(validate {<http-schema:request method="GET" href="{$href}" follow-redirect="true" override-media-type="binary"/>}, (), ())
};

(:~
 : Makes a HTTP HEAD request.
 :
 : @param $href The URL to which the request will be made.
 : @return A element which describes the result of this request. A http HEAD
 :         request never returns a body.
 : @error error:HC001 An HTTP error occurred.
 : @error error:HC002 Error parsing the entity content as XML or HTML.
 : @error error:HC003 With a multipart response, the override-media-type must be either a multipart media type or application/octet-stream.
 : @error error:HC004 The src attribute on the body element is mutually exclusive with all other attribute (except the media-type).
 : @error error:HC005 The request element is not valid.
 : @error error:HC006 A timeout occurred waiting for the response.
 :)
declare %ann:nondeterministic function http:head($href as xs:string) as item() {
  http:http-nondeterministic-impl(
    validate {
      <http-schema:request method="HEAD" href="{$href}">
      </http-schema:request>
    }, (), ())
};

(:~
 : Makes a HTTP OPTIONS request.
 :
 : This request ask for OPTIONS supported of the server.
 :
 : @param $href The URL where to send the request.
 : @return A sequence of string with the allowed operations
 : @error error:HC001 An HTTP error occurred.
 : @error error:HC002 Error parsing the entity content as XML or HTML.
 : @error error:HC003 With a multipart response, the override-media-type must be either a multipart media type or application/octet-stream.
 : @error error:HC004 The src attribute on the body element is mutually exclusive with all other attribute (except the media-type).
 : @error error:HC005 The request element is not valid.
 : @error error:HC006 A timeout occurred waiting for the response.
 :)
declare %ann:nondeterministic function http:options($href as xs:string) as xs:string* {
  let $resp := http:http-nondeterministic-impl(
    validate {
      <http-schema:request method="OPTIONS" href="{$href}">
      </http-schema:request>
    }, (), ())[1]
  return
    fn:tokenize(fn:data($resp/http-schema:header[@name = "Allow"]/@value), ",")
};


(:~
 : Makes a HTTP PUT request.
 :
 : @param $href The URL where to send the request.
 : @param $body The body which will be sent to the server
 : @return The first element of the result is the metadata (like
 :         headers, status etc), the next elements are the response
 : @error error:HC001 An HTTP error occurred.
 : @error error:HC002 Error parsing the entity content as XML or HTML.
 : @error error:HC003 With a multipart response, the override-media-type must be either a multipart media type or application/octet-stream.
 : @error error:HC004 The src attribute on the body element is mutually exclusive with all other attribute (except the media-type).
 : @error error:HC005 The request element is not valid.
 : @error error:HC006 A timeout occurred waiting for the response.
 :)
declare %ann:sequential function http:put($href as xs:string, $body as item()) as item()+
{
  variable $media-type as xs:string+ :=
    typeswitch($body)
      case xs:string return ("text/plain","text")
      case element() return ("text/xml", "xml")
      default return ("text/plain","xml");

  variable $result := http:put($href, $body, $media-type[1]);

  $result
};

(:~
 : Makes a HTTP PUT request. This function takes the content type as a third parameter.
 : Note that this content type is used to determine the serialization, if the second
 : argument is an element node. If this automatic process does not work, use fn:serialize
 : instead.
 :
 : @param $href The URL where to send the request.
 : @param $body The body which will be sent to the server
 : @param $content-type The content type of the body.
 : @return The first element of the result is the metadata (like
 :         headers, status etc), the next elements are the response
 : @error error:HC001 An HTTP error occurred.
 : @error error:HC002 Error parsing the entity content as XML or HTML.
 : @error error:HC003 With a multipart response, the override-media-type must be either a multipart media type or application/octet-stream.
 : @error error:HC004 The src attribute on the body element is mutually exclusive with all other attribute (except the media-type).
 : @error error:HC005 The request element is not valid.
 : @error error:HC006 A timeout occurred waiting for the response.
 :)
declare %ann:sequential function http:put($href as xs:string, $body as item(), $content-type as xs:string) as item()+
{
  variable $method :=
    typeswitch ($body)
      case element() return
        if ($content-type = ("text/xml", "application/xml",
                                         "text/xml-external-parsed-entity",
                                         "application/xml-external-parsed-entity")
          or fn:ends-with($content-type, "+xml")) then
            "xml"
        else if (fn:starts-with($content-type, "text/html")) then
          "html"
        else if (fn:starts-with($content-type, "text/")) then
          "text"
        else
          "binary"
      case xs:base64Binary return "binary"
      default return "text";

  variable $result := http:http-sequential-impl(validate {
    <http-schema:request href="{$href}" method="PUT">
      <http-schema:body media-type="{$content-type}" method="{$method}">{$body}</http-schema:body>
    </http-schema:request>}
    , (), ());

  $result
};

(:~
 : Makes a HTTP DELETE request.
 :
 : @param $href The URL where to send the request.
 : @return The first element of the result is the metadata (like
 :         headers, status etc), the next elements are the response
 : @error error:HC001 An HTTP error occurred.
 : @error error:HC002 Error parsing the entity content as XML or HTML.
 : @error error:HC003 With a multipart response, the override-media-type must be either a multipart media type or application/octet-stream.
 : @error error:HC004 The src attribute on the body element is mutually exclusive with all other attribute (except the media-type).
 : @error error:HC005 The request element is not valid.
 : @error error:HC006 A timeout occurred waiting for the response.
 :)
declare %ann:sequential function http:delete($href as xs:string) as item()+
{
  http:http-nondeterministic-impl(
    validate {
      <http-schema:request method="DELETE" href="{$href}">
      </http-schema:request>
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
 : @error error:HC001 An HTTP error occurred.
 : @error error:HC002 Error parsing the entity content as XML or HTML.
 : @error error:HC003 With a multipart response, the override-media-type must be either a multipart media type or application/octet-stream.
 : @error error:HC004 The src attribute on the body element is mutually exclusive with all other attribute (except the media-type).
 : @error error:HC005 The request element is not valid.
 : @error error:HC006 A timeout occurred waiting for the response.
 :)
declare %ann:sequential function http:post($href as xs:string, $body as item()) as item()+
{
  variable $media-type as xs:string :=
    typeswitch($body)
      case xs:string return "text/plain"
      case element() return "text/xml"
      default return "text/plain";

  variable $result := http:post($href, $body, $media-type);

  $result
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
 : @param $content-type The content type of the body.
 : @return The first element of the result is the metadata (like
 :         headers, status etc), the next elements are the response
 : @error error:HC001 An HTTP error occurred.
 : @error error:HC002 Error parsing the entity content as XML or HTML.
 : @error error:HC003 With a multipart response, the override-media-type must be either a multipart media type or application/octet-stream.
 : @error error:HC004 The src attribute on the body element is mutually exclusive with all other attribute (except the media-type).
 : @error error:HC005 The request element is not valid.
 : @error error:HC006 A timeout occurred waiting for the response.
 :)
declare %ann:sequential function http:post($href as xs:string, $body as item(), $content-type as xs:string) as item()+
{
  variable $method :=
    typeswitch ($body)
      case element() return
        if ($content-type = ("text/xml", "application/xml",
                                         "text/xml-external-parsed-entity",
                                         "application/xml-external-parsed-entity")
          or fn:ends-with($content-type, "+xml")) then
            "xml"
        else if (fn:starts-with($content-type, "text/html")) then
          "html"
        else if (fn:starts-with($content-type, "text/")) then
          "text"
        else
          "binary"
      case xs:base64Binary return "binary"
      default return "text";

  variable $result := http:http-sequential-impl(validate {
    <http-schema:request href="{$href}" method="POST">
      <http-schema:body media-type="{$content-type}" method="{$method}">{$body}</http-schema:body>
    </http-schema:request>}
    , (), ());

  $result
};

declare %private %ann:sequential function http:http-sequential-impl(
  $request as schema-element(http-schema:request)?,
  $href as xs:string?,
  $bodies as item()*) as item()+ external;


declare %private %ann:nondeterministic function http:http-nondeterministic-impl(
  $request as schema-element(http-schema:request)?,
  $href as xs:string?,
  $bodies as item()*) as item()+ external;



(:~
 : This function takes an http-schema:body element, copies it, and
 : adds a method attribute to the copy if there is none
 : in the original element.
 :
 : @param $body is the original http-schema:body element
 : @return a http-schema:body element with a corresponding <code>@method</code>
 :   attribute 
 :)
declare %private function http:create-body (
  $body as element(http-schema:body))
    as element(http-schema:body) {
  <http-schema:body>{$body/@*}
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
  </http-schema:body>
};

(:~
 : This function takes an http-schema:multipart element, copies it and
 : adds a @method attribute to all body elements which don't have
 : one.
 :
 : @param $multipart the original http-schema:multipart
 : @return a copy of $multipart with all $multipart/body/@method set 
 :)
declare %private function http:create-multipart (
  $multipart as element(http-schema:multipart))
    as element(http-schema:multipart) {
    <http-schema:multipart>{$multipart/@*}
    {
    for $x in $multipart/node()
    return
      typeswitch($x)
        case element(http-schema:body) return http:create-body($x)
        default return $x
    }
    </http-schema:multipart>
};


(:~
 : This adds a default method attribute to all body elements which
 : don't contain a method attribute.
 :
 : @param $request The request which need to be copied.
 : @return A copy of $request with all request//body/@method set.
 :)
declare %private function http:set-content-type(
  $request as element(http-schema:request)?)
    as element(http-schema:request)? {
  if ($request) then
    <http-schema:request>{$request/@*}
    {
    for $x in $request/node()
    return
      typeswitch($x)
        case element(http-schema:body) return http:create-body($x)
        case element(http-schema:multipart) return http:create-multipart($x)
        default return $x
    }
    </http-schema:request>
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
  $request as element(http-schema:request)?,
  $href as xs:string?,
  $bodies as item()*) as xs:boolean {
  let $multipart := $request/http:multipart
  let $override := $request/@override-media-type/data(.)
  let $should-be-empty :=
    for $x in $request//http-schema:body
    return
      if ($x/@src and fn:not((fn:count($x/@*) eq 2))) then 1
      else ()
  return
    if (fn:empty($href) and fn:empty($request)) then
      fn:error($error:HC005, "The request element is not valid.")
    else if ($href eq "") then
      fn:error($error:HC005,
        "The request element is not valid.")
    else if (not(count($request//http-schema:body[not(exists(node())) and not(exists(@src))]) eq count($bodies))) then
      fn:error($error:HC005,
        "The request element is not valid.")
    else if ($should-be-empty) then
      fn:error($error:HC004, "The src attribute on the body element is mutually exclusive with all other attribute (except the media-type).")
    else
      fn:true()
};
