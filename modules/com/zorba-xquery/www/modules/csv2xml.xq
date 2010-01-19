(:
 : Copyright 2006-2009 The FLWOR Foundation.
 :
 : Licensed under the Apache License, Version 2.0 (the "License");
 : you may not use this file except in compliance with the License.
 : You may obtain a copy of the License at
 :
 : http://www.apache.org/licenses/LICENSE-2.0
 :
 : Unless required by applicable law or agreed to in writing, software
 : distributed under the License is distributed on an "AS IS" BASIS,
 : WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 : See the License for the specific language governing permissions and
 : limitations under the License.
:)


(:~
 : Function library providing convertors from CSV/TXT to XML and back.
 : The functions are optimized to work with large amounts of data, in a streaming way.
 :
 : @version 1.0 
 : @author Daniel Turcanu
 :)
module namespace zorba-csv = "http://www.zorba-xquery.com/modules/csv2xml";

(:~
 : Converts a CSV string into a sequence of XML nodes. 
 : Each row in the CSV string is returned as a XML node. This will contain subnodes for each CSV column.
 : 
 : @param $csv the csv string, with each line separated by CR, LF, or CRLF.
 : 		The CSV string is read as UTF8.
 : @param $first_row_is_header set to fn:true() if the first line in CSV is the header.
 : 		Then all subnodes elements will have the name coresponding to the header.
 : @param $separator specifies the separator between field. Common separators are comma and tab.
 : @param $quote_char specifies the quote char used to quote the field if it contains special chars
 : 		like the separator char or CR LF. Common quote char is the double quote.
 : @param $quote_escape specifies how is the quote char escaped inside the field.
 : 		If the quote char is the double quote, then the quote escape is commonly two double quotes.
 : @param $row_node the name of the row node element.
 : @param $default_column_node the name of the subnodes elements if the first row in CSV is not a header.
 : @return a sequence of nodes, one for each row in CSV string.
 : 		If the first row is the header, then it is not returned.
 : @error API0071 - invalid or missing parameter
 : @error API0072 - if there are more fields on a line than they are in the header 
 :                   (if first_row_is_header is set to true)
:)
declare function zorba-csv:csv-to-xml( $csv as xs:string,
                              $first_row_is_header as xs:boolean,
                              $separator as xs:string,
                              $quote_char as xs:string,
                              $quote_escape as xs:string,
                              $row_node as xs:QName,
                              $default_column_node as xs:QName
                              ) as node()* external;

(:~
 : Converts a text table into a sequence of XML nodes.
 : Each line is returned as a XML node, having subnodes for each column.
 : Each column in the text table has a fixed length in characters.
 : 
 : @param $csv the text table string. Each line ends with CR, LF or CRLF.
 : 		The string is read as UTF8.
 : @param $first_row_is_header specifies if the first row in the table is the header.
 : 		If true, then the subnodes elements will have the names coresponding to the header names.
 : @param $columns_positions specifies a list of integers with the starting positions of every column.
 : 		The first position is 1.  The last column ends at newline.
 : 		Each field will have the whitespaces trimmed.
 : @param $row_node the name of the row element for each row.
 : @param $default_column_node the name of the subnode elements if the first row is not header.
 : @return a sequence of nodes, for each line in text table, except the first if it is the header.
 : @error API0071 - invalid or missing parameter
 : @error API0071 - if a column position is less than 1
 : @error API0071 - if column positions sequence is empty
 : @error API0072 - if there are more fields on a line than they are in the header 
 :                   (if first_row_is_header is set to true)
:)
declare function zorba-csv:txt-to-xml( $csv as xs:string,
                              $first_row_is_header as xs:boolean,
                              $columns_positions as xs:integer+,
                              $row_node as xs:QName,
                              $default_column_node as xs:QName
                              ) as node()* external;
(:                                 
declare function zorba-csv:csv-to-xml($csv as xs:string) as node()*
{
  zorba-csv:csv2xml($csv, fn:false(), ",", '"', '""', 
                    fn:QName("", "row"),
                    fn:QName("", "column"))
                    
};
:)

(:~
 : Converts a CSV file into a sequence of XML nodes. 
 : Each row in the CSV file is returned as a XML node. This will contain subnodes for each CSV column.
 : 
 : @param $csv_file the name of the csv file.
 : 		The file name can be a file:// URI, an absolute file path or a relative file path.
 : 		If it is a relative file path, then the absolute file path is computed based
 : 		on the directory where the query is stored.
 : 		The CSV file must be encoded as UTF8 and have each line ending with CR, LF or CRLF.
 : @param $first_row_is_header set to fn:true() if the first line in CSV is the header.
 : 		Then all subnodes elements will have the names coresponding to the header.
 : @param $separator specifies the separator between field. Common separators are comma and tab.
 : @param $quote_char specifies the quote char used to quote the field if it contains special chars
 : 		like the separator char or CR LF. Common quote char is the double quote.
 : @param $quote_escape specifies how is the quote char escaped inside the field.
 : 		If the quote char is the double quote, then the quote escape is commonly two double quotes.
 : @param $row_node the name of the row node element.
 : @param $default_column_node the name of the subnodes elements if the first row in CSV is not a header.
 : @return a sequence of nodes, one for each row in CSV file.
 : 		If the first row is the header, then it is not returned.
 : 		After returning the last row, the file is closed.
 : @error API0071 - invalid or missing parameter
 : @error API0071 - cannot open file
 : @error API0072 - if there are more fields on a line than they are in the header 
 :                   (if first_row_is_header is set to true)
:)
declare function zorba-csv:csv-file-to-xml( $csv_file as xs:string,
                              $first_row_is_header as xs:boolean,
                              $separator as xs:string,
                              $quote_char as xs:string,
                              $quote_escape as xs:string,
                              $row_node as xs:QName,
                              $default_column_node as xs:QName
                              ) as node()* external;

