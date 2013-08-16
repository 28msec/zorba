declare namespace ann = "http://zorba.io/annotations";

{
  %ann:nonassignable variable $var := 3;

  $var := 5;
  $var
}

