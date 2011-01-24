declare variable $seq := fn:doc("cxml_sm.xml");

<result>
{
for sliding window $w in $seq/sequence/*
start $cur previous $prev
when day-from-dateTime($cur/@date) ne day-from-dateTime($prev/@date) or empty($prev)
end $end next $next
when day-from-dateTime(xs:dateTime($end/@date)) ne day-from-dateTime(xs:dateTime($next/@date))
return
<window>
  <prev>{$prev/@date, node-name($prev)}</prev>,
  <cur>{$cur/@date, node-name($cur)}</cur>,
  <end>{$end/@date, node-name($end)}</end>,
  <next>{$next/@date, node-name($next)}</next>
</window>
}
</result>
