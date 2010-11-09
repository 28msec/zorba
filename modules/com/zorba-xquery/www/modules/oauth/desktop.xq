(:~
: OAuth Desktop Module
: This module provides the functions necessary to acquire access to the personal resources of a 
: user through the open standard called <a href="http://oauth.net/" target="_blank">OAuth</a>.
: The application/mashup creator does not need to know the specifics of
:<a href="http://oauth.net/" target="_blank">OAuth</a> to use this module.
: @author Stephanie Russell
: @see <a href="http://oauth.net/" target="_blank">OAuth</a>
: @see <a href="http://tools.ietf.org/html/draft-hammer-http-token-auth-01" target="_blank">OAuth token</a>
:
:)

module namespace oauth-desktop = 'http://www.zorba-xquery.com/modules/oauth/desktop';
import module namespace io = "http://www.zorba-xquery.com/zorba/util-functions";

(:~
 : Resource Owner Authorization.
 :
 : @see http://tools.ietf.org/html/rfc5849#section-2.2
 : @param $oauth-token see <a href="http://tools.ietf.org/html/draft-hammer-http-token-auth-01" target="_blank">OAuth token</a>
 : @return authorization string.
 :)
declare sequential function oauth-desktop:authorize-twitter($oauth-token as xs:string) as xs:string
{
  (:
  declare $authorization-uri:= concat("http://api.twitter.com/oauth/authorize?oauth_token=", $oauth-token);
  io:print((concat("Type the following URL in your browser: ", $authorization-uri),"&#xA;"," Type pin code: "));
  let $oauth-verifier := io:read-line()
  return $oauth-verifier;
  :)
  let $authorization-uri:= concat("http://api.twitter.com/oauth/authorize?oauth_token=", $oauth-token)
  return concat("Type the following URL in your browser: ", $authorization-uri,"&#xA;"," Type pin code: ");
};
