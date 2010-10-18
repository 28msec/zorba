(: type attribute missing :)

import module namespace json = "http://www.zorba-xquery.com/modules/json";

declare variable $test :=
  <json type="object">
      <pair type="string">value</pair>
  </json>;

json:serialize($test)
