import module namespace file = "http://www.zorba-xquery.com/modules/file";

declare variable $path as xs:string external;

let $files := file:files($path, "dir", fn:false())
for $file in $files
order by $file
return <result>{$file}</result>
