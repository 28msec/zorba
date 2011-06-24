(: Complex zorba-rest:get example with parameters and headers :)

import module namespace zorba-rest = "http://www.zorba-xquery.com/zorba/rest-functions";

zorba-rest:get(
  "http://www.example.com/path",
  <payload>
    <part name="parameter1">value1</part>
    <part name="parameter2">value2</part>
  </payload>,
  <headers>
    <header name="Referer">http://www.example2.com/path2</header>
    <header name="User_agent">ZorbaREST</header>
  </headers>)
