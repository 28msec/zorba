
module namespace zorba-csv = "http://www.zorba-xquery.com/modules/csv2xml";

declare function zorba-csv:csv2xml( $csv as xs:string,
                              $first_row_is_header as xs:boolean,
                              $separator as xs:string,
                              $quote_char as xs:string,
                              $quote_escape as xs:string,
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

                                  