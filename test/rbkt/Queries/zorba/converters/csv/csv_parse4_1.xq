import module namespace zorba-csv = "http://www.zorba-xquery.com/modules/csv";
import module namespace file="http://www.zorba-xquery.com/modules/file";

zorba-csv:parse(file:read-text(fn:resolve-uri("ME_1_2008_v08.txt")), 

<options>
  <first-row-is-header/>
  <add-last-void-columns/>
  <csv separator="&#009;"
       quote-char=""
       quote-escape=""/>
  <xml-nodes>
    <row/>
  </xml-nodes>
</options>
)
