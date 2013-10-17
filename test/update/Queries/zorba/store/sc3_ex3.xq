import module namespace doc = "http://zorba.io/modules/store/documents";

import module namespace j = "http://zorba.io/modules/json-xml";

j:xml-to-json(
  doc:document("meat_poultry.xml")/root/row,
  { "json-format" : "JsonML-array" }
)
