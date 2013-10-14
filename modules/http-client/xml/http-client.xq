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
 : <h1>Introduction</h1>
 : <p>
 : This module provides provides simple functions for performing HTTP requests
 : (GET, POST, DELETE etc.), as well as a more flexible general
 : purpose function (<a href="#send-request-3">send-request()</a>).
 : </p>
 :
 : <h1>Examples of how to use this module</h1>
 :
 : <h4>Simple GET Request</h4>
 :
 : <pre class="ace-static" ace-mode="xquery">
 : import module namespace http="http://www.zorba-xquery.com/modules/http-client";
 : declare namespace svg="http://www.w3.org/2000/svg";
 : http:get("http://www.w3.org/Graphics/SVG/svglogo.svg")[2]/svg:svg/svg:title
 : </pre>
 :
 : <p>
 : This example downloads an XML resource from the web (in this case,
 : an SVG file, which is an XML-based image format) and returns it as
 : a document node. Since the XML is in a namespace, we declare that
 : namespace; we can then perform a path expression directly on the
 : return value of http:get().
 : </p>
 : 
 : <h4>Simple GET Request (retrieving XHTML)</h4>
 : 
 :   <pre class="ace-static" ace-mode="xquery">
 :   import module namespace http="http://www.zorba-xquery.com/modules/http-client";
 :   declare namespace xhtml="http://www.w3.org/1999/xhtml";
 : 
 :   http:get-node( "http://www.w3.org" )[2]//xhtml:body
 :   </pre>
 : 
 : <p>
 : This example shows how to retrieve an XHTML resource. XHTML is
 : XML, so the http:get-node() function will return it as a document node
 : and you can operate on it with the full power of XQuery. As above, since this
 : XML is in a particular namespace, the above query defines that namespace
 : with the prefix "xhtml" so it can easily perform path expressions, etc.
 : </p>
 :
 : <p>
 : Note: many webservers, include www.w3.org, return XHTML with the
 : HTTP Content-Type "text/html". Zorba cannot assume that "text/html"
 : is actually XHTML, and so http:get() would have returned raw text
 : rather than a document node. That is why the example above uses
 : http:get-node(), which overrides the server's Content-Type and tells
 : Zorba to attempt to parse the result as XML.
 : </p>
 : 
 : <h4>Simple GET Request (retrieving HTML as text)</h4>
 : 
 : <p>
 : Note that XQuery does <b>not</b> understand plain HTML, and so if the URL
 : you retrieve contains plain HTML data (not XHTML), it will be treated as
 : plain text as shown in the next example. If you want to operate on the HTML
 : with XQuery, you should use the HTML language module which can transform
 : HTML to XHTML. The HTML module is supported by the Zorba team, but it is
 : not a "core module", meaning that it is not shipped with every Zorba
 : installation and may not be available. See
 : <a href="http://www.zorba-xquery.com/site2/html/downloads.html">the Zorba downloads
 : page</a> for information about obtaining this module if you do not
 : have it.</p>
 : 
 : <pre class="ace-static" ace-mode="xquery">
 : import module namespace http="http://www.zorba-xquery.com/modules/http-client";
 : http:get("http://www.example.com")[2]
 : </pre>
 : 
 : returns
 : 
 :   <pre class="ace-static" ace-mode="xml">
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
 : <p>Note that the response data above is a simple
 : xs:string value containing the HTML data, not actual XML data. If you
 : executed the above query using the Zorba command-line client, you would
 : have actually seen data like the following:</p>
 :
 : <pre class="ace-static" ace-mode="xml">
 :   &amp;lt;!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"&amp;gt;
 :   &amp;lt;html&amp;gt;
 :      ...
 : </pre>
 :
 : <p>because Zorba would attempt to serialize it as XML data, and would
 : escape all the raw angle brackets in the original xs:string.</p>
 :
 : <h4>Simple POST Request</h4>
 : 
 : <p>
 : Here is a simple example which sends text content by making an HTTP POST
 : request.
 : </p>
 : 
 : <pre class="ace-static" ace-mode="xquery">
 : import module namespace http="http://www.zorba-xquery.com/modules/http-client";
 : http:post( "...", "Hello World" )
 : </pre>
 :
 : <h1 id="standard_return">Return Values</h1>
 : 
 : <p>Most functions in this module (all except
 : <a href="#options-1">options()</a>) return one or more items.
 : (<a href="#head-1">head()</a> returns exactly one.) For all of these,
 : the first item returned will be a &lt;http-schema:response&gt;
 : element, as seen in the examples above. This element has "status" and
 : "message" attributes, representing the result of the HTTP call. It
 : also has any number of &lt;http-schema:header&gt; child elements that
 : encode the HTTP headers returned by the HTTP server. Finally, it
 : will generally contain a &lt;http-schema:body&gt; child element with
 : a "media-type" attribute that identifies the content-type of the
 : result data.</p>
 : 
 : <p>The full schema of this &lt;http-schema:response&gt; element is
 : part of the <a href="http://expath.org/modules/http-client/">EXPath
 : HTTP Client module</a>. You can see the schema
 : <a href="schemas/expath.org_ns_http-client.html">here</a>.</p>
 : 
 : <p>Any items in function return values after the initial
 : &lt;http-schema:response&gt; element are the body/bodies of the HTTP
 : response from the server. (MIME Multi-part responses will have
 : more than one body.) The type of these items depends on the 
 : Content-Type for each body. Each item will be:</p>
 : 
 : <ul>
 :  <li>
 :    an element node, if the returned content type is one of:
 :    <ul>
 :      <li>text/xml</li>
 :      <li>application/xml</li>
 :      <li>text/xml-external-parsed-entity</li>
 :      <li>application/xml-external-parsed-entity</li>
 :      <li>or if the Content-Type ends with "+xml".</li>
 :    </ul>
 :  </li>
 :  <li>
 :    an xs:string, if the returned content type starts with "text/" 
 :    and does not match the above XML content types strings, or if
 :    it is one of:
 :    <ul> 
 :      <li>"application/json"</li>
 :      <li>"application/x-javascript"</li>
 :    </ul>
 :  </li>
 :  <li>xs:base64Binary for all other content types.</li>
 : </ul>
 : 
 : <p>This return value - a sequence of items comprising one
 : &lt;http-schema:response&gt; element followed by zero or more
 : response items - is referred to as the "standard http-client 
 : return type" in the function declarations below.</p>
 :
 : <h1 id="url_string">$href Arguments to Functions</h1>
 :
 : All functions in this module accept a URL argument named $href. In
 : all cases, the value passed to $href must be a valid xs:anyURI.
 : However, all functions declare $href to be of type xs:string. This
 : is for convenience, since you can pass a string literal value (that
 : is, a URL in double-quotes spelled out explicitly in your query)
 : to an xs:string parameter.
 : 
 : <h1 id="get_warning">Important Notice Regarding get() Functions</h1>
 : 
 : All of the get() functions in this module -
 : <a href="#get-1">get()</a>, <a href="#get-node-1">get-node()</a>,
 : <a href="#get-text-1">get-text()</a>, and
 : <a href="#get-binary()">get-binary()</a> - are declared to be
 : <i>nondeterministic</i>, which means that Zorba will not cache
 : their results. However, they are <b>not</b> declared to be
 : <i>sequential</i>, which means that Zorba may re-order them
 : as part of its query optimization. According to the HTTP RFC,
 : GET requests should only return data, and should not have any
 : side-effects. However, in practice it is not uncommon for GET
 : requests to have side-effects. If your application depends on
 : the ordering of side-effects from making GET requests, you should
 : either use the more complex <a href="#send-request-3">send-request()</a>
 : function (which <b>is</b> declared <i>sequential</i>), or alterately
 : wrap each call to get() in your own sequential function, to ensure
 : that Zorba does not place the GET requests out of order.
 : 
 : <h1 id="expath_relation">Relation to the EXPath http-client module</h1>
 : 
 : <a href="http://expath.org/">EXPath</a> defines its own http-client
 : module, which is available separately for Zorba as a non-core module.
 : There are two primary differences between EXPath's http-client and
 : Zorba's core http-client (this module):
 : 
 : <ol>
 :   <li>EXPath defines only the send-request() function, although it
 : does include convenient 1- and 2-argument forms in addition to the
 : full 3-argument form. EXPath does not include the simpler get(),
 : post(), put(), delete(), head(), and options() functions defined by
 : this module.</li>
 :   <li>EXPath specifies that all HTML content returned from the
 : HTTP server will be <i>tidied up</i> into valid XML, and then parsed
 : into an element. As this required an additional third-party library
 : dependency, Zorba's http-client module does not perform this tidying.
 : Instead, HTML content is returned as a string (with special XML
 : characters replaced with XML entity references, as shown in the
 : above examples).</li>
 : </ol>
 : 
 : See <a href="http://www.expath.org/spec/http-client">the full spec
 : of the EXPath http-client module</a> for more information.
 : 
 : 
 : @author Markus Pilman, Federico Cavalieri
 : @see <a href="http://www.w3.org/TR/xquery-11/#FunctionDeclns">XQuery 1.1: Function Declaration</a>
 : @library <a href="http://curl.haxx.se/">cURL Library</a>
 : @project Zorba/Input Output/HTTP Client
 :)
