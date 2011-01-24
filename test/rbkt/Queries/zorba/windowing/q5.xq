declare variable $timesequence := fn:doc("temp_events.xml");
let $SMOOTH_CONST := 0.2

for sliding window $w in $timesequence/stream/event
  start at $s_pos when true()
  only end at $e_pos when $e_pos - $s_pos eq 2
return 
  round-half-to-even($SMOOTH_CONST * data($w[3]/@temp) + (1 - $SMOOTH_CONST) *
    ( $SMOOTH_CONST * data($w[2]/@temp) + 
      (1 - $SMOOTH_CONST) * data($w[1]/@temp) ), 2)
