(: Example of zorba-rest:post with the contents of an image file :)

import module namespace zorba-rest = "http://www.zorba-xquery.com/zorba/rest-functions";

zorba-rest:post(
  "http://www.example.com/path",
  <payload filename="test.jpg" content-type="image/jpeg"/>)
