declare namespace blub = "http://jsoniq.org/types";

(:  Only null may be cast to null:)
(: Null may be cast to string or untypedAtomic ("null", its lexical representation) only. :)

null cast as xs:untypedAtomic
