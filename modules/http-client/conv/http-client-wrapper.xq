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
 : <p>This module provides conversion functions between the 
 : XML Expath http-client request and response formats and the 
 : JSON http-client request and response formats used by the
 : <code>http://zorba.io/modules/http-client</code> module.   
 : </p>
 :
 : <p>This module is reserved for internal use by the 
 : <code>http://www.zorba-xquery.com/modules/http-client</code> and the 
 : <code>http://expath.org/ns/http-client</code> modules.
 : This module may be removed at any time. Method signature and 
 : semantics may change.        
 : </p>
 :
 : @author Federico Cavalieri
 : @project Zorba/Input Output/HTTP Client
 :)
module namespace http-wrapper = "http://zorba.io/modules/http-client-wrapper";

import module namespace error = "http://expath.org/ns/error";
import module namespace json-http = "http://zorba.io/modules/http-client";
import module namespace libjn = "http://jsoniq.org/function-library";

import schema namespace http-schema = "http://expath.org/ns/http-client";

declare namespace an = "http://zorba.io/annotations";
declare namespace ver = "http://zorba.io/options/versioning";
declare namespace err = "http://www.w3.org/2005/xqt-errors";
declare namespace ser  = "http://www.w3.org/2010/xslt-xquery-serialization";
declare namespace jn = "http://jsoniq.org/functions";

declare option ver:module-version "1.0";

(:~
 : <p>This function sends an HTTP request and returns the corresponding response.
 : This function is declared sequential and can be used to issue
 : requests which change the state of the server.</p>
 :
 : <p>Its inputs, outputs, and behavior are identical to the
 : <a href="http://expath.org/spec/http-client">EXPath http-client</a>'s
 : send-request() function (except that HTML responses are not tidied
 : into XML - see <a href="#expath_relation">the note above</a>). It
 : is provided here for use in Zorba installations that do not have
 : the EXPath module available. If you have the option of using the 
 : EXPath module instead of this function, please do so, as it will
 : allow your application to be more interoperable between different
 : XQuery engines.</p>
 :
 : <p>Full documentation of the $request parameter can be found in
 : <a href="http://expath.org/spec/http-client#d2e183">the EXPath
 : specification</a>.</p>
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
 :
 : @error error:HC001 An HTTP error occurred.
 : @error error:HC002 Error parsing the response content as XML.
 : @error error:HC003 With a multipart response, the override-media-type must be either a multipart media type or application/octet-stream.
 : @error error:HC004 The src attribute on the body element is mutually exclusive with all other attribute (except the media-type).
 : @error error:HC005 The input request element is not valid.
 : @error error:HC006 A timeout occurred waiting for the response.
 : @error error:HCV02 Trying to follow a redirect of a POST, PUT, or DELETE request
~:)
declare %an:sequential function http-wrapper:http-sequential-request(
  $request as element()?,
  $href as xs:string?,
  $bodies as item()*) as item()+
{
  try 
  {
     {
       variable $json-request := http-wrapper:json-request($request, $href, $bodies);
       variable $json-response := json-http:send-request($json-request);       
       variable $xml-response :=  http-wrapper:xml-response($json-response, fn:data($request/@override-media-type));         
       $xml-response       
     }
  } catch XPTY0004 {
    fn:error($error:HC005, "The input request element is not valid.")
  } catch json-http:HTTP {
    fn:error($error:HC001, "An HTTP error occurred.")
  } catch json-http:REQUEST {
    fn:error($error:HC005, "The input request element is not valid.")
  } catch json-http:TIMEOUT {
    fn:error($error:HC006, "A timeout occurred waiting for the response.")
  } catch json-http:FOLLOW {
    fn:error($error:HCV02, "Trying to follow a redirect of a POST, PUT, or DELETE request.")
  } catch json-http:CHARSET {
    fn:error($error:HC005, "The input request element is not valid: invalid charset specified.")
  } catch * {
    fn:error(fn:QName($error:errNS, fn:local-name-from-QName($err:code)),$err:description, $err:value)
  }
};

