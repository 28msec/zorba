import module namespace cdml = "http://www.zorba-xquery.com/modules/store/dynamic/collections/dml";

import module namespace http = "http://www.zorba-xquery.com/modules/http-client";

import module namespace csv = "http://www.zorba-xquery.com/modules/converters/csv";

let $data := http:get-text("http://www.zorba-xquery.com/rest-tests/eqs7day-M1.txt")[2]
for $entry in csv:parse($data, ())[position() > 1] (: skip csv header row :)
return
  cdml:insert-nodes-last(xs:QName("earthquakes"), $entry );