module namespace http = "http://www.zorba-xquery.com/modules/http-client";

import module namespace error = "http://expath.org/ns/error";
import module namespace json-http = "http://zorba.io/modules/http-client";
import module namespace http-wrapper = "http://zorba.io/modules/http-client-wrapper";
import module namespace libjn = "http://jsoniq.org/function-library";

import schema namespace http-schema = "http://expath.org/ns/http-client";

declare namespace an = "http://zorba.io/annotations";
declare namespace ver = "http://zorba.io/options/versioning";
declare namespace err = "http://www.w3.org/2005/xqt-errors";
declare namespace ser  = "http://www.w3.org/2010/xslt-xquery-serialization";
declare namespace jn = "http://jsoniq.org/functions";

declare option ver:module-version "2.0";

(:~
 : This function sends an HTTP request and returns the corresponding response.
 : Its inputs, outputs, and behavior are identical to the
 : <a href="http://expath.org/spec/http-client">EXPath http-client</a>'s
 : send-request() function (except that HTML responses are not tidied
 : into XML - see <a href="#expath_relation">the note above</a>). It
 : is provided here for use in Zorba installations that do not have
 : the EXPath module available. If you have the option of using the 
 : EXPath module instead of this function, please do so, as it will
 : allow your application to be more interoperable between different
 : XQuery engines.
 :
 : Full documentation of the $request parameter can be found in
 : <a href="http://expath.org/spec/http-client#d2e183">the EXPath
 : specification</a>.
 :
 : @param $request Contains the various parameters of the request (see above).
 : @param $href The URL to which the request will be made (see
 :  <a href="#url_string">note</a> above). If this
 :  parameter is specified, it will override the "href" attribute of
 :  $request.
 : @param $bodies is the request body content, for HTTP methods that can
 :  contain a body in the request (i.e. POST and PUT). It is an error if this
 :  param is not the empty sequence for methods 
 : @return <a href="#standard_return">standard http-client return type</a>.
 : @error error:HC001 An HTTP error occurred.
 : @error error:HC002 Error parsing the response content as XML.
 : @error error:HC003 With a multipart response, the override-media-type must be either a multipart media type or application/octet-stream.
 : @error error:HC004 The src attribute on the body element is mutually exclusive with all other attribute (except the media-type).
 : @error error:HC005 The input request element is not valid.
 : @error error:HC006 A timeout occurred waiting for the response.
 : @error error:HCV02 Trying to follow a redirect of a POST, PUT, or DELETE request
 :
 : @example test/rbkt/Queries/zorba/http-client/xml/send-request/send-request_href.xq
 : @example test/rbkt/Queries/zorba/http-client/xml/send-request/http3-post.xq
 :)
