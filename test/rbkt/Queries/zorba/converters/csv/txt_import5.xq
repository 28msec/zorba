import module namespace zorba-csv = "http://www.zorba-xquery.com/modules/csv2xml";

zorba-csv:txt2xmlFromFile("PUAOSL95.TXT", fn:false(),  (1, 21, 66, 101, 118, 137, 141, 143, 160), 
                    fn:QName("", "row"),
                    fn:QName("", "column"))
