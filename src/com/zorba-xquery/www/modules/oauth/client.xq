xquery version "3.0";

(:
 : Copyright 2008-2011 The FLWOR Foundation.
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
 : This module provides the functions necessary to acquire access to the personal
 : resources of a user through the open standard called
 : <a href="http://oauth.net/" target="_blank">OAuth</a>.
 : The application/mashup creator does not need to know the
 : specifics of <a href="http://oauth.net/" target="_blank">OAuth</a> to use this module.
 : @author Stephanie Russell
 : @author <a href="mailto:william.candillon@28msec.com">William Candillon</a>
 : @see <a href="http://oauth.net/" target="_blank">OAuth Website</a>
 : @project OAuth
 :
 :)
module namespace oauth = "http://www.zorba-xquery.com/modules/oauth/client";

import module namespace ra = "http://www.zorba-xquery.com/modules/random";
import module namespace hmac = "http://www.zorba-xquery.com/modules/cryptography/hmac";
import module namespace http-client = "http://expath.org/ns/http-client";
import schema namespace http = "http://expath.org/ns/http-client";

import module namespace base64 = "http://www.zorba-xquery.com/modules/converters/base64";

(:~
 : Use err module functions for throwing errors.
 :)
import module namespace oerr = "http://www.zorba-xquery.com/modules/oauth/error";

import schema namespace sp = "http://www.zorba-xquery.com/schemas/oauth/service-provider";
import schema namespace p = "http://www.zorba-xquery.com/schemas/oauth/parameters";

declare namespace an = "http://www.zorba-xquery.com/annotations";
declare namespace ver = "http://www.zorba-xquery.com/options/versioning";
declare namespace op = "http://www.zorba-xquery.com/options/features";
declare namespace f = "http://www.zorba-xquery.com/features";

declare option op:disable "f:trace";

declare option ver:module-version "1.0";

(:~
 : Utility function to build a service provider object.
 : This object contains the information required by the 
 : OAuth client to interact with an OAuth service provider.
 : For instance the following expression:
 : <pre class="ace-static" ace-mode="xquery">
 : let $consumer-key     := "#"
 : let $consumer-secret  := "#"
 : let $signature-method := "HMAC-SHA1"
 : let $realm            := "twitter.com"
 : let $authorize-url    := "http://api.twitter.com/oauth/authorize"
 : let $request-token-method := "POST"
 : let $request-token-url := "https://twitter.com/oauth/request_token"
 : let $request-token-callback-url := "https://twitter.com/oauth/request_token"
 : let $access-token-method := "POST"
 : let $access-token-url := "https://api.twitter.com/oauth/access_token"
 : return oauth:service-provider(
 :   $consumer-key, $consumer-secret, $signature-method,
 :   $realm, $authorize-url, $request-token-method,
 :   $request-token-url, $request-token-callback-url,
 :   $access-token-method, $access-token-url
 : )
 : </pre>
 : Will return the following XML schema instance:
 : <pre class="ace-static" ace-mode="xml">
 : <sp:service-provider xmlns:sp="http://www.zorba-xquery.com/schemas/oauth/service-provider"
 :     consumer-key="#" consumer-secret="#" signature-method="HMAC-SHA1"
 :     realm="twitter.com" authorize-url="http://api.twitter.com/oauth/authorize">
 :   <sp:request-token
 :       method="POST"
 :       href="https://twitter.com/oauth/request_token"
 :       callback-url="https://twitter.com/oauth/request_token"/>
 :   <sp:access-token
 :       method="POST"
 :       href="https://api.twitter.com/oauth/access_token"/>
 : </sp:service-provider>
 : </pre>
 : @param $consumer-key Client Identifier, also known as the consumer-key
 : @param $consumer-secret Client Shared-Secret, also known as the consumer-secret
 : @param $signature-method Method with which the signing key is signed (typically HMAC-SHA1)
 : @param $realm Realm that defines the protection space
 : @param $authorize-url authorize-url
 : @param $request-token-method request-token-method
 : @param $request-token-url request-token-url
 : @param $request-token-callback-url request-token-callback-url
 : @param $access-token-method access-token-method
 : @param $access-token-url access-token-url
 : @return instance of the OAuth service provider XML schema.
:)
declare function oauth:service-provider(
  $consumer-key as xs:string, $consumer-secret as xs:string, $signature-method as xs:string,
  $realm as xs:string, $authorize-url as xs:string, $request-token-method as xs:string,
  $request-token-url as xs:string, $request-token-callback-url as xs:string,
  $access-token-method as xs:string, $access-token-url as xs:string
)
as schema-element(sp:service-provider)
{
validate {
  element sp:service-provider {
    attribute consumer-key    { $consumer-key },
    attribute consumer-secret { $consumer-secret },
    attribute signature-method { $signature-method },
    attribute realm { $realm },
    attribute authorize-url { $authorize-url },
    element sp:request-token {
      attribute method { $request-token-method },
      attribute href { $request-token-url },
      attribute callback-url { $request-token-callback-url }
    },
    element sp:access-token {
      attribute method { $access-token-method },
      attribute href { $access-token-url }
    }
  }
}
};

