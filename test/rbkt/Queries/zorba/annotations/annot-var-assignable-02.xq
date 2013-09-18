declare namespace ann = "http://zorba.io/annotations";

{
  %ann:assignable variable $var := 3;

  $var := 5;
  $var
}
