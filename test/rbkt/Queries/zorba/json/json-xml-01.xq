import module namespace jsd="http://zorba.io/modules/json-xml";
import module namespace jsdi="http://jsoniq.org/functions";

declare variable $jsnTree := jsdi:parse-json('{
"phone" : ["604 123-1234","406 321-4321"],
"phoneNumbers2" : [ "212 732-1234", "646 123-4567" ]
}'); 
declare variable $asXML := jsd:json-to-xml($jsnTree);

[
  $asXML
]
