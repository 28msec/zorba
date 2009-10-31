(: Declaration of index in main module :)

import module namespace ddl = "http://www.zorba-xquery.com/module/ddl";

declare index foo on (<a i="1"/>, <b i="2"/>, <c i="1"/>)
                     by (fn:data(./@i));

ddl:create-index(xs:QName("foo"));
ddl:drop-index(xs:QName("foo"));

