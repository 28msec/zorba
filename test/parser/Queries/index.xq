
(: --------------------------------------------------------------------- :)

declare index foo:bar on nodes xqddf:collection(coll:foo)
  by ./@id as xs:string;

(: --------------------------------------------------------------------- :)
declare unique index foo:bar on nodes xqddf:collection(coll:foo)
  by ./@id as xs:string;


(: --------------------------------------------------------------------- :)
declare non unique index foo:bar on nodes xqddf:collection(coll:foo)
  by ./@id as xs:string;


(: --------------------------------------------------------------------- :)
declare value range index foo:bar on nodes xqddf:collection(coll:foo)
  by ./@id as xs:string;


(: --------------------------------------------------------------------- :)
declare value equality index foo:bar on nodes xqddf:collection(coll:foo)
  by ./@id as xs:string;


(: --------------------------------------------------------------------- :)
declare automatically maintained index foo:bar on nodes xqddf:collection(coll:foo)
  by ./@id as xs:string;


(: --------------------------------------------------------------------- :)
declare manually maintained index foo:bar on nodes xqddf:collection(coll:foo)
  by ./@id as xs:string;


(: --------------------------------------------------------------------- :)
declare unique value range automatically maintained index foo:bar on nodes xqddf:collection(coll:foo)
  by ./@id as xs:string;


1
