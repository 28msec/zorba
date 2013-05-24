

let $auction := doc("../xmark/auction.xml")
return
  for $b in $auction//site/regions//item
  let $k := $b/name/text()
  stable order by zero-or-one($b/location) ascending empty greatest
  return <item name="{$k}">{$b/location/text()}</item>
