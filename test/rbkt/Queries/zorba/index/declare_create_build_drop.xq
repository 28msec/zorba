declare namespace op-extensions = "http://www.zorba-xquery.com/zorba/op-extensions";

declare index "foo" on (<a i="1"/>, <b i="2"/>, <c i="1"/>)
by (fn:data(./@i));

create index "foo"; 
build index "foo";
op-extensions:probe-index-point(xs:anyURI("foo"), "1");
drop index "foo";
create index "foo"; 
build index "foo"; 
op-extensions:probe-index-point(xs:anyURI("foo"), "1");
