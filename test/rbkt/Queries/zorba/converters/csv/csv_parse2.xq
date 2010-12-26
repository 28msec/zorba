(:Parse csv with two lines, and the last field is stretched over the next line:)

import module namespace zorba-csv = "http://www.zorba-xquery.com/modules/csv";

zorba-csv:parse(
'f1, f2, f3, f4
f5, f6, "f7", "f8
""f9"', 
<options>
  <csv separator=","
       quote-char="&quot;"
       quote-escape="&quot;&quot;"/>
  <xml-nodes>
    <row>
      <column/>
    </row>
  </xml-nodes>
</options>
)





(:
<b>Output:</b>

<?xml version="1.0" encoding="UTF-8"?>
<row>
  <column>f1</column>
  <column> f2</column>
  <column> f3</column>
  <column> f4</column>
</row><row>
  <column>f5</column>
  <column> f6</column>
  <column> f7</column>
  <column> f8
"f9</column>
</row>

:)