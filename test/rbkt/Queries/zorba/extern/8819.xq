declare variable $in := (<logfile>
	<event action="login" uid="1" />   (:  1 :)
	<event action="fail" uid="1" />    (:  2 :)
	<event action="login" uid="1" />   (:  3 :)
	<event action="fail" uid="2" />    (:  4 :)
	<event action="login" uid="1" />   (:  5 :)
	<event action="fail" uid="1" />    (:  6 :)
	<event action="login" uid="1" />   (:  7 :)
	<event action="login" uid="1" />   (:  8 :)
	<event action="fail" uid="2" />    (:  9 :)
	<event action="login" uid="1" />   (: 10 :)
	<event action="fail" uid="2" />    (: 11 :)
	<event action="login" uid="1" />   (: 12 :)
	<event action="fail" uid="3" />    (: 13 :)
	<event action="fail" uid="3" />    (: 14 :)
	<event action="fail" uid="3" />    (: 15 :)
	<event action="login" uid="1" />   (: 16 :)
	<event action="login" uid="1" />   (: 17 :)
	<event action="fail" uid="4" />    (: 18 :)
	<event action="fail" uid="4" />    (: 19 :)
	<event action="login" uid="4" />   (: 20 :)
	<event action="login" uid="1" />   (: 21 :)
</logfile>) ;

for $e in $in/event
let $uid := $e/@uid
group by $uid
for sliding window $w in $e
    start $start at $startpos
    next $smid
    when $start/@action = 'fail'
    only end $end at $endpos
    when $endpos - $startpos = 2 and $smid/@action = 'fail' and $end/@action = 'fail'
return <r>{data($w[1]/@uid)}</r>


(:

1 --> 1.login, 2.fail, 3.login, 5.login, 6.fail, 7.login, 8.login, 10.login, 12.login
      16.login, 17.login, 21.login

2 --> 4.fail, 9.fail, 11.fail, 

3 --> 

:)
