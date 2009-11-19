(:~
 : Module Name: Intospection Module for the Dynamic Context
 : Copyright: 2006-2009 The FLWOR Foundation. Licensed under the Apache License, Version 2.0.
 : @version 1.0
 :)
module namespace dctx = "http://www.zorba-xquery.com/modules/introspection/dctx";


(:~
 :)
declare function dctx:is-available-collection($name as xs:QName) as xs:boolean external;

(:~
 :)
declare function dctx:available-collections() as xs:QName* external;

(:~
 :)
declare function dctx:is-available-index($name as xs:QName) as xs:boolean external;

(:~
 :)
declare function dctx:available-indexes() as xs:QName* external;
