import module namespace zorba-csv = "http://www.zorba-xquery.com/modules/csv2xml";

zorba-csv:xml2csv((<row><f1>value1</f1><f2>value2</f2><f3>value3</f3><f4>value4</f4></row>,
                  <row><f1>value11</f1><f2>value12</f2><f3>value13</f3><f4>value14</f4></row>), 
                   (), fn:true(), ",", '"', '""')
