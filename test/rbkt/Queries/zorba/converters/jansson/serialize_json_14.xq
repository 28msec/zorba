(: valid json generation: comments should be ignored :)

import module namespace json = "http://www.zorba-xquery.com/modules/convertors/json";
import schema namespace html-options="http://www.zorba-xquery.com/modules/convertors/json-options";

declare variable $local:json :=
   <json type="object">
    <pair name="servlet" type="object">
  <!--comment-->
        <pair name="name" type="string">value</pair>
    </pair>
  </json>;

json:serialize($local:json,<options xmlns="http://www.zorba-xquery.com/modules/convertors/json-options" >
              <jsonParam name="mapping" value="simple-json" />
            </options>)
