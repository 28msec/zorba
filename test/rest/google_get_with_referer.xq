(: Invoke zorba-rest:get and pass a value for the Referer header :)

import module namespace zorba-rest = "http://www.zorba-xquery.com/zorba/rest-functions";

zorba-rest:get(
    "http://www.google.com/", 
    (),
    <headers>
      <header name="Referer">http://www.yahoo.com/</header>
    </headers>)
