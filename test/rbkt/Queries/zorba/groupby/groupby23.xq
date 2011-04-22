
xquery version "3.0";

for $item in doc('input.xml')/data/item
let $key := $item/foo
group by $key
return
  <group count="{count($item)}">
    <first>{$item[1]}</first>
  </group>
