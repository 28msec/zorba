declare variable $input-context external;
let $auction := doc($input-context) return
for $i in $auction/site/regions/australia/item
return <item name="{$i/name/text()}">{$i/description}</item>
