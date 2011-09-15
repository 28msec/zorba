import module namespace m = 'xqueryzorba.org/test/xqddf/ic' at '../xqddf/ic.xqlib';

import module namespace ddl = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";

import module namespace dml = "http://www.zorba-xquery.com/modules/store/static/collections/dml";

import module namespace ic_ddl = "http://www.zorba-xquery.com/modules/store/static/integrity_constraints/ddl";

ddl:create($m:empc);

variable $test:=<root><child><childchild/></child></root>;

ic_ddl:activate(xs:QName("m:ic_simple"));


try
{
(
  replace value of node $test/child with "x",

  delete node $test/child/childchild,

  dml:insert-nodes($m:empc, <emp><salary>600</salary></emp>)
);
}
catch * 
{
}

$test
