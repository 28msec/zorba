module namespace testGetExtVarB = "http://www.zorba-xquery.com/modules/testGetExtVarB";

declare variable $testGetExtVarB:ext external;
declare function testGetExtVarB:get-external(){
$testGetExtVarB:ext
};