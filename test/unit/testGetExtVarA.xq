module namespace testGetExtVarA = "http://www.zorba-xquery.com/modules/testGetExtVarA";
import module namespace testGetExtVarB = "http://www.zorba-xquery.com/modules/testGetExtVarB";


declare variable $testGetExtVarA:ext external;

declare function testGetExtVarA:get-external(){
  $testGetExtVarA:ext
};

declare function testGetExtVarA:get-b(){
  testGetExtVarB:get-external()
};