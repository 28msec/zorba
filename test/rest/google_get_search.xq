(: Invoke Google search for the "zorba xquery" term :)

import module namespace zorba-rest = "http://www.zorba-xquery.com/zorba/rest-functions";

zorba-rest:get("http://www.google.com/search",
  <payload>
    <part name="q">zorba xquery</part>
  </payload>)
