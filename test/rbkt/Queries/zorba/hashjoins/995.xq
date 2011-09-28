let $x := doc("995.xml")/phones
for $a in $x/entry
  for $b in $x/entry
    where $a/last_name eq $b/last_name
    return $a