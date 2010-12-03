import module namespace zorba-csv = "http://www.zorba-xquery.com/modules/csv";
import module namespace file="http://www.zorba-xquery.com/modules/file";

zorba-csv:parse(file:read-text(fn:resolve-uri("PUAOSL95.TXT")), 
                    
<options>
  <column-widths>
    <column-width>20</column-width>
    <column-width>45</column-width>
    <column-width>35</column-width>
    <column-width>17</column-width>
    <column-width>19</column-width>
    <column-width>4</column-width>
    <column-width>2</column-width>
    <column-width>17</column-width>
  </column-widths>
</options>   
)                 
