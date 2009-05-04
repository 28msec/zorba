declare variable $var := 42;

declare function local:getQuery() as xs:string {
  "$x + $y + local:f()"
};

declare function local:f() {
  1 + 1
};

for $y in 1 to 10
let $x := $var
where $y mod 2 eq 0
return 
  using $x, $y 
  eval { local:getQuery() }
