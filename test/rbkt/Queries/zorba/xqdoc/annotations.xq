xquery version "3.0";

import module namespace xqd = "http://www.zorba-xquery.com/modules/xqdoc";

import schema namespace xqdoc = "http://www.xqdoc.org/1.0";

declare copy-namespaces preserve, inherit;

declare namespace ann = "http://www.zorba-xquery.com/annotations";

declare %ann:sequential function local:remove-date($xqdoc)
{
  let $date := $xqdoc//xqdoc:date[1]
  return
	replace value of node $date with "";
  exit returning $xqdoc;
};

local:remove-date(xqd:xqdoc-content(
'
  xquery version "3.0";
  
  module namespace annotations = "http://www.zorba-xquery.com/modules/xqdoc/annotations";
  
  declare namespace restxq = "http://www.zorba-xquery.com/modules/xqdoc/test";
  
  declare %restxq:form-param("message","{$message}", "''no message delivered''", 5) variable $annotations:variable := ("tt");
  
  declare %restxq:form-param("message","{$message}", "''no message delivered''", 5) function annotations:function()
  as xs:string
  { "test" };
'))