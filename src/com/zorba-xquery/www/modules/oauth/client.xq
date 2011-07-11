(:~
 : OAuth Client Module
 : This module provides the functions necessary to acquire access to the personal
 : resources of a user through the open standard called
 : <a href="http://oauth.net/" target="_blank">OAuth</a>.
 : The application/mashup creator does not need to know the
 : specifics of <a href="http://oauth.net/" target="_blank">OAuth</a> to use this module.
 : @author Stephanie Russell
 : @see <a href="http://oauth.net/" target="_blank">OAuth</a>
 : @project OAuth
 :
 :)

module namespace oauth = 'http://www.zorba-xquery.com/modules/oauth/client';
import module namespace ra = "http://www.zorba-xquery.com/modules/random";
import module namespace hmac = "http://www.zorba-xquery.com/modules/cryptography/hmac";
import module namespace http-client = "http://expath.org/ns/http-client";
import schema namespace http = "http://expath.org/ns/http-client";
import module namespace date = "http://www.zorba-xquery.com/modules/datetime";

(:~
 : Use err module functions for throwing errors.
 :)
import module namespace oerr="http://www.zorba-xquery.com/modules/oauth/error";

declare namespace ann = "http://www.zorba-xquery.com/annotations";
declare namespace ver = "http://www.zorba-xquery.com/options/versioning";
declare namespace op = "http://www.zorba-xquery.org/options";

declare option op:trace "disable";
declare option ver:module-version "1.0";

(:~
 : The timestamp is expressed in the number of seconds since January 1, 1970 00:00:00 GMT.
 :
 : @see http://tools.ietf.org/html/rfc5849#section-3.3
 : @return integer time in seconds since Unix epoch
 :)