(:~
 : Create an OAuth Parameters instance.
 : Instances of OAuth parameters are used to 
 : contain value/pair data such as <em>oauth_token</em>
 : and <em>oauth_token_secret</em>.
 : For instance the following code snippet:
 : <pre class="ace-static" ace-mode="xquery">
 :  oauth:parameters("oauth_token", "#")
 : </pre>
 : Returns the following XML schema instance:
 : <pre class="ace-static" ace-mode="xml">
 : <p:parameters xmlns:p="http://www.zorba-xquery.com/schemas/oauth/parameters">
 :   <p:parameter name="oauth_token" value="#" />
 : </p:parameters>
 : </pre>
 : @param $name parameter name
 : @param $value parameter value
 : @return instance of the OAuth parameters XML schema.
 :)
declare function oauth:parameters($name as xs:string, $value as xs:string)
as element(p:parameters)
{
  validate {
    <p:parameters>
      <p:parameter name="{$name}" value="{$value}" />
    </p:parameters>
  }
};

(:~
 : Adds an OAuth parameter to an OAuth Parameters instance.
 : Instances of OAuth parameters are used to 
 : contain value/pair data such as <em>oauth_token</em>
 : and <em>oauth_token_secret</em>.
 : For instance the following code snippet:
 : <pre class="ace-static" ace-mode="xquery">
 :  let $params := oauth:parameters("oauth_token", "#")
 :  let $params := oauth:add-parameter($params, "oauth_token_secret", "#")
 :  return $params
 : </pre>
 : Returns the following XML schema instance:
 : <pre class="ace-static" ace-mode="xquery">
 : <p:parameters xmlns:p="http://www.zorba-xquery.com/schemas/oauth/parameters">
 :   <p:parameter name="oauth_token" value="#" />
 :   <p:parameter name="oauth_token_secret" value="#" />
 : </p:parameters>
 : </pre>
 : @param $parameters parameters
 : @param $name parameter name
 : @param $value parameter value
 : @return instance of the OAuth parameters XML schema.
 :)
declare function oauth:add-parameter($parameters as schema-element(p:parameters)?, $name as xs:string, $value as xs:string)
as schema-element(p:parameters)
{
  validate {
    <p:parameters>
      {
        if($name != "") then
          <p:parameter name="{$name}" value="{$value}" />
        else (),
        $parameters/p:parameter
      }
    </p:parameters>
  }
};

(:~
 : This function returns the string value of the parameters whose key matches a $string input.
 : @param $params element parameters
 : @param $string string as the "key" name
 : @return string value of the parameter with key $string
 :
 : <pre class="ace-static" ace-mode="xquery">
 : let $params := oauth:parameters("oauth_token", "token")
 : let $params := oauth:add-parameter($params, "oauth_token_secret", "secret")
 : let $token-secret := oauth:parameter($params, "oauth_token_secret")
 : return $token-secret
 : </pre>
 :)
