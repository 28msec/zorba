import module namespace xqxq = 'http://www.zorba-xquery.com/modules/xqxq';

variable $query-key := xqxq:prepare-main-module('
import module namespace ddl = "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl";
declare namespace an = "http://www.zorba-xquery.com/annotations";
declare %an:sequential function local:foo() {
  ddl:create(xs:QName("hola"),(<a/>,<b/>));                  
  
  exit returning ();
};

local:foo()
');
variable $a := xqxq:evaluate($query-key);
$a
