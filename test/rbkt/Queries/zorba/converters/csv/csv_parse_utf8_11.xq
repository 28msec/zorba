(: csv-to-xml example with 1 row :)

import module namespace zorba-csv = "http://www.zorba-xquery.com/modules/csv";

zorba-csv:parse("ü,ö,ä, ă,î,ș,ț,â", ())
