let $enc := jn:encode-for-roundtrip(
    {
      'comment' : comment { "a comment" },
      'document' : document { <a/> } ,
      'pi' : processing-instruction target { "an instruction" },
      'text' : text { "some text" }
    }
  )
let $dec := jn:decode-from-roundtrip($enc)
return (
  $dec("comment") instance of comment(),
  $dec("document") instance of document-node(),
  $dec("pi") instance of processing-instruction(),
  $dec("text") instance of text()
)
