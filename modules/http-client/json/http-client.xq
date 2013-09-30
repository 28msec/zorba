jsoniq version "1.0";

(:
 : Copyright 2006-2013 The FLWOR Foundation.
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
 : This module provides functions for performing HTTP requests.
 : </p>
 :
 : <h2>A simple GET request using the get#1 convenience function</h2>
 :
 : <pre class="ace-static" ace-mode="xquery">
 : import module namespace http="http://zorba.io/modules/http-client";
 : http:get("http://www.example.com")
 : </pre>
 :
 : <p>
 : This example makes a GET request to example.com and returns the server's response
 : as a JSON object.
 : </p>
 :
 : <pre class="ace-static" ace-mode="java">
 : {
 :   "status" : 200, 
 :   "message" : "OK", 
 :   "headers" : {
 :     "Content-Length" : "1270", 
 :     "Date" : "Tue, 11 Jun 2013 22:27:10 GMT", 
 :     ...
 :   }, 
 :   "body" : {
 :     "media-type" : "text/html", 
 :     "content" : "..."
 :   }
 : }
 : </pre>
 :
 : <h2 id="standard_return">Response format</h2>
 :
 : <p>Most functions in this module (all except <a href="#options-1">options#1</a>)
 : return a single JSON item, describing the server's response, as in the previous
 : example.
 : The server status (integer) and message (string) fields are always present.
 : If the server replied sending one or more headers, they are reported 
 : in an optional headers object. Each header is represented as a single (string) 
 : field.</p>
 :
 : <p>For non-multipart responses, as in the previous example, the response body, 
 : if any, is reported as a body object. This object contains both the (string) 
 : media-type returned by the server and its content.
 : The type of the content field is determined by the media-type returned by the
 : server. If the media-type indicates that the body content is textual,
 : then the content has type string, base64Binary otherwise. 
 : Specifically, the body content is considered textual only if the MIME-type specified in 
 : the media-type is one of:
 : <ul>
 :   <li>"application/json"</li>
 :   <li>"application/x-javascript"</li>
 :   <li>"application/xml"</li>
 :   <li>"application/xml-external-parsed-entity"</li>
 : </ul>
 : or if the MIME-type starts with "text/" or ends with "+xml".</p>
 :
 : <p>For multipart responses, multiple bodies are returned, as in the following example: </p> 
 :
 : <pre class="ace-static" ace-mode="java">
 : {
 :   "status" : 200, 
 :   "message" : "OK", 
 :   "headers" : { 
 :     "Date" : "Tue, 11 Jun 2013 22:34:13 GMT", 
 :     ...
 :   }, 
 :   "multipart" : {
 :     "boundary": "--AaB03x",  
 :     "parts": [
 :       {
 :         "headers" : {
 :            "Content Disposition: file",
 :            ...
 :         },
 :         "body": {
 :           "media-type" : "image/gif", 
 :           "content" : "..."
 :         }  
 :       },
 :       {
 :         "body" : {
 :           "media-type" : "text/html", 
 :           "content" : "..."
 :         }
 :       }
 :    ]
 : }
 : </pre>
 : 
 : <p>The multipart field contains both the boundary used to separate parts
 : and an array containing all parts. Each part contains its specific headers,
 : if any, and the corresponding body.</p>
 :
 : <h2 id="nondeterministic_warning">Important Notice Regarding Nondeterministic Functions</h2>
 : 
 : <p>
 : The following functions in this module -
 : <a href="#get-1">get#1</a>,
 : <a href="#get-text-1">get-text#1</a>,
 : <a href="#get-binary-1">get-binary#1</a>, 
 : <a href="#send-nondeterministic-request-1">send-nondeterministic-request-1</a>,
 : <a href="#head-1">head#1</a>, and
 : <a href="#options-1">options#1</a> 
 : are declared to be <i>nondeterministic</i>, which means that their results 
 : will not be cached. 
 : However, they are <b>not</b> declared to be
 : <i>sequential</i>, which means that they may be re-ordered during query optimization.
 : According to the HTTP RFC, GET, HEAD an OPTIONS requests should not have any side-effects. 
 : However, in practice it is not uncommon, especially for GET requests, to have side-effects. 
 : If your application depends on the ordering of side-effects from requests issued through
 : these functions, you should either use the <a href="#send-request-3">send-request()</a>
 : function (which is declared <i>sequential</i>), or alternatively
 : wrap each call to get() in your own sequential function, to ensure
 : that the requests are not reordered.
 : </p>
 :
 : <h2 id="url_string">$href Arguments to Functions</h2>
 :
 : <p>Several functions in this module accept a URL argument named $href. In
 : all cases, the value passed to $href must be a valid anyURI.
 : However, all functions declare $href to be of type string. This
 : is for convenience, since you can pass a string literal value (that
 : is, a URL in double-quotes spelled out explicitly in your query)
 : to an string parameter.</p>
 : 
 : <h2 id="expath_relation">Relation to the EXPath http-client module</h2>
 : 
 : <p><a href="http://expath.org/">EXPath</a> defines its own http-client
 : module, which is available separately.
 : There are two primary differences between EXPath's http-client and
 : this module:
 : 
 : <ol>
 :   <li>EXPath defines only the send-request() function, although it
 : does include convenient 1- and 2-argument forms in addition to the
 : full 3-argument form. EXPath does not include the simpler get(),
 : post(), put(), delete(), head(), and options() functions defined by
 : this module.</li>
 : <li>EXPath uses XML to represent request for its send-request() function, 
 : whereas this module uses JSON.</li>
 : <li>EXPath specifies that all XML content returned by an HTTP server
 : will be parsed and returned as an XML document, whereas all HTML content 
 : will be <i>tidied up</i> into valid XML, and then parsed into an element. 
 : This module returns any textual content as string and any binary content 
 : as base6Binary.</li>
 : <li>EXPath accepts XML nodes as body in the send-request() function and 
 : automatically serializes them into a string. The send-request() function
 : defined in this module only allows string, base64Binary, and hexBinary 
 : as body types.
 : </li>
 : </ol>
 : </p>
 :
 : <p>
 : See <a href="http://www.expath.org/spec/http-client">the full spec
 : of the EXPath http-client module</a> for more information.
 : </p>
 :
 : @author Federico Cavalieri
 : @see <a href="http://www.w3.org/TR/xquery-11/#FunctionDeclns">XQuery 1.1: Function Declaration</a> 
 : @library <a href="http://curl.haxx.se/">cURL Library</a>
 : @project Zorba/Input Output/HTTP Client
 :)
module namespace http = "http://zorba.io/modules/http-client";

import module namespace libjn = "http://jsoniq.org/function-library";

declare namespace an = "http://zorba.io/annotations";
declare namespace ver = "http://zorba.io/options/versioning";
declare namespace err = "http://www.w3.org/2005/xqt-errors";

declare option ver:module-version "1.0";

(:~
 : <p>
 : This function sends an HTTP request and returns the corresponding response.
 : </p>
 :
 : <p>
 : This function is declared as sequential and should be used whenever the 
 : request may have side-effects.
 : </p>
 :
 : <p>
 : The request parameters are specified in the $request JSON object, which 
 : has the following minimal structure:
 : 
 : <pre class="ace-static" ace-mode="java">
 :   {
 :     "href": "http://www.example.com"
 :   }
 : </pre>
 : </p>
 :
 : <p>This object specifies a GET request of the URI "http://www.example.com"</p> 
 :
 : <p>Additional optional parameters can be specified when issuing a request, 
 : using the following structure:</p>
 : <pre class="ace-static" ace-mode="java">
 :  {
 :    "method": "POST", 
 :    "href": "http://www.example.com",
 :    "authentication": 
 :    {
 :      "username" : "user",
 :      "password" : "pass",
 :      "auth-method" : "Basic"
 :    },
 :    "options": 
 :    {
 :      "status-only": true,
 :      "override-media-type": "text/plain",
 :      "follow-redirect": false,
 :      "timeout": 30,
 :      "user-agent": "Mozilla/5.0"
 :    },   
 :    "headers":
 :    {
 :      "name": "value",
 :      ...
 :    },    
 :    "body":
 :    {
 :      "media-type": "text/plain", 
 :      "content": "..." 
 :    }
 :  }
 :</pre>
 : <p>
 : The method field (string) defines the HTTP verb to use in the HTTP request (i.e., GET, HEAD, OPTIONS,
 : POST, PUT, DELETE). If not specified GET will be used. 
 : The authentication field can be used to specify the credentials and authentication method
 : used when issuing a request (e.g, Basic). If the authentication field is specified, all its (string) 
 : subfields must be specified. If an authentication object is provided, it overrides any 
 : Authorization header specified in the request. 
 : Additionally, the following options can be specified:
 : <ul>
 :    <li>status-only. If true, the response body contents are omitted from the response object.</li>
 :    <li>override-media-type. Is a MIME type that will override the Content-Type header returned
 :        by the server. It affects the type of the result body content.</li>
 :    <li>follow-redirect. Control whether an http redirect is automatically followed or not. If
 :        it is false, the http redirect is returned as the response. If it is
 :        true (the default) the function tries to follow the redirect, by
 :        sending the same request to the new address (including body, headers,
 :         and authentication credentials.) Maximum one redirect is followed
 :        (there is no attempt to follow a redirect in response to following a
 :          first redirect).</li>
 :    <li>timeout. Is the maximum number of seconds to wait for the server to respond. 
 :         If no response is received withing this time duration, an error is thrown.</li>
 :    <li>user-agent. The user agent sent to the server when issuing the request.
 :        If not specified libcurl-agent/1.0 is used.</li>
 : </ul>
 : </p>
 :
 : <p>One or more headers can be sent to the server, specifying them in an optional headers object. 
 : Each header is represented as a single (string) field. These headers are overridden if the corresponding
 : option/authentication has been specified in the request.</p>
 :
 : <p>For non-multipart request a body object can be specified. 
 : This object must contain both the desired (string) media-type and its content.
 : The type of the content field must be either string, base64Binary, or hexBinary. </p> 
 :
 : <p>For multipart requests, multipart object can be specified in place of the body object.
 : The multipart object has the following structure: </p> 
 :
 : <pre class="ace-static" ace-mode="java">
 :  "multipart" : {
 :    "boundary": "--AaB03x",  
 :    "parts": [
 :      {
 :        "headers" : {
 :           "Content Disposition: file",
 :           ...
 :        },
 :        "body": {
 :          "media-type" : "image/gif", 
 :          "content" : "..."
 :        }  
 :      },
 :      {
 :        "body" : {
 :          "media-type" : "text/html", 
 :          "content" : "..."
 :        }
 :      }
 :   ]
 : }
 : </pre>
 : 
 : <p>The multipart field contains an optional (string) field which specifies
 : the boundary used to separate each part and an array containing all parts. 
 : Each part contains its specific headers, if any, and the corresponding body.
 : </p>
 :
 :
 : @param $request a JSON http-client request object
 : @return <a href="#standard_return">standard http-client return type</a>.
 :
 : @error http:HTTP An HTTP error occurred.
 : @error http:REQUEST The specified request is not valid.
 : @error http:TIMEOUT A timeout occurred waiting for the response.
 : @error http:FOLLOW Cannot follow a redirect of a POST, PUT, or DELETE request.
 : @error http:CHARSET The specified charset is unsupported.
 :
 :)
declare %an:sequential function http:send-request($request as object) as object
{
  if (http:check-request($request))
  then http:http-sequential-impl($request)
  else ()   
};

(:~
 : <p> 
 : This function sends an HTTP request and returns the corresponding response.
 : </p>
 : <p>
 : This function has the same semantics of <a href="#send-request-1">send-request-1</a>, 
 : but is declared as nondeterministic and thus should only be used when
 : the request has no side-effects.
 : </p>
 :
 : @see <a href="#nondeterministic_warning">Notice about nondeterministic functions</a>
 : @param $request see request parameter of <a href="#send-request-1">send-request#1</a>
 : @return <a href="#standard_return">standard http-client return type</a>.
 :
 : @error http:HTTP An HTTP error occurred.
 : @error http:REQUEST The specified request is not valid.
 : @error http:TIMEOUT A timeout occurred waiting for the response.
 : @error http:FOLLOW Cannot follow a redirect of a POST, PUT, or DELETE request.
 : @error http:CHARSET The specified charset is unsupported.
 :)
declare %an:nondeterministic function http:send-nondeterministic-request($request as object) as object
{
  if (http:check-request($request))
  then http:http-nondeterministic-impl($request)
  else ()
};


(:~
 : <p>
 : This function makes a GET request to a given URL.
 : </p>
 :
 : @see <a href="#nondeterministic_warning">Notice about nondeterministic functions</a>
 : @param $href The URL to which the request will be made (see 
 :  <a href="#url_string">note</a> above).
 : @return <a href="#standard_return">standard http-client return type</a>.
 :
 : @error http:HTTP An HTTP error occurred.
 : @error http:REQUEST The specified href is not valid.
 : @error http:TIMEOUT A timeout occurred waiting for the response.
 :)
declare %an:nondeterministic function http:get($href as string) as object
{
  http:send-nondeterministic-request(
  {
    "method" : "GET",
    "href": $href
  })
};

(:~
 : <p>
 : This function makes a GET request to a given URL. All returned bodies
 : are forced to be interpreted as textual, with a UTF-8 charset and will
 : be returned as string items.
 : </p>
 :
 : @see <a href="#nondeterministic_warning">Notice about nondeterministic functions</a>
 : @param $href The URL to which the request will be made (see
 :  <a href="#url_string">note</a> above).
 : @return <a href="#standard_return">standard http-client return type</a>.
 :
 : @error http:HTTP An HTTP error occurred.
 : @error http:REQUEST The specified href is not valid.
 : @error http:TIMEOUT A timeout occurred waiting for the response.
 :
 :)
declare %an:nondeterministic function http:get-text($href as string) as object
{
  http:send-nondeterministic-request(
  {
    "method": "GET",
    "href": $href,
    "options": {
      "override-media-type": "text/plain; charset=utf-8"
    }
  })
};

(:~
 : <p>
 : This function makes a GET request on a given URL. All returned bodies
 : are forced to be interpreted as binary data, and will be returned
 : as base64Binary items.
 : </p>
 :
 : @see <a href="#nondeterministic_warning">Notice about nondeterministic functions</a>
 : @param $href The URL to which the request will be made (see
 :  <a href="#url_string">note</a> above).
 : @return <a href="#standard_return">standard http-client return type</a>.
 :
 : @error http:HTTP An HTTP error occurred.
 : @error http:REQUEST The specified href is not valid.
 : @error http:TIMEOUT A timeout occurred waiting for the response.
 :
 :)
declare %an:nondeterministic function http:get-binary($href as string) as object
{
  http:send-nondeterministic-request(
  {
    "method": "GET",
    "href": $href,
    "options": {
      "override-media-type": "binary"      
    }
  })
};

(:~
 : <p>
 : This function makes an HTTP HEAD request on a given URL.
 : </p>
 :
 : @see <a href="#nondeterministic_warning">Notice about nondeterministic functions</a>
 : @param $href The URL to which the request will be made (see
 :  <a href="#url_string">note</a> above).
 : @return <a href="#standard_return">standard http-client return type</a>.
 :
 : @error http:HTTP An HTTP error occurred.
 : @error http:REQUEST The specified href is not valid.
 : @error http:TIMEOUT A timeout occurred waiting for the response.
 :
 :)
declare %an:nondeterministic function http:head($href as string) as object 
{
  http:send-nondeterministic-request(
  {
    "method": "HEAD",
    "href": $href    
  })
};

(:~
 : <p>
 : This function makes an HTTP OPTIONS request, which asks the server
 : which operations it supports.
 : </p>
 :
 : @see <a href="#nondeterministic_warning">Notice about nondeterministic functions</a>
 : @param $href The URL to which the request will be made (see
 :  <a href="#url_string">note</a> above).
 : @return A sequence of string values of the allowed operations.
 :
 : @error http:HTTP An HTTP error occurred.
 : @error http:REQUEST The specified href is not valid.
 : @error http:TIMEOUT A timeout occurred waiting for the response.
 :
 :)
declare %an:nondeterministic function http:options($href as string) as string* 
{
  let $resp := http:send-nondeterministic-request(
    {
      "method": "OPTIONS",
      "href": $href      
    })[1]
  return
    fn:tokenize($resp.headers.Allow, ",")
};


(:~
 : <p>
 : This function makes an HTTP PUT request to a given URL.
 : </p>
 : <p>
 : The body passed to this function must be either a string, a base64Binary or 
 : an hexBinary.
 : If it is a string, the Content-Type sent to the server will be "text/plain",
 : "application/octet-stream" otherwise.
 : </p>
 :
 : @param $href The URL to which the request will be made (see
 :  <a href="#url_string">note</a> above).
 : @param $body The body which will be sent to the server.
 : @return <a href="#standard_return">standard http-client return type</a>.
 :
 : @error http:HTTP An HTTP error occurred.
 : @error http:REQUEST The specified request is not valid.
 : @error http:TIMEOUT A timeout occurred waiting for the response.
 :
 :)
declare %an:sequential function http:put($href as string, $body as atomic) as object
{
  variable $media-type as string :=
    typeswitch($body)
      case string return "text/plain"
      case base64Binary return "application/octet-stream"
      case hexBinary return "application/octet-stream"
      default return fn:error(QName("http:REQUEST"), "The specified request is not valid. The type of the request body must be string, base64Binary, or hexBinary.");
  http:put($href, $body, $media-type)
};

(:~
 : <p>
 : This function makes an HTTP PUT request to a given URL.
 : </p>
 : <p>
 : The body passed to this function must be either a string, a base64Binary, or
 : an hexBinary.
 : In any case, Content-Type of the request sent to the server will
 : be $content-type.
 : </p>
 :
 : @param $href The URL to which the request will be made (see
 :  <a href="#url_string">note</a> above).
 : @param $body The body which will be sent to the server.
 : @param $content-type The content type of $body to send to the server.
 : @return <a href="#standard_return">standard http-client return type</a>.
 :
 : @error http:HTTP An HTTP error occurred.
 : @error http:REQUEST The specified request is not valid.
 : @error http:TIMEOUT A timeout occurred waiting for the response.
 : @error http:CHARSET The specified charset is unsupported.
 : 
 :)
declare %an:sequential function http:put($href as string, $body as atomic, $content-type as string) as object
{
  http:send-request(
  {
    "method": "PUT",
    "href": $href,
    "body": {
      "media-type": $content-type,
      "content": $body
    }
  })
};

(:~
 : <p>
 : This function makes an HTTP DELETE request to a given URL.
 : </p>
 :
 : @param $href The URL to which the request will be made (see
 :  <a href="#url_string">note</a> above).
 : @return <a href="#standard_return">standard http-client return type</a>.
 :
 : @error http:HTTP An HTTP error occurred.
 : @error http:REQUEST The specified request is not valid.
 : @error http:TIMEOUT A timeout occurred waiting for the response.
 :
 :)
declare %an:sequential function http:delete($href as string) as object
{
  http:send-request(
  {
      "method": "DELETE",
      "href": $href      
  })
};

(:~
 : <p>
 : This function makes an HTTP POST request to a given URL.
 : </p>
 : <p> 
 : The body passed to this function must be either a string, a base64Binary, or an 
 : hexBinary.
 : If it is a string, the Content-Type sent to the server will be "text/plain",
 : "application/octet-stream" otherwise.
 : </p>
 :
 : @param $href The URL to which the request will be made (see
 :  <a href="#url_string">note</a> above).
 : @param $body The body which will be sent to the server.
 : @return <a href="#standard_return">standard http-client return type</a>.
 :
 : @error http:HTTP An HTTP error occurred.
 : @error http:REQUEST The specified request is not valid.
 : @error http:TIMEOUT A timeout occurred waiting for the response.
 : 
 :)
declare %an:sequential function http:post($href as string, $body as atomic) as object
{
  variable $media-type as string :=
    typeswitch($body)
      case string return "text/plain"
      case base64Binary return "application/octet-stream"
      case hexBinary return "application/octet-stream"
      default return fn:error(QName("http:REQUEST"), "The specified request is not valid. The type of the request body must be string, base64Binary, or hexBinary.");

  http:post($href, $body, $media-type)
};

(:~
 : <p>
 : This function makes an HTTP POST request to a given URL.
 : </p>
 : <p> 
 : The body passed to this function must be either a string, a base64Binary, 
 : or an hexBinary.
 : In any case, Content-Type of the request sent to the server will
 : be $content-type.
 : </p>
 :
 : @param $href The URL to which the request will be made (see
 :  <a href="#url_string">note</a> above).
 : @param $body The body which will be sent to the server
 : @param $content-type The content type of the body as described above.
 : @return <a href="#standard_return">standard http-client return type</a>.
 :
 : @error http:HTTP An HTTP error occurred.
 : @error http:REQUEST The specified request is not valid.
 : @error http:TIMEOUT A timeout occurred waiting for the response.
 : @error http:CHARSET The specified charset is unsupported.
 :
 :)
declare %an:sequential function http:post($href as string, $body as atomic, $content-type as string) as object
{
  http:send-request(
  {
    "method": "POST",
    "href": $href,
    "body": {
      "media-type": $content-type,
      "content": $body
    }
  })  
};


(:~
 : Private function used internally by this module.
 :
 : This function checks if the request, href, and bodies parameters
 : are consistent.
 : 
 : @error http:REQUEST The specified request is not valid.
 :)
declare %private function http:check-request($request as object) as boolean
{  
  for $body in libjn:descendant-objects($request).body
  return
  (
    if (exists($body.src) and exists($body.content))
    then fn:error(QName("http:REQUEST"), "The specified request is not valid. The src and content fields are mutually exclusive.")
    else (),
    if (exists($body.content))
    then 
      typeswitch($body.content)
      case string return ()
      case base64Binary return ()
      case hexBinary return ()
      default return fn:error(QName("http:REQUEST"), "The specified request is not valid. The type of the body content must be string, base64Binary, or hexBinary.")
    else ()    
  ),    
  if (count(libjn:descendant-objects($request).body[exists($$.src) and exists($$.content)]) gt 1)
  then fn:error(QName("http:REQUEST"), "The specified request is not valid. The src and content fields are mutually exclusive.")
  else if (exists($request.href) and not($request.href castable as anyURI))
       then fn:error(QName("http:REQUEST"), "he specified request is not valid. The specified href is not a valid anyURI.")
       else (),
  fn:true()
};

declare %private %an:sequential function http:http-sequential-impl($request as object) as object external;

declare %private %an:nondeterministic function http:http-nondeterministic-impl($request as object) as object external;
