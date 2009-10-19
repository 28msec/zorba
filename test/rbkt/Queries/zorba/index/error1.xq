declare namespace idx = "http://www.zorba-xquery.com/zorba/op-extensions";

declare index idx:foo on (<a i="1"/>, <b i="2"/>, <c i="1"/>)
                      by (fn:data(./@i));

idx:create-index(xs:QName("idx:foo"));
idx:probe-index-point(xs:QName("idx:foo"), "1");
idx:drop-index(xs:QName("idx:foo"));
idx:create-index(xs:QName("idx:foo"));
idx:probe-index-point(xs:QName("idx:foo"), "1");
