import module namespace zq = 'http://zorba.io/modules/zorba-query';

variable $query-key := zq:prepare-main-module('
import module namespace ddl = "http://zorba.io/modules/store/dynamic/collections/ddl";
declare namespace an = "http://zorba.io/annotations";
declare %an:sequential function local:foo() {
  ddl:create(xs:QName("hola"),(<a/>,<b/>));                  
  
  exit returning ();
};

local:foo()
');
variable $a := zq:evaluate($query-key);
$a
