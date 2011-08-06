import module namespace doc = "http://www.zorba-xquery.com/modules/store/dynamic/documents";

import module namespace j = "http://www.zorba-xquery.com/modules/converters/json";

j:serialize(
  doc:document("meat_poultry.xml")/root/row,
  <options xmlns="http://www.zorba-xquery.com/modules/converters/json-options" >
    <jsonParam name="mapping" value="json-ml" />
  </options>
)
