jsoniq version "1.0";

import module namespace ft = "http://zorba.io/modules/full-text";
import module namespace ref = "http://zorba.io/modules/reference";

let $x := <msg xml:lang="en" content="Houston, we have a problem!"/>
let $tokens := ft:tokenize-node( $x/@content )
let $node-ref := $tokens[5].node-ref
let $node := ref:dereference( $node-ref )
return $node instance of attribute(content)

(: vim:set et sw=2 ts=2: :)
