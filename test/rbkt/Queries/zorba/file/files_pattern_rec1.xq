import module namespace file = "http://expath.org/ns/file";

declare variable $path as xs:string external;

let $files := file:list($path, fn:true(), "*dir*")
for $file in $files
where fn:not(fn:matches($file, "\.svn"))
let $f := fn:replace($file, fn:concat("\", file:directory-separator()), "/")
order by $f
return <result>{$f}</result>
