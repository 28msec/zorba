declare namespace ann = "http://www.zorba-xquery.com/annotations";

(: --------------------------------------------------------------------- :)

declare index foo:bar on nodes xqddf:collection(coll:foo)
  by ./@id as xs:string;

(: --------------------------------------------------------------------- :)
declare %ann:unique index foo:bar on nodes xqddf:collection(coll:foo)
  by ./@id as xs:string;


(: --------------------------------------------------------------------- :)
declare %ann:nonunique index foo:bar on nodes xqddf:collection(coll:foo)
  by ./@id as xs:string;


(: --------------------------------------------------------------------- :)
declare %ann:value-range index foo:bar on nodes xqddf:collection(coll:foo)
  by ./@id as xs:string;


(: --------------------------------------------------------------------- :)
declare %ann:value-equality index foo:bar on nodes xqddf:collection(coll:foo)
  by ./@id as xs:string;


(: --------------------------------------------------------------------- :)
declare %ann:automatic index foo:bar on nodes xqddf:collection(coll:foo)
  by ./@id as xs:string;


(: --------------------------------------------------------------------- :)
declare %ann:manual index foo:bar on nodes xqddf:collection(coll:foo)
  by ./@id as xs:string;


(: --------------------------------------------------------------------- :)
declare %ann:unique %ann:value-range %automatic index foo:bar on nodes xqddf:collection(coll:foo)
  by ./@id as xs:string;


1
