import module namespace np = "http://www.zorba-xquery.com/modules/node-position";

declare function local:get-ordpath($struct)
{
replace($struct,'^zorba:\d*\.[0-9a-fA-F\-]*\.\d*\.','np:')
};

declare function local:test-generated-ordpath($testa,$testb)
{
  let $orda:=local:get-ordpath(np:node-position($testa))
  let $ordb:=local:get-ordpath(np:node-position($testb))
  return
    if ($orda eq $ordb)
    then concat("OK: ",$orda)    
    else concat("KO: ",$orda," != ",$ordb)    
};

variable $test1a:=text{"aaa"};
variable $test1b:=<aaa/>;

variable $test2a:=<element>aaa</element>;
variable $test2b:=<element><aaa/></element>;

variable $test3a:=<element><x/>aaa</element>;
variable $test3b:=<element><x/><aaa/></element>;

variable $test4a:=<element attr="attr">aaa</element>;
variable $test4b:=<element attr="attr"><aaa/></element>;

variable $test5a:=<element attr="attr"><x/>aaa</element>;
variable $test5b:=<element attr="attr"><x/><aaa/></element>;

variable $test6a:=<element>aaa</element>;
variable $test6b:=<element><aaa/></element>;

variable $test7a:=<element><x/>aaa</element>;
variable $test7b:=<element><x/><aaa/></element>;

variable $test8a:=<element attr="attr">aaa</element>;
variable $test8b:=<element attr="attr"><aaa/></element>;

variable $test9a:=<element attr="attr"><x/>aaa</element>;
variable $test9b:=<element attr="attr"><x/><aaa/></element>;

variable $test10a:=<element><bbb/></element>;
insert node text{"aaa"} as first into $test10a;
variable $test10b:=<element><bbb/></element>;
insert node <aaa/> as first into $test10b;

variable $test11a:=<element><x/><bbb/></element>;
insert node text{"aaa"} after $test11a/x;
variable $test11b:=<element><x/><bbb/></element>;
insert node <aaa/> after $test11b/x;

variable $test12a:=<element attr="attr"><bbb/></element>;
insert node text{"aaa"} as first into $test12a;
variable $test12b:=<element attr="attr"><bbb/></element>;
insert node <aaa/> as first into $test12b;

variable $test13a:=<element attr="attr"><x/><bbb/></element>;
insert node text{"aaa"} after $test13a/x;
variable $test13b:=<element attr="attr"><x/><bbb/></element>;
insert node <aaa/> after $test13b/x;

<result>
  <test1>{local:test-generated-ordpath($test1a,$test1b)}</test1>
  <test2>{local:test-generated-ordpath($test2a/text(),$test2b/aaa)}</test2>
  <test3>{local:test-generated-ordpath($test3a/text(),$test3b/aaa)}</test3>
  <test4>{local:test-generated-ordpath($test4a/text(),$test4b/aaa)}</test4>
  <test5>{local:test-generated-ordpath($test5a/text(),$test5b/aaa)}</test5>
  <test6>{local:test-generated-ordpath($test6a/text(),$test6b/aaa)}</test6>
  <test7>{local:test-generated-ordpath($test7a/text(),$test7b/aaa)}</test7>
  <test8>{local:test-generated-ordpath($test8a/text(),$test8b/aaa)}</test8>
  <test9>{local:test-generated-ordpath($test9a/text(),$test9b/aaa)}</test9>
  <test10>{local:test-generated-ordpath($test10a/text(),$test10b/aaa)}</test10>
  <test11>{local:test-generated-ordpath($test11a/text(),$test11b/aaa)}</test11>
  <test12>{local:test-generated-ordpath($test12a/text(),$test12b/aaa)}</test12>
  <test13>{local:test-generated-ordpath($test13a/text(),$test13b/aaa)}</test13>
</result>