declare function oauth:parameter($params as schema-element(p:parameters), $string as xs:string) as xs:string
{
  let $value := 
    for $param in $params/p:parameter
    let $key := $param/@name/string(.)
    let $value := $param/@value/string(.)
    where $key = $string
    return $value
  return
    if(empty($value)) then
      error($oerr:OC005, concat("Parameter not found: ", $string))
    else
      xs:string($value)
      
};

(:~
 : This function allows the client to obtain a set of temporary credentials from the service provider by making an authenticated HTTP request to the Temporary Credential Request endpoint.
 : This function is provided for convenience for <a href="#request-token-2">request-token#2</a>.
 : Invoking this function is equivalent to:
 : <pre class="ace-static" ace-mode="xquery">
 : oauth:request-token($service-provider, ())
 : </pre>
 :
 : @see http://tools.ietf.org/html/rfc5849#section-2.1
 : @param $service-provider Information about the service provider
 : @return temporary credentials correctly parsed as parameter elements, or an error if http response status is not 200 OK
 :)
declare %an:sequential function oauth:request-token($service-provider as schema-element(sp:service-provider))
as schema-element(p:parameters)
{
  oauth:request-token($service-provider, ())
};

(:~
 : This function allows the client to obtain a set of temporary credentials from the service provider by making an authenticated HTTP request to the Temporary Credential Request endpoint.
 : This function is provided for convenience.
 : @see http://tools.ietf.org/html/rfc5849#section-2.1
 : @param $service-provider Information about the service provider
 : @param $parameters Additionnal parameters to the request
 : @return temporary credentials correctly parsed as parameter elements, or an error if http response status is not 200 OK
 :
 : <pre class="ace-static" ace-mode="xquery">
 : let $twitter-config := oauth:service-provider(...)
 : let $additional-parameter := oauth:parameters("foo", "bar")
 : let $tokens := oauth:request-token($twitter-config, $additional-parameter)
 : let $token := oauth:parameter($tokens, "oauth_token")
 : let $token-secret := oauth:parameter($tokens, "oauth_token_secret")
 : ...
 : </pre>
 :)
declare %an:sequential function oauth:request-token($service-provider as schema-element(sp:service-provider), $parameters as schema-element(p:parameters)?)
as schema-element(p:parameters)
{
  let $consumer-key     as xs:string := $service-provider/@consumer-key/string(.)
  let $consumer-secret  as xs:string := $service-provider/@consumer-secret/string(.)
  let $signature-method as xs:string := $service-provider/@signature-method/string(.)
  let $realm            as xs:string := $service-provider/@realm/string(.)
  let $callback-url     as xs:string := $service-provider/sp:request-token/@callback-url/string(.)
  let $method           as xs:string := $service-provider/sp:request-token/@method/string(.)
  let $temporary-credential-request as xs:string := $service-provider/sp:request-token/@href/string(.)
  let $additional-parameters := oauth:additional-parameters($parameters)
  return oauth:request-token(
    $consumer-key,
    $consumer-secret,
    $signature-method,
    $method,
    $realm,
    $temporary-credential-request,
    $callback-url,
    $additional-parameters
    )
};

(:~
 : This function allows the client to obtain a set of token credentials from the service provider by making an authenticated HTTP request to the Token Request endpoint.
 : This function is provided for convenience.
 : @see http://tools.ietf.org/html/rfc5849#section-2.3
 : @param $service-provider Contains service provider information
 : @param $parameters parameters
 : @return token credentials correctly parsed as parameter elements, or an error if http response status is not 200 OK
 :
 : <pre class="ace-static" ace-mode="xquery">
 : let $service-provider := oauth:service-provider(...)
 : let $parameters := oauth:parameters("oauth_token", "#")
 : let $parameters := oauth:add-parameter($parameters, "oauth_token_secret", "#")
 : let $tokens := oauth:access-token($service-provider, $parameters)
 : ...
 : </pre>
 :)
