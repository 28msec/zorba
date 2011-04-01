
import module namespace fn-zorba-util = "http://www.zorba-xquery.com/modules/schema"; 
import schema default element namespace "http://www.w3.org/XQueryTest" at "atomic.xsd";

declare variable $doc as document-node(element(root)) external;

let $x := fn:data(($doc//decimal)[1])
return ($x instance of xs:decimal, fn-zorba-util:schema-type($x))
