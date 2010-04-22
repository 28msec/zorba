(: json:serialize test escaping of double quotes :)

import module namespace json = "http://www.zorba-xquery.com/modules/json";

json:serialize(
  <json type="object">
     <pair name="firstName" type="string">&quot;</pair>
  </json>
),
json:serializeML(
  <person><firstName>&quot;</firstName></person>
)
