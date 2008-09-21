import module namespace
coll="http://www.zorba-xquery.com/zorba/collection-functions";

let $collUri := "http://example.org/collection_1"
return (
coll:create-collection($collUri,<a/>),
let $a := fn:collection($collUri)
return
coll:insert-nodes-last($collUri, <b/>)
)