declare %an:sequential function http:send-request(
  $request as element(http-schema:request)?,
  $href as xs:string?,
  $bodies as item()*) as item()+ 
{
  http-wrapper:http-sequential-request($request, $href, $bodies)  
};



(:~
 : This function makes a GET request to a given URL.
 :
 : @see <a href="#get_warning">Notice about get() functions</a>
 : @param $href The URL to which the request will be made (see
 :  <a href="#url_string">note</a> above).
 : @return <a href="#standard_return">standard http-client return type</a>.
 : @error error:HC001 An HTTP error occurred.
 : @error error:HC002 Error parsing the response content as XML.
 : @error error:HC006 A timeout occurred waiting for the response.
 :
 : @example test/rbkt/Queries/zorba/http-client/xml/get/get_text.xq
 :)
declare %an:nondeterministic function http:get($href as xs:string) as item()+
{
  http-wrapper:http-nondeterministic-request(validate {<http-schema:request method="GET" href="{$href}" follow-redirect="true"/>}, (), ())
};

(:~
 : This function makes a GET request to a given URL. All returned bodies
 : are forced to be interpreted as XML and parsed into elements.
 :
 : @see <a href="#get_warning">Notice about get() functions</a>
 : @param $href The URL to which the request will be made (see
 :  <a href="#url_string">note</a> above).
 : @return <a href="#standard_return">standard http-client return type</a>.
 : @error error:HC001 An HTTP error occurred.
 : @error error:HC002 Error parsing the response content as XML.
 : @error error:HC006 A timeout occurred waiting for the response.
 :
 : @example test/rbkt/Queries/zorba/http-client/xml/get-node/get-node_xml_query.xq
 :)
