import module namespace file = "http://expath.org/ns/file";

declare variable $path as xs:string external;

let $files := file:list($path, fn:false(), "*.txt")
for $file in $files
order by $file
return <result>{$file}</result>