(:~
 : <p>This function sends an HTTP request and returns the corresponding response.
 : This function is declared non-deterministic and should only be used to issue
 : requests which do not change the state of the server.</p>
 :
 : <p>Its inputs, outputs, and behavior are identical to the
 : <a href="http://expath.org/spec/http-client">EXPath http-client</a>'s
 : send-request() function (except that HTML responses are not tidied
 : into XML - see <a href="#expath_relation">the note above</a>). It
 : is provided here for use in Zorba installations that do not have
 : the EXPath module available. If you have the option of using the 
 : EXPath module instead of this function, please do so, as it will
 : allow your application to be more interoperable between different
 : XQuery engines.</p>
 :
 : <p>Full documentation of the $request parameter can be found in
 : <a href="http://expath.org/spec/http-client#d2e183">the EXPath
 : specification</a>.</p>
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
 :
 : @error error:HC001 An HTTP error occurred.
 : @error error:HC002 Error parsing the response content as XML.
 : @error error:HC003 With a multipart response, the override-media-type must be either a multipart media type or application/octet-stream.
 : @error error:HC004 The src attribute on the body element is mutually exclusive with all other attribute (except the media-type).
 : @error error:HC005 The input request element is not valid.
 : @error error:HC006 A timeout occurred waiting for the response.
 : @error error:HCV02 Trying to follow a redirect of a POST, PUT, or DELETE request
~:)
declare %an:nondeterministic function http-wrapper:http-nondeterministic-request(
  $request as element()?,
  $href as xs:string?,
  $bodies as item()*) as item()+
{
  try 
  {
     {
       variable $json-request := http-wrapper:json-request($request, $href, $bodies);
       variable $json-response := json-http:send-nondeterministic-request($json-request);
       variable $xml-response :=  http-wrapper:xml-response($json-response, fn:data($request/@override-media-type));  
       $xml-response       
     }
  } catch XPTY0004 {
    fn:error($error:HC005, "The input request element is not valid.")
  } catch json-http:HTTP {
    fn:error($error:HC001, "An HTTP error occurred.")
  } catch json-http:REQUEST {
    fn:error($error:HC005, "The input request element is not valid.")
  } catch json-http:TIMEOUT {
    fn:error($error:HC006, "A timeout occurred waiting for the response.")
  } catch json-http:FOLLOW {
    fn:error($error:HCV02, "Trying to follow a redirect of a POST, PUT, or DELETE request.")
  } catch json-http:CHARSET {
    fn:error($error:HC005, "The input request element is not valid: invalid charset specified.")
  } catch * {
    fn:error(fn:QName($error:errNS, fn:local-name-from-QName($err:code)),$err:description, $err:value)
  }  
};


(:
 :  JSON Response to XML Response Conversion
 :)

(:~
 : Private function used internally by this module.
 :
 : This function accepts a JSON HTTP module response, as
 : used by the http://zorba.io/modules/http-client module 
 : and returns its EXPath XML representation.
 :
 : @param $response a JSON response representation.
 : @param $override-media-type if specified, is used in place of all
 :  body media-types in the response.
 : @return EXPath XML response representation.
 : @error error:HC002 Error parsing the response content as XML.
 :)
declare %private function http-wrapper:xml-response($response as object(), $override-media-type as xs:string?) as item()+
{
  validate 
  {
    element http-schema:response
    {
      attribute message {$response("message")},
      attribute status {$response("status")},
      http-wrapper:xml-headers($response("headers")),
      http-wrapper:xml-body($response("body")),
      http-wrapper:xml-multipart($response("multipart"))    
    }
  },
  http-wrapper:get-bodies(libjn:descendant-objects($response)("body"), $override-media-type)  
};

(:~
 : Private function used internally by this module.
 :
 : This function accepts a JSON HTTP module response, as
 : used by the http://zorba.io/modules/http-client module 
 : and returns its EXPath XML representation.
 : 
 : If the body media-type indicates that the response body 
 : has an XML content, the response body is parsed as XML
 : before being returned. 
 :
 : @param $bodies a sequence JSON bodies.
 : @param $override-media-type if specified, is used in place of all body media-types.
 : @return body contents.
 : @error error:HC002 Error parsing the response content as XML.
 :)
declare %private function http-wrapper:get-bodies($bodies as object()*, $override-media-type as xs:string?) as item()*
{
  for $body in $bodies
  let $media-type := ($override-media-type, $body("media-type"))[1]
  let $mime-type := if (fn:contains($media-type,";"))
                    then fn:substring-before($media-type,";")
                    else $media-type
  return 
    if ($mime-type eq "text/xml" or
        $mime-type eq "application/xml" or
        $mime-type eq "text/xml-external-parsed-entity" or
        $mime-type eq "application/xml-external-parsed-entity" or
        fn:ends-with($mime-type,"+xml"))
    then 
      try {
        parse-xml($body("content"))}
      catch FODC0006 {
        fn:error($error:HC002, "Error parsing the response content as XML.")}        
    else $body("content")
};

