import module namespace zorba-csv = "http://www.zorba-xquery.com/modules/csv2xml";

zorba-csv:xml2txt((<row><column f1="value1"/><column f2='"value2"'/><column f3="value3,value33"/><column f4="value4"/></row>,
                  <row><column f1="value11"/><column f2="value12"/><column f3="value13"/><column f4="value14"/></row>), 
                   ("./column/@f1", "./column/@f2", "./column/@f3", "./column/@f4"), 
                   fn:true(), 
                   (10, 7, 10, 7))
