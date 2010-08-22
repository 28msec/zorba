import module namespace zorba-csv = "http://www.zorba-xquery.com/modules/csv2xml";
declare namespace data="http://www.zorba-xquery/data";

zorba-csv:xml-to-csv(fn:doc("data.xml")/data:root/data:person, 
                   ("./data:name", 
                    "./data:address",
                    "./data:address2"), fn:true(), ",", '"', '""')
