import module namespace zorba-csv = "http://www.zorba-xquery.com/modules/csv2xml";

zorba-csv:csv-file-to-xml("ME_1_2008_v08.txt", fn:true(),  "	", '', '', 
                    fn:QName("", "row"),
                    fn:QName("", "column"))
