import module namespace doc = "http://www.zorba-xquery.com/modules/store/dynamic/documents";

import module namespace j = "http://zorba.io/modules/json-xml";

j:xml-to-json(
  doc:document("meat_poultry.xml")/root/row,
  { "json-format" : "JsonML-array" }
)
