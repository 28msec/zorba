(: rest-getTidy example using payload, headers and Tidy options :)

import module namespace zorba-rest = "http://www.zorba-xquery.com/zorba/rest-functions"; 

let $tmp := zorba-rest:getTidy("http://www.google.com/search",
  '"newline=CRLF","doctype=omit","force-output","bare=yes"',
  <payload>
    <part name="q">zorba xquery</part>
  </payload>,
  <headers>
    <header name="Referer">http://www.yahoo.com/</header>
  </headers>)

return $tmp//zorba-rest:status-code
