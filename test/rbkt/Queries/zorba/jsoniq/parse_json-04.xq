(: test for invalid type (jerr:JNTY0020) of jsoniq-multiple-top-level-items option :)
jn:parse-json('{ "a" : true }{ "b" : false }', { "jsoniq-multiple-top-level-items" : 1 })
