import schema namespace csv-options="http://www.zorba-xquery.com/modules/csv-options";
import module namespace zorba-csv = "http://www.zorba-xquery.com/modules/csv";
import module namespace file="http://www.zorba-xquery.com/modules/file";


let $options :=
<csv-options:options>
  <first-row-is-header/>
  <csv separator="&#009;"
       quote-char=""
       quote-escape=""/>
  <xml-nodes>
    <row>
      <column/>
    </row>
  </xml-nodes>
</csv-options:options>
return
zorba-csv:serialize(zorba-csv:parse(file:read-text(fn:resolve-uri("tri_2008_NH_v08.txt")), $options),
                    $options)
