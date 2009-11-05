(:~
 : Module Name: XQDoc
 : Module Overview: This library module provides XQDoc utility functions.
 : Date: November 03, 2009
 : Copyright: 2006-2009 The FLWOR Foundation. Licensed under the Apache License, Version 2.0.
 : @author Gabriel Petrovay
 : @version 1.0
 :)
module namespace xqd = "http://www.zorba-xquery.com/modules/xqdoc";


(:~
 : Generated the an XQDoc XML document for the provided module.
 :
 : @param module The module file for which to generate XQDoc.
 : @return The xqdoc element as specified by www.xqdoc.org.
 : @error An error is thrown if an IO problem occurs.
 :)
declare sequential function xqd:xqdoc($module as xs:string) as element() external;