declare variable $x := 1;
declare sequential function local:f () {
  declare $x := 2;
  set $x := $x + 10;
  exit with $x;
};

set $x := $x + 100;
($x, local:f (), $x);
