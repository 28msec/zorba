(: Fetch a schemas's content :)
import module namespace fetch = "http://zorba.io/modules/fetch";

fn:parse-xml(
  fetch:content("http://zorba-tests.28.io/modules/theschema", "SCHEMA")
)/*:schema/*:element/@name/data()
