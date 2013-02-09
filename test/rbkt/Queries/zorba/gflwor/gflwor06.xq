declare variable $doc := <a/>;

for $x allowing empty in $doc/foo
return count($x)
