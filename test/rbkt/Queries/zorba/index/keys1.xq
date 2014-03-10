import module namespace ddl = "http://zorba.io/modules/store/static/collections/ddl";
import module namespace dml = "http://zorba.io/modules/store/static/collections/dml";
import module namespace index_ddl = "http://zorba.io/modules/store/static/indexes/ddl";
import module namespace index_dml = "http://zorba.io/modules/store/static/indexes/dml";

import module namespace keys-lib = "http://www.example.com/" at "keys_mod.xqlib";

ddl:create(xs:QName("keys-lib:foo"));
index_ddl:create(xs:QName("keys-lib:FooIdx"));

for $i in 1 to 10
return
  dml:insert(xs:QName("keys-lib:foo"),
    <foo id="{$i}"/>
  );

let $keys := index_dml:keys(xs:QName("keys-lib:FooIdx"))
let $attr := $keys[1]/self::*:key/*:attribute/@*:value
return
  <keys typeIsInteger="{data($attr) instance of xs:integer}">{
    $keys
  }</keys>
