import module namespace id = "http://www.zorba-xquery.com/modules/node-reference";

variable $node:=<root><child>text</child></root>;

variable $before-currentid:=id:node-reference($node);
variable $got:=id:node-reference($node);
variable $after:=id:node-reference($node);

<result>
<before>{fn:string-length($before-currentid)}</before>
<after>{fn:string-length($got)}</after>
<stable>{$got eq $after}</stable>
</result>