declare %an:sequential function oauth:access-token($service-provider as schema-element(sp:service-provider), $parameters as schema-element(p:parameters))
as schema-element(p:parameters)
{
  let $consumer-key       as xs:string := $service-provider/@consumer-key/string(.)
  let $consumer-secret    as xs:string := $service-provider/@consumer-secret/string(.)
  let $signature-method   as xs:string := $service-provider/@signature-method/string(.)
  let $realm              as xs:string := $service-provider/@realm/string(.) 
  let $method             as xs:string := $service-provider/sp:access-token/@method/string(.)
  let $token-request-uri  as xs:string := $service-provider/sp:access-token/@href/string(.)
  let $oauth-token        as xs:string := oauth:parameter($parameters,"oauth_token")
  let $oauth-token-secret as xs:string := oauth:parameter($parameters,"oauth_token_secret")
  let $additional-parameters := oauth:additional-parameters($parameters)
  return 
    oauth:access-token(
    $consumer-key,
    $consumer-secret,
    $signature-method,
    $realm,
    $oauth-token,
    $oauth-token-secret,
    $method,
    $token-request-uri,
    $additional-parameters
    )
};


(:~
 : This function allows the client access to the protected resources of the user.
 : This function is provided for convenience.
 : @see http://tools.ietf.org/html/rfc5849#section-3
 : @param $protected-resource (Not schema-validated) http:request element with http method and href.
 : @param $service-provider Information about the service provider
 : @param $parameters parameters
 : @return protected resources parsed as parameter elements, or an error if http response status is not 200 OK
 :
 : <pre class="ace-static" ace-mode="xquery">
 : let $tokens := oauth:parameters("oauth_token", "#")
 : let $tokens := oauth:add-parameter($tokens, "oauth_token_secret", "#")
 : let $service-provider := oauth:service-provider(...)
 : let $request := validate {
 :   <request xmlns="http://expath.org/ns/http-client"
 :            href="http://twitter.com/account/verify_credentials.xml"
 :            method="GET" />
 : }
 : return oauth:protected-resource($request, $service-provider, $tokens)                           
 : </pre>
 :)
declare %an:sequential function oauth:protected-resource(
  $protected-resource as schema-element(http:request),
  $service-provider as schema-element(sp:service-provider),
  $parameters as schema-element(p:parameters)
)
as item()*
{
  let $consumer-key        as xs:string := $service-provider/@consumer-key/string(.)
  let $consumer-secret     as xs:string := $service-provider/@consumer-secret/string(.)
  let $signature-method    as xs:string := $service-provider/@signature-method/string(.)
  let $realm               as xs:string := $service-provider/@realm/string(.) 
  let $oauth-token         as xs:string := oauth:parameter($parameters,"oauth_token")
  let $oauth-token-secret  as xs:string := oauth:parameter($parameters,"oauth_token_secret")
  let $additional-parameters := oauth:additional-parameters($parameters)
  return 
  oauth:protected-resource(
    $consumer-key,
    $consumer-secret,
    $signature-method,
    $oauth-token,
    $oauth-token-secret,
    $realm,
    $protected-resource,
    $additional-parameters)
};

(:~
 : The timestamp is expressed in the number of seconds since January 1, 1970 00:00:00 GMT.
 :
 : @see http://tools.ietf.org/html/rfc5849#section-3.3
 : @return integer time in seconds since Unix epoch
 :)
declare %private %an:nondeterministic function oauth:timestamp() as xs:decimal
{
  let $current-dateTime := fn:adjust-dateTime-to-timezone(current-dateTime(), xs:dayTimeDuration('PT0H'))
  let $duration := $current-dateTime - xs:dateTime("1970-01-01T00:00:00Z")
  return fn:round($duration div xs:dayTimeDuration('PT1S'))
};

(:~
 : This function returns a string key which is the client and temporary credential concatenated with an ampersand.
 :
 : @see http://tools.ietf.org/html/rfc5849#section-3.4.2
 : @param $oauth-consumer-secret Client credential referred to as the "consumer secret"
 : @param $oauth-token-secret Temporary credential referred to as the "oauth token secret"
 : @return String signing key
 :)
declare %private function oauth:key($oauth-consumer-secret as xs:string, $oauth-token-secret as xs:string?) as xs:string
{
  concat($oauth-consumer-secret, "&amp;", 
    if(empty($oauth-token-secret)) 
    then "" 
    else $oauth-token-secret)
};

