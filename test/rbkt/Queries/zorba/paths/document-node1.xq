let $foo := document { <root><hi/></root> }
return $foo/descendant-or-self::document-node(element(root))