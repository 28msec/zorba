declare variable $seq := fn:doc("person_events.xml");

<result>{
  for tumbling window $w in $seq/stream/event 
    start  $s when $s/person eq "Anton" and $s/direction eq "in"
    only end $e next $n when  xs:dateTime($n/@time) - xs:dateTime($s/@time) gt 
      xs:dayTimeDuration("PT1H") 
      or  ($e/person eq "Barbara" and $e/direction eq "in") 
      or ($e/person eq "Anton" and $e/direction eq "out") 
  where $e/person eq "Barbara" and $e/direction eq "in"
  return 
    <warning time="{ $e/@time }">Barbara: Anton arrived 1h ago</warning>
}</result>
