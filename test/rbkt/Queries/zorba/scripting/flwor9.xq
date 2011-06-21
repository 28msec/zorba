variable $seq as xs:string* := ();

for $x in (1,2,3,4)
return  
{
  if (empty($seq))
  then
  {
    $seq:=($seq, "empty", string($x));
  }
  else
  {
    $seq:=($seq, "full", string($x));
  }
}

$seq
