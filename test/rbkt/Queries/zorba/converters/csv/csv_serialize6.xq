(:Serialize a sequence of constructed nodes in csv lines, without header:)
import schema namespace csv-options="http://www.zorba-xquery.com/modules/csv-options";
import module namespace zorba-csv = "http://www.zorba-xquery.com/modules/csv";
declare namespace data="http://www.zorba-xquery/data";
declare variable $input-xml external;

zorba-csv:serialize(
for $person in $input-xml/data:root/data:person
return <row>{$person/data:name}
            {$person/data:address}
            {$person/data:address2}
        </row>, 
validate{
<csv-options:options>
  <first-row-is-header/>
  <csv separator=","
       quote-char="&quot;"
       quote-escape="&quot;&quot;"/>
</csv-options:options>})