declare %ann:nondeterministic function oauth:timestamp() as xs:decimal
{
  let $current-dateTime := fn:adjust-dateTime-to-timezone(date:current-dateTime(), xs:dayTimeDuration('PT0H'))
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
declare function oauth:key($oauth-consumer-secret as xs:string, $oauth-token-secret as xs:string?) as xs:string
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
declare %ann:nondeterministic function oauth:nonce() as xs:string
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
declare function oauth:normalization($params as element()+, $divide as xs:string, $option as xs:string?,$comma as xs:string) as xs:string
{
  fn:string-join(
          for $param in $params//param
          let $k := $param/@key/data(.)
          let $v := $param/@value/data(.)
          order by $param/@key
          return concat(fn:encode-for-uri($k), $divide,encode-for-uri($v), $option),$comma)
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
declare function oauth:authorization-header($params as element()+, $realm as xs:string, $signature as xs:string) as xs:string
{
  concat('OAuth ', 
             string-join(
               (concat('realm="', $realm, '"'),oauth:normalization($params,'="','"',", "),
               concat('oauth_signature="', $signature, '"')
               ), ", "))
};

(:~
 : This function constructs the Signature Base String; a consistent, reproducible concatenation of several of the HTTP request elements into a single string.
 : @see http://tools.ietf.org/html/rfc5849#section-3.4.1
 : @param $http-method string method for posting the request to the url
 : @param $base-uri string base-uri for request, access, or protected resources
 : @param $params Element containing OAuth specific parameters
 : @return signature base string formatted to create the signature
 :)
declare function oauth:signature-base-string($http-method as xs:string, $base-uri as xs:string, $params as element()+) as xs:string
{
  let $base-string := concat($http-method, "&amp;", fn:encode-for-uri($base-uri), "&amp;",
        oauth:normalization($params, "%3D", "%26",""))
  return
    if (matches($base-string, "%26"))
    then replace($base-string,
           concat('^(.*)', "%26",'.*'),
         '$1')
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
declare function oauth:signature($base-string as xs:string, $oauth-signature-method as xs:string, $key as xs:string) as xs:string
{
  (:
   : HMAC-SHA1
   : @see http://tools.ietf.org/html/rfc5849#section-3.4.2
   : uses the hmac-sha1 algorithm found here @see http://tools.ietf.org/html/rfc2104
   :)
  if($oauth-signature-method = "HMAC-SHA1")
  then hmac:sha1($base-string, $key)
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
declare function oauth:parse-parameters($input as xs:string) as element()+
{
  <parameters>{
  for $param in fn:tokenize(replace($input, "&#xA;",""), "&amp;")
  let $key-value := fn:tokenize($param, "=")
  return <param key="{$key-value[1]}" value="{$key-value[2]}" />
  }</parameters>
};

(:~
 : This function returns the string value of the parameters whose key matches a $string input.
 : @param $params element parameters
 : @param $string string as the "key" name
 : @return string value of the parameter with key $string
 :)
declare function oauth:parameters($params as element()+,$string as xs:string) as xs:string
{
  for $param in $params//param
  let $key := $param/@key/data(.)
  let $value := $param/@value/data(.)
  where $key = $string
  return xs:string($value)
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
 : @return -
 :)
declare %ann:sequential function oauth:http-request(
    $consumer-secret as xs:string,
    $method as xs:string,
    $oauth-token-secret as xs:string?,
    $params as element()+,
    $realm as xs:string?,
    $signature-method as xs:string,
    $url as xs:string
) (:as element(http:response):)
{
  let $base-url         := trace(tokenize($url, "\?")[1], "base-url")
  let $base-signature   := trace(oauth:signature-base-string($method, $base-url, $params),"base-sign")
  let $key    := trace(oauth:key($consumer-secret, $oauth-token-secret),"sign-key")
  let $signature   := trace(fn:encode-for-uri(oauth:signature($base-signature, $signature-method, $key)),"signature")
  let $authorization-header   := trace(oauth:authorization-header($params,$realm,$signature),"authorization-header")
  return http-client:send-request(
    <http:request href="{$url}" method="{$method}" >
      <http:header name="Authorization" value="{$authorization-header}" />
    </http:request>
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
declare %private %ann:sequential %ann:nondeterministic function oauth:format-request(
    $consumer-key as xs:string,
    $consumer-secret as xs:string,
    $method as xs:string,
    $oauth-token as xs:string?,
    $oauth-token-secret as xs:string?,
    $realm as xs:string?,
    $signature-method as xs:string,
    $url as xs:string,
    $additional-parameters as xs:string,
    $format-params as xs:boolean) (:as element()+:)
{
  let $version := "1.0"
  let $base-params := concat("&amp;oauth_consumer_key=",$consumer-key,"&amp;oauth_nonce=",trace(oauth:nonce(),"nonce"),
"&amp;oauth_signature_method=",$signature-method,"&amp;oauth_timestamp=",oauth:timestamp(),"&amp;oauth_version=",$version)
  let $params := oauth:parse-parameters(concat($additional-parameters,$base-params))
  let $response := trace(oauth:http-request($consumer-secret,$method,$oauth-token-secret,$params,$realm,$signature-method,$url), "response")
  return 
    if($response[1]/@status = 200)
    then 
      if ($format-params) then
        oauth:parse-parameters($response[2])
      else 
        $response[2]
    (:originally, this next line was it.:)
    (:else $response[2]:)
    else if ($response[1]/@status = 401)
    then error(xs:QName("oerr:OC003"), concat("Authorization header unauthorized: ", $response[2]//error/data(.)))
    else if ($response[1]/@status = 500)
    then error($oerr:OC004, concat("Internal server error", $response[2]))
    else $response[2]
};

declare %private %ann:sequential %ann:nondeterministic function oauth:format-request(
    $consumer-key as xs:string,
    $consumer-secret as xs:string,
    $method as xs:string,
    $oauth-token as xs:string?,
    $oauth-token-secret as xs:string?,
    $realm as xs:string?,
    $signature-method as xs:string,
    $url as xs:string,
    $additional-parameters as xs:string) (:as element()+:)
{
  oauth:format-request($consumer-key, $consumer-secret, $method, $oauth-token, $oauth-token-secret, $realm, $signature-method, $url, $additional-parameters, true())
};

(:~
 : This function finds the server-specific parameters. The specification states, "Servers MAY specify additional parameters..."
 : @see http://tools.ietf.org/html/rfc5849#section-2.1
 : @param $request element containing the client's request
 : @return may return parsed parameters or empty sequence if there were no server specific parameters
 :)
declare function oauth:additional-parameters($request as element()+) as element()?
{
  let $additional-parameters := 
    for $param in $request//param
    let $key := $param/@key/data(.)
    let $value := $param/@value/data(.)
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
  let $parameters :=
    if(empty($additional-parameters))
    then (:"":) ()
    else oauth:parse-parameters(concat("&amp;", oauth:normalization($additional-parameters,'=',(),"&amp;")))
  return $parameters
};

(:~
 : This function allows the client to obtain a set of temporary credentials from the service provider by making an authenticated HTTP request to the Temporary Credential Request endpoint.
 : This function is provided for convenience.
 : @see http://tools.ietf.org/html/rfc5849#section-2.1
 : @param $request request element containing the client's request
 : @return temporary credentials correctly parsed as parameter elements, or an error if http response status is not 200 OK
 :)
declare %ann:sequential %ann:nondeterministic function oauth:request-token($request as element(request)+) as element()+
{
  let $consumer-key := oauth:parameters($request,"oauth_consumer_key")
  let $consumer-secret := oauth:parameters($request,"oauth_consumer_secret")
  let $signature-method := 
    if(oauth:parameters($request,"oauth_signature_method") = "")
    then "HMAC-SHA1"
    else oauth:parameters($request,"oauth_signature_method")
  let $callback-url := oauth:parameters($request,"oauth_callback")
  let $realm := oauth:parameters($request,"realm")
  let $method := 
    if(oauth:parameters($request,"method") = "")
    then "GET"
    else oauth:parameters($request,"method")
  let $temporary-credential-request := oauth:parameters($request,"url")
  let $parameters := oauth:additional-parameters($request)
  return oauth:request-token(
    $consumer-key,
    $consumer-secret,
    $signature-method,
    $method,
    $realm,
    $temporary-credential-request,
    $callback-url,
    $parameters)
};

(:~
 : This function allows the client to obtain a set of token credentials from the service provider by making an authenticated HTTP request to the Token Request endpoint.
 : This function is provided for convenience.
 : @see http://tools.ietf.org/html/rfc5849#section-2.3
 : @param $request request element containing the client's request
 : @return token credentials correctly parsed as parameter elements, or an error if http response status is not 200 OK
 :)
declare %ann:sequential %ann:nondeterministic function oauth:access-token($request as element(request)+) as element()+
{
  let $consumer-key := oauth:parameters($request,"oauth_consumer_key")
  let $consumer-secret := oauth:parameters($request,"oauth_consumer_secret")
  let $signature-method := 
    if(oauth:parameters($request,"oauth_signature_method") = "")
    then "HMAC-SHA1"
    else oauth:parameters($request,"oauth_signature_method")
  let $callback-url := oauth:parameters($request,"oauth_callback")
  let $realm := oauth:parameters($request,"realm")
  let $method := 
    if(oauth:parameters($request,"method") = "")
    then "GET"
    else oauth:parameters($request,"method")
  let $token-request-uri := oauth:parameters($request,"url")
  let $oauth-token := oauth:parameters($request,"oauth_token")
  let $oauth-token-secret := oauth:parameters($request,"oauth_token_secret")
  let $oauth-verifier := oauth:parameters($request,"oauth_verifier")
  let $parameters := oauth:additional-parameters($request)
  return 
    oauth:access-token(
    $consumer-key,
    $consumer-secret,
    $signature-method,
    $realm,
    $oauth-token,
    $oauth-token-secret,
    $oauth-verifier,
    $method,
    $token-request-uri,
    $parameters)
};

(:~
 : This function allows the client access to the protected resources of the user.
 : This function is provided for convenience.
 : @see http://tools.ietf.org/html/rfc5849#section-3
 : @param $protected-resource (Not schema-validated) http:request element with http method and href.
 : @param $request request element containing the client's request
 : @return protected resources parsed as parameter elements, or an error if http response status is not 200 OK
 :)
declare %ann:sequential %ann:nondeterministic function oauth:protected-resource($protected-resource as element(http:request),$request as element(request)+) as element()+
{
  let $consumer-key := oauth:parameters($request,"oauth_consumer_key")
  let $consumer-secret := oauth:parameters($request,"oauth_consumer_secret")
  let $signature-method := 
    if(oauth:parameters($request,"oauth_signature_method") = "")
    then "HMAC-SHA1"
    else oauth:parameters($request,"oauth_signature_method")
  let $callback-url := oauth:parameters($request,"oauth_callback")
  let $realm := oauth:parameters($request,"realm")
  let $oauth-token := oauth:parameters($request,"oauth_token")
  let $oauth-token-secret := oauth:parameters($request,"oauth_token_secret")
  let $url := $protected-resource/@href/data(.)
  let $method := $protected-resource/@method/data(.)
  let $parameters := oauth:additional-parameters($request)
  return 
    oauth:protected-resource(
    $consumer-key,
    $consumer-secret,
    $signature-method,
    $oauth-token,
    $oauth-token-secret,
    $realm,
    $method,
    $url,
    $parameters)
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
declare %ann:sequential %ann:nondeterministic function oauth:request-token(
    $consumer-key as xs:string,
    $consumer-secret as xs:string,
    $signature-method as xs:string,
    $method as xs:string,
    $realm as xs:string,
    $temporary-credential-request as xs:string,
    $callback-url as xs:string,
    $additional-parameters as xs:string?) as element()+
{
  let $add := concat("oauth_callback=",fn:encode-for-uri($callback-url),$additional-parameters)
  return oauth:format-request($consumer-key,$consumer-secret,$method,(),(),$realm,$signature-method,$temporary-credential-request,$add)
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
 : @param $oauth-verifier The verification code
 : @param $additional-parameters Parameters specific to a certain step (access-token) of the OAuth authorization
 : @return token credentials correctly parsed as parameter elements, or an error if http response status is not 200 OK
 :)
declare %ann:sequential %ann:nondeterministic function oauth:access-token(
    $consumer-key as xs:string,
    $consumer-secret as xs:string,
    $signature-method as xs:string,
    $realm as xs:string,
    $oauth-token as xs:string,
    $oauth-token-secret as xs:string,
    $oauth-verifier as xs:string?,
    $method as xs:string,
    $token-request-uri as xs:string,
    $additional-parameters as xs:string?) as element()+
{
  let $add := concat("oauth_token=",$oauth-token,"&amp;oauth_verifier=",$oauth-verifier, $additional-parameters)
  return oauth:format-request($consumer-key,$consumer-secret,$method,$oauth-token,$oauth-token-secret,$realm,$signature-method,$token-request-uri,$add)
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
declare %ann:sequential %ann:nondeterministic function oauth:protected-resource(
    $consumer-key as xs:string,
    $consumer-secret as xs:string,
    $signature-method as xs:string,
    $oauth-token as xs:string,
    $oauth-token-secret as xs:string,
    $realm as xs:string,
    $method as xs:string,
    $url as xs:string,
    $additional-parameters as xs:string?) (:as element()+:)
{
  let $addition := concat("&amp;",tokenize($url, "\?")[2])
  let $add := 
    if ($addition eq "&amp;")
    then concat("oauth_token=",$oauth-token,$additional-parameters)
    else concat("oauth_token=",$oauth-token,$additional-parameters, $addition)
  return oauth:format-request($consumer-key,$consumer-secret,$method,$oauth-token,$oauth-token-secret,$realm,$signature-method,$url,$add, false())
};
