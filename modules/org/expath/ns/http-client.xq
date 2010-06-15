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
 : The module basically defines a single function, <code>http:send-request()</code>
 : (with several arities for the sake of ease of use.) In general, the function
 : takes a description of the request as parameter, executes an HTTP request,
 : and returns a representation of the HTTP response.
 : </p>
 :
 : <p>
 : The request is represented by an http:request element, giving the URI,
 : the HTTP method, the headers and the body content (for POST and PUT methods.)
 : The response is returned as a sequence of one or more items. The first
 : one is an http:response element with quite the same structure as an http:request,
 : but without the content itself. The content is returned as the second item
 : (or several items in case of a multipart response) as a string, a
 : document node or a binary item, depending on the Content-Type returned by the
 : server. Here is a simple example of call in XQuery, which sends a text content by POST:
 : </p>
 :
 : <code>
 :   <pre>
 :   http:send-request(
 :      http:request href="..." method="post">
 :         &lt;http:body content-type="text/plain">
 :            Hello, world!
 :         &lt;/http:body>
 :      &lt;/http:request>
 :   )
 :   </pre>
 : </code>
 :
 : The response element can look like the following:
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
 : by this module. Moreover, the details are described in the
 : <a href="http://expath.org/modules/http-client.html#d2e183">specification</a>.
 : Analogously, the response element is also described in this
 : <a href="http://expath.org/modules/http-client.html#d2e483">specification</a>.
 : </p>

 : <p>
 : If the content type of a response is html, http-client will tidy it automatically.
 : If you want to prevent that, you can also set your own content-type by setting the
 : override-media-type attribute in the request element.
 : For tidying, the following <a href="http://tidy.sourceforge.net/docs/quickref.html">options</a>
 : will be used:
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
 : Please note, that this module is an extension to the module specified
 : by EXPath because it adds some convenience functions and send-request
 : functions that are declared as deterministic and nondeterministic
 : (see XQuery 1.1), respectively.
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
 : http:send-request($request, (), ())
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
 : This function is <b>not</b> declared as sequential.
 : That is, the query processor is free to optimize invocations of this
 : function. For example, a call to this function within a for expression
 : could be hoisted outside of the for because it assumes that every
 : invocation of the function (with the same parameters) has the same result
 : (in particular it doesn't have any side effects). Usually, this
 : function will be used for retrieving resources using HTTP GET or HEAD
 : which are known to not change during the execution of the query.
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
 :
 : The result of this function is equal to calling the send-request function
 : as follows:
 :
 : <code>
 : http:send-request-deterministic($request, $href, ())
 : </code>
 :
 : @see documentation of <a href="#send-request-deterministic-3">send-request-deterministic</a>
 :      with three parameters.
 :
 : @param $request see parameter $request of the deterministic
 :  <a href="#send-request-deterministic-3">send-request-deterministic</a> function with
 :  three parameters.
 : @param href see parameter $href of the deterministic
 :  <a href="#send-request-deterministic-3">send-request-deterministic</a> function with
 :  three parameters.
 : @return see return of the deterministic
 :  <a href="#send-request-deterministic-3">send-request-deterministic</a> function with
 :  three parameters.
 :)
declare function http:send-request-deterministic(
  $request as element(https:request)?,
  $href as xs:string?) as item()+ {
  http:send-request-deterministic($request, $href, ())
};

(:~
 : Function for convenience.
 :
 : The result of this function is equal to calling the send-request function
 : as follows:
 :
 : <code>
 : http:send-request-deterministic($request, (), ())
 : </code>
 :
 : @see documentation of <a href="#send-request-deterministic-3">send-request-deterministic</a>
 :      with three parameters.
 :
 : @param $request see parameter $request of the deterministic
 :  <a href="#send-request-deterministic-3">send-request-deterministic</a> function with
 :  three parameters.
 : @return see return of the deterministic
 :  <a href="#send-request-deterministic-3">send-request-deterministic</a> function with
 :  three parameters.
 :)
declare function http:send-request-deterministic(
  $request as element(https:request)?) as item()+ {
  http:send-request-deterministic($request, (), ())
};

(:~
 : This function sends an HTTP request and returns the corresponding response. 
 :
 : <p>
 : This function is declared as nondeterministic but not sequential.
 : Usually, this function should be used for retrieving resources
 : using HTTP GET or HEAD which are known to change during the execution of
 : the query, i.e. return a different result with each invocation of the
 : function (even with the same parameters).
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
 :
 : The result of this function is equal to calling the send-request-nondeterministic function
 : as follows:
 :
 : <code>
 : http:send-request-nondeterministic($request, $href, ())
 : </code>
 :
 : @see documentation of <a href="#send-request-nondeterministic-3">send-request-nondeterministic</a>
 :      with three parameters.
 :
 : @param $request see parameter $request of
 :  <a href="#send-request-nondeterministic-3">send-request-nondeterministic</a> with three parameters
 : @param href see parameter $href of
 :  <a href="#send-request-nondeterministic-3">send-request-nondeterministic</a> with three parameters
 : @return see return of
 :  <a href="#send-request-nondeterministic-3">send-request-nondeterministic</a> with three parameters
 :)
declare function http:send-request-nondeterministic(
  $request as element(https:request)?,
  $href as xs:string?) as item()+ {
  http:send-request-nondeterministic($request, $href, ())
};

(:~
 : Function for convenience.
 :
 : The result of this function is equal to calling the send-request-nondeterministic function
 : as follows:
 :
 : <code>
 : http:send-request-nondeterministic($request, (), ())
 : </code>
 :
 : @see documentation of <a href="#send-request-nondeterministic-3">send-request-nondeterministic</a>
 :      with three parameters.
 :
 : @param $request see parameter $request of
 :  <a href="#send-request-nondeterministic-3">send-request-nondeterministic</a> with three parameters
 : @return see return of
 :  <a href="#send-request-nondeterministic-3">send-request-nondeterministic</a> with three parameters
 :)
declare function http:send-request-nondeterministic(
  $request as element(https:request)?) as item()+ {
  http:send-request-nondeterministic($request, (), ())
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
