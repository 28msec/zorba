import module namespace file = "http://www.zorba-xquery.com/modules/file";
import module namespace commons = "http://www.zorba-xquery.com/modules/file/tests/commons" at "common.xqlib";

declare variable $xml := <elem>value</elem>;
declare variable $testDir := "tmpCreateWriteReadDeleteSeries";
declare variable $outFile := fn:concat($testDir, file:path-separator(), "file.xml");


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
(: = FILE READS AND WRITES = :)
(: ========================= :)

(: ====== DEFAULT XML ====== :)

  (: ==================================================================== :)
  (: write some XML to a file :)
  (: ========= :)
  let $s := commons:testWriteXml($outFile, $xml)
  return
    if (fn:not(commons:isSuccess($s))) then
      exit returning commons:error(("FILE R/W - DEFAULT XML - could not write to file:", $outFile))
    else ();

  (: ==================================================================== :)
  (: the written XML file must exist :)
  (: ========= :)
  let $s := commons:testExists($outFile)
  return
    if (fn:not(commons:isSuccess($s))) then
      exit returning commons:error(("FILE R/W - DEFAULT XML - could not find the written file:", $outFile))
    else ();

  (: ==================================================================== :)
  (: read the written XML from the file :)
  (: ========= :)
  let $s := commons:testReadAndCompareXml($outFile, $xml)
  return
    if (fn:not(commons:isSuccess($s))) then
      exit returning commons:error(("FILE R/W - DEFAULT XML - incorrect read from file:", $outFile))
    else ();

(: ======= METHOD XML ====== :)

  (: ==================================================================== :)
  (: write again but test the XML serialization method :)
  (: ========= :)
  let $s := commons:testWriteSerializeXml($outFile, $xml)
  return
    if (fn:not(commons:isSuccess($s))) then
      exit returning commons:error(("FILE R/W - METHOD XML - could write-serialize to file:", $outFile))
    else ();

  (: ==================================================================== :)
  (: the written XML file must exist :)
  (: ========= :)
  let $s := commons:testExists($outFile)
  return
    if (fn:not(commons:isSuccess($s))) then
      exit returning commons:error(("FILE R/W - METHOD XML - could not find the written file:", $outFile))
    else ();

  (: ==================================================================== :)
  (: read the written XML from the file :)
  (: ========= :)
  let $s := commons:testReadAndCompareXml($outFile, $xml)
  return
    if (fn:not(commons:isSuccess($s))) then
      exit returning commons:error(("FILE R/W - METHOD XML - incorrect read from file:", $outFile))
    else ();

(: ========================= :)
(: ======== DELETE ========= :)
(: ========================= :)

  (: ==================================================================== :)
  (: it must not be possible to remove a non-empty directory :)
  (: ========= :)
  let $s := commons:testRemoveNonEmptyDir($testDir)
  return
    if (commons:isSuccess($s)) then
      exit returning commons:error(("DELETE - must not delete a non-empty directory:", $outFile))
    else ();

  (: ==================================================================== :)
  (: the test directory must still exist :)
  (: ========= :)
  let $s := commons:testExists($testDir)
  return 
    if (fn:not(commons:isSuccess($s))) then
      exit returning commons:error(("DELETE - directory must exist:", $testDir))
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
