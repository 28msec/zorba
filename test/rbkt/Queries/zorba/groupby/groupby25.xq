for $a in 1
for $a in 2
for $b in (1, 2, 1, 1)
group by $b
return <b>{$b}<a>{$a}</a></b>
