import module namespace http = "http://www.zorba-xquery.com/modules/http-client";

import module namespace doc = "http://www.zorba-xquery.com/modules/store/dynamic/documents";

declare namespace x = "http://www.zorba-xquery.com/http-test-data";

let $mydoc := http:get-node("http://zorbatest.lambda.nu:8080/http-test-data/http2.xml")[2]
return
  {
    doc:put("mydoc.xml", $mydoc); (: add the document with name mydoc.xml :)

    replace value of node
      doc:document("mydoc.xml")//x:title
    with
      "Excel Functions";

    doc:document("mydoc.xml")//x:title/text()
  }
