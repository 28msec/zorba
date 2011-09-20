import module namespace doc = "http://www.zorba-xquery.com/modules/store/dynamic/documents";

let $doc := doc:document("meat_poultry.xml")
let $first-row := $doc/root/row[1]
for $row in $doc/root/row[position() > 1]
for $column at $y in $row/column
return rename node $column as $first-row/column[$y]
