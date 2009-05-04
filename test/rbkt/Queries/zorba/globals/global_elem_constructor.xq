declare variable $x := <a/>;
declare variable $y := 42;
declare function local:f () {
  $x
};

count ((local:f() union $x union $x union local:f(), $y))
