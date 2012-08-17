import module namespace ft = "http://www.zorba-xquery.com/modules/full-text";
import module namespace ref = "http://www.zorba-xquery.com/modules/node-reference";

import schema namespace fts = "http://www.zorba-xquery.com/modules/full-text";

let $x := <msg xml:lang="en" content="Houston, we have a problem!"/>
let $tokens := ft:tokenize-node( $x/@content )
let $node-ref := (validate { $tokens[5] }) /@node-ref
let $node := ref:node-by-reference( $node-ref )
return $node instance of attribute(content)

(: vim:set et sw=2 ts=2: :)
