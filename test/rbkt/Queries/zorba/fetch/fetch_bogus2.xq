(: Fetch a valid module URI but as SOME_CONTENT :)
import module namespace fetch = "http://www.zorba-xquery.com/modules/fetch";

fetch:content("http://zorba-tests.28msec.us/modules/ext", "SOME_CONTENT")
