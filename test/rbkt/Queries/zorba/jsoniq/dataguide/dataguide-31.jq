jsoniq version "1.0";

declare variable $doc1 :=
"
  {
    \"foo\" : { \"name\" : \"moto\", \"price\" : 100 },
    \"boo\" : { \"name\" : \"car\", \"price\" : 1000 }
  }
";

let $v := exactly-one(jn:parse-json($doc1))
return
  if ($v.foo.name eq "moto")
  then
   $v
  else
   ()
