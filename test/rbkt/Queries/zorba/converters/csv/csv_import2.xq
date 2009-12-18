import module namespace zorba-csv = "http://www.zorba-xquery.com/modules/csv2xml";

zorba-csv:csv-to-xml('f1, f2, f3, f4
f5, f6, "f7", "f8
""f9"', fn:false(), ",", '"', '""', 
                    fn:QName("", "row"),
                    fn:QName("", "column"))
