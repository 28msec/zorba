import module namespace json = "http://www.zorba-xquery.com/modules/json";

declare variable $test :=
<json type="object">
  <pair name="servlet" type="array">
    <item type="object">
    </item>
  </pair>
</json>;

json:serialize($test)
