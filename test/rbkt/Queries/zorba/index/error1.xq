(: Declaration of index in main module :)

import module namespace init = "http://www.zorba-xquery.com/modules/store/static-collections/initialization";

declare index foo 
on nodes (<a i="1"/>, <b i="2"/>, <c i="1"/>)
by fn:data(./@i) as xs:string;

init:create-index(xs:QName("foo"));
init:drop-index(xs:QName("foo"));

