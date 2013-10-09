
import module namespace fn-zorba-util = "http://zorba.io/modules/schema"; 
import schema default element namespace "http://www.w3.org/XQueryTest" at "atomic.xsd";

declare variable $doc as document-node(element(root)) external;

let $x := $doc//decimal
return ($x instance of element(*, xs:decimal), fn-zorba-util:schema-type($x))
