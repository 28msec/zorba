declare variable $timesequence := fn:doc("6123.xml");
let $SMOOTH_CONST := 0.2

for sliding window $w in $timesequence/stream/event
  start at $s_pos when true()
  only end at $e_pos when $e_pos - $s_pos eq 2
return
  (
  round-half-to-even(
    $SMOOTH_CONST * data($w[3]/@temp) +
    (1 - $SMOOTH_CONST) * 
    ($SMOOTH_CONST * data($w[2]/@temp) + (1 - $SMOOTH_CONST) * data($w[1]/@temp)),
    2)
  )


(:

<root>

<window>
  <event temp="10" time="1"></event>
  <event temp="8" time="2"></event>
  <event temp="6" time="3"></event>
</window>
8.88

<window>
  <event temp="8" time="2"></event>
  <event temp="6" time="3"></event>
  <event temp="13" time="4"></event>
</window>
8.68

<window>
  <event temp="6" time="3"></event>
  <event temp="13" time="4"></event>
  <event temp="32" time="5"></event>
</window>
12.32

<window>
  <event temp="13" time="4"></event>
  <event temp="32" time="5"></event>
  <event temp="9" time="6"></event>
</window>
15.24

<window>
  <event temp="32" time="5"></event>
  <event temp="9" time="6"></event>
  <event temp="10" time="7"></event>
</window>
23.92

</root>

:)
