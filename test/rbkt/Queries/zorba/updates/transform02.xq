declare variable $filename as xs:string := "test";

copy $filename := $filename
modify ()
return $filename