(:~
 : Converts a text table file into a sequence of XML nodes.
 : Each line is returned as a XML node, having subnodes for each column.
 : Each column in the text table has a fixed length in characters.
 : 
 : @param $csv_file the name of the text file.
 : 		The file name can be a file:// URI, an absolute file path or a relative file path.
 : 		If it is a relative file path, then the absolute file path is computed based
 : 		on the directory where the query is stored.
 : 		The text table file must be encoded as UTF8 and have each line ending with CR, LF or CRLF.
 : @param $first_row_is_header specifies if the first row in the table is the header.
 : 		If true, then the subnodes elements will have the names coresponding to the header names.
 : @param $columns_positions specifies a list of integers with the starting positions of every column.
 : 		The first position is 1. The last column ends at newline.
 : 		Each field will have the whitespaces trimmed.
 : @param $row_node the name of the row element for each row.
 : @param $default_column_node the name of the subnode elements if the first row is not header.
 : @return a sequence of nodes, for each line in text table, except the first if it is the header.
 : @error API0071 - invalid or missing parameter
 : @error API0071 - cannot open file
 : @error API0071 - if a column position is less than 1
 : @error API0071 - if column positions sequence is empty
 : @error API0072 - if there are more fields on a line than they are in the header 
 :                   (if first_row_is_header is set to true)
:)
declare function zorba-csv:txt-file-to-xml( $csv_file as xs:string,
                              $first_row_is_header as xs:boolean,
                              $columns_positions as xs:integer+,
                              $row_node as xs:QName,
                              $default_column_node as xs:QName
                              ) as node()* external;

                                  
(:                                 
declare function zorba-csv:csv-file-to-xml($csv_file as xs:string) as node()*
{
  zorba-csv:csv2xmlFromFile($csv_file, fn:false(), ",", '"', '""', 
                    fn:QName("", "row"),
                    fn:QName("", "column"))
                    
};
:)

(:~
 : Exports a sequence of XML nodes into a CSV string.
 : Each XML node will be exported into a CSV line.
 : 
 : @param $xml the sequence of xml nodes. The names of the nodes are ignored.
 : @param $xpaths Can be empty if all the subnodes elements inside each node are to be included in the CSV line.
 : 		Otherwise you can specify a sequence of xpath strings (or even xquery code) that will
 : 		select which subnodes and attributes should be included in the CSV line.
 : 		One xpath can produce multiple nodes (be it elements, attributes, text and so on) and all
 : 		the results will be included in the CSV line.
 : 		The xpaths will be applied for each xml node in the sequence. 
 : 		The xml node will be set as the current item, and you have to refer it by dot '.' .
 : @param $first_row_is_header specifies if the first row is the header.
 : 		If true, then the first row will be the names of the output items from the first xml node.
 : 		If using xpaths and some non-elements and non-attributes items get selected,
 : 		then the coresponding name in the header will be empty string.
 : @param $separator the separator used between fields. Common separators are comma and tab.
 : @param $quote_char The character to quote the field if it contains separator char or newline char (or the quote char itself).
 : 		Common quote char is the double quotes.
 : @param $quote_escape how to escape the quote char if found inside the field.
 : 		Common quote escape is two double quotes.
 : @return the CSV multiline string encoded as UTF8.
 : @error API0073 - invalid or missing parameter
 : @error API0073 - cannot transform node into csv line
:)
declare function zorba-csv:xml-to-csv($xml as node()*, 
																	 $xpaths as xs:string*,
																	 $first_row_is_header as xs:boolean,
																	 $separator as xs:string,
																	 $quote_char as xs:string,
																	 $quote_escape as xs:string) as xs:string external;

