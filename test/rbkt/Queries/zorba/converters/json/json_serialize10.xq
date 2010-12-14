(: object contained in an array is allowed :)

import module namespace json = "http://www.zorba-xquery.com/modules/json";

declare variable $test :=
  <json type="object">
    <pair name="servlet" type="array">
	<item type="object">
            <pair name="name" type="string">value1</pair>
	</item>>
        <item type="string">value2</item>
    </pair>
  </json>;

json:serialize($test) eq '{"servlet": [{"name": "value1"}, "value2"]}'
