jsoniq version "1.0";

import module namespace ft = "http://zorba.io/modules/full-text";
import module namespace ref = "http://zorba.io/modules/reference";

let $x := <p xml:lang="en">Houston, we have a <em>problem</em>!</p>
let $tokens := ft:tokenize-node( $x )
let $node-ref := $tokens[5].node-ref
let $node := ref:dereference( $node-ref )
return $node instance of text()

(: vim:set et sw=2 ts=2: :)
