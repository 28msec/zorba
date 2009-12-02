import module namespace zorba-csv = "http://www.zorba-xquery.com/modules/csv2xml";

zorba-csv:csv2xml("f1, f2, f3, f4", fn:false(), ",", '"', '""', 
                    fn:QName("", "row"),
                    fn:QName("", "column"))
