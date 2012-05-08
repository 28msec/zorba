(: Fetch a random file from the filesystem :)
import module namespace fetch = "http://www.zorba-xquery.com/modules/fetch#2.0";

fetch:content-binary("http://www.zorba-xquery.com/modules/fetch", "MODULE")
