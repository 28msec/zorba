import module namespace fs = "http://expath.org/ns/file";

declare default element namespace "http://www.w3.org/2005/Atom";

(: Generate Index :)
let $feed := doc("atom.xml")/feed
let $index :=  {
  "title": $feed/title/text(),
  "tags": {|
    for $tag in distinct-values($feed/entry/category/@term/string())
    return { $tag: count($feed/entry/category/@term[string() eq $tag]) }
  |},
  "entries": [
    for $entry in $feed/entry
    return {
      "title": $entry/title/string(),
      "id": $entry/id/string(),
      "updated": $entry/updated/string(),
      "summary": $entry/summary/string(),
      "content": $entry/content/string(),
      "authors": [
        for $author in $entry/author
        return {
          "name": $author/name/string(),
          "email": $author/email/string()
        }
      ],
      "tags": [
        for $cat in $entry/category
        return $cat/@term/string()
      ]
    }
  ]
}
return fs:write("index.json", $index, ())
