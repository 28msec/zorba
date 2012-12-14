
variable $doc := <a><b/></a>;

for $x allowing empty at $pos in $doc/foo
where $pos = 1
return <result>{$x}</result>
,
"
,
"
,
for $x allowing empty at $pos in fn:subsequence($doc/foo, 1, 1)
return <result>{$x, $pos}</result>
,
"
"
