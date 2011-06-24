(: Example of zorba-rest:post with XML parts and strings as parameters :)

import module namespace zorba-rest = "http://www.zorba-xquery.com/zorba/rest-functions";

zorba-rest:post(
  "http://www.example.com/path",
  <payload content-type="multipart/form-data">
    <part name="parameter1">value1</part>
    <part name="parameter2">
      <data attr="value">
        <a>text</a>
        <b>text2</b>
      </data>
    </part>
  </payload>)
