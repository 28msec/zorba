import module namespace idd = "http://www.zorba-xquery.com/reference" at "reference.xqlib";
import module namespace id = "http://www.zorba-xquery.com/modules/node-reference";
import module namespace doc = "http://www.zorba-xquery.com/modules/store/dynamic/documents";
import module namespace map = "http://www.zorba-xquery.com/modules/store/data-structures/unordered-map";

variable $node:=<root>global</root>;
variable $x := <a>1</a>;
fn:put(<root>doc</root>,"doc");

map:create(xs:QName("local:bar"), xs:QName("xs:integer"));
map:insert(xs:QName("local:bar"), id:node-reference($x), 1);



<result>
<out-of-module-global>{id:node-by-reference(id:node-reference($idd:node))}</out-of-module-global>
<put-doc>{id:node-by-reference(id:node-reference(doc:document("doc")))}</put-doc>
<in-scope>{id:node-by-reference(id:node-reference($node))}</in-scope>

<temporary-variable-out-of-scope>{id:node-by-reference(id:node-reference(<root>temp</root>))}</temporary-variable-out-of-scope>
<temporary-variable-in-scope>{
for $i in (1 to 3)
let $temp:=<root>{$i}</root>
where string($temp) = string($i)   
let $ref:=id:node-reference($temp)
return
id:node-by-reference($ref)
}</temporary-variable-in-scope>
<temporary-variable-in-scope>{variable $temp:=<root>temp</root>; id:node-by-reference(id:node-reference($temp))}</temporary-variable-in-scope>
<in-map>
{id:node-by-reference(map:get(xs:QName("local:bar"), 1))}
</in-map>
</result>