import module namespace xqxq = 'http://www.zorba-xquery.com/modules/xqxq';

variable $query-key1 := xqxq:prepare-main-module('
import module namespace ddl = "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl";
declare namespace an = "http://www.zorba-xquery.com/annotations";
declare %an:sequential function local:foo() {
  ddl:create(xs:QName("hola"),(<a/>,<b/>));                  
  
  exit returning ();
};

local:foo()
');  
variable $query-key2 := xqxq:prepare-main-module("insert node <child/> into /parent");  
variable $is-updating := xqxq:is-updating($query-key2);
variable $is-not-updating := xqxq:is-updating($query-key1); 
xqxq:delete-query($query-key1);
xqxq:delete-query($query-key2);
$is-updating, $is-not-updating
 