declare %an:nondeterministic function http:get-node($href as xs:string) as item()+
{
  http-wrapper:http-nondeterministic-request(validate {<http-schema:request method="GET" href="{$href}" follow-redirect="true" override-media-type="text/xml; charset=utf-8"/>}, (), ())
};

(:~
 : This function makes a GET request to a given URL. All returned bodies
 : are forced to be interpreted as plain strings, and will be returned
 : as xs:string items.
 :
 : @see <a href="#get_warning">Notice about get() functions</a>
 : @param $href The URL to which the request will be made (see
 :  <a href="#url_string">note</a> above).
 : @return <a href="#standard_return">standard http-client return type</a>.
 : @error error:HC001 An HTTP error occurred.
 : @error error:HC002 Error parsing the response content as XML.
 : @error error:HC006 A timeout occurred waiting for the response.
 :
 : @example test/rbkt/Queries/zorba/http-client/xml/get-text/get-text_xml_query.xq 
 :)
declare %an:nondeterministic function http:get-text($href as xs:string) as item()+
{
  http-wrapper:http-nondeterministic-request(validate {<http-schema:request method="GET" href="{$href}" follow-redirect="true" override-media-type="text/plain; charset=utf-8"/>}, (), ())
};

(:~
 : This function makes a GET request on a given URL. All returned bodies
 : are forced to be interpreted as binary data, and will be returned
 : as xs:base64Binary items.
 :
 : @see <a href="#get_warning">Notice about get() functions</a>
 : @param $href The URL to which the request will be made (see
 :  <a href="#url_string">note</a> above).
 : @return <a href="#standard_return">standard http-client return type</a>.
 : @error error:HC001 An HTTP error occurred.
 : @error error:HC002 Error parsing the response content as XML.
 : @error error:HC006 A timeout occurred waiting for the response.
 :
 : @example test/rbkt/Queries/zorba/http-client/xml/get-binary/get-binary_xml_query.xq
 :)
declare %an:nondeterministic function http:get-binary($href as xs:string) as item()+
{
  http-wrapper:http-nondeterministic-request(validate {<http-schema:request method="GET" href="{$href}" follow-redirect="true" override-media-type="binary"/>}, (), ())
};

