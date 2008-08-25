(: Example of zorba-rest:post with string parameters :)

import module namespace zorba-rest = "http://www.zorba-xquery.com/zorba/rest-functions";

zorba-rest:post(
  "http://www.example.com/path",
  <payload content-type="multipart/form-data">
    <part name="parameter1">value1</part>
    <part name="parameter2">value2</part>
  </payload>)
