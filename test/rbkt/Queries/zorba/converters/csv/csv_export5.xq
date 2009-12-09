import module namespace zorba-csv = "http://www.zorba-xquery.com/modules/csv2xml";

let $export_result := 
        zorba-csv:xml2csvFile((<row><column f1="value1"/><column f2='"value2"'/><column f3="value3,value33"/><column f4="value4"/></row>,
                  <row><column f1="value11"/><column f2="value12"/><column f3="value13"/><column f4="value14"/></row>),
                  "csv_export_result.csv", 
                   ("./column/@f1", "./column/@f2", "./column/@f3", "./column/@f4"), 
                   fn:true(), ",", '"', '""')
let $import_back := zorba-csv:csv2xmlFromFile("csv_export_result.csv", 
                    fn:true(),  ",", '"', '""', 
                    fn:QName("", "row"),
                    fn:QName("", "column"))
return
  if($export_result) then
    $import_back
  else
    ""