(:~
 : This function should return a new UUID every time the function is invoked.
 :
 : @see http://tools.ietf.org/html/rfc5849#section-3.3
 : @return random string
 :)
declare %private %an:nondeterministic function oauth:nonce() as xs:string
{
  ra:uuid()
};

(:~
 : This function normalizes parameters into a single string.
 :
 : @see http://tools.ietf.org/html/rfc5849#section-3.4.1.3.2
 : @param $params Element containing OAuth specific parameters
 : @param $divide String, usually an equal sign(=)
 : @param $option Optional string, quotation mark '"' in the creation of the authorization header
 : @param $comma String, typically a comma (,) in the authorization header
 : @return string formatted specifically for the authorization header, or for parameterization
 :)
declare %private function oauth:normalization($params as schema-element(p:parameters), $divide as xs:string, $option as xs:string?, $comma as xs:string) as xs:string
{
  fn:string-join(
    for $param in $params/p:parameter
    let $k := $param/@name/string(.)
    let $v := $param/@value/string(.)
    order by $param/@name
    where $param/@name != ""
    return concat($k, $divide, $v, $option),
    $comma
  )
};

(:~
 : This function formats the authorization header.
 :
 : @see http://tools.ietf.org/html/rfc5849#section-3.5.1
 : @param $params Element containing OAuth specific parameters
 : @param $realm Realm that defines the protection space
 : @param $signature string signed signature
 : @return string authorization header
 :)
declare %private function oauth:authorization-header($params as element(p:parameters), $realm as xs:string, $signature as xs:string) as xs:string
{
  concat('OAuth ', 
    string-join(
      (
        concat('realm="', $realm, '"'),
        oauth:normalization($params,'="','"',", "),
        concat('oauth_signature="', $signature, '"')
      ),
      ", ")
  )
};

(:~
 : This function constructs the Signature Base String; a consistent, reproducible concatenation of several of the HTTP request elements into a single string.
 : @see http://tools.ietf.org/html/rfc5849#section-3.4.1
 : @param $http-method string method for posting the request to the url
 : @param $base-uri string base-uri for request, access, or protected resources
 : @param $params Element containing OAuth specific parameters
 : @return signature base string formatted to create the signature
 :)
declare %private function oauth:signature-base-string($http-method as xs:string, $base-uri as xs:string, $params as element(p:parameters)) as xs:string
{
  let $params := validate {
    <p:parameters>{
      for $param in $params/p:parameter
      let $k := $param/@name/string(.)
      let $v := $param/@value/string(.)
      return <p:parameter name="{encode-for-uri($k)}" value="{encode-for-uri($v)}" />
    }</p:parameters>
  }        
  let $base-string := concat($http-method, "&amp;", encode-for-uri($base-uri), "&amp;",
        oauth:normalization($params, "%3D", "%26",""))
  return
    if (true() and matches($base-string, "%26"))
    then trace(replace(trace($base-string, "before"),
           concat('^(.*)', "%26",'.*'),
         '$1'), "after")
    else ''
};

(:~
 : This function generates a signature string which becomes the "oauth_signature" parameter. The service provider verifies the signature as specified for each method.
 : @see http://tools.ietf.org/html/rfc5849#section-3.4
 : @param $base-string signature base string
 : @param $oauth-signature-method string signing method
 : @param $key string signing key
 : @return signature base string formatted to create the signature
 :)
declare %private function oauth:signature($base-string as xs:string, $oauth-signature-method as xs:string, $key as xs:string) as xs:string
{
  (:
   : HMAC-SHA1
   : @see http://tools.ietf.org/html/rfc5849#section-3.4.2
   : uses the hmac-sha1 algorithm found here @see http://tools.ietf.org/html/rfc2104
   :)
  if($oauth-signature-method = "HMAC-SHA1")
  then xs:string(hmac:sha1($base-string, $key))
  (:
   : RSA-SHA1
   : @see http://tools.ietf.org/html/rfc5849#section-3.4.3  
   :)
  else if($oauth-signature-method = "RSA-SHA1")
  then error($oerr:OC001, concat("Method not implemented yet: ", $oauth-signature-method))
  (:
   : PLAINTEXT
   : @see http://tools.ietf.org/html/rfc5849#section-3.4.4 
   :)
  else if($oauth-signature-method = "PLAINTEXT")
  then $key
  else error(xs:QName("oerr:OC001"), concat("Unsupported signing method: ", $oauth-signature-method))
};

