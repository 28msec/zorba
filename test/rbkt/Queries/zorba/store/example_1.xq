import module namespace http = "http://www.zorba-xquery.com/modules/http-client";

import module namespace doc = "http://www.zorba-xquery.com/modules/store/dynamic/documents";

let $mydoc := http:get-node("http://zorba-xquery.com/rest-tests/doc.html")[2]
return
  {
    doc:put("mydoc.xml", $mydoc); (: add the document with name mydoc.xml :)
    doc:document("mydoc.xml")
  }
