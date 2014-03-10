import module namespace ddl = "http://zorba.io/modules/store/static/collections/ddl";
import module namespace dml = "http://zorba.io/modules/store/static/collections/dml";
import module namespace index_ddl = "http://zorba.io/modules/store/static/indexes/ddl";
import module namespace index_dml = "http://zorba.io/modules/store/static/indexes/dml";

import module namespace keys-lib = "http://www.example.com/" at "keys_mod.xqlib";

ddl:create(xs:QName("keys-lib:foo"));
index_ddl:create(xs:QName("keys-lib:FooIdx-general"));

for $i in 1 to 10
return
  dml:insert(xs:QName("keys-lib:foo"),
    if ($i mod 2 = 0) then
      <foo id="{$i}"/>
    else
      <foo id="{$i - 1}" string="true"/>
  );

let $keys :=
  for $key in index_dml:keys(xs:QName("keys-lib:FooIdx-general"))
  let $attr := $key/self::*:key/*:attribute
  order by xs:string($attr/@*:type), xs:long($attr/@*:value)
  return $key
return
  <keys count="{ count($keys) }">{
    $keys
  }</keys>
