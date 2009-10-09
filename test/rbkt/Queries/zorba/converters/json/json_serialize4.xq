(: json:serialize test escaping of double quotes :)

import module namespace json = "http://www.zorba-xquery.com/zorba/json-functions";
import module namespace jsonml = "http://www.zorba-xquery.com/zorba/json-ml-functions";

json:serialize(
  <json type="object">
     <pair name="firstName" type="string">&quot;</pair>
  </json>
),
jsonml:serialize(
  <person><firstName>&quot;</firstName></person>
)
