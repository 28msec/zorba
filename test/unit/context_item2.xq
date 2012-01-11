
declare context item as xs:string external;

for $i in ("foo", "boo")
where $i eq .
return $i
