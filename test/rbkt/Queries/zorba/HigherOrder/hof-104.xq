(: Higher order function as a prolog variable :)

declare variable $func := function($x){translate($x, "abcdefghijklmnopqrstuvwxyz", "nopqrstuvwxyzabcdefghijklm")};

declare function local:scramble($x as function(xs:string) as xs:string, $y as xs:string) as xs:string {
  $x($y)
};

local:scramble($func, "john")
