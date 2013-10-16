(: Fetch a random file from the filesystem :)
import module namespace fetch = "http://zorba.io/modules/fetch";

fetch:content("http://zorba-tests.28msec.us/random-file", "SOME_CONTENT")
