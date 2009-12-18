import module namespace zorba-csv = "http://www.zorba-xquery.com/modules/csv2xml";

zorba-csv:csv-file-to-xml("NAWQA.swmaster.CROSSTAB_COUNT.1260179451247.csv", fn:true(),  ",", '', '', 
                    fn:QName("", "row"),
                    fn:QName("", "column"))
