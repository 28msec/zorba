
variable $x :=
element {QName("http://outer","bind")}
{
element {QName("http://named","named:middle")}
{
element {QName("","b")}
{
"inner"
}
}
};


$x

(:

let $node := $x//*:b
for $pre in in-scope-prefixes($node)
return ($pre, " --> ", namespace-uri-for-prefix($pre, $node), "
")

:)
