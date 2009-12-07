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


module namespace zorba-csv = "http://www.zorba-xquery.com/modules/csv2xml";

declare function zorba-csv:csv2xml( $csv as xs:string,
                              $first_row_is_header as xs:boolean,
                              $separator as xs:string,
                              $quote_char as xs:string,
                              $quote_escape as xs:string,
                              $row_node as xs:QName,
                              $default_column_node as xs:QName
                              ) as node()* external;

declare function zorba-csv:txt2xml( $csv as xs:string,
                              $first_row_is_header as xs:boolean,
                              $columns_positions as xs:integer+,
                              $row_node as xs:QName,
                              $default_column_node as xs:QName
                              ) as node()* external;
(:                                 
declare function zorba-csv:csv2xml($csv as xs:string) as node()*
{
  zorba-csv:csv2xml($csv, fn:false(), ",", '"', '""', 
                    fn:QName("", "row"),
                    fn:QName("", "column"))
                    
};
:)

declare function zorba-csv:csv2xmlFromFile( $csv_file as xs:string,
                              $first_row_is_header as xs:boolean,
                              $separator as xs:string,
                              $quote_char as xs:string,
                              $quote_escape as xs:string,
                              $row_node as xs:QName,
                              $default_column_node as xs:QName
                              ) as node()* external;
declare function zorba-csv:txt2xmlFromFile( $csv_file as xs:string,
                              $first_row_is_header as xs:boolean,
                              $columns_positions as xs:integer+,
                              $row_node as xs:QName,
                              $default_column_node as xs:QName
                              ) as node()* external;

                                  
(:                                 
declare function zorba-csv:csv2xmlFromFile($csv_file as xs:string) as node()*
{
  zorba-csv:csv2xmlFromFile($csv_file, fn:false(), ",", '"', '""', 
                    fn:QName("", "row"),
                    fn:QName("", "column"))
                    
};
:)
