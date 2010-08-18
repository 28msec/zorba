import module namespace zorba-csv = "http://www.zorba-xquery.com/modules/csv2xml";
declare namespace data="http://www.zorba-xquery/data";

zorba-csv:xml-to-csv(fn:doc("data.xml")/data:root/data:person, 
                   ("declare namespace data='http://www.zorba-xquery/data'; ./data:name", 
                    "declare namespace data='http://www.zorba-xquery/data'; ./data:address",
                    "declare namespace data='http://www.zorba-xquery/data'; ./data:address2"), fn:true(), ",", '"', '""')
