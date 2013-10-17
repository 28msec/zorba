import module namespace zq = 'http://zorba.io/modules/zorba-query';

variable $query-key := zq:prepare-main-module('
import module namespace ddl = "http://zorba.io/modules/store/dynamic/collections/ddl";
declare namespace an = "http://zorba.io/annotations";
declare %an:sequential function local:foo() {
  ddl:create(xs:QName("hola"),(<a/>,<b/>));                  
  
  exit returning true();
};

local:foo()
');    
variable $xml := doc("context-item.xml");
zq:bind-context-item($query-key, $xml);  
zq:evaluate-sequential($query-key)
 
