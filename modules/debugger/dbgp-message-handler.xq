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
 : Zorba debugger module.
 :
 : @author Gabriel Petrovay
 : @project Zorba/Debugger/Debugger
 :)
module namespace dmh = "http://zorba.io/modules/dbgp-message-handler";

import module namespace base64 = "http://zorba.io/modules/base64";

declare namespace ver = "http://zorba.io/options/versioning";
declare option ver:module-version "1.0";

(:~
 : Endline.
 :)
declare %private variable $dmh:endl as xs:string := "
";

(:~
 : Set this variale to true if you want to have mode debug information when
 : an error occurs.
 :)
declare variable $dmh:debug as xs:boolean := fn:false();


declare %private function dmh:status($resp as element(response))
{
  switch ($resp/@status)
  case "starting"
  case "stopping"
    return "idle"
  case "break"
    return
      let $status := $resp/@status
      let $whyInfo :=
        if ($resp/@reason ne "ok") then
          fn:concat(" (", $resp/@reason, ")")
        else
          ""
      let $whereInfo :=
        if ($resp/text()[1] ne "") then
          fn:concat(" in ", $resp/text()[1])
        else
          ""
      return
        fn:concat($status, $whyInfo, $whereInfo)
  default
    return $resp/@status
};

declare %private function dmh:source($resp as element(response))
{
  $resp/text()
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
    let $bs := $resp/breakpoint
    return
      if (fn:exists($bs)) then
        fn:concat(
          "--------------------------------------", $dmh:endl,
          "|   ID   |   State   |  Line  | File", $dmh:endl,
          "|--------|-----------|--------|-------", $dmh:endl,
          fn:string-join(
            for $b in $bs
            return
              fn:concat(
                "| ", dmh:lpottl($b/@id, 6, " "), " ",
                "| ", if ($b/@state eq "enabled") then "enabled  " else "disabled ", " ",
                "| ", dmh:lpottl($b/@lineno, 6, " "), " ",
                "| ", $b/@filename, $dmh:endl),
            ""
          ),
          "--------------------------------------", $dmh:endl
        )
      else
        "No breakpoints set"
  )
};

(:~
 : left-pad-or-trim-to-length
 :)
declare %private function dmh:lpottl($value as xs:string, $length as xs:integer, $padChar as xs:string)
 as xs:string
{
  let $padChar := fn:substring($padChar, 1, 1)
  let $len := fn:string-length($value)
  return
    if ($len < $length) then
      let $pad :=
        fn:string-join(
          for $i in 1 to $length - $len
          return $padChar,
          ""
        )
      return
        fn:concat($pad, $value)
    else
      fn:substring($value, $len - $length + 1)
};

declare %private function dmh:breakpoint-remove($resp as element(response))
{
  "Breakpoint removed"
};

declare %private function dmh:stack-depth($resp as element(response))
{
  fn:concat("depth: ", $resp/@depth)
};

declare %private function dmh:stack-get($resp as element(response))
{
  fn:string-join(
    for $s in $resp/stack
    return
      fn:concat("#", $s/@level, " in ", $s/@where, " at ", $s/@filename, ":", $s/@lineno),
    $dmh:endl
  )
};


declare %private function dmh:context-names($resp as element(response))
{
  fn:string-join(
    for $c in $resp/context
    return
      fn:concat("context ", $c/@id, ": ", $c/@name),
    $dmh:endl
  )
};

declare %private function dmh:context-get($resp as element(response))
{
  fn:string-join(
    for $p in $resp/property
    return
      fn:concat($p/@fullname, " ", $p/@type,
        if ($p/text() ne "") then
          fn:concat(": ", base64:decode($p/text()))
        else
          ""
      ),
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
      fn:concat("Error: ", $message),

      (: the debug info :)
      if ($dmh:debug and fn:string-length($debugMessage) gt 0) then
        $debugMessage
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
  case "source"             return dmh:source($resp)

  (: continuation command only need to display/process the status :)
  case "run"
  case "step_into"
  case "step_out"
  case "step_over"
  case "stop"
  case "status"
    return dmh:status($resp)

  default
    return dmh:report-error(fn:concat("Command not implemented: ", $resp/@command))
};

declare %private function dmh:process-init($init as element(init))
{
  fn:string-join(
    ("Established connection with", $init/@language, "client", $init/@appid),
    " "
  )
};

(:~
 : Process one message received from the Zorba debugger server.
 : @param $message the message.
 : @return ().
 :)
declare function dmh:process($message as element()) as xs:anyAtomicType*
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
