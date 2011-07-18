module namespace client = 'http://www.zorba-xquery.com/examples/twitter/client';

import module namespace cmd = 'http://www.zorba-xquery.com/examples/commandline';
import module namespace file = 'http://expath.org/ns/file';
import module namespace oauth = "http://www.zorba-xquery.com/modules/oauth/client";

declare namespace ann = "http://www.zorba-xquery.com/annotations";
declare namespace output = 'http://www.w3.org/2010/xslt-xquery-serialization';

declare %private variable $client:oauth-token as xs:string := "";
declare %private variable $client:oauth-token-secret as xs:string := "";
declare %private variable $client:screen-name as xs:string := "";
declare %private variable $client:token-file as xs:string := "token.txt";
declare %private variable $client:consumer-key as xs:string := "YOUR_CONSUMER_KEY";
declare %private variable $client:consumer-secret as xs:string := "YOUR_CONSUMER_SECRET";

declare %ann:sequential %ann:nondeterministic function client:tweets()
{
  variable $answer :=
    oauth:protected-resource($client:consumer-key,
                         $client:consumer-secret,
                         "HMAC-SHA1",
                         $client:oauth-token,
                         $client:oauth-token-secret,
                         "twitter.com",
                         "GET",
                         "http://api.twitter.com/statuses/home_timeline.xml",
                         ());
  cmd:print-line(string-join(
      for $status in $answer//status
      return string-join((
                              concat("Id: ", $status/id/text()),
                              concat("From User: ", $status/user/name/text()),
                              "",
                              $status/text/text()
                            ), $cmd:endl)
    , concat($cmd:endl, "=====================================================================", $cmd:endl))
  );
};

declare %ann:sequential %ann:nondeterministic function client:get-tweet($id as xs:string) as element(status)
{
  variable $answer :=
    oauth:protected-resource($client:consumer-key,
                         $client:consumer-secret,
                         "HMAC-SHA1",
                         $client:oauth-token,
                         $client:oauth-token-secret,
                         "twitter.com",
                         "GET",
                         concat("http://api.twitter.com/statuses/show/", $id, ":id.xml"),
                         ());
  exit returning $answer/status;
};

declare %private %ann:sequential %ann:nondeterministic function client:oauth() {
  variable $pin as xs:string;
  variable $access-token;
  variable $req-answer := 
    oauth:request-token($client:consumer-key,
                        $client:consumer-secret,
                        "HMAC-SHA1",
                        "POST",
                        "twitter.com",
                        "http://api.twitter.com/oauth/request_token",
                        "oob", ());
  cmd:print(string-join(("Please type in the folloing URL into your browser to authorize the application:",
                         concat("http://api.twitter.com/oauth/authorize?oauth_token=", data($req-answer/param[@key = "oauth_token"]/@value)),
                         "Then copy the showed up PIN into this window",
                         "PIN> ")
                   , $cmd:endl));
  $pin := cmd:get-line();
  $access-token :=
    oauth:access-token($client:consumer-key,
                       $client:consumer-secret,
                       "HMAC-SHA1",
                       "twitter.com",
                       data($req-answer/param[@key = "oauth_token"]/@value),
                       data($req-answer/param[@key = "oauth_token_secret"]/@value),
                       $pin,
                       "POST",
                       "https://api.twitter.com/oauth/access_token",
                       ());
  $client:oauth-token := xs:string(data($access-token/param[@key = "oauth_token"]/@value));
  $client:oauth-token-secret := xs:string(data($access-token/param[@key = "oauth_token_secret"]/@value));
  $client:screen-name := xs:string(data($access-token/param[@key = "screen_name"]/@value));
};

declare %ann:sequential %ann:nondeterministic function client:authenticate()
{
  variable $file-content as xs:string+;
  if (file:is-file($client:token-file)) then {
    $file-content := tokenize(file:read-text($client:token-file), " ");
    $client:oauth-token := $file-content[1];
    $client:oauth-token-secret := $file-content[2];
    $client:screen-name := $file-content[3];
  }
  else {
    client:oauth();
    file:write($client:token-file, string-join(($client:oauth-token, $client:oauth-token-secret, $client:screen-name), " "),
      <output:serialization-parameters>
        <output:method value="text"/>
      </output:serialization-parameters>);
  }
  cmd:print-line(concat("Authenticated as User ", $client:screen-name));
};

