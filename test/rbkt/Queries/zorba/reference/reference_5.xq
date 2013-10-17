import module namespace idd = "http://zorba.io/reference" at "reference.xqlib";
import module namespace id = "http://zorba.io/modules/reference";
import module namespace doc = "http://zorba.io/modules/store/documents";

variable $node:=<root>global</root>;

fn:put(<root>doc</root>,"doc");


<result>

<temporary-variable-in-scope>
{
  let $temp:=<root>temp</root> return id:dereference(id:reference($temp))
}
</temporary-variable-in-scope>

<temporary-variable-in-scope>
{
  let $temp:=<root>temp</root> 
  return
    let $ref:=id:reference($temp)
    return id:dereference($ref)
}
</temporary-variable-in-scope>

<temporary-variable-in-scope>
{
  for $i in (1 to 3)
  let $temp := <root>temp</root> 
  let $ref := id:reference($temp)
  return id:dereference($ref)
}
</temporary-variable-in-scope>

<temporary-variable-in-scope>
{
  let $temp:=<root>temp</root> return id:dereference(id:reference($temp))
}
</temporary-variable-in-scope>

</result>
