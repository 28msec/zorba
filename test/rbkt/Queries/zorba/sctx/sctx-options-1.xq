declare namespace op = "http://www.zorba-xquery.org/options";

import module namespace sctx = "http://zorba.io/modules/sctx";

declare option op:trace "disable";
declare option op:blub "foo";

sctx:option(xs:QName("op:trace"))
