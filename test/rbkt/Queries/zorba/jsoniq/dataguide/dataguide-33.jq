jsoniq version "1.0";

declare variable $doc :=
" { 
      \"foo\"  : { \"name\" : \"moto1\", \"price\" : 100 },
      \"boo\"  : { \"name\" : \"moto2\", \"price\" : 120 },
      \"boo2\" : { \"name\" : \"moto3\", \"price\" : 130 }
  } 
";

for tumbling window $var in jn:parse-json($doc)
start $s previous $p when fn:true()
end next $n when fn:true()
return ($var.foo, $s.boo)
