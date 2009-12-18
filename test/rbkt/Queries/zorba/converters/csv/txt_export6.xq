import module namespace zorba-csv = "http://www.zorba-xquery.com/modules/csv2xml";

declare variable $export-filename as xs:string external;

let $export_result:= 
            zorba-csv:xml-to-txt-file((<row><f1>value1</f1><f2>value2</f2><f3>value3</f3><f4>value4</f4></row>,
                  <row><f1>value11</f1><f2>value12</f2><f3>value13</f3><f4>value14</f4></row>),
                  $export-filename,
                   (), 
                   fn:true(), 
                   (7, 7, 7, 7))
let $import_back :=    
            zorba-csv:txt-file-to-xml($export-filename, 
                    fn:true(),  
                    (1, 8, 15, 22), 
                    fn:QName("", "row"),
                    fn:QName("", "column"))
return
  if($export_result) then
    $import_back
  else
    ""                    
                           