(:~
 : This function makes an HTTP HEAD request on a given URL.
 :
 : @param $href The URL to which the request will be made (see
 :  <a href="#url_string">note</a> above).
 : @return <a href="#standard_return">standard http-client return type</a>
 :  (since HEAD never returns any body data, only the
 :  &lt;http-schema:response&gt; element will be returned).
 : @error error:HC001 An HTTP error occurred.
 : @error error:HC006 A timeout occurred waiting for the response.
 :
 : @example test/rbkt/Queries/zorba/http-client/xml/head/head_status.xq
 :)
declare %an:nondeterministic function http:head($href as xs:string) as item() {
  http-wrapper:http-nondeterministic-request(
    validate {
      <http-schema:request method="HEAD" href="{$href}">
      </http-schema:request>
    }, (), ())
};

(:~
 : This function makes an HTTP OPTIONS request, which asks the server
 : which operations it supports.
 :
 : @param $href The URL to which the request will be made (see
 :  <a href="#url_string">note</a> above).
 : @return A sequence of xs:string values of the allowed operations.
 : @error error:HC001 An HTTP error occurred.
 : @error error:HC006 A timeout occurred waiting for the response.
 :
 : @example test/rbkt/Queries/zorba/http-client/xml/options/options.xq
 :)
declare %an:nondeterministic function http:options($href as xs:string) as xs:string* {
  let $resp := http-wrapper:http-nondeterministic-request(
    validate {
      <http-schema:request method="OPTIONS" href="{$href}">
      </http-schema:request>
    }, (), ())[1]
  return
    fn:tokenize(fn:data($resp/http-schema:header[@name = "Allow"]/@value), ",")
};


(:~
 : This function makes an HTTP PUT request to a given URL. If the body
 : passed to this function is an element, it will be serialized to XML
 : to be sent to the server, and the Content-Type sent to the server will
 : be "text/xml". Otherwise, the body will be converted to
 : a plain string, and the Content-Type will be "text/plain".
 :
 : @param $href The URL to which the request will be made (see
 :  <a href="#url_string">note</a> above).
 : @param $body The body which will be sent to the server.
 : @return <a href="#standard_return">standard http-client return type</a>.
 : @error error:HC001 An HTTP error occurred.
 : @error error:HC002 Error parsing the response content as XML.
 : @error error:HC006 A timeout occurred waiting for the response.
 : @error error:HCV02 Trying to follow a redirect of a PUT request.
 :
 : @example test/rbkt/Queries/zorba/http-client/xml/put/put2_element.xq
 :)
declare %an:sequential function http:put($href as xs:string, $body as item()) as item()+
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
 : This function makes an HTTP PUT request to a given URL. If the body
 : passed to this function is an element, it will be serialized 
 : according to the $content-type parameter as follows:
 : <ul>
 :  <li>If $content-type is "text/xml", "application/xml",
 : "text/xml-external-parsed-entity", or
 : "application/xml-external-parsed-entity", or if it ends with "+xml",
 : $body will be serialized to XML.</li>
 :  <li>If $content-type starts with "text/html", $body will be
 : serialized to HTML.</li>
 :  <li>Otherwise, $body will be serialized to text.</li>
 : </ul>
 : If $body is not an element, $body will be serialized to text
 : regardless of $content-type.
 :
 : <p>In any case, Content-Type of the request sent to the server will
 : be $content-type.</p>
 :
 : @param $href The URL to which the request will be made (see
 :  <a href="#url_string">note</a> above).
 : @param $body The body which will be sent to the server.
 : @param $content-type The content type of $body as described above.
 : @return <a href="#standard_return">standard http-client return type</a>.
 : @error error:HC001 An HTTP error occurred.
 : @error error:HC002 Error parsing the response content as XML.
 : @error error:HC006 A timeout occurred waiting for the response.
 : @error error:HCV02 Trying to follow a redirect of a PUT request.
 :
 : @example test/rbkt/Queries/zorba/http-client/xml/put/put3_html_br.xq
 :)
