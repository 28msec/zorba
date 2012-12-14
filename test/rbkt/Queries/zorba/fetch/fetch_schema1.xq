(: Fetch a schemas's content :)
import module namespace fetch = "http://www.zorba-xquery.com/modules/fetch";

fn:parse-xml(
  fetch:content("http://zorba-tests.28msec.us/modules/theschema", "SCHEMA")
)/*:schema/*:element/@name/data()
