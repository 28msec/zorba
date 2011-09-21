(: Declaration of index in main module :)

import module namespace index_ddl = "http://www.zorba-xquery.com/modules/store/static/indexes/ddl";

declare index foo 
on nodes (<a i="1"/>, <b i="2"/>, <c i="1"/>)
by fn:data(./@i) as xs:string;

index_ddl:create(xs:QName("foo"));
index_ddl:drop-index(xs:QName("foo"));

