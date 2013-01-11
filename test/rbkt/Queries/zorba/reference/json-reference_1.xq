import module namespace id = "http://www.zorba-xquery.com/modules/reference";

variable $node := { "foo" : "bar" };

variable $before-currentid:=id:reference($node);
variable $got:=id:reference($node);
variable $after:=id:reference($node);

<result>
<before>{fn:string-length($before-currentid)}</before>
<after>{fn:string-length($got)}</after>
<stable>{$got eq $after}</stable>
</result>

