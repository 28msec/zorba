import module namespace id = "http://www.zorba-xquery.com/modules/node-identifier";

variable $node:=<root><child>text</child></root>;

variable $before-hasid:=id:has-identifier($node);
variable $before-currentid:=id:node-identifier($node);
variable $got:=id:node-identifier($node);
variable $after-hasid:=id:has-identifier($node);
variable $after:=id:node-identifier($node);

<result>
<before hasid="{$before-hasid}">{fn:string-length($before-currentid)}</before>
<after hasid="{$after-hasid}">{fn:string-length($got)}</after>
<stable>{$got eq $after}</stable>
</result>