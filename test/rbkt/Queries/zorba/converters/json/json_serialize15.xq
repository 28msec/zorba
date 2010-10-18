(: valid json generation: comments should be ignored :)

import module namespace json = "http://www.zorba-xquery.com/modules/json";

declare variable $test :=
  <json type="object">
    <pair name="servlet" type="object">
	<!--comment-->
        <pair name="name" type="string">value</pair>
    </pair>
  </json>;

json:serialize($test)
