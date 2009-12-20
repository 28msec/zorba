(: Declaration of index in main module :)

import module namespace xqddf = "http://www.zorba-xquery.com/modules/xqddf";

declare index foo 
on nodes (<a i="1"/>, <b i="2"/>, <c i="1"/>)
by fn:data(./@i) as xs:string;

xqddf:create-index(xs:QName("foo"));
xqddf:drop-index(xs:QName("foo"));

