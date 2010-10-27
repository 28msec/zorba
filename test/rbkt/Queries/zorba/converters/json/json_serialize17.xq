import module namespace json = "http://www.zorba-xquery.com/modules/json";

declare variable $test :=
<json type="object">
  <pair name="servlet" type="array">
    <item type="array">
      <item type='string'>212 732-1234</item>
    </item>
  </pair>
</json>;

json:serialize($test)