(:~
 : Private function used internally by this module.
 :
 : This function accepts the headers portion of a JSON HTTP module 
 : response, as used by the http://zorba.io/modules/http-client module 
 : and returns its EXPath XML representation.
 :
 : @param $headers JSON representation of an headers set.
 : @return XML representation of the given headers.
 :)
declare %private function http-wrapper:xml-headers($headers as object()?) as element()*
{
  if (exists($headers))
  then 
    for $header-name in jn:keys($headers)
    return 
      element http-schema:header 
      {
         attribute name {$header-name},
         attribute value {$headers($header-name)}
      }
  else ()
};


(:~
 : Private function used internally by this module.
 :
 : This function accepts the body portion of a JSON HTTP module 
 : response, as used by the http://zorba.io/modules/http-client module 
 : and returns its EXPath XML representation.
 :
 : @param $body JSON representation of a body.
 : @return XML representation of the given body.
 :)
declare %private function http-wrapper:xml-body($body as object()?) as element()?
{
  if(exists($body))
  then 
    element http-schema:body
    {
      attribute media-type {$body("media-type")}
    }
  else ()  
};

(:~
 : Private function used internally by this module.
 :
 : This function accepts the multipart portion of a JSON HTTP module 
 : response, as used by the http://zorba.io/modules/http-client module 
 : and returns its EXPath XML representation.
 :
 : @param $multipart JSON representation of a multipart.
 : @return XML representation of the given multipart.
 :)
declare %private function http-wrapper:xml-multipart($multipart as object()?) as element()?
{
  if(exists($multipart))
  then 
    element http-schema:multipart
    {
      attribute media-type {$multipart("media-type")},
      
      if ($multipart("boundary")) 
      then attribute boundary {$multipart("boundary")}
      else (),
      
      for $part in jn:members($multipart("part"))
      return
      ( 
        http-wrapper:xml-headers($part("headers")),
        http-wrapper:xml-body($part("body"))
      )
    }
  else ()
};

(:
 : XML Request to JSON Request
 :)
(:~
 : Private function used internally by this module.
 :
 : This function accepts an XML EXPath HTTP request and returns its 
 : JSON representation, as used by the http://zorba.io/modules/http-client
 : module. 
 :
 : @param $request XML EXPath HTTP request.
 : @param $href is the HTTP or HTTPS URI to send the request to. If specified,
 :  any href URI specified in the request element is ignored.
 : @param $bodies the request bodies content.  
 : @return JSON HTTP request representation.
 :
 : @error error:HC005 The specified request object is not valid.
 :)
declare %private function http-wrapper:json-request($request as element()?, $href as xs:string?, $bodies as item()*) as item()
{
  if (http-wrapper:check-params($request, $href, $bodies))
  then
  {
    variable $req := if ($request) 
                     then try {
                         validate { http-wrapper:set-content-type($request) }}
                       catch XQDY0027 {
                         fn:error($error:HC005, "The request element is not valid.")}
                      else ();
    {|
      
      {"method": if ($req/@method) then $req/@method/string(.) else "GET"},
      
      if ($href)
        then {"href": $href} 
        else {"href": $req/@href/string(.)},
      
      if ($request)
      then 
      ( 
        http-wrapper:json-authentication($req),      
        http-wrapper:json-options($req),
        http-wrapper:json-headers($req/http-schema:header),      
        http-wrapper:json-body($req/http-schema:body,$bodies),
        http-wrapper:json-multipart($req/http-schema:multipart,$bodies)
      )
      else ()      
      
     |}
     
  }
  else ()
  
};

(:~
 : Private function used internally by this module.
 :
 : This function accepts an XML EXPath HTTP request and returns the  
 : JSON representation of its authentication options, as used by the 
 : http://zorba.io/modules/http-client module. 
 :
 : @param $request XML EXPath HTTP request.
 : @return JSON HTTP request authentication representation.
 :)
declare %private function http-wrapper:json-authentication($request as element()) as object()?
{
  if (xs:boolean($request/@send-authorization/data(.)))
  then 
  {
    "authentication" :
    {
      "username": $request/@username/string(.),
      "password": $request/@password/string(.),
      "auth-method": $request/@auth-method/string(.)
    }
  }
  else ()
};


(:~
 : Private function used internally by this module.
 :
 : This function accepts an XML EXPath HTTP request and returns the  
 : JSON representation of its options, as used by the 
 : http://zorba.io/modules/http-client module. 
 :
 : @param $request XML EXPath HTTP request.
 : @return JSON HTTP request options representation.
 :)
