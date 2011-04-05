import module namespace file = "http://www.zorba-xquery.com/modules/file";

declare variable $path as xs:string external;

let $files := file:list($path, fn:true(), "*dir*")
for $file in $files
where fn:not(fn:matches($file, "\.svn"))
let $f := fn:replace($file, fn:concat("\", file:directory-separator()), "/")
order by $f
return <result>{$f}</result>
