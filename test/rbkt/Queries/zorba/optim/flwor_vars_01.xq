
declare context item := 
<doc>
  <count meaning="yes"/>
</doc>;

 
let $y := ./count[@meaning eq "yes"]
let $output := if (./@level = 3) then $y else $y
return if (./@nr = 3) then <b>{$output}</b> else $output
