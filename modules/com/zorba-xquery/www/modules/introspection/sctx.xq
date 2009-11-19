(:~
 : Module Name: Intospection Module for the Static Context
 : Copyright: 2006-2009 The FLWOR Foundation. Licensed under the Apache License, Version 2.0.
 : @version 1.0
 :)
module namespace sctx = "http://www.zorba-xquery.com/modules/introspection/sctx";


(:~
 :)
declare function sctx:is-declared-collection($name as xs:QName) as xs:boolean external;

(:~
 :)
declare function sctx:declared-collections() as xs:QName* external;

(:~
 :)
declare function sctx:is-declared-index($name as xs:QName) as xs:boolean external;

(:~
 :)
declare function sctx:declared-indexes() as xs:QName* external;
