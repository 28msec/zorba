(: json:serialize some pitfall characters :)

import module namespace json = "http://www.zorba-xquery.com/modules/json";

declare variable $test :=
  <json type="object">
      <pair name="name" type="string">\"\\\/\b\f\n\r\t</pair>
  </json>;

json:serialize($test)
