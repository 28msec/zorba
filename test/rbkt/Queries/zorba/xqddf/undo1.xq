
import module namespace m = 'xqueryzorba.org/test/xqddf/ic' at 'ic.xqlib';

import module namespace ddl =
"http://zorba.io/modules/store/static/collections/ddl";

import module namespace dml =
"http://zorba.io/modules/store/static/collections/dml";

import module namespace ic_ddl =
"http://zorba.io/modules/store/static/integrity-constraints/ddl";

declare namespace err = "http://www.w3.org/2005/xqt-errors";

ddl:create($m:empc);

ic_ddl:activate(xs:QName("m:ic_simple"));

variable $test:=<root><a/><b/><c/></root>;

try
{
{
(
  replace node $test/*[1] with "something",

  replace node $test/*[2] with "else",

  dml:insert($m:empc,
  <emp>
  <salary>600</salary>
  </emp>
  )
);

()
}
}
catch * 
{
  <exception>{$err:code} : {$err:description}</exception>
}
,
$test
