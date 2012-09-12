declare variable $seq := fn:doc("person_events.xml");

<result>
{
for sliding window $w in $seq/stream/event 
  start $s when $s/direction eq "in"
  only end $e when $s/person eq $e/person and $e/direction eq "out"
let $person := $s/person
let $workingTime := xs:dateTime($e/@time) - xs:dateTime($s/@time)
group by $person2 := $person
return
  <working-time>
    { $person[1] }
    <time>{ sum($workingTime) }</time>
  </working-time>
}
</result>
