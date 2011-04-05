import module namespace file = "http://www.zorba-xquery.com/modules/file";

declare variable $path as xs:string external;

let $files := file:list($path, fn:false(), "*dir*")
for $file in $files
order by $file
return <result>{$file}</result>
