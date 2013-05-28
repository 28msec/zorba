(: The base-uri of a document node should be the retrieval URI. :)
let $uri := fn:resolve-uri( "input.xml", fn:static-base-uri() )
let $doc := fn:doc($uri)
return (fn:base-uri($doc) eq $uri)