(:~
 : This function takes an input string and parses the parameters into parameter elements.
 : @param $input string of parameters to be parsed into element parameters
 : @return element parameters
 :)
declare %private function oauth:parse-parameters($input as xs:string) as element(p:parameters)
{
validate {
 <p:parameters>{
  for $param in fn:tokenize(replace($input, "&#xA;",""), "&amp;")
  let $key-value := fn:tokenize($param, "=")
  return <p:parameter name="{$key-value[1]}" value="{$key-value[2]}" />
  }</p:parameters>
}
};

(:~
 : This function makes the request, and sends it to the specified url using the specified http request method.
 :
 : @see http://tools.ietf.org/html/rfc5849#section-3.1
 : @param $consumer-secret Client Shared-Secret, also known as the consumer-secret 
 : @param $method HTTP request method (e.g., "GET", "POST", etc.)
 : @param $oauth-token-secret the temporary credentials shared-secret
 : @param $params Element containing OAuth specific parameters
 : @param $realm Realm that defines the protection space
 : @param $signature-method Method with which the signing key is signed (typically HMAC-SHA1)
 : @param $url Target URL
 : @return HTTP response.
 :)
declare %private %an:sequential function oauth:http-request(
    $consumer-secret as xs:string,
    $protected-resource as element(http:request),
    $oauth-token-secret as xs:string?,
    $params as element(p:parameters),
    $realm as xs:string?,
    $signature-method as xs:string
)
as item()*
{
  let $url    := $protected-resource/@href/string(.)
  let $method := $protected-resource/@method/string(.)
  let $base-url         := trace(tokenize($url, "\?")[1], "base-url")
  let $base-signature   := trace(oauth:signature-base-string($method, $base-url, $params),"base-sign")
  let $key    := trace(oauth:key($consumer-secret, $oauth-token-secret),"sign-key")
  let $signature   := trace(encode-for-uri(oauth:signature($base-signature, $signature-method, $key)),"signature")
  let $authorization-header   := trace(oauth:authorization-header($params,$realm,$signature),"authorization-header")
  let $authorization-header   := <http:header name="Authorization" value="{$authorization-header}" />
  let $request := copy $request := $protected-resource modify (insert node $authorization-header into $request) return $request
  return http-client:send-request(
    $request
  )
};

(:~
 : This function creates the parameters to be given to the http-request function. It parses the response into 
 : parameter elements if the response status is 200 (OK).
 :
 : @param $consumer-key Client Identifier, also known as the consumer-key
 : @param $consumer-secret Client Shared-Secret, also known as the consumer-secret
 : @param $method HTTP request method (e.g., "GET", "POST", etc.)
 : @param $oauth-token The temporary credentials identifier
 : @param $oauth-token-secret The temporary credentials shared-secret
 : @param $realm Realm that defines the protection space
 : @param $signature-method Method with which the signing key is signed (typically HMAC-SHA1)
 : @param $url Target URL
 : @param $additional-parameters Parameters specific to a certain step (request-token, authorize, access-token, protected-resource) of the OAuth authorization
 : @return correctly parsed parameters, or an error if http response status is not 200 OK
 : @error XQP0021(oerr:OC003) if we receive http 401 error from the server.
 : @error XQP0021(oerr:OC004) if we receive http 500 error from the server.
 :)
declare %private %an:sequential function oauth:format-request(
    $consumer-key as xs:string,
    $consumer-secret as xs:string,
    $protected-resource as element(http:request),
    $oauth-token as xs:string?,
    $oauth-token-secret as xs:string?,
    $realm as xs:string?,
    $signature-method as xs:string,
    $additional-parameters as element(p:parameters)?,
    $format-params as xs:boolean)
