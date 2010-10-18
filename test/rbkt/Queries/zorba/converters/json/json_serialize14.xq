(: valid json generation: comments should be ignored :)

import module namespace json = "http://www.zorba-xquery.com/modules/json";

declare variable $test :=
  <json type="object">
    <pair name="servlet" type="array">
	<!--comment-->
        <item type="string">value</item>
    </pair>
  </json>;

json:serialize($test)
