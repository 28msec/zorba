import module namespace file = "http://www.zorba-xquery.com/modules/file";

declare variable $xml := <elem>value</elem>;
declare variable $dir := "test";
declare variable $file := fn:concat($dir, file:path-separator(), "file.xml");

declare function local:error($messages as xs:string*) as xs:string* {
  "
************************************************************************
ERROR:
  Location:", file:path-to-full-path("."), "
  Cause:",
  $messages,
  "
************************************************************************
"
};


declare function local:testExists($path as xs:string) as xs:boolean {
  fn:not(file:exists($path))
};

declare function local:testMkdirs($path as xs:string) as xs:boolean {
  file:mkdirs($path)
};

declare function local:testWrite($path as xs:string) as xs:boolean {
  file:write($path, $xml, ()),
  fn:true()
};

declare function local:testRead($path as xs:string) as xs:boolean {
  let $x := file:read-xml($path)
  return
    if($x eq $xml) then 
      fn:true()
    else
      fn:false()
};

(:~
 : This test succeeds when the the delete operation fails for non-empty
 : directories.
 :)
declare function local:testRemoveNonEmptyDir($path as xs:string) as xs:boolean {
  try {
    file:remove($path)
  } catch * {
    fn:true()
  }
};

declare function local:testRemoveFile($path as xs:string) as xs:boolean {
  file:remove($path)
};

declare function local:testWriteSerialize($path as xs:string) as xs:boolean {
  let $serOpt := <options
    method="xml" />
  return
    file:write($path, $xml, $serOpt/@*),
  fn:true()
};

declare function local:testRemoveDir($path as xs:string) as xs:boolean {
  file:remove($path)
};


(: ==================================================================== :)
if (fn:not(local:testExists($dir))) then
  local:error(("directory already exists:", $dir))
(: ==================================================================== :)
else if (fn:not(local:testMkdirs($dir))) then
  local:error(("could not create directory:", $dir))
(: ==================================================================== :)
else if (local:testExists($dir)) then
  local:error(("directory must exists:", $dir))
(: ==================================================================== :)
else if (fn:not(local:testWrite($file))) then
  local:error(("could not write to file:", $file))
(: ==================================================================== :)
else if (fn:not(local:testRead($file))) then
  local:error(("incorrect read from file:", $file))
(: ==================================================================== :)
else if (fn:not(local:testRemoveNonEmptyDir($dir))) then
  local:error(("should not delete", $file))
(: ==================================================================== :)
else if (fn:not(local:testRemoveFile($file))) then
  local:error(("could not delete file:", $file))
(: ==================================================================== :)
else if (fn:not(local:testWriteSerialize($file))) then
  local:error(("could write-serialize to file:", $file))
(: ==================================================================== :)
else if (fn:not(local:testRemoveFile($file))) then
  local:error(("could not delete file-serialize:", $file))
(: ==================================================================== :)
else if (fn:not(local:testRemoveDir($dir))) then
  local:error(("could not delete directory:", $dir ,"directory"))
(: ==================================================================== :)
else
  "SUCCESS"
