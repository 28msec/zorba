
(: --------------------------------------------------------------------- :)
declare index foo:bar on xqddf:collection(coll:foo)
  by ./@id as xs:string;

(:
declare index foo:bar on nodes $e in xqddf:collection(coll:foo)
  by $e/@id as xs:string;
:)

(: --------------------------------------------------------------------- :)
declare unique index foo:bar on xqddf:collection(coll:foo)
  by ./@id as xs:string;

(:
declare unique index foo:bar on nodes $e in xqddf:collection(coll:foo)
  by $e/@id as xs:string;
:)

(: --------------------------------------------------------------------- :)
declare non unique index foo:bar on xqddf:collection(coll:foo)
  by ./@id as xs:string;

(:
declare non unique index foo:bar on nodes $e in xqddf:collection(coll:foo)
  by $e/@id as xs:string;
:)

(: --------------------------------------------------------------------- :)
declare ordered index foo:bar on xqddf:collection(coll:foo)
  by ./@id as xs:string;

(:
declare value range index foo:bar on nodes $e in xqddf:collection(coll:foo)
  by $e/@id as xs:string;
:)

(: --------------------------------------------------------------------- :)
declare ordered index foo:bar on xqddf:collection(coll:foo)
  by ./@id as xs:string;

(:
declare value range index foo:bar on nodes $e in xqddf:collection(coll:foo)
  by $e/@id as xs:string;
:)

(: --------------------------------------------------------------------- :)
declare unordered index foo:bar on xqddf:collection(coll:foo)
  by ./@id as xs:string;

(:
declare value equality index foo:bar on nodes $e in xqddf:collection(coll:foo)
  by $e/@id as xs:string;
:)

(: --------------------------------------------------------------------- :)
declare automatic index foo:bar on xqddf:collection(coll:foo)
  by ./@id as xs:string;

(:
declare automatically maintained index foo:bar on nodes $e in xqddf:collection(coll:foo)
  by $e/@id as xs:string;
:)

(: --------------------------------------------------------------------- :)
declare manual index foo:bar on xqddf:collection(coll:foo)
  by ./@id as xs:string;

(:
declare explicitly maintained index foo:bar on nodes $e in xqddf:collection(coll:foo)
  by $e/@id as xs:string;
:)

(: --------------------------------------------------------------------- :)
declare unique ordered automatic index foo:bar on xqddf:collection(coll:foo)
  by ./@id as xs:string;

(:
declare unique value range automatically maintained index foo:bar on nodes $e in xqddf:collection(coll:foo)
  by $e/@id as xs:string;
:)

(: --------------------------------------------------------------------- :)
declare index foo:bar on xqddf:collection(coll:foo)
  by ./@id as xs:string ascending empty greatest;

(:
declare index foo:bar on nodes $e in xqddf:collection(coll:foo)
  by $e/@id as xs:string ascending empty greatest;
:)

(: --------------------------------------------------------------------- :)
declare index foo:bar on xqddf:collection(coll:foo)
  by ./@id as xs:string ascending empty least;

(:
declare index foo:bar on nodes $e in xqddf:collection(coll:foo)
  by $e/@id as xs:string ascending empty least;
:)

(: --------------------------------------------------------------------- :)
declare index foo:bar on xqddf:collection(coll:foo)
  by ./@id as xs:string ascending;

(:
declare index foo:bar on nodes $e in xqddf:collection(coll:foo)
  by $e/@id as xs:string ascending;
:)

(: --------------------------------------------------------------------- :)
declare index foo:bar on xqddf:collection(coll:foo)
  by ./@id as xs:string ascending,
     ./@id2 as xs:integer descending;

(:
declare index foo:bar on nodes $e in xqddf:collection(coll:foo)
  by $e/@id as xs:string ascending,
     $e/@id2 as xs:integer descending;
:)

(: --------------------------------------------------------------------- :)
declare index foo:bar on xqddf:collection(coll:foo) 
  by ./@id as xs:string ascending empty least collation "http://foo.com/bar",
     ./@id2 as xs:integer descending;

(:
declare index foo:bar on nodes $e in xqddf:collection(coll:foo)
  by $e/@id as xs:string ascending empty least collation "http://foo.com/bar",
     $e/@id2 as xs:integer descending;
:)

1
