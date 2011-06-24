(: Example of zorba-rest:post with the contents of a file. The default application/octet-stream content type is used :)

import module namespace zorba-rest = "http://www.zorba-xquery.com/zorba/rest-functions";

zorba-rest:post(
  "http://www.example.com/path",
  <payload filename="test.bin" /> )
