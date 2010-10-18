(: valid json generation: array in an array :)

import module namespace json = "http://www.zorba-xquery.com/modules/json";

declare variable $test :=
  <json type="object">
    <pair name="servlet" type="array">
	<item type="array">
          <item type="string">value1</item>
	</item>
        <item type="string">value2</item>
    </pair>
  </json>;

json:serialize($test)
