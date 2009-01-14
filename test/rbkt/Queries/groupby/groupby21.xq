let $doc := <doc> 
<item><key1>1</key1>  <key2>1</key2> <key3>1</key3> <value>a</value></item>
<item><key1>1</key1>  <key2>1</key2> <key3></key3> <value>b</value></item>
<item><key1>1</key1>  <key2>1</key2> <key3></key3> <value>c</value></item>
<item><key1>1</key1>                 <key3>1</key3> <value>d</value></item>
<item><key1>1</key1>                 <key3>1</key3> <value>e</value></item>
<item><key1>1</key1>                 <key3>2</key3> <value>f</value></item>
<item><key1>1</key1>                  <key3>2</key3> <value>g</value></item>
</doc>
for $item in $doc/item
let $key1 := $item/key1
let $key2 := $item/key2
let $key3 := $item/key3
let $value := $item/value
group by $key1, $key2, $key3
return <result key1="{$key1}" key2="{$key2}" key3="{$key3}">{$value/text()}</result>