declare %private function http-wrapper:json-options($request as element()) as object()?
{
  if ($request/@status-only || $request/@override-media-type || 
      $request/@follow-redirect || $request/@timeout || $request/@user-agent)
  then
  {
    "options": 
    {
      {|
        if ($request/@status-only) 
        then {"status-only": xs:boolean($request/@status-only/data(.))} 
        else (),
        
        if ($request/@override-media-type) 
        then {"override-media-type": $request/@override-media-type/string(.)} 
        else (),
        
        if ($request/@follow-redirect) 
        then {"follow-redirect": xs:boolean($request/@follow-redirect/data(.))} 
        else (),
              
        if ($request/@timeout) 
        then {"timeout": $request/@timeout/data(.)} 
        else (),
        
        if ($request/@user-agent) 
        then {"user-agent": $request/@user-agent/string(.)} 
        else ()
      |}
    }
  }
  else ()
};


(:~
 : Private function used internally by this module.
 :
 : This function accepts a sequence of headers in the XML EXPath HTTP request
 : format and returns their JSON representation, as used by the 
 : http://zorba.io/modules/http-client module. 
 :
 : @param $headers XML EXPath HTTP headers.
 : @return JSON HTTP request headers representation.
 :)
declare %private function http-wrapper:json-headers($headers as element()*) as object()?
{
  if ($headers) 
  then
  {
    "headers": 
    {|
      for $header in $headers
      group by $name := $header/@name
      return {$name: string-join($header/@value,",")}
    |}
  }
  else ()
};


(:~
 : Private function used internally by this module.
 :
 : This function accept a body element in the XML EXPath HTTP request
 : format and returns its JSON representation, as used by the 
 : http://zorba.io/modules/http-client module. 
 :
 : @param $body XML EXPath HTTP body element.
 : @param $content body content.
 : @return JSON HTTP request headers representation.
 :)
declare %private function http-wrapper:json-body($body as element()?, $content as item()*) as object()?
{
  if ($body)
  then 
  {
    "body": 
    {|
      {"media-type": $body/@media-type/string(.)},
      
      if ($body/@src)
      then {"src": $body/@src/string(.)}
      else {"content": http-wrapper:produce-content($body,$content)}      
    |}
  }  
  else ()
};

(:~
 : Private function used internally by this module.
 :
 : This function serializes a request body. 
 :
 : @param $body request contents. 
 : @return serialized body.
 :)
declare %private function http-wrapper:produce-content($body as element(), $content as item()*) as xs:string
{
  let $request-body := if ($body/node()) 
                       then $body/node()                                             
                       else $content
  return
    if ($body/@method eq "binary")
    then if ($request-body instance of xs:base64Binary or $request-body instance of xs:hexBinary)
         then $request-body
         else 
            copy $serialization-parameters := http-wrapper:serialization-parameters($body)
            modify delete node $serialization-parameters/ser:method
            return fn:serialize($request-body,$serialization-parameters)         
    else fn:serialize($request-body, http-wrapper:serialization-parameters($body))
};


(:~
 : Private function used internally by this module.
 :
 : This function accept a body element in the XML EXPath HTTP request
 : format and returns the serializer parameters to be used to serialize 
 : its content. 
 :
 : @param $body XML EXPath HTTP body element. 
 : @return serializer parameters.
 :)
declare %private function http-wrapper:serialization-parameters($body as element()) as element()
{
  element ser:serialization-parameters
  {
    http-wrapper:default-serialization-parameters($body),
    for $option in $body/(@method | @byte-order-mark | @cdata-section-elements |
                          @doctype-public | @doctype-system | @encoding |
                          @escape-uri-attributes | @indent |@normalization-form |
                          @omit-xml-declaration | @standalone | @suppress-indentation |
                          @undeclare-prefixes | @version)
    return 
      element {QName("http://www.w3.org/2010/xslt-xquery-serialization",local-name($option))}
              {attribute value {$option/string(.)}}           
  }
};

(:~
 : Private function used internally by this module.
 :
 : This function return this module default serialization parameters. 
 :
 : @param $body XML EXPath HTTP body element. 
 : @return serializer parameters.
 :)
declare %private function http-wrapper:default-serialization-parameters($body as element()) as element()*
{
  if ($body/@method/string(.) eq "xml")
  then
  (
    if ($body/@omit-xml-declaration)
    then ()
    else 
      element {QName("http://www.w3.org/2010/xslt-xquery-serialization","omit-xml-declaration")}
              {attribute value {"no"}}
  )
  else ()  
};

(:~
 : Private function used internally by this module.
 :
 : This function accept a multipart element in the XML EXPath HTTP request
 : format and returns its JSON representation, as used by the 
 : http://zorba.io/modules/http-client module. 
 :
 : @param $multipart XML EXPath HTTP multipart  element.
 : @param $bodies multipart bodies content.
 : @return JSON HTTP request multipart representation.
 :)
