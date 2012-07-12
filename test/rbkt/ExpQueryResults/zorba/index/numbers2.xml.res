<?xml version="1.0" encoding="UTF-8"?>
xs:long 

TEST 1:

<exception>err:XPTY0004 : node with untyped key value found during probe on index "num:idx-g-h-untyped"</exception>

TEST 2:

 
  <s:integer xmlns:s="http://www.zorba-xquery.com/numbers.xsd">2</s:integer>

TEST 3:

<s:integer xmlns:s="http://www.zorba-xquery.com/numbers.xsd">2</s:integer><untyped>2</untyped>
<s:integer xmlns:s="http://www.zorba-xquery.com/numbers.xsd">2</s:integer><untyped>2</untyped>
<s:integer xmlns:s="http://www.zorba-xquery.com/numbers.xsd">2</s:integer><untyped>2</untyped>
<s:integer xmlns:s="http://www.zorba-xquery.com/numbers.xsd">2</s:integer><untyped>2</untyped>
<untyped>2</untyped>
