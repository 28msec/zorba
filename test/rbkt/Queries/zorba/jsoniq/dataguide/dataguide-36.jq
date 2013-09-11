jsoniq version "1.0";

declare variable $doc1 :=
"
  {
    \"foo\" :  { \"name\" : \"moto\", \"price\" : 100 },
    \"boo\" :  { \"name\" : \"car\",  \"price\" : 1000 }
  }
";

declare function local:nav($var)
{
  $var.boo
};
  
(
  let $v := exactly-one(jn:parse-json($doc1))
  where ( if ($v.foo.name eq "moto")
          then
            local:nav($v)
          else
            ()
        ).price ge 100
  return $v.foo
).price
