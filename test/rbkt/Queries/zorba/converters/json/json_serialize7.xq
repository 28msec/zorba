(: type value wrong :)

import module namespace json = "http://www.zorba-xquery.com/modules/json";

declare variable $test :=
  <json type="object">
      <pair name="name" type="huhu">value</pair>
  </json>;

json:serialize($test)
