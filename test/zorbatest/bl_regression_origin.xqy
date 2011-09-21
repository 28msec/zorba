declare variable $bl_raw_regress external;
declare variable $bl_prev_regress external;
declare variable $now external;
declare variable $rev external;

<root>{
for $r in $bl_raw_regress//regress
return
<regress>
{$r/case} {

let $prevr := $bl_prev_regress//regress [case eq $r/case] return
if ($prevr) then $prevr/since
else <since><rev>{$rev}</rev><date>{$now}</date></since>

}</regress>}{$bl_raw_regress//progress}
</root>
