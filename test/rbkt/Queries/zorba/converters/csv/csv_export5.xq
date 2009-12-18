import module namespace zorba-csv = "http://www.zorba-xquery.com/modules/csv2xml";

declare variable $export-filename as xs:string external;

let $export_result := 
        zorba-csv:xml-to-csv-file((<row><column f1="value1"/><column f2='"value2"'/><column f3="value3,value33"/><column f4="value4"/></row>,
                  <row><column f1="value11"/><column f2="value12"/><column f3="value13"/><column f4="value14"/></row>),
                  $export-filename, 
                   ("./column/@f1", "./column/@f2", "./column/@f3", "./column/@f4"), 
                   fn:true(), ",", '"', '""')
let $import_back := zorba-csv:csv-file-to-xml($export-filename, 
                    fn:true(),  ",", '"', '""', 
                    fn:QName("", "row"),
                    fn:QName("", "column"))
return
  if($export_result) then
    $import_back
  else
    ""

