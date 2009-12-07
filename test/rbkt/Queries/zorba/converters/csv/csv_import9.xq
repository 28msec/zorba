import module namespace zorba-csv = "http://www.zorba-xquery.com/modules/csv2xml";

zorba-csv:csv2xmlFromFile("budauth.csv", fn:true(),  ",", '"', '""', 
                    fn:QName("", "row"),
                    fn:QName("", "column"))
