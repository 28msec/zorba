import module namespace zorba-csv = "http://www.zorba-xquery.com/modules/csv";
declare namespace data="http://www.zorba-xquery/data";

zorba-csv:serialize(
for $person in fn:doc("data.xml")/data:root/data:person
return <row>{$person/data:name}
            {$person/data:address}
            {$person/data:address2}
        </row>, 
<options>
  <first-row-is-header/>
  <csv separator=","
       quote-char="&quot;"
       quote-escape="&quot;&quot;"/>
</options>)
