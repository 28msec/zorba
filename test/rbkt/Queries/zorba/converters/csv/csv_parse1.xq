(: csv-to-xml example with 1 row :)

import module namespace zorba-csv = "http://www.zorba-xquery.com/modules/csv";

zorba-csv:parse("f1, f2, f3, f4", ())
