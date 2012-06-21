(: Fetch a schemas's content :)
import module namespace fetch = "http://www.zorba-xquery.com/modules/fetch";

fn:parse-xml(
  fetch:content("http://www.zorba-xquery.com/modules/theschema", "SCHEMA")
)/*:schema/*:element/@name/data()
