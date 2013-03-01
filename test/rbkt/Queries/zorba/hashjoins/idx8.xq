declare namespace xqdoc = "http://www.xqdoc.org/1.0";

let $fs := doc("xqdoc.xml")/xqdoc:xqdoc/xqdoc:functions/xqdoc:function

for $function in ($fs[1],$fs[8])

for $furi in ("http://www.w3.org/2005/xpath-functions",())

let $invokedFunctions := $function/xqdoc:invoked[string(xqdoc:uri)=$furi]

return ($function/xqdoc:name/text(),":",$invokedFunctions) 


(:


<root>
insert :
<xqdoc:invoked xmlns:xqdoc="http://www.xqdoc.org/1.0">
  <xqdoc:uri>http://www.w3.org/2005/xpath-functions</xqdoc:uri>
  <xqdoc:name arity="2">QName</xqdoc:name>
</xqdoc:invoked>
<xqdoc:invoked xmlns:xqdoc="http://www.xqdoc.org/1.0">
  <xqdoc:uri>http://www.w3.org/2005/xpath-functions</xqdoc:uri>
  <xqdoc:name arity="2">concat</xqdoc:name>
</xqdoc:invoked>
<xqdoc:invoked xmlns:xqdoc="http://www.xqdoc.org/1.0">
  <xqdoc:uri>http://www.w3.org/2005/xpath-functions</xqdoc:uri>
  <xqdoc:name arity="0">current-date</xqdoc:name>
</xqdoc:invoked>
<xqdoc:invoked xmlns:xqdoc="http://www.xqdoc.org/1.0">
  <xqdoc:uri>http://www.w3.org/2005/xpath-functions</xqdoc:uri>
  <xqdoc:name arity="0">current-time</xqdoc:name>
</xqdoc:invoked>
<xqdoc:invoked xmlns:xqdoc="http://www.xqdoc.org/1.0">
  <xqdoc:uri>http://www.w3.org/2005/xpath-functions</xqdoc:uri>
  <xqdoc:name arity="1">empty</xqdoc:name>
</xqdoc:invoked>
<xqdoc:invoked xmlns:xqdoc="http://www.xqdoc.org/1.0">
  <xqdoc:uri>http://www.w3.org/2005/xpath-functions</xqdoc:uri>
  <xqdoc:name arity="2">error</xqdoc:name>
</xqdoc:invoked>
<xqdoc:invoked xmlns:xqdoc="http://www.xqdoc.org/1.0">
  <xqdoc:uri>http://www.w3.org/2005/xpath-functions</xqdoc:uri>
  <xqdoc:name arity="1">normalize-space</xqdoc:name>
</xqdoc:invoked>
<xqdoc:invoked xmlns:xqdoc="http://www.xqdoc.org/1.0">
  <xqdoc:uri>http://www.w3.org/2005/xpath-functions</xqdoc:uri>
  <xqdoc:name arity="1">string-length</xqdoc:name>
</xqdoc:invoked>

logout :
<xqdoc:invoked xmlns:xqdoc="http://www.xqdoc.org/1.0">
  <xqdoc:uri>http://www.w3.org/2005/xpath-functions</xqdoc:uri>
  <xqdoc:name arity="2">QName</xqdoc:name>
</xqdoc:invoked>
<xqdoc:invoked xmlns:xqdoc="http://www.xqdoc.org/1.0">
  <xqdoc:uri>http://www.w3.org/2005/xpath-functions</xqdoc:uri>
  <xqdoc:name arity="2">concat</xqdoc:name>
</xqdoc:invoked>
<xqdoc:invoked xmlns:xqdoc="http://www.xqdoc.org/1.0">
  <xqdoc:uri>http://www.w3.org/2005/xpath-functions</xqdoc:uri>
  <xqdoc:name arity="0">current-date</xqdoc:name>
</xqdoc:invoked>
<xqdoc:invoked xmlns:xqdoc="http://www.xqdoc.org/1.0">
  <xqdoc:uri>http://www.w3.org/2005/xpath-functions</xqdoc:uri>
  <xqdoc:name arity="0">current-time</xqdoc:name>
</xqdoc:invoked>
<xqdoc:invoked xmlns:xqdoc="http://www.xqdoc.org/1.0">
  <xqdoc:uri>http://www.w3.org/2005/xpath-functions</xqdoc:uri>
  <xqdoc:name arity="1">empty</xqdoc:name>
</xqdoc:invoked>
<xqdoc:invoked xmlns:xqdoc="http://www.xqdoc.org/1.0">
  <xqdoc:uri>http://www.w3.org/2005/xpath-functions</xqdoc:uri>
  <xqdoc:name arity="2">error</xqdoc:name></xqdoc:invoked>
<xqdoc:invoked xmlns:xqdoc="http://www.xqdoc.org/1.0">
  <xqdoc:uri>http://www.w3.org/2005/xpath-functions</xqdoc:uri>
  <xqdoc:name arity="1">normalize-space</xqdoc:name>
</xqdoc:invoked>
<xqdoc:invoked xmlns:xqdoc="http://www.xqdoc.org/1.0">
  <xqdoc:uri>http://www.w3.org/2005/xpath-functions</xqdoc:uri>
  <xqdoc:name arity="1">string-length</xqdoc:name>
</xqdoc:invoked>
</root>

:)
