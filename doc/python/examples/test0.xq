declare variable $sequence := (65 to 90);
declare variable $var := 1;

declare %sequential function local:foo()
{
  $var := $var + 1;
  $var
};


declare %sequential function local:bar()
{
  for $i in (1 to 10)
  return
    {
      variable $rand := local:foo();

      $sequence[$rand]
    }
};


local:bar()