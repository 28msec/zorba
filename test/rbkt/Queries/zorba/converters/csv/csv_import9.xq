import module namespace zorba-csv = "http://www.zorba-xquery.com/modules/csv2xml";

zorba-csv:csv-file-to-xml("budauth.csv", fn:true(),  ",", '"', '""', 
                    fn:QName("", "row"),
                    fn:QName("", "column"))
