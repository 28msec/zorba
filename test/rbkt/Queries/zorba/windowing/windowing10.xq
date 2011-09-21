declare variable $seq := fn:doc("person_events_sm.xml");

<result>
{
for sliding window $w in $seq/stream/event
    start $s when $s/direction eq "in"
    only end $e when $s/person eq $e/person and $e/direction eq "out"
let $person := $s/person
let $workingTime := xs:dateTime($e/@time) - xs:dateTime($s/@time)
return
  <window>
  {$s}
  {$e}
  </window>
}
</result>
