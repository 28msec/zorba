import module namespace zq = 'http://zorba.io/modules/zorba-query';

variable $query-key1 := zq:prepare-main-module('
import module namespace ddl = "http://zorba.io/modules/store/dynamic/collections/ddl";
declare namespace an = "http://zorba.io/annotations";
declare %an:sequential function local:foo() {
  ddl:create(xs:QName("hola"),(<a/>,<b/>));                  
  
  exit returning ();
};

local:foo()
');  
variable $query-key2 := zq:prepare-main-module("insert node <child/> into /parent");  
variable $is-sequential := zq:is-sequential($query-key1);
variable $is-not-sequential := zq:is-sequential($query-key2); 
$is-sequential, $is-not-sequential
 
