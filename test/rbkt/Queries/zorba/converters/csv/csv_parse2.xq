(:Parse csv with two lines, and the last field is stretched over the next line:)

import schema namespace csv-options="http://www.zorba-xquery.com/modules/csv-options";
import module namespace zorba-csv = "http://www.zorba-xquery.com/modules/csv";

zorba-csv:parse(
'f1, f2, f3, f4
f5, f6, "f7", "f8
""f9"', 
validate{
<csv-options:options>
  <csv separator=","
       quote-char="&quot;"
       quote-escape="&quot;&quot;"/>
  <xml-nodes>
    <row>
      <column/>
    </row>
  </xml-nodes>
</csv-options:options>}
)

