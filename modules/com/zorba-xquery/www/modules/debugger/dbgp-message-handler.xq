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


declare variable $dmh:endl as xs:string := "
";

(:~
 : Set this variale to true if you want to have mode debug information when
 : an error occurs.
 :)
declare variable $dmh:debug as xs:boolean := fn:true();


declare %private function dmh:status($resp as element(response))
{
  fn:concat(
    $resp/@status,
    if ($resp/@status eq "break" and $resp/@reason ne "ok") then
      fn:concat(" (", $resp/@reason, ")")
    else
      ""
  )
};

declare %private function dmh:run($resp as element(response))
{
  if ($resp/@status eq "starting") then
    "Starting query"
  else
    dmh:status($resp)
};

declare %private function dmh:stop($resp as element(response))
{
  dmh:status($resp)
};

declare %private function dmh:breakpoint-set($resp as element(response))
{
  fn:concat("set breakpoint with id ", data($resp/@id), " and state ", data($resp/@state))
};

declare %private function dmh:breakpoint-get($resp as element(response))
{
  let $b := $resp/breakpoint
  return
    fn:concat(
      "Breakpoint ", $b/@id, $dmh:endl,
      "  type:  ", $b/@type, $dmh:endl,
      "  file:  ", $b/@filename, $dmh:endl,
      "  line:  ", $b/@lineno, $dmh:endl,
      "  state: ", $b/@state
    )
};

declare %private function dmh:breakpoint-list($resp as element(response))
{
  fn:string-join(
    for $b in $resp/breakpoint
    return concat("Breakpoint ", data($b/@id), " at ", data($b/@filename), ":", data($b/@lineno), " ", data($b/@state)),
    $dmh:endl
  )
};

declare %private function dmh:breakpoint-remove($resp as element(response))
{
  "Breakpoint removed"
};

declare %private function dmh:stack-depth($resp as element(response))
{
  concat("Depth: ", data($resp/@depth))
};

declare %private function dmh:stack-get($resp as element(response))
{
  string-join(
    for $s in $resp/stack
    return concat("Level ", data($s/@level), " at ", data($s/@filename), ":", data($s/@lineno)),
    $dmh:endl
  )
};


declare %private function dmh:context-names($resp as element(response))
{
  string-join(
    for $c in $resp/context
    return concat("Context: ", data($c/@name), " id: ", data($c/@id)),
    $dmh:endl
  )
};

declare %private function dmh:context-get($resp as element(response))
{
  string-join(
    for $p in $resp/property
    return concat(data($p/@fullname), ": [", data($p/@type), "]",
                  if ($p/text() ne "") then concat(": ", base64:decode($p/text())) else ""),
    $dmh:endl
  )
};

declare %private function dmh:eval($resp as element(response))
{
  if ($resp/@success eq "1") then
    dmh:context-get($resp)
  else
    dmh:report-error("An unknown error occured while evaluating expression.")
};

declare %private function dmh:report-error(
  $message as xs:string)
{
  dmh:report-error($message, ())
};

declare %private function dmh:report-error(
  $message as xs:string,
  $debugMessage as xs:string*)
{
  fn:string-join(
    (
      (: the error message :)
      fn:concat("ERROR: ", $message),

      (: the debug info :)
      if ($dmh:debug and fn:string-length($debugMessage) gt 0) then
        fn:concat("DEBUG: ", $debugMessage)
      else
        ()
    ),
    $dmh:endl
  )
};

declare %private function dmh:process-response($resp as element(response))
{
  switch ($resp/@command)
  case "eval"               return dmh:eval($resp)
  case "context_get"        return dmh:context-get($resp)
  case "context_names"      return dmh:context-names($resp)
  case "stack_get"          return dmh:stack-get($resp)
  case "stack_depth"        return dmh:stack-depth($resp)
  case "breakpoint_remove"  return dmh:breakpoint-remove($resp)
  case "breakpoint_list"    return dmh:breakpoint-list($resp)
  case "breakpoint_get"     return dmh:breakpoint-get($resp)
  case "breakpoint_set"     return dmh:breakpoint-set($resp)
  case "run"                return dmh:run($resp)
  case "stop"               return dmh:stop($resp)
  case "status"             return dmh:status($resp)

  default
    return dmh:report-error(fn:concat("Command not implemented: ", $resp/@command))
};

declare function dmh:process-init($init as element(init))
{
  fn:string-join(
    ("Established connection with", $init/@language, "client", $init/@appid),
    " "
  )
};

declare function dmh:process($message as element())
{
  let $nodeName := fn:local-name($message)
  let $id := fn:data($message/@transaction_id)
  return
    if ($nodeName eq "response") then
      (: no transaction_id :)
      if (fn:count($id) eq 0 or $id eq "") then
        (0, dmh:report-error("Invalid response", "Missing or empty response transaction ID."))
      (: wrong transaction_id :)
      else if (xs:string(fn:number($id)) eq "NaN") then
        (0, dmh:report-error("Invalid response", "Invalid value for response transaction ID."))
      (: no or empty command :)
      else if (fn:count($message/@command) eq 0 or $message/@command eq "") then
        ($id, dmh:report-error("Invalid response", "Missing or empty response command attribute."))
      (: error response :)
      else if (fn:exists($message/error)) then
        ($id, dmh:report-error(fn:data($message/error/message), fn:concat("Error code: ", fn:data($message/error/@code))))
      else
        ($id, dmh:process-response($message))
    else if ($nodeName eq "init") then
      (0, dmh:process-init($message))
    else
      (
        if (fn:count($id) eq 0 or $id eq "" or xs:string(fn:number($id)) eq "NaN") then
          0
        else
          $id,
        dmh:report-error(fn:concat("Unknown message node: ", $nodeName))
      )
};
