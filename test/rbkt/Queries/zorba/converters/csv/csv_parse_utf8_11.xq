(: csv-to-xml example with utf8 characters :)

import module namespace zorba-csv = "http://www.zorba-xquery.com/modules/csv";

zorba-csv:parse("ü,ö,ä, ă,î,ș,ț,â", ())
