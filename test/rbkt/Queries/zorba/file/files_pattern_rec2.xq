import module namespace file = "http://expath.org/ns/file";

declare variable $path as xs:string external;

let $sep := file:directory-separator()
let $escaped_sep :=
  if ($sep eq "\") then
    fn:concat("\", $sep)
  else
    $sep
let $files := file:list($path, fn:true(), "*.txt")
for $file in $files
where fn:not(fn:matches($file, "\.svn"))
let $f := fn:replace($file, $escaped_sep, "/")
order by $f
return <result>{$f}</result>