declare %private function http-wrapper:json-multipart($multipart as element()?, $bodies as item()*) as object()?
{
  if ($multipart)
  then 
  {
    "multipart": 
    {| 
       {"media-type": $multipart/@media-type/string(.)},
       
       if ($multipart/@boundary) 
       then {"boundary": $multipart/@boundary/string(.)} 
       else (),
       
       {"parts":
         [
           let $requests:= $multipart/*
           for $part in $requests
           group by $bodies-before:= count($requests[local-name(.) eq "body" and . << $part])
           return 
             let $content := 
               if ($part/self::http-schema:body/@src) 
               then () (: The content will be downloaded from the "src" url :)
               else if ($part/self::http-schema:body/node())
                 then ($part/self::http-schema:body/node()) (: the content is made by the body children :)
                 else (: the content is the 1+n-th body item, where n is the number of parts 
                         before the current one which body has no src attributes and no childrens :) 
                      ($bodies[1+count($requests[local-name(.) eq "body" and 
                         not(@content) and not(node()) and . << $part/self::http-schema:body])]) 
             return http-wrapper:json-part($part/self::http-schema:header, $part/self::http-schema:body, $content)
         ]}         
    |}
  }
  else ()
};

(:~
 : Private function used internally by this module.
 :
 : This function accept a part headers, body and content  in the XML 
 : EXPath HTTP request format and returns its JSON representation, as 
 : used by the http://zorba.io/modules/http-client module. 
 :
 : @param $headers XML EXPath HTTP header elements.
 : @param $body XML EXPath HTTP body element.
 : @param $content XML EXPath HTTP body content. 
 : @return JSON HTTP request part representation.
 :)
declare %private function http-wrapper:json-part($headers as element()*, $body as element(), $content as item()*) as item() 
{    
  {|
    http-wrapper:json-headers($headers),
    http-wrapper:json-body($body,$content)
  |}      
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
 :
 : @error error:HC004 The src attribute on the body element is mutually exclusive with all other attribute (except the media-type).
 : @error error:HC005 The specified request object is not valid.
 :
 :)
declare %private function http-wrapper:check-params(
  $request as element(http-schema:request)?,
  $href as xs:string?,
  $bodies as item()*) as xs:boolean {
  let $multipart := $request/http-schema:multipart
  let $override := $request/@override-media-type/string(.)
  let $should-be-empty :=
    for $x in $request//http-schema:body
    return
      if ($x/@src and fn:not((fn:count($x/@*) eq 2))) then 1
      else ()
  return
    if (fn:empty($href) and fn:empty($request)) then
      fn:error($error:HC005, "The request element is not valid.")
    else if ($href eq "") then
      fn:error($error:HC005, "The request element is not valid.")
    else if (not(count($request//http-schema:body[not(exists(node())) and not(exists(@src))]) eq count($bodies))) then
      fn:error($error:HC005, "The request element is not valid.")
    else if ($should-be-empty) then
      fn:error($error:HC004, "The src attribute on the body element is mutually exclusive with all other attributes (except the media-type).")
    else
      fn:true()
};

(:~
 : This adds a default method attribute to all body elements which
 : don't contain a method attribute.
 :
 : @param $request The request which need to be copied.
 : @return A copy of $request with all request//body/@method set.
 :)
declare %private function http-wrapper:set-content-type(
  $request as element(http-schema:request)?)
    as element(http-schema:request)? {
  if ($request) then
    <http-schema:request>{$request/@*}
    {
    for $x in $request/node()
    return
      typeswitch($x)
        case element(http-schema:body) return http-wrapper:create-body($x)
        case element(http-schema:multipart) return http-wrapper:create-multipart($x)
        default return $x
    }
    </http-schema:request>
  else ()
};


(:~
 : This function takes an http-schema:body element, copies it, and
 : adds a method attribute to the copy if there is none
 : in the original element.
 :
 : @param $body is the original http-schema:body element
 : @return a http-schema:body element with a corresponding <code>@method</code>
 :   attribute 
 :)
declare %private function http-wrapper:create-body (
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
declare %private function http-wrapper:create-multipart (
  $multipart as element(http-schema:multipart))
    as element(http-schema:multipart) {
    <http-schema:multipart>{$multipart/@*}
    {
    for $x in $multipart/node()
    return
      typeswitch($x)
        case element(http-schema:body) return http-wrapper:create-body($x)
        default return $x
    }
    </http-schema:multipart>
};
