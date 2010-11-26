import module namespace http = 'http://expath.org/ns/http-client';

let $status-with := http:send-request(<http:request href="http://www.apple.ch" method="HEAD" follow-redirect="true"/>)[1]/@status/data(.)
let $status-without := http:send-request(<http:request href="http://www.apple.ch" method="HEAD" follow-redirect="false"/>)[1]/@status/data(.)
return
  if ($status-without eq 301) then
    $status-with
  else "failed"
