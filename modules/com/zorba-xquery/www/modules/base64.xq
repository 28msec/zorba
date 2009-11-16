(:~
 : Module Name: Base64
 : Copyright: 2006-2009 The FLWOR Foundation. Licensed under the Apache License, Version 2.0.
 : @version 1.0
 :)
module namespace base64 = "http://www.zorba-xquery.com/modules/base64";


(:~
 : @param base64 The xs:base64Binary item to decode
 : @return the decoded xs:base64Binary item as string
 :)
declare function base64:decode($base64 as xs:base64Binary) as xs:string external;

(:~
 : @param item The item whose string-value should be encoded
 : @return the base64 encoded string-value of the item parameter
 :)
declare function base64:encode($item) as xs:base64Binary external;
