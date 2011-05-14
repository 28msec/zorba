
let $doc := <root>
              <foo id="-1"><boo id="1"/><boo id="2"/></foo>
              <foo id="-2"><boo id="3"/><boo id="4"/></foo>
            </root>

for $a in $doc/foo
for $b in $a//boo
return
{
  variable $x := $b/@id;

  for $c in 1 to $x
  return $a/@id + 2 * $x + $c
}

(:

 $a  $b  $x  $c  res

 -1   1   1   1   2

 -1   2   2   1   4

 -1   2   2   2   5

 -2   3   3   1   5

 -2   3   3   2   6

 -2   3   3   3   7

 -2   4   4   1   7

 -2   4   4   2   8

 -2   4   4   3   9

 -2   4   4   4  10

:)
