(: wrong value for array :)

import module namespace json = "http://www.zorba-xquery.com/modules/json";

declare variable $test :=
  <json type="object">
      <pair name="name" type="array">
          <pair name="wrong" type="string">value</pair>
      </pair>
  </json>;

json:serialize($test)
