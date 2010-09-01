import module namespace oauth = "http://www.zorba-xquery.com/modules/oauth/client";
import module namespace desktop = "http://www.zorba-xquery.com/modules/oauth/desktop";

let $method := "GET"
let $consumer-key := "AJNRLGd7aT0SvQMLjudog"
let $consumer-secret := "hOUuiWTlqiBFNfwh5nIaKQZ9KS5hSkfI1eltrXG8r4I"
let $signature-method := "HMAC-SHA1"
let $realm := "twitter.com"
let $temporary-credential-request := "http://twitter.com/oauth/request_token"
let $callback-url := "oob"
let $response := oauth:request-token($consumer-key,$consumer-secret,$signature-method, $method,$realm,$temporary-credential-request,$callback-url,"")
let $oauth-token := oauth:parameters($response,"oauth_token")
let $auth := desktop:authorize-twitter($oauth-token)
return 
  if(empty($auth))
  then <test name="test-authorize-twitter" succeed="false" message="Authorization not found" />
  else <test name="test-authorize-twitter" succeed="true" message="Authorization complete" />
