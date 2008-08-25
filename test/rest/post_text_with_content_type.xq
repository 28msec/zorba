(: Example of zorba-rest:post with a text content :)

import module namespace zorba-rest = "http://www.zorba-xquery.com/zorba/rest-functions";

zorba-rest:post(
  "http://www.example.com/path",
  <payload content-type="text/plain">This is a test</payload>)
