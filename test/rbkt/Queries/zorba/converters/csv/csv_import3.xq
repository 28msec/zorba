import module namespace zorba-csv = "http://www.zorba-xquery.com/modules/csv2xml";

zorba-csv:csv2xmlFromFile("tri_2008_NH_v08.txt", fn:true(),  "	", '', '', 
                    fn:QName("", "row"),
                    fn:QName("", "column"))
