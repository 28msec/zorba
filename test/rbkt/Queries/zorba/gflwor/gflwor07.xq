import module namespace ddl = 
"http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl";

import module namespace dml = 
"http://www.zorba-xquery.com/modules/store/dynamic/collections/dml";


variable $foo := 1;

ddl:create(xs:QName("FOO"));


for $zip in dml:collection(xs:QName("FOO"))//foo
let $zip := jn:parse-json(xs:string($zip))
let $state := $zip("state")
group by $state
let $pop := sum($zip("pop"))
where $pop > 10000000
order by $pop descending
return
{
 "state": $state,
 "population" : $pop,
 "seq" : { $foo := $foo+1; $foo }
}
