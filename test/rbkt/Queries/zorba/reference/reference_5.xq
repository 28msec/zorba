import module namespace idd = "http://www.zorba-xquery.com/reference" at "reference.xqlib";
import module namespace id = "http://www.zorba-xquery.com/modules/node-reference";
import module namespace doc = "http://www.zorba-xquery.com/modules/store/dynamic/documents";

variable $node:=<root>global</root>;

fn:put(<root>doc</root>,"doc");


<result>
<temporary-variable-in-scope>{let $temp:=<root>temp</root> return id:node-by-reference(id:node-reference($temp))}</temporary-variable-in-scope>
<temporary-variable-in-scope>{
let $temp:=<root>temp</root> 
return
let $ref:=id:node-reference($temp)
return
id:node-by-reference($ref)
}</temporary-variable-in-scope>
<temporary-variable-in-scope>{
for $i in (1 to 3)
let $temp:=<root>temp</root> 
let $ref:=id:node-reference($temp)
return
id:node-by-reference($ref)
}</temporary-variable-in-scope>

<temporary-variable-in-scope>{let $temp:=<root>temp</root> return id:node-by-reference(id:node-reference($temp))}</temporary-variable-in-scope>

</result>
