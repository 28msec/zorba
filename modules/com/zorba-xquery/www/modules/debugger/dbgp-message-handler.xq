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
module namespace dmh = "http://www.zorba-xquery.com/modules/debugger/dbgp-message-handler";

import module namespace base64 = "http://www.zorba-xquery.com/modules/converters/base64";


declare variable $dmh:endl as xs:string := '
';

declare %private function dmh:has-to-stop($resp as element())
{
  fn:not(($resp/@command eq "stop" and $resp/@reason eq "ok")
    or ($resp/@status eq "stopped")
    or ($resp/@status eq "stopping"))
};

declare %private function dmh:status($resp as element())
{
  fn:concat(
    "Status: ", $resp/@status, $dmh:endl,
    "Reason: ", $resp/@reason, $dmh:endl,
    let $msg := $resp/text()
    return
      if (fn:empty($msg) or $msg eq "") then
        ""
      else
        fn:concat($msg, $dmh:endl)
  )
};

declare %private function dmh:run($resp as element())
{
  if ($resp/@status eq "starting") then
    "Starting query"
  else
    dmh:status($resp)
};

declare %private function dmh:stop($resp as element())
{
  dmh:status($resp)
};

declare %private function dmh:breakpoint-set($resp as element())
{
  if ($resp/error) then
    fn:concat("Error when setting a breakpoint: ", if ($resp/error/message) then $resp/error/message/text() else concat(" errcode: ", data($resp/error/@code)))
  else
    fn:concat("set breakpoint with id ", data($resp/@id), " and state ", data($resp/@state))
};

declare %private function dmh:breakpoint-list($resp as element())
{
  string-join(
    for $b in $resp/breakpoint
    return concat("Breakpoint ", data($b/@id), " at ", data($b/@filename), ":", data($b/@lineno), " ", data($b/@state)),
    $dmh:endl
  )
};

declare %private function dmh:breakpoint-remove($resp as element())
{
  "Breakpoint removed"
};

declare %private function dmh:stack-depth($resp as element())
{
  concat("Depth: ", data($resp/@depth))
};

declare %private function dmh:stack-get($resp as element())
{
  string-join(
    for $s in $resp/stack
    return concat("Level ", data($s/@level), " at ", data($s/@filename), ":", data($s/@lineno)),
    $dmh:endl
  )
};


declare %private function dmh:context-names($resp as element())
{
  string-join(
    for $c in $resp/context
    return concat("Context: ", data($c/@name), " id: ", data($c/@id)),
    $dmh:endl
  )
};

declare %private function dmh:context-get($resp as element())
{
  string-join(
    for $p in $resp/property
    return concat(data($p/@fullname), ": [", data($p/@type), "]",
                  if ($p/text() ne "") then concat(": ", base64:decode($p/text())) else ""),
    $dmh:endl
  )
};

declare %private function dmh:eval($resp as element())
{
  if ($resp/@success eq "1") then
    dmh:context-get($resp)
  else
    concat("Eval failed", ":", $resp/error/message/text())
};

declare %private function dmh:process-response($resp as element())
{
  if ($resp/@command eq "") then
    (fn:true(), $resp/fn:data(@transaction_id), dmh:status($resp))
  else
    (
      dmh:has-to-stop($resp),

      $resp/fn:data(@transaction_id),

      switch (fn:local-name($resp))
      case "eval"               return dmh:eval($resp)
      case "context_get"        return dmh:context-get($resp)
      case "context_names"      return dmh:context-names($resp)
      case "stack_get"          return dmh:stack-get($resp)
      case "stack_depth"        return dmh:stack-depth($resp)
      case "breakpoint_remove"  return dmh:breakpoint-remove($resp)
      case "breakpoint_list"    return dmh:breakpoint-list($resp)
      case "breakpoint_set"     return dmh:breakpoint-set($resp)
      case "run"                return dmh:run($resp)
      case "stop"               return dmh:stop($resp)
      case "status"             return dmh:status($resp)
      default return fn:concat("Command not implemented: ", fn:node-name($resp))
    )
};

declare function dmh:process-init($init as element())
{
  fn:true(),
  0,
  fn:concat(fn:string-join(
  ('Established connection with', $init/@language, 'client', $init/@appid), ' '), '
')
};

declare function dmh:process($message as element())
{
  switch (fn:local-name($message))
  case "init"       return dmh:process-init($message)
  case "response"   return dmh:process-response($message)
  default return
    (
      fn:true(),
      if (fn:exists($message/@transaction_id)) then
        $message/fn:data(@transaction_id)
      else
        0,
      fn:concat("ERROR: Unknown message node: ", fn:node-name($message))
    )
};
