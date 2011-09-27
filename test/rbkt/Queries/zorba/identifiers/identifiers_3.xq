import module namespace idd = "http://www.zorba-xquery.com/identifiers" at "identifiers.xqlib";
import module namespace id = "http://www.zorba-xquery.com/modules/node-identifier";


variable $node:=<root><child>text</child></root>;
variable $id1:=
try
{
  id:current-node-identifier($node)
}
catch ZAPI0090
{
  "No current id"
};
variable $id2:=id:node-identifier($node);
variable $id3:=id:current-node-identifier($node);


<result>
<before>{$id1}</before>
<get>{fn:string-length($id2)}</get>
<after equal="{$id2 =$id3}">{fn:string-length($id3)}</after>
</result>