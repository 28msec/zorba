import module namespace file = "http://expath.org/ns/file";
import module namespace commons = "http://expath.org/ns/file/tests/commons" at "common.xqlib";

declare namespace ann = "http://www.zorba-xquery.com/annotations";

declare variable $xml := <elem>value</elem>;
declare variable $testDir := "tmpCreateWriteReadDeleteSeries";
declare variable $outFile := fn:concat($testDir, file:directory-separator(), "file.xml");


declare %ann:nondeterministic %ann:sequential function local:main() as xs:string* {

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
(: = FILE READS AND WRITES = :)
(: ========================= :)

(: ====== DEFAULT XML ====== :)

  (: ==================================================================== :)
  (: write some XML to a file :)
  (: ========= :)
  variable $s2 := commons:testWriteXml($outFile, $xml);
  if (fn:not(commons:isSuccess($s2))) then
    exit returning commons:error(("FILE R/W - DEFAULT XML - could not write to file:", $outFile));
  else ();

  (: ==================================================================== :)
  (: the written XML file must exist :)
  (: ========= :)
  variable $s3 := commons:testExists($outFile);
  if (fn:not(commons:isSuccess($s3))) then
    exit returning commons:error(("FILE R/W - DEFAULT XML - could not find the written file:", $outFile));
  else ();

  (: ==================================================================== :)
  (: read the written XML from the file :)
  (: ========= :)
  variable $s4 := commons:testReadAndCompareXml($outFile, $xml);
  if (fn:not(commons:isSuccess($s4))) then
    exit returning commons:error(("FILE R/W - DEFAULT XML - incorrect read from file:", $outFile));
  else ();

(: ======= METHOD XML ====== :)

  (: ==================================================================== :)
  (: write again but test the XML serialization method :)
  (: ========= :)
  variable $s5 := commons:testWriteSerializeXml($outFile, $xml);
  if (fn:not(commons:isSuccess($s5))) then
    exit returning commons:error(("FILE R/W - METHOD XML - could write-serialize to file:", $outFile));
  else ();

  (: ==================================================================== :)
  (: the written XML file must exist :)
  (: ========= :)
  variable $s6 := commons:testExists($outFile);
  if (fn:not(commons:isSuccess($s6))) then
    exit returning commons:error(("FILE R/W - METHOD XML - could not find the written file:", $outFile));
  else ();

  (: ==================================================================== :)
  (: read the written XML from the file :)
  (: ========= :)
  variable $s7 := commons:testReadAndCompareXml($outFile, $xml);
  if (fn:not(commons:isSuccess($s7))) then
    exit returning commons:error(("FILE R/W - METHOD XML - incorrect read from file:", $outFile));
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
