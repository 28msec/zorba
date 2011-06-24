(: Example of zorba-rest:post with a XML part :)

import module namespace zorba-rest = "http://www.zorba-xquery.com/zorba/rest-functions";

zorba-rest:post(
  "http://www.example.com/path",
  <payload>
    <data attr="value">
      <a>text</a>
      <b>text2</b>
    </data>
  </payload>)
