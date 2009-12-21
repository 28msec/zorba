
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


(: --------------------------------------------------------------------- :)
declare index foo:bar on nodes xqddf:collection(coll:foo)
  by ./@id as xs:string ascending empty greatest;


(: --------------------------------------------------------------------- :)
declare index foo:bar on nodes xqddf:collection(coll:foo)
  by ./@id as xs:string ascending empty least;


(: --------------------------------------------------------------------- :)
declare index foo:bar on nodes xqddf:collection(coll:foo)
  by ./@id as xs:string ascending;


(: --------------------------------------------------------------------- :)
declare index foo:bar on nodes xqddf:collection(coll:foo)
  by ./@id as xs:string ascending,
     ./@id2 as xs:integer descending;


(: --------------------------------------------------------------------- :)
declare index foo:bar on nodes xqddf:collection(coll:foo)
  by ./@id as xs:string ascending empty least collation "http://foo.com/bar",
     ./@id2 as xs:integer descending;


1
