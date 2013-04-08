

(:
 : Test shows that index join rewrite should not be done if the inner var is
 : an outer-FOR variable.
 :)

declare variable $doc := <a/>;

for $x in (1, 2, 3, 4)
for $y allowing empty in $doc/foo
where $x eq count($y)
return 1
