import module namespace num = "http://www.w3.org/TestModules/numbers" at "numbers.xqlib";

import module namespace ddl = "http://zorba.io/modules/store/static/collections/ddl";
import module namespace dml = "http://zorba.io/modules/store/static/collections/dml";
import module namespace iddl = "http://zorba.io/modules/store/static/indexes/ddl";
import module namespace idml = "http://zorba.io/modules/store/static/indexes/dml";

declare namespace err = "http://www.w3.org/2005/xqt-errors";

import module namespace schema = "http://zorba.io/modules/schema";

import schema namespace s = "http://zorba.io/numbers.xsd" at "numbers.xsd";

declare variable $doc :=
<numbers>
<s:long>1</s:long>
<s:integer>2</s:integer>
<untyped>3</untyped>
</numbers>
;

declare variable $vdoc := validate lax { $doc };


ddl:create($num:collname2);

iddl:create($num:idx-g-h-untyped);

dml:insert($num:collname2, $vdoc);


schema:schema-type(data(dml:collection($num:collname2)//s:long))
,
"

TEST 1:

"
,
try
{
  idml:probe-index-point-value($num:idx-g-h-untyped, 3) 
}
catch *
{
  <exception>{$err:code} : {$err:description}</exception>
}
,
"

TEST 2:

"
,
{
  delete node dml:collection($num:collname2)/untyped;

  idml:probe-index-point-general($num:idx-g-h-untyped, 3)
  ,
  "
  "
  ,
  idml:probe-index-point-value($num:idx-g-h-untyped, 2)
}
,
"

TEST 3:

"
,
{
  insert node <untyped>2</untyped> as last into dml:collection($num:collname2)[1];

  idml:probe-index-point-general($num:idx-g-h-untyped, 2),
"
",
  idml:probe-index-point-general($num:idx-g-h-untyped, 2.0),
"
",
  idml:probe-index-point-general($num:idx-g-h-untyped, xs:double(2.0)),
"
",
  idml:probe-index-point-general($num:idx-g-h-untyped, xs:int(2)),
"
",
  idml:probe-index-point-general($num:idx-g-h-untyped, "2")
}
,
"
"

