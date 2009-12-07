import module namespace zorba-csv = "http://www.zorba-xquery.com/modules/csv2xml";

zorba-csv:csv2xmlFromFile("Hospital Outpatient Payments for 61 Commonly Performed Procedures, CY 2008 Data.csv", fn:false(),  ",", '"', '""', 
                    fn:QName("", "row"),
                    fn:QName("", "column"))
