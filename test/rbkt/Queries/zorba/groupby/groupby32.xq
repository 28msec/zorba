declare variable $doc :=
<root>
<elem id = "1" val="1">0</elem>
<elem id = "2" val="5">0</elem>
<elem id = "3" val="2">0</elem>
<elem id = "4" val="1">1</elem>
<elem id = "5" val="7">1</elem>
<elem id = "6" val="1">1</elem>
</root>;

for $i in 1 to 6
group by $x := ($doc/elem)[$i], $y := $x/@val
return <res>{$x} : {$y}</res>
