import module namespace cdml = "http://zorba.io/modules/store/dynamic/collections/dml";

import module namespace http = "http://www.zorba-xquery.com/modules/http-client";

import module namespace csv = "http://www.zorba-xquery.com/modules/converters/csv";

let $data := http:get-text("http://zorbatest.28.io:8080/http-test-data/eqs7day-M1.txt")[2]
for $entry in csv:parse($data, ())[position() > 1] (: skip csv header row :)
return
  cdml:insert-last(xs:QName("earthquakes"), $entry );
