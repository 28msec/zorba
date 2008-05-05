declare variable $input-context external;
let $doc := doc($input-context)
return
<authors>
{
  for $author in distinct-values($doc//author)
    return <author>{$author}</author>
}
</authors>

(: q1: saxon: 1.6s :)
