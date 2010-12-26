(: csv-to-xml example with 1 row :)

import module namespace zorba-csv = "http://www.zorba-xquery.com/modules/csv";

zorba-csv:parse("f1, f2, f3, f4", ())



(:
<b>Output:</b>

<?xml version="1.0" encoding="UTF-8"?>
<row>
  <column>f1</column>
  <column> f2</column>
  <column> f3</column>
  <column> f4</column>
</row>
:)