import module namespace file = "http://www.zorba-xquery.com/modules/file";
import module namespace base64 = "http://www.zorba-xquery.com/modules/base64";
import module namespace commons = "http://www.zorba-xquery.com/modules/file/tests/commons" at "common.xqlib";

declare variable $inFile as xs:string := fn:concat(file:dirname(fn:static-base-uri()), "/../image/images/bird.gif");
declare variable $testDir as xs:string := fn:concat(file:dirname(fn:static-base-uri()),"/tmpBinaryReadWrite");
declare variable $outFile as xs:string := fn:concat($testDir, file:path-separator(), "bird.gif");

declare sequential function local:thisTest() as xs:string* {
  (: ==================================================================== :)
  (: read the image file (binary) :)
  (: ========= :)
  let $base64In := commons:testReadBinary($inFile)
  return block {
    file:write($outFile, base64:decode($base64In), <method>binary</method>);
    let $base64Out := commons:testReadBinary($outFile)
    return
      if ($base64In ne $base64Out) then
        exit returning "the initial and the final base64 did not match"
      else ();
  };

  "SUCCESS";
};

declare sequential function local:main() as xs:string* {

(: ========================= :)
(: ==== DIRECTORY INIT ===== :)
(: ========================= :)

  (: ==================================================================== :)
  (: initialize test - create test directory :)
  (: ========= :)
  let $s := commons:testInitDir($testDir)
  return
    if (fn:not(commons:isSuccess($s))) then
      exit returning commons:error(("DIRECTORY INIT - failed:
", $s))
    else ();  

(: ========================= :)
(: ====== THIS TEST ======== :)
(: ========================= :)

  (: ==================================================================== :)
  (: the image file to read must exist :)
  (: ========= :)
  let $s := commons:testExists($inFile)
  return
    if (fn:not(commons:isSuccess($s))) then
      exit returning commons:error(("Could not find the image to read:
", $s))
    else ();

  (: ==================================================================== :)
  (: perform this test - binary read and write :)
  (: ========= :)
  let $s := local:thisTest()
  return
    if (fn:not(commons:isSuccess($s))) then
      exit returning commons:error(("Binary r/w failed:
", $s))
    else ();

(: ========================= :)
(: === DIRECTORY UNINIT ==== :)
(: ========================= :)

  (: ==================================================================== :)
  (: initialize test - create test directory :)
  (: ========= :)
  let $s := commons:testUnInitDir($testDir, $outFile)
  return
    if (fn:not(commons:isSuccess($s))) then
      exit returning commons:error(("DIRECTORY UNINIT - failed:
", $s))
    else ();  

  (: ==================================================================== :)

  "SUCCESS";

};

local:main()
