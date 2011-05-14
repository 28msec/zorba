declare %sequential function local:test2 () as xs:string
{
  variable $local_variable as xs:string := "result";

  $local_variable
};

local:test2 ()
