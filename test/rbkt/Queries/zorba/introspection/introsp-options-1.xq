declare namespace op = "http://www.zorba-xquery.org/options";

import module namespace sctx = "http://www.zorba-xquery.com/modules/introspection/sctx";

declare option op:trace "disable";
declare option op:blub "foo";

sctx:option(xs:QName("op:trace"))