as item()*
{
  let $version := "1.0"
  let $base-params := concat("&amp;oauth_consumer_key=",$consumer-key,"&amp;oauth_nonce=",trace(oauth:nonce(),"nonce"),
"&amp;oauth_signature_method=",$signature-method,"&amp;oauth_timestamp=",oauth:timestamp(),"&amp;oauth_version=",$version)
  let $params := oauth:parse-parameters($base-params)
  let $params := validate { 
    <p:parameters>
    {$params/p:parameter}
    {$additional-parameters/p:parameter}
    </p:parameters>
  }
  let $response := oauth:http-request($consumer-secret, $protected-resource, $oauth-token-secret, $params, $realm, $signature-method)
  let $head := $response[1]
  let $body := if($response[2] instance of xs:base64Binary) then base64:decode($response[2]) else $response[2]
  return 
    if($head/@status = 200)
    then 
      if ($format-params) then
        oauth:parse-parameters($body)
      else 
        $response
    else if ($head/@status = 401) then 
      error(
        xs:QName("oerr:OC003"),
        concat("Authorization header unauthorized: ", $body)
      )
    else
      error($oerr:OC004, concat("Service Provider Error: ", $body))

};

declare %private %an:sequential function oauth:format-request(
    $consumer-key as xs:string,
    $consumer-secret as xs:string,
    $protected-resource as element(http:request),
    $oauth-token as xs:string?,
    $oauth-token-secret as xs:string?,
    $realm as xs:string?,
    $signature-method as xs:string,
    $additional-parameters as element(p:parameters)?)
as item()*
{
  oauth:format-request($consumer-key, $consumer-secret, $protected-resource, $oauth-token, $oauth-token-secret, $realm, $signature-method, $additional-parameters, true())
};

(:~
 : This function finds the server-specific parameters. The specification states, "Servers MAY specify additional parameters..."
 : @see http://tools.ietf.org/html/rfc5849#section-2.1
 : @param $request element containing the client's request
 : @return may return parsed parameters or empty sequence if there were no server specific parameters
 :)
declare %private function oauth:additional-parameters($parameters as element(p:parameters)?) as element(p:parameters)?
{
  let $additional-parameters := validate {
    <p:parameters>{
    for $param in $parameters/p:parameter
    let $key := $param/@name/string(.)
    let $value := $param/@value/string(.)
    where (($key != "oauth_callback")         and 
           ($key != "oauth_consumer_key")     and 
           ($key != "oauth_consumer_secret")  and 
           ($key != "oauth_signature_method") and 
           ($key != "method")                 and 
           ($key != "realm")                  and
           ($key != "url")                    and
           ($key != "oauth_token")            and
           ($key != "oauth_token_secret")     and
           ($key != "oauth_verifier"))
    return $param
    }</p:parameters>
  }
  let $parameters :=
    if(empty($additional-parameters/p:parameter))
    then (:"":) ()
    else $additional-parameters(:oauth:parse-parameters(concat("&amp;", oauth:normalization($additional-parameters,'=',(),"&amp;"))):)
  return $parameters
};

(:~
 : This function allows the client to obtain a set of temporary credentials from the service provider by making an authenticated HTTP request to the Temporary Credential Request endpoint.
 :
 : @see http://tools.ietf.org/html/rfc5849#section-2.1
 : @param $consumer-key Client Identifier, also known as the consumer-key
 : @param $consumer-secret Client Shared-Secret, also known as the consumer-secret
 : @param $signature-method Method with which the signing key is signed (typically HMAC-SHA1)
 : @param $method HTTP request method (e.g., "GET", "POST", etc.) HTTP request method
 : @param $realm Realm that defines the protection space
 : @param $temporary-credential-request Target url for temporary credentials request
 : @param $callback-url Service provider redirects the user to this url after authorization. The parameter value MUST be set to "oob" (case sensitive), to indicate an out-of-band configuration.
 : @param $additional-parameters Parameters specific to a certain step (request-token) of the OAuth authorization
 : @return temporary credentials correctly parsed as parameter elements, or an error if http response status is not 200 OK
 :)