declare %an:sequential function http:put($href as xs:string, $body as item(), $content-type as xs:string) as item()+
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

  variable $result := http-wrapper:http-sequential-request(validate {
    <http-schema:request href="{$href}" method="PUT">
      <http-schema:body media-type="{$content-type}" method="{$method}">{$body}</http-schema:body>
    </http-schema:request>}
    , (), ());

  $result
};

(:~
 : This function makes an HTTP DELETE request to a given URL.
 :
 : @param $href The URL to which the request will be made (see
 :  <a href="#url_string">note</a> above).
 : @return <a href="#standard_return">standard http-client return type</a>.
 : @error error:HC001 An HTTP error occurred.
 : @error error:HC002 Error parsing the response content as XML.
 : @error error:HC006 A timeout occurred waiting for the response.
 : @error error:HCV02 Trying to follow a redirect of a DELETE request.
 :
 : @example test/rbkt/Queries/zorba/http-client/xml/delete/delete.xq
 :)
declare %an:sequential function http:delete($href as xs:string) as item()+
{
  http-wrapper:http-sequential-request(
    validate {
      <http-schema:request method="DELETE" href="{$href}">
      </http-schema:request>
    }, (), ())
};

(:~
 : This function makes an HTTP POST request to a given URL. If the body
 : passed to this function is an element, it will be serialized to XML
 : to be sent to the server, and the Content-Type sent to the server will
 : be "text/xml". Otherwise, the body will be converted to
 : a plain string, and the Content-Type will be "text/plain".
 :
 : @param $href The URL to which the request will be made (see
 :  <a href="#url_string">note</a> above).
 : @param $body The body which will be sent to the server.
 : @return <a href="#standard_return">standard http-client return type</a>.
 : @error error:HC001 An HTTP error occurred.
 : @error error:HC002 Error parsing the response content as XML.
 : @error error:HC006 A timeout occurred waiting for the response.
 : @error error:HCV02 Trying to follow a redirect of a POST request.
 :
 : @example test/rbkt/Queries/zorba/http-client/xml/post/post2_comment.xq
 :)
declare %an:sequential function http:post($href as xs:string, $body as item()) as item()+
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
 : This function makes an HTTP POST request to a given URL. If the body
 : passed to this function is an element, it will be serialized 
 : according to the $content-type parameter as follows:
 : <ul>
 :  <li>If $content-type is "text/xml", "application/xml",
 : "text/xml-external-parsed-entity", or
 : "application/xml-external-parsed-entity", or if it ends with "+xml",
 : $body will be serialized to XML.</li>
 :  <li>If $content-type starts with "text/html", $body will be
 : serialized to HTML.</li>
 :  <li>Otherwise, $body will be serialized to text.</li>
 : </ul>
 : If $body is not an element, $body will be serialized to text
 : regardless of $content-type.
 :
 : <p>In any case, Content-Type of the request sent to the server will
 : be $content-type.</p>
 :
 : @param $href The URL to which the request will be made (see
 :  <a href="#url_string">note</a> above).
 : @param $body The body which will be sent to the server
 : @param $content-type The content type of the body as described above.
 : @return The first element of the result is the metadata (like
 :         headers, status etc), the next elements are the response
 : @error error:HC001 An HTTP error occurred.
 : @error error:HC002 Error parsing the response content as XML.
 : @error error:HC006 A timeout occurred waiting for the response.
 : @error error:HCV02 Trying to follow a redirect of a POST request.
 :
 : @example test/rbkt/Queries/zorba/http-client/xml/post/post3_xml.xq
 :)
declare %an:sequential function http:post($href as xs:string, $body as item(), $content-type as xs:string) as item()+
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

  variable $result := http-wrapper:http-sequential-request(validate {
    <http-schema:request href="{$href}" method="POST">
      <http-schema:body media-type="{$content-type}" method="{$method}">{$body}</http-schema:body>
    </http-schema:request>}
    , (), ());

  $result
};
