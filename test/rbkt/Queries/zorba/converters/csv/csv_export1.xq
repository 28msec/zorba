import module namespace zorba-csv = "http://www.zorba-xquery.com/modules/csv2xml";

zorba-csv:xml2csv(<row><column>f1</column><column>f2</column><column>f3</column><column>f4</column></row>, 
                   (), fn:false(), ",", '"', '""')
