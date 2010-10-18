(: json:serialize serialize some pitfall characters :)

import module namespace json = "http://www.zorba-xquery.com/modules/json";

declare variable $test :=
  <json type="object">
      <pair name="name" type="string">!_"-\?*.$+</pair>
  </json>;

json:parse(json:serialize($test))/pair/text() eq $test/pair/text()
