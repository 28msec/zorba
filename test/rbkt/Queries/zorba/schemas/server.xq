(: Schema Imports :)
import schema namespace oas="http://www.28msec.com/modules/oauth/server" at
"server.xsd";

(: remove old tokens (request and authorized-request tokens) :)
declare function local:remove-tokens()
{
let $timestamp := ()
let $token-status := (oas:token-status("request"),
oas:token-status("authorized-request"))
let $tokens := ()[@status = $token-status and xs:dateTime(@timestamp) lt
$timestamp]
return
()
};

()
