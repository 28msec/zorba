(: test for invalid type (jerr:JSDY0041) of jsoniq-multiple-top-level-items option :)
jn:parse-json('{ "a" : true }{ "b" : false }', { "jsoniq-multiple-top-level-items" : 1 })
