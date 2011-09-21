(: Fetch a valid module URI but as SOME_CONTENT :)
import module namespace fetch = "http://www.zorba-xquery.com/modules/fetch#2.0";

fetch:content("http://www.zorba-xquery.com/modules/ext", "SOME_CONTENT")
