(: Example of zorba-rest:post with a string content :)

import module namespace zorba-rest = "http://www.zorba-xquery.com/zorba/rest-functions";

zorba-rest:post(
  "http://www.example.com/path",
  <payload>This is a test</payload>)
