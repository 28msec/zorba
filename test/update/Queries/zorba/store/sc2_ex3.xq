import module namespace cdml = "http://www.zorba-xquery.com/modules/store/dynamic/collections/dml";

for $e in cdml:collection(xs:QName("earthquakes"))
let $r := $e/column[last()] (: last column contains region name :)
where xs:double($e/column[7]) > 3 (: 7th column contains magnitude :)
group by $r2 := $r
let $r := $r[1]
where $r contains text ("California")
return
  <region name="{$r}">{ $e }</region>
