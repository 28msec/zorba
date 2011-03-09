(: Simple example of serializing xml to csv :)

import module namespace zorba-csv = "http://www.zorba-xquery.com/modules/csv";

zorba-csv:serialize(
<row>
  <column>f1</column>
  <column>f2</column>
  <column>f3</column>
  <column>f4</column>
</row>, ())

