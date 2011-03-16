import module namespace json = "http://www.zorba-xquery.com/modules/convertors/json";
import schema namespace html-options="http://www.zorba-xquery.com/modules/convertors/json-options";

declare variable $local:json :=<json type="object">
  <pair name="servlet" type="array">
    <item type="array">
      <item type='string'>212 732-1234</item>
    </item>
  </pair>
</json>;

json:serialize($local:json,<options xmlns="http://www.zorba-xquery.com/modules/convertors/json-options" >
              <jsonParam name="mapping" value="simple-json" />
            </options>)
