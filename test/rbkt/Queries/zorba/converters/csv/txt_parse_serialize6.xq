import module namespace zorba-csv = "http://www.zorba-xquery.com/modules/csv";
import module namespace file="http://www.zorba-xquery.com/modules/file";

let $options :=
<options>
  <column-widths align="right">
    <column-width align="left">20</column-width>
    <column-width>45</column-width>
    <column-width>35</column-width>
    <column-width>17</column-width>
    <column-width align="left">19</column-width>
    <column-width>4</column-width>
    <column-width>2</column-width>
    <column-width>17</column-width>
  </column-widths>
</options>   
return
let $result := 
zorba-csv:serialize(
zorba-csv:parse(file:read-text(fn:resolve-uri("PUAOSL95.TXT")), $options),
                $options)
return 
  $result
