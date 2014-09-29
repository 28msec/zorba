import module namespace http = "http://www.zorba-xquery.com/modules/http-client";

import module namespace doc = "http://zorba.io/modules/store/documents";

let $mydoc := http:get-node("http://zorbatest.28.io:8080/http-test-data/http1.xml")[2]
return
  {
    doc:put("mydoc.xml", $mydoc); (: add the document with name mydoc.xml :)
    doc:document("mydoc.xml")
  }
