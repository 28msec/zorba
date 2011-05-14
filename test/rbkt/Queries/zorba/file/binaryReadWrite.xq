import module namespace base64 = "http://www.zorba-xquery.com/modules/base64";
import module namespace commons = "http://expath.org/ns/file/tests/commons" at "common.xqlib";

import module namespace file = "http://expath.org/ns/file";

import schema namespace output = "http://www.w3.org/2010/xslt-xquery-serialization";

declare variable $inFile as xs:string := fn:concat(file:dir-name(fn:static-base-uri()), "/../image/images/bird.gif");
declare variable $testDir as xs:string := fn:concat(file:dir-name(fn:static-base-uri()),"/tmpBinaryReadWrite");
declare variable $outFile as xs:string := fn:concat($testDir, file:directory-separator(), "bird.gif");

declare %sequential function local:thisTest() as xs:string* {
  (: ==================================================================== :)
  (: read the image file (binary) :)
  (: ========= :)
  let $base64In := commons:testReadBinary($inFile)
  return {
    file:write-binary(
      $outFile,
      $base64In);
    let $base64Out := commons:testReadBinary($outFile)
    return
      if ($base64In ne $base64Out) then
        exit returning "the initial and the final base64 did not match";
      else ();
  }

  "SUCCESS"
};


declare %sequential function local:main() as xs:string* 
{

(: ========================= :)
(: ==== DIRECTORY INIT ===== :)
(: ========================= :)

  (: ==================================================================== :)
  (: initialize test - create test directory :)
  (: ========= :)
  variable $s1 := commons:testInitDir($testDir);
  if (fn:not(commons:isSuccess($s1))) then
    exit returning commons:error(("DIRECTORY INIT - failed: 
", $s1));
    else ();

(: ========================= :)
(: ====== THIS TEST ======== :)
(: ========================= :)

  (: ==================================================================== :)
  (: the image file to read must exist :)
  (: ========= :)
  variable $s2 := commons:testExists($inFile);
  if (fn:not(commons:isSuccess($s2))) then
    exit returning commons:error(("Could not find the image to read:
", $s2));
  else ();

  (: ==================================================================== :)
  (: perform this test - binary read and write :)
  (: ========= :)
  variable $s3 := local:thisTest();
  if (fn:not(commons:isSuccess($s3))) then
    exit returning commons:error(("Binary r/w failed:
", $s3));
    else ();

(: ========================= :)
(: === DIRECTORY UNINIT ==== :)
(: ========================= :)

  (: ==================================================================== :)
  (: initialize test - create test directory :)
  (: ========= :)
  {
    variable $s := commons:testUnInitDir($testDir);

    if (fn:not(commons:isSuccess($s))) 
    then
      exit returning commons:error(("DIRECTORY UNINIT - failed:", $s));
    else 
      ();  
  }

  (: ==================================================================== :)

  "SUCCESS"

};

local:main()