(:~
 : Exports a sequence of XML nodes into a CSV file.
 : Each XML node will be exported into a CSV line.
 : 
 : @param $xml the sequence of xml nodes. The names of the nodes are ignored.
 : @param $output_file the name of the output CSV file.
 : 		The file name can be a file:// URI, an absolute file path or a relative file path.
 : 		If it is a relative file path, then the absolute file path is computed based
 : 		on the directory where the query is stored.
 : 		The CSV file will be encoded as UTF8 and have each line ending with CR.
 : 		The file will be closed upon return from function.
 : @param $xpaths Can be empty if all the subnodes elements inside each node are to be included in the CSV line.
 : 		Otherwise you can specify a sequence of xpath strings (or even xquery code) that will
 : 		select which subnodes and attributes should be included in the CSV line.
 : 		One xpath can produce multiple nodes (be it elements, attributes, text and so on) and all
 : 		the results will be included in the CSV line.
 : 		The xpaths will be applied for each xml node in the sequence. 
 : 		The xml node will be set as the current item, and you have to refer it by dot '.' .
 : @param $first_row_is_header specifies if the first row is the header.
 : 		If true, then the first row will be the names of the output sub-items from the first xml node.
 : 		If using xpaths and some non-elements and non-attributes items get selected,
 : 		then the coresponding name in the header will be empty string.
 : @param $separator the separator used between fields. Common separators are comma and tab.
 : @param $quote_char The character to quote the field if it contains separator char or newline char (or the quote char itself).
 : 		Common quote char is the double quotes.
 : @param $quote_escape how to escape the quote char if found inside the field.
 : 		Common quote escape is two double quotes.
 : @return the boolean true.
 : @error API0073 - invalid or missing parameter
 : @error API0073 - cannot open file for writing
 : @error API0073 - cannot transform node into csv line
:)
declare function zorba-csv:xml-to-csv-file($xml as node()*, 
																	 $output_file as xs:string,
																	 $xpaths as xs:string*,
																	 $first_row_is_header as xs:boolean,
																	 $separator as xs:string,
																	 $quote_char as xs:string,
																	 $quote_escape as xs:string) as xs:boolean external;

(:~
 : Exports a sequence of XML nodes into a text table string.
 : Each XML node will be exported into a table line.
 : Each column of the table has a fixed length, so there is no need for special separator char or quote char.
 : 
 : @param $xml the sequence of xml nodes. The names of the nodes are ignored.
 : @param $xpaths Can be empty if all the subnodes elements inside each node are to be included in the table line.
 : 		Otherwise you can specify a sequence of xpath strings (or even xquery code) that will
 : 		select which subnodes and attributes should be included in the table line.
 : 		One xpath can produce multiple nodes (be it elements, attributes, text and so on) and all
 : 		the results will be included in the table line.
 : 		The xpaths will be applied for each xml node in the sequence. 
 : 		The xml node will be set as the current item, and you have to refer it by dot '.' .
 : @param $first_row_is_header specifies if the first row is the header.
 : 		If true, then the first row will be the names of the output items from the first xml node.
 : 		If using xpaths and some non-elements and non-attributes items get selected,
 : 		then the coresponding name in the header will be empty string.
 : @param $field_lengths specifies the length of all columns.
 : 		The size of this sequence of integers should be equal or greater than the number
 : 		of the sub-items outputed to the table line.
 : @return the text table multiline string encoded as UTF8.
 : @error API0073 - invalid or missing parameter
 : @error API0073 - if field lengths are not positive integers
 : @error API0073 - if field lengths sequence is empty
 : @error API0073 - cannot transform node into csv line
:)
declare function zorba-csv:xml-to-txt($xml as node()*, 
																	 $xpaths as xs:string*,
																	 $first_row_is_header as xs:boolean,
																	 $field_lengths as xs:integer+) as xs:string external;

(:~
 : Exports a sequence of XML nodes into a text table file.
 : Each XML node will be exported into a table line.
 : 
 : @param $xml the sequence of xml nodes. The names of the nodes are ignored.
 : @param $output_file the name of the output text table file.
 : 		The file name can be a file:// URI, an absolute file path or a relative file path.
 : 		If it is a relative file path, then the absolute file path is computed based
 : 		on the directory where the query is stored.
 : 		The text table file will be encoded as UTF8 and have each line ending with CR.
 : 		The file will be closed upon return from function.
 : @param $xpaths Can be empty if all the subnodes elements inside each node are to be included in the table line.
 : 		Otherwise you can specify a sequence of xpath strings (or even xquery code) that will
 : 		select which subnodes and attributes should be included in the table line.
 : 		One xpath can produce multiple nodes (be it elements, attributes, text and so on) and all
 : 		the results will be included in the table line.
 : 		The xpaths will be applied for each xml node in the sequence. 
 : 		The xml node will be set as the current item, and you have to refer it by dot '.' .
 : @param $first_row_is_header specifies if the first row is the header.
 : 		If true, then the first row will be the names of the output sub-items from the first xml node.
 : 		If using xpaths and some non-elements and non-attributes items get selected,
 : 		then the coresponding name in the header will be empty string.
 : @param $field_lengths specifies the length of all columns.
 : 		The size of this sequence of integers should be equal or greater than the number
 : 		of the sub-items outputed to the table line.
 : @return the boolean true.
 : @error API0073 - invalid or missing parameter
 : @error API0073 - cannot open file for writing
 : @error API0073 - if field lengths are not positive integers
 : @error API0073 - if field lengths sequence is empty
 : @error API0073 - cannot transform node into csv line
:)
declare function zorba-csv:xml-to-txt-file($xml as node()*, 
																	 $output_file as xs:string,
																	 $xpaths as xs:string*,
																	 $first_row_is_header as xs:boolean,
																	 $field_lengths as xs:integer+) as xs:boolean external;
																	 																	 
