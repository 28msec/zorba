(: csv-to-xml example with utf8 characters :)

import module namespace zorba-csv = "http://www.zorba-xquery.com/modules/csv";

zorba-csv:parse("ü,ö,ä, ă,î,ș,ț,â", ())

(:
<b>Output:</b>

<?xml version="1.0" encoding="UTF-8"?>
<row>
  <column>ü</column>
  <column>ö</column>
  <column>ä</column>
  <column> ă</column>
  <column>î</column>
  <column>ș</column>
  <column>ț</column>
  <column>â</column>
</row>
:)