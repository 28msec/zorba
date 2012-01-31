import module namespace ft = "http://www.zorba-xquery.com/modules/full-text";

let $doc := <msg>hello, world</msg>
return ft:tokenize( $doc, xs:language("en") )
