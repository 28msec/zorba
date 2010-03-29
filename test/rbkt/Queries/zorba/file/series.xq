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


declare sequential function local:testExists($path as xs:string) as xs:boolean {
  let $b := file:exists($path)
  return fn:not($b)
};

declare sequential function local:testMkdirs($path as xs:string) as xs:boolean {
  file:mkdirs($path)
};

declare sequential function local:testWrite($path as xs:string) as xs:boolean {
  file:write($path, $xml, ());
  fn:true();
};

declare sequential function local:testRead($path as xs:string) as xs:boolean {
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
declare sequential function local:testRemoveNonEmptyDir($path as xs:string) as xs:boolean {
  try {
    file:remove($path)
  } catch * {
    fn:true()
  }
};

declare sequential function local:testRemoveFile($path as xs:string) as xs:boolean {
  file:remove($path)
};

declare sequential function local:testWriteSerialize($path as xs:string) as xs:boolean {
  file:write($path, $xml, <options method="xml" />/@*);
  fn:true();
};

declare sequential function local:testRemoveDir($path as xs:string) as xs:boolean {
  file:remove($path)
};

declare sequential function local:main() as xs:string* {
  (: ==================================================================== :)
  let $b := local:testExists($dir)
  return
    if (fn:not($b)) then
      exit returning local:error(("directory already exists:", $dir))
    else ();

  (: ==================================================================== :)
  let $b := local:testMkdirs($dir)
  return 
    if (fn:not($b)) then
      exit returning local:error(("could not create directory:", $dir))
    else ();

  (: ==================================================================== :)
  let $b := local:testExists($dir)
  return 
    if ($b) then
      exit returning local:error(("directory must exists:", $dir))
    else ();

  (: ==================================================================== :)
  let $b := local:testWrite($file)
  return
    if (fn:not($b)) then
      exit returning local:error(("could not write to file:", $file))
    else ();

  (: ==================================================================== :)
  let $b := local:testRead($file)
  return
    if (fn:not($b)) then
      exit returning local:error(("incorrect read from file:", $file))
    else ();

  (: ==================================================================== :)
  let $b := local:testRemoveNonEmptyDir($dir)
  return
    if (fn:not($b)) then
      exit returning local:error(("should not delete", $file))
    else ();

  (: ==================================================================== :)
  let $b := local:testRemoveFile($file)
  return
    if (fn:not($b)) then
      exit returning local:error(("could not delete file:", $file))
    else ();

  (: ==================================================================== :)
  let $b := local:testWriteSerialize($file)
  return
    if (fn:not($b)) then
      exit returning local:error(("could write-serialize to file:", $file))
    else ();

  (: ==================================================================== :)
  let $b := local:testRemoveFile($file)
  return
    if (fn:not($b)) then
      exit returning local:error(("could not delete file-serialize:", $file))
    else ();

  (: ==================================================================== :)
  let $b := local:testRemoveDir($dir)
  return
    if (fn:not($b)) then
      exit returning local:error(("could not delete directory:", $dir ,"directory"))
    else ();

  (: ==================================================================== :)
  "SUCCESS";
};

local:main()
