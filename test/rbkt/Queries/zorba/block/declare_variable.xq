declare sequential function local:test2 () as xs:string
{
  declare $local_variable as xs:string := "result";

  $local_variable;
};

local:test2 ()
