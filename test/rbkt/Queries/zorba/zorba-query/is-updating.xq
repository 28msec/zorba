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
variable $is-updating := zq:is-updating($query-key2);
variable $is-not-updating := zq:is-updating($query-key1); 
zq:delete-query($query-key1);
zq:delete-query($query-key2);
$is-updating, $is-not-updating
 