declare %private %an:sequential %an:nondeterministic function oauth:request-token(
    $consumer-key as xs:string,
    $consumer-secret as xs:string,
    $signature-method as xs:string,
    $method as xs:string,
    $realm as xs:string,
    $temporary-credential-request as xs:string,
    $callback-url as xs:string,
    $additional-parameters as element(p:parameters)?) as element(p:parameters)
{
  let $protected-resource := validate {
    <http:request href="{$temporary-credential-request}" method="{$method}" />
  }
  let $add := oauth:add-parameter($additional-parameters, "oauth_callback", encode-for-uri($callback-url))
  return oauth:format-request($consumer-key,$consumer-secret, $protected-resource,(),(),$realm,$signature-method,$add)
};

(:~
 : This function allows the client to obtain a set of token credentials from the service provider by making an authenticated HTTP request to the Token Request endpoint.
 :
 : @see http://tools.ietf.org/html/rfc5849#section-2.3
 : @param $consumer-key Client Identifier, also known as the consumer-key
 : @param $consumer-secret Client Shared-Secret, also known as the consumer-secret
 : @param $signature-method Method with which the signing key is signed (typically HMAC-SHA1)
 : @param $method HTTP request method (e.g., "GET", "POST", etc.)
 : @param $realm Realm that defines the protection space
 : @param $token-request-uri Target uri for token credentials request
 : @param $oauth-token The temporary credentials identifier
 : @param $oauth-token-secret the temporary credentials shared-secret
 : @param $additional-parameters Parameters specific to a certain step (access-token) of the OAuth authorization
 : @return token credentials correctly parsed as parameter elements, or an error if http response status is not 200 OK
 :)
declare %private %an:sequential %an:nondeterministic function oauth:access-token(
    $consumer-key as xs:string,
    $consumer-secret as xs:string,
    $signature-method as xs:string,
    $realm as xs:string,
    $oauth-token as xs:string,
    $oauth-token-secret as xs:string,
    $method as xs:string,
    $token-request-uri as xs:string,
    $additional-parameters as element(p:parameters)?)
as element(p:parameters)
{
  let $protected-resource := validate {
    <http:request href="{$token-request-uri}" method="{$method}" />
  }
  let $additional-parameters := oauth:add-parameter($additional-parameters, "oauth_token", $oauth-token)
  return
  oauth:format-request($consumer-key,$consumer-secret,$protected-resource,$oauth-token,$oauth-token-secret,$realm,$signature-method, $additional-parameters)
};

(:~
 : This function allows the client access to the protected resources of the user.
 :
 : @see http://tools.ietf.org/html/rfc5849#section-3
 : @param $consumer-key Client Identifier, also known as the consumer-key
 : @param $consumer-secret Client Shared-Secret, also known as the consumer-secret
 : @param $signature-method Method with which the signing key is signed (typically HMAC-SHA1)
 : @param $method HTTP request method (e.g., "GET", "POST", etc.)
 : @param $realm Realm that defines the protection space
 : @param $url Target URL
 : @param $oauth-token The temporary credentials identifier
 : @param $oauth-token-secret the temporary credentials shared-secret
 : @param $additional-parameters Parameters specific to a certain step (protected-resource) of the OAuth authorization
 : @return protected resources parsed as parameter elements, or an error if http response status is not 200 OK
 :)
declare %private %an:sequential %an:nondeterministic function oauth:protected-resource(
    $consumer-key as xs:string,
    $consumer-secret as xs:string,
    $signature-method as xs:string,
    $oauth-token as xs:string,
    $oauth-token-secret as xs:string,
    $realm as xs:string,
    $protected-resource as schema-element(http:request),
    $additional-parameters as element(p:parameters)?)
as item()*
{
  let $parameters := oauth:add-parameter($additional-parameters, "oauth_token", $oauth-token)
  return oauth:format-request($consumer-key,$consumer-secret, $protected-resource, $oauth-token,$oauth-token-secret,$realm,$signature-method,$parameters, false())
};
