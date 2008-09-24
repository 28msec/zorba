declare variable $x1 as xs:integer* := (123, 1, 2, 3);
declare variable $foo := <a>elem</a>;
declare variable $var := <bar>fuebar</bar>;

for $e in (1 to 10)
return
 if ($e mod 1000 eq 0)
 then $e
 else ()
