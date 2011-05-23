

{
  variable $x := 1;

  {
    variable $y := 1;
    $x := $x + $y;
  }

  local variable $y := 10;

  $x + $y
}
