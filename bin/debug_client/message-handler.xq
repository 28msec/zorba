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

import module namespace refl = 'http://www.zorba-xquery.com/modules/reflection';
import module namespace sctx = "http://www.zorba-xquery.com/modules/introspection/sctx";
import module namespace base64 = "http://www.zorba-xquery.com/modules/converters/base64";


declare variable $local:localns as xs:string := 'http://www.w3.org/2005/xquery-local-functions';


declare variable $local:endl as xs:string := '
';

declare function local:has-to-stop($resp as element())
{
  fn:not(($resp/@command/data(.) eq "stop" and $resp/@reason/data(.) eq "ok")
    or ($resp/@status/data(.) eq "stopped")
    or ($resp/@status/data(.) eq "stopping"))
};

declare function local:status($resp as element())
{
  fn:concat(
    "Status: ", $resp/@status/data(.), $local:endl,
    "Reason: ", $resp/@reason/data(.), $local:endl,
    let $msg := $resp/text()
    return
      if (fn:empty($msg) or $msg eq "") then
        ""
      else
        fn:concat($msg, $local:endl)
  )
};


declare function local:run($resp as element()) {
  if ($resp/@status/data(.) eq "starting") then
    "Starting query"
  else
    local:status($resp)
};

declare function local:stop($resp as element())
{
  local:status($resp)
};

declare function local:breakpoint_set($resp as element())
{
  if ($resp/error) then
    fn:concat("Error when setting a breakpoint: ", if ($resp/error/message) then $resp/error/message/text() else concat(" errcode: ", data($resp/error/@code)))
  else
    fn:concat("set breakpoint with id ", data($resp/@id), " and state ", data($resp/@state))
};

declare function local:breakpoint_list($resp as element())
{
  string-join(
    for $b in $resp/breakpoint
    return concat("Breakpoint ", data($b/@id), " at ", data($b/@filename), ":", data($b/@lineno), " ", data($b/@state)),
    $local:endl
  )
};

declare function local:breakpoint_remove($resp as element())
{
  "Breakpoint removed"
};

declare function local:stack_depth($resp as element())
{
  concat("Depth: ", data($resp/@depth))
};

declare function local:stack_get($resp as element())
{
  string-join(
    for $s in $resp/stack
    return concat("Level ", data($s/@level), " at ", data($s/@filename), ":", data($s/@lineno)),
    $local:endl
  )
};


declare function local:context_names($resp as element())
{
  string-join(
    for $c in $resp/context
    return concat("Context: ", data($c/@name), " id: ", data($c/@id)),
    $local:endl
  )
};

declare function local:context_get($resp as element())
{
  string-join(
    for $p in $resp/property
    return concat(data($p/@fullname), ": [", data($p/@type), "]",
                  if ($p/text() ne "") then concat(": ", base64:decode($p/text())) else ""),
    $local:endl
  )
};

declare function local:eval($resp as element())
{
  if (data($resp/@success) eq "1") then
    local:context_get($resp)
  else
    concat("Eval failed", ":", $resp/error/message/text())
};

declare function local:process-response($resp as element())
{
  if (data($resp/@command) eq "") then
    (fn:true(), $resp/@transaction_id/data(.), local:status($resp))
  else
    let $fun-cont-name := fn:QName($local:localns, concat("local:", $resp/@command/data(.), "-cont"))
    let $fun-msg-name := fn:QName($local:localns, concat("local:", $resp/@command/data(.)))
    return (
      if (sctx:function-arguments-count($fun-cont-name) = 1) then
        refl:invoke-simple($fun-cont-name, $resp)
      else
        local:has-to-stop($resp),
      $resp/@transaction_id/data(.),
      if (sctx:function-arguments-count($fun-msg-name) = 1) then
        refl:invoke-simple($fun-msg-name, $resp)
      else
        "Recieved a message - command not implemented"
    )
};

declare function local:process-init($init as element())
{
  fn:true(),
  0,
  fn:concat(fn:string-join(
  ('Established connection with', $init/@language/data(.), 'client', $init/@appid/data(.)), ' '), '
')
};

declare function local:main($response as element()) {
  let $process-fun as xs:QName := fn:QName($local:localns, concat("local:process-", node-name($response)))
  return
    if (sctx:function-arguments-count($process-fun) = 1) then
      refl:invoke-simple($process-fun, $response)
    else (
          true(),
          ($response/@transaction_id, 0)[1]/data(.),
          "ERROR: Recieved unknown node from client"
         )
};
