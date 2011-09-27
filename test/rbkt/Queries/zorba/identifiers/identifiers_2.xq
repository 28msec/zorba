import module namespace idd = "http://www.zorba-xquery.com/identifiers" at "identifiers.xqlib";
import module namespace id = "http://www.zorba-xquery.com/modules/node-identifier";


declare function local:test()
{
  let $node:=<root><child>text</child></root>
  return id:node-identifier($node)
};

variable $node:=<root><child>text</child></root>;
variable $id1:=id:node-identifier($idd:node);
variable $id2:=local:test();
variable $id3:=id:node-identifier($node);


<result>
<out-of-module>{id:node-by-identifier($id1)}</out-of-module>
<temporary-variable>{id:node-by-identifier($id2)}</temporary-variable>
<in-scope>{id:node-by-identifier($id3)}</in-scope>
</result>