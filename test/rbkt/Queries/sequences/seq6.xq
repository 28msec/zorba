(: test fn:empty :)
for $i in (1,2,3) 
where fn:empty($i)
return $i
