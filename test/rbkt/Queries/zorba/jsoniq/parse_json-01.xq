(: allow parsing multiple top-level items :)
for $i in jn:parse-json('{ "a" : true }{ "b" : false}')
return serialize($i)
