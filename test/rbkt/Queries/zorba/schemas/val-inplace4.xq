import module namespace schema = "http://zorba.io/modules/schema";
import schema namespace d="http://www.example.com/doc" at "val-inplace4.xsd";
import module namespace file = "http://expath.org/ns/file";
declare revalidation lax;

variable $doc:=<items xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
       xmlns="http://www.zorba-xquery.org/schema">
  <bigEl>
    <a>old</a>
  </bigEl>
</items>;

variable $doc-2:=<items xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
       xmlns="http://www.zorba-xquery.org/schema">
  <bigEl>
    <a>old</a>
  </bigEl>
</items>;

(
  schema:validate-in-place($doc),
  rename node $doc/*:bigEl as QName("http://www.zorba-xquery.org/schema","smallEl")
);


schema:validate-in-place($doc-2);
(
<doc>
{
for $x in ($doc//*)
return (<node name="{node-name($x)}" type="{schema:schema-type($x)}"/>)
}
</doc>,
<doc2>
{
for $x in ($doc-2//*)
return (<node name="{node-name($x)}" type="{schema:schema-type($x)}"/>)
}
</doc2>
)