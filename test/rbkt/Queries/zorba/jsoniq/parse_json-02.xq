(: test for jerr:JNDY0021 because multiple top-level items are not allowed :)
jn:parse-json('{ "a" : true() }{ "b" : false() }', { "jsoniq-multiple-top-level-items" : false() })
